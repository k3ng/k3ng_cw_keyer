/*
  E24C1024.cpp
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

// Note: This is written for Arduino versions before 1.0. If you are using Arduino 1.0 and above
// then you need to change Wire.Send to Wire.write and Wire.receive to Wire.read

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Wire.h>
#include "E24C1024.h"

E24C1024::E24C1024(void)
{
   Wire.begin();
}

void E24C1024::write(unsigned long dataAddress, uint8_t data)
{
   Wire.beginTransmission((uint8_t)((0x500000 | dataAddress) >> 16)); // B1010xxx
   Wire.write((uint8_t)((dataAddress & WORD_MASK) >> 8)); // MSB
   Wire.write((uint8_t)(dataAddress & 0xFF)); // LSB
   Wire.write(data);
   Wire.endTransmission();
   delay(5);
}

uint8_t E24C1024::read(unsigned long dataAddress)
{
   uint8_t data = 0x00;
   Wire.beginTransmission((uint8_t)((0x500000 | dataAddress) >> 16)); // B1010xxx
   Wire.write((uint8_t)((dataAddress & WORD_MASK) >> 8)); // MSB
   Wire.write((uint8_t)(dataAddress & 0xFF)); // LSB
   Wire.endTransmission();
   Wire.requestFrom(0x50,1);
   if (Wire.available()) data = Wire.read();
   return data;
}

E24C1024 EEPROM1024;
