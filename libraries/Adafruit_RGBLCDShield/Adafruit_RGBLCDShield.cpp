/*************************************************** 
  This is a library for the Adafruit RGB 16x2 LCD Shield 
  Pick one up at the Adafruit shop!
  ---------> http://http://www.adafruit.com/products/714

  The shield uses I2C to communicate, 2 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/


#include "Adafruit_RGBLCDShield.h"

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <Wire.h>

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

// When the display powers up, it is configured as follows:
//
// 1. Display clear
// 2. Function set: 
//    DL = 1; 8-bit interface data 
//    N = 0; 1-line display 
//    F = 0; 5x8 dot character font 
// 3. Display on/off control: 
//    D = 0; Display off 
//    C = 0; Cursor off 
//    B = 0; Blinking off 
// 4. Entry mode set: 
//    I/D = 1; Increment by 1 
//    S = 0; No shift 
//
// Note, however, that resetting the Arduino doesn't reset the LCD, so we
// can't assume that its in that state when a sketch starts (and the
// RGBLCDShield constructor is called).

Adafruit_RGBLCDShield::Adafruit_RGBLCDShield() {
  _i2cAddr = 0;

  _displayfunction = LCD_4BITMODE | LCD_1LINE | LCD_5x8DOTS;
  
  // the I/O expander pinout
  _rs_pin = 15;
  _rw_pin = 14;
  _enable_pin = 13;
  _data_pins[0] = 12;  // really d4
  _data_pins[1] = 11;  // really d5
  _data_pins[2] = 10;  // really d6
  _data_pins[3] = 9;  // really d7
  
  _button_pins[0] = 0;
  _button_pins[1] = 1;
  _button_pins[2] = 2;
  _button_pins[3] = 3;
  _button_pins[4] = 4;
  // we can't begin() yet :(
}




void Adafruit_RGBLCDShield::init(uint8_t fourbitmode, uint8_t rs, uint8_t rw, uint8_t enable,
			 uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
			 uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
{
  _rs_pin = rs;
  _rw_pin = rw;
  _enable_pin = enable;
  
  _data_pins[0] = d0;
  _data_pins[1] = d1;
  _data_pins[2] = d2;
  _data_pins[3] = d3; 
  _data_pins[4] = d4;
  _data_pins[5] = d5;
  _data_pins[6] = d6;
  _data_pins[7] = d7; 

  _i2cAddr = 255;

  _pinMode(_rs_pin, OUTPUT);
  // we can save 1 pin by not using RW. Indicate by passing 255 instead of pin#
  if (_rw_pin != 255) { 
    _pinMode(_rw_pin, OUTPUT);
  }
  _pinMode(_enable_pin, OUTPUT);
  

  if (fourbitmode)
    _displayfunction = LCD_4BITMODE | LCD_1LINE | LCD_5x8DOTS;
  else 
    _displayfunction = LCD_8BITMODE | LCD_1LINE | LCD_5x8DOTS;
  
  begin(16, 1);  
}

void Adafruit_RGBLCDShield::begin(uint8_t cols, uint8_t lines, uint8_t dotsize) {
  // check if i2c
  if (_i2cAddr != 255) {
    //_i2c.begin(_i2cAddr);
    Wire.begin();
    _i2c.begin();

    _i2c.pinMode(8, OUTPUT);
    _i2c.pinMode(6, OUTPUT);
    _i2c.pinMode(7, OUTPUT);
    setBacklight(0x7);

    if (_rw_pin)
      _i2c.pinMode(_rw_pin, OUTPUT);

    _i2c.pinMode(_rs_pin, OUTPUT);
    _i2c.pinMode(_enable_pin, OUTPUT);
    for (uint8_t i=0; i<4; i++) 
      _i2c.pinMode(_data_pins[i], OUTPUT);

    for (uint8_t i=0; i<5; i++) {
      _i2c.pinMode(_button_pins[i], INPUT);
      _i2c.pullUp(_button_pins[i], 1);
    }
  }

  if (lines > 1) {
    _displayfunction |= LCD_2LINE;
  }
  _numlines = lines;
  _currline = 0;

  // for some 1 line displays you can select a 10 pixel high font
  if ((dotsize != 0) && (lines == 1)) {
    _displayfunction |= LCD_5x10DOTS;
  }

  // SEE PAGE 45/46 FOR INITIALIZATION SPECIFICATION!
  // according to datasheet, we need at least 40ms after power rises above 2.7V
  // before sending commands. Arduino can turn on way befer 4.5V so we'll wait 50
  delayMicroseconds(50000); 
  // Now we pull both RS and R/W low to begin commands
  _digitalWrite(_rs_pin, LOW);
  _digitalWrite(_enable_pin, LOW);
  if (_rw_pin != 255) { 
    _digitalWrite(_rw_pin, LOW);
  }
  
  //put the LCD into 4 bit or 8 bit mode
  if (! (_displayfunction & LCD_8BITMODE)) {
    // this is according to the hitachi HD44780 datasheet
    // figure 24, pg 46

    // we start in 8bit mode, try to set 4 bit mode
    write4bits(0x03);
    delayMicroseconds(4500); // wait min 4.1ms

    // second try
    write4bits(0x03);
    delayMicroseconds(4500); // wait min 4.1ms
    
    // third go!
    write4bits(0x03); 
    delayMicroseconds(150);

    // finally, set to 8-bit interface
    write4bits(0x02); 
  } else {
    // this is according to the hitachi HD44780 datasheet
    // page 45 figure 23

    // Send function set command sequence
    command(LCD_FUNCTIONSET | _displayfunction);
    delayMicroseconds(4500);  // wait more than 4.1ms

    // second try
    command(LCD_FUNCTIONSET | _displayfunction);
    delayMicroseconds(150);

    // third go
    command(LCD_FUNCTIONSET | _displayfunction);
  }

  // finally, set # lines, font size, etc.
  command(LCD_FUNCTIONSET | _displayfunction);  

  // turn the display on with no cursor or blinking default
  _displaycontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;  
  display();

  // clear it off
  clear();

  // Initialize to default text direction (for romance languages)
  _displaymode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
  // set the entry mode
  command(LCD_ENTRYMODESET | _displaymode);

}

/********** high level commands, for the user! */
void Adafruit_RGBLCDShield::clear()
{
  command(LCD_CLEARDISPLAY);  // clear display, set cursor position to zero
  delayMicroseconds(2000);  // this command takes a long time!
}

void Adafruit_RGBLCDShield::home()
{
  command(LCD_RETURNHOME);  // set cursor position to zero
  delayMicroseconds(2000);  // this command takes a long time!
}

void Adafruit_RGBLCDShield::setCursor(uint8_t col, uint8_t row)
{
  int row_offsets[] = { 0x00, 0x40, 0x14, 0x54 };
  if ( row > _numlines ) {
    row = _numlines-1;    // we count rows starting w/0
  }
  
  command(LCD_SETDDRAMADDR | (col + row_offsets[row]));
}

// Turn the display on/off (quickly)
void Adafruit_RGBLCDShield::noDisplay() {
  _displaycontrol &= ~LCD_DISPLAYON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void Adafruit_RGBLCDShield::display() {
  _displaycontrol |= LCD_DISPLAYON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turns the underline cursor on/off
void Adafruit_RGBLCDShield::noCursor() {
  _displaycontrol &= ~LCD_CURSORON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void Adafruit_RGBLCDShield::cursor() {
  _displaycontrol |= LCD_CURSORON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turn on and off the blinking cursor
void Adafruit_RGBLCDShield::noBlink() {
  _displaycontrol &= ~LCD_BLINKON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void Adafruit_RGBLCDShield::blink() {
  _displaycontrol |= LCD_BLINKON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// These commands scroll the display without changing the RAM
void Adafruit_RGBLCDShield::scrollDisplayLeft(void) {
  command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVELEFT);
}
void Adafruit_RGBLCDShield::scrollDisplayRight(void) {
  command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVERIGHT);
}

// This is for text that flows Left to Right
void Adafruit_RGBLCDShield::leftToRight(void) {
  _displaymode |= LCD_ENTRYLEFT;
  command(LCD_ENTRYMODESET | _displaymode);
}

// This is for text that flows Right to Left
void Adafruit_RGBLCDShield::rightToLeft(void) {
  _displaymode &= ~LCD_ENTRYLEFT;
  command(LCD_ENTRYMODESET | _displaymode);
}

// This will 'right justify' text from the cursor
void Adafruit_RGBLCDShield::autoscroll(void) {
  _displaymode |= LCD_ENTRYSHIFTINCREMENT;
  command(LCD_ENTRYMODESET | _displaymode);
}

// This will 'left justify' text from the cursor
void Adafruit_RGBLCDShield::noAutoscroll(void) {
  _displaymode &= ~LCD_ENTRYSHIFTINCREMENT;
  command(LCD_ENTRYMODESET | _displaymode);
}

// Allows us to fill the first 8 CGRAM locations
// with custom characters
void Adafruit_RGBLCDShield::createChar(uint8_t location, uint8_t charmap[]) {
  location &= 0x7; // we only have 8 locations 0-7
  command(LCD_SETCGRAMADDR | (location << 3));
  for (int i=0; i<8; i++) {
    write(charmap[i]);
  }
  command(LCD_SETDDRAMADDR);  // unfortunately resets the location to 0,0
}

/*********** mid level commands, for sending data/cmds */

inline void Adafruit_RGBLCDShield::command(uint8_t value) {
  send(value, LOW);
}

#if ARDUINO >= 100
inline size_t Adafruit_RGBLCDShield::write(uint8_t value) {
  send(value, HIGH);
  return 1;
}
#else
inline void Adafruit_RGBLCDShield::write(uint8_t value) {
  send(value, HIGH);
}
#endif

/************ low level data pushing commands **********/

// little wrapper for i/o writes
void  Adafruit_RGBLCDShield::_digitalWrite(uint8_t p, uint8_t d) {
  if (_i2cAddr != 255) {
    // an i2c command
    _i2c.digitalWrite(p, d);
  } else {
    // straightup IO
    digitalWrite(p, d);
  }
}

// Allows to set the backlight, if the LCD backpack is used
void Adafruit_RGBLCDShield::setBacklight(uint8_t status) {
  // check if i2c or SPI
  _i2c.digitalWrite(8, ~(status >> 2) & 0x1);
  _i2c.digitalWrite(7, ~(status >> 1) & 0x1);
  _i2c.digitalWrite(6, ~status & 0x1);
}

// little wrapper for i/o directions
void  Adafruit_RGBLCDShield::_pinMode(uint8_t p, uint8_t d) {
  if (_i2cAddr != 255) {
    // an i2c command
    _i2c.pinMode(p, d);
  } else {
    // straightup IO
    pinMode(p, d);
  }
}

// write either command or data, with automatic 4/8-bit selection
void Adafruit_RGBLCDShield::send(uint8_t value, uint8_t mode) {
  _digitalWrite(_rs_pin, mode);

  // if there is a RW pin indicated, set it low to Write
  if (_rw_pin != 255) { 
    _digitalWrite(_rw_pin, LOW);
  }
  
  if (_displayfunction & LCD_8BITMODE) {
    write8bits(value); 
  } else {
    write4bits(value>>4);
    write4bits(value);
  }
}

void Adafruit_RGBLCDShield::pulseEnable(void) {
  _digitalWrite(_enable_pin, LOW);
  delayMicroseconds(1);    
  _digitalWrite(_enable_pin, HIGH);
  delayMicroseconds(1);    // enable pulse must be >450ns
  _digitalWrite(_enable_pin, LOW);
  delayMicroseconds(100);   // commands need > 37us to settle
}

void Adafruit_RGBLCDShield::write4bits(uint8_t value) {
  if (_i2cAddr != 255) {
    uint16_t out = 0;

    out = _i2c.readGPIOAB();

    // speed up for i2c since its sluggish
    for (int i = 0; i < 4; i++) {
      out &= ~_BV(_data_pins[i]);
      out |= ((value >> i) & 0x1) << _data_pins[i];
    }

    // make sure enable is low
    out &= ~ _BV(_enable_pin);

    _i2c.writeGPIOAB(out);

    // pulse enable
    delayMicroseconds(1);
    out |= _BV(_enable_pin);
    _i2c.writeGPIOAB(out);
    delayMicroseconds(1);
    out &= ~_BV(_enable_pin);
    _i2c.writeGPIOAB(out);   
    delayMicroseconds(100);

  } else {
    for (int i = 0; i < 4; i++) {
     _pinMode(_data_pins[i], OUTPUT);
     _digitalWrite(_data_pins[i], (value >> i) & 0x01);
    }
    pulseEnable();
  }
}

void Adafruit_RGBLCDShield::write8bits(uint8_t value) {
  for (int i = 0; i < 8; i++) {
    _pinMode(_data_pins[i], OUTPUT);
    _digitalWrite(_data_pins[i], (value >> i) & 0x01);
  }
  
  pulseEnable();
}

uint8_t Adafruit_RGBLCDShield::readButtons(void) {
  uint8_t reply = 0x1F;

  for (uint8_t i=0; i<5; i++) {
    reply &= ~((_i2c.digitalRead(_button_pins[i])) << i);
  }
  return reply;
}
