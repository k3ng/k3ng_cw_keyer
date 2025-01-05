/* ***************************************************************************

pico pico pico pico pico pico pico pico pico pico pico pico pico pico pico pico 
pico pico pico pico pico pico pico pico pico pico pico pico pico pico pico pico 
pico pico pico pico pico pico pico pico pico pico pico pico pico pico pico pico 
pico pico pico pico pico pico pico pico pico pico pico pico pico pico pico pico 

M     M  OOOOO  RRRR   TTTTTT  TTTTTT  Y    Y       RRRR   TTTTTT  TTTTTT  Y    Y
M M M M  O   O  R  RR    TT      TT     Y  Y        R  RR    TT      TT     Y  Y 
M  M  M  O   O  RRR      TT      TT      YY         RRR      TT      TT      YY  
M     M  O   O  R  R     TT      TT      YY         R  R     TT      TT      YY  
M     M  OOOOO  R   R    TT      TT      YY         R   R    TT      TT      YY  

TinyFSK sketch for a Mortty v5 Keyer on RPi Pico-W platform by K8UT 2023-09-22

TinyFSK Version 1.1.0 
Copyright (C) 2013-2015 Andrew T. Flowers K0SM 

Permission is hereby granted, free of charge, to any person obtaining a copy 
of this software and associated documentation files (the "Software"), to deal 
in the Software without restriction, including without limitation the rights 
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
copies of the Software, and to permit persons to whom the Software is furnished 
to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in 
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
IN THE SOFTWARE.
****************************************************************************
Revisions:
1.1.0:  Make "Robust UnShift On Space" transmission to be compatible with MMTTY's 
        non-USOS default receiver.  It is effectively non-USOS transmission 
        with extra FIGS shifts if a figs character appears after a space. This should
        always print properly on by USOS and non-USOS demodulators at the expense of
        having to send a few extra symbols in some contest exchages.

        Version information displayed at beginning of configuration screen so people
        can tell what version of firmware they have.
        
1.0.1:  Swap FSK and PTT pins to make pin-compatible with K3NG "nanokeyer"
1.0.0:  Initial release
*********************************************************************************** */


// original source version number from K0SM
#define VERSION "1.1.0"
// ported to Raspberry Pi Pico-W 2023-09-25 by Larry Gauthier K8UT
#define VERSION_pico "0.0.1"



// TEST troubleshooting parms - these define's must be placed at the beginning before #include "TimerInterrupt_Generic.h"
// _TIMERINTERRUPT_LOGLEVEL_ from 0 to 4
// Don't define _TIMERINTERRUPT_LOGLEVEL_ > 0. Only for special ISR debugging only. Can hang the system.
// #define TIMER_INTERRUPT_DEBUG 1
// #define _TIMERINTERRUPT_LOGLEVEL_ 4

// Can be included as many times as necessary, without `Multiple Definitions` Linker Error
#include "RPi_Pico_TimerInterrupt.h"
// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error
#include "RPi_Pico_ISR_Timer.h"
// define the RPI_PICO_Timer
RPI_PICO_Timer FSKTimer(0);

// Pico-W - do not use on-board LED
//   #if !defined(LED_BUILTIN)
//     #define LED_BUILTIN     25
//   #endif

//Arduino pins for Radio 1 and Radio 2 PTT and FSK to control transmitter
#define R1_FSK_PIN 11
#define R1_PTT_PIN 13
#define R2_FSK_PIN 6
#define R2_PTT_PIN 8




//Special Baudot symbols for shift
#define LTRS_SHIFT 0x1F  //baudot letter shift byte
#define FIGS_SHIFT 0x1B  //baudot figs shift byte

#define SHIFT_UNKNOWN 0  //Undefined shift--used at TX start to force shift state

//Special ASCII SYMBOLS (8 bit)
#define ASCII_NULL 0x00
#define ASCII_LF 0x0A
#define ASCII_CR 0x0D

//BUFFER SETTINGS
#define SEND_BUFFER_SIZE 500  // Allow up to 500 chars in the buffer \
                              // before overrunning (wrapping around). \
                              // This can be increased on most boards \
                              // with more RAM.

#define TX_END_FLAG 0xFF  // Used in Baudot stream to indicate EOT

//References used in banging out the bits for 5-bit baudot. These
//are relative to the first data bit in the frame.
#define START_BIT_POS -1
#define STOP_BIT_POS 5

//Commands that control transmitter sequencing
#define TX_ON '['      // TX now => {TX} in N1MM
#define TX_END ']'     // Buffered switch to RX => {END} in N1MM
#define TX_ABORT '\\'  // (Backslash) Immediate switch to RX and clear buffer => {ESC} in N1MM

//Configuration commands.  These are also the values saved in the EEPROM.
#define COMMAND_ESCAPE '~'
#define COMMAND_POLARITY_MARK_HIGH '0'
#define COMMAND_POLARITY_MARK_LOW '1'
#define COMMAND_45BAUD '4'
#define COMMAND_50BAUD '5'
#define COMMAND_75BAUD '7'
#define COMMAND_DUMP_CONFIG '?'

// Stop bit settings
#define STOP_BITS_1 1    // 1 stop bit
#define STOP_BITS_1R5 2  // 1.5 stop bits
#define STOP_BITS_2 3    // 2 stop bits

// TX USOS settings
#define USOS_OFF 1  //Assumes that RX will not reset to LTRS shift after space \
                    //All shift symbols are explicit and spaces do not change \
                    //shift state: \
                    //  K0SM 599 05 NY NY \
                    //     --> <LTR>K<FIG>0<LTR>SM <FIG>599 05 <LTR>NY NY

#define USOS_ON 2  //Space is an implicit LTRS shift character.  "Ham standard" \
                   //demodulators operate in this mode. \
                   //  K0SM 599 05 NY NY \
                   //     --> <LTR>K<FIG>0<LTR>SM <FIG>599 <FIG>05 NY NY

#define USOS_MMTTY_HACK 3  //Essentially USOS OFF plus extra FIGS shifts for all words \
                           //starting with numbers.  This is what MMTTY somewhat misleadingly \
                           //calls "USOS transmission."  This settings makes many contest exchanges \
                           //longer (and slightly more prone to bit errors) all to be \
                           //compatible with MMTTY's non-USOS RX default \
                           //  K0SM 599 05 NY NY \
                           //     --> <LTR>K<FIG>0<LTR>SM <FIG>599 <FIG>05 <LTR>NY NY

void initTimer();
void handleConfigurationCommand(byte oneByte);
void eeLoad();
void initTimer();
bool timerISR(struct repeating_timer* t);
void displayConfigurationPrompt();
void displayConfiguration();
void processHalfBit();
void resetChar();
void resetSendBuffer();
void addToSendBuffer(byte newByte);
byte getNextSendChar();
boolean requiresLetters(byte asciiByte);
boolean requiresFigures(byte asciiByte);
void setPTT(byte isPTT);
void echo(byte b);

/******************************************************
     Variable declarations
*******************************************************/

//EEPROM addresses to persist configuration
int ee_speed_addr;
int ee_polarity_addr;


// Mapping of ascii to baudot symbols.  This is the
// translation table that maps an incoming ASCII byte
// on the serial interface to a equivalent (or reasonable
// substitute) that exists the ITA2 or US 5-bit code.
// In general, any ASCII control character will be mapped
// to a Baudot NULL.  Punctuation will be mapped to '?' if
// there is no equivalent in the Baudot set.  Note that
// some punctuation such as '[', ']' and '\' are used
// to control the PTT behavior.  Tilda (~) is used
// to enter the configuration menu.  You can use
// your imagination to add other control functions here.
int asciiToBaudot[127] = {

  ////      ASCII                  ASCII IDX (decimal)
  0,   //	Null character	          //	0
  0,   //	Start of Header	          //	1
  0,   //	Start of Text	            //	2
  0,   //	End of Text	              //	3
  0,   //	End of Transmission	      //	4
  0,   //	Enquiry	                  //	5
  0,   //	Acknowledgment	          //	6
  5,   //	Bell	                    //	7
  0,   //	Backspace	                //	8
  0,   //	Horizontal Tab  	        //	9
  2,   //	Line feed	                //	10
  0,   //	Vertical Tab	            //	11
  0,   //	Form feed	                //	12
  8,   //	Carriage return  	        //	13
  0,   //	Shift Out	                //	14
  0,   //	Shift In	                //	15
  0,   //	Data Link Escape	        //	16
  0,   //	Device Control 1 	        //	17
  0,   //	Device Control 2	        //	18
  0,   //	Device Control 3 	        //	19
  0,   //	Device Control 4	        //	20
  0,   //	Negative Acknowledgement  //	21
  0,   //	Synchronous idle	        //	22
  0,   //	End of Transmission Block //	23
  0,   //	Cancel	                  //	24
  0,   //	End of Medium	            //	25
  0,   //	Substitute	              //	26
  0,   //	Escape  	                //	27
  0,   //	File Separator	          //	28
  0,   //	Group Separator	          //	29
  0,   //	Record Separator	        //	30
  0,   //	Unit Separator	          //	31
  4,   //	space	                  //	32
  13,  //	!	                  //	33
  17,  //	"	                  //	34
  20,  //	#	                  //	35
  9,   //	$	                  //	36
  25,  //	%	                  //	37
  26,  //	&	                  //	38
  11,  //	'	                  //	39
  15,  //	(	                  //	40
  18,  //	)	                  //	41
  25,  //	*	                  //	42
  17,  //	+	                  //	43  //ITA2
  12,  //	,	                  //	44
  3,   //	-	                  //	45
  28,  //	.	                  //	46
  29,  //	/	                  //	47
  22,  //	0	                  //	48
  23,  //	1	                  //	49
  19,  //	2	                  //	50
  1,   //	3	                  //	51
  10,  //	4	                  //	52
  16,  //	5	                  //	53
  21,  //	6	                  //	54
  7,   //	7	                  //	55
  6,   //	8	                  //	56
  24,  //	9	                  //	57
  14,  //	:	                  //	58
  30,  //	;	                  //	59
  25,  //	<	                  //	60
  30,  //	=	                  //	61 //ITA2
  25,  //	>	                  //	62
  25,  //	?	                  //	63
  25,  //	@	                  //	64
  3,   //	A	                  //	65
  25,  //	B	                  //	66
  14,  //	C	                  //	67
  9,   //	D	                  //	68
  1,   //	E	                  //	69
  13,  //	F	                  //	70
  26,  //	G	                  //	71
  20,  //	H	                  //	72
  6,   //	I	                  //	73
  11,  //	J	                  //	74
  15,  //	K	                  //	75
  18,  //	L	                  //	76
  28,  //	M	                  //	77
  12,  //	N	                  //	78
  24,  //	O	                  //	79
  22,  //	P	                  //	80
  23,  //	Q	                  //	81
  10,  //	R	                  //	82
  5,   //	S	                  //	83
  16,  //	T	                  //	84
  7,   //	U	                  //	85
  30,  //	V	                  //	86
  19,  //	W	                  //	87
  29,  //	X	                  //	88
  21,  //	Y	                  //	89
  17,  //	Z	                  //	90
  15,  //	[ Used to start TX        //	91
  20,  //	\ Used to escape TX       //	92
  18,  //	] Buffered end TX         //	93
  25,  //	^	                  //	94
  4,   //	_	                  //	95
  25,  //	`	                  //	96
  3,   //	a	                  //	97
  25,  //	b	                  //	98
  14,  //	c	                  //	99
  9,   //	d	                  //	100
  1,   //	e	                  //	101
  13,  //	f	                  //	102
  26,  //	g	                  //	103
  20,  //	h	                  //	104
  6,   //	i	                  //	105
  11,  //	j	                  //	106
  15,  //	k	                  //	107
  18,  //	l	                  //	108
  28,  //	m	                  //	109
  12,  //	n	                  //	110
  24,  //	o	                  //	111
  22,  //	p	                  //	112
  23,  //	q	                  //	113
  10,  //	r	                  //	114
  5,   //	s	                  //	115
  16,  //	t	                  //	116
  7,   //	u	                  //	117
  30,  //	v	                  //	118
  19,  //	w	                  //	119
  29,  //	x	                  //	120
  21,  //	y	                  //	121
  17,  //	z	                  //	122
  15,  //	{	                  //	123
  20,  //	|	                  //	124
  18,  //	}	                  //	125
  25   //	~ Command escape char     //	126
};


/*******************************************************
This section defines static runtime variables that affect
RTTY transmission.  They are NOT directly changeable by user 
commands because they can get ops into trouble.  They are
here for the tinkerer/experimenter in case you want access
to them at runtime.
********************************************************/

long serialSpeed = 9600;  //This is the speed for the serial
                          //(more likely USB) connection, 8-N-1

// Not user selectable, but USOS behavior can be changed here.
// We set this to TX extra shifts to be compatible with silly
// MMTTY default reciever
int usos = USOS_MMTTY_HACK;

int stopBits = STOP_BITS_1R5;  // TX 1.5 stop bits

/***************************************
Dynamic runtime variables these are minipulated with
user commands or during normal TX operation.
*****************************************/
float baudrate = 45.45;  //default--can be changed by user command

int pttLeadMillis = 150;  //time before first start bit
int pttTailMillis = 25;   //time after last stop bit


// Polarity--changed with user commands and stored in EEPROM
//boolean mark = LOW;    //High indicates +V on the FSK pin
//boolean space = HIGH;  //Low indicates 0V on the FSK pin
boolean mark = HIGH;  //High indicates +V on the FSK pin
boolean space = LOW;  //Low indicates 0V on the FSK pin

// Buffer management variables to handle TX text input
byte sendBufferArray[SEND_BUFFER_SIZE];  // size of TX buffer
byte sendBufferBytes = 0;                // number of bytes unsent in TX buffer
byte lastAsciiByteSent = 0;              // needed to echo back sent characters to terminal
boolean endWhenBufferEmpty = true;       //flag to kill TX when buffer empty (']')

byte currentShiftState = SHIFT_UNKNOWN;  //Keeps track of Letter/Figs state to determine
                                         //if we need to send shift chars

// boolean ptt = false;  // old one radio parm - Keeps track of PTT state (true = Transmitter is on)
boolean isR1_PTT = false;  // Keeps track of Radio 1 PTT state (true = Transmitter is on)
boolean isR2_PTT = false;  // Keeps track of Radio 2 PTT state (true = Transmitter is on)

volatile boolean isRxFlag = false;  //set by timer interrupt.  Set high every 1/2 bit
                                    //to indicate when we should exectute the bit-banging
                                    //routine.  This is handled in the main loop function.

boolean configurationMode = false;  //flag indicates if we are in the menu system or
                                    //in normal operation.

// timer interval must be defined as a Unsigned Long integer "L"
unsigned long FSKTIMER_INTERVAL_US = 11001L;  // default to 45.45 baud: 11001, 22002 == 45 baud 10000, 20000 = 50 baud  6666, 13332 == 75 baud



/**
* Handles configuration change commands by changing variables
* and writing new values to EEPROM.
*/
void handleConfigurationCommand(byte oneByte) {
  switch (oneByte) {
    case (COMMAND_POLARITY_MARK_HIGH):
      {
        mark = HIGH;
        space = LOW;
        EEPROM.write(ee_polarity_addr, COMMAND_POLARITY_MARK_HIGH);        
        break;
      }
    case (COMMAND_POLARITY_MARK_LOW):
      {
        mark = LOW;
        space = HIGH;
        EEPROM.write(ee_polarity_addr, COMMAND_POLARITY_MARK_LOW);
        break;
      }
    case (COMMAND_45BAUD):
      {
        baudrate = 45.45;
        FSKTIMER_INTERVAL_US = 11001;
        initTimer();
        EEPROM.write(ee_speed_addr, COMMAND_45BAUD);
        break;
      }
    case (COMMAND_50BAUD):
      {
        baudrate = 50.0;
        FSKTIMER_INTERVAL_US = 10000L;
        initTimer();
        EEPROM.write(ee_speed_addr, COMMAND_50BAUD);
        break;
      }
    case (COMMAND_75BAUD):
      {
        baudrate = 75.0;
        FSKTIMER_INTERVAL_US = 6666L;
        initTimer();
        EEPROM.write(ee_speed_addr, COMMAND_75BAUD);
        break;
      }
    case (COMMAND_DUMP_CONFIG):
      {
        // we dump it out below
        break;
      }
    default:
      {
        Serial.write("\nNot a recognized command. Exiting configuration mode.\n");
      }
  }
  #if defined(ARDUINO_RASPBERRY_PI_PICO_W) || defined(ARDUINO_RASPBERRY_PI_PICO) 
    EEPROM.commit();
  #endif
  displayConfiguration();
  configurationMode = false;
}

/**
* Loads speed and polarity from EEPROM 
*/
void eeLoad() {

  byte speedChar = EEPROM.read(ee_speed_addr);
  byte polarity  = EEPROM.read(ee_polarity_addr);

  if (polarity == COMMAND_POLARITY_MARK_LOW) {
    mark = LOW;
  } else {
    mark = HIGH;
  }
  space = !mark;

  switch (speedChar) {
    case (COMMAND_50BAUD):
      {
        baudrate = 50.0;
        break;
      }
    case (COMMAND_75BAUD):
      {
        baudrate = 75.0;
        break;
      }
    default:
      {
        baudrate = 45.45;
        break;
      }
  }
}

/**
* Init the timer to fire every *half* bit period.  This allows us 
* to have 1.5 stop bits if we want.
*/
void initTimer() {
  
  FSKTimer.stopTimer(); // if timer is running, stop it
  if (!FSKTimer.attachInterruptInterval(FSKTIMER_INTERVAL_US, timerISR)) {  // if init fails, print this to console
    Serial.println(F("Can't set FSKTimer. Select another freq. or timer"));
  }  
}  // end of Init Timer() --------------------------------------------------------------------------

bool timerISR(struct repeating_timer* t) {  // -----------------------------------------------------
  (void)t;
  isRxFlag = true;

  /* TEST stuff from examples ino file
  static bool toggle1 = false;

  #if (TIMER_INTERRUPT_DEBUG > 0)
    //timer interrupt toggles pin outputPin1
    Serial.print("R1 Pin ");
    Serial.print(outputPin1);
    Serial.println(toggle1 ? F(" ON") : F(" OFF"));
  #endif

  digitalWrite(outputPin1, toggle1);
  toggle1 = !toggle1;
*/
  return true;
}  // end of timerISR() FSK Timer Handler --------------------------------------------------------------------

/**
* Displays the configuration options on the console. keystroke ~?
*/
void displayConfigurationPrompt() {

  Serial.write("\nEnter configuration command.  Valid commands are:\n");
  Serial.write("   0    Set FSK polarity mark = HIGH\n");
  Serial.write("   1    Set FSK polarity mark = LOW\n");
  Serial.write("   4    Set 45.45 baud\n");
  Serial.write("   5    Set 50.0 baud\n");
  Serial.write("   7    Set 75.0 baud\n");
  Serial.write("\n   ?    Show current configuration\n");
}

/**
* Prints the current configuration the console
*/
void displayConfiguration() {
  Serial.write("\nBased on TinyFSK by K0SM v");
  Serial.write(VERSION);
  Serial.write("\nPorted to Pico-W by K8UT v");
  Serial.write(VERSION_pico);

  Serial.write("\nCurrent configuration:\n");
  Serial.write("   Speed (baud):  ");
  Serial.print(baudrate);
  Serial.write("\n");

  Serial.write("   Polarity       ");
  if (mark == LOW) {
    Serial.write(" mark = logical LOW");
  } else {
    Serial.write(" mark = logical HIGH");
  }
  Serial.write("\n");
}

/******************************************************************
* This called every half-bit period to figure out what to bit-bang
* out the FSK pin.  It is basically an incremental counter that
* counts half bit periods and toggles the bits of the baudot character
* as needed.  It bangs out the start bit, five symbol bits, and the 
* stop bit, which is 1.5 bits long (hence the need to have a timer
* counting half bits).
* The 5 bit RTTY character frame looks like this:
*
*       ||Start | LSB |  X  |  X  |  X  | MSB | Stop    ||
* bitPos:   -1     0     1     2     3     4      5
******************************************************************/
int sendingChar = LTRS_SHIFT;  // default--this is the "diddle character"
int stopBitCounter = 0;        // counts half-bits for stop bit
int bitPos = START_BIT_POS;    // -1 = Start bit
bool midBit = false;           // used as like an ignore flag--we usually don't
                               // toggle state in the middle of a bit.  The exception
                               // is the stop bit, which is often 1.5 bits long.
void processHalfBit() {

  //=====if (!ptt)  // old one radio parm - not transmitting, so just return--there's nothing to send.
  if (!isR1_PTT)  //Radio 1 not transmitting, so just return--there's nothing to send.
  {
    return;
  }

  if (midBit) {
    midBit = false;  // reset the flag.  Next time we need to send the next bit.
    return;
  }

  // it's time to bang out the next bit.  We check for the special cases
  // first.  If it's a start bit we always sent SPACE and if its a STOP bit
  // we always send MARK.
  if (bitPos == START_BIT_POS) {  // we have to send a start bit

    // If it is time to send a start bit, we grab the next character to send so
    // that it is ready the next time through the loop.  The next character
    // might be the TX_END_FLAG, in which case we need to turn off the transmitter.
    sendingChar = getNextSendChar();

    //===== need to expand R1 R2 if/when TinyFSK SO2R capable if (ptt) {
    if (isR1_PTT) {
      if (sendingChar == TX_END_FLAG)  //end of data to send
      {
        setPTT(false);
        return;
      } else {
        digitalWrite(R1_FSK_PIN, space);  //start bit is always space
        bitPos++;
        midBit = true;
      }
    }
  } else if (bitPos == STOP_BIT_POS)  // we have to send a stop bit
  {
    //if stopBitCounter == 0 we are at the beginning of a stop bit
    if (stopBitCounter == 0) {
      digitalWrite(R1_FSK_PIN, mark);
      stopBitCounter = stopBits;  //this determines # of half-bit periods we stay in stop bit
    } else                        // already in stop bit, just decrement
    {
      // stopBitCounter counts half-bit periods.  2 ==> one stop bit
      //                                          3 ==> 1.5 stop bits
      //                                          4 ==> two stop bits
      stopBitCounter--;
      if (stopBitCounter == 0)  // end of stop bit period
      {
        bitPos = START_BIT_POS;  // move on to start bit of next char

        //  If we just sent an explicit LTRS or FIGS shift, obviously we are in that state.  If USOS is turned on and we
        //  have sent a space character, we are implicitly in LTRS shift.
        if (sendingChar == LTRS_SHIFT || (usos == USOS_ON && sendingChar == 0x04))  //0x04 = Baudot space
        {
          currentShiftState = LTRS_SHIFT;
        } else if (sendingChar == FIGS_SHIFT) {
          currentShiftState = FIGS_SHIFT;
        }
      }
    }
  } else {
    // We are not sending a stop/start bit, so we send the next bit of the
    // of the character.
    bool b = (sendingChar & (0x01 << bitPos));  //LSB first
    if (b) {
      digitalWrite(R1_FSK_PIN, mark);
    } else {
      digitalWrite(R1_FSK_PIN, space);
    }
    bitPos++;
    midBit = true;
  }
}

/**
* Reset character buffer.  This is a helper routine when stop the 
* transmitter so that everything is back to initial states ready
* to bang out the first character.
*/
void resetChar() {
  sendingChar = LTRS_SHIFT;
  stopBitCounter = 0;
  bitPos = START_BIT_POS;
  midBit = false;
}

/**
*Wipes the send buffer. Helper function for aborting 
* a transmission.
*/
void resetSendBuffer() {
  for (int i = 0; i < SEND_BUFFER_SIZE; i++) {
    sendBufferArray[i] = 0;
  }
  sendBufferBytes = 0;
}

/**
* Adds a new byte to the transmit text buffer.  These
* are *ASCII* bytes from the terminal, not Baudot.
*/
void addToSendBuffer(byte newByte) {
  if (sendBufferBytes < SEND_BUFFER_SIZE) {
    sendBufferBytes++;
    sendBufferArray[sendBufferBytes - 1] = newByte;
  }
}

/**
* Gets the next Baudot (5-bit) char from the buffer.  This
* function will return LTRS or FIGS shift characters when
* needed depending on the current shift state and USOS setting.
*/
byte getNextSendChar() {

  byte rVal = LTRS_SHIFT;  //default "idle" or "diddles" when nothing to send

  if (sendBufferBytes > 0)  // there is still data in buffer to send
  {
    byte asciiByte = sendBufferArray[0];

    if (currentShiftState != LTRS_SHIFT && requiresLetters(asciiByte)) {
      //echo('_');
      return LTRS_SHIFT;
    } else if (currentShiftState != FIGS_SHIFT && requiresFigures(asciiByte)) {
      //echo('^');
      return FIGS_SHIFT;
    }
    // Special "robust" USOS case--send FIGS after a space even if already in FIGS state and next
    // character requires FIGS shift.  Note: when this is called
    // sendingChar is the char we just *finished* sending
    else if (usos == USOS_MMTTY_HACK && currentShiftState != LTRS_SHIFT && requiresFigures(asciiByte) && sendingChar == 0x04) {
      //echo('^');
      return FIGS_SHIFT;
    } else  //we don't need to send a shift character.  Just find the baudot equiv of the ascii symbol and return it.
    {
      rVal = asciiToBaudot[asciiByte];
      lastAsciiByteSent = asciiByte;
      sendBufferBytes--;
      if (sendBufferBytes > 0) {
        for (int i = 0; i < sendBufferBytes; i++) {
          sendBufferArray[i] = sendBufferArray[i + 1];
        }
      }
      echo(asciiByte);
    }
  } else  // the buffer is empty
  {
    if (endWhenBufferEmpty) {
      rVal = TX_END_FLAG;  // signals to stop the TX
    } else                 // slow typist?
    {
      if (currentShiftState == SHIFT_UNKNOWN) {
        rVal = LTRS_SHIFT;  //send LTRS idle if we haven't sent anything on this TX
      } else {
        rVal = currentShiftState;  // idle on LTRS or FIGS depending on what state we are in
      }
    }
  }
  return rVal;
}

/*
* returns whether or not this is a "letter".  Letters require LTRS
* shift preceding the byte if currently in FIGS mode.
*/
boolean requiresLetters(byte asciiByte) {
  return (asciiByte >= 'A' && asciiByte <= 'Z')
         || (asciiByte >= 'a' && asciiByte <= 'z');
}

/**
* Helper function to find out whether a particular byte
* needs the FIGS shift preceeding it.
*/
boolean requiresFigures(byte asciiByte) {
  return !requiresLetters(asciiByte)
         && (asciiByte != ASCII_NULL)  //null
         && (asciiByte != ASCII_LF)    //LF
         && (asciiByte != ASCII_CR)
         && (asciiByte != ' ');
}

/*
* Turns the PTT on or off and applies any delays that might exist.
*/
void setPTT(byte isPTT) {
  if (isPTT) {                       // PTT ON
    digitalWrite(R1_FSK_PIN, mark);  //always start in mark state
    digitalWrite(R1_PTT_PIN, HIGH);
    // we will stay in the mark state for some amount of time
    // before sending the first start bit of the first character
    delay(pttLeadMillis);
  } else {                          // PTT OFF
    digitalWrite(R1_PTT_PIN, LOW);  // drop PTT
    digitalWrite(R1_FSK_PIN, space);
    delay(pttTailMillis);
    stopBitCounter = 0;
    bitPos = -1;
    currentShiftState = SHIFT_UNKNOWN;

    lastAsciiByteSent = 0;
    Serial.write("\ncmd:\n");  // Tells N1MM that TX is finished
  }  
  isR1_PTT = isPTT;
}

/**
* Echo to the serial port.  This will show up in the user's terminal
* if he or she is watching.
*/
void echo(byte b) {
  Serial.write(b);
}

/*********************************************************************
Main execution
***********************************************************************/

/**
* Exectutes *once* at program start (when power applied or
* reset button pressed.  Note that many Arudino devices have a 
* "software reset" option that will reset the processor when
* the serial port is opened.
* It opens the port, configures the output pins, and loads
* configuration from EEPROM.
*/
void TinyFSKsetup() {  // ==============================================================================================
  



  #ifdef __LGT8FX8P__
    /* LGT chip emulates EEPROM at the cost of giving up twice the space in program flash memory.
     * Unortunately, the last 4 bytes of every 1KB block are read-only. Therefore 
     * EEPROM.length() would return 1024 (readable EEPROM size), while EEPROM.size() returns 1020
     * (writable EEPROM size). The following line will give the right figure for LGT.
     */
    ee_speed_addr = EEPROM.size() - 1; 
    ee_polarity_addr = EEPROM.size() - 2; 
  #elif (!defined(ARDUINO_SAM_DUE) && !defined(ARDUINO_ARCH_MBED) && !defined(ARDUINO_RASPBERRY_PI_PICO_W) && !defined(ARDUINO_RASPBERRY_PI_PICO) && !defined(HARDWARE_GENERIC_STM32F103C)) || (defined(ARDUINO_SAM_DUE) && defined(FEATURE_EEPROM_E24C1024))
    ee_speed_addr = EEPROM.length() - 1; 
    ee_polarity_addr = EEPROM.length() - 2; 
  #elif defined(HARDWARE_GENERIC_STM32F103C)
    ee_speed_addr = 252; 
    ee_polarity_addr = 253;   
  #elif defined(ARDUINO_RASPBERRY_PI_PICO_W) || defined(ARDUINO_RASPBERRY_PI_PICO)
    ee_speed_addr = 4094; 
    ee_polarity_addr = 4095;   
    EEPROM.begin(4096);  
  #else
    // assume eeprom size of 1024 and hope for the best
    ee_speed_addr = 1022; 
    ee_polarity_addr = 1023;  
  #endif


  Serial.begin(serialSpeed);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for Leonardo only
  }
  
  // configure Radio 1 and Radio 2 FSK and PTT pins as outputs
  pinMode(R1_FSK_PIN, OUTPUT);
  pinMode(R1_PTT_PIN, OUTPUT);
  pinMode(R2_FSK_PIN, OUTPUT);
  pinMode(R2_PTT_PIN, OUTPUT);

  eeLoad();
  displayConfiguration();

  // start the half-bit timer.
  initTimer();

  Serial.write("\ncmd:\n");  // Tell N1MM we are in "RX" mode.  This will be sent
                             // at the end of transmission.
}  // end of SETUP() ===============================================================================

/** 
* Main loop.  This loop does two things:
* (1) Process any input from the serial connection one byte at a time.
*
* (2) If the half-bit timer interrupt fired we need to execute the bit-banging
* routine to keep clocking out RTTY.
*/
void TinyFSKloop() {  // =================================================================================

  // (1) Now read *one* byte from serial port if anything is there.
  // We only read one byte so as not to bog down the processor if
  // hundreds of bytes arrive all at once.  If there is more to read
  // it will be picked up once each time through the loop.
  if (Serial.available() > 0) {
    // get incoming byte:
    byte oneByte = Serial.read();

    // if we are in configuration mode, this byte is likely intended to change
    // a configuration setting.
    if (configurationMode) {
      handleConfigurationCommand(oneByte);
    } else  //not in configuration mode
    {
      // check for TX abort character.  This immediately kills the
      // transmitter and dumps anything remaining in the buffer.
      if (oneByte == TX_ABORT) {
        setPTT(false);
        resetSendBuffer();
        endWhenBufferEmpty = true;
        return;
      } else if (oneByte == TX_ON) {
        // The set PTT method has a delay
        // in it so that there is a chance for another character to
        // arrive in the input buffer.  We return immediately here
        // so that we can pick it up at the top of this loop.  If we
        // didn't do this, we would like continue on, see the buffer
        //is empty, and transmit a diddle before the first real character.
        endWhenBufferEmpty = false;
        setPTT(true);
        return;  //return to beginning of loop to pick up first char if any
      } else if (oneByte == TX_END) {
        endWhenBufferEmpty = true;
      } else if (oneByte == COMMAND_ESCAPE) {
        configurationMode = true;
        displayConfigurationPrompt();
      } else  // character to TX, so add to send buffer
      {
        addToSendBuffer(oneByte);
      }
    }
  }

  // (2) if the ISR fired we need may need to bit-bang something out the the FSK port
  if (isRxFlag) {
    processHalfBit();
    isRxFlag = false;
  }
}  // end of program LOOP()  =======================================================================
