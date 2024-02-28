#if !defined(audiopwmsinewave_h)
#define audiopwmsinewave_h

// IMPORTANT: MUST INSTALL - Adriono IDE >Tools >Library Manager >RPI_PICO_TimerInterrupt
#include "RPi_Pico_TimerInterrupt.h"
// #include "RPi_Pico_ISR_Timer.h" //- no longer needed
#include "RP2040_PWM.h"

/*
Produce PWM GPIO output for Sinewave IO board on the Mortty_v5 IO and CPU boards, Larry K8UT 2023-12-15
  
PICO-W PICO-W PICO-W PICO-W PICO-W PICO-W PICO-W PICO-W PICO-W PICO-W PICO-W PICO-W PICO-W 
M     M  OOOOO  RRRR   TTTTTT  TTTTTT  Y    Y     AAAAAA   UU  UU  DDDD    IIII   OOOOOO
M M M M  O   O  R  RR    TT      TT     Y  Y      AA  AA   UU  UU  DD  DD   II    OO  OO
M  M  M  O   O  RRR      TT      TT      YY       AAAAAA   UU  UU  DDDDDD   II    OO  OO
M     M  O   O  R  R     TT      TT      YY       AA  AA   UU  UU  DD  DD   II    OO  OO
M     M  OOOOO  R   R    TT      TT      YY       AA  AA   UUUUUU  DDDD    IIII   OOOOOO

SOURCE: http://www.arduino.cc/en/Tutorial/Blink
SOURCE: https://github.com/earlephilhower/arduino-pico/discussions/184  PWM functions in Arduino IDE
SOURCE: https://registry.platformio.org/libraries/khoih-prog/RP2040_PWM
SOURCE: https://randomnerdtutorials.com/raspberry-pi-pico-pwm-analogwrite-arduino/
SOURCE: https://www.daycounter.com/Calculators/Sine-Generator-Calculator.phtml
This example to demo the new function setPWM_manual(uint8_t pin, uint16_t top, uint8_t div, uint16_t level, bool phaseCorrect = false)
used to generate a waveform. Check https://github.com/khoih-prog/RP2040_PWM/issues/6

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software

// Mortty_v5 PWM Sinewave Generator. Use 20 bits ("sices") in the sidetone array.
// SINE WAVE CALCULATED VALUES from website for 20 slices: MAX=1000, IMPORTANT: adjust MAX element from 1000 to 998
// NOTE: variables modified from original source using Millisecond integer values rather than microSecond decimal values
// Measured INTERVAL_MS: 20=2500 Hz. 30=1663 Hz, 40=1250 Hz, 50=1000 Hz, 60=833 Hz, 70=714 Hz, 80=624 Hz, 90=556, 100=500 Hz
// Measured INTERVAL_MS: 110=453 Hz. 120=416 Hz, 130=382 Hz, 140=357 Hz, 150=333 Hz
// RTTY Mark/Space frequencies: target MARK=2125 Hz, use 190=2105 Hz  -- target SPACE=2295 Hz, use 180=2222 Hz

version 1.0.0 2024/01/01 by k8UT
*/

// VARIABLES //////////////////////////////////////////////////////////////////

// TEST PWM troubleshooting parms - not sure this works
// _TIMERINTERRUPT_LOGLEVEL_ from 0 to 4
// Don't define _TIMERINTERRUPT_LOGLEVEL_ > 0. Only for special ISR debugging only. Can hang the system.
// #define TIMER_INTERRUPT_DEBUG 1
// #define _TIMERINTERRUPT_LOGLEVEL_ 4

// Mortty_v5 Sidetone output PWM pin 16: channel PWM0A (SPI D2)
//#define pin_Sidetone 16  // GP16, PWM channel 0A (spi D2)
//#define pin_Carrier 8

volatile uint16_t sineWaveArrayPtr = 0;
volatile bool isSidetoneON = true;
volatile float sidetoneAudioHz;
float sidetoneCarrierHz;
byte pin_Sidetone = 16;  // GP16, PWM channel 0A (spi D2)
byte pin_Carrier = 8;    // testing purposes
volatile uint16_t sidetoneDutyCycle;

// sineWave definition ---------------
typedef struct
{
  uint16_t top;
  uint8_t div;
  uint16_t level;
} PWD_Data;

#define NUM_PWM_POINTS 20
PWD_Data PWM_SINE_DATA[NUM_PWM_POINTS] = {
  { 1000, 10, 0 },  // arrange sinewave array with "0" value first. Audio OFF point with 0 volts output
  { 1000, 10, 24 },
  { 1000, 10, 95 },
  { 1000, 10, 206 },
  { 1000, 10, 345 },
  { 1000, 10, 500 },
  { 1000, 10, 655 },
  { 1000, 10, 794 },
  { 1000, 10, 905 },
  { 1000, 10, 976 },
  { 1000, 10, 998 },  // reduce top "1000" to "998" to nearest even integer for cleaner output
  { 1000, 10, 976 },
  { 1000, 10, 905 },
  { 1000, 10, 794 },
  { 1000, 10, 655 },
  { 1000, 10, 500 },
  { 1000, 10, 345 },
  { 1000, 10, 206 },
  { 1000, 10, 95 },
  { 1000, 10, 24 }
};

RPI_PICO_Timer timerSidetone(0);               //declore timerSidetone as an RPI_PICO_TIMER
RP2040_PWM* PWM_Sidetone;                      //declore PWM_Sidetone as a PWM output
volatile uint32_t timerSidetone_Milliseconds;  // = 0;  // CW audio range values from 250 Ms = 333 Hz -to- 20 Ms = 2500 Hz
// PWM_SINE_DATA_idle - sineWaveArray position of 0 volts. Resting point when sidetone == OFF
PWD_Data PWM_SINE_DATA_idle = PWM_SINE_DATA[0];  // ?does this do anything? I don't think so
// end of define variables ------------
// ////////////////////////////////////////////////////////////////////////////
// ----- procs and functions //////////////////////////////////////////////////

void set_SidetoneOutput(int localPtr) {
  // BUSTED do not print here Serial.print(".");
  // increment pointer to the sinwWaveArray
  if ((sineWaveArrayPtr >= (NUM_PWM_POINTS - 1)) || (!isSidetoneON)) {
    sineWaveArrayPtr = 0;
  } else {
    sineWaveArrayPtr++;
  }
  // set dutyCycle to [array element * 100] for 0->100,000 range required by (PWM_Sidetone->setPWM_Int)
  PWM_Sidetone->setPWM_Int(pin_Sidetone, sidetoneCarrierHz, (PWM_SINE_DATA[sineWaveArrayPtr].level) * 100);
  return;
}  // end of set SidetoneOutput() -------------------------

bool timerSidetone_Handler(struct repeating_timer* t) {
  (void)t;

  set_SidetoneOutput(sineWaveArrayPtr);
  // BUSTED do not print here Serial.print(".");
  return true;
}  // end of timerSidetone_Handler() interrupt ------------

// ------------------------------------
// Interrupts - PWM generator is a repeating timer --------
// calculate Millisecond interval = 1 / (Targer Audio in Hz ) / (NUM_PWM_POINTS (aka slices) * 1000000)

void timerSidetone_Init() {  // initialize the ISR timer interrupt routine
  if (timerSidetone.attachInterruptInterval(timerSidetone_Milliseconds, timerSidetone_Handler)) {
    //Serial.print("Starting timerSidetone OK, = ");
    //   Serial.print(timerSidetone_INTERVAL_MS * 10000);
    //Serial.println(" timerSidetone interval in uS");
  } else {
    //Serial.println(F("Can't set timerSidetone. Select another Timer, freq. or timer"));
  }
  return;
}  // end of timerSidetone_Init() -------------------------

int32_t PWMTone(byte pin, uint32_t hz) {
  // called by K3NG_KEYER.INO to start sending sidetone ---
  // C++ (float) calculation for calculaint timerSidetone_Milliseconds from Audio Hertz
  // = (( (float)1 / (float)Hertz ) / NUM_PWM_POINTS )*1000000
  //=====pin_PWM_Output = pin;
  pin_Sidetone = pin;
  if (pin == 0) {  // pin#0 == sidetoneOFF
    isSidetoneON = false;
    timerSidetone_Milliseconds = 50;  // with sidetone OFF, set timer for 50% duty cycle
  } else {
    sidetoneAudioHz = hz;
    if (hz <= 375) {  // low end of Winkeyer sidetone choices = 375
      sidetoneAudioHz = 375;
    } else {  // high end of PWM generator - ignore Winkey values sidetone frequencies
      if (hz >= 1500) {
        sidetoneAudioHz = 1500;
      }
      // enable for RTTY sidetones - standard MARK/SPACE tones
      //if ((hz >= 2125) || (hz <= 2295)) { sidetoneAudioHz = hz; }
    }
    isSidetoneON = true;
    timerSidetone_Milliseconds = (((float)1 / (float)sidetoneAudioHz) / NUM_PWM_POINTS) * 1000000;

    timerSidetone.stopTimer();
    timerSidetone_Init();
  }
  return timerSidetone_Milliseconds;
  delay(10);

}  // end of PWMTone() ------------------------------------

void noPWMTone(byte pin) {
  // called by K3NG_KEYER.INO. Stop sending sidetone ------
  if (pin_Sidetone > 0) {
    isSidetoneON = false;
	PWM_Sidetone->setPWM_Int(pin_Sidetone, sidetoneCarrierHz, (PWM_SINE_DATA[0].level) * 100);
  }  // PWM generator never turns off, but continuously sends the "0" zero elemeent
}  // end of noPWMTone() ----------------------------------
//
// end of procedures and functions ------------------------
#endif