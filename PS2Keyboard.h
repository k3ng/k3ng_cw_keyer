/*
  PS2Keyboard.h - PS2Keyboard library
  Copyright (c) 2007 Free Software Foundation.  All right reserved.
  Written by Christian Weichel <info@32leaves.net>


  - Modified by Anthony Good / anthony dot good at gmail dot com
  - August 2011
  - Amateur Radio Operator K3NG
  - Modified for additional key codes to be returned and CTRL key combinations
  - http://radioartisan.wordpress.com

  ** Mostly rewritten Paul Stoffregen <paul@pjrc.com>, June 2010
  ** Modified for use with Arduino 13 by L. Abraham Smith, <n3bah@microcompdesign.com> * 
  ** Modified for easy interrup pin assignement on method begin(datapin,irq_pin). Cuningan <cuninganreset@gmail.com> **

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


#ifndef PS2Keyboard_h
#define PS2Keyboard_h

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

// Every call to read() returns a single byte for each
// keystroke.  These configure what byte will be returned
// for each "special" key.  To ignore a key, use zero.
#define PS2_TAB         9
#define PS2_ENTER       13
#define PS2_BACKSPACE   127
#define PS2_ESC         27
#define PS2_INSERT      128
#define PS2_DELETE      127
#define PS2_HOME        129
#define PS2_END         156
#define PS2_PAGEUP      25
#define PS2_PAGEDOWN    26
#define PS2_UPARROW     11
#define PS2_LEFTARROW   8
#define PS2_DOWNARROW   10
#define PS2_RIGHTARROW  21
#define PS2_F1          130
#define PS2_F2          131
#define PS2_F3          132
#define PS2_F4          133
#define PS2_F5          134
#define PS2_F6          135
#define PS2_F7          136
#define PS2_F8          137
#define PS2_F9          138
#define PS2_F10         139
#define PS2_F11         140
#define PS2_F12         141
#define PS2_SCROLL      142

#define PS2_F1_SHIFT          143
#define PS2_F2_SHIFT          144
#define PS2_F3_SHIFT          145
#define PS2_F4_SHIFT          146
#define PS2_F5_SHIFT          147
#define PS2_F6_SHIFT          148
#define PS2_F7_SHIFT          149
#define PS2_F8_SHIFT          150
#define PS2_F9_SHIFT          151
#define PS2_F10_SHIFT         152
#define PS2_F11_SHIFT         153
#define PS2_F12_SHIFT         154
#define PS2_TAB_SHIFT         9
#define PS2_ENTER_SHIFT       13
#define PS2_BACKSPACE_SHIFT   157

#define PS2_LEFT_ALT	158
//#define PS2_LEFT_CTRL	159
#define PS2_SCROLL_SHIFT 160

#define PS2_A_CTRL 162
#define PS2_B_CTRL 163
#define PS2_C_CTRL 164
#define PS2_D_CTRL 165
#define PS2_E_CTRL 166
#define PS2_F_CTRL 167
#define PS2_G_CTRL 168
#define PS2_H_CTRL 169
#define PS2_I_CTRL 170
#define PS2_J_CTRL 171
#define PS2_K_CTRL 172
#define PS2_L_CTRL 173
#define PS2_M_CTRL 174
#define PS2_N_CTRL 175
#define PS2_O_CTRL 176
#define PS2_P_CTRL 177
#define PS2_Q_CTRL 178
#define PS2_R_CTRL 179
#define PS2_S_CTRL 180
#define PS2_T_CTRL 181
#define PS2_U_CTRL 182
#define PS2_V_CTRL 183
#define PS2_W_CTRL 184
#define PS2_X_CTRL 185
#define PS2_Y_CTRL 186
#define PS2_Z_CTRL 187
#define PS2_F1_CTRL 188
#define PS2_F2_CTRL 189
#define PS2_F3_CTRL 190
#define PS2_F4_CTRL 191
#define PS2_F5_CTRL 192
#define PS2_F6_CTRL 193
#define PS2_F7_CTRL 194
#define PS2_F8_CTRL 195
#define PS2_F9_CTRL 196
#define PS2_F10_CTRL 197
#define PS2_F11_CTRL 198
#define PS2_F12_CTRL 199
#define PS2_F1_ALT 200
#define PS2_F2_ALT 201
#define PS2_F3_ALT 202
#define PS2_F4_ALT 203
#define PS2_F5_ALT 204
#define PS2_F6_ALT 205
#define PS2_F7_ALT 206
#define PS2_F8_ALT 207
#define PS2_F9_ALT 208
#define PS2_F10_ALT 209
#define PS2_F11_ALT 210
#define PS2_F12_ALT 211


/* Previous versions of this library returned a mix of ascii characters
 * and raw scan codes (if no ASCII character could be found).  There was
 * no way to determine if a byte was ascii or a raw scan code.  With
 * version 2.0, only ASCII is returned, plus the special bytes above.
 * These raw scan codes are never returned by read() anymore.
 *
 * PS2 keyboard "make" codes to check for certain keys.
 */
//#define PS2_KC_BREAK  0xf0
//#define PS2_KC_ENTER  0x0d
//#define PS2_KC_ESC    0x76
//#define PS2_KC_KPLUS  0x79
//#define PS2_KC_KMINUS 0x7b
//#define PS2_KC_KMULTI 0x7c
//#define PS2_KC_NUM    0x77
//#define PS2_KC_BKSP   0x66


/**
 * Purpose: Provides an easy access to PS2 keyboards
 * Author:  Christian Weichel
 */
class PS2Keyboard {
  public:
  	/**
  	 * This constructor does basically nothing. Please call the begin(int,int)
  	 * method before using any other method of this class.
  	 */
    PS2Keyboard();
    
    /**
     * Starts the keyboard "service" by registering the external interrupt.
     * setting the pin modes correctly and driving those needed to high.
     * The propably best place to call this method is in the setup routine.
     */
    static void begin(uint8_t dataPin, uint8_t irq_pin);
    
    /**
     * Returns true if there is a char to be read, false if not.
     */
    static bool available();
    
    /**
     * Returns the char last read from the keyboard.
     * If there is no char availble, -1 is returned.
     */
    static int read();
};

// interrupt pins for known boards
#ifndef CORE_INT0_PIN   // if not already defined by core (eg, Teensy)
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) // Arduino Mega
#define CORE_INT0_PIN  2
#define CORE_INT1_PIN  3
#define CORE_INT2_PIN  21
#define CORE_INT3_PIN  20
#define CORE_INT4_PIN  19
#define CORE_INT5_PIN  18
#elif defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644__) // Sanguino
#define CORE_INT0_PIN  10
#define CORE_INT1_PIN  11
#define CORE_INT2_PIN  2
#else  // Arduino Duemilanove, Diecimila, LilyPad, Mini, Fio, etc...
#define CORE_INT0_PIN  2
#define CORE_INT1_PIN  3
#endif
#endif

#endif
