/*
  K3NG_PS2Keyboard.cpp - K3NG_PS2Keyboard library
  Copyright (c) 2007 Free Software Foundation.  All right reserved.
  Written by Christian Weichel <info@32leaves.net>


  - Modified 2011 Anthony Good anthony dot good at gmail dot com
  - Amateur Radio Operator K3NG
  - Modified for additional key codes to be returned and CTRL key combinations
  

  ** Mostly rewritten Paul Stoffregen <paul@pjrc.com> 2010, 2011
  ** Modified for use beginning with Arduino 13 by L. Abraham Smith, <n3bah@microcompdesign.com> * 
  ** Modified for easy interrup pin assignement on method begin(datapin,irq_pin). Cuningan <cuninganreset@gmail.com> **

  for more information you can read the original wiki in arduino.cc
  at http://www.arduino.cc/playground/Main/PS2Keyboard
  or http://www.pjrc.com/teensy/td_libs_PS2Keyboard.html

  Version 2.1 (May 2011)
  - timeout to recover from misaligned input
  - compatibility with Arduino "new-extension" branch
  - TODO: send function, proposed by Scott Penrose, scooterda at me dot com

  Version 2.0 (June 2010)
  - Buffering added, many scan codes can be captured without data loss
    if your sketch is busy doing other work
  - Shift keys supported, completely rewritten scan code to ascii
  - Slow linear search replaced with fast indexed table lookups
  - Support for Teensy, Arduino Mega, and Sanguino added

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
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

// K3NG Version 2015101401  

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h" // for attachInterrupt, FALLING
#else
#include "WProgram.h"
#endif
#include "K3NG_PS2Keyboard.h"

#define BUFFER_SIZE 45
static volatile uint8_t buffer[BUFFER_SIZE];
static volatile uint8_t head, tail;
static uint8_t ps2Keyboard_DataPin;
static char ps2Keyboard_CharBuffer=0;

// The ISR for the external interrupt
void k3ng_ps2interrupt(void)
{
	static uint8_t bitcount=0;
	static uint8_t incoming=0;
	static uint32_t prev_ms=0;
	uint32_t now_ms;
	uint8_t n, val;

	val = digitalRead(ps2Keyboard_DataPin);
	now_ms = millis();
	if (now_ms - prev_ms > 250) {
		bitcount = 0;
		incoming = 0;
	}
	prev_ms = now_ms;
	n = bitcount - 1;
	if (n <= 7) {
		incoming |= (val << n);
	}
	bitcount++;
	if (bitcount == 11) {
		uint8_t i = head + 1;
		if (i >= BUFFER_SIZE) i = 0;
		if (i != tail) {
			buffer[i] = incoming;
			head = i;
		}
		bitcount = 0;
		incoming = 0;
	}
}

static inline uint8_t get_scan_code(void)
{
	uint8_t c, i;

	i = tail;
	if (i == head) return 0;
	i++;
	if (i >= BUFFER_SIZE) i = 0;
	c = buffer[i];
	tail = i;
	return c;
}

// http://www.quadibloc.com/comp/scan.htm
// http://www.computer-engineering.org/ps2keyboard/scancodes2.html

#define BREAK     0x01
#define MODIFIER  0x02
#define SHIFT_L   0x04
#define SHIFT_R   0x08
#define CTRL      0x10
#define ALT       0x20


// These arrays provide a simple key map, to turn scan codes into ASCII
// output.  If a non-US keyboard is used, these may need to be modified
// for the desired output.
//

#ifdef OPTION_PS2_KEYBOARD_US
const PROGMEM unsigned char scan2ascii_noshift[] = {
	0, PS2_F9, 0, PS2_F5, PS2_F3, PS2_F1, PS2_F2, PS2_F12,
	0, PS2_F10, PS2_F8, PS2_F6, PS2_F4, PS2_TAB, '`', 0,
	0, PS2_LEFT_ALT /*Lalt*/, 0 /*Lshift*/, 0, 0 /*PS2_LEFT_CTRL*/ /*Lctrl*/, 'q', '1', 0,
	0, 0, 'z', 's', 'a', 'w', '2', 0,
	0, 'c', 'x', 'd', 'e', '4', '3', 0,
	0, ' ', 'v', 'f', 't', 'r', '5', 0,
	0, 'n', 'b', 'h', 'g', 'y', '6', 0,
	0, 0, 'm', 'j', 'u', '7', '8', 0,
	0, ',', 'k', 'i', 'o', '0', '9', 0,
	0, '.', '/', 'l', ';', 'p', '-', 0,
	0, 0, '\'', 0, '[', '=', 0, 0,
	0 /*CapsLock*/, 0 /*Rshift*/, PS2_ENTER /*Enter*/, ']', 0, '\\', 0, 0,
	0, 0, 0, 0, 0, 0, PS2_BACKSPACE, 0,
	0, '1', 0, '4', '7', 0, 0, 0,
	'0', '.', '2', '5', '6', '8', PS2_ESC, 0 /*NumLock*/,
	PS2_F11, '+', '3', '-', '*', '9', PS2_SCROLL, 0,
	0, 0, 0, PS2_F7 };
const PROGMEM unsigned char scan2ascii_shift[] = {
	0, PS2_F9_SHIFT, 0, PS2_F5_SHIFT, PS2_F3_SHIFT, PS2_F1_SHIFT, PS2_F2_SHIFT, PS2_F12_SHIFT,
	0, PS2_F10_SHIFT, PS2_F8_SHIFT, PS2_F6_SHIFT, PS2_F4_SHIFT, PS2_TAB_SHIFT, '~', 0,
	0, 0 /*Lalt*/, 0 /*Lshift*/, 0, 0 /*Lctrl*/, 'Q', '!', 0,
	0, 0, 'Z', 'S', 'A', 'W', '@', 0,
	0, 'C', 'X', 'D', 'E', '$', '#', 0,
	0, ' ', 'V', 'F', 'T', 'R', '%', 0,
	0, 'N', 'B', 'H', 'G', 'Y', '^', 0,
	0, 0, 'M', 'J', 'U', '&', '*', 0,
	0, '<', 'K', 'I', 'O', ')', '(', 0,
	0, '>', '?', 'L', ':', 'P', '_', 0,
	0, 0, '"', 0, '{', '+', 0, 0,
	0 /*CapsLock*/, 0 /*Rshift*/, PS2_ENTER_SHIFT /*Enter*/, '}', 0, '|', 0, 0,
	0, 0, 0, 0, 0, 0, PS2_BACKSPACE_SHIFT, 0,
	0, '1', 0, '4', '7', 0, 0, 0,
	'0', '.', '2', '5', '6', '8', PS2_ESC, 0 /*NumLock*/,
	PS2_F11_SHIFT, '+', '3', '-', '*', '9', PS2_SCROLL_SHIFT, 0,
	0, 0, 0, PS2_F7_SHIFT };
const PROGMEM unsigned char scan2ascii_ctrl[] = {
	0, PS2_F9_CTRL, 0, PS2_F5_CTRL, PS2_F3_CTRL, PS2_F1_CTRL, PS2_F2_CTRL, PS2_F12_CTRL,
	0, PS2_F10_CTRL, PS2_F8_CTRL, PS2_F6_CTRL, PS2_F4_CTRL, PS2_TAB_SHIFT, '~', 0,
	0, 0 /*Lalt*/, 0 /*Lshift*/, 0, 0 /*Lctrl*/, 'Q', '!', 0,
	0, 0, PS2_Z_CTRL, 'S', PS2_A_CTRL, PS2_W_CTRL, '@', 0,
	0, 'C', 'X', PS2_D_CTRL, PS2_E_CTRL, '$', '#', 0,
	0, ' ', 'V', 'F', PS2_T_CTRL, 'R', '%', 0,
	0, PS2_N_CTRL, PS2_B_CTRL, PS2_H_CTRL, PS2_G_CTRL, 'Y', '^', 0,
	0, 0, PS2_M_CTRL, 'J', PS2_U_CTRL, '&', '*', 0,
	0, '<', 'K', PS2_I_CTRL, PS2_O_CTRL, ')', '(', 0,
	0, '>', '?', 'L', ':', 'P', '_', 0,
	0, 0, '"', 0, '{', '+', 0, 0,
	0 /*CapsLock*/, 0 /*Rshift*/, PS2_ENTER_SHIFT /*Enter*/, '}', 0, '|', 0, 0,
	0, 0, 0, 0, 0, 0, PS2_BACKSPACE_SHIFT, 0,
	0, '1', 0, '4', '7', 0, 0, 0,
	'0', '.', '2', '5', '6', '8', PS2_ESC, 0 /*NumLock*/,
	PS2_F11_SHIFT, '+', '3', '-', '*', '9', PS2_SCROLL_SHIFT, 0,
	0, 0, 0, PS2_F7_SHIFT };
const PROGMEM unsigned char scan2ascii_alt[] = {
	0, PS2_F9_ALT, 0, PS2_F5_ALT, PS2_F3_ALT, PS2_F1_ALT, PS2_F2_ALT, PS2_F12_ALT,
	0, PS2_F10_ALT, PS2_F8_ALT, PS2_F6_ALT, PS2_F4_ALT, PS2_TAB_SHIFT, '~', 0,
	0, 0 /*Lalt*/, 0 /*Lshift*/, 0, 0 /*Lctrl*/, 'Q', '!', 0,
	0, 0, PS2_Z_CTRL, 'S', PS2_A_CTRL, PS2_W_CTRL, '@', 0,
	0, 'C', 'X', PS2_D_CTRL, PS2_E_CTRL, '$', '#', 0,
	0, ' ', 'V', 'F', PS2_T_CTRL, 'R', '%', 0,
	0, PS2_N_CTRL, PS2_B_CTRL, PS2_H_CTRL, PS2_G_CTRL, 'Y', '^', 0,
	0, 0, PS2_M_CTRL, 'J', PS2_U_CTRL, '&', '*', 0,
	0, '<', 'K', PS2_I_CTRL, PS2_O_CTRL, ')', '(', 0,
	0, '>', '?', 'L', ':', 'P', '_', 0,
	0, 0, '"', 0, '{', '+', 0, 0,
	0 /*CapsLock*/, 0 /*Rshift*/, PS2_ENTER /*Enter*/, '}', 0, '|', 0, 0,
	0, 0, 0, 0, 0, 0, PS2_BACKSPACE_SHIFT, 0,
	0, '1', 0, '4', '7', 0, 0, 0,
	'0', '.', '2', '5', '6', '8', PS2_ESC, 0 /*NumLock*/,
	PS2_F11_ALT, '+', '3', '-', '*', '9', PS2_SCROLL_SHIFT, 0,
	0, 0, 0, PS2_F7_ALT };
#endif //OPTION_PS2_KEYBOARD_US

	//--------------------------------------------------

#ifdef OPTION_PS2_KEYBOARD_GERMAN
 // without shift
const PROGMEM unsigned char scan2ascii_noshift[] =	
	{0, PS2_F9, 0, PS2_F5, PS2_F3, PS2_F1, PS2_F2, PS2_F12,
	0, PS2_F10, PS2_F8, PS2_F6, PS2_F4, PS2_TAB, '^', 0,
	0, 0 /*Lalt*/, 0 /*Lshift*/, 0, 0 /*Lctrl*/, 'q', '1', 0,
	0, 0, 'y', 's', 'a', 'w', '2', 0,
	0, 'c', 'x', 'd', 'e', '4', '3', 0,
	0, ' ', 'v', 'f', 't', 'r', '5', 0,
	0, 'n', 'b', 'h', 'g', 'z', '6', 0,
	0, 0, 'm', 'j', 'u', '7', '8', 0,
	0, ',', 'k', 'i', 'o', '0', '9', 0,
	0, '.', '-', 'l', PS2_o_DIAERESIS, 'p', PS2_SHARP_S, 0,
	0, 0, PS2_a_DIAERESIS, 0, PS2_u_DIAERESIS, '\'', 0, 0,
	0 /*CapsLock*/, 0 /*Rshift*/, PS2_ENTER /*Enter*/, '+', 0, '#', 0, 0,
	0, '<', 0, 0, 0, 0, PS2_BACKSPACE, 0,
	0, '1', 0, '4', '7', 0, 0, 0,
	'0', '.', '2', '5', '6', '8', PS2_ESC, 0 /*NumLock*/,
	PS2_F11, '+', '3', '-', '*', '9', PS2_SCROLL, 0,
	0, 0, 0, PS2_F7 };
  // with shift
const PROGMEM unsigned char scan2ascii_shift[] = 	
	{0, PS2_F9_SHIFT, 0, PS2_F5_SHIFT, PS2_F3_SHIFT, PS2_F1_SHIFT, PS2_F2_SHIFT, PS2_F12_SHIFT,
	0, PS2_F10_SHIFT, PS2_F8_SHIFT, PS2_F6_SHIFT, PS2_F4_SHIFT, PS2_TAB_SHIFT, PS2_DEGREE_SIGN, 0,
	0, 0 /*Lalt*/, 0 /*Lshift*/, 0, 0 /*Lctrl*/, 'Q', '!', 0,
	0, 0, 'Y', 'S', 'A', 'W', '"', 0,
	0, 'C', 'X', 'D', 'E', '$', PS2_SECTION_SIGN, 0,
	0, ' ', 'V', 'F', 'T', 'R', '%', 0,
	0, 'N', 'B', 'H', 'G', 'Z', '&', 0,
	0, 0, 'M', 'J', 'U', '/', '(', 0,
	0, ';', 'K', 'I', 'O', '=', ')', 0,
	0, ':', '_', 'L', PS2_O_DIAERESIS, 'P', '?', 0,
	0, 0, PS2_A_DIAERESIS, 0, PS2_U_DIAERESIS, '`', 0, 0,
	0 /*CapsLock*/, 0 /*Rshift*/, PS2_ENTER /*Enter*/, '*', 0, '\'', 0, 0,
	0, '>', 0, 0, 0, 0, PS2_BACKSPACE, 0,
	0, '1', 0, '4', '7', 0, 0, 0,
	'0', '.', '2', '5', '6', '8', PS2_ESC, 0 /*NumLock*/,
	PS2_F11_SHIFT, '+', '3', '-', '*', '9', PS2_SCROLL, 0,
	0, 0, 0, PS2_F7_SHIFT };
const PROGMEM unsigned char scan2ascii_ctrl[] =  // this needs to be updated!!! (it is copy of US)
	{0, PS2_F9_CTRL, 0, PS2_F5_CTRL, PS2_F3_CTRL, PS2_F1_CTRL, PS2_F2_CTRL, PS2_F12_CTRL,
	0, PS2_F10_CTRL, PS2_F8_CTRL, PS2_F6_CTRL, PS2_F4_CTRL, PS2_TAB_SHIFT, '~', 0,
	0, 0 /*Lalt*/, 0 /*Lshift*/, 0, 0 /*Lctrl*/, 'Q', '!', 0,
	0, 0, PS2_Z_CTRL, 'S', PS2_A_CTRL, PS2_W_CTRL, '@', 0,
	0, 'C', 'X', PS2_D_CTRL, PS2_E_CTRL, '$', '#', 0,
	0, ' ', 'V', 'F', PS2_T_CTRL, 'R', '%', 0,
	0, PS2_N_CTRL, PS2_B_CTRL, PS2_H_CTRL, PS2_G_CTRL, 'Y', '^', 0,
	0, 0, PS2_M_CTRL, 'J', PS2_U_CTRL, '&', '*', 0,
	0, '<', 'K', PS2_I_CTRL, PS2_O_CTRL, ')', '(', 0,
	0, '>', '?', 'L', ':', 'P', '_', 0,
	0, 0, '"', 0, '{', '+', 0, 0,
	0 /*CapsLock*/, 0 /*Rshift*/, PS2_ENTER_SHIFT /*Enter*/, '}', 0, '|', 0, 0,
	0, 0, 0, 0, 0, 0, PS2_BACKSPACE_SHIFT, 0,
	0, '1', 0, '4', '7', 0, 0, 0,
	'0', '.', '2', '5', '6', '8', PS2_ESC, 0 /*NumLock*/,
	PS2_F11_CTRL, '+', '3', '-', '*', '9', PS2_SCROLL_SHIFT, 0,
	0, 0, 0, PS2_F7_CTRL};	
  // with altgr
const PROGMEM unsigned char scan2ascii_alt[] = 	
	{0, PS2_F9_ALT, 0, PS2_F5_ALT, PS2_F3_ALT, PS2_F1_ALT, PS2_F2_ALT, PS2_F12_ALT,
	0, PS2_F10_ALT, PS2_F8_ALT, PS2_F6_ALT, PS2_F4_ALT, PS2_TAB, 0, 0,
	0, 0 /*Lalt*/, 0 /*Lshift*/, 0, 0 /*Lctrl*/, '@', 0, 0,
	0, 0, 0, 0, 0, 0, PS2_SUPERSCRIPT_TWO, 0,
	0, 0, 0, 0, PS2_CURRENCY_SIGN, 0, PS2_SUPERSCRIPT_THREE, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, PS2_MICRO_SIGN, 0, 0, '{', '[', 0,
	0, 0, 0, 0, 0, '}', ']', 0,
	0, 0, 0, 0, 0, 0, '\\', 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0 /*CapsLock*/, 0 /*Rshift*/, PS2_ENTER /*Enter*/, '~', 0, '#', 0, 0,
	0, '|', 0, 0, 0, 0, PS2_BACKSPACE, 0,
	0, '1', 0, '4', '7', 0, 0, 0,
	'0', '.', '2', '5', '6', '8', PS2_ESC, 0 /*NumLock*/,
	PS2_F11_ALT, '+', '3', '-', '*', '9', PS2_SCROLL, 0,
	0, 0, 0, PS2_F7_ALT};
#endif //OPTION_PS2_KEYBOARD_GERMAN

	//--------------------------------------------------
	
#ifdef OPTION_PS2_KEYBOARD_FRENCH
const PROGMEM unsigned char scan2ascii_noshift[] =
	{0, PS2_F9, 0, PS2_F5, PS2_F3, PS2_F1, PS2_F2, PS2_F12,
	0, PS2_F10, PS2_F8, PS2_F6, PS2_F4, PS2_TAB, PS2_SUPERSCRIPT_TWO, 0,
	0, 0 /*Lalt*/, 0 /*Lshift*/, 0, 0 /*Lctrl*/, 'a', '&', 0,
	0, 0, 'w', 's', 'q', 'z', PS2_e_ACUTE, 0,
	0, 'c', 'x', 'd', 'e', '\'', '"', 0,
	0, ' ', 'v', 'f', 't', 'r', '(', 0,
	0, 'n', 'b', 'h', 'g', 'y', '-', 0,
	0, 0, ',', 'j', 'u', PS2_e_GRAVE, '_', 0,
	0, ';', 'k', 'i', 'o', PS2_a_GRAVE, PS2_c_CEDILLA, 0,
	0, ':', '!', 'l', 'm', 'p', ')', 0,
	0, 0, PS2_u_GRAVE, 0, '^', '=', 0, 0,
	0 /*CapsLock*/, 0 /*Rshift*/, PS2_ENTER /*Enter*/, '$', 0, '*', 0, 0,
	0, '<', 0, 0, 0, 0, PS2_BACKSPACE, 0,
	0, '1', 0, '4', '7', 0, 0, 0,
	'0', '.', '2', '5', '6', '8', PS2_ESC, 0 /*NumLock*/,
	PS2_F11, '+', '3', '-', '*', '9', PS2_SCROLL, 0,
	0, 0, 0, PS2_F7 };

  // with shift
const PROGMEM unsigned char scan2ascii_shift[] = 	
	{0, PS2_F9_SHIFT, 0, PS2_F5_SHIFT, PS2_F3_SHIFT, PS2_F1_SHIFT, PS2_F2_SHIFT, PS2_F12_SHIFT,
	0, PS2_F10_SHIFT, PS2_F8_SHIFT, PS2_F6_SHIFT, PS2_F4_SHIFT, PS2_TAB_SHIFT, 0, 0,
	0, 0 /*Lalt*/, 0 /*Lshift*/, 0, 0 /*Lctrl*/, 'A', '1', 0,
	0, 0, 'W', 'S', 'Q', 'Z', '2', 0,
	0, 'C', 'X', 'D', 'E', '4', '3', 0,
	0, ' ', 'V', 'F', 'T', 'R', '5', 0,
	0, 'N', 'B', 'H', 'G', 'Y', '6', 0,
	0, 0, '?', 'J', 'U', '7', '8', 0,
	0, '.', 'K', 'I', 'O', '0', '9', 0,
	0, '/', PS2_SECTION_SIGN, 'L', 'M', 'P', PS2_DEGREE_SIGN, 0,
	0, 0, '%', 0, PS2_DIAERESIS, '+', 0, 0,
	0 /*CapsLock*/, 0 /*Rshift*/, PS2_ENTER /*Enter*/, PS2_POUND_SIGN, 0, PS2_MICRO_SIGN, 0, 0,
	0, '>', 0, 0, 0, 0, PS2_BACKSPACE, 0,
	0, '1', 0, '4', '7', 0, 0, 0,
	'0', '.', '2', '5', '6', '8', PS2_ESC, 0 /*NumLock*/,
	PS2_F11_SHIFT, '+', '3', '-', '*', '9', PS2_SCROLL, 0,
	0, 0, 0, PS2_F7_SHIFT};
const PROGMEM unsigned char scan2ascii_ctrl[] =  // this needs to be updated!!! (it is copy of US)
	{0, PS2_F9_CTRL, 0, PS2_F5_CTRL, PS2_F3_CTRL, PS2_F1_CTRL, PS2_F2_CTRL, PS2_F12_CTRL,
	0, PS2_F10_CTRL, PS2_F8_CTRL, PS2_F6_CTRL, PS2_F4_CTRL, PS2_TAB, '~', 0,
	0, 0 /*Lalt*/, 0 /*Lshift*/, 0, 0 /*Lctrl*/, 'Q', '!', 0,
	0, 0, PS2_Z_CTRL, 'S', PS2_A_CTRL, PS2_W_CTRL, '@', 0,
	0, 'C', 'X', PS2_D_CTRL, PS2_E_CTRL, '$', '#', 0,
	0, ' ', 'V', 'F', PS2_T_CTRL, 'R', '%', 0,
	0, PS2_N_CTRL, PS2_B_CTRL, PS2_H_CTRL, PS2_G_CTRL, 'Y', '^', 0,
	0, 0, PS2_M_CTRL, 'J', PS2_U_CTRL, '&', '*', 0,
	0, '<', 'K', PS2_I_CTRL, PS2_O_CTRL, ')', '(', 0,
	0, '>', '?', 'L', ':', 'P', '_', 0,
	0, 0, '"', 0, '{', '+', 0, 0,
	0 /*CapsLock*/, 0 /*Rshift*/, PS2_ENTER_SHIFT /*Enter*/, '}', 0, '|', 0, 0,
	0, 0, 0, 0, 0, 0, PS2_BACKSPACE_SHIFT, 0,
	0, '1', 0, '4', '7', 0, 0, 0,
	'0', '.', '2', '5', '6', '8', PS2_ESC, 0 /*NumLock*/,
	PS2_F11_CTRL, '+', '3', '-', '*', '9', PS2_SCROLL_SHIFT, 0,
	0, 0, 0, PS2_F7_CTRL};	
const PROGMEM unsigned char scan2ascii_alt[] = 
  // with altgr
	{0, PS2_F9_ALT, 0, PS2_F5_ALT, PS2_F3_ALT, PS2_F1_ALT, PS2_F2_ALT, PS2_F12_ALT,
	0, PS2_F10_ALT, PS2_F8_ALT, PS2_F6_ALT, PS2_F4_ALT, PS2_TAB, 0, 0,
	0, 0 /*Lalt*/, 0 /*Lshift*/, 0, 0 /*Lctrl*/, '@', 0, 0,
	0, 0, 0, 0, 0, 0, '~', 0,
	0, 0, 0, 0, 0 /*PS2_EURO_SIGN*/, '{', '#', 0,
	0, 0, 0, 0, 0, 0, '[', 0,
	0, 0, 0, 0, 0, 0, '|', 0,
	0, 0, 0, 0, 0, '`', '\\', 0,
	0, 0, 0, 0, 0, '@', '^', 0,
	0, 0, 0, 0, 0, 0, ']', 0,
	0, 0, 0, 0, 0, 0, '}', 0,
	0 /*CapsLock*/, 0 /*Rshift*/, PS2_ENTER /*Enter*/, '¤', 0, '#', 0, 0,
	0, '|', 0, 0, 0, 0, PS2_BACKSPACE, 0,
	0, '1', 0, '4', '7', 0, 0, 0,
	'0', '.', '2', '5', '6', '8', PS2_ESC, 0 /*NumLock*/,
	PS2_F11_ALT, '+', '3', '-', '*', '9', PS2_SCROLL, 0,
	0, 0, 0, PS2_F7_ALT};


#endif //OPTION_PS2_KEYBOARD_FRENCH

//--------------------------------------------------

static char get_ascii_code(void)
{
	static uint8_t state=0;
	uint8_t s;
	char c;

	while (1) {
		s = get_scan_code();
		if (!s) return 0;
		if (s == 0xF0) {
			state |= BREAK;
		} else if (s == 0xE0) {
			state |= MODIFIER;
		} else {
			if (state & BREAK) {
				if (s == 0x12) {
					state &= ~SHIFT_L;
				} else if (s == 0x59) {
					state &= ~SHIFT_R;
                                //start K3NG modification
				} else if (s == 0x14) {
                                        state &= ~CTRL;
                                } else if (s == 0x11) {
                                        state &= ~ALT;
                                }
                                // end K3NG modification
				state &= ~(BREAK | MODIFIER);
				continue;
			}
			if (s == 0x12) {
				state |= SHIFT_L;
				continue;
			} else if (s == 0x59) {
				state |= SHIFT_R;
				continue;
			} else if (s == 0x14) {
                                state |= CTRL;
                                continue;
			} else if (s == 0x11) {
                                state |= ALT;
                                continue;
                        }
			c = 0;
			if (state & MODIFIER) {
				switch (s) {
				  case 0x70: c = PS2_INSERT;      break;
				  case 0x6C: c = PS2_HOME;        break;
				  case 0x7D: c = PS2_PAGEUP;      break;
				  case 0x71: c = PS2_DELETE;      break;
				  case 0x69: c = PS2_END;         break;
				  case 0x7A: c = PS2_PAGEDOWN;    break;
				  case 0x75: c = PS2_UPARROW;     break;
				  case 0x6B: c = PS2_LEFTARROW;   break;
				  case 0x72: c = PS2_DOWNARROW;   break;
				  case 0x74: c = PS2_RIGHTARROW;  break;
				  case 0x4A: c = '/';             break;
				  case 0x5A: c = PS2_ENTER;       break;
				  default: break;
				}
			} else if (state & (SHIFT_L | SHIFT_R)) {
				if (s < sizeof(scan2ascii_shift))
					c = pgm_read_byte(scan2ascii_shift + s);
                        //start K3NG modification
                        } else if ((state & CTRL)) {
				if (s < sizeof(scan2ascii_ctrl))
					c = pgm_read_byte(scan2ascii_ctrl + s);
                        } else if ((state & ALT)) {
				if (s < sizeof(scan2ascii_alt))
					c = pgm_read_byte(scan2ascii_alt + s);
                        //end K3NG modification
			} else {
				if (s < sizeof(scan2ascii_noshift))
					c = pgm_read_byte(scan2ascii_noshift + s);
			}
			state &= ~(BREAK | MODIFIER);
			if (c) return c;
		}
	}
}

bool K3NG_PS2Keyboard::available() {
	if (ps2Keyboard_CharBuffer) return true;
	ps2Keyboard_CharBuffer = get_ascii_code();
	if (ps2Keyboard_CharBuffer) return true;
	return false;
}

int K3NG_PS2Keyboard::read() {
	char result;

	result = ps2Keyboard_CharBuffer;
	if (result) {
		ps2Keyboard_CharBuffer = 0;
	} else {
		result = get_ascii_code();
	}
	if (!result) return -1;
	return result;
}

K3NG_PS2Keyboard::K3NG_PS2Keyboard() {
  // nothing to do here, begin() does it all
}

void K3NG_PS2Keyboard::begin(uint8_t dataPin, uint8_t irq_pin) {
  uint8_t irq_num=0;

  ps2Keyboard_DataPin = dataPin;

  // initialize the pins
#ifdef INPUT_PULLUP
  pinMode(irq_pin, INPUT_PULLUP);
  pinMode(dataPin, INPUT_PULLUP);
#else
  pinMode(irq_pin, INPUT);
  digitalWrite(irq_pin, HIGH);
  pinMode(dataPin, INPUT);
  digitalWrite(dataPin, HIGH);
#endif
  
  switch(irq_pin) {
    #ifdef CORE_INT0_PIN
    case CORE_INT0_PIN:
      irq_num = 0;
      break;
    #endif
    #ifdef CORE_INT1_PIN
    case CORE_INT1_PIN:
      irq_num = 1;
      break;
    #endif
    #ifdef CORE_INT2_PIN
    case CORE_INT2_PIN:
      irq_num = 2;
      break;
    #endif
    #ifdef CORE_INT3_PIN
    case CORE_INT3_PIN:
      irq_num = 3;
      break;
    #endif
    #ifdef CORE_INT4_PIN
    case CORE_INT4_PIN:
      irq_num = 4;
      break;
    #endif
    #ifdef CORE_INT5_PIN
    case CORE_INT5_PIN:
      irq_num = 5;
      break;
    #endif
    #ifdef CORE_INT6_PIN
    case CORE_INT6_PIN:
      irq_num = 6;
      break;
    #endif
    #ifdef CORE_INT7_PIN
    case CORE_INT7_PIN:
      irq_num = 7;
      break;
    #endif
    default:
      irq_num = 0;
      break;
  }
  head = 0;
  tail = 0;
  attachInterrupt(irq_num, k3ng_ps2interrupt, FALLING);
}


