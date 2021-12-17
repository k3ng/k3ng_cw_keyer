// ---------------------------------------------------------------------------
// NewTone Library - v1.0 - 01/20/2013
//
// AUTHOR/LICENSE:
// Created by Tim Eckel - teckel@leethost.com
// Copyright 2013 License: GNU GPL v3 http://www.gnu.org/licenses/gpl-3.0.html
//
// LINKS:
// Project home: http://code.google.com/p/arduino-new-tone/
// Blog: http://arduino.cc/forum/index.php/XXX
//
// DISCLAIMER:
// This software is furnished "as is", without technical support, and with no 
// warranty, express or implied, as to its usefulness for any purpose.
//
// PURPOSE:
// Almost 1,300 bytes smaller code size than the Tone library. Faster execution
// time. Exclusive use of port registers for fastest and smallest code. Higher
// quality sound output than tone library. Plug-in replacement for Tone. Uses
// timer 1 which may free up conflicts with the tone library.
//
// SYNTAX:
//   NewTone( pin, frequency [, length ] ) - Play a note on pin at frequency in Hz.
//     Parameters:
//       * pin        - Pin speaker is wired to (other wire to ground, be sure to add an inline 100 ohm resistor).
//       * frequency  - Play the specified frequency indefinitely, turn off with noNewTone().
//       * length     - [optional] Set the length to play in milliseconds. (default: 0 [forever], range: 0 to 2^32-1)
//   noNewTone(pin) - Stop playing note (pin is optional, will always stop playing on pin that was last used).
//
// HISTORY:
// 01/20/2013 v1.0 - Initial release.
//
// ---------------------------------------------------------------------------

#ifndef NewTone_h
  #define NewTone_h

  #if defined(ARDUINO) && ARDUINO >= 100
    #include <Arduino.h>
  #else
    #include <WProgram.h>
  #endif

  #if defined(__AVR_ATmega8__) || defined(__AVR_ATmega128__)
    #define TIMSK1 TIMSK
  #endif

  void NewTone(uint8_t pin, unsigned long frequency, unsigned long length = 0);
  void noNewTone(uint8_t pin = 0);
#endif