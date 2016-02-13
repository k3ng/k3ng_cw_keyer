#ifndef E24C1024_h
#define E24C1024_h
/*
  E24C1024.h
  AT24C1024 Library for Arduino 
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  US

  This library is based on several projects:
 
  The Arduino EEPROM library found here:  
  http://arduino.cc/en/Reference/EEPROM

  The 24C256 library found here:
  http://www.arduino.cc/playground/Code/I2CEEPROM

  The 24C512 library found here:
  http://www.arduino.cc/playground/Code/I2CEEPROM24LC512

  Our project page is here:
  http://www.arduino.cc/playground/Code/I2CEEPROM24C1024
  
  From the datasheet:

  The AT24C1024B provides 1,048,576 bits of serial electrically 
  erasable and programmable read only memory (EEPROM) organized 
  as 131,072 words of 8 bits each. The device’s cascadable 
  feature allows up to four devices to share a common two-wire 
  bus.
  
  http://www.atmel.com/dyn/resources/prod_documents/doc5194.pdf
  
*/


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Wire.h>
#define FULL_MASK 0x7FFFF
#define DEVICE_MASK 0x7F0000
#define WORD_MASK 0xFFFF
class E24C1024
{
  public:
    E24C1024();
    static void write(unsigned long, uint8_t);
    static uint8_t read(unsigned long);
};

extern E24C1024 EEPROM1024;

#endif
