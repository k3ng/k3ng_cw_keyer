#if !defined(audiopwmsinewave_h)
#define audiopwmsinewave_h

#include "RPi_Pico_TimerInterrupt.h"
#include "RPi_Pico_ISR_Timer.h"

/*
Generate a PWM-based sine wave: Mortty_v5 CPU and Sidetone boards, Steve N8AR and Larry K8UT 2023-10-27

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software
PIPICO-W PICO-W PICO-W PICO-W PICO-W PICO-W PICO-W PICO-W PICO-W PICO-W PICO-W PICO-W PICO-W 

M     M  OOOOO  RRRR   TTTTTT  TTTTTT  Y    Y     AAAAAA   UU  UU   DDDD    II  OOOOO
M M M M  O   O  R  RR    TT      TT     Y  Y      AA  AA   UU  UU   DD  D   II  O   O
M  M  M  O   O  RRR      TT      TT      YY       AAAAAA   UU  UU   DD  DD  II  O   O
M     M  O   O  R  R     TT      TT      YY       AA  AA   UU  UU   DD  D   II  O   O
M     M  OOOOO  R   R    TT      TT      YY       AA  AA   UUUUUU   DDDD    II  OOOOO

REFERENCE MATERIAL
Nice PWM Tutorial - VIdeo: https://www.youtube.com/watch?v=Au-oc4hxj-c
Sample code - SOURCE: https://github.com/khoih-prog/RPI_PICO_TimerInterrupt
SineWaveTable - SOURCE: https://forum.arduino.cc/t/create-an-array-of-wave-data-for-wavetable-synth/1030423/13

// PWM PulseWidthModulation parms - timer interval must be an Unsigned Long integer "L"
// unsigned long AudioPWMTIMER_INTERVAL_US = 1000L;  // this is in MICROSECONDS timer interval in microseconds
// Square wave Scope Trigger frequency
// uint32_t freqTrigger = 1000; // this is in HERTZ

// const float AudioPWMTIMER_INTERVAL_MS = nL; this is in MICROSECONDS
// /\/\/ <10L + 500000 does not oscillate (?) BUSTED
//  10L + 500000 = 1562.6 Hz 2.4v p-p
//  11L + 500000 = 1420.4 Hz 
//  12L + 500000 = 1302.1 Hz 
// /\/\/ <12L causes Windows USB fault (?) - BUSTED do not use values below 13nS
//  13L + 500000 = 1201.9 Hz 
//  14L + 500000 = 1106.1 Hz 
//  15L + 500000 = 1041.7 Hz 2.6v p-p
//  16L + 500000 = 976.5 Hz
//  17L + 500000 = 919.1 Hz
//  18L + 500000 = 868.8 Hz
//  19L + 500000 = 822.5 Hz
//  20L + 500000 = 776.9 Hz 2.8v p-p
//  21L + 500000 = 744.0 Hz
//  22L + 500000 = 710.2 Hz
//  23L + 500000 = 679.4 Hz 
//  24L + 500000 = 651.1 Hz
//  25L + 500000 = 624.9 Hz 3.0v p-p
//  26L + 500000 = 600.9 Hz
//  27L + 500000 = 573.6 Hz
//  28L + 500000 = 558.0 Hz
//  29L + 500000 = 538.8 Hz
//  30L + 500000 = 520.8 Hz 3.2v p-p
//  31L + 500000 = 504.0 Hz
//  32L + 500000 = 488.3 Hz
//  33L + 500000 = 473.5 Hz
//  34L + 500000 = 459.5 Hz
//  35L + 500000 = 446.3 Hz
//  36L + 500000 = 433.9 Hz
//  37L + 500000 = 422.2 Hz
//  38L + 500000 = 411.2 Hz
//  39L + 500000 = 400.1 Hz
//  40L + 500000 = 390.6 Hz
//  41L + 500000 = 381.1 Hz
//  42L + 500000 = 372.1 Hz 3.3v p-p

// Low Frequencies. Do not use for CW Sidetone
// 75L + 500000 = 208.4 Hz
// 100L + 500000 = 156.2 Hz
// 125L + 500000 = 125.0 Hz
// 150L + 500000 = 104.2 Hz
// 156L + 500000 = 100.1 Hz
  */

// // IMPORTANT: MUST INSTALL - Adriono IDE >Tools >Library Manager >RPI_PICO_TimerInterrupt
// #include "RPi_Pico_TimerInterrupt.h"
// #include "RPi_Pico_ISR_Timer.h"

// VARIABLES //////////////////////////////////////////////////////////////////

// TEST PWM troubleshooting parms - not sure this works
// _TIMERINTERRUPT_LOGLEVEL_ from 0 to 4
// Don't define _TIMERINTERRUPT_LOGLEVEL_ > 0. Only for special ISR debugging only. Can hang the system.
// #define TIMER_INTERRUPT_DEBUG 1
// #define _TIMERINTERRUPT_LOGLEVEL_ 4

void initTimer();
bool timerISR(struct repeating_timer* t);
void writePWM_Pin();

RPI_PICO_Timer AudioPWMTimer(0); // define the Mortty Audio PWM timer as a RPI_PICO_Timer
RPI_PICO_ISR_Timer AudioPWM_ISR_timer;  // define the ISR Interrupt Service Request timer

const float AudioPWMTIMER_INTERVAL_MS = 16L;  // this is in MICROSECONDS timer interval in microseconds
// uint32_t freqTrigger = 500000;  // this is in HERTZ. Square wave Scope Trigger frequency

byte pin_PWM_Output = 0;
// NOTE: Radio #1 PTT LED (13) used for scope PWM_Trigger. Do not use for production operation
// #define pin_PWM_Trigger_LED 13  // TEST Mortty R1 PTT - output blink LED at start of each cycle (NOTE: trigger channel on scope)

// SineWaveTable - SOURCE: https://forum.arduino.cc/t/create-an-array-of-wave-data-for-wavetable-synth/1030423/13
volatile int arrPtr = 0; // pointer for looping through SineWaveArray
const int sineWaveArray[64] = {
  127, 139, 152, 164, 176, 187, 198, 208, 217, 225, 233, 239, 244, 249, 252,
  253, 254, 253, 252, 249, 244, 239, 233, 225, 217, 208, 198, 187, 176, 164, 152,
  139, 127, 115, 102, 90, 78, 67, 56, 46, 37, 29, 21, 15, 10, 5, 3, 2, 1, 2, 3,
  5, 10, 15, 21, 29, 37, 46, 56, 67, 78, 90, 102, 115
};




void initTimer() {
  // --------------------------------------------------------------------------
  AudioPWMTimer.stopTimer();  // if timer is running, stop it

  if (!AudioPWMTimer.attachInterruptInterval(AudioPWMTIMER_INTERVAL_MS, timerISR)) {  // if init fails, print this to console
  //   Serial.println(F("FAIL init AudioPWMTimer. Select another freq. or timer"));
  // } else {
  //   Serial.println(F("SUCCESS init AudioPWMTimer"));
  }
}  // ----- end of initTimer()

bool timerISR(struct repeating_timer* t) {
  // ------------------------------------------------------------------------
  (void)t;
  writePWM_Pin();  // do this every time the Repeating Timer fires
  return true;
}  // ----- end of timerISR() AudioPWM Timer Handler

void writePWM_Pin() {
  // ------------------------------------------------------------------------
  // loop through 64 bit (0-63) SineWaveArray  
  if (arrPtr < 63) {
    arrPtr++;
  } else {
    arrPtr = 0;
  }  
  analogWrite(pin_PWM_Output, sineWaveArray[arrPtr]);  // PWM output to audio filter  
} // ----- end of writePWM+Pin()

void PWMTone(byte pin, uint32_t hz){
  pin_PWM_Output = pin;
  if (pin_PWM_Output > 0){
    analogWriteFreq(hz * 1000);
    initTimer();
  }
}

void noPWMTone(byte pin){
  if (pin_PWM_Output > 0){
    AudioPWMTimer.stopTimer();
    digitalWrite(pin_PWM_Output,LOW);
  }
}

#endif