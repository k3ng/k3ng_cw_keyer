/*

 K3NG Arduino CW Keyer

 Copyright 1340 BC, 2010, 2011, 2012, 2013, 2014, 2015 Anthony Good, K3NG
 All trademarks referred to in source code and documentation are copyright their respective owners.

    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    

If you offer a hardware kit using this software, show your appreciation by sending the author a complimentary kit or a bottle of bourbon ;-)

Full documentation can be found at http://blog.radioartisan.com/arduino-cw-keyer/ .  Please read it before requesting help.

 Command Line Interface ("CLI") (USB Port) (Note: turn on carriage return if using Arduino Serial Monitor program)

    CW Keyboard: type what you want the keyer to send (all commands are preceded with a backslash ( \ )
    \?     Help                                      (requires FEATURE_SERIAL_HELP)
    \#     Play memory #                             (requires FEATURES_MEMORIES; play memories 1 - 10 (0 = memory 10) )
    \a     Iambic A mode
    \b     Iambic B mode
    \c     Switch to CW (from Hell)
    \d     Ultimatic mode
    \e#### Set serial number to ####
    \f#### Set sidetone frequency to #### hertz
    \g     Bug mode
    \h     Switch to Hell sending                    (requires FEATURE_HELL)
    \i     Transmit enable/disable
    \j###  Dah to dit ratio (300 = 3.00)
    \k     Callsign receive practice
    \l##   Set weighting (50 = normal)
    \m###  Set Farnsworth speed
    \n     Toggle paddle reverse
    \o     Toggle sidetone on/off
    \p#    Program memory #  ( 1 - 9, 0 = memory 10)
    \q##   Switch to QRSS mode, dit length ## seconds
    \r     Switch to regular speed mode
    \s     Status
    \t     Tune mode
    \u     Manual PTT toggle
    \v     Toggle potentiometer active / inactive   (requires FEATURE_POTENTIOMETER)
    \w###  Set speed in WPM
    \x#    Switch to transmitter #
    \y#    Change wordspace to # elements (# = 1 to 9)
    \z     Autospace on/off
    \+     Create prosign
    \!##   Repeat play memory
    \|#### Set memory repeat (milliseconds)
    \*     Toggle paddle echo
    \`     Toggle straight key echo
    \^     Toggle wait for carriage return to send CW / send CW immediately
    \&     Toggle CMOS Super Keyer Timing on/off
    \%##   Set CMOS Super Keyer Timing %     
    \.     Toggle dit buffer on/off
    \-     Toggle dah buffer on/off
    \~     Reset unit
    \:     Toggle cw send echo
    \{     QLF mode on/off

 Buttons
    button 0: command mode / command mode exit
    button 0 + left paddle:  increase cw speed
    button 0 + right paddle: decrease cw speed
    button 1 - 12 hold + left paddle: repeat memory
    button 1 - 6 half second hold: switch to TX # 1 - 6

 Command Mode (press button0 to enter command mode and press again to exit)
    A  Switch to Iambic A mode
    B  Switch to Iambic B mode
    D  Switch to Ultimatic mode
    E  Announce speed
    F  Adjust sidetone frequency
    G  Switch to bug mode
    I  TX enable / disable
    J  Dah to dit ratio adjust
    N  Toggle paddle reverse
    O  Toggle sidetone on / off
    P#(#) Program a memory
    S  Alphabet code practice (FEATURE_ALPHABET_SEND_PRACTICE)
    T  Tune mode
    V  Toggle potentiometer active / inactive
    W  Change speed
    X  Exit command mode (you can also press the command button (button0) to exit)
    Y#### Change memory repeat delay to #### mS
    Z  Autospace On/Off
    #  Play a memory without transmitting

 Memory Macros
    \#     Jump to memory #
    \c     Play serial number with cut numbers
    \d###  Delay for ### seconds
    \e     Play serial number, then increment
    \f#### Change sidetone to #### hertz (must be four digits - use leading zero below 1000 hz)
    \h     Switch to Hell sending
    \i#    Insert memory number
    \l     Switch to CW (from Hell mode)
    \n     Decrement serial number, do not send
    \q##   Switch to QRSS mode, dit length ## seconds
    \r     Switch to regular speed mode
    \s     Insert space
    \t###  Transmit for ### seconds (must be three digits, use leading zeros if necessary)
    \u     Activate PTT
    \v     Deactivate PTT
    \w###  Set regular mode speed to ### WPM (must be three digits, use leading zeros if necessary)
    \x#    Switch to transmitter # (1, 2, or 3)
    \y#    Increase speed # WPM
    \z#    Decrease speed # WPM
    \+     Prosign the next two characters

 PS2 / USB Keyboard

   CTRL-A           Iambic A
   CTRL-B           Iambic B
   CTRL-D           Ultimatic
   CTRL-E           Set Serial Number
   CTRL-G           Bug
   CTRL-H           Toggle Hell Mode On/Off              (requires FEATURE_HELL)
   CTRL-I           TX enable / disable
   CTRL-O           Toggle Sidetone On/Off
   CTRL-M           Set Farnsworth Speed (0 = disabled)  (requires FEATURE_FARNSWORTH)
   CTRL-N           Paddle Reverse
   CTRL-T           Tune
   CTRL-U           Manual PTT Toggle
   CTRL-W           Set WPM
   CTRL-F1          Switch to TX #1
   CTRL-F2          Switch to TX #2
   CTRL-F3          Switch to TX #3
   CTRL-F4          Switch to TX #4
   CTRL-F5          Switch to TX #5
   CTRL-F6          Switch to TX #6
   END              Send serial number no increment
   ESC              Stop sending and clear buffer
   F1, F2, F3..     Play memory 1, 2, 3...
   DOWN ARROW       Decrease WPM
   HOME             Reset timing settings
   INSERT           Send serial number and increment
   LEFT ARROW       Decrease Dah to Dit Ratio
   PGDN             Decrease Sidetone Frequency
   PGUP             Increase Sidetone Frequency
   RIGHT ARROW      Increase Dah to Dit Ratio
   SCROLL LOCK      Prosign Next Two Characters
   SHIFT-BACKSPACE  Decrement serial number
   SHIFT-F1, F2...  Program Memory 1, 2...
   ALT-F1, F2...    Repeat Memory 1, 2...
   TAB              Pause Sending Immediately
   UP ARROW         Increase WPM
   Keypad /         Dit Paddle (USB Keyboard Only)
   Keypad *         Dah Paddle (USB Keyboard Only)
   Keypad ENTER     Tune / Straightkey (USB Keyboard Only)
   
 USB Mouse
 
   Left Button      Dit
   Right Button     Dah
   Middle Button    Tune / Straight Key

 PS2 Keyboard Notes (FEATURE_PS2_KEYBOARD)

    The original PS2Keyboard library can be found at http://www.pjrc.com/teensy/td_libs_PS2Keyboard.html .  Both PS2Keyboard.h and PS2Keyboard.cpp
    have been modified in order to return codes for keys not originally configured in the PS2Keyboard library.  These modified files are available
    at http://radioartisan.wordpress.com/k3ng-modified-ps2keyboard-library-files/

    Some keyboards may require a reset sequence upon startup.  This is activated with OPTION_PS2_KEYBOARD_RESET.

 USB Keyboard Notes (FEATURE_USB_KEYBOARD)
 
    To use a USB keyboard you need to download and install this library: https://github.com/felis/USB_Host_Shield_2.0 .  You may use an Arduino Mega
    ADK board (which has a built in USB host interface, get or Circuits@Home USB shield (http://www.circuitsathome.com/products-page/arduino-shields/usb-host-shield-2-0-for-arduino),
    or built your own MAX3421 based USB port.
    
    If you are using an Arduino Mega ADK, you must customize the USB Host Shield Library settings.h file!
 
 Useful Stuff
    Reset to defaults: squeeze both paddles at power up (good to use if you dorked up the speed and don't have the CLI)
    Press the right paddle to enter straight key mode at power up
    Press the left  paddle at power up to enter and stay forever in beacon mode

New fetures in this stable release:


    fixed bug with Winkey 00 admin command which affected Win-Test program
    no longer necessary to manually uncomment:
      #include <avr/sleep.h>
      #include <PS2Keyboard.h>
      #include <LiquidCrystal.h>
      #include <Wire.h>
      #include <LiquidCrystal_I2C.h>
      #include <Adafruit_MCP23017.h>
      #include <Adafruit_RGBLCDShield.h>
      #include <BasicTerm.h>
      PS2Keyboard keyboard;
      LiquidCrystal lcd(lcd_rs, lcd_enable, lcd_d4, lcd_d5, lcd_d6, lcd_d7);
      all USB keyboard and mouse stuff
    fixed Arduino IDE compilation errors
    fixed issue when FEATURE_COMMAND_LINE_INTERFACE and FEATURE_WINKEY_EMULATION are compiled without FEATURE_COMMAND_BUTTONS
    fixed compile bug involving hz_sidetone when OPTION_MORE_DISPLAY_MSGS is enabled
    fixed compile bug with OPTION_PS2_NON_ENGLISH_CHAR_LCD_DISPLAY_SUPPORT
    fixed bugs with FEATURE_CAPACITIVE_PADDLE_PINS
    fixed issue with Arduino IDE compilation and FEATURE_CAPACITIVE_PADDLE_PINS code
    fixed issue with N command mode command - fix from LA3ZA
    improved paddle echo and it should work better with autospace now
    OPTION_KEEP_PTT_KEYED_WHEN_CHARS_BUFFERED
    OPTION_DISPLAY_NON_ENGLISH_EXTENSIONS  // OZ1JHM provided code
    OPTION_EXCLUDE_PTT_HANG_TIME_FOR_MANUAL_SENDING
    // alter these to map to alternate hang time wordspace units
      #define WINKEY_HANG_TIME_1_0 1.0
      #define WINKEY_HANG_TIME_1_33 1.33
      #define WINKEY_HANG_TIME_1_66 1.66
      #define WINKEY_HANG_TIME_2_0 2.0
    improved paddle interruption of send_char()
    Updated OPTION_DISPLAY_NON_ENGLISH_EXTENSIONS from OZ1JHM provided code
    OPTION_WINKEY_SEND_BREAKIN_STATUS_BYTE
    Updates to OPTION_DISPLAY_NON_ENGLISH_EXTENSIONS
    Update to OPTION_NON_ENGLISH_EXTENSIONS
    DEBUG_DISPLAY_SCROLL_PRINT_CHAR
    OPTION_DISPLAY_NON_ENGLISH_EXTENSIONS addition code in display_scroll_print_char() 
    fixed bug with OPTION_REVERSE_BUTTON_ORDER
    #define WINKEY_1_REPORT_VERSION_NUMBER 10
    #define WINKEY_2_REPORT_VERSION_NUMBER 23

    S command - alphabet send practice; contributed by Ryan, KC2ZWM (documented on web page)

    #define correct_answer_led 0
    #define wrong_answer_led 0

    #define DEBUG_AUX_SERIAL_PORT
    #define DEBUG_WINKEY
    #define MAIN_SERIAL_PORT &Serial
    #define DEBUG_AUX_SERIAL_PORT &Serial1
    #define DEBUG_AUX_SERIAL_PORT_BAUD 115200
    #define OPTION_WINKEY_2_HOST_CLOSE_NO_SERIAL_PORT_RESET - fixes an issue with Win-Test and Winkey 2 emulation
    /: - CW send echo inhibit toggle (documented on web page)

    bug with get_cw_input_from_user(unsigned int exit_time_milliseconds) fixed (thanks Rob, W7FJ)

    OPTION_WINKEY_FREQUENT_STATUS_REPORT / RUMlog and RUMped compatibility- thanks Jim W2XO for code (documented on web page)

    wpm_limit_low and wpm_limit_high settings in keyer_settings.h

    potentiometer_always_on setting in keyer_settings.h

    Command Mode E command: announce speed  (documented on web page)
      
    Fixed compilation error involving OPTION_WINKEY_2_HOST_CLOSE_NO_SERIAL_PORT_RESET and FEATURE_WINKEY_EMULATION

    OPTION_PS2_KEYBOARD_RESET, thanks Bill, W9BEL for the code (documented on web page 2015-01-03)

    FEATURE_CW_DECODER No space on LCD bug fixed by Rob, W7FJ

    Bug fix in speed_change() - lcd_center_print_timed() - Thanks Vincenzo, IZ0RUS

    FEATURE_PTT_INTERLOCK (documented on web page 2014-05-06)

    Fixed bug in FEATURE_USB_KEYBOARD, reported by Bill, W9BEL

    Fixed bug in FEATURE_PTT_INTERLOCK

    #define unknown_cw_character '*'  (documented on web page 2014-05-06)

    OPTION_UNKNOWN_CHARACTER_ERROR_TONE  (documented on web page 2014-05-06)
    OPTION_DO_NOT_SAY_HI (FEATURE_SAY_HI is gone)
    FEATURE_DISPLAY no longer needs to be configured, it is automatically defined when an LCD feature is enabled
    added keyer_dependencies.h file (documentation updated)

    Fixed administrative bug - FEATURE_COMMAND_BUTTONS disappeared in last update - oooooops!  (Thanks Peter, SM0NTR)

    K3NG_PS2Keyboard.h and K3NG_PS2Keyboard.cpp replace PS2Keyboard.h and PS2Keyboard.cpp  (documented on web page 2014-05-06)
    K3NG_PS2Keyboard.h: (documented on web page 2014-05-06)
      #define OPTION_PS2_KEYBOARD_US
      #define OPTION_PS2_KEYBOARD_GERMAN - still needs work
      #define OPTION_PS2_KEYBOARD_FRENCH - still needs work

    fixed mispelling of potentiometer_always_on

    FEATURE_QLF (documented on web page 2014-05-06)
    #define qlf_dit_max 125
    #define qlf_dit_min 75
    #define qlf_dah_max 200
    #define qlf_dah_min 100
    #define qlf_on_by_default 0

    keyer_hardware.h and HARDWARE_NANOKEYER_REV_B (documented on web page)

    OPTION_SAVE_MEMORY_NANOKEYER

    OPTION_WINKEY_IGNORE_FIRST_STATUS_REQUEST

    changed reset method to 'asm volatile ("jmp 0");'

    FEATURE_SERIAL no longer needs to be uncommented for FEATURE_COMMAND_LINE_INTERFACE or FEATURE_WINKEY_EMULATION (documented on web page)
    keyer_hardware.h now switches features, pins, and settings files
    Fixed compilation issue with OPTION_WINKEY_2_SUPPORT consuming memory without FEATURE_WINKEY_EMULATION enabled
    OPTION_WINKEY_2_SUPPORT is now enabled by default in features and options file

    HARDWARE_OPEN_INTERFACE  http://remoteqth.com/open-interface.php (documented)
    @ symbol now works in LCD display

    replaced prog_char with const char to fix issue with Arduino 1.6 compilation

    Fixed bug introduced in 2.2.2015030701 where memory buttons don't work unless FEATURE_WINKEY_EMULATION is compiled in (Thanks Bill, W9BEL)
    Fixed bug with OPTION_SAVE_MEMORY_NANOKEYER where keyer didn't say hi
    Fixed bug with OPTION_WINKEY_SEND_BREAKIN_STATUS_BYTE when Winkey is activated and user goes into command mode with button

    Working on HARDWARE_ARDUINO_DUE; Arduino Due setup requires E24C1024 I2C EEPROM hardware

    2.2.2015040402 More work on HARDWARE_ARDUINO_DUE (documented)

    2.2.2015040501 Fixed bug with O command not working when any display feature was compiled in
    
    2.2.2015040801 FEATURE_EEPROM_E24C1024; working on FEATURE_CW_COMPUTER_KEYBOARD (documented)
    
    2.2.2015040901 updated serial help text with recently added commands, consolidated the three paddle echo features into one subroutine
    
    2.2.2015040902 Minor typos fixed

    2.2.2015042002 Eliminated keyer.h declaration (upgrade Stino if you're still using keyer.h)

    2.2.2015042301 
      '#define PRIMARY_SERIAL_PORT &Serial' is now '#define PRIMARY_SERIAL_PORT &Serial' (documented on website 2015-04-25)
      OPTION_SERIAL_PORT_DEFAULT_WINKEY_EMULATION is now OPTION_PRIMARY_SERIAL_PORT_DEFAULT_WINKEY_EMULATION (documented on website 2015-04-25)
      '#define default_serial_baud_rate 115200' is now '#define PRIMARY_SERIAL_PORT_BAUD 115200' (documented on website 2015-04-25)
      #define SECONDARY_SERIAL_PORT_BAUD 115200 (documented on website 2015-04-25)
      FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT  (documented on website 2015-04-25)
      FEATURE_LCD1602_N07DH (Thanks Xigco for code!)  (documented on website 2015-04-25)
      
    2.2.2015042302  
      OPTION_CW_KEYBOARD_ITALIAN (Thanks Giorgio IZ2XBZ)  (documented on website 2015-04-25)
      FEATURE_CW_COMPUTER_KEYBOARD repeating backspace, fixed caps lock sounds

    2.2.2015042303
      Test of GitHub - no changes  

    2.2.2015042501
      FEATURE_CW_COMPUTER_KEYBOARD update from Giorgio IZ2XBZ 
      Website documentation up to date!  Yeahhhhhh!  :-)

    2.2.2015042901
      HARDWARE_NANOKEYER_REV_D

    2.2.2015043001
      Fixed compilation bug with FEATURE_COMMAND_LINE_INTERFACE when FEATURE_WINKEY_EMULATION not enabled

    2.2.2015051201
      OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR (website updated 2015-05-12)

    2.2.2015051301  
      Improvements to FEATURE_CW_DECODER for better decoding and Goetzel settings for Arduino Due

    2.2.2015061101
      lcd_columns and lcd_rows in keyer_settings*.h files renamed to LCD_COLUMNS and LCD_ROWS
      OPTION_INVERT_PADDLE_PIN_LOGIC - paddle closed = HIGH, paddle open = LOW
      
    2.2.2015082801  
      Added E24C1024.h and E24C1024.cpp to git
      Fixed compilation issue with Due involving E24C1024 library

    2.2.2015082802
      FEATURE_STRAIGHT_KEY  {documented on web page 2015-09-05}

    2.2.2015090501
      Memories can now be programmed in commmand mode (FEATURE_COMMAND_BUTTONS) by pressing the memory button
      FEATURE_CW_DECODER now has digital input pin (cw_decoder_pin) and if OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR is enable, cw_decoder_audio_input_pin will work in parallel

    2.2.2015090801
      Fixed issue with FEATURE_CW_DECODER + OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR and wrong GOERTZ_SAMPLING_FREQ and GOERTZ_SAMPLES used in goertzel.h causing keyer lockups after startup
  
    2.2.2015091301
      FEATURE_DYNAMIC_DAH_TO_DIT_RATIO (code contributed by Giorgio, IZ2XBZ)
      #ifdef FEATURE_DYNAMIC_DAH_TO_DIT_RATIO  (keyer_settings.h)
        #define DYNAMIC_DAH_TO_DIT_RATIO_LOWER_LIMIT_WPM 30
        #define DYNAMIC_DAH_TO_DIT_RATIO_LOWER_LIMIT_RATIO 300 // 300 = 3:1 ratio
        #define DYNAMIC_DAH_TO_DIT_RATIO_UPPER_LIMIT_WPM 70
        #define DYNAMIC_DAH_TO_DIT_RATIO_UPPER_LIMIT_RATIO 240 // 240 = 2.4:1 ratio
      #endif //FEATURE_DYNAMIC_DAH_TO_DIT_RATIO

    2.2.2015091302
      FEATURE_COMPETITION_COMPRESSION_DETECTION - Experimental 
      Fixed compiler error when only FEATURE_COMMAND_BUTTONS was enabled

    2.2.2015091801
      OPTION_DIT_DAH_BUFFERS_OFF_BY_DEFAULT_FOR_FEATURE_DIT_DAH_BUFFER_CONTROL
      OPTION_ADVANCED_SPEED_DISPLAY (code contributed by Giorgio, IZ2XBZ)

    2.2.2015091802
      Improved handling of spaces in LCD display 

    2.2.2015092101
      Fixed bugs in OPTION_CW_KEYBOARD_ITALIAN and OPTION_UNKNOWN_CHARACTER_ERROR_TONE (courtesy of Giorgio, IZ2XBZ) 

    2.2.2015092301   
      FEATURE_COMPETITION_COMPRESSION_DETECTION improvements

    2.2.2015092401
      #define compression_detection_pin 0
      default potentiometer_change_threshold changed to 0.9

    2.2.2015101201
      Additional DEBUG_PS2_KEYBOARD code 

    2.2.2015101301
      OPTION_STRAIGHT_KEY_ECHO
      
    2.2.2015101302 
      OPTION_STRAIGHT_KEY_ECHO is now FEATURE_STRAIGHT_KEY_ECHO
      CLI command: \`     Toggle straight key echo
      #define cli_paddle_echo_on_at_boot 1
      #define cli_straight_key_echo_on_at_boot 1
      FEATURE_STRAIGHT_KEY now works with FEATURE_CW_COMPUTER_KEYBOARD
      Straight Key can now program memories
    
    2.2.2015101401
      Fixed compile bug with FEATURE_DISPLAY and cli_straight_key_echo

    2.2.2015101402
      K3NG_PS2Keyboard Library: Fixed issues with CTRL and ALT key combinations with German and French keyboards 

    2.2.2015101801
      OPTION_WINKEY_IGNORE_LOWERCASE    
      
*/

#define CODE_VERSION "2.2.2015101801"
#define eeprom_magic_number 19

#include <stdio.h>
#include "keyer_hardware.h"

#ifndef HARDWARE_ARDUINO_DUE
  #include <avr/pgmspace.h>
  #include <avr/wdt.h>
  #include <EEPROM.h>
#else
  #include <SPI.h>
  #include <Wire.h>
  #define tone toneDUE
  #define noTone noToneDUE
#endif //HARDWARE_ARDUINO_DUE

#ifdef HARDWARE_NANOKEYER_REV_B
  #include "keyer_features_and_options_nanokeyer_rev_b.h"
#endif

#ifdef HARDWARE_NANOKEYER_REV_D
  #include "keyer_features_and_options_nanokeyer_rev_d.h"
#endif

#ifdef HARDWARE_OPEN_INTERFACE
  #include "keyer_features_and_options_open_interface.h"
#endif

#ifndef HARDWARE_CUSTOM
  #include "keyer_features_and_options.h"
#endif

#ifdef FEATURE_EEPROM_E24C1024
  #include "E24C1024.h"
  #define EEPROM EEPROM1024
#endif 

#include "keyer_dependencies.h"
#include "keyer_debug.h"

#ifdef HARDWARE_NANOKEYER_REV_B
  #include "keyer_pin_settings_nanokeyer_rev_b.h"
  #include "keyer_settings_nanokeyer_rev_b.h"
#endif

#ifdef HARDWARE_NANOKEYER_REV_D
  #include "keyer_pin_settings_nanokeyer_rev_d.h"
  #include "keyer_settings_nanokeyer_rev_d.h"
#endif

#ifdef HARDWARE_OPEN_INTERFACE
  #include "keyer_pin_settings_open_interface.h"
  #include "keyer_settings_open_interface.h"
#endif

#ifndef HARDWARE_CUSTOM
  #include "keyer_pin_settings.h"
  #include "keyer_settings.h"
#endif

#if defined(FEATURE_SLEEP)
  #include <avr/sleep.h>
#endif 

#if defined(FEATURE_PS2_KEYBOARD)
  #ifdef OPTION_USE_ORIGINAL_VERSION_2_1_PS2KEYBOARD_LIB
    #include "PS2Keyboard.h"
  #else //OPTION_USE_ORIGINAL_VERSION_2_1_PS2KEYBOARD_LIB
    #include "K3NG_PS2Keyboard.h"
  #endif
#endif

#if defined(FEATURE_LCD_4BIT) || defined(FEATURE_LCD1602_N07DH)
  #include <LiquidCrystal.h>
#endif

#if defined(FEATURE_LCD_ADAFRUIT_I2C) || defined(FEATURE_LCD_YDv1)
  #include <Wire.h>
#endif

#if defined(FEATURE_LCD_YDv1)
  #include <LiquidCrystal_I2C.h>
#endif

#if defined(FEATURE_LCD_ADAFRUIT_I2C)
  #include <Adafruit_MCP23017.h>
  #include <Adafruit_RGBLCDShield.h>
#endif

#if defined(FEATURE_CALLSIGN_RECEIVE_PRACTICE)
  #include "BasicTerm.h"
#endif

#if defined(OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR)
  #include "goertzel.h"
#endif

#if defined(FEATURE_USB_KEYBOARD) || defined(FEATURE_USB_MOUSE)  // note_usb_uncomment_lines
  //#include <hidboot.h>  // Arduino 1.6.x (and maybe 1.5.x) has issues with these three lines, so they are commented out
  //#include <usbhub.h>   // Uncomment the three lines if you are using FEATURE_USB_KEYBOARD or FEATURE_USB_MOUSE
  //#include <Usb.h>      // the USB Library can be downloaded at https://github.com/felis/USB_Host_Shield_2.0
#endif



// Variables and stuff
struct config_t {  // 23 bytes
  unsigned int wpm;
  byte paddle_mode;
  byte keyer_mode;
  byte sidetone_mode;
  unsigned int hz_sidetone;
  unsigned int dah_to_dit_ratio;
  byte pot_activated;
  byte length_wordspace;
  byte autospace_active;
  unsigned int wpm_farnsworth;
  byte current_ptt_line;
  byte current_tx;
  byte weighting;
  unsigned int memory_repeat_time;
  byte dit_buffer_off;
  byte dah_buffer_off;
  byte cmos_super_keyer_iambic_b_timing_percent;
  byte cmos_super_keyer_iambic_b_timing_on;
} configuration;


byte command_mode_disable_tx = 0;
byte current_tx_key_line = tx_key_line_1;
#ifdef OPTION_SAVE_MEMORY_NANOKEYER
  unsigned int ptt_tail_time[] = {initial_ptt_tail_time_tx1,initial_ptt_tail_time_tx2,initial_ptt_tail_time_tx3};
  unsigned int ptt_lead_time[] = {initial_ptt_lead_time_tx1,initial_ptt_lead_time_tx2,initial_ptt_lead_time_tx3};
#else //OPTION_SAVE_MEMORY_NANOKEYER
  unsigned int ptt_tail_time[] = {initial_ptt_tail_time_tx1,initial_ptt_tail_time_tx2,initial_ptt_tail_time_tx3,initial_ptt_tail_time_tx4,initial_ptt_tail_time_tx5,initial_ptt_tail_time_tx6};
  unsigned int ptt_lead_time[] = {initial_ptt_lead_time_tx1,initial_ptt_lead_time_tx2,initial_ptt_lead_time_tx3,initial_ptt_lead_time_tx4,initial_ptt_lead_time_tx5,initial_ptt_lead_time_tx6};
#endif //OPTION_SAVE_MEMORY_NANOKEYER
byte manual_ptt_invoke = 0;
byte qrss_dit_length = initial_qrss_dit_length;
byte keyer_machine_mode = KEYER_NORMAL;   // KEYER_NORMAL, BEACON, KEYER_COMMAND_MODE
byte char_send_mode = 0; // CW, HELL
byte key_tx = 0;         // 0 = tx_key_line control suppressed
byte dit_buffer = 0;     // used for buffering paddle hits in iambic operation
byte dah_buffer = 0;     // used for buffering paddle hits in iambic operation
byte button0_buffer = 0;
byte being_sent = 0;     // SENDING_NOTHING, SENDING_DIT, SENDING_DAH
byte key_state = 0;      // 0 = key up, 1 = key down
byte config_dirty = 0;
unsigned long ptt_time = 0; 
byte ptt_line_activated = 0;
byte speed_mode = SPEED_NORMAL;
#ifndef OPTION_SAVE_MEMORY_NANOKEYER
  unsigned int serial_number = 1;
#endif //OPTION_SAVE_MEMORY_NANOKEYER
byte pause_sending_buffer = 0;
byte length_letterspace = default_length_letterspace;
byte keying_compensation = default_keying_compensation;
byte first_extension_time = default_first_extension_time;
byte ultimatic_mode = ULTIMATIC_NORMAL;
float ptt_hang_time_wordspace_units = default_ptt_hang_time_wordspace_units;
byte last_sending_type = MANUAL_SENDING;
byte zero = 0;
byte iambic_flag = 0;
unsigned long last_config_write = 0;

#ifdef FEATURE_SLEEP
  unsigned long last_activity_time = 0;
#endif


#ifdef FEATURE_DISPLAY
  enum lcd_statuses {LCD_CLEAR, LCD_REVERT, LCD_TIMED_MESSAGE, LCD_SCROLL_MSG};
  #define default_display_msg_delay 1000
#endif //FEATURE_DISPLAY

#ifdef FEATURE_LCD_ADAFRUIT_I2C
  #define RED 0x1
  #define YELLOW 0x3
  #define GREEN 0x2
  #define TEAL 0x6
  #define BLUE 0x4
  #define VIOLET 0x5
  #define WHITE 0x7
  byte lcdcolor = GREEN;  // default color for RGB LCD display
#endif //FEATURE_LCD_ADAFRUIT_I2C

#if defined(OPTION_WINKEY_2_SUPPORT) && defined(FEATURE_WINKEY_EMULATION)
  byte wk2_mode = 1;
  byte wk2_both_tx_activated = 0;
  byte wk2_paddle_only_sidetone = 0;
#endif //defined(OPTION_WINKEY_2_SUPPORT) && defined(FEATURE_WINKEY_EMULATION)

#ifdef FEATURE_DISPLAY
  byte lcd_status = LCD_CLEAR;
  unsigned long lcd_timed_message_clear_time = 0;
  byte lcd_previous_status = LCD_CLEAR;
  byte lcd_scroll_buffer_dirty = 0;
  String lcd_scroll_buffer[LCD_ROWS];
  byte lcd_scroll_flag = 0;
  byte lcd_paddle_echo = 1;
  byte lcd_send_echo = 1;
#endif //FEATURE_DISPLAY

#ifdef DEBUG_VARIABLE_DUMP
  long dit_start_time;
  long dit_end_time;
  long dah_start_time;
  long dah_end_time;
#endif //DEBUG_VARIABLE_DUMP

#ifdef FEATURE_COMMAND_BUTTONS
  int button_array_high_limit[analog_buttons_number_of_buttons];
  int button_array_low_limit[analog_buttons_number_of_buttons];
  long button_last_add_to_send_buffer_time = 0;
#endif //FEATURE_COMMAND_BUTTONS

byte pot_wpm_low_value;

#ifdef FEATURE_POTENTIOMETER
  byte pot_wpm_high_value;
  byte last_pot_wpm_read;
  int pot_full_scale_reading = default_pot_full_scale_reading;
#endif //FEATURE_POTENTIOMETER

#if defined(FEATURE_SERIAL)
  byte incoming_serial_byte;
  long primary_serial_port_baud_rate;
  byte cw_send_echo_inhibit = 0;
  #ifdef FEATURE_COMMAND_LINE_INTERFACE
    byte serial_backslash_command;
    byte cli_paddle_echo = cli_paddle_echo_on_at_boot;
    byte cli_prosign_flag = 0;
    byte cli_wait_for_cr_to_send_cw = 0;
    #if defined(FEATURE_STRAIGHT_KEY_ECHO)
      byte cli_straight_key_echo = cli_straight_key_echo_on_at_boot;
    #endif   
  #endif //FEATURE_COMMAND_LINE_INTERFACE  
#endif //FEATURE_SERIAL

byte send_buffer_array[send_buffer_size];
byte send_buffer_bytes = 0;
byte send_buffer_status = SERIAL_SEND_BUFFER_NORMAL;

#ifdef FEATURE_MEMORIES
  byte play_memory_prempt = 0;
  long last_memory_button_buffer_insert = 0;
  byte repeat_memory = 255;
  unsigned long last_memory_repeat_time = 0;
#endif //FEATURE_MEMORIES

#if defined(FEATURE_SERIAL)
  byte primary_serial_port_mode = SERIAL_CLI;
#endif //FEATURE_SERIAL

#ifdef FEATURE_WINKEY_EMULATION
  byte winkey_serial_echo = 1;
  byte winkey_host_open = 0;
  unsigned int winkey_last_unbuffered_speed_wpm = 0;
  byte winkey_buffer_counter = 0;
  byte winkey_buffer_pointer = 0;
  byte winkey_dit_invoke = 0;
  byte winkey_dah_invoke = 0;
  long winkey_paddle_echo_buffer = 0;
  byte winkey_paddle_echo_activated = 0;
  unsigned long winkey_paddle_echo_buffer_decode_time = 0;
  byte winkey_sending = 0;
  byte winkey_interrupted = 0;
  byte winkey_xoff = 0;
  #ifdef OPTION_WINKEY_SEND_BREAKIN_STATUS_BYTE
    byte winkey_breakin_status_byte_inhibit = 0;
  #endif //OPTION_WINKEY_SEND_BREAKIN_STATUS_BYTE
#endif //FEATURE_WINKEY_EMULATION

#ifdef FEATURE_PS2_KEYBOARD
  byte ps2_keyboard_mode = PS2_KEYBOARD_NORMAL;
  byte ps2_keyboard_command_buffer[25];
  byte ps2_keyboard_command_buffer_pointer = 0;
#endif //FEATURE_PS2_KEYBOARD


#ifdef FEATURE_HELL
  PROGMEM const char hell_font1[] = {B00111111, B11100000, B00011001, B11000000, B01100011, B00000001, B10011100, B00111111, B11100000,    // A
                                     B00110000, B00110000, B11111111, B11000011, B00110011, B00001100, B11001100, B00011100, B11100000,    // B
                                     B00111111, B11110000, B11000000, B11000011, B00000011, B00001100, B00001100, B00110000, B00110000,    // C
                                     B00110000, B00110000, B11111111, B11000011, B00000011, B00001100, B00001100, B00011111, B11100000,    // D
                                     B00111111, B11110000, B11001100, B11000011, B00110011, B00001100, B00001100, B00110000, B00110000,
                                     B00111111, B11110000, B00001100, B11000000, B00110011, B00000000, B00001100, B00000000, B00110000,
                                     B00111111, B11110000, B11000000, B11000011, B00000011, B00001100, B11001100, B00111111, B00110000,
                                     B00111111, B11110000, B00001100, B00000000, B00110000, B00000000, B11000000, B00111111, B11110000,
                                     B00000000, B00000000, B00000000, B00000011, B11111111, B00000000, B00000000, B00000000, B00000000,
                                     B00111100, B00000000, B11000000, B00000011, B00000000, B00001100, B00000000, B00111111, B11110000,
                                     B00111111, B11110000, B00001100, B00000000, B01110000, B00000011, B00110000, B00111000, B11100000,
                                     B00111111, B11110000, B11000000, B00000011, B00000000, B00001100, B00000000, B00110000, B00000000,
                                     B00111111, B11110000, B00000001, B10000000, B00001100, B00000000, B00011000, B00111111, B11110000,
                                     B00111111, B11110000, B00000011, B10000000, B00111000, B00000011, B10000000, B00111111, B11110000,
                                     B00111111, B11110000, B11000000, B11000011, B00000011, B00001100, B00001100, B00111111, B11110000,
                                     B00110000, B00110000, B11111111, B11000011, B00110011, B00000000, B11001100, B00000011, B11110000,
                                     B00111111, B11110000, B11000000, B11000011, B11000011, B00001111, B11111100, B11110000, B00000000,
                                     B00111111, B11110000, B00001100, B11000000, B00110011, B00000011, B11001100, B00111001, B11100000,
                                     B00110001, B11100000, B11001100, B11000011, B00110011, B00001100, B11001100, B00011110, B00110000,
                                     B00000000, B00110000, B00000000, B11000011, B11111111, B00000000, B00001100, B00000000, B00110000,
                                     B00111111, B11110000, B11000000, B00000011, B00000000, B00001100, B00000000, B00111111, B11110000,
                                     B00111111, B11110000, B01110000, B00000000, B01110000, B00000000, B01110000, B00000000, B01110000,
                                     B00011111, B11110000, B11000000, B00000001, B11110000, B00001100, B00000000, B00011111, B11110000,
                                     B00111000, B01110000, B00110011, B00000000, B01111000, B00000011, B00110000, B00111000, B01110000,
                                     B00000000, B01110000, B00000111, B00000011, B11110000, B00000000, B01110000, B00000000, B01110000,
                                     B00111000, B00110000, B11111000, B11000011, B00110011, B00001100, B01111100, B00110000, B01110000};   // Z

  PROGMEM const char hell_font2[] = {B00011111, B11100000, B11000000, B11000011, B00000011, B00001100, B00001100, B00011111, B11100000,   // 0
                                     B00000000, B00000000, B00000011, B00000000, B00000110, B00001111, B11111100, B00000000, B00000000,
                                     B00111000, B01100000, B11110000, B11000011, B00110011, B00001100, B01111000, B00110000, B00000000,
                                     B11000000, B00000011, B00000000, B11000110, B00110011, B00001100, B11111100, B00011110, B00000000,
                                     B00000111, B11111000, B00011000, B00000000, B01100000, B00001111, B11111100, B00000110, B00000000,
                                     B00110000, B00000000, B11000000, B00000011, B00011111, B10000110, B01100110, B00001111, B00011000,
                                     B00011111, B11110000, B11001100, B01100011, B00011000, B11001100, B01100000, B00011111, B00000000,
                                     B01110000, B00110000, B01110000, B11000000, B01110011, B00000000, B01111100, B00000000, B01110000,
                                     B00111100, B11110001, B10011110, B01100110, B00110001, B10011001, B11100110, B00111100, B11110000,
                                     B00000011, B11100011, B00011000, B11000110, B01100011, B00001100, B00001100, B00011111, B11100000};  // 9

 PROGMEM const char hell_font3[]  = {B00000011, B00000000, B00001100, B00000001, B11111110, B00000000, B11000000, B00000011, B00000000,
                                     B00000011, B00000000, B00001100, B00000000, B00110000, B00000000, B11000000, B00000011, B00000000,
                                     B00000000, B00110000, B00000000, B11001110, B01110011, B00000000, B01111100, B00000000, B00000000,
                                     B01110000, B00000000, B01110000, B00000000, B01110000, B00000000, B01110000, B00000000, B01110000,
                                     B00111000, B00000000, B11100000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
                                     B00001100, B00000001, B11110000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
                                     B00000000, B00111000, B00000011, B10000000, B00000000, B00000000, B00000000, B00000000, B00000000,
                                     B00001100, B11000000, B00110011, B00000000, B11001100, B00000011, B00110000, B00001100, B11000000,
                                     B01110000, B00111000, B01110011, B10000000, B01111000, B00000000, B00000000, B00000000, B00000000,
                                     B00000000, B00000000, B00000000, B00000000, B01111000, B00000111, B00111000, B01110000, B00111000,
                                     B00000000, B00000000, B01110011, B10000001, B11001110, B00000000, B00000000, B00000000, B00000000,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0};


#endif //FEATURE_HELL

#define SIDETONE_HZ_LOW_LIMIT 299
#define SIDETONE_HZ_HIGH_LIMIT 2001

#ifdef FEATURE_DEAD_OP_WATCHDOG
  byte dead_op_watchdog_active = 1;
  byte dit_counter = 0;
  byte dah_counter = 0;
#endif //FEATURE_DEAD_OP_WATCHDOG


#ifdef FEATURE_ROTARY_ENCODER            // Rotary Encoder State Tables
  #ifdef OPTION_ENCODER_HALF_STEP_MODE      // Use the half-step state table (emits a code at 00 and 11)
  const unsigned char ttable[6][4] = {
    {0x3 , 0x2, 0x1,  0x0}, {0x23, 0x0, 0x1, 0x0},
    {0x13, 0x2, 0x0,  0x0}, {0x3 , 0x5, 0x4, 0x0},
    {0x3 , 0x3, 0x4, 0x10}, {0x3 , 0x5, 0x3, 0x20}
  };
  #else                                      // Use the full-step state table (emits a code at 00 only)
  const unsigned char ttable[7][4] = {
    {0x0, 0x2, 0x4,  0x0}, {0x3, 0x0, 0x1, 0x10},
    {0x3, 0x2, 0x0,  0x0}, {0x3, 0x2, 0x1,  0x0},
    {0x6, 0x0, 0x4,  0x0}, {0x6, 0x5, 0x0, 0x10},
    {0x6, 0x5, 0x4,  0x0},
  };
  #endif //OPTION_ENCODER_HALF_STEP_MODE 
  unsigned char state = 0;
  #define DIR_CCW 0x10                      // CW Encoder Code (do not change)
  #define DIR_CW 0x20                       // CCW Encoder Code (do not change)
#endif //FEATURE_ENCODER_SUPPORT

#ifdef FEATURE_USB_KEYBOARD
  unsigned long usb_keyboard_special_mode_start_time = 0;
  String keyboard_string;
#endif //FEATURE_USB_KEYBOARD

#if defined(FEATURE_USB_MOUSE) || defined(FEATURE_USB_KEYBOARD)
  byte usb_dit = 0;
  byte usb_dah = 0;
#endif 

#if defined(FEATURE_PS2_KEYBOARD)
  #ifdef OPTION_USE_ORIGINAL_VERSION_2_1_PS2KEYBOARD_LIB
    PS2Keyboard keyboard;
  #else //OPTION_USE_ORIGINAL_VERSION_2_1_PS2KEYBOARD_LIB
  K3NG_PS2Keyboard keyboard;
  #endif //OPTION_USE_ORIGINAL_VERSION_2_1_PS2KEYBOARD_LIB
#endif

#if defined(FEATURE_LCD_4BIT) || defined(FEATURE_LCD1602_N07DH)
  LiquidCrystal lcd(lcd_rs, lcd_enable, lcd_d4, lcd_d5, lcd_d6, lcd_d7);
#endif

#if defined(FEATURE_LCD_ADAFRUIT_I2C)
  Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();
#endif

#if defined(FEATURE_LCD_YDv1)
  //LiquidCrystal_I2C lcd(0x38);
  LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // for FEATURE_LCD_YDv1; set the LCD I2C address needed for LCM1602 IC V1
#endif

#if defined(FEATURE_USB_KEYBOARD) || defined(FEATURE_USB_MOUSE)
  USB Usb;
  uint32_t next_time;
#endif

#if defined(FEATURE_USB_KEYBOARD)
  class KbdRptParser : public KeyboardReportParser
    {
      protected:
        virtual void OnKeyDown (uint8_t mod, uint8_t key);
        virtual void OnKeyUp (uint8_t mod, uint8_t key);
    };
  HIDBoot<HID_PROTOCOL_KEYBOARD> HidKeyboard(&Usb);
  KbdRptParser KeyboardPrs;
#endif

#if defined(FEATURE_USB_MOUSE)
  class MouseRptParser : public MouseReportParser 
    {
      protected:
        virtual void OnMouseMove(MOUSEINFO *mi);
        virtual void OnLeftButtonUp(MOUSEINFO *mi);
        virtual void OnLeftButtonDown(MOUSEINFO *mi);
        virtual void OnRightButtonUp(MOUSEINFO *mi);
        virtual void OnRightButtonDown(MOUSEINFO *mi);
        virtual void OnMiddleButtonUp(MOUSEINFO *mi);
        virtual void OnMiddleButtonDown(MOUSEINFO *mi);
     };
  HIDBoot<HID_PROTOCOL_MOUSE> HidMouse(&Usb);
  MouseRptParser MousePrs;
#endif //FEATURE_USB_MOUSE

#if defined(FEATURE_CALLSIGN_RECEIVE_PRACTICE)
  BasicTerm term(&Serial);
#endif

HardwareSerial * primary_serial_port;

#if defined(FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT)
  HardwareSerial * secondary_serial_port;
#endif

HardwareSerial * debug_serial_port;

#ifdef FEATURE_PTT_INTERLOCK
  byte ptt_interlock_active = 0;
#endif //FEATURE_PTT_INTERLOCK

#ifdef FEATURE_QLF
  byte qlf_active = qlf_on_by_default;
#endif //FEATURE_QLF

#if defined(FEATURE_PADDLE_ECHO)
  byte paddle_echo = 0;
  long paddle_echo_buffer = 0;
  unsigned long paddle_echo_buffer_decode_time = 0;
#endif //FEATURE_PADDLE_ECHO 

#if defined(FEATURE_CW_DECODER) && defined(OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR)
  Goertzdetector cwtonedetector;
#endif

#if defined(FEATURE_COMPETITION_COMPRESSION_DETECTION)
  unsigned long compression_detection_key_down_time = 0;
  unsigned long compression_detection_key_up_time = 0;
  int time_array[COMPETITION_COMPRESSION_DETECTION_ARRAY_SIZE];
  byte time_array_index = 0;
#endif //FEATURE_COMPETITION_COMPRESSION_DETECTION

#if defined(FEATURE_CW_COMPUTER_KEYBOARD) 
  byte cw_keyboard_capslock_on = 0;
#endif //defined(FEATURE_CW_COMPUTER_KEYBOARD)


/*---------------------------------------------------------------------------------------------------------


                                    this code is a work of art.  enjoy.


---------------------------------------------------------------------------------------------------------*/

void setup()
{

  initialize_pins();
  initialize_keyer_state();
  initialize_potentiometer();
  initialize_rotary_encoder();
  initialize_default_modes();
  initialize_watchdog();
  check_eeprom_for_initialization();
  check_for_beacon_mode();
  check_for_debug_modes();
  initialize_analog_button_array();
  initialize_serial_ports();
  initialize_ps2_keyboard();
  initialize_usb();
  initialize_cw_keyboard();
  initialize_display();
  initialize_debug_startup();

}

// --------------------------------------------------------------------------------------------

void loop()
{
  
  // this is where the magic happens
  
  #ifdef OPTION_WATCHDOG_TIMER
    wdt_reset();
  #endif  //OPTION_WATCHDOG_TIMER
  
  #if defined(FEATURE_BEACON) && defined(FEATURE_MEMORIES)
    if (keyer_machine_mode == BEACON) {
      delay(201);
      while (keyer_machine_mode == BEACON) {  // if we're in beacon mode, just keep playing memory 1
        if (!send_buffer_bytes) {
          play_memory(0);
        }
        service_send_buffer(PRINTCHAR);
        #ifdef FEATURE_SERIAL
          check_serial();
        #endif
        #ifdef OPTION_WATCHDOG_TIMER
          wdt_reset();
        #endif  //OPTION_WATCHDOG_TIMER      
      }
    }
  #endif //defined(FEATURE_BEACON) && defined(FEATURE_MEMORIES)

  if (keyer_machine_mode == KEYER_NORMAL) {
    #ifdef FEATURE_COMMAND_BUTTONS
      check_command_buttons();
    #endif //FEATURE_COMMAND_BUTTONS
    check_paddles();
    service_dit_dah_buffers();

    #if defined(FEATURE_SERIAL)       
      check_serial();
      check_paddles();            
      service_dit_dah_buffers();
    #endif //FEATURE_SERIAL

    service_send_buffer(PRINTCHAR);
    check_ptt_tail();

    #ifdef FEATURE_POTENTIOMETER
      check_potentiometer();
    #endif //FEATURE_POTENTIOMETER
    
    #ifdef FEATURE_ROTARY_ENCODER
      check_rotary_encoder();
    #endif //FEATURE_ROTARY_ENCODER

    #ifdef FEATURE_PS2_KEYBOARD
      check_ps2_keyboard();
    #endif //FEATURE_PS2_KEYBOARD
    
    #if defined(FEATURE_USB_KEYBOARD) || defined(FEATURE_USB_MOUSE)
      service_usb();
    #endif //FEATURE_USB_KEYBOARD || FEATURE_USB_MOUSE   

    check_for_dirty_configuration();

    #ifdef FEATURE_DEAD_OP_WATCHDOG
      check_for_dead_op();
    #endif //FEATURE_DEAD_OP_WATCHDOG

    #ifdef FEATURE_MEMORIES
      check_memory_repeat();
    #endif //FEATURE_MEMORIES

    #ifdef FEATURE_DISPLAY
      check_paddles();
      service_dit_dah_buffers();
      service_send_buffer(PRINTCHAR);
      service_display();
    #endif //FEATURE_DISPLAY
    
    #ifdef FEATURE_CW_DECODER
      service_cw_decoder();
    #endif //FEATURE_CW_DECODER
    
    #ifdef FEATURE_LED_RING
      update_led_ring();
    #endif //FEATURE_LED_RING
      
    #ifdef FEATURE_SLEEP
      check_sleep();
    #endif //FEATURE_SLEEP

    #ifdef FEATURE_PTT_INTERLOCK
      service_ptt_interlock();
    #endif //FEATURE_PTT_INTERLOCK
    
    #ifdef FEATURE_PADDLE_ECHO
      service_paddle_echo();
    #endif    

    #ifdef FEATURE_STRAIGHT_KEY
      service_straight_key();
    #endif //FEATURE_STRAIGHT_KEY

    #if defined(FEATURE_COMPETITION_COMPRESSION_DETECTION)
      service_competition_compression_detection();
    #endif //FEATURE_COMPETITION_COMPRESSION_DETECTION

  }
  
}

// Subroutines --------------------------------------------------------------------------------------------


// Are you a radio artisan ?


#if defined(FEATURE_COMPETITION_COMPRESSION_DETECTION)
  void service_competition_compression_detection(){

//zzzzzz

    static byte compression_detection_indicator_on = 0;
    static unsigned long last_compression_check_time = 0;
    
    
    

    if ((millis() - last_compression_check_time) > 1000){
      float time_average = 0;
      if (time_array_index == COMPETITION_COMPRESSION_DETECTION_ARRAY_SIZE){
        for (int i = 0;i < COMPETITION_COMPRESSION_DETECTION_ARRAY_SIZE;i++){
          time_average = time_average + time_array[i];
        }
        time_average = time_average / COMPETITION_COMPRESSION_DETECTION_ARRAY_SIZE;
        if (time_average < ((1200/configuration.wpm)*COMPETITION_COMPRESSION_DETECTION_AVERAGE_ALARM_THRESHOLD)){
          if (!compression_detection_indicator_on){
            compression_detection_indicator_on = 1;
            digitalWrite(compression_detection_pin,HIGH);
            #if defined(DEBUG_FEATURE_COMPETITION_COMPRESSION_DETECTION)
              debug_serial_port->print("service_competition_compression_detection: time_array: ");
              for (int i = 0;i < COMPETITION_COMPRESSION_DETECTION_ARRAY_SIZE;i++){
                debug_serial_port->print(time_array[i]);
                debug_serial_port->print(" ");
              }            
              debug_serial_port->print("\n\rservice_competition_compression_detection: COMPRESSION DETECTION ON  average: ");
              debug_serial_port->println(time_average);              
            #endif
          }

        } else {
          if (compression_detection_indicator_on){
            compression_detection_indicator_on = 0;
            digitalWrite(compression_detection_pin,LOW);
            #if defined(DEBUG_FEATURE_COMPETITION_COMPRESSION_DETECTION)
              debug_serial_port->print("service_competition_compression_detection: time_array: ");
              for (int i = 0;i < COMPETITION_COMPRESSION_DETECTION_ARRAY_SIZE;i++){
                debug_serial_port->print(time_array[i]);
                debug_serial_port->print(" ");
              }                 
              debug_serial_port->print("\n\rservice_competition_compression_detection: COMPRESSION DETECTION OFF  average: ");
              debug_serial_port->println(time_average);
            #endif
          }
        }
      }
      last_compression_check_time = millis();
    }

  }
#endif //FEATURE_COMPETITION_COMPRESSION_DETECTION

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_STRAIGHT_KEY
  long service_straight_key(){

    static byte last_straight_key_state = 0;
    
  
    

    if (digitalRead(pin_straight_key) == STRAIGHT_KEY_ACTIVE_STATE){
      if (!last_straight_key_state){
        tx_and_sidetone_key(1,MANUAL_SENDING);
        last_straight_key_state = 1;


        #ifdef FEATURE_MEMORIES
          clear_send_buffer();
          repeat_memory = 255;
        #endif

      }
    } else {
      if (last_straight_key_state){
        tx_and_sidetone_key(0,MANUAL_SENDING);
        last_straight_key_state = 0;
      }
    }


//zzzzzzzz

  #if defined(FEATURE_STRAIGHT_KEY_DECODE)

    static unsigned long last_transition_time = 0;
    static unsigned long last_decode_time = 0;
    static byte last_state = 0;
    static int decode_elements[16];                  // this stores received element lengths in mS (positive = tone, minus = no tone)
    static byte decode_element_pointer = 0;
    static float decode_element_tone_average = 0;
    static float decode_element_no_tone_average = 0;
    static int no_tone_count = 0;
    static int tone_count = 0;
    byte decode_it_flag = 0;
    
    int element_duration = 0;
    static float decoder_wpm = configuration.wpm;
    long decode_character = 0;
    static byte space_sent = 0;
    #if defined(FEATURE_COMMAND_LINE_INTERFACE) && defined(FEATURE_STRAIGHT_KEY_ECHO)
      static byte screen_column = 0;
      static int last_printed_decoder_wpm = 0;
    #endif
    
    #if defined(FEATURE_CW_COMPUTER_KEYBOARD) 
      static byte cw_keyboard_no_space = 0;
      char cw_keyboard_character_to_send;
      static byte cw_keyboard_backspace_flag = 0;
    #endif //defined(FEATURE_CW_COMPUTER_KEYBOARD)       

   
    if  (last_transition_time == 0) { 
      if (last_straight_key_state == 1) {  // is this our first tone?
        last_transition_time = millis();
        last_state = 1;
        
        #ifdef FEATURE_SLEEP
          last_activity_time = millis(); 
        #endif //FEATURE_SLEEP
        
      } else {
        
          if ((last_decode_time > 0) && (!space_sent) && ((millis() - last_decode_time) > ((1200/decoder_wpm)*CW_DECODER_SPACE_PRINT_THRESH))) { // should we send a space?
             #if defined(FEATURE_SERIAL) && defined(FEATURE_STRAIGHT_KEY_ECHO)
               #ifdef FEATURE_COMMAND_LINE_INTERFACE
                 primary_serial_port->write(32);
                 screen_column++;
               #endif //FEATURE_COMMAND_LINE_INTERFACE
             #endif //FEATURE_SERIAL
             #ifdef FEATURE_DISPLAY
               display_scroll_print_char(' ');
             #endif //FEATURE_DISPLAY
             space_sent = 1;
             
            #if defined(FEATURE_CW_COMPUTER_KEYBOARD)
              if (!cw_keyboard_no_space){
                Keyboard.write(' ');
                #ifdef DEBUG_CW_COMPUTER_KEYBOARD
                  debug_serial_port->println("service_straight_key: Keyboard.write: <space>");
                #endif //DEBUG_CW_COMPUTER_KEYBOARD 
              }
              cw_keyboard_no_space = 0;   
            #endif //defined(FEATURE_CW_COMPUTER_KEYBOARD)    
                
          }// should we send a space?
      }
    } else {
      if (last_straight_key_state != last_state) {
        // we have a transition 
        element_duration = millis() - last_transition_time;
        if (element_duration > CW_DECODER_NOISE_FILTER) {                                    // filter out noise
          if (last_straight_key_state == 1) {  // we have a tone
            decode_elements[decode_element_pointer] = (-1 * element_duration);  // the last element was a space, so make it negative
            no_tone_count++;
            if (decode_element_no_tone_average == 0) {
              decode_element_no_tone_average = element_duration;
            } else {
              decode_element_no_tone_average = (element_duration + decode_element_no_tone_average) / 2;
            }
            decode_element_pointer++;
            last_state = 1;
          } else {  // we have no tone
            decode_elements[decode_element_pointer] = element_duration;  // the last element was a tone, so make it positive 
            tone_count++;       
            if (decode_element_tone_average == 0) {
              decode_element_tone_average = element_duration;
            } else {
              decode_element_tone_average = (element_duration + decode_element_tone_average) / 2;
            }
            last_state = 0;
            decode_element_pointer++;
          }
          last_transition_time = millis();
          if (decode_element_pointer == 16) { decode_it_flag = 1; }  // if we've filled up the array, go ahead and decode it
        }
        
        
      } else {
        // no transition
        element_duration = millis() - last_transition_time;
        if (last_state == 0)  {
          // we're still high (no tone) - have we reached character space yet?        
          //if ((element_duration > (decode_element_no_tone_average * 2.5)) || (element_duration > (decode_element_tone_average * 2.5))) {
          if (element_duration > (float(1200/decoder_wpm)*CW_DECODER_SPACE_DECODE_THRESH)) {
            decode_it_flag = 1;
          }
        } else {
          // have we had tone for an outrageous amount of time?  
        }
      }
     }
    
   
   
    if (decode_it_flag) {                      // are we ready to decode the element array?

      // adjust the decoder wpm based on what we got
      
      if ((no_tone_count > 0) && (tone_count > 1)){ // NEW
      
        if (decode_element_no_tone_average > 0) {
          if (abs((1200/decode_element_no_tone_average) - decoder_wpm) < 5) {
            decoder_wpm = (decoder_wpm + (1200/decode_element_no_tone_average))/2;
          } else {
            if (abs((1200/decode_element_no_tone_average) - decoder_wpm) < 10) {
              decoder_wpm = (decoder_wpm + decoder_wpm + (1200/decode_element_no_tone_average))/3;
            } else {
              if (abs((1200/decode_element_no_tone_average) - decoder_wpm) < 20) {
                decoder_wpm = (decoder_wpm + decoder_wpm + decoder_wpm + (1200/decode_element_no_tone_average))/4;    
              }      
            }
          }
        }
      
      
      } // NEW
      
      #ifdef DEBUG_FEATURE_STRAIGHT_KEY_ECHO
        if (abs(decoder_wpm - last_printed_decoder_wpm) > 0.9) {
          debug_serial_port->print("<");
          debug_serial_port->print(int(decoder_wpm));
          debug_serial_port->print(">");
          last_printed_decoder_wpm = decoder_wpm;
        }
      #endif //DEBUG_FEATURE_STRAIGHT_KEY_ECHO
      
      for (byte x = 0;x < decode_element_pointer; x++) {
        if (decode_elements[x] > 0) {  // is this a tone element?          
          // we have no spaces to time from, use the current wpm
          if ((decode_elements[x]/(1200/decoder_wpm)) < 2.1 ) {  // changed from 1.3 to 2.1 2015-05-12
            decode_character = (decode_character * 10) + 1; // we have a dit
          } else {
            decode_character = (decode_character * 10) + 2; // we have a dah
          }  
        }
        #ifdef DEBUG_FEATURE_STRAIGHT_KEY_ECHO
          debug_serial_port->print(F("service_straight_key: decode_elements["));
          debug_serial_port->print(x);
          debug_serial_port->print(F("]: "));
          debug_serial_port->println(decode_elements[x]);
        #endif //DEBUG_FEATURE_STRAIGHT_KEY_ECHO
      }

      #ifdef DEBUG_FEATURE_STRAIGHT_KEY_ECHO
        debug_serial_port->print(F("service_straight_key: decode_element_tone_average: "));
        debug_serial_port->println(decode_element_tone_average);
        debug_serial_port->print(F("service_straight_key: decode_element_no_tone_average: "));
        debug_serial_port->println(decode_element_no_tone_average);
        debug_serial_port->print(F("service_straight_key: decode_element_no_tone_average wpm: "));
        debug_serial_port->println(1200/decode_element_no_tone_average);
        debug_serial_port->print(F("service_straight_key: decoder_wpm: "));
        debug_serial_port->println(decoder_wpm);
        debug_serial_port->print(F("service_straight_key: decode_character: "));
        debug_serial_port->println(decode_character);
      #endif //DEBUG_FEATURE_STRAIGHT_KEY_ECHO

      #if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && defined(FEATURE_STRAIGHT_KEY_ECHO)
        if (cli_straight_key_echo){
          primary_serial_port->write(convert_cw_number_to_ascii(decode_character));
          #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
            secondary_serial_port->write(convert_cw_number_to_ascii(decode_character));
          #endif
          screen_column++;
        }
      #endif //defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)

      #if defined(FEATURE_DISPLAY) && defined(FEATURE_STRAIGHT_KEY_ECHO)
        if (cli_straight_key_echo){display_scroll_print_char(convert_cw_number_to_ascii(decode_character));}
      #endif //FEATURE_DISPLAY
        
      #if defined(FEATURE_CW_COMPUTER_KEYBOARD)       
        switch (decode_character){
          case 111111:
          case 1111111:
          case 11111111:
          case 111111111:
            Keyboard.write(KEY_BACKSPACE); // backspace
            cw_keyboard_no_space = 1;
            break;
          case 1212:  // prosign AA
            Keyboard.write(KEY_RETURN);
            cw_keyboard_no_space = 1;   
            break;
          case 211222: // prosign DO
            Keyboard.write(KEY_CAPS_LOCK);
            #ifdef OPTION_CW_KEYBOARD_CAPSLOCK_BEEP
              if (cw_keyboard_capslock_on){
                beep();delay(100);
                boop();
                cw_keyboard_capslock_on = 0;
              } else {
                boop();
                beep();
                cw_keyboard_capslock_on = 1;
              }
            #endif //OPTION_CW_KEYBOARD_CAPSLOCK_BEEP
            cw_keyboard_no_space = 1;       
            break;
      
          #ifdef OPTION_CW_KEYBOARD_ITALIAN  // courtesy of Giorgio IZ2XBZ
            case 122121: // "@"
              Keyboard.press(KEY_LEFT_ALT);
              Keyboard.write(59);
              Keyboard.releaseAll();
              break;
            case 112211:// "?"
              Keyboard.write(95);
              break;
            case 11221: // "!"
              Keyboard.write(33);
              break;
            case 21121: // "/"
              Keyboard.write(38);
              break;
            case 21112: // "=" or "BT"
              Keyboard.write(41);  
              break;
            case 12212: //à
              Keyboard.write(39);  
              break;
            case 11211: //è
              Keyboard.write(91);  
              break;
            case 12221: //ì
              Keyboard.write(61);  
              break;
            case 2221: //ò
              Keyboard.write(59);  
              break;
              case 1122: //ù
              Keyboard.write(92);  
              break;
            case 21221: // (
              Keyboard.write(42);  
              break;
            case 212212: // )
              Keyboard.write(40);  
              break;
            case 12111: // &
              Keyboard.write(94);  
              break;
            case 222111: //:
              Keyboard.write(62);  
              break;
            case 212121: //;
              Keyboard.write(60);  
            break;
              case 12121: //+
              Keyboard.write(93);  
              break;
            case 211112: // -
              Keyboard.write(47);  
              break;   
          #endif //OPTION_CW_KEYBOARD_ITALIAN
            
          default:
            cw_keyboard_character_to_send = convert_cw_number_to_ascii(decode_character);
            if ((cw_keyboard_character_to_send > 64) && (cw_keyboard_character_to_send < 91)) {cw_keyboard_character_to_send = cw_keyboard_character_to_send + 32;}
            if (cw_keyboard_character_to_send=='*'){
              cw_keyboard_no_space = 1;
              #ifdef OPTION_UNKNOWN_CHARACTER_ERROR_TONE
                boop();
              #endif //OPTION_UNKNOWN_CHARACTER_ERROR_TONE
            } else {
              if (!((cw_keyboard_backspace_flag) && ((decode_character == 1) || (decode_character == 11) || (decode_character == 111) || (decode_character == 1111) || (decode_character == 11111)))){
                Keyboard.write(char(cw_keyboard_character_to_send));
              }
              cw_keyboard_backspace_flag = 0;
            }
            break;
            
        } //switch (decode_character)
          
        #ifdef DEBUG_CW_COMPUTER_KEYBOARD
          debug_serial_port->print("service_straight_key: Keyboard.write: ");
          debug_serial_port->write(character_to_send);
          debug_serial_port->println();
        #endif //DEBUG_CW_COMPUTER_KEYBOARD
       

      #endif //defined(FEATURE_CW_COMPUTER_KEYBOARD) 

      
      // reinitialize everything
      last_transition_time = 0;
      last_decode_time = millis();
      decode_element_pointer = 0; 
      decode_element_tone_average = 0;
      decode_element_no_tone_average = 0;
      space_sent = 0;
      no_tone_count = 0;
      tone_count = 0;      
      
    } //if (decode_it_flag)
    
    #if defined(FEATURE_SERIAL) && defined(FEATURE_STRAIGHT_KEY_ECHO)
      #ifdef FEATURE_COMMAND_LINE_INTERFACE
      if ((screen_column > CW_DECODER_SCREEN_COLUMNS) && (cli_straight_key_echo)) {    
        #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
          secondary_serial_port->println();
        #else
          primary_serial_port->println();
        #endif    
        screen_column = 0;
      }
      #endif //FEATURE_COMMAND_LINE_INTERFACE
    #endif //FEATURE_SERIAL

  return(decode_character);

  #endif //FEATURE_STRAIGHT_KEY_DECODE


  




  }
#endif //FEATURE_STRAIGHT_KEY

//-------------------------------------------------------------------------------------------------------

void initialize_cw_keyboard(){

  #ifdef FEATURE_CW_COMPUTER_KEYBOARD
    Keyboard.begin();
  #endif //FEATURE_CW_COMPUTER_KEYBOARD

}

//-------------------------------------------------------------------------------------------------------

#ifdef HARDWARE_ARDUINO_DUE

/*

This code from http://forum.arduino.cc/index.php?topic=136500.0

*/


// timers TC0 TC1 TC2   channels 0-2 ids 0-2  3-5  6-8     AB 0 1
// use TC1 channel 0 

#define TONE_TIMER TC1
#define TONE_CHNL 0
#define TONE_IRQ TC3_IRQn

// TIMER_CLOCK4   84MHz/128 with 16 bit counter give 10 Hz to 656KHz

static uint8_t pinEnabled[PINS_COUNT];
static uint8_t TCChanEnabled = 0;
static boolean pin_state = false ;
static Tc *chTC = TONE_TIMER;
static uint32_t chNo = TONE_CHNL;

volatile static int32_t toggle_count;
static uint32_t tone_pin;  

void toneDUE(uint32_t ulPin, uint32_t frequency, int32_t duration = 0){
  
  // frequency (in hertz) and duration (in milliseconds)
  
  const uint32_t rc = VARIANT_MCK / 256 / frequency; 
  tone_pin = ulPin;
  toggle_count = 0;  // strange  wipe out previous duration
  if (duration > 0 ){
    toggle_count = 2 * frequency * duration / 1000;
  } else {
    toggle_count = -1;
  }
  if (!TCChanEnabled) {
    pmc_set_writeprotect(false);
    pmc_enable_periph_clk((uint32_t)TONE_IRQ);
    TC_Configure(chTC, chNo, TC_CMR_TCCLKS_TIMER_CLOCK4 |
      TC_CMR_WAVE |         // Waveform mode
      TC_CMR_WAVSEL_UP_RC ); // Counter running up and reset when equals to RC
    chTC->TC_CHANNEL[chNo].TC_IER=TC_IER_CPCS;  // RC compare interrupt
    chTC->TC_CHANNEL[chNo].TC_IDR=~TC_IER_CPCS;
    NVIC_EnableIRQ(TONE_IRQ);
    TCChanEnabled = 1;
  }
  if (!pinEnabled[ulPin]) {
    pinMode(ulPin, OUTPUT);
    pinEnabled[ulPin] = 1;
  }
  TC_Stop(chTC, chNo);
  TC_SetRC(chTC, chNo, rc);    // set frequency
  TC_Start(chTC, chNo);
}

void noToneDUE(uint32_t ulPin){
  
  TC_Stop(chTC, chNo);  // stop timer
  digitalWrite(ulPin,LOW);  // no signal on pin

}

// timer ISR  TC1 ch 0
void TC3_Handler ( void ) {
  
  TC_GetStatus(TC1, 0);
  if (toggle_count != 0){
    // toggle pin  TODO  better
    digitalWrite(tone_pin,pin_state= !pin_state);
    if (toggle_count > 0) toggle_count--;
  } else {
    noTone(tone_pin);
  }
  
}

#endif //HARDWARE_ARDUINO_DUE


//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_SLEEP
void wakeup() {
  detachInterrupt(0);
}
#endif //FEATURE_SLEEP

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_SLEEP
void check_sleep(){
  
  if ((millis() - last_activity_time) > (go_to_sleep_inactivity_time*60000)){
    
    if (config_dirty) {  // force a configuration write to EEPROM if the config is dirty
      last_config_write = 0;
      check_for_dirty_configuration();
    }
    
    attachInterrupt(0, wakeup, LOW);
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    #ifdef DEBUG_SLEEP
    debug_serial_port->println(F("check_sleep: entering sleep"));
    delay(1000);
    #endif //DEBUG_SLEEP

    sleep_mode();

    // shhhhh! we are asleep here !!

    sleep_disable();
    last_activity_time = millis();     
    
    #ifdef DEBUG_SLEEP
    debug_serial_port->println(F("check_sleep: I'm awake!"));
    #endif //DEBUG_SLEEP
  }
  
  
}
#endif //FEATURE_SLEEP

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_DISPLAY
void service_display() {

  #ifdef DEBUG_LOOP
  debug_serial_port->println(F("loop: entering service_display"));
  #endif    

  byte x = 0;

  if (lcd_status == LCD_REVERT) {
    lcd_status = lcd_previous_status;
    switch (lcd_status) {
      case LCD_CLEAR: lcd_clear(); break;
      case LCD_SCROLL_MSG:
         lcd.clear();
         for (x = 0;x < LCD_ROWS;x++){
           //clear_display_row(x);
           lcd.setCursor(0,x);
           lcd.print(lcd_scroll_buffer[x]);
         }         
         lcd_scroll_flag = 0; 
         lcd_scroll_buffer_dirty = 0;         
         break;
    }
  } else {
    switch (lcd_status) {
      case LCD_CLEAR : break;
      case LCD_TIMED_MESSAGE:
        if (millis() > lcd_timed_message_clear_time) {
          lcd_status = LCD_REVERT;
        }
      case LCD_SCROLL_MSG:
        if (lcd_scroll_buffer_dirty) { 
          if (lcd_scroll_flag) {
            lcd.clear();
            lcd_scroll_flag = 0;
          }         
          for (x = 0;x < LCD_ROWS;x++){
            //clear_display_row(x);
            lcd.setCursor(0,x);
            lcd.print(lcd_scroll_buffer[x]);
          }
          lcd_scroll_buffer_dirty = 0;
        }
      break;
    }
  }

}
#endif



//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_DISPLAY
void display_scroll_print_char(char charin){
  
  static byte column_pointer = 0;
  static byte row_pointer = 0;
  static byte holding_space = 0;
  byte x = 0;

  #ifdef DEBUG_DISPLAY_SCROLL_PRINT_CHAR
  debug_serial_port->print(F("display_scroll_print_char: "));
  debug_serial_port->write(charin);
  debug_serial_port->print(" ");
  debug_serial_port->println(charin);
  #endif //DEBUG_DISPLAY_SCROLL_PRINT_CHAR

  #ifdef OPTION_DISPLAY_NON_ENGLISH_EXTENSIONS
  switch (charin){
    case 220: charin = 0;break; // U_umlaut  (D, ...)
    case 214: charin = 1;break; // O_umlaut  (D, SM, OH, ...)
    case 196: charin = 2;break; // A_umlaut  (D, SM, OH, ...)
    case 198: charin = 3;break; // AE_capital (OZ, LA)
    case 216: charin = 4;break; // OE_capital (OZ, LA)
    case 197: charin = 6;break; // AA_capital (OZ, LA, SM)
    case 209: charin = 7;break; // N-tilde (EA) 
  }
  #endif //OPTION_DISPLAY_NON_ENGLISH_EXTENSIONS

  if (lcd_status != LCD_SCROLL_MSG) {
    lcd_status = LCD_SCROLL_MSG;
    lcd.clear();
  } 

  if (charin == ' '){
    holding_space = 1;
    return;
  }

  if (holding_space){   // ok, I admit this is a hack.  Hold on to spaces and don't scroll until the next char comes in...
    if (column_pointer > (LCD_COLUMNS-1)) {
      row_pointer++;
      column_pointer = 0;
      if (row_pointer > (LCD_ROWS-1)) {
        for (x = 0; x < (LCD_ROWS-1); x++) {
          lcd_scroll_buffer[x] = lcd_scroll_buffer[x+1];
        }
        lcd_scroll_buffer[x] = "";     
        row_pointer--;
        lcd_scroll_flag = 1;
      }    
    } 
    if (column_pointer > 0){ // don't put a space in the first column
      lcd_scroll_buffer[row_pointer].concat(' ');
      column_pointer++;
    }
    holding_space = 0;
  }

  

  if (column_pointer > (LCD_COLUMNS-1)) {
    row_pointer++;
    column_pointer = 0;
    if (row_pointer > (LCD_ROWS-1)) {
      for (x = 0; x < (LCD_ROWS-1); x++) {
        lcd_scroll_buffer[x] = lcd_scroll_buffer[x+1];
      }
      lcd_scroll_buffer[x] = "";     
      row_pointer--;
      lcd_scroll_flag = 1;
    }    
  } 
  lcd_scroll_buffer[row_pointer].concat(charin);
  column_pointer++;
  

  lcd_scroll_buffer_dirty = 1; 
}

#endif //FEATURE_DISPLAY


//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_DISPLAY
void lcd_clear() {

  lcd.clear();
  lcd_status = LCD_CLEAR;

}
#endif
//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_DISPLAY
void lcd_center_print_timed(String lcd_print_string, byte row_number, unsigned int duration)
{
  if (lcd_status != LCD_TIMED_MESSAGE) {
    lcd_previous_status = lcd_status;
    lcd_status = LCD_TIMED_MESSAGE;
    lcd.clear();
  } else {
    clear_display_row(row_number);
  }
  lcd.setCursor(((LCD_COLUMNS - lcd_print_string.length())/2),row_number);
  lcd.print(lcd_print_string);
  lcd_timed_message_clear_time = millis() + duration;
}
#endif

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_DISPLAY
void clear_display_row(byte row_number)
{
  for (byte x = 0; x < LCD_COLUMNS; x++) {
    lcd.setCursor(x,row_number);
    lcd.print(" ");
  }
}
#endif

//-------------------------------------------------------------------------------------------------------

void check_for_dirty_configuration()
{
  #ifdef DEBUG_LOOP
  debug_serial_port->println(F("loop: entering check_for_dirty_configuration"));
  #endif

  if ((config_dirty) && ((millis()-last_config_write)>30000)) {
    write_settings_to_eeprom(0);
    last_config_write = millis();
    #ifdef DEBUG_EEPROM
    debug_serial_port->println(F("check_for_dirty_configuration: wrote config\n"));
    #endif
  }

}

//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_MEMORIES
void check_memory_repeat() {

  #ifdef DEBUG_LOOP
  debug_serial_port->println(F("loop: entering check_memory_repeat"));
  #endif    
  
  if ((repeat_memory < number_of_memories) && ((millis() - last_memory_repeat_time) > configuration.memory_repeat_time)) {
    add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
    add_to_send_buffer(repeat_memory);
    last_memory_repeat_time = millis();
    #ifdef DEBUG_MEMORIES
    debug_serial_port->print(F("check_memory_repeat: added repeat_memory to send buffer\n\r"));
    #endif
  }
  
  if (repeat_memory == 255){last_memory_repeat_time = 0;}

}
#endif

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_DEAD_OP_WATCHDOG
void check_for_dead_op()

  // if the dit or dah paddle is stuck, disable the transmitter line after 100 straight dits or dahs
  // go in and out of command mode to clear or just reset the unit

{
  
  #ifdef DEBUG_LOOP
  debug_serial_port->println(F("loop: entering check_for_dead_op"));
  #endif    
    
  if (dead_op_watchdog_active && ((dit_counter > 100) || (dah_counter > 100))) {
    key_tx = 0;
  }
}
#endif
//-------------------------------------------------------------------------------------------------------

#if (defined(FEATURE_PS2_KEYBOARD) || defined(FEATURE_USB_KEYBOARD)) && defined(FEATURE_MEMORIES)

void repeat_memory_msg(byte memory_number){
  
  #ifdef FEATURE_MEMORIES
  repeat_memory = memory_number;
  #ifdef FEATURE_DISPLAY
  lcd_center_print_timed("Repeat Memory " + String(memory_number+1), 0, default_display_msg_delay); 
  service_display();
  #endif //FEATURE_DISPLAY
  #endif //FEATURE_MEMORIES
}

#endif //defined(FEATURE_PS2_KEYBOARD) || defined(FEATURE_USB_KEYBOARD)

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_PS2_KEYBOARD
void check_ps2_keyboard()
{

  #ifdef DEBUG_LOOP
  debug_serial_port->println(F("loop: entering check_ps2_keyboard"));
  #endif    
  
  static byte keyboard_tune_on = 0;
  static byte ps2_prosign_flag = 0;
  int work_int = 0;
  uint8_t keystroke = 0;
  
  /* NOTE!!! This entire block of code is repeated again below the #else.  This was done to fix a bug with Notepad++ not
             collapsing code correctly when while() statements are encapsulated in #ifdef/#endifs.                        */
  
  #ifdef FEATURE_MEMORIES
  while ((keyboard.available()) && (play_memory_prempt == 0)) {      
    
    // read the next key
    keystroke = keyboard.read();

    #if defined(DEBUG_PS2_KEYBOARD)
    debug_serial_port->print("check_ps2_keyboard: keystroke: ");
    debug_serial_port->println(keystroke,DEC);
    #endif //DEBUG_PS2_KEYBOARD
    
    #ifdef FEATURE_SLEEP
    last_activity_time = millis(); 
    #endif //FEATURE_SLEEP

    if (ps2_keyboard_mode == PS2_KEYBOARD_NORMAL) {
      switch (keystroke) {
        case PS2_PAGEUP : sidetone_adj(20); break;
        case PS2_PAGEDOWN : sidetone_adj(-20); break;
        case PS2_RIGHTARROW : adjust_dah_to_dit_ratio(int(configuration.dah_to_dit_ratio/10)); break;
        case PS2_LEFTARROW : adjust_dah_to_dit_ratio(-1*int(configuration.dah_to_dit_ratio/10)); break;
        case PS2_UPARROW : speed_set(configuration.wpm+1); break;
        case PS2_DOWNARROW : speed_set(configuration.wpm-1); break;
        case PS2_HOME :
          configuration.dah_to_dit_ratio = initial_dah_to_dit_ratio;
          key_tx = 1;
          config_dirty = 1;
          #ifdef FEATURE_DISPLAY
          #ifdef OPTION_MORE_DISPLAY_MSGS
          lcd_center_print_timed("Default ratio", 0, default_display_msg_delay);
          service_display();
          #endif
          #endif           
          break;
        case PS2_TAB :
          if (pause_sending_buffer) {
            pause_sending_buffer = 0;
            #ifdef FEATURE_DISPLAY
            #ifdef OPTION_MORE_DISPLAY_MSGS
            lcd_center_print_timed("Resume", 0, default_display_msg_delay);
            #endif
            #endif                 
          } else {
            pause_sending_buffer = 1;
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Pause", 0, default_display_msg_delay);
            #endif            
          }
        break;  // pause

        case PS2_SCROLL :   // Prosign next two characters
          ps2_prosign_flag = 1;
          #ifdef FEATURE_DISPLAY
          #ifdef OPTION_MORE_DISPLAY_MSGS
          lcd_center_print_timed("Prosign", 0, default_display_msg_delay);
          #endif
          #endif          
          break;

        #ifdef FEATURE_MEMORIES
        case PS2_F1 : ps2_usb_keyboard_play_memory(0); break;
        case PS2_F2 : ps2_usb_keyboard_play_memory(1); break;
        case PS2_F3 : ps2_usb_keyboard_play_memory(2); break;
        #ifndef OPTION_SAVE_MEMORY_NANOKEYER
        case PS2_F4 : ps2_usb_keyboard_play_memory(3); break;
        case PS2_F5 : ps2_usb_keyboard_play_memory(4); break;
        case PS2_F6 : ps2_usb_keyboard_play_memory(5); break;
        case PS2_F7 : ps2_usb_keyboard_play_memory(6); break;
        case PS2_F8 : ps2_usb_keyboard_play_memory(7); break;
        case PS2_F9 : ps2_usb_keyboard_play_memory(8); break;
        case PS2_F10 : ps2_usb_keyboard_play_memory(9); break;
        case PS2_F11 : ps2_usb_keyboard_play_memory(10); break;
        case PS2_F12 : ps2_usb_keyboard_play_memory(11); break;
        #endif //OPTION_SAVE_MEMORY_NANOKEYER
        case PS2_F1_ALT : if (number_of_memories > 0) {repeat_memory_msg(0);} break;
        case PS2_F2_ALT : if (number_of_memories > 1) {repeat_memory_msg(1);} break;
        case PS2_F3_ALT : if (number_of_memories > 2) {repeat_memory_msg(2);} break;
        #ifndef OPTION_SAVE_MEMORY_NANOKEYER
        case PS2_F4_ALT : if (number_of_memories > 3) {repeat_memory_msg(3);} break;
        case PS2_F5_ALT : if (number_of_memories > 4) {repeat_memory_msg(4);} break;
        case PS2_F6_ALT : if (number_of_memories > 5) {repeat_memory_msg(5);} break;
        case PS2_F7_ALT : if (number_of_memories > 6) {repeat_memory_msg(6);} break;
        case PS2_F8_ALT : if (number_of_memories > 7) {repeat_memory_msg(7);} break;
        case PS2_F9_ALT : if (number_of_memories > 8) {repeat_memory_msg(8);} break;
        case PS2_F10_ALT : if (number_of_memories > 9) {repeat_memory_msg(9);} break;
        case PS2_F11_ALT : if (number_of_memories > 10) {repeat_memory_msg(10);} break;
        case PS2_F12_ALT : if (number_of_memories > 11) {repeat_memory_msg(11);} break;
        #endif //OPTION_SAVE_MEMORY_NANOKEYER
        #endif //FEATURE_MEMORIES

        case PS2_DELETE : if (send_buffer_bytes > 0) { send_buffer_bytes--; } break;
        case PS2_ESC :  // clear the serial send buffer and a bunch of other stuff
          if (manual_ptt_invoke) {
            manual_ptt_invoke = 0;
            ptt_unkey();
          }
          if (keyboard_tune_on) {
            tx_and_sidetone_key(0,MANUAL_SENDING);
            keyboard_tune_on = 0;
          }
          if (pause_sending_buffer) {
            pause_sending_buffer = 0;
          }
          clear_send_buffer();
          #ifdef FEATURE_MEMORIES
          //clear_memory_button_buffer();
          play_memory_prempt = 1;
          repeat_memory = 255;
          #endif
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Abort", 0, default_display_msg_delay);
          #endif          
          break;

        #ifdef FEATURE_MEMORIES
        case PS2_F1_SHIFT  :
          ps2_keyboard_program_memory(0);
          break;

        case PS2_F2_SHIFT  :
          ps2_keyboard_program_memory(1);
          break;

        case PS2_F3_SHIFT  :
          ps2_keyboard_program_memory(2);
          break;


        #ifndef OPTION_SAVE_MEMORY_NANOKEYER
        case PS2_F4_SHIFT  :
          ps2_keyboard_program_memory(3);
          break;

        case PS2_F5_SHIFT  :
          ps2_keyboard_program_memory(4);
          break;

        case PS2_F6_SHIFT  :
          ps2_keyboard_program_memory(5);
          break;

        case PS2_F7_SHIFT  :
          ps2_keyboard_program_memory(6);
          break;

        case PS2_F8_SHIFT  :
          ps2_keyboard_program_memory(7);
          break;

        case PS2_F9_SHIFT  :
          ps2_keyboard_program_memory(8);
          break;

        case PS2_F10_SHIFT  :
          ps2_keyboard_program_memory(9);
          break;

        case PS2_F11_SHIFT  :
          ps2_keyboard_program_memory(10);
          break;

        case PS2_F12_SHIFT  :
          ps2_keyboard_program_memory(11);
          break;
        #endif //OPTION_SAVE_MEMORY_NANOKEYER
        #endif //FEATURE_MEMORIES

        #ifndef OPTION_SAVE_MEMORY_NANOKEYER
        case PS2_INSERT :   // send serial number and increment
          put_serial_number_in_send_buffer();
          serial_number++;
          break;

        case PS2_END :      // send serial number no increment
          put_serial_number_in_send_buffer();
          break;

        case PS2_BACKSPACE_SHIFT :    // decrement serial number
          serial_number--;
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Serial: " + String(serial_number), 0, default_display_msg_delay);
          #endif          
          break;
        
        #endif //OPTION_SAVE_MEMORY_NANOKEYER

        case PS2_LEFT_ALT :
          #ifdef DEBUG_PS2_KEYBOARD
          debug_serial_port->println("PS2_LEFT_ALT\n");
          #endif
          break;


        case PS2_A_CTRL :
          configuration.keyer_mode = IAMBIC_A;
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Iambic A", 0, default_display_msg_delay);
          #endif

          config_dirty = 1;
          break;

        case PS2_B_CTRL :
          configuration.keyer_mode = IAMBIC_B;
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Iambic B", 0, default_display_msg_delay);
          #endif          
          config_dirty = 1;
          break;

        case PS2_D_CTRL :
          configuration.keyer_mode = ULTIMATIC;
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Ultimatic", 0, default_display_msg_delay);
          #endif        
          config_dirty = 1;
          break;

        #ifndef OPTION_SAVE_MEMORY_NANOKEYER
        case PS2_E_CTRL :
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Enter Serial #", 0, default_display_msg_delay);
          #else        
          boop_beep();
          #endif
          work_int = ps2_keyboard_get_number_input(4,0,10000);
          if (work_int > 0) {
            serial_number = work_int;
            #ifdef FEATURE_DISPLAY
            lcd_status = LCD_REVERT;
            #else             
            beep();
            #endif
          }
          break;
        #endif //OPTION_SAVE_MEMORY_NANOKEYER

        case PS2_G_CTRL :
          configuration.keyer_mode = BUG;
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Bug", 0, default_display_msg_delay);
          #endif
          config_dirty = 1;
          break;

        #ifdef FEATURE_HELL
        case PS2_H_CTRL :       
          if (char_send_mode == CW) {
            char_send_mode = HELL;
            beep();
          } else {
            char_send_mode = CW;
            beep();
          }
          break;
        #endif //FEATURE_HELL

        case PS2_I_CTRL :
          if (key_tx) {
            key_tx = 0;
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("TX Off", 0, default_display_msg_delay);
            #endif
            
          } else {
            key_tx = 1;
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("TX On", 0, default_display_msg_delay);
            #endif      
          }
          break;

        #ifdef FEATURE_FARNSWORTH
        case PS2_M_CTRL:         
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Farnsworth WPM", 0, default_display_msg_delay);
          #else          
          boop_beep();
          #endif
          work_int = ps2_keyboard_get_number_input(3,-1,1000);
          if (work_int > -1) {
            configuration.wpm_farnsworth = work_int;
            #ifdef FEATURE_DISPLAY
            lcd_status = LCD_REVERT;
            #else
            beep();
            #endif
            config_dirty = 1;
          }
          
          break;
          #endif //FEATURE_FARNSWORTH

        case PS2_N_CTRL :
          if (configuration.paddle_mode == PADDLE_NORMAL) {
            configuration.paddle_mode = PADDLE_REVERSE;
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Paddle Reverse", 0, default_display_msg_delay);
            #endif
          } else {
            configuration.paddle_mode = PADDLE_NORMAL;
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Paddle Normal", 0, default_display_msg_delay);
            #endif      
          }
          config_dirty = 1;
          break;

        case PS2_O_CTRL :
          if ((configuration.sidetone_mode == SIDETONE_ON) || (configuration.sidetone_mode == SIDETONE_PADDLE_ONLY)){
            configuration.sidetone_mode = SIDETONE_OFF;
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Sidetone Off", 0, default_display_msg_delay);
            #endif      
          } else {
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Sidetone On", 0, default_display_msg_delay);
            #endif      
            configuration.sidetone_mode = SIDETONE_ON;
          }
          config_dirty = 1;
         break;

        case PS2_T_CTRL :
          #ifdef FEATURE_MEMORIES
          repeat_memory = 255;
          #endif
          if (keyboard_tune_on) {
            tx_and_sidetone_key(0,MANUAL_SENDING);
            keyboard_tune_on = 0;
            #ifdef FEATURE_DISPLAY
            lcd_status = LCD_REVERT;
            #endif // FEATURE_DISPLAY
          } else {
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Tune", 0, default_display_msg_delay);
            #endif      
            tx_and_sidetone_key(1,MANUAL_SENDING);
            keyboard_tune_on = 1;
          }
          break;

        case PS2_U_CTRL :
          if (ptt_line_activated) {
            manual_ptt_invoke = 0;
            ptt_unkey();
            #ifdef FEATURE_DISPLAY
            lcd_status = LCD_REVERT;
            #endif // FEATURE_DISPLAY            
          } else {
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("PTT Invoke", 0, default_display_msg_delay);
            #endif      
            manual_ptt_invoke = 1;
            ptt_key();
          }
          break;

        case PS2_W_CTRL :
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("WPM Adjust", 0, default_display_msg_delay);
          #else
          boop_beep();
          #endif
          work_int = ps2_keyboard_get_number_input(3,0,1000);
          if (work_int > 0) {
            speed_set(work_int);
            #ifdef FEATURE_DISPLAY
            lcd_status = LCD_REVERT;
            #else
            beep();
            #endif
            config_dirty = 1;
          }
          break;

        case PS2_F1_CTRL :
          switch_to_tx_silent(1);
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("TX 1", 0, default_display_msg_delay);
          #endif          
          break;

        case PS2_F2_CTRL :
          if ((ptt_tx_2) || (tx_key_line_2)) {
            switch_to_tx_silent(2);          
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("TX 2", 0, default_display_msg_delay);
            #endif                      
          }
          break;
        #ifndef OPTION_SAVE_MEMORY_NANOKEYER
        case PS2_F3_CTRL :
          if ((ptt_tx_3)  || (tx_key_line_3)) {
            switch_to_tx_silent(3);                       
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("TX 3", 0, default_display_msg_delay);
            #endif                                  
          }
          break;

        case PS2_F4_CTRL :
          if ((ptt_tx_4)  || (tx_key_line_4)) {
            switch_to_tx_silent(4);   
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("TX 4", 0, default_display_msg_delay);
            #endif                                  
          }
          break;

        case PS2_F5_CTRL :
          if ((ptt_tx_5)  || (tx_key_line_5)) {
            switch_to_tx_silent(5);  
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("TX 5", 0, default_display_msg_delay);
            #endif                      
          }
          break;

        case PS2_F6_CTRL :
          if ((ptt_tx_6)  || (tx_key_line_6)) {
            switch_to_tx_silent(6);
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("TX 6", 0, default_display_msg_delay);
            #endif                                  
          }
          break;
        #endif //OPTION_SAVE_MEMORY_NANOKEYER

        #ifdef FEATURE_AUTOSPACE
        case PS2_Z_CTRL:
          if (configuration.autospace_active) {
            configuration.autospace_active = 0;
            config_dirty = 1;
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Autospace Off", 0, default_display_msg_delay);
            #endif                                  
          } else {
            configuration.autospace_active = 1;
            config_dirty = 1;
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Autospace On", 0, default_display_msg_delay);
            #endif                                  
          }
          break;
        #endif

        default :
          if ((keystroke > 31) && (keystroke < 255 /*123*/)) {
            if (ps2_prosign_flag) {
              add_to_send_buffer(SERIAL_SEND_BUFFER_PROSIGN);
              ps2_prosign_flag = 0;
            }
            keystroke = uppercase(keystroke);
            add_to_send_buffer(keystroke);
            #ifdef FEATURE_MEMORIES
            repeat_memory = 255;
            #endif
          }
          break;
      }
    } else {

    }
  } //while ((keyboard.available()) && (play_memory_prempt == 0))
    
    
    
  #else //FEATURE_MEMORIES --------------------------------------------------------------------



  while (keyboard.available()) {
 
    // read the next key
    keystroke = keyboard.read();
    
    #ifdef FEATURE_SLEEP
    last_activity_time = millis(); 
    #endif //FEATURE_SLEEP

    if (ps2_keyboard_mode == PS2_KEYBOARD_NORMAL) {
      switch (keystroke) {
        case PS2_PAGEUP : sidetone_adj(20); break;
        case PS2_PAGEDOWN : sidetone_adj(-20); break;
        case PS2_RIGHTARROW : adjust_dah_to_dit_ratio(int(configuration.dah_to_dit_ratio/10)); break;
        case PS2_LEFTARROW : adjust_dah_to_dit_ratio(-1*int(configuration.dah_to_dit_ratio/10)); break;
        case PS2_UPARROW : speed_set(configuration.wpm+1); break;
        case PS2_DOWNARROW : speed_set(configuration.wpm-1); break;
        case PS2_HOME :
          configuration.dah_to_dit_ratio = initial_dah_to_dit_ratio;
          key_tx = 1;
          config_dirty = 1;
          #ifdef FEATURE_DISPLAY
          #ifdef OPTION_MORE_DISPLAY_MSGS
          lcd_center_print_timed("Default ratio", 0, default_display_msg_delay);
          service_display();
          #endif
          #endif           
          break;
        case PS2_TAB :
          if (pause_sending_buffer) {
            pause_sending_buffer = 0;
            #ifdef FEATURE_DISPLAY
            #ifdef OPTION_MORE_DISPLAY_MSGS
            lcd_center_print_timed("Resume", 0, default_display_msg_delay);
            #endif
            #endif                 
          } else {
            pause_sending_buffer = 1;
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Pause", 0, default_display_msg_delay);
            #endif            
          }
        break;  // pause

        case PS2_SCROLL :   // Prosign next two characters
          ps2_prosign_flag = 1;
          #ifdef FEATURE_DISPLAY
          #ifdef OPTION_MORE_DISPLAY_MSGS
          lcd_center_print_timed("Prosign", 0, default_display_msg_delay);
          #endif
          #endif          
          break;

        #ifdef FEATURE_MEMORIES
        case PS2_F1 : ps2_usb_keyboard_play_memory(0); break;
        case PS2_F2 : ps2_usb_keyboard_play_memory(1); break;
        case PS2_F3 : ps2_usb_keyboard_play_memory(2); break;
        case PS2_F4 : ps2_usb_keyboard_play_memory(3); break;
        case PS2_F5 : ps2_usb_keyboard_play_memory(4); break;
        case PS2_F6 : ps2_usb_keyboard_play_memory(5); break;
        case PS2_F7 : ps2_usb_keyboard_play_memory(6); break;
        case PS2_F8 : ps2_usb_keyboard_play_memory(7); break;
        case PS2_F9 : ps2_usb_keyboard_play_memory(8); break;
        case PS2_F10 : ps2_usb_keyboard_play_memory(9); break;
        case PS2_F11 : ps2_usb_keyboard_play_memory(10); break;
        case PS2_F12 : ps2_usb_keyboard_play_memory(11); break;
        case PS2_F1_ALT : if (number_of_memories > 0) {repeat_memory_msg(0);} break;
        case PS2_F2_ALT : if (number_of_memories > 1) {repeat_memory_msg(1);} break;
        case PS2_F3_ALT : if (number_of_memories > 2) {repeat_memory_msg(2);} break;
        case PS2_F4_ALT : if (number_of_memories > 3) {repeat_memory_msg(3);} break;
        case PS2_F5_ALT : if (number_of_memories > 4) {repeat_memory_msg(4);} break;
        case PS2_F6_ALT : if (number_of_memories > 5) {repeat_memory_msg(5);} break;
        case PS2_F7_ALT : if (number_of_memories > 6) {repeat_memory_msg(6);} break;
        case PS2_F8_ALT : if (number_of_memories > 7) {repeat_memory_msg(7);} break;
        case PS2_F9_ALT : if (number_of_memories > 8) {repeat_memory_msg(8);} break;
        case PS2_F10_ALT : if (number_of_memories > 9) {repeat_memory_msg(9);} break;
        case PS2_F11_ALT : if (number_of_memories > 10) {repeat_memory_msg(10);} break;
        case PS2_F12_ALT : if (number_of_memories > 11) {repeat_memory_msg(11);} break;
        #endif

        case PS2_DELETE : if (send_buffer_bytes > 0) { send_buffer_bytes--; } break;
        case PS2_ESC :  // clear the serial send buffer and a bunch of other stuff
          if (manual_ptt_invoke) {
            manual_ptt_invoke = 0;
            ptt_unkey();
          }
          if (keyboard_tune_on) {
            tx_and_sidetone_key(0,MANUAL_SENDING);
            keyboard_tune_on = 0;
          }
          if (pause_sending_buffer) {
            pause_sending_buffer = 0;
          }
          clear_send_buffer();
          #ifdef FEATURE_MEMORIES
          //clear_memory_button_buffer();
          play_memory_prempt = 1;
          repeat_memory = 255;
          #endif
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Abort", 0, default_display_msg_delay);
          #endif          
          break;

        #ifdef FEATURE_MEMORIES
        case PS2_F1_SHIFT  :
          ps2_keyboard_program_memory(0);
          break;

        case PS2_F2_SHIFT  :
          ps2_keyboard_program_memory(1);
          break;

        case PS2_F3_SHIFT  :
          ps2_keyboard_program_memory(2);
          break;

        case PS2_F4_SHIFT  :
          ps2_keyboard_program_memory(3);
          break;

        case PS2_F5_SHIFT  :
          ps2_keyboard_program_memory(4);
          break;

        case PS2_F6_SHIFT  :
          ps2_keyboard_program_memory(5);
          break;

        case PS2_F7_SHIFT  :
          ps2_keyboard_program_memory(6);
          break;

        case PS2_F8_SHIFT  :
          ps2_keyboard_program_memory(7);
          break;

        case PS2_F9_SHIFT  :
          ps2_keyboard_program_memory(8);
          break;

        case PS2_F10_SHIFT  :
          ps2_keyboard_program_memory(9);
          break;

        case PS2_F11_SHIFT  :
          ps2_keyboard_program_memory(10);
          break;

        case PS2_F12_SHIFT  :
          ps2_keyboard_program_memory(11);
          break;
        #endif //FEATURE_MEMORIES

        case PS2_INSERT :   // send serial number and increment
          put_serial_number_in_send_buffer();
          serial_number++;
          break;

        case PS2_END :      // send serial number no increment
          put_serial_number_in_send_buffer();
          break;

        case PS2_BACKSPACE_SHIFT :    // decrement serial number
          serial_number--;
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Serial: " + String(serial_number), 0, default_display_msg_delay);
          #endif          
          break;

        case PS2_LEFT_ALT :
          #ifdef DEBUG_PS2_KEYBOARD
          debug_serial_port->println("PS2_LEFT_ALT\n");
          #endif
          break;

        case PS2_A_CTRL :
          configuration.keyer_mode = IAMBIC_A;
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Iambic A", 0, default_display_msg_delay);
          #endif

          config_dirty = 1;
          break;

        case PS2_B_CTRL :
          configuration.keyer_mode = IAMBIC_B;
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Iambic B", 0, default_display_msg_delay);
          #endif          
          config_dirty = 1;
          break;

        case PS2_D_CTRL :
          configuration.keyer_mode = ULTIMATIC;
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Ultimatic", 0, default_display_msg_delay);
          #endif        
          config_dirty = 1;
          break;

        case PS2_E_CTRL :
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Enter Serial #", 0, default_display_msg_delay);
          #else        
          boop_beep();
          #endif
          work_int = ps2_keyboard_get_number_input(4,0,10000);
          if (work_int > 0) {
            serial_number = work_int;
            #ifdef FEATURE_DISPLAY
            lcd_status = LCD_REVERT;
            #else             
            beep();
            #endif
          }
          break;

        case PS2_G_CTRL :
          configuration.keyer_mode = BUG;
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Bug", 0, default_display_msg_delay);
          #endif
          config_dirty = 1;
          break;

        case PS2_H_CTRL :
          #ifdef FEATURE_HELL
          if (char_send_mode == CW) {
            char_send_mode = HELL;
            beep();
          } else {
            char_send_mode = CW;
            beep();
          }
          #endif //FEATURE_HELL
          break;

        case PS2_I_CTRL :
          if (key_tx) {
            key_tx = 0;
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("TX Off", 0, default_display_msg_delay);
            #endif
            
          } else {
            key_tx = 1;
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("TX On", 0, default_display_msg_delay);
            #endif      
          }
          break;

        case PS2_M_CTRL:
          #ifdef FEATURE_FARNSWORTH
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Farnsworth WPM", 0, default_display_msg_delay);
          #else          
          boop_beep();
          #endif
          work_int = ps2_keyboard_get_number_input(3,-1,1000);
          if (work_int > -1) {
            configuration.wpm_farnsworth = work_int;
            #ifdef FEATURE_DISPLAY
            lcd_status = LCD_REVERT;
            #else
            beep();
            #endif
            config_dirty = 1;
          }
          #endif
          break;

        case PS2_N_CTRL :
          if (configuration.paddle_mode == PADDLE_NORMAL) {
            configuration.paddle_mode = PADDLE_REVERSE;
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Paddle Reverse", 0, default_display_msg_delay);
            #endif
          } else {
            configuration.paddle_mode = PADDLE_NORMAL;
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Paddle Normal", 0, default_display_msg_delay);
            #endif      
          }
          config_dirty = 1;
          break;

        case PS2_O_CTRL :
          if ((configuration.sidetone_mode == SIDETONE_ON) || (configuration.sidetone_mode == SIDETONE_PADDLE_ONLY)){
            configuration.sidetone_mode = SIDETONE_OFF;
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Sidetone Off", 0, default_display_msg_delay);
            #endif      
          } else {
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Sidetone On", 0, default_display_msg_delay);
            #endif      
            configuration.sidetone_mode = SIDETONE_ON;
          }
          config_dirty = 1;
         break;

        case PS2_T_CTRL :
          #ifdef FEATURE_MEMORIES
          repeat_memory = 255;
          #endif
          if (keyboard_tune_on) {
            tx_and_sidetone_key(0,MANUAL_SENDING);
            keyboard_tune_on = 0;
            #ifdef FEATURE_DISPLAY
            lcd_status = LCD_REVERT;
            #endif // FEATURE_DISPLAY
          } else {
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Tune", 0, default_display_msg_delay);
            #endif      
            tx_and_sidetone_key(1,MANUAL_SENDING);
            keyboard_tune_on = 1;
          }
          break;

        case PS2_U_CTRL :
          if (ptt_line_activated) {
            manual_ptt_invoke = 0;
            ptt_unkey();
            #ifdef FEATURE_DISPLAY
            lcd_status = LCD_REVERT;
            #endif // FEATURE_DISPLAY            
          } else {
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("PTT Invoke", 0, default_display_msg_delay);
            #endif      
            manual_ptt_invoke = 1;
            ptt_key();
          }
          break;

        case PS2_W_CTRL :
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("WPM Adjust", 0, default_display_msg_delay);
          #else
          boop_beep();
          #endif
          work_int = ps2_keyboard_get_number_input(3,0,1000);
          if (work_int > 0) {
            speed_set(work_int);
            #ifdef FEATURE_DISPLAY
            lcd_status = LCD_REVERT;
            #else
            beep();
            #endif
            config_dirty = 1;
          }
          break;

        case PS2_F1_CTRL :
          //current_ptt_line = ptt_tx_1;
          //current_tx_key_line = tx_key_line_1;
          switch_to_tx_silent(1);
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("TX 1", 0, default_display_msg_delay);
          #endif          
          break;

        case PS2_F2_CTRL :
          if ((ptt_tx_2) || (tx_key_line_2)) {
            switch_to_tx_silent(2);
            //current_ptt_line = ptt_tx_2;
            //current_tx_key_line = tx_key_line_2;           
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("TX 2", 0, default_display_msg_delay);
            #endif                      
          }
          break;

        case PS2_F3_CTRL :
          if ((ptt_tx_3)  || (tx_key_line_3)) {
            switch_to_tx_silent(3);
            //current_ptt_line = ptt_tx_3;
            //current_tx_key_line = tx_key_line_3;                       
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("TX 3", 0, default_display_msg_delay);
            #endif                                  
          }
          break;

        case PS2_F4_CTRL :
          if ((ptt_tx_4)  || (tx_key_line_4)) {
            switch_to_tx_silent(4);
            //current_ptt_line = ptt_tx_4;
            //current_tx_key_line = tx_key_line_4;     
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("TX 4", 0, default_display_msg_delay);
            #endif                                  
          }
          break;

        case PS2_F5_CTRL :
          if ((ptt_tx_5)  || (tx_key_line_5)) {
            switch_to_tx_silent(5);
            //current_ptt_line = ptt_tx_5;
            //current_tx_key_line = tx_key_line_5;  
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("TX 5", 0, default_display_msg_delay);
            #endif                      
          }
          break;

        case PS2_F6_CTRL :
          if ((ptt_tx_6)  || (tx_key_line_6)) {
            switch_to_tx_silent(6);
            //current_ptt_line = ptt_tx_6;
            //current_tx_key_line = tx_key_line_6; 
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("TX 6", 0, default_display_msg_delay);
            #endif                                  
          }
          break;

        #ifdef FEATURE_AUTOSPACE
        case PS2_Z_CTRL:
          if (configuration.autospace_active) {
            configuration.autospace_active = 0;
            config_dirty = 1;
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Autospace Off", 0, default_display_msg_delay);
            #endif                                  
          } else {
            configuration.autospace_active = 1;
            config_dirty = 1;
            #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Autospace On", 0, default_display_msg_delay);
            #endif                                  
          }
          break;
        #endif

        default :
          if ((keystroke > 31) && (keystroke < 255 /*123*/)) {
            if (ps2_prosign_flag) {
              add_to_send_buffer(SERIAL_SEND_BUFFER_PROSIGN);
              ps2_prosign_flag = 0;
            }
            keystroke = uppercase(keystroke);
            add_to_send_buffer(keystroke);
            #ifdef FEATURE_MEMORIES
            repeat_memory = 255;
            #endif
          }
          break;
      }
    } else {

    }
  } //while (keyboard.available())
  #endif //FEATURE_MEMORIES
}
#endif //FEATURE_PS2_KEYBOARD

//-------------------------------------------------------------------------------------------------------
#if (defined(FEATURE_PS2_KEYBOARD) || defined(FEATURE_USB_KEYBOARD)) && defined(FEATURE_MEMORIES)
void ps2_usb_keyboard_play_memory(byte memory_number){

  if (memory_number < number_of_memories) {
    add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
    add_to_send_buffer(memory_number);
    #ifdef FEATURE_MEMORIES
    repeat_memory = 255;
    #endif //FEATURE_MEMORIES
  }
}
#endif  //defined(FEATURE_PS2_KEYBOARD) || defined(FEATURE_USB_KEYBOARD)
//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_PS2_KEYBOARD) && defined(FEATURE_MEMORIES)
void ps2_keyboard_program_memory(byte memory_number)
{

  char keystroke;
  byte looping = 1;
  byte error = 0;
  int temp_memory_index = 0;
  byte temp_memory[(memory_end(memory_number)-memory_start(memory_number) + 1)];
  int x;
  String keyboard_string;
  String lcd_string = "Program Memory";

  if (memory_number > (number_of_memories - 1)) {
    boop();
    return;
  }
  
  #ifdef FEATURE_DISPLAY
  if (memory_number < 9) {
    lcd_string.concat(' ');
  }
  lcd_string.concat(memory_number+1);
  lcd_center_print_timed(lcd_string, 0, default_display_msg_delay);
  #else
  boop_beep();
  #endif
  repeat_memory = 255;
  while (looping) {
    while (keyboard.available() == 0) {
      if (keyer_machine_mode == KEYER_NORMAL) {          // might as well do something while we're waiting
        check_paddles();
        service_dit_dah_buffers();
      }
    }
    keystroke = keyboard.read();
    #ifdef DEBUG_PS2_KEYBOARD
    debug_serial_port->println(keystroke,DEC);
    #endif
    if (keystroke == 13) {        // did we get a carriage return?
      looping = 0;
    } else {
      if (keystroke == PS2_BACKSPACE) {
        if (temp_memory_index) {
          temp_memory_index--;
          #ifdef FEATURE_DISPLAY
          keyboard_string = keyboard_string.substring(0,keyboard_string.length()-1);
          lcd_center_print_timed(keyboard_string, 1, default_display_msg_delay);
          #endif            
        }
      } else {
        if (keystroke == PS2_ESC) {
          looping = 0;
          error = 1;
        } else {
          keystroke = uppercase(keystroke);
          #ifdef FEATURE_DISPLAY
          keyboard_string.concat(char(keystroke));
          if (keyboard_string.length() > LCD_COLUMNS) {
            lcd_center_print_timed(keyboard_string.substring((keyboard_string.length()-LCD_COLUMNS)), 1, default_display_msg_delay);
          } else {         
            lcd_center_print_timed(keyboard_string, 1, default_display_msg_delay);
          }
          #endif
          temp_memory[temp_memory_index] = keystroke;
          temp_memory_index++;
          if (temp_memory_index > (memory_end(memory_number)-memory_start(memory_number))) {
            looping = 0;
          }
        }
      }
    }
  }  //while (looping)

  if (error) {
    #ifdef FEATURE_DISPLAY
    lcd_status = LCD_REVERT;
    #else
    boop();
    #endif
  } else {
    for (x = 0;x < temp_memory_index;x++) {  // write to memory
      EEPROM.write((memory_start(memory_number)+x),temp_memory[x]);
      if ((memory_start(memory_number) + x) == memory_end(memory_number)) {    // are we at last memory location?
        x = temp_memory_index;
      }
    }
    // write terminating 255
    EEPROM.write((memory_start(memory_number)+x),255);
    #ifdef FEATURE_DISPLAY
    lcd_center_print_timed("Done", 0, default_display_msg_delay);
    #else    
    beep();
    #endif
  }
}
#endif

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_PS2_KEYBOARD

int ps2_keyboard_get_number_input(byte places,int lower_limit, int upper_limit)
{

  byte looping = 1;
  byte error = 0;
  byte numberindex = 0;
  int numbers[6];
  char keystroke;
  String keyboard_string;

  #ifdef FEATURE_MEMORIES
  repeat_memory = 255;
  #endif

  while (looping) {
    if (keyboard.available() == 0) {        // wait for the next keystroke
      if (keyer_machine_mode == KEYER_NORMAL) {          // might as well do something while we're waiting
        check_paddles();
        service_dit_dah_buffers();
        service_send_buffer(PRINTCHAR);

        check_ptt_tail();
        #ifdef FEATURE_POTENTIOMETER
        if (configuration.pot_activated) {
          check_potentiometer();
        }
        #endif
        #ifdef FEATURE_ROTARY_ENCODER
        check_rotary_encoder();
        #endif //FEATURE_ROTARY_ENCODER
      }
    } else {
      keystroke = keyboard.read();
      if ((keystroke > 47) && (keystroke < 58)) {    // ascii 48-57 = "0" - "9")
        numbers[numberindex] = keystroke;
        numberindex++;
        #ifdef FEATURE_DISPLAY
        keyboard_string.concat(String(keystroke-48));
        lcd_center_print_timed(keyboard_string, 1, default_display_msg_delay);
        #endif                     
        if (numberindex > places){
            looping = 0;
            error = 1;
        }
      } else {
        if (keystroke == PS2_BACKSPACE) {
          if (numberindex) {
            numberindex--;
            #ifdef FEATURE_DISPLAY
            keyboard_string = keyboard_string.substring(0,keyboard_string.length()-1);
            lcd_center_print_timed(keyboard_string, 1, default_display_msg_delay);
            #endif             
          }
        } else {
          if (keystroke == PS2_ENTER) {   // carriage return - get out
            looping = 0;
          } else {                 // bogus input - error out
            looping = 0;
            error = 1;
          }
        }
      }
    }
  }
  if (error) {
    boop();
    return(-1);
  } else {
    int y = 1;
    int return_number = 0;
    for (int x = (numberindex - 1); x >= 0 ; x = x - 1) {
      return_number = return_number + ((numbers[x]-48) * y);
      y = y * 10;
    }
    if ((return_number > lower_limit) && (return_number < upper_limit)) {
      return(return_number);
    } else {
      boop();
      return(-1);
    }
  }
}
#endif

//-------------------------------------------------------------------------------------------------------
#if (defined(FEATURE_PS2_KEYBOARD) || defined(FEATURE_USB_KEYBOARD)) && !defined(OPTION_SAVE_MEMORY_NANOKEYER)
void put_serial_number_in_send_buffer()
{

  String serial_number_string;

  #ifdef FEATURE_MEMORIES
  repeat_memory = 255;
  #endif

  serial_number_string = String(serial_number, DEC);
  if ((serial_number_string.length() < 3 ) && (serial_leading_zeros)) {
    if (serial_cut_numbers) {
      add_to_send_buffer('T');
    } else {
      add_to_send_buffer('0');
    }
  }
  if ((serial_number_string.length() == 1) && (serial_leading_zeros)) {
    if (serial_cut_numbers) {
      add_to_send_buffer('T');
    } else {
      add_to_send_buffer('0');
    }
  }
  for (byte a = 0; a < serial_number_string.length(); a++)  {
    if ((serial_number_string[a] == '0') && (serial_cut_numbers)) {
      add_to_send_buffer('T');
    } else {
     if ((serial_number_string[a] == '9')  && (serial_cut_numbers)) {
       add_to_send_buffer('N');
     } else {
       add_to_send_buffer(serial_number_string[a]);
     }
    }
  }
}
#endif //defined(FEATURE_PS2_KEYBOARD) || defined(FEATURE_USB_KEYBOARD)

//-------------------------------------------------------------------------------------------------------

#ifdef DEBUG_CAPTURE_COM_PORT
void debug_capture ()
{

  byte serial_byte_in;
  int x = 1022;

  while (primary_serial_port->available() == 0) {}  // wait for first byte
  serial_byte_in = primary_serial_port->read();
  primary_serial_port->write(serial_byte_in);
  //if ((serial_byte_in > 47) or (serial_byte_in = 20)) { primary_serial_port->write(serial_byte_in); }  // echo back
  if (serial_byte_in == '~') {
    debug_capture_dump();    // go into dump mode if we get a tilde
  } else {
    EEPROM.write(x,serial_byte_in);
    x--;
    while ( x > 400) {
      if (primary_serial_port->available() > 0) {
        serial_byte_in = primary_serial_port->read();
        EEPROM.write(x,serial_byte_in);
        EEPROM.write(x-1,255);
        send_dit(AUTOMATIC_SENDING);
        x--;
        primary_serial_port->write(serial_byte_in);
        //if ((serial_byte_in > 47) or (serial_byte_in = 20)) { primary_serial_port->write(serial_byte_in); }  // echo back
      }
    }
  }

  while (1) {}

}
#endif

//-------------------------------------------------------------------------------------------------------

#ifdef DEBUG_CAPTURE_COM_PORT
void debug_capture_dump()
{
  byte eeprom_byte_in;

  for ( int x = 1022; x > (1022-100); x-- ) {
    eeprom_byte_in = EEPROM.read(x);
    if (eeprom_byte_in < 255) {
      primary_serial_port->print(eeprom_byte_in,BYTE);
    } else {
      x = 0;
    }
  }
  primary_serial_port->println("\n");
  for ( int x = 1022; x > (1022-100); x-- ) {
    eeprom_byte_in = EEPROM.read(x);
    if (eeprom_byte_in < 255) {
      primary_serial_port->print(eeprom_byte_in,HEX);
      primary_serial_port->write("   :");
      primary_serial_port->println(eeprom_byte_in,BYTE);
    } else {
      x = 0;
    }
  }

  while (1) {}

}
#endif

//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_ROTARY_ENCODER
void check_rotary_encoder(){

  static unsigned long timestamp[5];

  unsigned char pinstate = (digitalRead(rotary_pin2) << 1) | digitalRead(rotary_pin1);
  state = ttable[state & 0xf][pinstate];
  unsigned char result = (state & 0x30);
      
  if (result) {                                    // If rotary encoder modified  
    timestamp[0] = timestamp[1];                    // Encoder step timer
    timestamp[1] = timestamp[2]; 
    timestamp[2] = timestamp[3]; 
    timestamp[3] = timestamp[4]; 
    timestamp[4] = millis();
    
    unsigned long elapsed_time = (timestamp[4] - timestamp[0]); // Encoder step time difference for 10's step
 
    if (result == DIR_CW) {                      
      if (elapsed_time < 250) {speed_change(2);} else {speed_change(1);};
    }
    if (result == DIR_CCW) {                      
      if (elapsed_time < 250) {speed_change(-2);} else {speed_change(-1);};
    }
    
  } // if (result)

  
  
}
#endif //FEATURE_ROTARY_ENCODER
//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_POTENTIOMETER
void check_potentiometer()
{
  #ifdef DEBUG_LOOP
  debug_serial_port->println(F("loop: entering check_potentiometer")); 
  #endif
    
  if (configuration.pot_activated || potentiometer_always_on) {
    byte pot_value_wpm_read = pot_value_wpm();
    if ((abs(pot_value_wpm_read - last_pot_wpm_read) > potentiometer_change_threshold)) {
      #ifdef DEBUG_POTENTIOMETER
      debug_serial_port->print(F("check_potentiometer: speed change: "));
      debug_serial_port->print(pot_value_wpm_read);
      debug_serial_port->print(F(" analog read: "));
      debug_serial_port->println(analogRead(potentiometer));
      #endif
      speed_set(pot_value_wpm_read);
      last_pot_wpm_read = pot_value_wpm_read;
      #ifdef FEATURE_WINKEY_EMULATION
      if ((primary_serial_port_mode == SERIAL_WINKEY_EMULATION) && (winkey_host_open)) {
        winkey_port_write(((pot_value_wpm_read-pot_wpm_low_value)|128));
        winkey_last_unbuffered_speed_wpm = configuration.wpm;
      }
      #endif
      #ifdef FEATURE_SLEEP
      last_activity_time = millis(); 
      #endif //FEATURE_SLEEP
    }
  }
}

#endif
//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_POTENTIOMETER
byte pot_value_wpm()
{
  int pot_read = analogRead(potentiometer);
  byte return_value = map(pot_read, 0, pot_full_scale_reading, pot_wpm_low_value, pot_wpm_high_value);
  return return_value;

}

#endif

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_HELL
void hell_test ()
{
  for (byte h = 65; h < 91; h++) {
    transmit_hell_char(h);
  }
  transmit_hell_char('0');
  transmit_hell_char('1');
  transmit_hell_char('2');
  transmit_hell_char('3');
  transmit_hell_char('4');
  transmit_hell_char('5');
  transmit_hell_char('6');
  transmit_hell_char('7');
  transmit_hell_char('8');
  transmit_hell_char('9');
  transmit_hell_char('+');
  transmit_hell_char('-');
  transmit_hell_char('?');
  transmit_hell_char('/');
  transmit_hell_char('.');
  transmit_hell_char(',');
//  transmit_hell_char('‘');  // this causes compiler warning; unicode character or something?
  transmit_hell_char('=');
  transmit_hell_char(')');
  transmit_hell_char('(');
  transmit_hell_char(':');
}
#endif

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_HELL
void transmit_hell_char (byte hellchar)
{

  // blank column
  for (byte w = 0; w < 14; w++) {
    transmit_hell_pixel(0);
  }

  if ((hellchar > 64) && (hellchar < 91)) {    // A - Z
    hellchar = ((hellchar - 65) * 9);
    transmit_hell_pixels(hell_font1, hellchar);
  } else {
    if ((hellchar > 47) && (hellchar < 58)) {  // 0 - 9
      hellchar = ((hellchar - 48) * 9);
      transmit_hell_pixels(hell_font2, hellchar);
    } else {
      switch (hellchar) {
        case '+': hellchar = 0; break;
        case '-': hellchar = 1; break;
        case '?': hellchar = 2; break;
        case '/': hellchar = 3; break;
        case '.': hellchar = 4; break;
        case ',': hellchar = 5; break;
//        case '‘': hellchar = 6; break;  // this causes compiler warning; unicode character or something?
        case '=': hellchar = 7; break;
        case ')': hellchar = 8; break;
        case '(': hellchar = 9; break;
        case ':': hellchar = 10; break;
        default : hellchar = 11; break;
      }
      hellchar = hellchar * 9;
      transmit_hell_pixels(hell_font3, hellchar);

    }
  }

  // blank column
  for (byte w = 0; w < 14; w++) {
    transmit_hell_pixel(0);
  }

}
#endif

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_HELL
void transmit_hell_pixels (const char* hell_pixels, byte hellchar)
//void transmit_hell_pixels (prog_uchar* hell_pixels, byte hellchar)
{

  for (byte x = 0; x < 9; x++) {
    for (int y = 7; y > -1; y--) {
      if ((x < 8) || ((x == 8) && (y > 1))) {  // drop the last 2 bits in byte 9
        if (bitRead(pgm_read_byte(hell_pixels + hellchar + x ),y)) {
          transmit_hell_pixel(1);
        } else {
          transmit_hell_pixel(0);
        }
      }
    }
  }

}
#endif

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_HELL
void transmit_hell_pixel (byte hellbit)
{
  if (hellbit) {
    tx_and_sidetone_key(1,AUTOMATIC_SENDING);
  } else {
    tx_and_sidetone_key(0,AUTOMATIC_SENDING);
  }
  delayMicroseconds(hell_pixel_microseconds);
}
#endif

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_MEMORIES
void put_memory_button_in_buffer(byte memory_number_to_put_in_buffer)
{

  if (memory_number_to_put_in_buffer < number_of_memories) {
    #ifdef DEBUG_MEMORIES
    debug_serial_port->print(F("put_memory_button_in_buffer: memory_number_to_put_in_buffer:"));
    debug_serial_port->println(memory_number_to_put_in_buffer,DEC);
    #endif
    repeat_memory = 255;
    if ((millis() - last_memory_button_buffer_insert) > 400) {    // don't do another buffer insert if we just did one - button debounce
      #ifdef FEATURE_WINKEY_EMULATION
      if (winkey_sending && winkey_host_open) {
        winkey_port_write(0xc0|winkey_sending|winkey_xoff);
        winkey_interrupted = 1;
      }
      #endif

      add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
      add_to_send_buffer(memory_number_to_put_in_buffer);
      last_memory_button_buffer_insert = millis();
    }
  } else {
    #ifdef DEBUG_MEMORIES
    debug_serial_port->println(F("put_memory_button_in_buffer: bad memory_number_to_put_in_buffer"));
    #endif
  }
}
#endif

//-------------------------------------------------------------------------------------------------------

void check_paddles()
{
  
  #ifdef DEBUG_LOOP
    debug_serial_port->println(F("loop: entering check_paddles"));
  #endif  

  #define NO_CLOSURE 0
  #define DIT_CLOSURE_DAH_OFF 1
  #define DAH_CLOSURE_DIT_OFF 2
  #define DIT_CLOSURE_DAH_ON 3
  #define DAH_CLOSURE_DIT_ON 4

  static byte last_closure = NO_CLOSURE;

  check_dit_paddle();
  check_dah_paddle();

  #ifdef FEATURE_WINKEY_EMULATION
    if (winkey_dit_invoke) {
      dit_buffer = 1;
    }
    if (winkey_dah_invoke) {
      dah_buffer = 1;
    }
  #endif //FEATURE_WINKEY_EMULATION

  if (configuration.keyer_mode == ULTIMATIC) {
    if (ultimatic_mode == ULTIMATIC_NORMAL) {
      switch (last_closure) {
        case DIT_CLOSURE_DAH_OFF:
          if (dah_buffer) {
            if (dit_buffer) {
              last_closure = DAH_CLOSURE_DIT_ON;
              dit_buffer = 0;
            } else {
              last_closure = DAH_CLOSURE_DIT_OFF;
            }
          } else {
            if (!dit_buffer) {
              last_closure = NO_CLOSURE;
            }
          }
          break;
        case DIT_CLOSURE_DAH_ON:
          if (dit_buffer) {
            if (dah_buffer) {
              dah_buffer = 0;
            } else {
              last_closure = DIT_CLOSURE_DAH_OFF;
            }
          } else {
            if (dah_buffer) {
              last_closure = DAH_CLOSURE_DIT_OFF;
            } else {
              last_closure = NO_CLOSURE;
            }
          }
          break;

        case DAH_CLOSURE_DIT_OFF:
          if (dit_buffer) {
            if (dah_buffer) {
              last_closure = DIT_CLOSURE_DAH_ON;
              dah_buffer = 0;
            } else {
              last_closure = DIT_CLOSURE_DAH_OFF;
            }
          } else {
            if (!dah_buffer) {
              last_closure = NO_CLOSURE;
            }
          }
          break;

        case DAH_CLOSURE_DIT_ON:
          if (dah_buffer) {
            if (dit_buffer) {
              dit_buffer = 0;
            } else {
              last_closure = DAH_CLOSURE_DIT_OFF;
            }
          } else {
            if (dit_buffer) {
              last_closure = DIT_CLOSURE_DAH_OFF;
            } else {
              last_closure = NO_CLOSURE;
            }
          }
          break;

        case NO_CLOSURE:
          if ((dit_buffer) && (!dah_buffer)) {
            last_closure = DIT_CLOSURE_DAH_OFF;
          } else {
            if ((dah_buffer) && (!dit_buffer)) {
              last_closure = DAH_CLOSURE_DIT_OFF;
            } else {
              if ((dit_buffer) && (dah_buffer)) {
                // need to handle dit/dah priority here
                last_closure = DIT_CLOSURE_DAH_ON;
                dah_buffer = 0;
              }
            }
          }
          break;
      }
    } else {
     if ((dit_buffer) && (dah_buffer)) {   // dit or dah priority mode
       if (ultimatic_mode == ULTIMATIC_DIT_PRIORITY) {
         dah_buffer = 0;
       } else {
         dit_buffer = 0;
       }
     }
    }
  }
}

//-------------------------------------------------------------------------------------------------------

void ptt_key()
{
  if (ptt_line_activated == 0) {   // if PTT is currently deactivated, bring it up and insert PTT lead time delay
    if (configuration.current_ptt_line) {
      digitalWrite (configuration.current_ptt_line, HIGH);    
      #if defined(OPTION_WINKEY_2_SUPPORT) && defined(FEATURE_WINKEY_EMULATION)
      if ((wk2_both_tx_activated) && (ptt_tx_2)) {
        digitalWrite (ptt_tx_2, HIGH);
      }
      #endif
      delay(ptt_lead_time[configuration.current_tx-1]);
    }
    ptt_line_activated = 1;
  }
  ptt_time = millis();
}

//-------------------------------------------------------------------------------------------------------
void ptt_unkey()
{
  if (ptt_line_activated) {
    if (configuration.current_ptt_line) {
      digitalWrite (configuration.current_ptt_line, LOW);
      #if defined(OPTION_WINKEY_2_SUPPORT) && defined(FEATURE_WINKEY_EMULATION)
      if ((wk2_both_tx_activated) && (ptt_tx_2)) {
        digitalWrite (ptt_tx_2, LOW);
      }
      #endif

    }
    ptt_line_activated = 0;
  }
}

//-------------------------------------------------------------------------------------------------------
void check_ptt_tail()
{
  #ifdef DEBUG_LOOP
  debug_serial_port->println(F("loop: entering check_ptt_tail"));
  #endif
    
  if (key_state) {
    ptt_time = millis();
  } else {
    if ((ptt_line_activated) && (manual_ptt_invoke == 0)) {
      //if ((millis() - ptt_time) > ptt_tail_time) {
      if (last_sending_type == MANUAL_SENDING) {
        #ifndef OPTION_INCLUDE_PTT_TAIL_FOR_MANUAL_SENDING
        if ((millis() - ptt_time) >= ((configuration.length_wordspace*ptt_hang_time_wordspace_units)*float(1200/configuration.wpm)) ) {
          ptt_unkey();
        }          
        #else //ndef OPTION_INCLUDE_PTT_TAIL_FOR_MANUAL_SENDING
        #ifndef OPTION_EXCLUDE_PTT_HANG_TIME_FOR_MANUAL_SENDING
        if ((millis() - ptt_time) >= (((configuration.length_wordspace*ptt_hang_time_wordspace_units)*float(1200/configuration.wpm))+ptt_tail_time[configuration.current_tx-1])) {       
          ptt_unkey();
        }
        #else //OPTION_EXCLUDE_PTT_HANG_TIME_FOR_MANUAL_SENDING
        if ((millis() - ptt_time) >= ptt_tail_time[configuration.current_tx-1]) {       
          ptt_unkey();
        }
        #endif //OPTION_EXCLUDE_PTT_HANG_TIME_FOR_MANUAL_SENDING
        #endif //ndef OPTION_INCLUDE_PTT_TAIL_FOR_MANUAL_SENDING
      } else {
        if ((millis() - ptt_time) > ptt_tail_time[configuration.current_tx-1]) {
          #ifdef OPTION_KEEP_PTT_KEYED_WHEN_CHARS_BUFFERED
          if (!send_buffer_bytes){
            ptt_unkey();
          }
          #else
          ptt_unkey();
          #endif //OPTION_KEEP_PTT_KEYED_WHEN_CHARS_BUFFERED
        }
      }
    }
  }
}

//-------------------------------------------------------------------------------------------------------
void write_settings_to_eeprom(int initialize_eeprom) {  
 
  #if !defined(HARDWARE_ARDUINO_DUE) || (defined(HARDWARE_ARDUINO_DUE) && defined(FEATURE_EEPROM_E24C1024))
  
  if (initialize_eeprom) {
    //configuration.magic_number = eeprom_magic_number;
    EEPROM.write(0,eeprom_magic_number);
    #ifdef FEATURE_MEMORIES
    initialize_eeprom_memories();
    #endif  //FEATURE_MEMORIES    
  }

  const byte* p = (const byte*)(const void*)&configuration;
  unsigned int i;
  int ee = 1;  // starting point of configuration struct
  for (i = 0; i < sizeof(configuration); i++){
    EEPROM.write(ee++, *p++);  
  }
  
  #endif //!defined(HARDWARE_ARDUINO_DUE) || (defined(HARDWARE_ARDUINO_DUE) && defined(FEATURE_EEPROM_E24C1024))
  
  config_dirty = 0;
  
  
}

//-------------------------------------------------------------------------------------------------------

int read_settings_from_eeprom() {

  // returns 0 if eeprom had valid settings, returns 1 if eeprom needs initialized
  
  #if !defined(HARDWARE_ARDUINO_DUE) || (defined(HARDWARE_ARDUINO_DUE) && defined(FEATURE_EEPROM_E24C1024))

    if (EEPROM.read(0) == eeprom_magic_number){
    
      byte* p = (byte*)(void*)&configuration;
      unsigned int i;
      int ee = 1; // starting point of configuration struct
      for (i = 0; i < sizeof(configuration); i++){
        *p++ = EEPROM.read(ee++);  
      }
    
    //if (configuration.magic_number == eeprom_magic_number) {
      switch_to_tx_silent(configuration.current_tx);
      config_dirty = 0;

      #if defined(OPTION_DIT_DAH_BUFFERS_OFF_BY_DEFAULT_FOR_FEATURE_DIT_DAH_BUFFER_CONTROL) && defined(FEATURE_DIT_DAH_BUFFER_CONTROL)
        configuration.dit_buffer_off = 1;
        configuration.dah_buffer_off = 1;
      #endif //defined(OPTION_DIT_DAH_BUFFERS_OFF_BY_DEFAULT_FOR_FEATURE_DIT_DAH_BUFFER_CONTROL) && defined(FEATURE_DIT_DAH_BUFFER_CONTROL)

      return 0;
    } else {
      return 1;
    }
  
  #endif //!defined(HARDWARE_ARDUINO_DUE) || (defined(HARDWARE_ARDUINO_DUE) && defined(FEATURE_EEPROM_E24C1024))


 
  return 1;

}

//-------------------------------------------------------------------------------------------------------

void check_dit_paddle()
{
  byte pin_value = 0;
  byte dit_paddle = 0;
  #ifdef OPTION_DIT_PADDLE_NO_SEND_ON_MEM_RPT
    static byte memory_rpt_interrupt_flag = 0;
  #endif

  if (configuration.paddle_mode == PADDLE_NORMAL) {
    dit_paddle = paddle_left;
  } else {
    dit_paddle = paddle_right;
  }


  pin_value = paddle_pin_read(dit_paddle);

  
  #if defined(FEATURE_USB_MOUSE) || defined(FEATURE_USB_KEYBOARD)
    if (usb_dit) {pin_value = 0;}
  #endif   
  
  #ifdef OPTION_DIT_PADDLE_NO_SEND_ON_MEM_RPT
    if (pin_value && memory_rpt_interrupt_flag) {
      memory_rpt_interrupt_flag = 0;
      loop_element_lengths(3,0,configuration.wpm,MANUAL_SENDING);
      dit_buffer = 0;
    }
  #endif
  
  #ifdef OPTION_DIT_PADDLE_NO_SEND_ON_MEM_RPT
    if ((pin_value == 0) && (memory_rpt_interrupt_flag == 0)) {
  #else
    if (pin_value == 0) {
  #endif
    #ifdef FEATURE_DEAD_OP_WATCHDOG
      if (dit_buffer == 0) {
        dit_counter++;
        dah_counter = 0;
      }
    #endif
    dit_buffer = 1;

    #if defined(OPTION_WINKEY_SEND_BREAKIN_STATUS_BYTE) && defined(FEATURE_WINKEY_EMULATION)
      if (!winkey_interrupted && winkey_host_open && !winkey_breakin_status_byte_inhibit){
        winkey_port_write(0xc2|winkey_sending|winkey_xoff); // 0xc2 - BREAKIN bit set high
        winkey_interrupted = 1;
        // tone(sidetone_line,1000);
        // delay(500);
        // noTone(sidetone_line);
        dit_buffer = 0;
      }   
    #endif //defined(OPTION_WINKEY_SEND_BREAKIN_STATUS_BYTE) && defined(FEATURE_WINKEY_EMULATION) 


    #ifdef FEATURE_SLEEP
      last_activity_time = millis(); 
    #endif //FEATURE_SLEEP
    manual_ptt_invoke = 0;
    #ifdef FEATURE_MEMORIES
      if (repeat_memory < 255) {
        repeat_memory = 255;
        clear_send_buffer();
        #ifdef OPTION_DIT_PADDLE_NO_SEND_ON_MEM_RPT
          dit_buffer = 0;
          while (!paddle_pin_read(dit_paddle)) {};
          memory_rpt_interrupt_flag = 1;
        #endif
      }
    #endif
  }





}

//-------------------------------------------------------------------------------------------------------

void check_dah_paddle()
{
  byte pin_value = 0;
  byte dah_paddle;

  if (configuration.paddle_mode == PADDLE_NORMAL) {
    dah_paddle = paddle_right;
  } else {
    dah_paddle = paddle_left;
  }


  pin_value = paddle_pin_read(dah_paddle);

  
  #if defined(FEATURE_USB_MOUSE) || defined(FEATURE_USB_KEYBOARD)
  if (usb_dah) {pin_value = 0;}
  #endif 
  
  if (pin_value == 0) {
    #ifdef FEATURE_DEAD_OP_WATCHDOG
      if (dah_buffer == 0) {
        dah_counter++;
        dit_counter = 0;
      }
    #endif
    dah_buffer = 1;

    #if defined(OPTION_WINKEY_SEND_BREAKIN_STATUS_BYTE) && defined(FEATURE_WINKEY_EMULATION)
      if (!winkey_interrupted && winkey_host_open && !winkey_breakin_status_byte_inhibit){
        winkey_port_write(0xc2|winkey_sending|winkey_xoff); // 0xc2 - BREAKIN bit set high
        winkey_interrupted = 1;
        // tone(sidetone_line,1000);
        // delay(500);
        // noTone(sidetone_line);
        //dah_buffer = 0;
      }   
    #endif //defined(OPTION_WINKEY_SEND_BREAKIN_STATUS_BYTE) && defined(FEATURE_WINKEY_EMULATION) 


    #ifdef FEATURE_SLEEP
      last_activity_time = millis(); 
    #endif //FEATURE_SLEEP    
    #ifdef FEATURE_MEMORIES
      repeat_memory = 255;
    #endif
    manual_ptt_invoke = 0;
  }

}

//-------------------------------------------------------------------------------------------------------

void send_dit(byte sending_type)
{

  // notes: key_compensation is a straight x mS lengthening or shortening of the key down time
  //        weighting is

  unsigned int character_wpm = configuration.wpm;
  #ifdef FEATURE_FARNSWORTH
    if ((sending_type == AUTOMATIC_SENDING) && (configuration.wpm_farnsworth > configuration.wpm)) {
      character_wpm = configuration.wpm_farnsworth;
    }
  #endif //FEATURE_FARNSWORTH

  being_sent = SENDING_DIT;
  tx_and_sidetone_key(1,sending_type);
  #ifdef DEBUG_VARIABLE_DUMP
    dit_start_time = millis();
  #endif
  if ((tx_key_dit) && (key_tx)) {digitalWrite(tx_key_dit,HIGH);}


  #ifdef FEATURE_QLF
    if (qlf_active){
      loop_element_lengths((1.0*(float(configuration.weighting)/50)*(random(qlf_dit_min,qlf_dit_max)/100.0)),keying_compensation,character_wpm,sending_type);
    } else {
      loop_element_lengths((1.0*(float(configuration.weighting)/50)),keying_compensation,character_wpm,sending_type);
    }
  #else //FEATURE_QLF 
    loop_element_lengths((1.0*(float(configuration.weighting)/50)),keying_compensation,character_wpm,sending_type);
  #endif //FEATURE_QLF


  
  if ((tx_key_dit) && (key_tx)) {digitalWrite(tx_key_dit,LOW);}
  #ifdef DEBUG_VARIABLE_DUMP
    dit_end_time = millis();
  #endif
  tx_and_sidetone_key(0,sending_type);


  loop_element_lengths((2.0-(float(configuration.weighting)/50)),(-1.0*keying_compensation),character_wpm,sending_type);

  #ifdef FEATURE_AUTOSPACE

    byte autospace_end_of_character_flag = 0;

    if ((sending_type == MANUAL_SENDING) && (configuration.autospace_active)) {
      check_paddles();
    }
    if ((sending_type == MANUAL_SENDING) && (configuration.autospace_active) && (dit_buffer == 0) && (dah_buffer == 0)) {
      loop_element_lengths(2,0,configuration.wpm,sending_type);
      autospace_end_of_character_flag = 1;
    }
  #endif

  #ifdef FEATURE_WINKEY_EMULATION
    if ((winkey_host_open) && (winkey_paddle_echo_activated) && (sending_type == MANUAL_SENDING)) {
      winkey_paddle_echo_buffer = (winkey_paddle_echo_buffer * 10) + 1;
      winkey_paddle_echo_buffer_decode_time = millis() + (float((cw_echo_timing_factor*1200.0)/configuration.wpm)*length_letterspace);

      #ifdef FEATURE_AUTOSPACE
        if (autospace_end_of_character_flag){winkey_paddle_echo_buffer_decode_time = 0;}
      #endif //FEATURE_AUTOSPACE    
    }
  #endif


  #ifdef FEATURE_PADDLE_ECHO
    if (sending_type == MANUAL_SENDING) {
      paddle_echo_buffer = (paddle_echo_buffer * 10) + 1;
      paddle_echo_buffer_decode_time = millis() + (float((cw_echo_timing_factor*1200.0)/configuration.wpm)*length_letterspace);

      #ifdef FEATURE_AUTOSPACE
        if (autospace_end_of_character_flag){paddle_echo_buffer_decode_time = 0;}
      #endif //FEATURE_AUTOSPACE    
    }
  #endif //FEATURE_PADDLE_ECHO

  #ifdef FEATURE_AUTOSPACE
    autospace_end_of_character_flag = 0;
  #endif //FEATURE_AUTOSPACE

  being_sent = SENDING_NOTHING;
  last_sending_type = sending_type;
  
  check_paddles();

}

//-------------------------------------------------------------------------------------------------------

void send_dah(byte sending_type)
{

  unsigned int character_wpm = configuration.wpm;

  #ifdef FEATURE_FARNSWORTH
    if ((sending_type == AUTOMATIC_SENDING) && (configuration.wpm_farnsworth > configuration.wpm)) {
      character_wpm = configuration.wpm_farnsworth;
    }
  #endif //FEATURE_FARNSWORTH

  being_sent = SENDING_DAH;
  tx_and_sidetone_key(1,sending_type);
  #ifdef DEBUG_VARIABLE_DUMP
    dah_start_time = millis();
  #endif
  if ((tx_key_dah) && (key_tx)) {digitalWrite(tx_key_dah,HIGH);}

  #ifdef FEATURE_QLF
    if (qlf_active){
      loop_element_lengths((float(configuration.dah_to_dit_ratio/100.0)*(float(configuration.weighting)/50)*(random(qlf_dah_min,qlf_dah_max)/100.0)),keying_compensation,character_wpm,sending_type);
    } else {
      loop_element_lengths((float(configuration.dah_to_dit_ratio/100.0)*(float(configuration.weighting)/50)),keying_compensation,character_wpm,sending_type);
    }
  #else //FEATURE_QLF 
    loop_element_lengths((float(configuration.dah_to_dit_ratio/100.0)*(float(configuration.weighting)/50)),keying_compensation,character_wpm,sending_type);
  #endif //FEATURE_QLF 

  if ((tx_key_dah) && (key_tx)) {digitalWrite(tx_key_dah,LOW);}

  #ifdef DEBUG_VARIABLE_DUMP
    dah_end_time = millis();
  #endif

  tx_and_sidetone_key(0,sending_type);

  loop_element_lengths((4.0-(3.0*(float(configuration.weighting)/50))),(-1.0*keying_compensation),character_wpm,sending_type);

  #ifdef FEATURE_AUTOSPACE

    byte autospace_end_of_character_flag = 0;

    if ((sending_type == MANUAL_SENDING) && (configuration.autospace_active)) {
      check_paddles();
    }
    if ((sending_type == MANUAL_SENDING) && (configuration.autospace_active) && (dit_buffer == 0) && (dah_buffer == 0)) {
      loop_element_lengths(2,0,configuration.wpm,sending_type);
      autospace_end_of_character_flag = 1;
    }
  #endif

  #ifdef FEATURE_WINKEY_EMULATION
    if ((winkey_host_open) && (winkey_paddle_echo_activated) && (sending_type == MANUAL_SENDING)) {
      winkey_paddle_echo_buffer = (winkey_paddle_echo_buffer * 10) + 2;
      winkey_paddle_echo_buffer_decode_time = millis() + (float((cw_echo_timing_factor*1200.0)/configuration.wpm)*length_letterspace);

      #ifdef FEATURE_AUTOSPACE
      if (autospace_end_of_character_flag){winkey_paddle_echo_buffer_decode_time = 0;}
      #endif //FEATURE_AUTOSPACE

    }
  #endif
 
  #ifdef FEATURE_PADDLE_ECHO
    if (sending_type == MANUAL_SENDING) {
      paddle_echo_buffer = (paddle_echo_buffer * 10) + 2;
      paddle_echo_buffer_decode_time = millis() + (float((cw_echo_timing_factor*1200.0)/configuration.wpm)*length_letterspace);

      #ifdef FEATURE_AUTOSPACE
      if (autospace_end_of_character_flag){paddle_echo_buffer_decode_time = 0;}
      #endif //FEATURE_AUTOSPACE    
    }
  #endif //FEATURE_PADDLE_ECHO 

  #ifdef FEATURE_AUTOSPACE
    autospace_end_of_character_flag = 0;
  #endif //FEATURE_AUTOSPACE  

//  if ((keyer_mode == IAMBIC_A) && (iambic_flag)) {
//    iambic_flag = 0;
//    //dit_buffer = 0;
//    dah_buffer = 0;
//  }

  check_paddles();

  being_sent = SENDING_NOTHING;
  last_sending_type = sending_type;

}

//-------------------------------------------------------------------------------------------------------

void tx_and_sidetone_key (int state, byte sending_type)
{

  #if defined(FEATURE_COMPETITION_COMPRESSION_DETECTION)

    byte i;

    if ((state == 0) && (key_state) && (compression_detection_key_up_time == 0) && (compression_detection_key_down_time == 0)){
      compression_detection_key_up_time = millis();
      //debug_serial_port->println("UP");
    }  
    if ((state) && (key_state == 0) && (compression_detection_key_up_time > 0) && (compression_detection_key_down_time == 0)) {
      compression_detection_key_down_time = millis();
      //debug_serial_port->println("DOWN");
    }

    unsigned long key_up_to_key_down_time = 0;
  
    if ((compression_detection_key_down_time != 0) && (compression_detection_key_up_time != 0)){  // do we have a measurement waiting for us?
      key_up_to_key_down_time = compression_detection_key_down_time - compression_detection_key_up_time;
      #if defined(DEBUG_FEATURE_COMPETITION_COMPRESSION_DETECTION)
       // debug_serial_port->print("service_competition_compression_detection: key_up_to_key_down_time:");
        //debug_serial_port->println(key_up_to_key_down_time);
      #endif 
      // is the time within the limits of what would be inter-character time?
      if ((key_up_to_key_down_time > ((1200/configuration.wpm)*COMPETITION_COMPRESSION_DETECTION_TIME_INTERCHAR_LOWER_LIMIT)) && (key_up_to_key_down_time < ((1200/configuration.wpm)*COMPETITION_COMPRESSION_DETECTION_TIME_INTERCHAR_UPPER_LIMIT))){
        // add it to the array
        if (time_array_index < COMPETITION_COMPRESSION_DETECTION_ARRAY_SIZE){ 

          #if defined(DEBUG_FEATURE_COMPETITION_COMPRESSION_DETECTION)
            debug_serial_port->print("tx_and_sidetone_key: service_competition_compression_detection: array entry ");
            debug_serial_port->print(time_array_index);
            debug_serial_port->print(":");
            debug_serial_port->println(key_up_to_key_down_time);
          #endif 

          time_array[time_array_index] = key_up_to_key_down_time;
          time_array_index++;

        } else { // if time array is completely filled up, we do a first in, first out
          for(i = 0;i < (COMPETITION_COMPRESSION_DETECTION_ARRAY_SIZE-1);i++){
            time_array[i]=time_array[i+1];
          }
          time_array[COMPETITION_COMPRESSION_DETECTION_ARRAY_SIZE-1] = key_up_to_key_down_time;


          #if defined(DEBUG_FEATURE_COMPETITION_COMPRESSION_DETECTION)
            debug_serial_port->print("tx_and_sidetone_key: service_competition_compression_detection: FIFO array entry ");
            debug_serial_port->print(time_array_index);
            debug_serial_port->print(":");
            debug_serial_port->println(key_up_to_key_down_time);
          #endif 

        }

      } else {
        #if defined(DEBUG_FEATURE_COMPETITION_COMPRESSION_DETECTION)
          //debug_serial_port->print("tx_and_sidetone_key: service_competition_compression_detection: discarded entry: ");
          //debug_serial_port->println(key_up_to_key_down_time);
        #endif         
      }
      compression_detection_key_down_time = 0;
      compression_detection_key_up_time = 0;
    }





  #endif //defined(FEATURE_COMPETITION_COMPRESSION_DETECTION)


  #if !defined(FEATURE_PTT_INTERLOCK)
    if ((state) && (key_state == 0)) {
      if (key_tx) {
        byte previous_ptt_line_activated = ptt_line_activated;
        ptt_key();
        if (current_tx_key_line) {digitalWrite (current_tx_key_line, HIGH);}
        #if defined(OPTION_WINKEY_2_SUPPORT) && defined(FEATURE_WINKEY_EMULATION)
          if ((wk2_both_tx_activated) && (tx_key_line_2)) {
            digitalWrite (tx_key_line_2, HIGH);
          }
        #endif
        if ((first_extension_time) && (previous_ptt_line_activated == 0)) {
          delay(first_extension_time);
        }
      }

      if ((configuration.sidetone_mode == SIDETONE_ON) || (keyer_machine_mode == KEYER_COMMAND_MODE) || ((configuration.sidetone_mode == SIDETONE_PADDLE_ONLY) && (sending_type == MANUAL_SENDING))) {
        tone(sidetone_line, configuration.hz_sidetone);
      }
      key_state = 1;
    } else {
      if ((state == 0) && (key_state)) {
        if (key_tx) {
          if (current_tx_key_line) {digitalWrite (current_tx_key_line, LOW);}
          #if defined(OPTION_WINKEY_2_SUPPORT) && defined(FEATURE_WINKEY_EMULATION)
            if ((wk2_both_tx_activated) && (tx_key_line_2)) {
              digitalWrite (tx_key_line_2, LOW);
            }
          #endif        
          ptt_key();
        }
        if ((configuration.sidetone_mode == SIDETONE_ON) || (keyer_machine_mode == KEYER_COMMAND_MODE) || ((configuration.sidetone_mode == SIDETONE_PADDLE_ONLY) && (sending_type == MANUAL_SENDING))) {
          noTone(sidetone_line);
        }
        key_state = 0;
      }
    }
  #else  //FEATURE_PTT_INTERLOCK
    if ((state) && (key_state == 0)) {
      if (key_tx) {
        byte previous_ptt_line_activated = ptt_line_activated;
        if (!ptt_interlock_active) {
          ptt_key();
        }
        if (current_tx_key_line) {digitalWrite (current_tx_key_line, HIGH);}
        #ifdef OPTION_WINKEY_2_SUPPORT
          if ((wk2_both_tx_activated) && (tx_key_line_2)) {
            digitalWrite (tx_key_line_2, HIGH);
          }
        #endif
        if ((first_extension_time) && (previous_ptt_line_activated == 0)) {
          delay(first_extension_time);
        }
      }
      if ((configuration.sidetone_mode == SIDETONE_ON) || (keyer_machine_mode == KEYER_COMMAND_MODE) || ((configuration.sidetone_mode == SIDETONE_PADDLE_ONLY) && (sending_type == MANUAL_SENDING))) {
        tone(sidetone_line, configuration.hz_sidetone);
      }
      key_state = 1;
    } else {
      if ((state == 0) && (key_state)) {
        if (key_tx) {
          if (current_tx_key_line) {digitalWrite (current_tx_key_line, LOW);}
          #ifdef OPTION_WINKEY_2_SUPPORT
            if ((wk2_both_tx_activated) && (tx_key_line_2)) {
              digitalWrite (tx_key_line_2, LOW);
            }
          #endif        
          if (!ptt_interlock_active) {
            ptt_key();
          }
        }
        if ((configuration.sidetone_mode == SIDETONE_ON) || (keyer_machine_mode == KEYER_COMMAND_MODE) || ((configuration.sidetone_mode == SIDETONE_PADDLE_ONLY) && (sending_type == MANUAL_SENDING))) {
          noTone(sidetone_line);
        }
        key_state = 0;
      }
    }

  #endif //FEATURE_PTT_INTERLOCK


}

//-------------------------------------------------------------------------------------------------------


#ifndef FEATURE_HI_PRECISION_LOOP_TIMING

  void loop_element_lengths(float lengths, float additional_time_ms, int speed_wpm_in, byte sending_type)
  {


    
    if ((lengths == 0) or (lengths < 0)) {
      return;
    }

    float element_length;

    if (speed_mode == SPEED_NORMAL) {
      element_length = 1200/speed_wpm_in;   
    } else {
      element_length = qrss_dit_length * 1000;
    }



    #ifdef FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
      unsigned long starttime = millis();
    #endif //FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING

    unsigned long endtime = millis() + long(element_length*lengths) + long(additional_time_ms);
    while ((millis() < endtime) && (millis() > 200)) {  // the second condition is to account for millis() rollover
      #ifdef OPTION_WATCHDOG_TIMER
        wdt_reset();
      #endif  //OPTION_WATCHDOG_TIMER
      
      #ifdef FEATURE_ROTARY_ENCODER
        check_rotary_encoder();
      #endif //FEATURE_ROTARY_ENCODER    
      
      #if defined(FEATURE_USB_KEYBOARD) || defined(FEATURE_USB_MOUSE)
        service_usb();
      #endif //FEATURE_USB_KEYBOARD || FEATURE_USB_MOUSE

      #ifdef FEATURE_PTT_INTERLOCK
        service_ptt_interlock();
      #endif //FEATURE_PTT_INTERLOCK
      
      if (configuration.keyer_mode != ULTIMATIC) {
        if ((configuration.keyer_mode == IAMBIC_A) && (paddle_pin_read(paddle_left) == LOW ) && (paddle_pin_read(paddle_right) == LOW )) {
            iambic_flag = 1;
        }    
     
        #ifndef FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
          if (being_sent == SENDING_DIT) {
            check_dah_paddle();
          } else {
            if (being_sent == SENDING_DAH) {
              check_dit_paddle();
            }
          }
        #else ////FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
          if ((float(float(millis()-starttime)/float(endtime-starttime))*100) >= configuration.cmos_super_keyer_iambic_b_timing_percent) {
            if (being_sent == SENDING_DIT) {
              check_dah_paddle();
            } else {
              if (being_sent == SENDING_DAH) {
                check_dit_paddle();
              }
            }     
          } else {
            if (((being_sent == SENDING_DIT) || (being_sent == SENDING_DAH)) && (paddle_pin_read(paddle_left) == LOW ) && (paddle_pin_read(paddle_right) == LOW )) {
              dah_buffer = 0;
              dit_buffer = 0;         
            }              
          }
        #endif //FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING

      }
      
      #if defined(FEATURE_MEMORIES) && defined(FEATURE_COMMAND_BUTTONS)
        check_the_memory_buttons();
      #endif

      // blow out prematurely if we're automatic sending and a paddle gets hit
      #ifdef FEATURE_COMMAND_BUTTONS
        if (sending_type == AUTOMATIC_SENDING && (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || analogbuttonread(0) || dit_buffer || dah_buffer)) {
          if (keyer_machine_mode == KEYER_NORMAL) {
            return;
          }
        }   
      #else
        if (sending_type == AUTOMATIC_SENDING && (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || dit_buffer || dah_buffer)) {
          if (keyer_machine_mode == KEYER_NORMAL) {
            return;
          }
        }   
      #endif

      #ifdef FEATURE_STRAIGHT_KEY
        service_straight_key();
      #endif //FEATURE_STRAIGHT_KEY

        
    }  //while ((millis() < endtime) && (millis() > 200))
   
    if ((configuration.keyer_mode == IAMBIC_A) && (iambic_flag) && (paddle_pin_read(paddle_left) == HIGH ) && (paddle_pin_read(paddle_right) == HIGH )) {
        iambic_flag = 0;
        dit_buffer = 0;
        dah_buffer = 0;
    }    
   
    #ifdef FEATURE_DIT_DAH_BUFFER_CONTROL
      if ((being_sent == SENDING_DIT) || (being_sent == SENDING_DAH)){
        if (configuration.dit_buffer_off) {dit_buffer = 0;}
        if (configuration.dah_buffer_off) {dah_buffer = 0;}
      }  
    #endif //FEATURE_DIT_DAH_BUFFER_CONTROL
   
   
  } //void loop_element_lengths


#else //FEATURE_HI_PRECISION_LOOP_TIMING

  void loop_element_lengths(float lengths, float additional_time_ms, int speed_wpm_in, byte sending_type){


    
    if ((lengths == 0) or (lengths < 0)) {
      return;
    }

    float element_length;

    if (speed_mode == SPEED_NORMAL) {
      element_length = 1200/speed_wpm_in;
    } else {
      element_length = qrss_dit_length * 1000;
    }

    #ifdef FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
      unsigned long starttime = micros();
    #endif //FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING

    unsigned long endtime = micros() + long(element_length*lengths*1000) + long(additional_time_ms*1000);
    while ((micros() < endtime) && (micros() > 200000)) {  // the second condition is to account for millis() rollover
      #ifdef OPTION_WATCHDOG_TIMER
        wdt_reset();
      #endif  //OPTION_WATCHDOG_TIMER
      
      #ifdef FEATURE_ROTARY_ENCODER
        check_rotary_encoder();
      #endif //FEATURE_ROTARY_ENCODER    
      
      #ifdef FEATURE_USB_KEYBOARD
        service_usb();
      #endif //FEATURE_USB_KEYBOARD
      
      if (configuration.keyer_mode != ULTIMATIC) {
        if ((configuration.keyer_mode == IAMBIC_A) && (paddle_pin_read(paddle_left) == LOW ) && (paddle_pin_read(paddle_right) == LOW )) {
            iambic_flag = 1;
        }    
    
        #ifndef FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
          if (being_sent == SENDING_DIT) {
            check_dah_paddle();
          } else {
            if (being_sent == SENDING_DAH) {
              check_dit_paddle();
            }
          }
        #else ////FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
          if ((float(float(micros()-starttime)/float(endtime-starttime))*100) >= configuration.cmos_super_keyer_iambic_b_timing_percent) {
            if (being_sent == SENDING_DIT) {
              check_dah_paddle();
            } else {
              if (being_sent == SENDING_DAH) {
                check_dit_paddle();
              }
            }     
          } else {
            if (((being_sent == SENDING_DIT) || (being_sent == SENDING_DAH)) && (paddle_pin_read(paddle_left) == LOW ) && (paddle_pin_read(paddle_right) == LOW )) {
              dah_buffer = 0;
              dit_buffer = 0;         
            }                 
          }
        #endif //FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING

        #ifdef FEATURE_STRAIGHT_KEY
          service_straight_key();
        #endif //FEATURE_STRAIGHT_KEY

      } //while ((millis() < endtime) && (millis() > 200))
      
      #if defined(FEATURE_MEMORIES) && defined(FEATURE_COMMAND_BUTTONS)
        check_the_memory_buttons();
      #endif

      // blow out prematurely if we're automatic sending and a paddle gets hit
      #ifdef FEATURE_COMMAND_BUTTONS
        if (sending_type == AUTOMATIC_SENDING && (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || analogbuttonread(0) || dit_buffer || dah_buffer)) {
          if (keyer_machine_mode == KEYER_NORMAL) {
            return;
          }
        }    
      #else
        if (sending_type == AUTOMATIC_SENDING && (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || dit_buffer || dah_buffer)) {
          if (keyer_machine_mode == KEYER_NORMAL) {
            return;
          }
        }  
      #endif
    }   
  
   
    if ((configuration.keyer_mode == IAMBIC_A) && (iambic_flag) && (paddle_pin_read(paddle_left) == HIGH ) && (paddle_pin_read(paddle_right) == HIGH )) {
        iambic_flag = 0;
        dit_buffer = 0;
        dah_buffer = 0;
    }    

    #ifdef FEATURE_DIT_DAH_BUFFER_CONTROL
    if ((being_sent == SENDING_DIT) || (being_sent == SENDING_DAH)){
      if (configuration.dit_buffer_off) {dit_buffer = 0;}
      if (configuration.dah_buffer_off) {dah_buffer = 0;}
    }  
    #endif //FEATURE_DIT_DAH_BUFFER_CONTROL
   
   
  } //void loop_element_lengths

#endif //FEATURE_HI_PRECISION_LOOP_TIMING

//-------------------------------------------------------------------------------------------------------

void speed_change(int change)
{
  if (((configuration.wpm + change) > wpm_limit_low) && ((configuration.wpm + change) < wpm_limit_high)) {
    speed_set(configuration.wpm + change);
  }
  


  #ifdef FEATURE_DISPLAY
    lcd_center_print_timed_wpm();
  #endif
}

//-------------------------------------------------------------------------------------------------------

void speed_set(int wpm_set){

  configuration.wpm = wpm_set;
  config_dirty = 1;

  #ifdef FEATURE_DYNAMIC_DAH_TO_DIT_RATIO
    if ((configuration.wpm >= DYNAMIC_DAH_TO_DIT_RATIO_LOWER_LIMIT_WPM) && (configuration.wpm <= DYNAMIC_DAH_TO_DIT_RATIO_UPPER_LIMIT_WPM)){
      int dynamicweightvalue=map(configuration.wpm,DYNAMIC_DAH_TO_DIT_RATIO_LOWER_LIMIT_WPM,DYNAMIC_DAH_TO_DIT_RATIO_UPPER_LIMIT_WPM,DYNAMIC_DAH_TO_DIT_RATIO_LOWER_LIMIT_RATIO,DYNAMIC_DAH_TO_DIT_RATIO_UPPER_LIMIT_RATIO);
      configuration.dah_to_dit_ratio=dynamicweightvalue;
    }
  #endif //FEATURE_DYNAMIC_DAH_TO_DIT_RATIO

    
  #ifdef FEATURE_LED_RING
    update_led_ring();
  #endif //FEATURE_LED_RING
    
  #ifdef FEATURE_DISPLAY
    lcd_center_print_timed_wpm();
  #endif
}
//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_DISPLAY
  void lcd_center_print_timed_wpm(){


    #if defined(OPTION_ADVANCED_SPEED_DISPLAY)
      lcd_center_print_timed(String(configuration.wpm) + " wpm - " + (configuration.wpm*5) + " cpm ", 0, default_display_msg_delay);
      lcd_center_print_timed(String(1200/configuration.wpm) + ":" + (((1200/configuration.wpm)*configuration.dah_to_dit_ratio)/100) + "ms 1:" + (float(configuration.dah_to_dit_ratio)/100.00), 1, default_display_msg_delay);
    #else
      lcd_center_print_timed(String(configuration.wpm) + " wpm", 0, default_display_msg_delay);
    #endif

  }
#endif
//-------------------------------------------------------------------------------------------------------

long get_cw_input_from_user(unsigned int exit_time_milliseconds) {

  byte looping = 1;
  byte paddle_hit = 0;
  long cw_char = 0;
  unsigned long last_element_time = 0;
  byte button_hit = 0;
  unsigned long entry_time = millis();

  while (looping) {
    #ifdef FEATURE_POTENTIOMETER
      if (configuration.pot_activated) {
        check_potentiometer();
      }
    #endif
    
    #ifdef FEATURE_ROTARY_ENCODER
      check_rotary_encoder();
    #endif //FEATURE_ROTARY_ENCODER    

    check_paddles();

    if (dit_buffer) {
      send_dit(MANUAL_SENDING);
      dit_buffer = 0;
      paddle_hit = 1;
      cw_char = (cw_char * 10) + 1;
      last_element_time = millis();
    }
    if (dah_buffer) {
      send_dah(MANUAL_SENDING);
      dah_buffer = 0;
      paddle_hit = 1;
      cw_char = (cw_char * 10) + 2;
      last_element_time = millis();
    }
    if ((paddle_hit) && (millis() > (last_element_time + (float(600/configuration.wpm) * length_letterspace)))) {
      #ifdef DEBUG_GET_CW_INPUT_FROM_USER
      debug_serial_port->println(F("get_cw_input_from_user: hit length_letterspace"));
      #endif
      looping = 0;
    }

    if ((!paddle_hit) && (exit_time_milliseconds) && ((millis() - entry_time) > exit_time_milliseconds)) { // if we were passed an exit time and no paddle was hit, blow out of here
      return 0;
    }

    #ifdef FEATURE_COMMAND_BUTTONS
      while (analogbuttonread(0)) {    // hit the button to get out of command mode if no paddle was hit
        looping = 0;
        button_hit = 1;
      }
    #endif

    #if defined(FEATURE_SERIAL)
      check_serial();
    #endif

  } //while (looping)

  if (button_hit) {
    #ifdef DEBUG_GET_CW_INPUT_FROM_USER
      debug_serial_port->println(F("get_cw_input_from_user: button_hit exit 9"));
    #endif
    return 9;
  } else {
    #ifdef DEBUG_GET_CW_INPUT_FROM_USER
      debug_serial_port->print(F("get_cw_input_from_user: exiting cw_char:"));
      debug_serial_port->println(cw_char);
    #endif    
    return cw_char;
  }
}

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_COMMAND_BUTTONS
void command_mode ()
{

  keyer_machine_mode = KEYER_COMMAND_MODE;
  
  #ifdef DEBUG_COMMAND_MODE
    debug_serial_port->println(F("command_mode: entering"));
  #endif
  
  byte looping;
  byte button_that_was_pressed = 0;
  byte paddle_hit = 0;
  unsigned long last_element_time = 0;
  int cw_char;
  byte stay_in_command_mode = 1;
  byte speed_mode_before = speed_mode;
  speed_mode = SPEED_NORMAL;                 // put us in normal speed mode (life is too short to do command mode in QRSS)
  byte keyer_mode_before = configuration.keyer_mode;
  if ((configuration.keyer_mode != IAMBIC_A) && (configuration.keyer_mode != IAMBIC_B)) {
    configuration.keyer_mode = IAMBIC_B;                   // we got to be in iambic mode (life is too short to make this work in bug mode)
  }

  command_mode_disable_tx = 0;

  boop_beep();
  #ifdef command_mode_active_led
    if (command_mode_active_led) {digitalWrite(command_mode_active_led,HIGH);}
  #endif //command_mode_active_led

  #ifdef FEATURE_DISPLAY
    lcd.clear();
    lcd_center_print_timed("Command Mode", 0, default_display_msg_delay);
  #endif 

  #if defined(FEATURE_WINKEY_EMULATION) && defined(OPTION_WINKEY_SEND_BREAKIN_STATUS_BYTE)
    winkey_breakin_status_byte_inhibit = 1;
  #endif

  while (stay_in_command_mode) {
    cw_char = 0;
 //   cw_char = get_cw_input_from_user(0);


    looping = 1;
    while (looping) {
      #ifdef FEATURE_POTENTIOMETER
        if (configuration.pot_activated) {
          check_potentiometer();
        }
      #endif
      
      #ifdef FEATURE_ROTARY_ENCODER
        check_rotary_encoder();
      #endif //FEATURE_ROTARY_ENCODER    

      check_paddles();

      if (dit_buffer) {
        send_dit(MANUAL_SENDING);
        dit_buffer = 0;
        paddle_hit = 1;
        cw_char = (cw_char * 10) + 1;
        last_element_time = millis();
      }
      if (dah_buffer) {
        send_dah(MANUAL_SENDING);
        dah_buffer = 0;
        paddle_hit = 1;
        cw_char = (cw_char * 10) + 2;
        last_element_time = millis();
      }
      if ((paddle_hit) && (millis() > (last_element_time + (float(600/configuration.wpm) * length_letterspace)))) {
        #ifdef DEBUG_GET_CW_INPUT_FROM_USER
          debug_serial_port->println(F("get_cw_input_from_user: hit length_letterspace"));
        #endif
        looping = 0;
      }

      if (analogbuttonpressed() < analog_buttons_number_of_buttons){  // check for a button press
        looping = 0;
        cw_char = 9;
        delay(50);
        button_that_was_pressed = analogbuttonpressed();
        while (analogbuttonpressed() < analog_buttons_number_of_buttons) {}
      }

      #if defined(FEATURE_SERIAL)
        check_serial();
      #endif

    } //while (looping)



// end new code

    #ifdef DEBUG_COMMAND_MODE
      debug_serial_port->print(F("command_mode: cwchar: "));
      debug_serial_port->println(cw_char);
    #endif
    if (cw_char > 0) {              // do the command      
      switch (cw_char) {
        case 12: // A - Iambic mode
          configuration.keyer_mode = IAMBIC_A;
          keyer_mode_before = IAMBIC_A;
          config_dirty = 1;
          #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Iambic A", 0, default_display_msg_delay);
          #endif
          send_dit(AUTOMATIC_SENDING);
          break; 
        case 2111: // B - Iambic mode
          configuration.keyer_mode = IAMBIC_B;
          keyer_mode_before = IAMBIC_B;
          config_dirty = 1;
          #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Iambic B", 0, default_display_msg_delay);
          #endif          
          send_dit(AUTOMATIC_SENDING);
          break;
        case 1: // E - announce spEed
          char c[4];
          delay(250);
          sprintf(c, "%d", configuration.wpm);
          send_char(c[0],KEYER_NORMAL);
          send_char(c[1],KEYER_NORMAL);
          break; 
        case 211: // D - Ultimatic mode
          configuration.keyer_mode = ULTIMATIC;
          keyer_mode_before = ULTIMATIC;
          config_dirty = 1;
          #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Ultimatic", 0, default_display_msg_delay);
          #endif                    
          send_dit(AUTOMATIC_SENDING);
          break; 
        case 1121: command_sidetone_freq_adj(); break;                    // F - adjust sidetone frequency
        case 221: // G - switch to buG mode
          configuration.keyer_mode = BUG;
          keyer_mode_before = BUG;
          config_dirty = 1;
          #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Bug", 0, default_display_msg_delay);
          #endif          
          send_dit(AUTOMATIC_SENDING);
          break;  
        case 11:                                                     // I - toggle TX enable / disable
          if (command_mode_disable_tx) {
            command_mode_disable_tx = 0;
            #ifdef FEATURE_DISPLAY
              lcd_center_print_timed("TX On", 0, default_display_msg_delay);
            #endif            
          } else {
            command_mode_disable_tx = 1;
            #ifdef FEATURE_DISPLAY
              lcd_center_print_timed("TX Off", 0, default_display_msg_delay);
            #endif            
          }
          send_dit(AUTOMATIC_SENDING);
          break;
        case 1222: command_dah_to_dit_ratio_adjust(); break;                        // J - dah to dit ratio adjust
        #ifdef FEATURE_MEMORIES
          case 1221: command_program_memory(); break;                       // P - program a memory
        #endif //FEATURE_MEMORIES  Acknowledgement: LA3ZA fixed!
        case 21: // N - paddle mode toggle
          if (configuration.paddle_mode == PADDLE_NORMAL) {
            configuration.paddle_mode = PADDLE_REVERSE;
            #ifdef FEATURE_DISPLAY
              lcd_center_print_timed("Paddle Reverse", 0, default_display_msg_delay);
            #endif //FEATURE_DISPLAY
          } else {
            #ifdef FEATURE_DISPLAY
              lcd_center_print_timed("Paddle Normal", 0, default_display_msg_delay);
            #endif //FEATURE_DISPLAY         
            configuration.paddle_mode = PADDLE_NORMAL;
          }
          config_dirty = 1;
          send_dit(AUTOMATIC_SENDING);
          break;  
        case 222: // O - toggle sidetone on and off
          if ((configuration.sidetone_mode == SIDETONE_ON) || (configuration.sidetone_mode == SIDETONE_PADDLE_ONLY)) {
            #ifdef FEATURE_DISPLAY
              lcd_center_print_timed("Sidetone Off", 0, default_display_msg_delay);
            #endif 
            #ifdef DEBUG_COMMAND_MODE
              debug_serial_port->println(F("command_mode: SIDETONE_OFF"));
            #endif
            configuration.sidetone_mode = SIDETONE_OFF;
            //boop();
          } else {
            #ifdef FEATURE_DISPLAY
              lcd_center_print_timed("Sidetone On", 0, default_display_msg_delay);
            #endif 
            #ifdef DEBUG_COMMAND_MODE
              debug_serial_port->println(F("command_mode: SIDETONE_ON"));
            #endif             
            configuration.sidetone_mode = SIDETONE_ON;
            //beep();
          }
          config_dirty = 1;        
          send_dit(AUTOMATIC_SENDING);
          break; 
        case 2: command_tuning_mode(); break;                             // T - tuning mode
        #ifdef FEATURE_POTENTIOMETER
          case 1112:  // V - toggle pot active
            if (configuration.pot_activated) {
              configuration.pot_activated = 0; 
              #ifdef FEATURE_DISPLAY
                lcd_center_print_timed("Pot Deactivated", 0, default_display_msg_delay);
              #endif             
            } else {
              configuration.pot_activated = 1;
              #ifdef FEATURE_DISPLAY
                lcd_center_print_timed("Pot Activated", 0, default_display_msg_delay);
              #endif 
            }
            config_dirty = 1;
            send_dit(AUTOMATIC_SENDING);
            break; 
        #endif
        case 122: command_speed_mode(); break;                            // W - change wpm
        #ifdef FEATURE_MEMORIES
          case 2122: command_set_mem_repeat_delay(); break; // Y - set memory repeat delay
        #endif  
        case 2112: stay_in_command_mode = 0; break;     // X - exit command mode
        #ifdef FEATURE_AUTOSPACE
          case 2211: // Z - Autospace
            if (configuration.autospace_active) {
              configuration.autospace_active = 0;
              config_dirty = 1;
              #ifdef FEATURE_DISPLAY
                lcd_center_print_timed("Autospace Off", 0, default_display_msg_delay);
                send_dit(AUTOMATIC_SENDING);
              #else
                send_char('O',KEYER_NORMAL);
                send_char('F',KEYER_NORMAL);
                send_char('F',KEYER_NORMAL);
              #endif
            } else {
              configuration.autospace_active = 1;
              config_dirty = 1;
              #ifdef FEATURE_DISPLAY
                lcd_center_print_timed("Autospace On", 0, default_display_msg_delay);
                send_dit(AUTOMATIC_SENDING);
              #else            
                send_char('O',KEYER_NORMAL);
                send_char('N',KEYER_NORMAL);
              #endif
            }
            break;
        #endif
        #ifdef FEATURE_MEMORIES
          case 12222: play_memory(0); break;
          case 11222: play_memory(1); break;
          case 11122: play_memory(2); break;
          case 11112: play_memory(3); break;
          case 11111: play_memory(4); break;
        #endif
        #ifdef FEATURE_ALPHABET_SEND_PRACTICE
          case 111:
            send_dit(AUTOMATIC_SENDING); 
            command_alphabet_send_practice(); // S - Alphabet Send Practice
            stay_in_command_mode = 0;
            break;
        #endif  //FEATURE_ALPHABET_SEND_PRACTICE
        case 9: // button was hit
          #if defined(FEATURE_MEMORIES)
            if (button_that_was_pressed == 0){  // button 0 was hit - exit
              stay_in_command_mode = 0;
            } else {
              program_memory(button_that_was_pressed - 1); // a button other than 0 was pressed - program a memory
            }
          #else 
            stay_in_command_mode = 0;
          #endif
          break;                           
        default: // unknown command, send a ?
          #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Unknown command", 0, default_display_msg_delay);          
          #endif
          send_char('?',KEYER_NORMAL); 
          break;                                   
      }
    }
  }
  beep_boop();
  #if defined(FEATURE_WINKEY_EMULATION) && defined(OPTION_WINKEY_SEND_BREAKIN_STATUS_BYTE)
    winkey_breakin_status_byte_inhibit = 0;
  #endif  

  #ifdef command_mode_active_led
    if (command_mode_active_led) {digitalWrite(command_mode_active_led,LOW);}
  #endif //command_mode_active_led

  keyer_machine_mode = KEYER_NORMAL;

  speed_mode = speed_mode_before;   // go back to whatever speed mode we were in before
  configuration.keyer_mode = keyer_mode_before;

  #ifdef DEBUG_COMMAND_MODE
    if (command_mode_disable_tx) {
      debug_serial_port->print(F("command_mode: command_mode_disable_tx set"));
    }
  #endif //DEBUG_COMMAND_MODE
}
#endif //FEATURE_COMMAND_BUTTONS

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_MEMORIES
void command_set_mem_repeat_delay() {
  
  byte character_count = 0;;
  int cw_char = 0;
  byte number_sent = 0;
  unsigned int repeat_value = 0;
  byte error_flag = 0;
  
  for (character_count = 0; character_count < 4; character_count++) {
    cw_char = get_cw_input_from_user(0);
    number_sent = (convert_cw_number_to_ascii(cw_char) - 48);
    if ((number_sent > -1) && (number_sent < 10)) {
      repeat_value = (repeat_value * 10) + number_sent;
    } else { // we got a bad value
      error_flag = 1;
      character_count = 5;
    }      
  }
  
  if (error_flag) {
    boop();
  } else {
    configuration.memory_repeat_time = repeat_value;
    config_dirty = 1;
    beep();
  }
  
}
#endif //FEATURE_MEMORIES

//-------------------------------------------------------------------------------------------------------

void adjust_dah_to_dit_ratio(int adjustment) {

 if ((configuration.dah_to_dit_ratio + adjustment) > 150 && (configuration.dah_to_dit_ratio + adjustment) < 810) {
   configuration.dah_to_dit_ratio = configuration.dah_to_dit_ratio + adjustment;
   #ifdef FEATURE_DISPLAY
   #ifdef OPTION_MORE_DISPLAY_MSGS
   lcd_center_print_timed("Dah/Dit: " + String(configuration.dah_to_dit_ratio), 0, default_display_msg_delay);
   service_display();
   #endif
   #endif   
 }

 config_dirty = 1;
}

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_COMMAND_BUTTONS
void command_dah_to_dit_ratio_adjust () {

  byte looping = 1;

  #ifdef FEATURE_DISPLAY
  lcd_center_print_timed("Adj dah to dit", 0, default_display_msg_delay);          
  #endif

  while (looping) {
   send_dit(AUTOMATIC_SENDING);
   send_dah(AUTOMATIC_SENDING);
   if (paddle_pin_read(paddle_left) == LOW) {
     adjust_dah_to_dit_ratio(10);
   }
   if (paddle_pin_read(paddle_right) == LOW) {
     adjust_dah_to_dit_ratio(-10);
   }
   while ((paddle_pin_read(paddle_left) == LOW && paddle_pin_read(paddle_right) == LOW) || (analogbuttonread(0))) { // if paddles are squeezed or button0 pressed - exit
     looping = 0;
   }
   
  }
  while (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || analogbuttonread(0) ) {}  // wait for all lines to go high
  dit_buffer = 0;
  dah_buffer = 0;
}
#endif //FEATURE_COMMAND_BUTTONS

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_COMMAND_BUTTONS
void command_tuning_mode() {

  byte looping = 1;
  byte latched = 0;
  
  
  #ifdef FEATURE_DISPLAY
  lcd_center_print_timed("Tune Mode", 0, default_display_msg_delay);          
  #endif  
  
  send_dit(AUTOMATIC_SENDING);
  key_tx = 1;
  while (looping) {

    if (paddle_pin_read(paddle_left) == LOW) {
      tx_and_sidetone_key(1,MANUAL_SENDING);
      ptt_key();
      latched = 0;
    } else {
       if (paddle_pin_read(paddle_left) == HIGH && latched == 0) {
         tx_and_sidetone_key(0,MANUAL_SENDING);
         ptt_unkey();
       }
    }

    if (paddle_pin_read(paddle_right) == LOW && latched == 0) {
      latched = 1;
      tx_and_sidetone_key(1,MANUAL_SENDING);
      ptt_key();
      while ((paddle_pin_read(paddle_right) == LOW) && (paddle_pin_read(paddle_left) == HIGH)) {
        delay(10);
      }
    } else {
      if ((paddle_pin_read(paddle_right) == LOW) && (latched)) {
        latched = 0;
        tx_and_sidetone_key(0,MANUAL_SENDING);
        ptt_unkey();
        while ((paddle_pin_read(paddle_right) == LOW) && (paddle_pin_read(paddle_left) == HIGH)) {
          delay(10);
        }
      }
    }
   if ((analogbuttonread(0)) || ((paddle_pin_read(paddle_left) == LOW) && (paddle_pin_read(paddle_right) == LOW))) { // if paddles are squeezed or button0 pressed - exit
     looping = 0;
   }
   
  }
  tx_and_sidetone_key(0,MANUAL_SENDING);
  ptt_unkey();
  while (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || analogbuttonread(0) ) {}  // wait for all lines to go high
  key_tx = 0;
  send_dit(AUTOMATIC_SENDING);
  dit_buffer = 0;
  dah_buffer = 0;
}
#endif //FEATURE_COMMAND_BUTTONS
//-------------------------------------------------------------------------------------------------------

void sidetone_adj(int hz) {

  if ((configuration.hz_sidetone + hz) > SIDETONE_HZ_LOW_LIMIT && (configuration.hz_sidetone + hz) < SIDETONE_HZ_HIGH_LIMIT) {
    configuration.hz_sidetone = configuration.hz_sidetone + hz;
    config_dirty = 1;
    #ifdef FEATURE_DISPLAY
    #ifdef OPTION_MORE_DISPLAY_MSGS
    lcd_center_print_timed("Sidetone " + String(configuration.hz_sidetone) + " Hz", 0, default_display_msg_delay);
    #endif
    #endif   
  }

}

//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_COMMAND_BUTTONS
void command_sidetone_freq_adj() {

  byte looping = 1;

  #ifdef FEATURE_DISPLAY
  lcd_center_print_timed("Sidetone " + String(configuration.hz_sidetone) + " Hz", 0, default_display_msg_delay);   
  #endif

  while (looping) {
    tone(sidetone_line, configuration.hz_sidetone);
    if (paddle_pin_read(paddle_left) == LOW) {
      #ifdef FEATURE_DISPLAY
      sidetone_adj(5);      
      lcd_center_print_timed("Sidetone " + String(configuration.hz_sidetone) + " Hz", 0, default_display_msg_delay);        
      #else
      sidetone_adj(1);
      #endif
      delay(10);
    }
    if (paddle_pin_read(paddle_right) == LOW) {
      #ifdef FEATURE_DISPLAY
      sidetone_adj(-5);
      lcd_center_print_timed("Sidetone " + String(configuration.hz_sidetone) + " Hz", 0, default_display_msg_delay);       
      #else
      sidetone_adj(-1);
      #endif
      delay(10);
    }
    while ((paddle_pin_read(paddle_left) == LOW && paddle_pin_read(paddle_right) == LOW) || (analogbuttonread(0))) { // if paddles are squeezed or button0 pressed - exit
      looping = 0;
    }
    

  }
  while (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || analogbuttonread(0) ) {}  // wait for all lines to go high
  noTone(sidetone_line);

}
#endif //FEATURE_COMMAND_BUTTONS
//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_COMMAND_BUTTONS
void command_speed_mode()
{

  byte looping = 1;
  String wpm_string;
  
  #ifdef FEATURE_DISPLAY
  lcd_center_print_timed("Adjust Speed", 0, default_display_msg_delay);        
  #endif
  

  while (looping) {
    send_dit(AUTOMATIC_SENDING);
    if ((paddle_pin_read(paddle_left) == LOW)) {
      speed_change(1);
    }
    if ((paddle_pin_read(paddle_right) == LOW)) {
      speed_change(-1);
    }
    while ((paddle_pin_read(paddle_left) == LOW && paddle_pin_read(paddle_right) == LOW) || (analogbuttonread(0) ))  // if paddles are squeezed or button0 pressed - exit
    {
      looping = 0;
    }

  }
  while (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || analogbuttonread(0) ) {}  // wait for all lines to go high
  #ifndef FEATURE_DISPLAY
  // announce speed in CW
  wpm_string = String(configuration.wpm, DEC);
  send_char(wpm_string[0],KEYER_NORMAL);
  send_char(wpm_string[1],KEYER_NORMAL);
  #endif

  dit_buffer = 0;
  dah_buffer = 0;

}
#endif //FEATURE_COMMAND_BUTTONS
//------------------------------------------------------------------
#ifndef FEATURE_DISPLAY
void send_tx() {

  send_char('T',KEYER_NORMAL);
  send_char('X',KEYER_NORMAL);
}
#endif

//------------------------------------------------------------------

void switch_to_tx_silent(byte tx) {

  switch (tx) {
   case 1: if ((ptt_tx_1) || (tx_key_line_1)) { configuration.current_ptt_line = ptt_tx_1; current_tx_key_line = tx_key_line_1; configuration.current_tx = 1; config_dirty = 1; } break;
   case 2: if ((ptt_tx_2) || (tx_key_line_2)) { configuration.current_ptt_line = ptt_tx_2; current_tx_key_line = tx_key_line_2; configuration.current_tx = 2; config_dirty = 1; } break;
   case 3: if ((ptt_tx_3) || (tx_key_line_3)) { configuration.current_ptt_line = ptt_tx_3; current_tx_key_line = tx_key_line_3; configuration.current_tx = 3; config_dirty = 1; } break;
   case 4: if ((ptt_tx_4) || (tx_key_line_4)) { configuration.current_ptt_line = ptt_tx_4; current_tx_key_line = tx_key_line_4; configuration.current_tx = 4; config_dirty = 1; } break;
   case 5: if ((ptt_tx_5) || (tx_key_line_5)) { configuration.current_ptt_line = ptt_tx_5; current_tx_key_line = tx_key_line_5; configuration.current_tx = 5; config_dirty = 1; } break;
   case 6: if ((ptt_tx_6) || (tx_key_line_6)) { configuration.current_ptt_line = ptt_tx_6; current_tx_key_line = tx_key_line_6; configuration.current_tx = 6; config_dirty = 1; } break;
  }
  
}

//------------------------------------------------------------------
void switch_to_tx(byte tx)
{

  #ifdef FEATURE_MEMORIES
  repeat_memory = 255;
  #endif

  #ifdef FEATURE_DISPLAY        
  switch (tx) {
   case 1: if ((ptt_tx_1) || (tx_key_line_1)) { switch_to_tx_silent(1); lcd_center_print_timed("TX 1", 0, default_display_msg_delay); } break;
   case 2: if ((ptt_tx_2) || (tx_key_line_2)) { switch_to_tx_silent(2); lcd_center_print_timed("TX 2", 0, default_display_msg_delay); } break;
   case 3: if ((ptt_tx_3) || (tx_key_line_3)) { switch_to_tx_silent(3); lcd_center_print_timed("TX 3", 0, default_display_msg_delay); } break;
   case 4: if ((ptt_tx_4) || (tx_key_line_4)) { switch_to_tx_silent(4); lcd_center_print_timed("TX 4", 0, default_display_msg_delay); } break;
   case 5: if ((ptt_tx_5) || (tx_key_line_5)) { switch_to_tx_silent(5); lcd_center_print_timed("TX 5", 0, default_display_msg_delay); } break;
   case 6: if ((ptt_tx_6) || (tx_key_line_6)) { switch_to_tx_silent(6); lcd_center_print_timed("TX 6", 0, default_display_msg_delay); } break;
  }
  #else
  switch (tx) {
   case 1: if ((ptt_tx_1) || (tx_key_line_1)) { switch_to_tx_silent(1); send_tx(); send_char('1',KEYER_NORMAL); } break;
   case 2: if ((ptt_tx_2) || (tx_key_line_2)) { switch_to_tx_silent(2); send_tx(); send_char('2',KEYER_NORMAL); } break;
   case 3: if ((ptt_tx_3) || (tx_key_line_3)) { switch_to_tx_silent(3); send_tx(); send_char('3',KEYER_NORMAL); } break;
   case 4: if ((ptt_tx_4) || (tx_key_line_4)) { switch_to_tx_silent(4); send_tx(); send_char('4',KEYER_NORMAL); } break;
   case 5: if ((ptt_tx_5) || (tx_key_line_5)) { switch_to_tx_silent(5); send_tx(); send_char('5',KEYER_NORMAL); } break;
   case 6: if ((ptt_tx_6) || (tx_key_line_6)) { switch_to_tx_silent(6); send_tx(); send_char('6',KEYER_NORMAL); } break;
  }
  #endif
}

//------------------------------------------------------------------

#ifdef FEATURE_MEMORIES
#ifdef FEATURE_COMMAND_BUTTONS
void check_the_memory_buttons()
{

  byte analogbuttontemp = analogbuttonpressed();
  if ((analogbuttontemp > 0) && (analogbuttontemp < (number_of_memories + 1)) && ((millis() - button_last_add_to_send_buffer_time) > 400)) {
    add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
    add_to_send_buffer(analogbuttontemp - 1);
    button_last_add_to_send_buffer_time = millis();
  }
}
#endif
#endif

//------------------------------------------------------------------

#ifdef FEATURE_COMMAND_BUTTONS
#ifdef FEATURE_DL2SBA_BANKSWITCH
void setOneButton(int button, int index) { 
    int button_value = int(1023 * (float(button * analog_buttons_r2)/float((button * analog_buttons_r2) + analog_buttons_r1))); 
    int lower_button_value = int(1023 * (float((button-1) * analog_buttons_r2)/float(((button-1) * analog_buttons_r2) + analog_buttons_r1))); 
    int higher_button_value = int(1023 * (float((button+1) * analog_buttons_r2)/float(((button+1) * analog_buttons_r2) + analog_buttons_r1))); 
    button_array_low_limit[index] = (button_value - ((button_value - lower_button_value)/2)); 
    button_array_high_limit[index] = (button_value + ((higher_button_value - button_value)/2)); 
}
#endif
#endif

//------------------------------------------------------------------

void initialize_analog_button_array() {
#ifdef FEATURE_COMMAND_BUTTONS  
  
  
  
  
  /* 
  
  typical button values:
  
    0: -56 - 46
    1: 47 - 131
    2: 132 - 203
    3: 203 - 264
    
  */
  

  
  #ifndef FEATURE_DL2SBA_BANKSWITCH
  
  int button_value;
  int lower_button_value;
  int higher_button_value;

  #ifdef OPTION_REVERSE_BUTTON_ORDER
  byte y = analog_buttons_number_of_buttons - 1;
  #endif

  for (int x = 0;x < analog_buttons_number_of_buttons;x++) {
    button_value = int(1023 * (float(x * analog_buttons_r2)/float((x * analog_buttons_r2) + analog_buttons_r1)));
    lower_button_value = int(1023 * (float((x-1) * analog_buttons_r2)/float(((x-1) * analog_buttons_r2) + analog_buttons_r1)));
    higher_button_value = int(1023 * (float((x+1) * analog_buttons_r2)/float(((x+1) * analog_buttons_r2) + analog_buttons_r1)));
    #ifndef OPTION_REVERSE_BUTTON_ORDER
    button_array_low_limit[x] = (button_value - ((button_value - lower_button_value)/2));
    button_array_high_limit[x] = (button_value + ((higher_button_value - button_value)/2));
    #else
    button_array_low_limit[y] = (button_value - ((button_value - lower_button_value)/2));
    button_array_high_limit[y] = (button_value + ((higher_button_value - button_value)/2));
    y--;
    #endif

    #ifdef DEBUG_BUTTON_ARRAY    
    debug_serial_port->print("initialize_analog_button_array: ");
    debug_serial_port->print(x);
    debug_serial_port->print(": ");
    debug_serial_port->print(button_array_low_limit[x]);
    debug_serial_port->print(" - ");
    debug_serial_port->println(button_array_high_limit[x]);
    #endif //DEBUG_BUTTON_ARRAY


  }
  
  #else //FEATURE_DL2SBA_BANKSWITCH
  
  setOneButton(0,0); 
  setOneButton(1,3); 
  setOneButton(2,2); 
  setOneButton(3,1); 
  setOneButton(4,9); 
  setOneButton(5,8); 
  setOneButton(6,7); 
  setOneButton(7,6); 
  setOneButton(8,5); 
  setOneButton(9,4); 
      
  #endif //FEATURE_DL2SBA_BANKSWITCH
#endif //FEATURE_COMMAND_BUTTONS
}


//------------------------------------------------------------------

#ifdef FEATURE_COMMAND_BUTTONS
byte analogbuttonpressed() {

  int analog_line_read_average = 0;
  int analog_read_temp = 0;
  
  #if !defined(OPTION_REVERSE_BUTTON_ORDER)
    if (analogRead(analog_buttons_pin) <= button_array_high_limit[analog_buttons_number_of_buttons-1]) {
      
      for (byte x = 0;x < 19;x++){
        analog_read_temp = analogRead(analog_buttons_pin);
        if (analog_read_temp <= button_array_high_limit[analog_buttons_number_of_buttons-1]){
          analog_line_read_average = (analog_line_read_average + analog_read_temp) / 2;
        }
      }
      
      for (int x = 0;x < analog_buttons_number_of_buttons;x++) {
        if ((analog_line_read_average > button_array_low_limit[x]) && (analog_line_read_average <=  button_array_high_limit[x])) {
          #ifdef DEBUG_BUTTONS
          //if (!debug_flag) {
            debug_serial_port->print(F(" analogbuttonpressed: returning: "));
            debug_serial_port->println(x);
          //  debug_flag = 1;
          //}
          #endif         
          return x;
        }  
      }    
      
    }

  #else //OPTION_REVERSE_BUTTON_ORDER

    if (analogRead(analog_buttons_pin) <= button_array_high_limit[0]) {
      \
      for (byte x = 0;x < 19;x++){
        analog_read_temp = analogRead(analog_buttons_pin);
        if (analog_read_temp <= button_array_high_limit[0]){
          analog_line_read_average = (analog_line_read_average + analog_read_temp) / 2;
        }
      }
      
      #ifdef DEBUG_BUTTONS
      debug_serial_port->print(F(" analogbuttonpressed: analog_line_read_average: "));
      debug_serial_port->println(analog_line_read_average);
      #endif 

      for (int x = 0;x < analog_buttons_number_of_buttons;x++) {
        if ((analog_line_read_average > button_array_low_limit[x]) && (analog_line_read_average <=  button_array_high_limit[x])) {
          #ifdef DEBUG_BUTTONS
          //if (!debug_flag) {
            debug_serial_port->print(F(" analogbuttonpressed: returning: "));
            debug_serial_port->println(x);
          //  debug_flag = 1;
          //}
          #endif         
          return x;
        }  
      }    
      
    }

  #endif //OPTION_REVERSE_BUTTON_ORDER
  

  /*

  int analog_line_read = analogRead(analog_buttons_pin);
  
  static byte samplecounts = 0;
  static int running_analog_line_read_average = 0;
  
  #ifdef DEBUG_BUTTONS
  static byte debug_flag = 0;
  #endif
  
  if (analog_line_read < 1000) {

    running_analog_line_read_average = running_analog_line_read_average + analog_line_read;
    samplecounts++;
    if (samplecounts > 19) {        
      analog_line_read = running_analog_line_read_average / samplecounts;
      
      #ifdef DEBUG_BUTTONS
      if (!debug_flag) {
        primary_serial_port->print(F("\nanalogbuttonpressed: analog_line_read: "));
        primary_serial_port->print(analog_line_read);
        primary_serial_port->print(F(" samplecounts: "));
        primary_serial_port->print(samplecounts);
      }
      #endif        
      
      for (int x = 0;x < analog_buttons_number_of_buttons;x++) {
        if ((analog_line_read > button_array_low_limit[x]) && (analog_line_read <=  button_array_high_limit[x])) {
          #ifdef DEBUG_BUTTONS
          if (!debug_flag) {
            primary_serial_port->print(F(" analogbuttonpressed: returning: "));
            primary_serial_port->println(x);
            debug_flag = 1;
          }
          #endif
          samplecounts = 0;
          running_analog_line_read_average = 0;          
          return x;
        }  
      }
    }  //(samplecounts > 9)
  } else {  //(analog_line_read < 1000)
    samplecounts = 0;
    running_analog_line_read_average = 0;
  }
   
  #ifdef DEBUG_BUTTONS
  debug_flag = 0;
  #endif
  
  
  */
  
  return 255; 
}
  
#endif

//------------------------------------------------------------------
#ifdef FEATURE_COMMAND_BUTTONS
byte analogbuttonread(byte button_number) {
 
  // button numbers start with 0
  
  int analog_line_read = analogRead(analog_buttons_pin);

  #ifdef DEBUG_BUTTONS
  static byte debug_flag = 0;
  #endif
  
  if (analog_line_read < 1000) {  
    if ((analog_line_read > button_array_low_limit[button_number])&& (analog_line_read <  button_array_high_limit[button_number])) {
      #ifdef DEBUG_BUTTONS
      if (!debug_flag) {
        debug_serial_port->print(F("\nanalogbuttonread: analog_line_read: "));
        debug_serial_port->print(analog_line_read);
        debug_serial_port->print(F("  button pressed: "));
        debug_serial_port->println(button_number);
        debug_flag = 1;
      }
      #endif
      return 1;
    }  
  }
  #ifdef DEBUG_BUTTONS
  debug_flag = 0;
  #endif  
  return 0;
}
#endif

//------------------------------------------------------------------

#ifdef FEATURE_COMMAND_BUTTONS
void check_command_buttons()
{

  #ifdef DEBUG_LOOP
    debug_serial_port->println(F("loop: entering check_buttons"));
  #endif

  static long last_button_action = 0;
  byte analogbuttontemp = analogbuttonpressed();
  long button_depress_time;
  byte paddle_was_hit = 0;
  byte store_key_tx = key_tx;
  byte previous_sidetone_mode = 0;
  if ((analogbuttontemp < analog_buttons_number_of_buttons) && ((millis() - last_button_action) > 200)) {
    #ifdef FEATURE_MEMORIES
      repeat_memory = 255;
    #endif
    button_depress_time = millis();
    while ((analogbuttontemp == analogbuttonpressed()) && ((millis() - button_depress_time) < 1000)) {
      if ((paddle_pin_read(paddle_left) == LOW) || (paddle_pin_read(paddle_right) == LOW)) {
        button_depress_time = 1001;  // if button 0 is held and a paddle gets hit, assume we have a hold and shortcut out
      }
    }
    if ((millis() - button_depress_time) < 500) {
      if (analogbuttontemp == 0) {
        key_tx = 0;
        command_mode();
        if (command_mode_disable_tx) {
          key_tx = !store_key_tx;
        } else {
          key_tx = 1;
        }
      }
      #ifdef FEATURE_MEMORIES
      if ((analogbuttontemp > 0) && (analogbuttontemp < (number_of_memories + 1)) && ((millis() - button_last_add_to_send_buffer_time) > 400)) {
        
        #ifdef FEATURE_WINKEY_EMULATION
        #ifndef OPTION_WINKEY_2_SUPPORT
        add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
        add_to_send_buffer(analogbuttontemp - 1);
        #else //OPTION_WINKEY_2_SUPPORT
        if ((winkey_host_open) && (wk2_mode == 2)) {   // if winkey is open and in wk2 mode, tell it about the button press
          byte winkey_byte_to_send = 0xc8;
          switch(analogbuttontemp) {
            case 1: winkey_byte_to_send = winkey_byte_to_send | 1; break;
            case 2: winkey_byte_to_send = winkey_byte_to_send | 2; break;
            case 3: winkey_byte_to_send = winkey_byte_to_send | 4; break;
            case 4: winkey_byte_to_send = winkey_byte_to_send | 16; break;            
          } 
          winkey_port_write(winkey_byte_to_send);
          winkey_port_write(0xc8); // tell it that the button is unpressed
        } else {  // otherwise, have the buttons act as normal
          add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
          add_to_send_buffer(analogbuttontemp - 1);
        }  
        #endif //OPTION_WINKEY_2_SUPPORT
        #else //FEATURE_WINKEY_EMULATION
        add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
        add_to_send_buffer(analogbuttontemp - 1);
        #endif //FEATURE_WINKEY_EMULATION

        button_last_add_to_send_buffer_time = millis();
        #ifdef DEBUG_BUTTONS
        debug_serial_port->print(F("\ncheck_buttons: add_to_send_buffer: "));
        debug_serial_port->println(analogbuttontemp - 1);
        #endif //DEBUG_BUTTONS
      }
      #endif
    } else {
//      if ((millis() - button_depress_time) < 1000) {
//        if ((analogbuttontemp > 0) && (analogbuttontemp < 7)) {
//          key_tx = 0;
//          switch_to_tx(analogbuttontemp);
//          key_tx = 1;
//        }
//      } else {  // we got a button hold
        if (analogbuttontemp == 0) {
          key_tx = 0;
          // do stuff if this is a command button hold down
          while (analogbuttonpressed() == 0) {
            if (paddle_pin_read(paddle_left) == LOW) {                     // left paddle increase speed
              speed_change(1);
              previous_sidetone_mode = configuration.sidetone_mode;
              configuration.sidetone_mode = SIDETONE_ON; 
              send_dit(MANUAL_SENDING);
              configuration.sidetone_mode = previous_sidetone_mode;
              //speed_button_cmd_executed = 1;
              dit_buffer = 0;
              
              #ifdef DEBUG_BUTTONS
              debug_serial_port->println(F("\ncheck_buttons: speed_change(1)"));
              #endif //DEBUG_BUTTONS            

              #ifdef FEATURE_WINKEY_EMULATION
              #ifdef FEATURE_POTENTIOMETER
              if ((primary_serial_port_mode == SERIAL_WINKEY_EMULATION) && (winkey_host_open)) {
                winkey_port_write(((configuration.wpm-pot_wpm_low_value)|128));
                winkey_last_unbuffered_speed_wpm = configuration.wpm;
              }
              #endif
              #endif

            }
            if (paddle_pin_read(paddle_right) == LOW) {                    // right paddle decreases speed
              speed_change(-1);
              previous_sidetone_mode = configuration.sidetone_mode;
              configuration.sidetone_mode = SIDETONE_ON; 
              send_dah(MANUAL_SENDING);
              configuration.sidetone_mode = previous_sidetone_mode;              
              //speed_button_cmd_executed = 1;
              dah_buffer = 0;

              #ifdef DEBUG_BUTTONS
              debug_serial_port->println(F("\ncheck_buttons: speed_change(-1)"));
              #endif //DEBUG_BUTTONS            

              #ifdef FEATURE_WINKEY_EMULATION
              #ifdef FEATURE_POTENTIOMETER
              if ((primary_serial_port_mode == SERIAL_WINKEY_EMULATION) && (winkey_host_open)) {
                winkey_port_write(((configuration.wpm-pot_wpm_low_value)|128));
                winkey_last_unbuffered_speed_wpm = configuration.wpm;
              }
              #endif
              #endif
            }
         }
         key_tx = 1;
       }  //(analogbuttontemp == 0)
       if ((analogbuttontemp > 0) && (analogbuttontemp < analog_buttons_number_of_buttons)) {
         while (analogbuttonpressed() == analogbuttontemp) {
            if (((paddle_pin_read(paddle_left) == LOW) || (paddle_pin_read(paddle_right) == LOW)) && (analogbuttontemp < (number_of_memories + 1))){
              #ifdef FEATURE_MEMORIES
              repeat_memory = analogbuttontemp - 1;
              last_memory_repeat_time = 0;
              #ifdef DEBUG_BUTTONS
              debug_serial_port->print(F("\ncheck_buttons: repeat_memory:"));
              debug_serial_port->println(repeat_memory);
              #endif //DEBUG_BUTTONS                    
              #endif
              paddle_was_hit = 1;
            }
         }
         if (!paddle_was_hit) {  // if no paddle was hit, this was a button hold to change transmitters
             key_tx = 0;
             previous_sidetone_mode = configuration.sidetone_mode;
             configuration.sidetone_mode = SIDETONE_ON;
             switch_to_tx(analogbuttontemp);
             key_tx = 1;
             configuration.sidetone_mode = previous_sidetone_mode;
         }
       }
     //} // button hold
    }
    last_button_action = millis();
    #ifdef FEATURE_SLEEP
    last_activity_time = millis(); 
    #endif //FEATURE_SLEEP
  }
}
#endif //FEATURE_COMMAND_BUTTONS

//-------------------------------------------------------------------------------------------------------

void service_dit_dah_buffers()
{
  #ifdef DEBUG_LOOP
  debug_serial_port->println(F("loop: entering service_dit_dah_buffers"));
  #endif      
      
  if ((configuration.keyer_mode == IAMBIC_A) || (configuration.keyer_mode == IAMBIC_B) || (configuration.keyer_mode == ULTIMATIC)) {
    if ((configuration.keyer_mode == IAMBIC_A) && (iambic_flag) && (paddle_pin_read(paddle_left)) && (paddle_pin_read(paddle_right))) {
      iambic_flag = 0;
      dit_buffer = 0;
      dah_buffer = 0;
    } else {
      if (dit_buffer) {
        dit_buffer = 0;
        send_dit(MANUAL_SENDING);
      }
      if (dah_buffer) {
        dah_buffer = 0;
        send_dah(MANUAL_SENDING);
      }
    }
  } else {
    if (configuration.keyer_mode == BUG) {
      if (dit_buffer) {
        dit_buffer = 0;
        send_dit(MANUAL_SENDING);
      }
      if (dah_buffer) {
        dah_buffer = 0;
        tx_and_sidetone_key(1,MANUAL_SENDING);
      } else {
        tx_and_sidetone_key(0,MANUAL_SENDING);
      }
      #ifdef FEATURE_DEAD_OP_WATCHDOG
      dah_counter = 0;
      #endif
    } else {
      if (configuration.keyer_mode == STRAIGHT) {
        if (dit_buffer) {
          dit_buffer = 0;
          tx_and_sidetone_key(1,MANUAL_SENDING);
        } else {
          tx_and_sidetone_key(0,MANUAL_SENDING);
        }
        #ifdef FEATURE_DEAD_OP_WATCHDOG
        dit_counter = 0;
        #endif
      }
    }
  }

}

//-------------------------------------------------------------------------------------------------------

void beep()
{
 tone(sidetone_line, hz_high_beep, 200);
}

//-------------------------------------------------------------------------------------------------------

void boop()
{
  tone(sidetone_line, hz_low_beep);
  delay(100);
  noTone(sidetone_line);
}

//-------------------------------------------------------------------------------------------------------

void beep_boop()
{
  tone(sidetone_line, hz_high_beep);
  delay(100);
  tone(sidetone_line, hz_low_beep);
  delay(100);
  noTone(sidetone_line);
}

//-------------------------------------------------------------------------------------------------------

void boop_beep()
{
  tone(sidetone_line, hz_low_beep);
  delay(100);
  tone(sidetone_line, hz_high_beep);
  delay(100);
  noTone(sidetone_line);
}



//-------------------------------------------------------------------------------------------------------
void send_the_dits_and_dahs(char * cw_to_send){


  for (int x = 0;x < 12;x++){
    switch(cw_to_send[x]){
      case '.': send_dit(AUTOMATIC_SENDING); break;
      case '-': send_dah(AUTOMATIC_SENDING); break;
      default: return; break;
    }
    if ((dit_buffer) || (dah_buffer)){
      return;
    }
  }

}

//-------------------------------------------------------------------------------------------------------

void send_char(char cw_char, byte omit_letterspace)
{
  #ifdef DEBUG_SEND_CHAR
  debug_serial_port->print(F("send_char: called with cw_char:"));
  debug_serial_port->print(cw_char);
  if (omit_letterspace) {
    debug_serial_port->print(F(" OMIT_LETTERSPACE"));
  }
  debug_serial_port->println();
  #endif


  #ifdef FEATURE_SLEEP
  last_activity_time = millis(); 
  #endif //FEATURE_SLEEP

  if ((cw_char == 10) || (cw_char == 13)) { return; }  // don't attempt to send carriage return or line feed

  if (char_send_mode == CW) {
    switch (cw_char) {
      case 'A': send_the_dits_and_dahs(".-");break;//send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); break;
      case 'B': send_the_dits_and_dahs("-...");break;//send_dah(AUTOMATIC_SENDING); send_dits(3); break;
      case 'C': send_the_dits_and_dahs("-.-.");break;//send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); break;
      case 'D': send_the_dits_and_dahs("-..");break;//send_dah(AUTOMATIC_SENDING); send_dits(2); break;
      case 'E': send_the_dits_and_dahs(".");break;//send_dit(AUTOMATIC_SENDING); break;
      case 'F': send_the_dits_and_dahs("..-.");break;//send_dits(2); send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); break;
      case 'G': send_the_dits_and_dahs("--.");break;//send_dahs(2); send_dit(AUTOMATIC_SENDING); break;
      case 'H': send_the_dits_and_dahs("....");break;//send_dits(4); break;
      case 'I': send_the_dits_and_dahs("..");break;//send_dits(2); break;
      case 'J': send_the_dits_and_dahs(".---");break;//send_dit(AUTOMATIC_SENDING); send_dahs(3); break;
      case 'K': send_the_dits_and_dahs("-.-");break;//send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); break;
      case 'L': send_the_dits_and_dahs(".-..");break;//send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); send_dits(2); break;
      case 'M': send_the_dits_and_dahs("--");break;//send_dahs(2); break;
      case 'N': send_the_dits_and_dahs("-.");break;//send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); break;
      case 'O': send_the_dits_and_dahs("---");break;//send_dahs(3); break;
      case 'P': send_the_dits_and_dahs(".--.");break;//send_dit(AUTOMATIC_SENDING); send_dahs(2); send_dit(AUTOMATIC_SENDING); break;
      case 'Q': send_the_dits_and_dahs("--.-");break;//send_dahs(2); send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); break;
      case 'R': send_the_dits_and_dahs(".-.");break;//send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); break;
      case 'S': send_the_dits_and_dahs("...");break;//send_dits(3); break;
      case 'T': send_the_dits_and_dahs("-");break;//send_dah(AUTOMATIC_SENDING); break;
      case 'U': send_the_dits_and_dahs("..-");break;//send_dits(2); send_dah(AUTOMATIC_SENDING); break;
      case 'V': send_the_dits_and_dahs("...-");break;//send_dits(3); send_dah(AUTOMATIC_SENDING); break;
      case 'W': send_the_dits_and_dahs(".--");break;//send_dit(AUTOMATIC_SENDING); send_dahs(2); break;
      case 'X': send_the_dits_and_dahs("-..-");break;//send_dah(AUTOMATIC_SENDING); send_dits(2); send_dah(AUTOMATIC_SENDING); break;
      case 'Y': send_the_dits_and_dahs("-.--");break;//send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); send_dahs(2); break;
      case 'Z': send_the_dits_and_dahs("--..");break;//send_dahs(2); send_dits(2); break;

      case '0': send_the_dits_and_dahs("-----");break;//send_dahs(5); break;
      case '1': send_the_dits_and_dahs(".----");break;//send_dit(AUTOMATIC_SENDING); send_dahs(4); break;
      case '2': send_the_dits_and_dahs("..---");break;//send_dits(2); send_dahs(3); break;
      case '3': send_the_dits_and_dahs("...--");break;//send_dits(3); send_dahs(2); break;
      case '4': send_the_dits_and_dahs("....-");break;//send_dits(4); send_dah(AUTOMATIC_SENDING); break;
      case '5': send_the_dits_and_dahs(".....");break;//send_dits(5); break;
      case '6': send_the_dits_and_dahs("-....");break;//send_dah(AUTOMATIC_SENDING); send_dits(4); break;
      case '7': send_the_dits_and_dahs("--...");break;//send_dahs(2); send_dits(3); break;
      case '8': send_the_dits_and_dahs("---..");break;//send_dahs(3); send_dits(2); break;
      case '9': send_the_dits_and_dahs("----.");break;//send_dahs(4); send_dit(AUTOMATIC_SENDING); break;

      case '=': send_the_dits_and_dahs("-...-");break;//send_dah(AUTOMATIC_SENDING); send_dits(3); send_dah(AUTOMATIC_SENDING); break;
      case '/': send_the_dits_and_dahs("-..-.");break;//send_dah(AUTOMATIC_SENDING); send_dits(2); send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); break;
      case ' ': loop_element_lengths((configuration.length_wordspace-length_letterspace-2),0,configuration.wpm,AUTOMATIC_SENDING); break;
      case '*': send_the_dits_and_dahs("-...-.-");break;//send_dah(AUTOMATIC_SENDING); send_dits(3); send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); break;    // using asterisk for BK
      //case '&': send_dit(AUTOMATIC_SENDING); loop_element_lengths(3); send_dits(3); break;
      case '.': send_the_dits_and_dahs(".-.-.-");break;//send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); break;
      case ',': send_the_dits_and_dahs("--..--");break;//send_dahs(2); send_dits(2); send_dahs(2); break;
      case '\'': send_the_dits_and_dahs(".----.");break;//send_dit(AUTOMATIC_SENDING); send_dahs(4); send_dit(AUTOMATIC_SENDING); break;                   // apostrophe
      case '!': send_the_dits_and_dahs("-.-.--");break;//send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); send_dahs(2); break;
      case '(': send_the_dits_and_dahs("-.--.");break;//send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); send_dahs(2); send_dit(AUTOMATIC_SENDING); break;
      case ')': send_the_dits_and_dahs("-.--.-");break;//send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); send_dahs(2); send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); break;
      case '&': send_the_dits_and_dahs(".-...");break;//send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); send_dits(3); break;
      case ':': send_the_dits_and_dahs("---...");break;//send_dahs(3); send_dits(3); break;
      case ';': send_the_dits_and_dahs("-.-.-.");break;//send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); break;
      case '+': send_the_dits_and_dahs(".-.-.");break;//send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); break;
      case '-': send_the_dits_and_dahs("-....-");break;//send_dah(AUTOMATIC_SENDING); send_dits(4); send_dah(AUTOMATIC_SENDING); break;
      case '_': send_the_dits_and_dahs("..--.-");break;//send_dits(2); send_dahs(2); send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); break;
      case '"': send_the_dits_and_dahs(".-..-.");break;//send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); send_dits(2); send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); break;
      case '$': send_the_dits_and_dahs("...-..-");break;//send_dits(3); send_dah(AUTOMATIC_SENDING); send_dits(2); send_dah(AUTOMATIC_SENDING); break;
      case '@': send_the_dits_and_dahs(".--.-.");break;//send_dit(AUTOMATIC_SENDING); send_dahs(2); send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); break;
      case '<': send_the_dits_and_dahs(".-.-.");break;//send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); break;     // AR
      case '>': send_the_dits_and_dahs("...-.-");break;//send_dits(3); send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); break;               // SK
      case '\n':
      case '\r': break;
      
      #ifdef OPTION_NON_ENGLISH_EXTENSIONS
      case 192: send_the_dits_and_dahs(".--.-");break;//send_dit(AUTOMATIC_SENDING);send_dahs(2);send_dit(AUTOMATIC_SENDING);send_dah(AUTOMATIC_SENDING); break; // 'À'
      case 194: send_the_dits_and_dahs(".-.-");break;//send_dit(AUTOMATIC_SENDING);send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); break; // 'Â'
      case 197: send_the_dits_and_dahs(".--.-");break;//send_dit(AUTOMATIC_SENDING);send_dahs(2);send_dit(AUTOMATIC_SENDING);send_dah(AUTOMATIC_SENDING); break; // 'Å' / 
      case 196: send_the_dits_and_dahs(".-.-");break;//send_dit(AUTOMATIC_SENDING);send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); break; // 'Ä'
      case 198: send_the_dits_and_dahs(".-.-");break;//send_dit(AUTOMATIC_SENDING);send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); break; // 'Æ'
      case 199: send_the_dits_and_dahs("-.-..");break;//send_dah(AUTOMATIC_SENDING);send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); send_dits(2); break;  // 'Ç'
      case 208: send_the_dits_and_dahs("..--.");break;//send_dits(2);send_dahs(2);send_dit(AUTOMATIC_SENDING);break;  // 'Ð'
      case 138: send_the_dits_and_dahs("----");break;//send_dahs(4);break; // 'Š'
      case 200: send_the_dits_and_dahs(".-..-");break;//send_dit(AUTOMATIC_SENDING);send_dah(AUTOMATIC_SENDING);send_dits(2);send_dah(AUTOMATIC_SENDING); break; // 'È'
      case 201: send_the_dits_and_dahs("..-..");break;//send_dits(2);send_dah(AUTOMATIC_SENDING);send_dits(2);break; // 'É'
      case 142: send_the_dits_and_dahs("--..-.");break;//send_dahs(2);send_dits(2);send_dah(AUTOMATIC_SENDING);send_dit(AUTOMATIC_SENDING);break; // 'Ž'
      case 209: send_the_dits_and_dahs("--.--");break;//send_dahs(2);send_dit(AUTOMATIC_SENDING);send_dahs(2);break; // 'Ñ'
      case 214: send_the_dits_and_dahs("---.");break;//send_dahs(3);send_dit(AUTOMATIC_SENDING);break; // 'Ö'
      case 216: send_the_dits_and_dahs("---.");break;//send_dahs(3);send_dit(AUTOMATIC_SENDING);break; // 'Ø'
      case 211: send_the_dits_and_dahs("---.");break;//send_dahs(3);send_dit(AUTOMATIC_SENDING);break; // 'Ó'
      case 220: send_the_dits_and_dahs("..--");break;//send_dits(2);send_dahs(2);break; // 'Ü'
      case 223: send_the_dits_and_dahs("------");break;//send_dits(6);break; // 'ß'

      // for English/Japanese font LCD controller which has a few European characters also (HD44780UA00) (LA3ZA code)
      case 225: send_the_dits_and_dahs(".-.-");break;//send_dit(AUTOMATIC_SENDING);send_dah(AUTOMATIC_SENDING); send_dit(AUTOMATIC_SENDING); send_dah(AUTOMATIC_SENDING); break; // 'ä' LA3ZA
      case 239: send_the_dits_and_dahs("---.");break;//send_dahs(3);send_dit(AUTOMATIC_SENDING);break; // 'ö' LA3ZA
      case 242: send_the_dits_and_dahs("---.");break;//send_dahs(3);send_dit(AUTOMATIC_SENDING);break; // 'ø' LA3ZA
      case 245: send_the_dits_and_dahs("..--");break;//send_dits(2);send_dahs(2);break; // 'ü' LA3ZA
      case 246: send_the_dits_and_dahs("----");break;//send_dahs(4);break; // almost '' or rather sigma LA3ZA
      case 252: send_the_dits_and_dahs(".--.-");break;//send_dit(AUTOMATIC_SENDING);send_dahs(2);send_dit(AUTOMATIC_SENDING);send_dah(AUTOMATIC_SENDING); break; // å (sort of) LA3ZA
      case 238: send_the_dits_and_dahs("--.--");break;//send_dahs(2);send_dit(AUTOMATIC_SENDING);send_dahs(2);break; // 'ñ' LA3ZA
      case 226: send_the_dits_and_dahs("------");break;//send_dits(6);break; // 'ß' LA3ZA



      #endif //OPTION_NON_ENGLISH_EXTENSIONS      
      
      case '|': loop_element_lengths(0.5,0,configuration.wpm,AUTOMATIC_SENDING); return; break;
      default: send_the_dits_and_dahs("..--..");break;//send_dits(2); send_dahs(2); send_dits(2); break;
      
    }
    if (omit_letterspace != OMIT_LETTERSPACE) {
      loop_element_lengths((length_letterspace-1),0,configuration.wpm,AUTOMATIC_SENDING); //this is minus one because send_dit and send_dah have a trailing element space
    }
  } else {
    #ifdef FEATURE_HELL
      transmit_hell_char(cw_char);
    #endif
  }

}

//-------------------------------------------------------------------------------------------------------

int uppercase (int charbytein)
{
  if (((charbytein > 96) && (charbytein < 123)) || ((charbytein > 223) && (charbytein < 255))) {
    charbytein = charbytein - 32;
  }
  if (charbytein == 158) { charbytein = 142; }  // ž -> Ž
  if (charbytein == 154) { charbytein = 138; }  // š -> Š
  
  return charbytein;
}

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_SERIAL)
#ifdef FEATURE_COMMAND_LINE_INTERFACE
void serial_qrss_mode()
{
  byte looping = 1;
  byte incoming_serial_byte;
  byte numbers[4];
  byte numberindex = 0;
  String numberstring;
  byte error =0;

  while (looping) {
    if (primary_serial_port->available() == 0) {        // wait for the next keystroke
      if (keyer_machine_mode == KEYER_NORMAL) {          // might as well do something while we're waiting
        check_paddles();
        service_dit_dah_buffers();
        //check_the_memory_buttons();
      }
    } else {

      incoming_serial_byte = primary_serial_port->read();
      if ((incoming_serial_byte > 47) && (incoming_serial_byte < 58)) {    // ascii 48-57 = "0" - "9")
        numberstring = numberstring + incoming_serial_byte;
        numbers[numberindex] = incoming_serial_byte;
//        primary_serial_port->write("numberindex:");
//        primary_serial_port->print(numberindex,DEC);
//        primary_serial_port->write("     numbers:");
//        primary_serial_port->println(numbers[numberindex],DEC);
        numberindex++;
        if (numberindex > 2)
          {
            looping = 0;
            error = 1;
          }
      } else {
        if (incoming_serial_byte == 13) {   // carriage return - get out
          looping = 0;
        } else {                 // bogus input - error out
          looping = 0;
          error = 1;
        }
      }
    }
  }

  if (error) {
    primary_serial_port->println(F("Error..."));
    while (primary_serial_port->available() > 0) { incoming_serial_byte = primary_serial_port->read(); }  // clear out buffer
    return;
  } else {
    primary_serial_port->print(F("Setting keyer to QRSS Mode. Dit length: "));
    primary_serial_port->print(numberstring);
    primary_serial_port->println(F(" seconds"));
    int y = 1;
    int set_dit_length = 0;
    for (int x = (numberindex - 1); x >= 0 ; x = x - 1) {
      set_dit_length = set_dit_length + ((numbers[x]-48) * y);
      y = y * 10;
    }
    qrss_dit_length = set_dit_length;
    speed_mode = SPEED_QRSS;
    //calculate_element_length();
  }

}
#endif
#endif
//-------------------------------------------------------------------------------------------------------

void service_send_buffer(byte no_print)
{
  // send one character out of the send buffer
  // values 200 and above do special things
  // 200 - SERIAL_SEND_BUFFER_WPM_CHANGE - next two bytes are new speed
  // 201 - SERIAL_SEND_BUFFER_PTT_ON
  // 202 - SERIAL_SEND_BUFFER_PTT_OFF
  // 203 - SERIAL_SEND_BUFFER_TIMED_KEY_DOWN
  // 204 - SERIAL_SEND_BUFFER_TIMED_WAIT
  // 205 - SERIAL_SEND_BUFFER_NULL
  // 206 - SERIAL_SEND_BUFFER_PROSIGN
  // 207 - SERIAL_SEND_BUFFER_HOLD_SEND
  // 208 - SERIAL_SEND_BUFFER_HOLD_SEND_RELEASE
  // 210 - SERIAL_SEND_BUFFER_MEMORY_NUMBER - next byte is memory number to play

  #ifdef DEBUG_LOOP
    debug_serial_port->println(F("loop: entering service_send_buffer"));
  #endif          

  #ifdef FEATURE_MEMORIES
    play_memory_prempt = 0;
  #endif

  static unsigned long timed_command_end_time;
  static byte timed_command_in_progress = 0;

  if (send_buffer_status == SERIAL_SEND_BUFFER_NORMAL) {
    if ((send_buffer_bytes > 0) && (pause_sending_buffer == 0)) {
      #ifdef FEATURE_SLEEP
        last_activity_time = millis(); 
      #endif //FEATURE_SLEEP
      if ((send_buffer_array[0] > SERIAL_SEND_BUFFER_SPECIAL_START) && (send_buffer_array[0] < SERIAL_SEND_BUFFER_SPECIAL_END)) {

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_HOLD_SEND) {
          send_buffer_status = SERIAL_SEND_BUFFER_HOLD;
          remove_from_send_buffer();
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_HOLD_SEND_RELEASE) {
          remove_from_send_buffer();
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_MEMORY_NUMBER) {
          #ifdef DEBUG_SEND_BUFFER
            debug_serial_port->println(F("service_send_buffer: SERIAL_SEND_BUFFER_MEMORY_NUMBER"));
          #endif
          #ifdef FEATURE_WINKEY_EMULATION
            if (winkey_sending && winkey_host_open) {
              winkey_port_write(0xc0|winkey_sending|winkey_xoff);
              winkey_interrupted = 1;
             }
          #endif
          remove_from_send_buffer();
          if (send_buffer_bytes > 0) {
            if (send_buffer_array[0] < number_of_memories) {
              #ifdef FEATURE_MEMORIES
              play_memory(send_buffer_array[0]);
              #endif
            }
            remove_from_send_buffer();
          }
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_WPM_CHANGE) {  // two bytes for wpm
          remove_from_send_buffer();
          if (send_buffer_bytes > 1) {
            configuration.wpm = send_buffer_array[0] * 256;
            remove_from_send_buffer();
            configuration.wpm = configuration.wpm + send_buffer_array[0];
            remove_from_send_buffer();
            
            #ifdef FEATURE_LED_RING
            update_led_ring();
            #endif //FEATURE_LED_RING            
            
          }
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_NULL) {
          remove_from_send_buffer();
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_PROSIGN) {
          remove_from_send_buffer();
          if (send_buffer_bytes > 0) {
            send_char(send_buffer_array[0],OMIT_LETTERSPACE);
            remove_from_send_buffer();
          }
          if (send_buffer_bytes > 0) {
            send_char(send_buffer_array[0],KEYER_NORMAL);
            remove_from_send_buffer();
          }
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_TIMED_KEY_DOWN) {
          remove_from_send_buffer();
          if (send_buffer_bytes > 0) {
            send_buffer_status = SERIAL_SEND_BUFFER_TIMED_COMMAND;
            tx_and_sidetone_key(1,AUTOMATIC_SENDING);
            timed_command_end_time = millis() + (send_buffer_array[0] * 1000);
            timed_command_in_progress = SERIAL_SEND_BUFFER_TIMED_KEY_DOWN;
            remove_from_send_buffer();
          }
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_TIMED_WAIT) {
          remove_from_send_buffer();
          if (send_buffer_bytes > 0) {
            send_buffer_status = SERIAL_SEND_BUFFER_TIMED_COMMAND;
            timed_command_end_time = millis() + (send_buffer_array[0] * 1000);
            timed_command_in_progress = SERIAL_SEND_BUFFER_TIMED_WAIT;
            remove_from_send_buffer();
          }
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_PTT_ON) {
          remove_from_send_buffer();
          manual_ptt_invoke = 1;
          ptt_key();
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_PTT_OFF) {
          remove_from_send_buffer();
          manual_ptt_invoke = 0;

          ptt_unkey();
        }
      } else {
        #ifdef FEATURE_WINKEY_EMULATION
          if ((primary_serial_port_mode == SERIAL_WINKEY_EMULATION) && (winkey_serial_echo) && (winkey_host_open) && (!no_print) && (!cw_send_echo_inhibit)){
            winkey_port_write(send_buffer_array[0]);
            if (send_buffer_array[0] == 13) {
              winkey_port_write(10);  // if we got a carriage return, also send a line feed          
            }
          }
        #endif //FEATURE_WINKEY_EMULATION


        #if defined(FEATURE_COMMAND_LINE_INTERFACE)
          if ((!no_print) && (!cw_send_echo_inhibit)){
            if (primary_serial_port_mode == SERIAL_CLI) {primary_serial_port->write(send_buffer_array[0]);};
            #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
              secondary_serial_port->write(send_buffer_array[0]);
            #endif //FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
            if (send_buffer_array[0] == 13) {
              if (primary_serial_port_mode == SERIAL_CLI) {primary_serial_port->write(10);}  // if we got a carriage return, also send a line feed
              #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
                secondary_serial_port->write(10);
              #endif //FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT              
            }
          }
        #endif //FEATURE_COMMAND_LINE_INTERFACE





        #ifdef FEATURE_DISPLAY
          if (lcd_send_echo) {
            display_scroll_print_char(send_buffer_array[0]);
            service_display();
          }
        #endif //FEATURE_DISPLAY
        send_char(send_buffer_array[0],KEYER_NORMAL);
        remove_from_send_buffer();
      }
    }

  } else {

    if (send_buffer_status == SERIAL_SEND_BUFFER_TIMED_COMMAND) {    // we're in a timed command

      if ((timed_command_in_progress == SERIAL_SEND_BUFFER_TIMED_KEY_DOWN) && (millis() > timed_command_end_time)) {
        tx_and_sidetone_key(0,AUTOMATIC_SENDING);
        timed_command_in_progress = 0;
        send_buffer_status = SERIAL_SEND_BUFFER_NORMAL;
      }

      if ((timed_command_in_progress == SERIAL_SEND_BUFFER_TIMED_WAIT) && (millis() > timed_command_end_time)) {
        timed_command_in_progress = 0;
        send_buffer_status = SERIAL_SEND_BUFFER_NORMAL;
      }

    }

    if (send_buffer_status == SERIAL_SEND_BUFFER_HOLD) {  // we're in a send hold ; see if there's a SERIAL_SEND_BUFFER_HOLD_SEND_RELEASE in the buffer
      if (send_buffer_bytes == 0) {
        send_buffer_status = SERIAL_SEND_BUFFER_NORMAL;  // this should never happen, but what the hell, we'll catch it here if it ever does happen
      } else {
        for (int z = 0; z < send_buffer_bytes; z++) {
          if (send_buffer_array[z] ==  SERIAL_SEND_BUFFER_HOLD_SEND_RELEASE) {
            send_buffer_status = SERIAL_SEND_BUFFER_NORMAL;
            z = send_buffer_bytes;
          }
        }
      }
    }

  }

  //if the paddles are hit, dump the buffer
  check_paddles();
  if ((dit_buffer || dah_buffer) && (send_buffer_bytes  > 0)) {
    clear_send_buffer();
    send_buffer_status = SERIAL_SEND_BUFFER_NORMAL;
    dit_buffer = 0;
    dah_buffer = 0;    
    #ifdef FEATURE_MEMORIES
      repeat_memory = 255;
    #endif
    #ifdef FEATURE_WINKEY_EMULATION
    if (winkey_sending && winkey_host_open) {
      winkey_port_write(0xc2|winkey_sending|winkey_xoff); // 0xc2 - BREAKIN bit set high
      winkey_interrupted = 1;
    }
    #endif
  }

}

//-------------------------------------------------------------------------------------------------------
void clear_send_buffer()
{
  #ifdef FEATURE_WINKEY_EMULATION
    winkey_xoff=0;
  #endif 
  send_buffer_bytes = 0;
}

//-------------------------------------------------------------------------------------------------------
void remove_from_send_buffer()
{
  
  #ifdef FEATURE_WINKEY_EMULATION
    if ((send_buffer_bytes < winkey_xon_threshold) && winkey_xoff && winkey_host_open) {
      winkey_xoff=0;
      winkey_port_write(0xc0|winkey_sending|winkey_xoff); //send status /XOFF
    }
  #endif
  
  if (send_buffer_bytes > 0) {
    send_buffer_bytes--;
  }
  if (send_buffer_bytes > 0) {
    for (int x = 0;x < send_buffer_bytes;x++) {
      send_buffer_array[x] = send_buffer_array[x+1];
    }
    #if defined(FEATURE_WINKEY_EMULATION) && defined(OPTION_WINKEY_FREQUENT_STATUS_REPORT)
      winkey_port_write(0xc0|winkey_sending|winkey_xoff);
   #endif
  }
}

//-------------------------------------------------------------------------------------------------------

void add_to_send_buffer(byte incoming_serial_byte)
{
//  if ((incoming_serial_byte == SERIAL_SEND_BUFFER_HOLD_SEND_RELEASE) && (send_buffer_status == SERIAL_SEND_BUFFER_HOLD)) {
//    send_buffer_status = SERIAL_SEND_BUFFER_NORMAL;
//  } else {
    if (send_buffer_bytes < send_buffer_size) {
      if (incoming_serial_byte != 127) {
        send_buffer_bytes++;
        send_buffer_array[send_buffer_bytes - 1] = incoming_serial_byte;
        
        #ifdef FEATURE_WINKEY_EMULATION
        if ((send_buffer_bytes>winkey_xoff_threshold) && winkey_host_open) {
          winkey_xoff=1;
          winkey_port_write(0xc0|winkey_sending|winkey_xoff); //send XOFF status         
        }
        #endif
              
      } else {  // we got a backspace
        send_buffer_bytes--;
      }
    }
//  }
}

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_WINKEY_EMULATION
void winkey_unbuffered_speed_command(byte incoming_serial_byte) {

  if (incoming_serial_byte == 0) {
    #ifdef FEATURE_POTENTIOMETER
      configuration.pot_activated = 1;
    #endif
  } else {
    configuration.wpm = incoming_serial_byte;
    winkey_last_unbuffered_speed_wpm = configuration.wpm;
    //calculate_element_length();
    #ifdef OPTION_WINKEY_STRICT_EEPROM_WRITES_MAY_WEAR_OUT_EEPROM
    config_dirty = 1;
    #endif
    
    #ifdef FEATURE_LED_RING
    update_led_ring();
    #endif //FEATURE_LED_RING    
    
  }

}
#endif //FEATURE_WINKEY_EMULATION

//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_WINKEY_EMULATION
void winkey_farnsworth_command(byte incoming_serial_byte) {

  #ifdef FEATURE_FARNSWORTH
  if ((incoming_serial_byte > 9) && (incoming_serial_byte < 100)) {
    configuration.wpm_farnsworth = incoming_serial_byte;
  }
  #endif //FEATURE_FFARNSWORTH

}
#endif //FEATURE_WINKEY_EMULATION

//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_WINKEY_EMULATION
void winkey_keying_compensation_command(byte incoming_serial_byte) {

  keying_compensation = incoming_serial_byte;
}
#endif //FEATURE_WINKEY_EMULATION

//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_WINKEY_EMULATION
void winkey_first_extension_command(byte incoming_serial_byte) {

  first_extension_time = incoming_serial_byte;
  #ifdef DEBUG_WINKEY_PROTOCOL
  send_char('X',KEYER_NORMAL);
  #endif
}
#endif //FEATURE_WINKEY_EMULATION

//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_WINKEY_EMULATION
void winkey_dah_to_dit_ratio_command(byte incoming_serial_byte) {

  if ((incoming_serial_byte > 32) && (incoming_serial_byte < 67)) {
    configuration.dah_to_dit_ratio = (300*(float(incoming_serial_byte)/50));
    #ifdef OPTION_WINKEY_STRICT_EEPROM_WRITES_MAY_WEAR_OUT_EEPROM
    config_dirty = 1;
    #endif
  }

}
#endif //FEATURE_WINKEY_EMULATION

//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_WINKEY_EMULATION
void winkey_weighting_command(byte incoming_serial_byte) {

  if ((incoming_serial_byte > 9) && (incoming_serial_byte < 91)) {
    configuration.weighting = incoming_serial_byte;
  }

}
#endif //FEATURE_WINKEY_EMULATION
//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_WINKEY_EMULATION
void winkey_ptt_times_parm1_command(byte incoming_serial_byte) {
  ptt_lead_time[configuration.current_tx-1] = (incoming_serial_byte*10);
  #ifdef DEBUG_WINKEY_PROTOCOL
  send_char('P',KEYER_NORMAL);
  send_char('1',KEYER_NORMAL);
  #endif
}
#endif //FEATURE_WINKEY_EMULATION
//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_WINKEY_EMULATION
void winkey_ptt_times_parm2_command(byte incoming_serial_byte) {

  ptt_tail_time[configuration.current_tx-1] = (incoming_serial_byte*10);
  #ifdef DEBUG_WINKEY_PROTOCOL
  send_char('P',KEYER_NORMAL);
  send_char('2',KEYER_NORMAL);
  #endif
}
#endif //FEATURE_WINKEY_EMULATION
//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_WINKEY_EMULATION
void winkey_set_pot_parm1_command(byte incoming_serial_byte) {

  //#ifdef FEATURE_POTENTIOMETER
  pot_wpm_low_value = incoming_serial_byte;
  //#endif
}
#endif //FEATURE_WINKEY_EMULATION
//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_WINKEY_EMULATION
void winkey_set_pot_parm2_command(byte incoming_serial_byte) {
  #ifdef FEATURE_POTENTIOMETER
  pot_wpm_high_value = (pot_wpm_low_value + incoming_serial_byte);
  #endif
}
#endif //FEATURE_WINKEY_EMULATION
//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_WINKEY_EMULATION
void winkey_set_pot_parm3_command (byte incoming_serial_byte) {

  #ifdef FEATURE_POTENTIOMETER
  #ifdef OPTION_WINKEY_2_SUPPORT
  pot_full_scale_reading = 1031;
  #else //OPTION_WINKEY_2_SUPPORT
  if (incoming_serial_byte == 255) {
    pot_full_scale_reading = 1031;
  } else {
    if (incoming_serial_byte == 127) {
      pot_full_scale_reading = 515;
    }
  }
  #endif //OPTION_WINKEY_2_SUPPORT
  configuration.pot_activated = 1;
  #endif
}
#endif //FEATURE_WINKEY_EMULATION

//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_WINKEY_EMULATION
void winkey_setmode_command(byte incoming_serial_byte) {

  #ifdef OPTION_WINKEY_STRICT_EEPROM_WRITES_MAY_WEAR_OUT_EEPROM
  config_dirty = 1;
  #endif
  if (incoming_serial_byte & 4) {  //serial echo enable
    #ifdef DEBUG_WINKEY_PROTOCOL
    send_char('S',KEYER_NORMAL);
    #endif
    winkey_serial_echo = 1;
  } else {
    winkey_serial_echo = 0;
  }
  if (incoming_serial_byte & 8) {  //paddle_swap
     configuration.paddle_mode = PADDLE_REVERSE;
  } else {
     configuration.paddle_mode = PADDLE_NORMAL;
  }
  switch (incoming_serial_byte & 48) {
    case 0: configuration.keyer_mode = IAMBIC_B;
      #ifdef DEBUG_WINKEY_PROTOCOL
      send_char('B',KEYER_NORMAL);
      #endif
      break;
    case 16: configuration.keyer_mode = IAMBIC_A;
      #ifdef DEBUG_WINKEY_PROTOCOL
      send_char('A',KEYER_NORMAL);
      #endif
      break;
    case 32: configuration.keyer_mode = ULTIMATIC;
      #ifdef DEBUG_WINKEY_PROTOCOL
      send_char('U',KEYER_NORMAL);
      #endif
      break;
    case 48: configuration.keyer_mode = BUG;
      #ifdef DEBUG_WINKEY_PROTOCOL
      send_char('G',KEYER_NORMAL);
      #endif
      break;
  }
  #ifdef FEATURE_DEAD_OP_WATCHDOG
  if ((incoming_serial_byte & 128) == 128) {  //1xxxxxxx = paddle watchdog
     dead_op_watchdog_active = 1;
  } else {
     dead_op_watchdog_active = 0;
  }
  #endif
  #ifdef FEATURE_AUTOSPACE
  if ((incoming_serial_byte & 2) == 2) {  //xxxxxx1x = autospace
     configuration.autospace_active = 1;
     #ifdef DEBUG_WINKEY_PROTOCOL
     send_char('T',KEYER_NORMAL);
     #endif
  } else {
     configuration.autospace_active = 0;
  }
  #endif
  if ((incoming_serial_byte & 128) == 128) {  //xxxxxxx1 = contest wordspace
     configuration.length_wordspace = 6;
  } else {
     configuration.length_wordspace = 7;
  }

  if ((incoming_serial_byte & 64) == 64) {  //x1xxxxxx = paddle echo
     winkey_paddle_echo_activated = 1;
  } else {
     winkey_paddle_echo_activated = 0;
  }

}

#endif //FEATURE_WINKEY_EMULATION

//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_WINKEY_EMULATION
void winkey_sidetone_freq_command(byte incoming_serial_byte) {
  
  #ifdef OPTION_WINKEY_2_SUPPORT
  if (incoming_serial_byte & 128) {
    if (configuration.sidetone_mode == SIDETONE_ON) {configuration.sidetone_mode = SIDETONE_PADDLE_ONLY;}
    wk2_paddle_only_sidetone = 1;
  } else {
    if (configuration.sidetone_mode == SIDETONE_PADDLE_ONLY) {configuration.sidetone_mode = SIDETONE_ON;}
    wk2_paddle_only_sidetone = 0;
  }
  #endif
  
  switch (incoming_serial_byte & 15) {
    case 1: configuration.hz_sidetone = WINKEY_SIDETONE_1; break;
    case 2: configuration.hz_sidetone = WINKEY_SIDETONE_2; break;
    case 3: configuration.hz_sidetone = WINKEY_SIDETONE_3; break;
    case 4: configuration.hz_sidetone = WINKEY_SIDETONE_4; break;
    case 5: configuration.hz_sidetone = WINKEY_SIDETONE_5; break;
    case 6: configuration.hz_sidetone = WINKEY_SIDETONE_6; break;
    case 7: configuration.hz_sidetone = WINKEY_SIDETONE_7; break;
    case 8: configuration.hz_sidetone = WINKEY_SIDETONE_8; break;
    case 9: configuration.hz_sidetone = WINKEY_SIDETONE_9; break;
    case 10: configuration.hz_sidetone = WINKEY_SIDETONE_10; break;
  }
  #ifdef OPTION_WINKEY_STRICT_EEPROM_WRITES_MAY_WEAR_OUT_EEPROM
  config_dirty = 1;
  #endif

}
#endif //FEATURE_WINKEY_EMULATION

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_WINKEY_EMULATION
void winkey_set_pinconfig_command(byte incoming_serial_byte) {
  
  if (incoming_serial_byte & 2) {
    #ifdef OPTION_WINKEY_2_SUPPORT
    if (wk2_paddle_only_sidetone) {
      configuration.sidetone_mode = SIDETONE_PADDLE_ONLY;
    } else {
    #endif
      configuration.sidetone_mode = SIDETONE_ON;
    #ifdef OPTION_WINKEY_2_SUPPORT
    }
    #endif
  } else {
    configuration.sidetone_mode = SIDETONE_OFF;
  }
  
  switch (incoming_serial_byte & 192) {
    case 0:  ultimatic_mode = ULTIMATIC_NORMAL; break;
    case 64: ultimatic_mode = ULTIMATIC_DAH_PRIORITY; break;
    case 128: ultimatic_mode = ULTIMATIC_DIT_PRIORITY; break;
  }

  switch(incoming_serial_byte & 48) {
    case 0: ptt_hang_time_wordspace_units = WINKEY_HANG_TIME_1_0; break;
    case 16: ptt_hang_time_wordspace_units = WINKEY_HANG_TIME_1_33; break;
    case 32: ptt_hang_time_wordspace_units = WINKEY_HANG_TIME_1_66; break;
    case 48: ptt_hang_time_wordspace_units = WINKEY_HANG_TIME_2_0; break;
  }

  switch(incoming_serial_byte & 12) {
    case 0:
      key_tx = 0; 
      #ifdef OPTION_WINKEY_2_SUPPORT
      wk2_both_tx_activated = 0;
      #endif
      break;
    case 4: 
      key_tx = 1;
      configuration.current_ptt_line = ptt_tx_1; 
      current_tx_key_line = tx_key_line_1;
      configuration.current_tx = 1;
      #ifdef OPTION_WINKEY_2_SUPPORT
      wk2_both_tx_activated = 0;
      #endif
      break;
    case 8: 
      key_tx = 1;
      if (ptt_tx_2) {
        configuration.current_ptt_line = ptt_tx_2;
      } else {
        configuration.current_ptt_line = ptt_tx_1;
      }
      if (tx_key_line_2) {
        current_tx_key_line = tx_key_line_2;
      } else {
        current_tx_key_line = tx_key_line_1;
      }
      #ifdef OPTION_WINKEY_2_SUPPORT
      wk2_both_tx_activated = 0;
      #endif
      break;
    case 12:
      key_tx = 1;
      configuration.current_ptt_line = ptt_tx_1;
      current_tx_key_line = tx_key_line_1; 
      configuration.current_tx = 1;
      #ifdef OPTION_WINKEY_2_SUPPORT
      wk2_both_tx_activated = 1;
      #endif
      break;
    }

}
#endif

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_WINKEY_EMULATION
void winkey_load_settings_command(byte winkey_status,byte incoming_serial_byte) {

  switch(winkey_status) {
     case WINKEY_LOAD_SETTINGS_PARM_1_COMMAND:
       winkey_setmode_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_2_COMMAND:
       winkey_unbuffered_speed_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_3_COMMAND:
       winkey_sidetone_freq_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_4_COMMAND:
       winkey_weighting_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_5_COMMAND:
       winkey_ptt_times_parm1_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_6_COMMAND:
       winkey_ptt_times_parm2_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_7_COMMAND:
       winkey_set_pot_parm1_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_8_COMMAND:
       winkey_set_pot_parm2_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_9_COMMAND:
       winkey_first_extension_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_10_COMMAND:
       winkey_keying_compensation_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_11_COMMAND:
       winkey_farnsworth_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_12_COMMAND:  // paddle switchpoint - don't need to support

       break;
     case WINKEY_LOAD_SETTINGS_PARM_13_COMMAND:
       winkey_dah_to_dit_ratio_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_14_COMMAND:
       winkey_set_pinconfig_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_15_COMMAND:
       winkey_set_pot_parm3_command(incoming_serial_byte);
       break;
  }
}
#endif

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_WINKEY_EMULATION
void winkey_admin_get_values_command() {

  byte byte_to_send;

  // 1 - mode register
  byte_to_send = 0;
  if (configuration.length_wordspace != default_length_wordspace) {
    byte_to_send = byte_to_send | 1;
  }
  #ifdef FEATURE_AUTOSPACE
  if (configuration.autospace_active) {
    byte_to_send = byte_to_send | 2;
  }
  #endif
  if (winkey_serial_echo) {
    byte_to_send = byte_to_send | 4;
  }
  if (configuration.paddle_mode == PADDLE_REVERSE) {
    byte_to_send = byte_to_send | 8;
  }
  switch (configuration.keyer_mode) {
    case IAMBIC_A: byte_to_send = byte_to_send | 16; break;
    case ULTIMATIC: byte_to_send = byte_to_send | 32; break;
    case BUG: byte_to_send = byte_to_send | 48; break;
  }
  if (winkey_paddle_echo_activated) {
    byte_to_send = byte_to_send | 64;
  }
  #ifdef FEATURE_DEAD_OP_WATCHDOG
  if (dead_op_watchdog_active) {
    byte_to_send = byte_to_send | 128;
  }
  #endif //FEATURE_DEAD_OP_WATCHDOG
  winkey_port_write(byte_to_send);

  // 2 - speed
  if (configuration.wpm > 99) {
    winkey_port_write(99);
  } else {
    byte_to_send = configuration.wpm;
    winkey_port_write(byte_to_send);
  }

  // 3 - sidetone
  switch(configuration.hz_sidetone) {
    case WINKEY_SIDETONE_1 : winkey_port_write(1); break;
    case WINKEY_SIDETONE_2 : winkey_port_write(2); break;
    case WINKEY_SIDETONE_3 : winkey_port_write(3); break;
    case WINKEY_SIDETONE_4 : winkey_port_write(4); break;
    case WINKEY_SIDETONE_5 : winkey_port_write(5); break;
    case WINKEY_SIDETONE_6 : winkey_port_write(6); break;
    case WINKEY_SIDETONE_7 : winkey_port_write(7); break;
    case WINKEY_SIDETONE_8 : winkey_port_write(8); break;
    case WINKEY_SIDETONE_9 : winkey_port_write(9); break;
    case WINKEY_SIDETONE_10 : winkey_port_write(10); break;
    default: winkey_port_write(5); break;
  }

  // 4 - weight
  winkey_port_write(configuration.weighting);

  // 5 - ptt lead
  winkey_port_write(zero);   // TODO - backwards calculate this

  // 6 - ptt tail
  winkey_port_write(zero);   // TODO - backwards calculate this

  // 7 - pot min wpm
  #ifdef FEATURE_POTENTIOMETER
  winkey_port_write(pot_wpm_low_value);
  #endif
  #ifndef FEATURE_POTENTIOMETER
  winkey_port_write(15);
  #endif

  // 8 - pot wpm range
  #ifdef FEATURE_POTENTIOMETER
  byte_to_send = pot_wpm_high_value - pot_wpm_low_value;
  winkey_port_write(byte_to_send);
  #endif
  #ifndef FEATURE_POTENTIOMETER
  winkey_port_write(20);
  #endif

  // 9 - 1st extension
  winkey_port_write(first_extension_time);

  // 10 - compensation
  winkey_port_write(keying_compensation);

  // 11 - farnsworth wpm
  #ifdef FEATURE_FARNSWORTH
  byte_to_send = configuration.wpm_farnsworth;
  winkey_port_write(byte_to_send);
  #endif
  #ifndef FEATURE_FARNSWORTH
  winkey_port_write(zero);
  #endif

  // 12 - paddle setpoint
  winkey_port_write(50);  // default value

  // 13 - dah to dit ratio
  winkey_port_write(50);  // TODO -backwards calculate

  // 14 - pin config
  #ifdef OPTION_WINKEY_2_SUPPORT
  byte_to_send = 0;
  if (configuration.current_ptt_line != 0) {byte_to_send = byte_to_send | 1;}
  if ((configuration.sidetone_mode == SIDETONE_ON) || (configuration.sidetone_mode == SIDETONE_PADDLE_ONLY)) {byte_to_send | 2;}
  if (current_tx_key_line == tx_key_line_1) {byte_to_send = byte_to_send | 4;}
  if (current_tx_key_line == tx_key_line_2) {byte_to_send = byte_to_send | 8;}
  if (wk2_both_tx_activated) {byte_to_send = byte_to_send | 12;}
  if (ultimatic_mode == ULTIMATIC_DIT_PRIORITY) {byte_to_send = byte_to_send | 128;}
  if (ultimatic_mode == ULTIMATIC_DAH_PRIORITY) {byte_to_send = byte_to_send | 64;}  
  if (ptt_hang_time_wordspace_units == 1.33) {byte_to_send = byte_to_send | 16;}
  if (ptt_hang_time_wordspace_units == 1.66) {byte_to_send = byte_to_send | 32;}
  if (ptt_hang_time_wordspace_units == 2.0) {byte_to_send = byte_to_send | 64;}
  winkey_port_write(byte_to_send);
  #else
  winkey_port_write(5); // default value
  #endif

  // 15 - pot range
  #ifdef OPTION_WINKEY_2_SUPPORT
  winkey_port_write(zero);
  #else
  winkey_port_write(0xFF);
  #endif

}
#endif
//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_SERIAL)
#ifdef FEATURE_WINKEY_EMULATION
#ifdef OPTION_WINKEY_2_SUPPORT
void winkey_eeprom_download() {
  
  byte zero = 0;
  unsigned int x = 0;
  //unsigned int y = 0;
  unsigned int bytes_sent = 0;
//  byte byte_read_from_eeprom = 0;
//  byte read_memory_number = 0;
//  byte memory_byte_counter = 0;
//  byte memory_sizes[5];
//  byte total_memory_sizes = 0;
//  byte previous_memories = 0;
  
  winkey_port_write(0xa5); // 01 magic byte
  winkey_admin_get_values_command(); // 02-16
  
  winkey_port_write(byte(configuration.wpm)); // 17 cmdwpm
  bytes_sent = 17;
  
  // This is a real PITA.  The K1EL Winkey 2 doesn't store memories in ASCII, so a lookup table is required
  
  // produce memory pointers
//  for (read_memory_number = 0; read_memory_number < 6; read_memory_number++) {
//    memory_byte_counter = 0;
//    for (y = (memory_start(read_memory_number)); (y < (memory_end(read_memory_number)+1)); y++) {
//      byte_read_from_eeprom = EEPROM.read(y);
//      if (byte_read_from_eeprom == 255) { // have we found the end of the memory?
//        y = (memory_end(read_memory_number)+1); // exit the loop
//      } else { 
//        memory_byte_counter++;  // count another byte
//      }
//    }
//    memory_sizes[read_memory_number] = memory_byte_counter;
//    total_memory_sizes = total_memory_sizes + memory_byte_counter;
//  }
//  
//  primary_serial_port->write((total_memory_sizes+24));  // freeptr
//  for (x = 0; x < 6; x++) { // send memory pointers
//    if (memory_sizes[x] > 0) {
//      primary_serial_port->write((memory_sizes[x]+23+previous_memories));
//      previous_memories = previous_memories + memory_sizes[x];
//    } else {
//      primary_serial_port->write(0x10);
//    }
//  }
//  
//  bytes_sent = 24;
  

  
  // dump memories
//  for (read_memory_number = 0; read_memory_number < 6; read_memory_number++) {
//    for (y = (memory_start(read_memory_number)); (y < (memory_end(read_memory_number)+1)); y++) {
//      byte_read_from_eeprom = EEPROM.read(y);
//      if (byte_read_from_eeprom == 255) {
//        y = (memory_end(read_memory_number)+1);
//      } else {
//        if ((EEPROM.read(Y+1) == 255)) {
//          primary_serial_port->write(byte_read_from_eeprom|128);  // if this is the last byte, set bit 8
//        } else {
//          primary_serial_port->write(byte_read_from_eeprom);
//        }
//        bytes_sent++;
//      }
//    }
//  }
  
  //pad the rest with zeros    
  for (x = 0;x < (256-bytes_sent); x++) {
    winkey_port_write(zero);
  }  
}
#endif
#endif
#endif

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_WINKEY_EMULATION
void winkey_port_write(byte byte_to_send){

  primary_serial_port->write(byte_to_send);
  #ifdef DEBUG_WINKEY
    debug_serial_port->print("Winkey Port TX: ");    
    if ((byte_to_send != 13) && (byte_to_send != 9) && (byte_to_send != 10)){
      debug_serial_port->write(byte_to_send);
    } else {
      debug_serial_port->print(" ");
    }
    debug_serial_port->print(" [");
    debug_serial_port->print(byte_to_send);
    debug_serial_port->println("]");
  #endif
}

#endif //FEATURE_WINKEY_EMULATION

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_WINKEY_EMULATION
void service_winkey(byte action) {

  /*
  
  Why I wrote this emulation:
  
  "The Winkey chip is $11.  We can't make the logging program a base for home brew projects. It's a contest logger."
  
  -N1MM
  
  */
  
   
  static byte winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
  static int winkey_parmcount = 0;
  static unsigned long winkey_last_activity;
  byte status_byte_to_send;
  static byte winkey_paddle_echo_space_sent = 1;
  #ifdef OPTION_N1MM_WINKEY_TAB_BUG_WORKAROUND
  static unsigned long winkey_connect_time = 0;
  #endif //OPTION_N1MM_WINKEY_TAB_BUG_WORKAROUND
  #ifdef OPTION_WINKEY_DISCARD_BYTES_AT_STARTUP
  static byte winkey_discard_bytes_init_done = 0;  
  if (!winkey_discard_bytes_init_done) {
    if (primary_serial_port->available()) {
      for (int z = winkey_discard_bytes_startup;z > 0;z--) {
        while (primary_serial_port->available() == 0) {}
        primary_serial_port->read();
      }
      winkey_discard_bytes_init_done = 1;
    }
  }
  #endif //OPTION_WINKEY_DISCARD_BYTES_AT_STARTUP
  
  #ifdef OPTION_WINKEY_IGNORE_FIRST_STATUS_REQUEST
  static byte ignored_first_status_request = 0;
  #endif //OPTION_WINKEY_IGNORE_FIRST_STATUS_REQUEST
  
  if (action == WINKEY_HOUSEKEEPING) {
    if (winkey_last_unbuffered_speed_wpm == 0) {
      winkey_last_unbuffered_speed_wpm = configuration.wpm;
    }
    // Winkey interface emulation housekeeping items
    // check to see if we were sending stuff and the buffer is clear
    if (winkey_interrupted) {   // if Winkey sending was interrupted by the paddle, look at PTT line rather than timing out to send 0xc0
      if (ptt_line_activated == 0) {
        winkey_sending = 0;
        winkey_interrupted = 0;
        //winkey_port_write(0xc2|winkey_sending|winkey_xoff);  <- this makes N1MM get borked
        winkey_port_write(0xc0|winkey_sending|winkey_xoff);    // tell the host we've sent everything
        winkey_buffer_counter = 0;
        winkey_buffer_pointer = 0;
      }
    } else {
      //if ((winkey_host_open) && (winkey_sending) && (send_buffer_bytes < 1) && ((millis() - winkey_last_activity) > winkey_c0_wait_time)) {
      if ((primary_serial_port->available() == 0) && (winkey_host_open) && (winkey_sending) && (send_buffer_bytes < 1) && ((millis() - winkey_last_activity) > winkey_c0_wait_time)) {
        #ifdef OPTION_WINKEY_SEND_WORDSPACE_AT_END_OF_BUFFER
        send_char(' ',KEYER_NORMAL);
        #endif
        //add_to_send_buffer(' ');    // this causes a 0x20 to get echoed back to host - doesn't seem to effect N1MM program
        winkey_sending = 0;
        winkey_port_write(0xc0|winkey_sending|winkey_xoff);    // tell the host we've sent everything
        winkey_buffer_counter = 0;
        winkey_buffer_pointer = 0;
      }
    }
    // failsafe check - if we've been in some command status for awhile waiting for something, clear things out
    if ((winkey_status != WINKEY_NO_COMMAND_IN_PROGRESS) && ((millis() - winkey_last_activity) > winkey_command_timeout_ms)) {
      winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      winkey_buffer_counter = 0;
      winkey_buffer_pointer = 0;
      winkey_port_write(0xc0|winkey_sending|winkey_xoff);    //send a status byte back for giggles
    }  
    if ((winkey_host_open) && (winkey_paddle_echo_buffer) && (winkey_paddle_echo_activated) && (millis() > winkey_paddle_echo_buffer_decode_time)) {
      winkey_port_write(byte(convert_cw_number_to_ascii(winkey_paddle_echo_buffer)));
      winkey_paddle_echo_buffer = 0;
      winkey_paddle_echo_buffer_decode_time = millis() + (float(600/configuration.wpm)*length_letterspace);
      winkey_paddle_echo_space_sent = 0;
    }
    if ((winkey_host_open) && (winkey_paddle_echo_buffer == 0) && (winkey_paddle_echo_activated) && (millis() > (winkey_paddle_echo_buffer_decode_time + (float(1200/configuration.wpm)*(configuration.length_wordspace-length_letterspace)))) && (!winkey_paddle_echo_space_sent)) {
      winkey_port_write(' ');
      winkey_paddle_echo_space_sent = 1;
    }
  }  // if (action == WINKEY_HOUSEKEEPING)

  if (action == SERVICE_SERIAL_BYTE) {
    #ifdef DEBUG_WINKEY
      debug_serial_port->print("Winkey Port RX: ");
      if ((incoming_serial_byte != 13) && (incoming_serial_byte != 9) && (incoming_serial_byte != 10)){
        debug_serial_port->write(incoming_serial_byte);
      } else {
        debug_serial_port->print(" ");
      }
      debug_serial_port->print(" [");
      debug_serial_port->print(incoming_serial_byte);
      debug_serial_port->println("]");
    #endif //DEBUG_WINKEY

    winkey_last_activity = millis();
    if (winkey_status == WINKEY_NO_COMMAND_IN_PROGRESS) {

      #if !defined(OPTION_WINKEY_IGNORE_LOWERCASE)
      if (incoming_serial_byte > 31) {
      #else
      if ((incoming_serial_byte > 31) && (incoming_serial_byte <97)) {
      #endif

        #if !defined(OPTION_WINKEY_IGNORE_LOWERCASE)
        if ((incoming_serial_byte > 96) && (incoming_serial_byte < 123)){incoming_serial_byte = incoming_serial_byte - 32;}
        #endif //!defined(OPTION_WINKEY_IGNORE_LOWERCASE)
      
        byte serial_buffer_position_to_overwrite;
        if (winkey_buffer_pointer > 0) {
          serial_buffer_position_to_overwrite = send_buffer_bytes - (winkey_buffer_counter - winkey_buffer_pointer) - 1;
          if ((send_buffer_bytes > 0) && (serial_buffer_position_to_overwrite < send_buffer_bytes )) {
            send_buffer_array[serial_buffer_position_to_overwrite] = incoming_serial_byte;
          }
          winkey_buffer_pointer++;
        } else {
          #ifdef OPTION_WINKEY_EXTENDED_COMMANDS
            if (incoming_serial_byte == 36) {         // Use the $ sign to escape command
              winkey_status = WINKEY_EXTENDED_COMMAND;
            } else {
          #endif //OPTION_WINKEY_EXTENDED_COMMANDS
          add_to_send_buffer(incoming_serial_byte);
          #if defined(OPTION_WINKEY_INTERRUPTS_MEMORY_REPEAT) && defined(FEATURE_MEMORIES)
            play_memory_prempt = 1;
            repeat_memory = 255;
          #endif
          winkey_buffer_counter++;
          #ifdef OPTION_WINKEY_EXTENDED_COMMANDS
           }
          #endif //OPTION_WINKEY_EXTENDED_COMMANDS
        }

        if (!winkey_sending) {
          winkey_sending=0x04;
          winkey_port_write(0xc4|winkey_sending|winkey_xoff);  // tell the client we're starting to send
          #ifdef FEATURE_MEMORIES
          repeat_memory = 255;
          #endif
        }
      } else {
        
        #ifdef OPTION_WINKEY_STRICT_HOST_OPEN
        if ((winkey_host_open) || (incoming_serial_byte == 0)) {
        #endif
        
        switch (incoming_serial_byte) {
          case 0x00:
            winkey_status = WINKEY_ADMIN_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND");
            #endif //DEBUG_WINKEY
            break;
          case 0x01:
            winkey_status = WINKEY_SIDETONE_FREQ_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_SIDETONE_FREQ_COMMAND");
            #endif //DEBUG_WINKEY               
            break;
          case 0x02:  // speed command - unbuffered
            winkey_status = WINKEY_UNBUFFERED_SPEED_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_UNBUFFERED_SPEED_COMMAND");
            #endif //DEBUG_WINKEY               
            break;
          case 0x03:  // weighting
            winkey_status = WINKEY_WEIGHTING_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_WEIGHTING_COMMAND");
            #endif //DEBUG_WINKEY               
            break;
          case 0x04: // PTT lead and tail time
            winkey_status = WINKEY_PTT_TIMES_PARM1_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_PTT_TIMES_PARM1_COMMAND");
            #endif //DEBUG_WINKEY               
            break;
          case 0x05:     // speed pot set
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_SET_POT_PARM1_COMMAND");
            #endif //DEBUG_WINKEY
            winkey_status = WINKEY_SET_POT_PARM1_COMMAND;
            break;
          case 0x06:
            winkey_status = WINKEY_PAUSE_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_PAUSE_COMMAND");
            #endif //DEBUG_WINKEY               
            break;
          case 0x07:
            #ifdef FEATURE_POTENTIOMETER
            winkey_port_write(((pot_value_wpm()-pot_wpm_low_value)|128));
            #endif
            #ifndef FEATURE_POTENTIOMETER
            winkey_port_write((byte(configuration.wpm-pot_wpm_low_value)|128));
            #endif
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: report pot");
            #endif //DEBUG_WINKEY               
            break;
          case 0x08:    // backspace command
            if (send_buffer_bytes > 0) {
              send_buffer_bytes--;
            }
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: backspace");
            #endif //DEBUG_WINKEY               
            break;
          case 0x09:
            #ifdef OPTION_N1MM_WINKEY_TAB_BUG_WORKAROUND     // this is a hack; if someone hits TAB in the send CW Window in N1MM, it sends a 0x09
            if ((millis() - winkey_connect_time) < 10000) {  // which according to the standard should be interpreted as a pinconfig command
              winkey_status = WINKEY_SET_PINCONFIG_COMMAND;  // if we've been connected for more than 10 seconds, ignore the 0x09 byte
            }
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_SET_PINCONFIG_COMMAND (N1MM bug workaround)");
            #endif //DEBUG_WINKEY             
            #else
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_SET_PINCONFIG_COMMAND");
            #endif //DEBUG_WINKEY             
            winkey_status = WINKEY_SET_PINCONFIG_COMMAND;
            #endif
            break;
          case 0x0a:                 // 0A - clear buffer - no parms
            if (winkey_sending) {
              clear_send_buffer();
              winkey_sending = 0;
              winkey_port_write(0xc0|winkey_sending|winkey_xoff);
            }
            pause_sending_buffer = 0;
            winkey_buffer_counter = 0;
            winkey_buffer_pointer = 0;
            #ifdef FEATURE_MEMORIES
            repeat_memory = 255;
            #endif
            tx_and_sidetone_key(0,AUTOMATIC_SENDING);  // N1MM program needs this for the CTRL-T tune command to work right since it issues a 0x0a
                                     // rather than 0x0b 0x00 to clear a key down - doesn't follow protocol spec
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: 0A clear buffer");
            #endif //DEBUG_WINKEY                                      
            break;
          case 0x0b:
            winkey_status = WINKEY_KEY_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_KEY_COMMAND");
            #endif //DEBUG_WINKEY              
            break;
          case 0x0c:
            winkey_status = WINKEY_HSCW_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_HSCW_COMMAND");
            #endif //DEBUG_WINKEY                 
            break;
          case 0x0d:
            winkey_status = WINKEY_FARNSWORTH_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_FARNSWORTH_COMMAND");
            #endif //DEBUG_WINKEY                 
            break;
          case 0x0e:
            winkey_status = WINKEY_SETMODE_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_SETMODE_COMMAND");
            #endif //DEBUG_WINKEY                 
            break;
          case 0x0f:  // bulk load of defaults
            winkey_status = WINKEY_LOAD_SETTINGS_PARM_1_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_LOAD_SETTINGS_PARM_1_COMMAND");
            #endif //DEBUG_WINKEY                 
            break;
          case 0x10:
            winkey_status = WINKEY_FIRST_EXTENSION_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_FIRST_EXTENSION_COMMAND");
            #endif //DEBUG_WINKEY                 
            break;
          case 0x11:
            winkey_status = WINKEY_KEYING_COMPENSATION_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_KEYING_COMPENSATION_COMMAND");
            #endif //DEBUG_WINKEY                 
            break;
          case 0x12:
            winkey_status = WINKEY_UNSUPPORTED_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: 0x12 unsupported");
            #endif //DEBUG_WINKEY     
            winkey_parmcount = 1;
            break;
          case 0x13:  // NULL command
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: 0x13 null");
            #endif //DEBUG_WINKEY               
            break;
          case 0x14:
            winkey_status = WINKEY_SOFTWARE_PADDLE_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_SOFTWARE_PADDLE_COMMAND");
            #endif //DEBUG_WINKEY                 
            break;
          case 0x15:  // report status
            #ifndef OPTION_WINKEY_IGNORE_FIRST_STATUS_REQUEST //--------------------
            status_byte_to_send = 0xc0|winkey_sending|winkey_xoff;
            if (send_buffer_status == SERIAL_SEND_BUFFER_TIMED_COMMAND) {
              status_byte_to_send = status_byte_to_send | 16;
            }
            winkey_port_write(status_byte_to_send);
            #ifdef DEBUG_WINKEY
            debug_serial_port->print("service_winkey: 0x15 rpt status: ");
            debug_serial_port->println(status_byte_to_send);
            #endif //DEBUG_WINKEY  
            #else //OPTION_WINKEY_IGNORE_FIRST_STATUS_REQUEST ------------------------
            if (ignored_first_status_request){
              status_byte_to_send = 0xc0|winkey_sending|winkey_xoff;
              if (send_buffer_status == SERIAL_SEND_BUFFER_TIMED_COMMAND) {
                status_byte_to_send = status_byte_to_send | 16;
              }
              winkey_port_write(status_byte_to_send);
              #ifdef DEBUG_WINKEY
              debug_serial_port->print("service_winkey: 0x15 rpt status: ");
              debug_serial_port->println(status_byte_to_send);
              #endif //DEBUG_WINKEY 
              } else {
                ignored_first_status_request = 1;
                #ifdef DEBUG_WINKEY
                debug_serial_port->println("service_winkey: ignored first 0x15 status request");
                #endif //DEBUG_WINKEY                
              }
            #endif //OPTION_WINKEY_IGNORE_FIRST_STATUS_REQUEST -------------------- 

            break;
          case 0x16:  // Pointer operation
            winkey_status = WINKEY_POINTER_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_POINTER_COMMAND");
            #endif //DEBUG_WINKEY                 
            break;
          case 0x17:  // dit to dah ratio
            winkey_status = WINKEY_DAH_TO_DIT_RATIO_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_DAH_TO_DIT_RATIO_COMMAND");
            #endif //DEBUG_WINKEY                 
            break;
          // start of buffered commands ------------------------------
          case 0x18:   //buffer PTT on/off
            winkey_status = WINKEY_BUFFFERED_PTT_COMMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_BUFFFERED_PTT_COMMMAND");
            #endif //DEBUG_WINKEY            
            break;
          case 0x19:
            winkey_status = WINKEY_KEY_BUFFERED_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_KEY_BUFFERED_COMMAND");
            #endif //DEBUG_WINKEY            
            break;
          case 0x1a:
            winkey_status = WINKEY_WAIT_BUFFERED_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_WAIT_BUFFERED_COMMAND");
            #endif //DEBUG_WINKEY            
            break;
          case 0x1b:
            winkey_status = WINKEY_MERGE_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_MERGE_COMMAND");
            #endif //DEBUG_WINKEY            
            break;
          case 0x1c:      // speed command - buffered
             winkey_status = WINKEY_BUFFERED_SPEED_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_BUFFERED_SPEED_COMMAND");
            #endif //DEBUG_WINKEY             
            break;
          case 0x1d:
            winkey_status = WINKEY_BUFFERED_HSCW_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_BUFFERED_HSCW_COMMAND");
            #endif //DEBUG_WINKEY            
            break;
          case 0x1e:  // cancel buffered speed command - buffered
            winkey_status = WINKEY_CANCEL_BUFFERED_SPEED_COMMAND;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_CANCEL_BUFFERED_SPEED_COMMAND");
            #endif //DEBUG_WINKEY            
            break;
          case 0x1f:  // buffered NOP - no need to do anything
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: 1F NOP");
            #endif //DEBUG_WINKEY          
            break;
        } //switch (incoming_serial_byte)
        
        #ifdef OPTION_WINKEY_STRICT_HOST_OPEN
        } //if ((winkey_host_open) || (incoming_serial_byte == 0))
        #endif
        
      }
    } else {

      if (winkey_status == WINKEY_UNSUPPORTED_COMMAND) {
        winkey_parmcount--;
        #ifdef DEBUG_WINKEY
        debug_serial_port->print("service_winkey: WINKEY_UNSUPPORTED_COMMAND winkey_parmcount:");
        debug_serial_port->println(winkey_parmcount);
        #endif //DEBUG_WINKEY          
        if (winkey_parmcount == 0) {
          winkey_port_write(0xc0|winkey_sending|winkey_xoff);           
          winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
          #ifdef DEBUG_WINKEY
          debug_serial_port->print("service_winkey: WINKEY_UNSUPPORTED_COMMAND: WINKEY_NO_COMMAND_IN_PROGRESS");
          debug_serial_port->println(winkey_parmcount);
          #endif //DEBUG_WINKEY          
        }

      }

      //WINKEY_LOAD_SETTINGS_PARM_1_COMMAND IS 101
      if ((winkey_status > 100) && (winkey_status < 116)) {   // Load Settings Command - this has 15 parameters, so we handle it a bit differently
        winkey_load_settings_command(winkey_status,incoming_serial_byte);
        winkey_status++;
        if (winkey_status > 115) {
          winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
        }
      }

      #ifdef OPTION_WINKEY_EXTENDED_COMMANDS
      if (winkey_status == WINKEY_EXTENDED_COMMAND) {  // this is for command extensions - not part of Winkey protocol
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;

      }
      #endif //OPTION_WINKEY_EXTENDED_COMMANDS

      if (winkey_status == WINKEY_SET_PINCONFIG_COMMAND) {
        winkey_set_pinconfig_command(incoming_serial_byte);
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status == WINKEY_MERGE_COMMAND) {
        #ifdef FEATURE_MEMORIES
        repeat_memory = 255;
        #endif
        add_to_send_buffer(SERIAL_SEND_BUFFER_PROSIGN);
        add_to_send_buffer(incoming_serial_byte);
        winkey_status = WINKEY_MERGE_PARM_2_COMMAND;
      } else {
        if (winkey_status == WINKEY_MERGE_PARM_2_COMMAND) {
          add_to_send_buffer(incoming_serial_byte);
          winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
        }
      }
      if (winkey_status == WINKEY_UNBUFFERED_SPEED_COMMAND) {
        winkey_unbuffered_speed_command(incoming_serial_byte);
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status == WINKEY_FARNSWORTH_COMMAND) {
        winkey_farnsworth_command(incoming_serial_byte);
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status ==  WINKEY_HSCW_COMMAND) {
        if (incoming_serial_byte == 0) {
          #ifdef FEATURE_POTENTIOMETER
            configuration.pot_activated = 1;
          #endif
        } else {
          configuration.wpm = ((incoming_serial_byte*100)/5);
          winkey_last_unbuffered_speed_wpm = configuration.wpm;
          #ifdef OPTION_WINKEY_STRICT_EEPROM_WRITES_MAY_WEAR_OUT_EEPROM
          config_dirty = 1;
          #endif
        }
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status == WINKEY_BUFFERED_SPEED_COMMAND) {
        add_to_send_buffer(SERIAL_SEND_BUFFER_WPM_CHANGE);
        add_to_send_buffer(0);
        add_to_send_buffer(incoming_serial_byte);
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status == WINKEY_BUFFERED_HSCW_COMMAND) {
        add_to_send_buffer(SERIAL_SEND_BUFFER_WPM_CHANGE);
        unsigned int send_buffer_wpm = ((incoming_serial_byte*100)/5);
        add_to_send_buffer(highByte(send_buffer_wpm));
        add_to_send_buffer(lowByte(send_buffer_wpm));
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status == WINKEY_KEY_BUFFERED_COMMAND) {
        add_to_send_buffer(SERIAL_SEND_BUFFER_TIMED_KEY_DOWN);
        add_to_send_buffer(incoming_serial_byte);
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status == WINKEY_WAIT_BUFFERED_COMMAND) {
        add_to_send_buffer(SERIAL_SEND_BUFFER_TIMED_WAIT);
        add_to_send_buffer(incoming_serial_byte);
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status == WINKEY_BUFFFERED_PTT_COMMMAND) {
        if (incoming_serial_byte) {
          add_to_send_buffer(SERIAL_SEND_BUFFER_PTT_ON);
        } else {
          add_to_send_buffer(SERIAL_SEND_BUFFER_PTT_OFF);
        }
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status == WINKEY_CANCEL_BUFFERED_SPEED_COMMAND) {
        add_to_send_buffer(SERIAL_SEND_BUFFER_WPM_CHANGE);
        add_to_send_buffer(winkey_last_unbuffered_speed_wpm);
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status == WINKEY_POINTER_01_COMMAND) { // move input pointer to new positon in overwrite mode
        winkey_buffer_pointer = incoming_serial_byte;
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status == WINKEY_POINTER_02_COMMAND) { // move input pointer to new position in append mode
        winkey_buffer_pointer = 0;
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status == WINKEY_POINTER_03_COMMAND) { // add multiple nulls to buffer
        byte serial_buffer_position_to_overwrite;
        for (byte x = incoming_serial_byte; x > 0; x--) {
          if (winkey_buffer_pointer > 0) {
            serial_buffer_position_to_overwrite = send_buffer_bytes - (winkey_buffer_counter - winkey_buffer_pointer) - 1;
            if ((send_buffer_bytes > 0) && (serial_buffer_position_to_overwrite < send_buffer_bytes )) {
              send_buffer_array[serial_buffer_position_to_overwrite] = SERIAL_SEND_BUFFER_NULL;
            }
            winkey_buffer_pointer++;
          } else {
              add_to_send_buffer(SERIAL_SEND_BUFFER_NULL);
              winkey_buffer_counter++;
          }
        }
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status == WINKEY_POINTER_COMMAND) {
        switch (incoming_serial_byte) {
          case 0x00:
            winkey_buffer_counter = 0;
            winkey_buffer_pointer = 0;
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            break;
          case 0x01:
            winkey_status = WINKEY_POINTER_01_COMMAND;
            break;
          case 0x02:
            winkey_status = WINKEY_POINTER_02_COMMAND;  // move to new position in append mode
            break;
          case 0x03:
            winkey_status = WINKEY_POINTER_03_COMMAND;
            break;
          default:
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            break;
        }
      }

      #ifdef OPTION_WINKEY_2_SUPPORT
      if (winkey_status == WINKEY_SEND_MSG) {
        if ((incoming_serial_byte > 0) && (incoming_serial_byte < 7)) {
          add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
          add_to_send_buffer(incoming_serial_byte - 1);
          #ifdef FEATURE_MEMORIES
          repeat_memory = 255;
          #endif
        }
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;  
      }
      #endif //OPTION_WINKEY_2_SUPPORT

      if (winkey_status == WINKEY_ADMIN_COMMAND) {
        switch (incoming_serial_byte) {
          case 0x00: 
            winkey_status = WINKEY_UNSUPPORTED_COMMAND;
            winkey_parmcount = 1;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: calibrate command (WINKEY_UNSUPPORTED_COMMAND) awaiting 1 parm");
            #endif //DEBUG_WINKEY            
            break;  // calibrate command
          case 0x01:
            #ifndef HARDWARE_ARDUINO_DUE
            asm volatile ("jmp 0"); /*wdt_enable(WDTO_30MS); while(1) {};*/ 
            #else //HARDWARE_ARDUINO_DUE
            setup();
            #endif //HARDWARE_ARDUINO_DUE
            break;  // reset command
          case 0x02:  // host open command - send version back to host
            #ifdef OPTION_WINKEY_2_SUPPORT
            winkey_port_write(WINKEY_2_REPORT_VERSION_NUMBER);
            #else //OPTION_WINKEY_2_SUPPORT
            winkey_port_write(WINKEY_1_REPORT_VERSION_NUMBER);
            #endif //OPTION_WINKEY_2_SUPPORT
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            winkey_host_open = 1;
            #ifdef OPTION_N1MM_WINKEY_TAB_BUG_WORKAROUND
            winkey_connect_time = millis();
            #endif
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND host open");
            #endif //DEBUG_WINKEY  
            boop_beep();             
            break;
          case 0x03: // host close command
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            winkey_host_open = 0;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND host close");
            #endif //DEBUG_WINKEY                  
            beep_boop();
            #if defined(OPTION_WINKEY_2_SUPPORT) && !defined(OPTION_WINKEY_2_HOST_CLOSE_NO_SERIAL_PORT_RESET)
            primary_serial_port->end();
            primary_serial_port->begin(1200);
            #endif
            break;
          case 0x04:  // echo command
            winkey_status = WINKEY_ADMIN_COMMAND_ECHO;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND_ECHO");
            #endif //DEBUG_WINKEY              
            break;
          case 0x05: // paddle A2D
            winkey_port_write(zero);
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: paddle A2D");
            #endif //DEBUG_WINKEY              
            break;
          case 0x06: // speed A2D
            winkey_port_write(zero);
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: speed A2D");
            #endif //DEBUG_WINKEY              
            break;
          case 0x07: // Get values
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: winkey_admin_get_values");
            #endif //DEBUG_WINKEY             
            winkey_admin_get_values_command();
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            break;
          case 0x08: // reserved
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            break;  
          case 0x09: // get cal
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: get cal");
            #endif //DEBUG_WINKEY           
            winkey_port_write(zero);
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            break;
          #ifdef OPTION_WINKEY_2_SUPPORT
          case 0x0a: // set wk1 mode
            wk2_mode = 1;
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: wk2_mode = 1");
            #endif //DEBUG_WINKEY              
            break;
          case 0x0b: // set wk2 mode
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: wk2_mode = 2");
            #endif //DEBUG_WINKEY              
            beep();
            beep();
            wk2_mode = 2;
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            break;            
          case 0x0c: // download EEPPROM 256 bytes
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: winkey_eeprom_download");
            #endif //DEBUG_WINKEY           
            winkey_eeprom_download();
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            break;  
          case 0x0d:
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: upload EEPROM");
            #endif //DEBUG_WINKEY           
            winkey_status = WINKEY_UNSUPPORTED_COMMAND;  // upload EEPROM 256 bytes
            winkey_parmcount = 256;
            break;       
          case 0x0e:
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_SEND_MSG");
            #endif //DEBUG_WINKEY          
            winkey_status = WINKEY_SEND_MSG;
            break;
          case 0x0f: // load xmode
            winkey_status = WINKEY_UNSUPPORTED_COMMAND;
            winkey_parmcount = 1;
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: load xmode");
            #endif //DEBUG_WINKEY            
            break;            
          case 0x10: // reserved
            winkey_port_write(zero);
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            break;
          case 0x11: // set high baud rate
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: set high baud rate");
            #endif //DEBUG_WINKEY            
            primary_serial_port->end();
            primary_serial_port->begin(9600);
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            break;
          case 0x12: // set low baud rate
            #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: set low baud rate");
            #endif //DEBUG_WINKEY           
            primary_serial_port->end();
            primary_serial_port->begin(1200);
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            break;
          #endif //OPTION_WINKEY_2_SUPPORT  
          default:
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            break;
          }
      } else {
        if (winkey_status == WINKEY_ADMIN_COMMAND_ECHO) {
          winkey_port_write(incoming_serial_byte);
          winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
        }
      }

      if (winkey_status == WINKEY_KEYING_COMPENSATION_COMMAND) {
        keying_compensation = incoming_serial_byte;
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status == WINKEY_FIRST_EXTENSION_COMMAND) {
        first_extension_time = incoming_serial_byte;
        #ifdef DEBUG_WINKEY_PROTOCOL
        send_char('X',KEYER_NORMAL);
        #endif
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status == WINKEY_PAUSE_COMMAND) {
        if (incoming_serial_byte) {
          pause_sending_buffer = 1;
        } else {
          pause_sending_buffer = 0;
        }
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status ==  WINKEY_KEY_COMMAND) {
        #ifdef FEATURE_MEMORIES
        repeat_memory = 255;
        #endif
        if (incoming_serial_byte) {
          tx_and_sidetone_key(1,AUTOMATIC_SENDING);
        } else {
          tx_and_sidetone_key(0,AUTOMATIC_SENDING);
        }
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status ==  WINKEY_DAH_TO_DIT_RATIO_COMMAND) {
        winkey_dah_to_dit_ratio_command(incoming_serial_byte);
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status == WINKEY_WEIGHTING_COMMAND) {
        winkey_weighting_command(incoming_serial_byte);
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status == WINKEY_PTT_TIMES_PARM1_COMMAND) {
        winkey_ptt_times_parm1_command(incoming_serial_byte);
        winkey_status = WINKEY_PTT_TIMES_PARM2_COMMAND;
      } else {
        if (winkey_status == WINKEY_PTT_TIMES_PARM2_COMMAND) {
          winkey_ptt_times_parm2_command(incoming_serial_byte);
          winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
        }
      }

      if (winkey_status == WINKEY_SET_POT_PARM1_COMMAND) {
        winkey_set_pot_parm1_command(incoming_serial_byte);
        winkey_status = WINKEY_SET_POT_PARM2_COMMAND;
      } else {
        if (winkey_status == WINKEY_SET_POT_PARM2_COMMAND) {
          winkey_set_pot_parm2_command(incoming_serial_byte);
          winkey_status = WINKEY_SET_POT_PARM3_COMMAND;
        } else {
          if (winkey_status == WINKEY_SET_POT_PARM3_COMMAND) {  // third parm is max read value from pot, depending on wiring
            winkey_set_pot_parm3_command(incoming_serial_byte); // WK2 protocol just ignores this third parm
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;      // this is taken care of in winkey_set_pot_parm3()
          }
        }
      }

      if (winkey_status ==  WINKEY_SETMODE_COMMAND) {
        winkey_setmode_command(incoming_serial_byte);
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status ==  WINKEY_SOFTWARE_PADDLE_COMMAND) {
        #ifdef FEATURE_MEMORIES
        repeat_memory = 255;
        #endif
        switch (incoming_serial_byte) {
          case 0: winkey_dit_invoke = 0; winkey_dah_invoke = 0; break;
          case 1: winkey_dit_invoke = 1; winkey_dah_invoke = 0; break;
          case 2: winkey_dit_invoke = 0; winkey_dah_invoke = 1; break;
          case 3: winkey_dah_invoke = 1; winkey_dit_invoke = 1; break;
        }
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status ==  WINKEY_SIDETONE_FREQ_COMMAND) {
        winkey_sidetone_freq_command(incoming_serial_byte);
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

    } // else (winkey_status == WINKEY_NO_COMMAND_IN_PROGRESS)
  }  // if (action == SERVICE_SERIAL_BYTE

  
}
#endif  //FEATURE_WINKEY_EMULATION

//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_COMMAND_LINE_INTERFACE
void service_command_line_interface(HardwareSerial * port_to_use) {
 
  static byte cli_wait_for_cr_flag = 0; 
  
  if (serial_backslash_command == 0) {
    //incoming_serial_byte = primary_serial_port->read();
    incoming_serial_byte = uppercase(incoming_serial_byte);
    if (incoming_serial_byte != 92) { // we do not have a backslash
      if (cli_prosign_flag) {
        add_to_send_buffer(SERIAL_SEND_BUFFER_PROSIGN);
        cli_prosign_flag = 0;
      }
      if (cli_wait_for_cr_to_send_cw) {
        if (cli_wait_for_cr_flag == 0) {
          if (incoming_serial_byte > 31) {
            #ifdef DEBUG_CHECK_SERIAL
            port_to_use->println(F("check_serial: add_to_send_buffer(SERIAL_SEND_BUFFER_HOLD_SEND)"));
            #endif
            add_to_send_buffer(SERIAL_SEND_BUFFER_HOLD_SEND);
            cli_wait_for_cr_flag = 1;
          }
        } else {
          if (incoming_serial_byte == 13) {
            #ifdef DEBUG_CHECK_SERIAL
            port_to_use->println(F("check_serial: add_to_send_buffer(SERIAL_SEND_BUFFER_HOLD_SEND_RELEASE)"));
            #endif
            add_to_send_buffer(SERIAL_SEND_BUFFER_HOLD_SEND_RELEASE);
            cli_wait_for_cr_flag = 0;
          }
        }
      }
      add_to_send_buffer(incoming_serial_byte);
      #ifdef FEATURE_MEMORIES
      if ((incoming_serial_byte != 13) && (incoming_serial_byte != 10)) {
        repeat_memory = 255;
      }
      #endif
    } else {     //(incoming_serial_byte != 92)  -- we got a backslash
      serial_backslash_command = 1;
      port_to_use->write(incoming_serial_byte);
    }
  } else { // (serial_backslash_command == 0) -- we already got a backslash
      //incoming_serial_byte = primary_serial_port->read();
      port_to_use->write(incoming_serial_byte);
      incoming_serial_byte = uppercase(incoming_serial_byte);
      process_serial_command(port_to_use);
      serial_backslash_command = 0;
      port_to_use->println();
  }
}
#endif //FEATURE_COMMAND_LINE_INTERFACE

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_SERIAL)
void check_serial(){
  
  #ifdef DEBUG_SERIAL_SEND_CW_CALLOUT
    byte debug_serial_send_cw[2];
    byte previous_tx = 0;
    byte previous_sidetone = 0;
  #endif
  
  #ifdef DEBUG_LOOP
    debug_serial_port->println(F("loop: entering check_serial")); 
  #endif 
    

  #ifdef FEATURE_WINKEY_EMULATION
    if (primary_serial_port_mode == SERIAL_WINKEY_EMULATION) {
      service_winkey(WINKEY_HOUSEKEEPING);
    }
  #endif


  while (primary_serial_port->available() > 0) {
    incoming_serial_byte = primary_serial_port->read();
    #ifdef FEATURE_SLEEP
      last_activity_time = millis(); 
    #endif //FEATURE_SLEEP    
    #ifdef DEBUG_SERIAL_SEND_CW_CALLOUT
      debug_serial_send_cw[0] = (incoming_serial_byte & 0xf0)>>4;
      debug_serial_send_cw[1] = incoming_serial_byte & 0x0f;
      for (byte x = 0;x < 2;x++) {
        if (debug_serial_send_cw[x] < 10) {
          debug_serial_send_cw[x] = debug_serial_send_cw[x] + 48;
        } else {
          debug_serial_send_cw[x] = debug_serial_send_cw[x] + 55;
        }
      }
      previous_tx = key_tx;
      key_tx = 0;
      previous_sidetone = configuration.sidetone_mode;
      configuration.sidetone_mode = SIDETONE_ON;
      send_char(debug_serial_send_cw[0],0);
      send_char(debug_serial_send_cw[1],0);
      key_tx = previous_tx;
      configuration.sidetone_mode = previous_sidetone;
    #endif
    
    #if !defined(FEATURE_WINKEY_EMULATION) && !defined(FEATURE_COMMAND_LINE_INTERFACE)
      primary_serial_port->println(F("No serial features enabled..."));
    #endif

    // yea, this is a bit funky below
/*
    #ifdef FEATURE_WINKEY_EMULATION
      if (primary_serial_port_mode == SERIAL_WINKEY_EMULATION) {
        service_winkey(SERVICE_SERIAL_BYTE);
      } else {
    #endif //FEATURE_WINKEY_EMULATION
    
    #ifdef FEATURE_COMMAND_LINE_INTERFACE    
      service_command_line_interface(primary_serial_port);
    #endif //FEATURE_COMMAND_LINE_INTERFACE
    
    #ifdef FEATURE_WINKEY_EMULATION
      } // if (primary_serial_port_mode == SERIAL_WINKEY_EMULATION)
    #endif //FEATURE_WINKEY_EMULATION
*/

    #if defined(FEATURE_WINKEY_EMULATION) && defined(FEATURE_COMMAND_LINE_INTERFACE)
      if (primary_serial_port_mode == SERIAL_WINKEY_EMULATION) {
        service_winkey(SERVICE_SERIAL_BYTE);
      } else {
        service_command_line_interface(primary_serial_port);
      }
    #else  //defined(FEATURE_WINKEY_EMULATION) && defined(FEATURE_COMMAND_LINE_INTERFACE)
      #ifdef FEATURE_COMMAND_LINE_INTERFACE    
        service_command_line_interface(primary_serial_port);
      #endif //FEATURE_COMMAND_LINE_INTERFACE
      #ifdef FEATURE_WINKEY_EMULATION
        service_winkey(SERVICE_SERIAL_BYTE);
      #endif //FEATURE_WINKEY_EMULATION
    #endif //defined(FEATURE_WINKEY_EMULATION) && defined(FEATURE_COMMAND_LINE_INTERFACE)

  }  //while (primary_serial_port->available() > 0)

  #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
    while (secondary_serial_port->available() > 0) {
      incoming_serial_byte = secondary_serial_port->read();     
      #ifdef FEATURE_SLEEP
        last_activity_time = millis(); 
      #endif //FEATURE_SLEEP    
      #ifdef DEBUG_SERIAL_SEND_CW_CALLOUT
        debug_serial_send_cw[0] = (incoming_serial_byte & 0xf0)>>4;
        debug_serial_send_cw[1] = incoming_serial_byte & 0x0f;
        for (byte x = 0;x < 2;x++) {
          if (debug_serial_send_cw[x] < 10) {
            debug_serial_send_cw[x] = debug_serial_send_cw[x] + 48;
          } else {
            debug_serial_send_cw[x] = debug_serial_send_cw[x] + 55;
          }
        }
        previous_tx = key_tx;
        key_tx = 0;
        previous_sidetone = configuration.sidetone_mode;
        configuration.sidetone_mode = SIDETONE_ON;
        send_char(debug_serial_send_cw[0],0);
        send_char(debug_serial_send_cw[1],0);
        key_tx = previous_tx;
        configuration.sidetone_mode = previous_sidetone;
      #endif /DEBUG_SERIAL_SEND_CW_CALLOUT
      service_command_line_interface(secondary_serial_port);
    } //  while (secondary_serial_port->available() > 0)  
  #endif //FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT


}
#endif //defined(FEATURE_SERIAL)

//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL_HELP) && defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void print_serial_help(HardwareSerial * port_to_use){

  port_to_use->println(F("\n\rK3NG Keyer Help\n\r"));
  port_to_use->println(F("CLI commands:"));
  port_to_use->println(F("\\#\t\t: play memory # x"));
  port_to_use->println(F("\\A\t\t: Iambic A"));
  port_to_use->println(F("\\B\t\t: Iambic B"));
  #ifdef FEATURE_HELL
    port_to_use->println(F("\\C\t\t: switch to CW (from Hell mode)"));
  #endif
  port_to_use->println(F("\\D\t\t: Ultimatic"));
  port_to_use->println(F("\\E####\t\t: Set serial number to ####"));
  port_to_use->println(F("\\F####\t\t: Set sidetone to #### hz"));
  port_to_use->println(F("\\G\t\t: switch to Bug mode"));
  #ifdef FEATURE_HELL
    port_to_use->println(F("\\H\t\t: Switch to Hell mode"));
  #endif
  port_to_use->println(F("\\I\t\t: TX line disable/enable"));
  port_to_use->println(F("\\J###\t\t: Set Dah to Dit Ratio"));
  #ifdef FEATURE_CALLSIGN_RECEIVE_PRACTICE
    port_to_use->println(F("\\K\t\t: Callsign receive practice"));
  #endif
  port_to_use->println(F("\\L##\t\t: Set weighting (50 = normal)"));
  #ifdef FEATURE_FARNSWORTH
    port_to_use->println(F("\\M###\t\t: Set Farnsworth Speed"));
  #endif
  port_to_use->println(F("\\N\t\t: toggle paddle reverse"));
  port_to_use->println(F("\\Px<string>\t: program memory #x with <string>"));
  port_to_use->println(F("\\Q#[#]\t\t: Switch to QRSS mode with ## second dit length"));
  port_to_use->println(F("\\R\t\t: Switch to regular speed (wpm) mode"));
  port_to_use->println(F("\\S\t\t: status report"));
  port_to_use->println(F("\\T\t\t: Tune mode"));
  port_to_use->println(F("\\U\t\t: PTT toggle"));
  #ifdef FEATURE_POTENTIOMETER
  port_to_use->println(F("\\V\t\t: Potentiometer activate/deactivate"));
  #endif //FEATURE_POTENTIOMETER
  port_to_use->println(F("\\W#[#][#]\t: Change WPM to ###"));
  port_to_use->println(F("\\X#\t\t: Switch to transmitter #"));
  port_to_use->println(F("\\Y#\t\t: Change wordspace to #"));
  #ifdef FEATURE_AUTOSPACE
    port_to_use->println(F("\\Z\t\t: Autospace on/off"));
  #endif //FEATURE_AUTOSPACE
  port_to_use->println(F("\\+\t\t: Prosign"));
  port_to_use->println(F("\\\\\t\t: Empty keyboard send buffer"));
  #ifdef FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
    port_to_use->println(F("\\&\t\t: Toggle CMOS Super Keyer Timing on/off"));
    port_to_use->println(F("\\%##\t\t: Set CMOS Super Keyer Timing %"));
  #endif //FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
  #ifdef FEATURE_DIT_DAH_BUFFER_CONTROL
    port_to_use->println(F("\\.\t\t: Toggle dit buffer on/off"));
    port_to_use->println(F("\\-\t\t: Toggle dah buffer on/off"));
  #endif //FEATURE_DIT_DAH_BUFFER_CONTROL  
  port_to_use->println(F("\nMemory Macros:"));
  port_to_use->println(F("\\#\t\t: Jump to memory #"));
  #ifdef FEATURE_HELL
    port_to_use->println(F("\\C\t\t: Switch to CW (from Hell mode)"));
  #endif //FEATURE_HELL
  port_to_use->println(F("\\D###\t\t: Delay for ### seconds"));
  port_to_use->println(F("\\E\t\t: Send serial number"));
  port_to_use->println(F("\\F####\t\t: Set sidetone to #### hz"));
  #ifdef FEATURE_HELL
    port_to_use->println(F("\\H\t\t: Switch to Hell mode"));
  #endif //FEATURE_HELL
  port_to_use->println(F("\\N\t\t: Decrement serial number"));
  port_to_use->println(F("\\Q##\t\t: Switch to QRSS with ## second dit length"));
  port_to_use->println(F("\\R\t\t: Switch to regular speed mode"));
  port_to_use->println(F("\\T###\t\t: Transmit for ### seconds"));
  port_to_use->println(F("\\U\t\t: key PTT"));
  port_to_use->println(F("\\V\t\t: unkey PTT"));
  port_to_use->println(F("\\W###\t\t: Change WPM to ###"));
  port_to_use->println(F("\\X#\t\t: Switch to transmitter #"));
  port_to_use->println(F("\\Y#\t\t: Increase speed # WPM"));
  port_to_use->println(F("\\Z#\t\t: Decrease speed # WPM"));
  port_to_use->println(F("\\^\t\t: Toggle send CW immediately"));
  port_to_use->println(F("\\+\t\t: Prosign"));
  #ifdef FEATURE_MEMORIES
    port_to_use->println(F("\\!##\t\t: Repeat play memory"));
    port_to_use->println(F("\\|####\t\t: Set memory repeat (milliseconds)"));
  #endif //FEATURE_MEMORIES
  #if defined(FEATURE_PADDLE_ECHO)
    port_to_use->println(F("\\*\t\t: Toggle paddle echo"));
  #endif //FEATURE_PADDLE_ECHO
  #if defined(FEATURE_STRAIGHT_KEY_ECHO)
    port_to_use->println(F("\\`\t\t: Toggle straight key echo"));
  #endif //FEATURE_STRAIGHT_KEY_ECHO  
  port_to_use->println(F("\\^\t\t: Toggle wait for carriage return to send CW / send CW immediately"));
  port_to_use->println(F("\\~\t\t: Reset unit"));
  #ifdef FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
    port_to_use->println(F("\\&\t\t: Toggle CMOS Super Keyer Timing on/off"));
    port_to_use->println(F("\\%##\t\t: Set CMOS Super Keyer Timing %"));
  #endif //FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
  #ifdef FEATURE_DIT_DAH_BUFFER_CONTROL
    port_to_use->println(F("\\.\t\t: Toggle dit buffer on/off"));
    port_to_use->println(F("\\-\t\t: Toggle dah buffer on/off"));
  #endif //FEATURE_DIT_DAH_BUFFER_CONTROL
  port_to_use->println(F("\\:\t\t: CW send echo inhibit toggle"));
  #ifdef FEATURE_QLF
    port_to_use->println(F("\\{\t\t: QLF mode on/off"));
  #endif //FEATURE_QLF

}
#endif
//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void process_serial_command(HardwareSerial * port_to_use) {
  
  int user_input_temp = 0;
        
  port_to_use->println();
  switch (incoming_serial_byte) {
    case 126:
      #ifndef HARDWARE_ARDUINO_DUE 
        asm volatile ("jmp 0"); /*wdt_enable(WDTO_30MS); while(1) {} ;*/ 
      #else //HARDWARE_ARDUINO_DUE
        setup();
      #endif //HARDWARE_ARDUINO_DUE
      break;  // ~ - reset unit
    case 42:                                                // * - paddle echo on / off
      if (cli_paddle_echo) {
        cli_paddle_echo = 0;
      } else {
        cli_paddle_echo = 1;
      }
      break;
    #if defined(FEATURE_STRAIGHT_KEY_ECHO)
      case '`':
        if (cli_straight_key_echo) {
          cli_straight_key_echo = 0;
        } else {
          cli_straight_key_echo = 1;
        }    
        break;
    #endif //FEATURE_STRAIGHT_KEY_ECHO
    case 43: cli_prosign_flag = 1; break;
    #if defined(FEATURE_SERIAL_HELP)
      case 63: print_serial_help(port_to_use); break;                         // ? = print help
    #endif //FEATURE_SERIAL_HELP
    case 65: configuration.keyer_mode = IAMBIC_A; config_dirty = 1; port_to_use->println(F("Iambic A")); break;    // A - Iambic A mode
    case 66: configuration.keyer_mode = IAMBIC_B; config_dirty = 1; port_to_use->println(F("Iambic B")); break;    // B - Iambic B mode
    case 67: char_send_mode = CW; port_to_use->println(F("CW mode")); break;             // C - CW mode
    case 68: configuration.keyer_mode = ULTIMATIC; config_dirty = 1; port_to_use->println(F("Ultimatic")); break;  // D - Ultimatic mode
    case 69: serial_set_serial_number(port_to_use); break;                                   // E - set serial number
    case 70: serial_set_sidetone_freq(port_to_use); break;                                   // F - set sidetone frequency
    case 71: configuration.keyer_mode = BUG; config_dirty = 1; port_to_use->println(F("Bug")); break;              // G - Bug mode
    #ifdef FEATURE_HELL
      case 72: char_send_mode = HELL; port_to_use->println(F("Hell mode")); break;         // H - Hell mode
    #endif //FEATURE_HELL
    case 73:                                                                      // I - transmit line on/off
      port_to_use->print(F("TX o"));
      if (key_tx) {
        key_tx = 0;
        port_to_use->println(F("ff"));
      } else {
        key_tx = 1;
        port_to_use->println(F("n"));
      }
      break;
    #ifdef FEATURE_MEMORIES
      case 33: repeat_play_memory(port_to_use); break;      // ! - repeat play
      case 124: serial_set_memory_repeat(port_to_use); break; // | - set memory repeat time
      case 48: serial_play_memory(9); break;    // 0 - play memory 10
      case 49:                                  // 1-9 - play memory #
      case 50:
      case 51:
      case 52:
      case 53:
      case 54: 
      case 55:
      case 56: 
      case 57: serial_play_memory(incoming_serial_byte-49); break;
      case 80: repeat_memory = 255; serial_program_memory(port_to_use); break;                                // P - program memory
    #endif //FEATURE_MEMORIES
    case 81: serial_qrss_mode(); break; // Q - activate QRSS mode
    case 82: speed_mode = SPEED_NORMAL; port_to_use->println(F("QRSS Off")); break; // R - activate regular timing mode
    case 83: serial_status(port_to_use); break;                                              // S - Status command
    case 74: serial_set_dit_to_dah_ratio(port_to_use); break;                          // J - dit to dah ratio
    #ifdef FEATURE_CALLSIGN_RECEIVE_PRACTICE
      case 75: serial_cw_practice(port_to_use); break;                     // K - CW practice
    #endif //FEATURE_CALLSIGN_RECEIVE_PRACTICE
    case 76: serial_set_weighting(port_to_use); break;
    #ifdef FEATURE_FARNSWORTH
      case 77: serial_set_farnsworth(port_to_use); break;                                // M - set Farnsworth speed
    #endif
    case 78:                                                                // N - paddle reverse
      port_to_use->print(F("Paddles "));
      if (configuration.paddle_mode == PADDLE_NORMAL) {
        configuration.paddle_mode = PADDLE_REVERSE;
        port_to_use->println(F("reversed"));
      } else {
        configuration.paddle_mode = PADDLE_NORMAL;
        port_to_use->println(F("normal"));
      }
      config_dirty = 1;
    break;  // case 78
    case 79:                                                                // O - toggle sidetone on/off
      port_to_use->print(F("Sidetone O"));
      if ((configuration.sidetone_mode == SIDETONE_ON) || (configuration.sidetone_mode == SIDETONE_PADDLE_ONLY)) {
        configuration.sidetone_mode = SIDETONE_OFF;
        port_to_use->println(F("FF"));
      } else {
        configuration.sidetone_mode = SIDETONE_ON;
        port_to_use->println(F("N"));
      }
      config_dirty = 1;
    break; // case 79
    case 84: // T - tune
      #ifdef FEATURE_MEMORIES
        repeat_memory = 255;
      #endif
      serial_tune_command(port_to_use); break;
    case 85:
      port_to_use->print(F("PTT o"));
      if (ptt_line_activated) {
        manual_ptt_invoke = 0;
        ptt_unkey();
        port_to_use->println(F("ff"));
      } else {
        manual_ptt_invoke = 1;
        ptt_key();
        port_to_use->println(F("n"));
      }
      break;
    #ifdef FEATURE_POTENTIOMETER
      case 86:                // V - toggle pot activation
        port_to_use->print(F("Potentiometer "));
        configuration.pot_activated = !configuration.pot_activated;
        if (configuration.pot_activated) {
          port_to_use->print(F("A"));
        } else {
          port_to_use->print(F("Dea"));
        }
        port_to_use->println(F("ctivated"));
        config_dirty = 1;
        break;
    #endif
    case 87: serial_wpm_set(port_to_use);break;                                        // W - set WPM
    case 88: serial_switch_tx(port_to_use);break;                                      // X - switch transmitter
    case 89: serial_change_wordspace(port_to_use); break;
    #ifdef FEATURE_AUTOSPACE
      case 90:
        port_to_use->print(F("Autospace O"));
        if (configuration.autospace_active) {
          configuration.autospace_active = 0;
          config_dirty = 1;
          port_to_use->println(F("ff"));
        } else {
          configuration.autospace_active = 1;
          config_dirty = 1;
          port_to_use->println(F("n"));
        }
        break;
    #endif
    #ifdef FEATURE_MEMORIES
      case 92:
        clear_send_buffer();
        play_memory_prempt = 1;
        repeat_memory = 255;
        break;                           // \ - double backslash - clear serial send buffer
    #endif
    case 94:                           // ^ - toggle send CW send immediately
       if (cli_wait_for_cr_to_send_cw) {
         cli_wait_for_cr_to_send_cw = 0;
         port_to_use->println(F("Send CW immediately"));
       } else {
         cli_wait_for_cr_to_send_cw = 1;
         port_to_use->println(F("Wait for CR to send CW"));
       }
      break;
    #ifdef FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
      case '&':
        port_to_use->print(F("CMOS Super Keyer Timing O"));
        if (configuration.cmos_super_keyer_iambic_b_timing_on) {
          configuration.cmos_super_keyer_iambic_b_timing_on = 0;
          port_to_use->println(F("ff"));        
        } else {
          configuration.cmos_super_keyer_iambic_b_timing_on = 1;
          port_to_use->println(F("n"));
          configuration.keyer_mode = IAMBIC_B;
        }
        config_dirty = 1;
        break;
      case '%':
        user_input_temp = serial_get_number_input(2,-1,100,port_to_use);
        if ((user_input_temp >= 0) && (user_input_temp < 100)) {
          configuration.cmos_super_keyer_iambic_b_timing_percent = user_input_temp;
          port_to_use->println(F("CMOS Super Keyer Timing Set."));
        }
        config_dirty = 1;
        break;
    #endif //FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
    #ifdef FEATURE_DIT_DAH_BUFFER_CONTROL
      case '.':
        port_to_use->print(F("Dit Buffer O"));
        if (configuration.dit_buffer_off) {
          configuration.dit_buffer_off = 0;
          port_to_use->println(F("n"));
        } else {
          configuration.dit_buffer_off = 1;
          port_to_use->println(F("ff"));
        }
        config_dirty = 1;
        break;
      case '-':
        port_to_use->print(F("Dah Buffer O"));
        if (configuration.dah_buffer_off) {
          configuration.dah_buffer_off = 0;
          port_to_use->println(F("n"));
        } else {
          configuration.dah_buffer_off = 1;
          port_to_use->println(F("ff"));
        }
        config_dirty = 1;    
        break;
    #endif //FEATURE_DIT_DAH_BUFFER_CONTROL
    case ':':
      if (cw_send_echo_inhibit) cw_send_echo_inhibit = 0; else cw_send_echo_inhibit = 1;
      break;
    #ifdef FEATURE_QLF
      case '{':
        port_to_use->print(F("QLF: O"));
        if (qlf_active){
            qlf_active = 0;
            port_to_use->println(F("ff"));
          } else {
            qlf_active = 1;
            port_to_use->println(F("n"));
          }
        break;
    #endif //FEATURE_QLF
    default: port_to_use->println(F("Unknown command")); break;
  }

}
#endif //defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)


//---------------------------------------------------------------------

#ifdef FEATURE_PADDLE_ECHO
void service_paddle_echo()
{
  
  #ifdef DEBUG_LOOP
    debug_serial_port->println(F("loop: entering service_paddle_echo"));
  #endif          

  static byte paddle_echo_space_sent = 1;
  byte character_to_send = 0;
  static byte no_space = 0;

  
  #if defined(FEATURE_DISPLAY) && defined(OPTION_DISPLAY_NON_ENGLISH_EXTENSIONS)
    byte ascii_temp = 0;
  #endif //defined(FEATURE_DISPLAY) && defined(OPTION_DISPLAY_NON_ENGLISH_EXTENSIONS)

  
  #if defined(FEATURE_CW_COMPUTER_KEYBOARD)
    static byte backspace_flag = 0;
    if (paddle_echo_buffer == 111111) {paddle_echo_buffer_decode_time = 0; backspace_flag = 1;}  //this is a special hack to make repeating backspace work
  #endif //defined(FEATURE_CW_COMPUTER_KEYBOARD)
  
  
  if ((paddle_echo_buffer) && (millis() > paddle_echo_buffer_decode_time)) {


    #if defined(FEATURE_CW_COMPUTER_KEYBOARD)
    switch (paddle_echo_buffer){
      case 111111:
      case 1111111:
      case 11111111:
      case 111111111:
        Keyboard.write(KEY_BACKSPACE); // backspace
        no_space = 1;
        break;
      case 1212:  // prosign AA
        Keyboard.write(KEY_RETURN);
        no_space = 1;   
        break;
      case 211222: // prosign DO
        Keyboard.write(KEY_CAPS_LOCK);
        #ifdef OPTION_CW_KEYBOARD_CAPSLOCK_BEEP
          if (cw_keyboard_capslock_on){
            beep();delay(100);
            boop();
            cw_keyboard_capslock_on = 0;
          } else {
            boop();
            beep();
            cw_keyboard_capslock_on = 1;
          }
        #endif //OPTION_CW_KEYBOARD_CAPSLOCK_BEEP
        no_space = 1;       
        break;
  
      #ifdef OPTION_CW_KEYBOARD_ITALIAN  // courtesy of Giorgio IZ2XBZ
        case 122121: // "@"
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.write(59);
          Keyboard.releaseAll();
          break;
        case 112211:// "?"
          Keyboard.write(95);
          break;
        case 11221: // "!"
          Keyboard.write(33);
          break;
        case 21121: // "/"
          Keyboard.write(38);
          break;
        case 21112: // "=" or "BT"
          Keyboard.write(41);  
          break;
        case 12212: //à
          Keyboard.write(39);  
          break;
        case 11211: //è
          Keyboard.write(91);  
          break;
        case 12221: //ì
          Keyboard.write(61);  
          break;
        case 2221: //ò
          Keyboard.write(59);  
          break;
          case 1122: //ù
          Keyboard.write(92);  
          break;
        case 21221: // (
          Keyboard.write(42);  
          break;
        case 212212: // )
          Keyboard.write(40);  
          break;
        case 12111: // &
          Keyboard.write(94);  
          break;
        case 222111: //:
          Keyboard.write(62);  
          break;
        case 212121: //;
          Keyboard.write(60);  
        break;
          case 12121: //+
          Keyboard.write(93);  
          break;
        case 211112: // -
          Keyboard.write(47);  
          break;   
      #endif //OPTION_CW_KEYBOARD_ITALIAN
        
      default:
        character_to_send = convert_cw_number_to_ascii(paddle_echo_buffer);
        if ((character_to_send > 64) && (character_to_send < 91)) {character_to_send = character_to_send + 32;}
        if (character_to_send=='*'){
          no_space = 1;
          #ifdef OPTION_UNKNOWN_CHARACTER_ERROR_TONE
            boop();
          #endif //OPTION_UNKNOWN_CHARACTER_ERROR_TONE
        } else {
          if (!((backspace_flag) && ((paddle_echo_buffer == 1) || (paddle_echo_buffer == 11) || (paddle_echo_buffer == 111) || (paddle_echo_buffer == 1111) || (paddle_echo_buffer == 11111)))){
            Keyboard.write(char(character_to_send));
          }
          backspace_flag = 0;
        }
        break;
    }
      #ifdef DEBUG_CW_COMPUTER_KEYBOARD
        debug_serial_port->print("service_paddle_echo: Keyboard.write: ");
        debug_serial_port->write(character_to_send);
        debug_serial_port->println();
      #endif //DEBUG_CW_COMPUTER_KEYBOARD
    #endif //defined(FEATURE_CW_COMPUTER_KEYBOARD)

 
    #ifdef FEATURE_DISPLAY
      if (lcd_paddle_echo){
        #ifndef OPTION_DISPLAY_NON_ENGLISH_EXTENSIONS
          display_scroll_print_char(byte(convert_cw_number_to_ascii(paddle_echo_buffer)));
        #else //OPTION_DISPLAY_NON_ENGLISH_EXTENSIONS
          ascii_temp = byte(convert_cw_number_to_ascii(paddle_echo_buffer));
          switch (ascii_temp){
            case 220: ascii_temp = 0;break; // U_umlaut  (D, ...)
            case 214: ascii_temp = 1;break; // O_umlaut  (D, SM, OH, ...)
            case 196: ascii_temp = 2;break; // A_umlaut  (D, SM, OH, ...)
            case 198: ascii_temp = 3;break; // AE_capital (OZ, LA)
            case 216: ascii_temp = 4;break; // OE_capital (OZ, LA)
            case 197: ascii_temp = 6;break; // AA_capital (OZ, LA, SM)
            case 209: ascii_temp = 7;break; // N-tilde (EA) 
          }
          display_scroll_print_char(ascii_temp);
        #endif //OPTION_DISPLAY_NON_ENGLISH_EXTENSIONS
      }
    #endif //FEATURE_DISPLAY
    
    #if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
      if (cli_paddle_echo){
        primary_serial_port->write(byte(convert_cw_number_to_ascii(paddle_echo_buffer)));

        #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
          secondary_serial_port->write(byte(convert_cw_number_to_ascii(paddle_echo_buffer)));
        #endif

      } 
    #endif //defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)   
   
    paddle_echo_buffer = 0;
    paddle_echo_buffer_decode_time = millis() + (float(600/configuration.wpm)*length_letterspace);
    paddle_echo_space_sent = 0;
  }
  
  if ((paddle_echo_buffer == 0) && (millis() > (paddle_echo_buffer_decode_time + (float(1200/configuration.wpm)*(configuration.length_wordspace-length_letterspace)))) && (!paddle_echo_space_sent)) {
    
    #if defined(FEATURE_CW_COMPUTER_KEYBOARD)
      if (!no_space){
        Keyboard.write(' ');
        #ifdef DEBUG_CW_COMPUTER_KEYBOARD
          debug_serial_port->println("service_paddle_echo: Keyboard.write: <space>");
        #endif //DEBUG_CW_COMPUTER_KEYBOARD 
      }
      no_space = 0;   
    #endif //defined(FEATURE_CW_COMPUTER_KEYBOARD)
    
    #ifdef FEATURE_DISPLAY
      if (lcd_paddle_echo){
        display_scroll_print_char(' ');
      }
    #endif //FEATURE_DISPLAY
    
    #if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
       if (cli_paddle_echo){
         primary_serial_port->write(" ");

        #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
          secondary_serial_port->write(" ");
        #endif

       }    
    #endif //defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
    
    
    paddle_echo_space_sent = 1;
  }
  
}
#endif //FEATURE_PADDLE_ECHO

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && defined(FEATURE_MEMORIES)
void serial_set_memory_repeat(HardwareSerial * port_to_use) {

  int temp_int = serial_get_number_input(5, -1, 32000, port_to_use);
  if (temp_int > -1) {
    configuration.memory_repeat_time = temp_int;
    config_dirty = 1;
  }

}
#endif
//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && defined(FEATURE_MEMORIES)
void repeat_play_memory(HardwareSerial * port_to_use) {

  byte memory_number = serial_get_number_input(2,0, (number_of_memories+1), port_to_use);
  #ifdef DEBUG_CHECK_SERIAL
    debug_serial_port->print(F("repeat_play_memory: memory_number:"));
    debug_serial_port->println(memory_number);
  #endif //DEBUG_SERIAL
  if (memory_number > -1) {
    repeat_memory = memory_number - 1;
  }

}

#endif

//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && defined(FEATURE_MEMORIES)

void serial_play_memory(byte memory_number) {

  if (memory_number < number_of_memories) {
    add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
    add_to_send_buffer(memory_number);
    repeat_memory = 255;
  }

}
#endif

//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
int serial_get_number_input(byte places,int lower_limit, int upper_limit,HardwareSerial * port_to_use)
{
  byte incoming_serial_byte = 0;
  byte looping = 1;
  byte error = 0;
  String numberstring = "";
  byte numberindex = 0;
  int numbers[6];

  while (looping) {
    if (port_to_use->available() == 0) {        // wait for the next keystroke
      if (keyer_machine_mode == KEYER_NORMAL) {          // might as well do something while we're waiting
        check_paddles();
        service_dit_dah_buffers();
        service_send_buffer(PRINTCHAR);

        check_ptt_tail();
        #ifdef FEATURE_POTENTIOMETER
        if (configuration.pot_activated) {
          check_potentiometer();
        }
        #endif
        
        #ifdef FEATURE_ROTARY_ENCODER
        check_rotary_encoder();
        #endif //FEATURE_ROTARY_ENCODER        
      }
    } else {
      incoming_serial_byte = port_to_use->read();
      if ((incoming_serial_byte > 47) && (incoming_serial_byte < 58)) {    // ascii 48-57 = "0" - "9")
        numberstring = numberstring + incoming_serial_byte;
        numbers[numberindex] = incoming_serial_byte;
        numberindex++;
        if (numberindex > places){
            looping = 0;
            error = 1;
        }
      } else {
        if (incoming_serial_byte == 13) {   // carriage return - get out
          looping = 0;
        } else {                 // bogus input - error out
          looping = 0;
          error = 1;
        }
      }
    }
  }
  if (error) {
    port_to_use->println(F("Error..."));
    while (port_to_use->available() > 0) { incoming_serial_byte = port_to_use->read(); }  // clear out buffer
    return(-1);
  } else {
    int y = 1;
    int return_number = 0;
    for (int x = (numberindex - 1); x >= 0 ; x = x - 1) {
      return_number = return_number + ((numbers[x]-48) * y);
      y = y * 10;
    }
    if ((return_number > lower_limit) && (return_number < upper_limit)) {
      return(return_number);
    } else {
      port_to_use->println(F("Error..."));
      return(-1);
    }
  }
}
#endif

//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_change_wordspace(HardwareSerial * port_to_use)
{
  int set_wordspace_to = serial_get_number_input(2,0,100,port_to_use);
  if (set_wordspace_to > 0) {
    config_dirty = 1;
    configuration.length_wordspace = set_wordspace_to;
    port_to_use->write("Wordspace set to ");
    port_to_use->println(set_wordspace_to,DEC);
  }
}
#endif

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_switch_tx(HardwareSerial * port_to_use)
{
  int set_tx_to = serial_get_number_input(1,0,7,port_to_use);
  if (set_tx_to > 0) {
    switch (set_tx_to){
      case 1: switch_to_tx_silent(1); port_to_use->print(F("Switching to TX #")); port_to_use->println(F("1")); break;
      case 2: if ((ptt_tx_2) || (tx_key_line_2)) {switch_to_tx_silent(2); port_to_use->print(F("Switching to TX #"));} port_to_use->println(F("2")); break;
      case 3: if ((ptt_tx_3) || (tx_key_line_3)) {switch_to_tx_silent(3); port_to_use->print(F("Switching to TX #"));} port_to_use->println(F("3")); break;
      case 4: if ((ptt_tx_4) || (tx_key_line_4)) {switch_to_tx_silent(4); port_to_use->print(F("Switching to TX #"));} port_to_use->println(F("4")); break;
      case 5: if ((ptt_tx_5) || (tx_key_line_5)) {switch_to_tx_silent(5); port_to_use->print(F("Switching to TX #"));} port_to_use->println(F("5")); break;
      case 6: if ((ptt_tx_6) || (tx_key_line_6)) {switch_to_tx_silent(6); port_to_use->print(F("Switching to TX #"));} port_to_use->println(F("6")); break;
    }
  }
}
#endif

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_set_dit_to_dah_ratio(HardwareSerial * port_to_use)
{
    int set_ratio_to = serial_get_number_input(4, 99, 1000, port_to_use);
    if ((set_ratio_to > 99) && (set_ratio_to < 1000)) {
      configuration.dah_to_dit_ratio = set_ratio_to;
      port_to_use->print(F("Setting dah to dit ratio to "));
      port_to_use->println((float(configuration.dah_to_dit_ratio)/100));
      config_dirty = 1;
    }
}
#endif

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_set_serial_number(HardwareSerial * port_to_use)
{
  int set_serial_number_to = serial_get_number_input(4,0,10000, port_to_use);
  if (set_serial_number_to > 0) {
    serial_number = set_serial_number_to;
    port_to_use->print(F("Setting serial number to "));
    port_to_use->println(serial_number);
  }
}
#endif

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_set_sidetone_freq(HardwareSerial * port_to_use)
{
  int set_sidetone_hz = serial_get_number_input(4,(SIDETONE_HZ_LOW_LIMIT-1),(SIDETONE_HZ_HIGH_LIMIT+1), port_to_use);
  if ((set_sidetone_hz > SIDETONE_HZ_LOW_LIMIT) && (set_sidetone_hz < SIDETONE_HZ_HIGH_LIMIT)) {
    port_to_use->write("Setting sidetone to ");
    port_to_use->print(set_sidetone_hz,DEC);
    port_to_use->println(F(" hz"));
    configuration.hz_sidetone = set_sidetone_hz;
    config_dirty = 1;
  }
}
#endif

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_wpm_set(HardwareSerial * port_to_use)
{
  int set_wpm = serial_get_number_input(3,0,1000, port_to_use);
  if (set_wpm > 0) {
    speed_set(set_wpm);
    port_to_use->write("Setting WPM to ");
    port_to_use->println(set_wpm,DEC);
    config_dirty = 1;
  }
}
#endif

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && defined(FEATURE_FARNSWORTH)
void serial_set_farnsworth(HardwareSerial * port_to_use)
{
  int set_farnsworth_wpm = serial_get_number_input(3,-1,1000, port_to_use);
  if (set_farnsworth_wpm > 0) {
    configuration.wpm_farnsworth = set_farnsworth_wpm;
    port_to_use->write("Setting Farnworth WPM to ");
    port_to_use->println(set_farnsworth_wpm,DEC);
    config_dirty = 1;
  }
}
#endif

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_set_weighting(HardwareSerial * port_to_use)
{
  int set_weighting = serial_get_number_input(2,9,91,port_to_use);
  if (set_weighting > 0) {
    configuration.weighting = set_weighting;
    port_to_use->write("Setting weighting to ");
    port_to_use->println(set_weighting,DEC);
  }
}
#endif

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_tune_command (HardwareSerial * port_to_use)
{
  byte incoming;

  delay(100);
  while (port_to_use->available() > 0) {  // clear out the buffer if anything is there
    incoming = port_to_use->read();
  }

  tx_and_sidetone_key(1,MANUAL_SENDING);
  port_to_use->println("Keying tx - press a key to unkey");
  #ifdef FEATURE_COMMAND_BUTTONS
  while ((port_to_use->available() == 0) && (!analogbuttonread(0))) {}  // keystroke or button0 hit gets us out of here
  #endif
  while (port_to_use->available() > 0) {  // clear out the buffer if anything is there
    incoming = port_to_use->read();
  }
  tx_and_sidetone_key(0,MANUAL_SENDING);

}
#endif
//---------------------------------------------------------------------
#ifdef FEATURE_CALLSIGN_RECEIVE_PRACTICE

String generate_callsign() {

  String callsign(10);
  char nextchar;
  long random_number = 0;

  switch (random(1,5)) {
    case 1: callsign = "K"; break;
    case 2: callsign = "W"; break;
    case 3: callsign = "N"; break;
    case 4: callsign = "A"; break;
  }
  if (callsign == "A") {                   // if the first letter is A, we definitely need a second letter before the number
    nextchar = random(65,91);
    callsign = callsign + nextchar;
  } else {
    random_number = random(0,1);           // randomly add a second letter for K, W, N prefixes
    if (random_number) {
      nextchar = random(65,91);
      callsign = callsign + nextchar;
    }
  }
  nextchar = random(48,58);               // generate the number
  callsign = callsign + nextchar;
  nextchar = random(65,91);               // generate first letter after number
  callsign = callsign + nextchar;
  if (random(1,5) < 4) {                  // randomly put a second character after the number
    nextchar = random(65,91);
    callsign = callsign + nextchar;
    if (random_number < 3) {              // randomly put a third character after the number
      nextchar = random(65,91);
      callsign = callsign + nextchar;
    }
  }
  if (random(1,16) == 1) {                // randomly put a slash something on the end like /QRP or /#
    if (random(1,4) == 1) {
      callsign = callsign + "/QRP";
    } else {
       nextchar = random(48,58);
       callsign = callsign + "/" + nextchar;
    }
  }

  return callsign;
}

#endif //FEATURE_CALLSIGN_RECEIVE_PRACTICE
//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_CALLSIGN_RECEIVE_PRACTICE) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void paqso_practice(HardwareSerial * port_to_use){
  
  // VT100 emulation in Linux: screen /dev/ttyACM1 115200 term vt100
  
  
  #define CONTEST_PRACTICE_IDLE 0
  #define CONTEST_PRACTICE_CQ_SENT 1
  #define CONTEST_PRACTICE_REPORT_SENT 2
  
  
  #define FIELD_CALLSIGN 0
  #define FIELD_NR 1
  #define FIELD_SECTION 2
  
  
  byte overall_state = CONTEST_PRACTICE_IDLE;
  byte loop1 = 1;
  byte user_input_buffer[10];
  byte user_input_buffer_characters = 0;
  byte incoming_char = 0;
  byte process_user_input_buffer = 0;
  unsigned long escape_flag_time = 0;
  String callsign;
  String nr;
  String section;
  byte cq_answered = 0;
  unsigned long transition_time = 0;
  byte current_field = FIELD_CALLSIGN;

  int previous_sidetone = configuration.hz_sidetone;
  int previous_wpm = configuration.wpm;
  int caller_sidetone = 0;
  int caller_wpm_delta = 0;

  while (port_to_use->available() > 0) {  // clear out the buffer if anything is there
    port_to_use->read();
  }  

  term.init();
  term.cls(); 
  term.position(0,0);  
  term.println(F("\nPA QSO Party Practice\n"));
  term.println(F("This requires VT100 emulation!\n"));
  term.println(F("F1 - Call CQ"));
  term.println(F("F2 - Exchange"));
  term.println(F("F3 - TU"));
  term.println(F("Insert - Callsign + Exchange"));
  term.println(F("\\ - Exit\n"));
  term.println(F("Callsign  NR  Section"));
  term.println(F("-------- ---- -------\n\n"));    
  
  while (loop1){
    
    
    // get user keyboard input
    if (port_to_use->available()){      
      user_input_buffer[user_input_buffer_characters] = toupper(port_to_use->read());
      switch(user_input_buffer[user_input_buffer_characters]){                    
        case 27: //escape
          escape_flag_time = millis();
          user_input_buffer_characters++;
        case 13: //return
        case 32: //space
          process_user_input_buffer = 1;
          break;
        case 127:
        case 8: //backspace
          if (user_input_buffer_characters > 0){user_input_buffer_characters--;}
          port_to_use->write(27);
          port_to_use->write(91);
          port_to_use->write(49);
          port_to_use->write(68);
          break;

          
        default:
          if (!(((user_input_buffer[user_input_buffer_characters-1] == 27) && (user_input_buffer[user_input_buffer_characters] == 79) && (user_input_buffer_characters>0)) ||
          ((user_input_buffer[user_input_buffer_characters-2] == 27) && (user_input_buffer[user_input_buffer_characters-1] == 79) && (user_input_buffer_characters>1)))){
            port_to_use->write(user_input_buffer[user_input_buffer_characters]);
          }
          user_input_buffer_characters++;
          break;                 
      } //switch(user_input_buffer[user_input_buffer_characters])
      if (user_input_buffer_characters == 10){process_user_input_buffer = 1;}
        
    }//(port_to_use->available())
    
    
    // process user keyboard input
    if ((process_user_input_buffer) && ((escape_flag_time == 0) || ((millis()-escape_flag_time) > 100))){ 
   
      #ifdef DEBUG_CW_PRACTICE
      debug_serial_port->print(F("escape_flag_time: process_user_input_buffer user_input_buffer_characters:"));
      debug_serial_port->println(user_input_buffer_characters);
      #endif
      
      if (user_input_buffer_characters > 0){
        if (user_input_buffer[0] == '\\'){  // does user want to exit?
          loop1 = 0;
        } else {
          if (user_input_buffer[0] == 27){
            if (user_input_buffer_characters == 3){
              if ((user_input_buffer[1] == 79) && (user_input_buffer[2] == 80)) {  //VT100 F1 key
                configuration.hz_sidetone = previous_sidetone;
                configuration.wpm = previous_wpm;
                add_to_send_buffer('C');
                add_to_send_buffer('Q');
                add_to_send_buffer(' ');
                add_to_send_buffer('T');
                add_to_send_buffer('E');
                add_to_send_buffer('S');
                add_to_send_buffer('T');
                add_to_send_buffer(' ');
                add_to_send_buffer('D');
                add_to_send_buffer('E');
                add_to_send_buffer(' ');
                add_to_send_buffer('K');
                add_to_send_buffer('3');
                add_to_send_buffer('N');
                add_to_send_buffer('G');
                overall_state = CONTEST_PRACTICE_CQ_SENT;
                transition_time = millis();
              } //((user_input_buffer[1] == 79) && (user_input_buffer[2] == 80)) VT100 F1 key       
            } //(user_input_buffer_characters == 3)
            if (user_input_buffer_characters == 4){
              if ((user_input_buffer[1] == 91) && (user_input_buffer[2] == 50)  && (user_input_buffer[3] == 126)) { //VT100 INS key
                for (byte x = 0; x < user_input_buffer_characters; x++) {
                  add_to_send_buffer(user_input_buffer[x]);
                }    
                add_to_send_buffer(' ');         
                add_to_send_buffer('0');
                add_to_send_buffer('0');
                add_to_send_buffer('1');
                add_to_send_buffer(' ');
                add_to_send_buffer('C');
                add_to_send_buffer('A');
                add_to_send_buffer('R');
                configuration.hz_sidetone = previous_sidetone;
                configuration.wpm = previous_wpm;              
                overall_state = CONTEST_PRACTICE_REPORT_SENT;
              }
            } //(user_input_buffer_characters == 4)

          } else { //(user_input_buffer[0] == 27)
          
          // we have a callsign, nr, or section
          
            switch(current_field){
              case FIELD_CALLSIGN:
                callsign = "";
                for (byte x = 0; x < user_input_buffer_characters; x++) {
                  callsign.concat(char(user_input_buffer[x]));
                } 
                current_field = FIELD_NR;
                break;
                
              case FIELD_NR:
                nr = "";
                for (byte x = 0; x < user_input_buffer_characters; x++) {
                  nr.concat(char(user_input_buffer[x]));
                }               
                current_field = FIELD_SECTION;
                break;
                
              case FIELD_SECTION:
                section = "";
                for (byte x = 0; x < user_input_buffer_characters; x++) {
                  section.concat(char(user_input_buffer[x]));
                }               
                current_field = FIELD_CALLSIGN;
                break;
              
            }
            term.position(13,0);
            term.print(callsign);
            term.position(13,9);
            term.print(nr);
            term.position(13,14);
            term.println(section);
            term.position(15,0);
            term.print(F("                     ")); 
            term.position(15,0);           
            
          }

        } //(user_input_buffer[0] == '\\')
      } //(user_input_buffer_characters > 0)
      process_user_input_buffer = 0; 
      user_input_buffer_characters = 0;    
      escape_flag_time = 0;
    } //((process_user_input_buffer) && ((escape_flag_time == 0) || ((millis() -escape_flag_time) > 100)))
  
    //do autonomous events
    service_send_buffer(NOPRINT);
    
    switch(overall_state){
      case CONTEST_PRACTICE_CQ_SENT:
        if (send_buffer_bytes == 0){
          if (!cq_answered){
            if (((millis() - transition_time) > random(250,1500))){  // add some random delay
              callsign = generate_callsign();
              caller_sidetone = random(500,1000);
              configuration.hz_sidetone = caller_sidetone;
              caller_wpm_delta = random(-5,5);
              configuration.wpm = configuration.wpm + caller_wpm_delta;
              for (byte x = 0; x < (callsign.length()); x++) {
                add_to_send_buffer(callsign[x]);
              }
              cq_answered = 1;
              transition_time = millis();
            }
          } else {  //send it again
            if ((cq_answered) && ((millis() - transition_time) > random(2000,4000))){
              configuration.hz_sidetone = caller_sidetone;
              configuration.wpm = configuration.wpm + caller_wpm_delta;
              for (byte x = 0; x < (callsign.length()); x++) {
                add_to_send_buffer(callsign[x]);
              }            
              cq_answered++;
              transition_time = millis();            
            }
          }
        } else {
          transition_time = millis();
        } //send_buffer_bytes == 0
        break;  //CONTEST_PRACTICE_CQ_SENT
      
      
    } //switch(overall_state)
    

  } //while (loop1)
  
  configuration.hz_sidetone = previous_sidetone;
  configuration.wpm = previous_wpm;
  send_buffer_bytes = 0;

}  
#endif

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_CALLSIGN_RECEIVE_PRACTICE) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_cw_practice(HardwareSerial * port_to_use){
  

  byte menu_loop = 1;
  byte menu_loop2 = 1;
  char incoming_char = ' ';
  
  while(menu_loop){
  
    while (port_to_use->available() > 0) {  // clear out the buffer if anything is there
      port_to_use->read();
    }  
    
    port_to_use->println("CW Practice\n");
    port_to_use->println("1 - US Callsigns");
    port_to_use->println("2 - PA QSO Party");
    port_to_use->println("0 - eXit\n");
    
    menu_loop2 = 1;
    
    while (menu_loop2){
    
      if (port_to_use->available()){
        incoming_char = port_to_use->read();
        menu_loop2 = 0;
      }
    }
      
      
    //port_to_use->println(incoming_char);
    
    switch(incoming_char){
      case '0': menu_loop = 0; break;
      case '1': us_callsign_practice(port_to_use); break;
      case '2': paqso_practice(port_to_use); break;
        
        
    } //switch(incoming_char)
    
 
    
  } //while(menu_loop)
      
  port_to_use->println(F("Exiting practice mode..."));
  
  
}
#endif


//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_CALLSIGN_RECEIVE_PRACTICE) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void us_callsign_practice(HardwareSerial * port_to_use)
{

  byte loop1 = 1;
  byte loop2 = 0;
  byte serialwaitloop = 0;
  String callsign(10);
  char incoming_char = ' ';
  String user_entered_callsign = "";

  byte previous_key_tx_state = key_tx;
  key_tx = 0;
  //randomSeed(analogRead(0));
  randomSeed(millis());
  port_to_use->println(F("Callsign receive practice; type in callsign and hit ENTER."));
  port_to_use->println(F("If you are using the Arduino serial monitor, select \"Carriage Return\" line ending."));
  port_to_use->println(F("Enter a blackslash \\ to exit."));
  while (port_to_use->available() > 0) {  // clear out the buffer if anything is there
    incoming_char = port_to_use->read();
  }
  port_to_use->print(F("Press enter to start..."));
  while (port_to_use->available() == 0) {
  }
  while (port_to_use->available() > 0) {  // clear out the buffer if anything is there
    incoming_char = port_to_use->read();
  }

  while (loop1){

    callsign = generate_callsign();
    loop2 = 1;
    
    while (loop2){

      for (byte x = 0; x < (callsign.length()); x++) {
        send_char(callsign[x],KEYER_NORMAL);
      }
  
  
      //port_to_use->println(callsign);
  
      serialwaitloop = 1;
      user_entered_callsign = "";
      while (serialwaitloop) {
        if (port_to_use->available() > 0) {
          incoming_char = port_to_use->read();
          port_to_use->print(incoming_char);
          if (incoming_char == 13) {
            serialwaitloop = 0;
          } else {
            if (incoming_char != 10) {
              user_entered_callsign = user_entered_callsign + incoming_char;
            }
          }
        }
      }
  
      if (user_entered_callsign[0] != '?') {
        if ((user_entered_callsign[0] == '\\')){
          port_to_use->println(F("Exiting...\n"));
          loop1 = 0;
          loop2 = 0;
        } else {
          user_entered_callsign.toUpperCase();  // the toUpperCase function was modified in 1.0; now it changes string in place
          if (callsign.compareTo(user_entered_callsign) == 0) {
            port_to_use->println(F("\nCorrect!"));
            loop2 = 0;
          } else {
            port_to_use->print(F("\nWrong!"));
            //port_to_use->println(callsign);
            //loop2 = 0;
          }
        }
      }
  
      delay(100);
      #ifdef FEATURE_COMMAND_BUTTONS
      while ((paddle_pin_read(paddle_left) == LOW) || (paddle_pin_read(paddle_right) == LOW) || (analogbuttonread(0))) {
        loop1 = 0;
        loop2 = 0;
      }
      #else 
      while ((paddle_pin_read(paddle_left) == LOW) || (paddle_pin_read(paddle_right) == LOW)) {
        loop1 = 0;
        loop2 = 0;
      }    
      #endif //FEATURE_COMMAND_BUTTONS
      delay(10);
    } //loop2
  } //loop1
  
  key_tx = previous_key_tx_state;
}
#endif //defined(FEATURE_SERIAL) && defined(FEATURE_CALLSIGN_RECEIVE_PRACTICE) && defined(FEATURE_COMMAND_LINE_INTERFACE)

//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_status(HardwareSerial * port_to_use) {

  port_to_use->println();
  switch (configuration.keyer_mode) {
    case IAMBIC_A: port_to_use->print(F("Iambic A")); break;
    case IAMBIC_B: port_to_use->print(F("Iambic B")); 
      #ifdef FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
        port_to_use->print(F(" / CMOS Super Keyer Timing: O"));
        if (configuration.cmos_super_keyer_iambic_b_timing_on) {
          port_to_use->print("N ");
          port_to_use->print(configuration.cmos_super_keyer_iambic_b_timing_percent);
          port_to_use->print("%");
        } else {
         port_to_use->print("FF");
        }
      #endif //FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
      break;
    case BUG: port_to_use->print(F("Bug")); break;
    case STRAIGHT: port_to_use->print(F("Straightkey")); break;
    case ULTIMATIC: port_to_use->print(F("Ultimatic")); break;
  }
  port_to_use->println();
  #ifdef FEATURE_DIT_DAH_BUFFER_CONTROL
    port_to_use->print(F("Buffers: Dit O"));
    if (configuration.dit_buffer_off){
      port_to_use->print(F("FF"));
    } else {
      port_to_use->print(F("N"));
    }
    port_to_use->print(F(" Dah O"));
    if (configuration.dah_buffer_off){
      port_to_use->println(F("FF"));
    } else {
      port_to_use->println(F("N"));
    }
  #endif //FEATURE_DIT_DAH_BUFFER_CONTROL  
  if (speed_mode == SPEED_NORMAL) {
    port_to_use->print(F("WPM: "));
    port_to_use->println(configuration.wpm,DEC);
    #ifdef FEATURE_FARNSWORTH
      port_to_use->print(F("Farnsworth WPM: "));
      if (configuration.wpm_farnsworth < configuration.wpm) {
        port_to_use->println(F("disabled"));
      } else {
        port_to_use->println(configuration.wpm_farnsworth,DEC);
      }
    #endif //FEATURE_FARNSWORTH
  } else {
    port_to_use->print(F("QRSS Mode Activated - Dit Length: "));
    port_to_use->print(qrss_dit_length,DEC);
    port_to_use->println(" seconds");
  }
  port_to_use->print(F("Sidetone:"));
  switch (configuration.sidetone_mode) {
    case SIDETONE_ON: port_to_use->print(F("ON")); break;
    case SIDETONE_OFF: port_to_use->print(F("OFF")); break;
    case SIDETONE_PADDLE_ONLY: port_to_use->print(F("Paddle Only")); break;
  }
  port_to_use->print(" ");
  port_to_use->print(configuration.hz_sidetone,DEC);
  port_to_use->println(" hz");
  port_to_use->print(F("Dah to dit: "));
  port_to_use->println((float(configuration.dah_to_dit_ratio)/100));
  port_to_use->print(F("Weighting: "));
  port_to_use->println(configuration.weighting,DEC);
  port_to_use->print(F("Serial Number: "));
  port_to_use->println(serial_number,DEC);
  #ifdef FEATURE_POTENTIOMETER
    port_to_use->print(F("Potentiometer WPM: "));
    port_to_use->print(pot_value_wpm(),DEC);
    port_to_use->print(F(" ("));
    if (configuration.pot_activated != 1) {
      port_to_use->print(F("not "));
    }
    port_to_use->println("activated)");
  #endif
  #ifdef FEATURE_AUTOSPACE
    port_to_use->print(F("Autospace O"));
    if (configuration.autospace_active) {
      port_to_use->println("n");
    } else {
      port_to_use->println("ff");
    }
  #endif
  port_to_use->print("Wordspace: ");
  port_to_use->println(configuration.length_wordspace,DEC);
  port_to_use->print("TX: ");
  port_to_use->println(configuration.current_tx);  


  #ifdef FEATURE_QLF
    port_to_use->print("QLF: O");
    if (qlf_active){
      port_to_use->println("n");
    } else {
      port_to_use->println("ff");
    }
  #endif //FEATURE_QLF

  #ifdef FEATURE_MEMORIES
    serial_status_memories(port_to_use);
  #endif

  #ifdef DEBUG_MEMORYCHECK
    memorycheck();
  #endif

  #ifdef DEBUG_VARIABLE_DUMP
    port_to_use->println(configuration.wpm);
    #ifdef FEATURE_FARNSWORTH
      port_to_use->println(configuration.wpm_farnsworth);
    #endif //FEATURE_FARNSWORTH
    port_to_use->println(1.0*(float(configuration.weighting)/50));
    port_to_use->println(keying_compensation,DEC);
    port_to_use->println(2.0-(float(configuration.weighting)/50));
    port_to_use->println(-1.0*keying_compensation);
    port_to_use->println((dit_end_time-dit_start_time),DEC);
    port_to_use->println((dah_end_time-dah_start_time),DEC);
    port_to_use->println(millis(),DEC);
  #endif //DEBUG_VARIABLE_DUMP
  
  #ifdef DEBUG_BUTTONS
  for (int x = 0;x < analog_buttons_number_of_buttons;x++) {
    port_to_use->print(F("analog_button_array:   "));
    port_to_use->print(x);
    port_to_use->print(F(" button_array_low_limit: "));
    port_to_use->print(button_array_low_limit[x]);
    port_to_use->print(F("  button_array_high_limit: "));
    port_to_use->println(button_array_high_limit[x]);
  }
  #endif 
  
}
#endif
//---------------------------------------------------------------------

int convert_cw_number_to_ascii (long number_in)
{

 switch (number_in) {
   case 12: return 65; break;         // A
   case 2111: return 66; break;
   case 2121: return 67; break;
   case 211: return 68; break;
   case 1: return 69; break;
   case 1121: return 70; break;
   case 221: return 71; break;
   case 1111: return 72; break;
   case 11: return 73; break;
   case 1222: return 74; break;
   case 212: return 75; break;
   case 1211: return 76; break;
   case 22: return 77; break;
   case 21: return 78; break;
   case 222: return 79; break;
   case 1221: return 80; break;
   case 2212: return 81; break;
   case 121: return 82; break;
   case 111: return 83; break;
   case 2: return 84; break;
   case 112: return 85; break;
   case 1112: return 86; break;
   case 122: return 87; break;
   case 2112: return 88; break;
   case 2122: return 89; break;
   case 2211: return 90; break;    // Z

   case 22222: return 48; break;    // 0
   case 12222: return 49; break;
   case 11222: return 50; break;
   case 11122: return 51; break;
   case 11112: return 52; break;
   case 11111: return 53; break;
   case 21111: return 54; break;
   case 22111: return 55; break;
   case 22211: return 56; break;
   case 22221: return 57; break;
   case 112211: return '?'; break;  // ?
   case 21121: return 47; break;   // /
   case 2111212: return '*'; break; // BK   
   case 221122: return 44; break;  // ,
   case 121212: return '.'; break;
   case 122121: return '@'; break;
   case 222222: return 92; break;  // special hack; six dahs = \ (backslash)
   //case 2222222: return '+'; break;
   case 9: return 32; break;       // special 9 = space
   
   #ifndef OPTION_PS2_NON_ENGLISH_CHAR_LCD_DISPLAY_SUPPORT
   case 21112: return '='; break;
   case 12121: return '+'; break;
   #else
   case 211112: return 45; break; // - // sp5iou
   case 21112: return 61; break; // = //sp5iou
   case 212122: return 33; break; // ! //sp5iou
   //case 121212: return 46; break; // . //sp5iou
   case 1112112: return 36; break; // $ //sp5iou
   case 12111: return 38; break; // & // sp5iou
   //case 221122: return 44; break; // ,
   case 122221: return 39; break; // ' // sp5iou
   case 121121: return 34; break; // " // sp5iou
   case 112212: return 95; break; // _ // sp5iou
   case 212121: return 59; break; // ; // sp5iou
   case 222111: return 58; break; // : // sp5iou
   case 212212: return 41; break; // KK (stored as ascii ) ) // sp5iou
   case 111212: return 62; break; // SK (stored as ascii > ) // sp5iou
   case 12121: return 60; break; // AR (store as ascii < ) // sp5iou
   case 21221: return 40; break; // (KN store as ascii ( ) //sp5iou
   #endif //OPTION_PS2_NON_ENGLISH_CHAR_LCD_DISPLAY_SUPPORT


   #ifdef OPTION_NON_ENGLISH_EXTENSIONS
     // for English/Cyrillic/Western European font LCD controller (HD44780UA02):
     case 12212: return 197; break;     // 'Å' - AA_capital (OZ, LA, SM)
     //case 12212: return 192; break;   // 'À' - A accent   
     case 1212: return 198; break;      // 'Æ' - AE_capital   (OZ, LA)
     //case 1212: return 196; break;    // 'Ä' - A_umlaut (D, SM, OH, ...)
     case 2222: return 138; break;      // CH  - (Russian letter symbol)
     case 22122: return 209; break;     // 'Ñ' - (EA)               
     //case 2221: return 214; break;    // 'Ö' – O_umlaut  (D, SM, OH, ...)
     //case 2221: return 211; break;    // 'Ò' - O accent
     case 2221: return 216; break;      // 'Ø' - OE_capital    (OZ, LA)
     case 1122: return 220; break;      // 'Ü' - U_umlaut     (D, ...)
     case 111111: return 223; break;    // beta - double S    (D?, ...)   


     
     case 21211: return 199; break;   // Ç
     case 11221: return 208; break;   // Ð
     case 12112: return 200; break;   // È
     case 11211: return 201; break;   // É
     case 221121: return 142; break;  // Ž
   #endif //OPTION_NON_ENGLISH_EXTENSIONS


   //default: return 254; break;
   default: 
     #ifdef OPTION_UNKNOWN_CHARACTER_ERROR_TONE
       boop();
     #endif  //OPTION_UNKNOWN_CHARACTER_ERROR_TONE
     return unknown_cw_character; 
     break;

 }

}

//---------------------------------------------------------------------
#ifdef DEBUG_MEMORYCHECK
void memorycheck()
{
  void* HP = malloc(4);
  if (HP)
    free (HP);

  unsigned long free = (unsigned long)SP - (unsigned long)HP;

//  port_to_use->print("Heap=");
//  port_to_use->println((unsigned long)HP,HEX);
//  port_to_use->print("Stack=");
//  port_to_use->println((unsigned long)SP,HEX);
//  port_to_use->print("Free Memory = ");
//  port_to_use->print((unsigned long)free,HEX);
//  port_to_use->print("  ");
  if (free > 2048) {
    free = 0;
  }
  if (primary_serial_port_mode == SERIAL_CLI) {
    port_to_use->print((unsigned long)free,DEC);
    port_to_use->println(F(" bytes free"));
  }
}
#endif

//---------------------------------------------------------------------

#ifdef FEATURE_MEMORIES
void initialize_eeprom_memories()
{
  for (int x = 0; x < number_of_memories; x++) {
    EEPROM.write(memory_start(x),255);
  }
}
#endif

//---------------------------------------------------------------------

#if defined(FEATURE_MEMORIES) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_status_memories(HardwareSerial * port_to_use)
{
  int last_memory_location;

  for (int x = 0; x < number_of_memories; x++) {
    last_memory_location = memory_end(x) + 1 ;
    port_to_use->write("Memory ");
    port_to_use->print(x+1);
    port_to_use->write(":");
    if ( EEPROM.read(memory_start(x)) == 255) {
      port_to_use->write("{empty}");
    } else {
      for (int y = (memory_start(x)); (y < last_memory_location); y++) {
        if (EEPROM.read(y) < 255) {
          port_to_use->write(EEPROM.read(y));
        } else {
          port_to_use->write("$");
          y = last_memory_location;
        }
      }
    }
    port_to_use->println();
  }
}
#endif

//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_MEMORIES) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_program_memory(HardwareSerial * port_to_use)
{

  byte incoming_serial_byte;
  byte memory_number;
  byte looping = 1;
  int memory_index = 0;

  while (port_to_use->available() == 0) {        // wait for the next keystroke
    if (keyer_machine_mode == KEYER_NORMAL) {          // might as well do something while we're waiting
      check_paddles();
      service_dit_dah_buffers();
      //check_the_memory_buttons();
    }
  }
  incoming_serial_byte = port_to_use->read();
  if (incoming_serial_byte == 48) {incoming_serial_byte = 58;} // 0 = memory 10
  if ((incoming_serial_byte > 48) && (incoming_serial_byte < (49 + number_of_memories))) {    
    memory_number = incoming_serial_byte - 49;
    port_to_use->print(memory_number+1);
    while (looping) {
      while (port_to_use->available() == 0) {
        if (keyer_machine_mode == KEYER_NORMAL) {          // might as well do something while we're waiting
          check_paddles();
          service_dit_dah_buffers();
        }
      }
      incoming_serial_byte = port_to_use->read();
      if (incoming_serial_byte == 13) {        // did we get a carriage return?
        looping = 0;
      } else {
        port_to_use->write(incoming_serial_byte);
        incoming_serial_byte = uppercase(incoming_serial_byte);
        EEPROM.write((memory_start(memory_number)+memory_index),incoming_serial_byte);
        #ifdef DEBUG_EEPROM
        debug_serial_port->print(F("serial_program_memory: wrote "));
        debug_serial_port->print(incoming_serial_byte);
        debug_serial_port->print(F(" to location "));
        debug_serial_port->println((memory_start(memory_number)+memory_index));
        #endif
        memory_index++;
        if ((memory_start(memory_number) + memory_index) == memory_end(memory_number)) {    // are we at last memory location?
          looping = 0;
          port_to_use->println(F("Memory full, truncating."));
        }
      }
    }  //while (looping)
    // write terminating 255
    EEPROM.write((memory_start(memory_number)+memory_index),255);
    #ifdef DEBUG_EEPROM
      debug_serial_port->print(F("serial_program_memory: wrote 255 to location "));
      debug_serial_port->println((memory_start(memory_number)+memory_index));
    #endif
    port_to_use->print(F("\n\rWrote memory #"));
    port_to_use->print(memory_number+1);
    port_to_use->println();
  } else {
    port_to_use->println(F("\n\rError"));
  }

}

#endif


//---------------------------------------------------------------------

#if defined(FEATURE_MEMORIES) && defined(FEATURE_COMMAND_BUTTONS)
void command_program_memory()
{
  int cw_char;
  cw_char = get_cw_input_from_user(0);            // get another cw character from the user to find out which memory number
  #ifdef DEBUG_COMMAND_MODE
  debug_serial_port->print(F("command_program_memory: cw_char: "));
  debug_serial_port->println(cw_char);
  #endif
  if (cw_char > 0) {
    if ((cw_char == 12222) && (number_of_memories > 9)) { // we have a 1, this could be 1 or 1x
      cw_char = get_cw_input_from_user((1200/configuration.wpm)*14);  // give the user some time to enter a second digit
      switch (cw_char) {
        case 0: program_memory(0); break;    // we didn't get anything, it's a 1   
        case 22222: program_memory(9); break; 
        case 12222: program_memory(10); break;
        case 11222: program_memory(11); break;
        case 11122: program_memory(12); break;
        case 11112: program_memory(13); break;
        case 11111: program_memory(14); break;
        case 21111: program_memory(15); break;
        default: send_char('?',KEYER_NORMAL); break;
      }
    } else {    
      switch (cw_char) {
        case 12222: program_memory(0); break;      // 1 = memory 0
        case 11222: program_memory(1); break;
        case 11122: program_memory(2); break;
        case 11112: program_memory(3); break;
        case 11111: program_memory(4); break;
        case 21111: program_memory(5); break;
        case 22111: program_memory(6); break;
        case 22211: program_memory(7); break;
        case 22221: program_memory(8); break;
        //case 22222: program_memory(9); break;
        default: send_char('?',KEYER_NORMAL); break;
      }
    }
  }
}
#endif //FEATURE_COMMAND_BUTTONS

//---------------------------------------------------------------------

#ifdef FEATURE_MEMORIES
byte memory_nonblocking_delay(unsigned long delaytime)
{
  // 2012-04-20 was long starttime = millis();
  unsigned long starttime = millis();

  while ((millis() - starttime) < delaytime) {
    check_paddles();
    #ifdef FEATURE_COMMAND_BUTTONS
    if (((dit_buffer) || (dah_buffer) || (analogbuttonread(0))) && (keyer_machine_mode != BEACON)) {   // exit if the paddle or button0 was hit
    #else
    if (((dit_buffer) || (dah_buffer)) && (keyer_machine_mode != BEACON)) {   // exit if the paddle or button0 was hit
    #endif
      dit_buffer = 0;
      dah_buffer = 0;
      #ifdef FEATURE_COMMAND_BUTTONS
      while (analogbuttonread(0)) {}
      #endif
      return 1;
    }
  }
  return 0;
}

#endif

//---------------------------------------------------------------------
void check_button0()
{
  #ifdef FEATURE_COMMAND_BUTTONS
    if (analogbuttonread(0)) {button0_buffer = 1;}
  #endif
}

//---------------------------------------------------------------------

#ifdef FEATURE_MEMORIES
void play_memory(byte memory_number)
{
  
  unsigned int jump_back_to_y = 99999;
  byte jump_back_to_memory_number = 255;

  if (memory_number > (number_of_memories - 1)) {
    boop();
    return;
  }

  String serial_number_string;
  static byte prosign_flag = 0;
  play_memory_prempt = 0;
  byte eeprom_byte_read;

  #ifdef DEBUG_PLAY_MEMORY
    debug_serial_port->print(F("play_memory: called with memory_number:"));
    debug_serial_port->println(memory_number);
  #endif  
  
  #ifdef FEATURE_MEMORY_MACROS
    byte eeprom_byte_read2;
    int z;
    byte input_error;
    byte delay_result = 0;
    int int_from_macro;
  #endif //FEATURE_MEMORY_MACROS

  button0_buffer = 0;

//  #ifdef DEBUG_MEMORYCHECK
//  memorycheck();
//  #endif

  if (keyer_machine_mode == KEYER_NORMAL) {
    #if defined(FEATURE_SERIAL)
      #ifdef FEATURE_WINKEY_EMULATION
        if (primary_serial_port_mode != SERIAL_WINKEY_EMULATION) {
          primary_serial_port->println();
        }
      #else
        primary_serial_port->println();
      #endif

      #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
        secondary_serial_port->println();
      #endif //FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
    #endif
  }
  
  for (int y = (memory_start(memory_number)); (y < (memory_end(memory_number)+1)); y++) {

    if (keyer_machine_mode == KEYER_NORMAL) {
      #ifdef FEATURE_POTENTIOMETER
        check_potentiometer();
      #endif
      
      #ifdef FEATURE_ROTARY_ENCODER
        check_rotary_encoder();
      #endif //FEATURE_ROTARY_ENCODER      
      
      #ifdef FEATURE_PS2_KEYBOARD
        check_ps2_keyboard();
      #endif

      check_button0();

      #ifdef FEATURE_DISPLAY
        service_display();
      #endif
    }

    #if defined(FEATURE_SERIAL)
      check_serial();
    #endif

    if ((play_memory_prempt == 0) && (pause_sending_buffer == 0)) {
      eeprom_byte_read = EEPROM.read(y);
      if (eeprom_byte_read < 255) {

        #ifdef DEBUG_PLAY_MEMORY
          debug_serial_port->println(F("\n\nplay_memory:\r"));
          debug_serial_port->print(F("    Memory number:"));
          debug_serial_port->println(memory_number);
          debug_serial_port->print(F("    EEPROM location:"));
          debug_serial_port->println(y);
          debug_serial_port->print(F("    eeprom_byte_read:"));
          debug_serial_port->println(eeprom_byte_read);
        #endif

        if (eeprom_byte_read != 92) {          // do we have a backslash?
          if (keyer_machine_mode == KEYER_NORMAL) {
            #if defined(FEATURE_SERIAL)
              #ifndef FEATURE_WINKEY_EMULATION
                if (!cw_send_echo_inhibit) {
                  primary_serial_port->write(eeprom_byte_read);
                  #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
                  secondary_serial_port->write(eeprom_byte_read);
                  #endif //FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
                }
              #else  //FEATURE_WINKEY_EMULATION
                if (((primary_serial_port_mode == SERIAL_WINKEY_EMULATION) && (winkey_paddle_echo_activated) && (winkey_host_open)) || (primary_serial_port_mode != SERIAL_WINKEY_EMULATION)) {
                  winkey_port_write(eeprom_byte_read);
                }
                #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
                  secondary_serial_port->write(eeprom_byte_read);
                #endif //FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT                
              #endif //FEATURE_WINKEY_EMULATION
            #endif //FEATURE_SERIAL
            #ifdef FEATURE_DISPLAY
              if (lcd_send_echo) {
                display_scroll_print_char(eeprom_byte_read); 
                service_display();
              }
            #endif            
          }

          if (prosign_flag) {
            send_char(eeprom_byte_read,OMIT_LETTERSPACE);
            prosign_flag = 0;
          } else {
            send_char(eeprom_byte_read,KEYER_NORMAL);         // no - play the character
          }
        } else {                               // yes - we have a backslash command ("macro")
          y++;                                 // get the next memory byte
          #ifdef FEATURE_MEMORY_MACROS
          if (y < (memory_end(memory_number)+1)) {
            eeprom_byte_read = EEPROM.read(y);            // memory macros (backslash commands)
            switch (eeprom_byte_read) {
              case 48:                         // 0 - jump to memory 10
                eeprom_byte_read = 58;
              case 49:                         // 1 - jump to memory 1
              case 50:                         // 2 - jump to memory 2
              case 51:                         // 3 - jump to memory 3
              case 52:                         // 4 - jump to memory 4
              case 53:                         // 5 - jump to memory 5
              case 54:                         // 6 - jump to memory 6
              case 55:                         // 7 - jump to memory 7
              case 56:                         // 8 - jump to memory 8
              case 57:                         // 9 - jump to memory 9
                if (number_of_memories > (eeprom_byte_read-49)) {
                  memory_number = (eeprom_byte_read-49);
                  y = ((memory_start(memory_number)) - 1);
                  if (keyer_machine_mode == KEYER_NORMAL) {
                    primary_serial_port->println();
                    #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
                      secondary_serial_port->println();
                    #endif //FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
                  }
                }
                break;
              case 'I': // insert memory #
                y++;
                if (y < (memory_end(memory_number)+1)) {  // get the next byte           
                 eeprom_byte_read = EEPROM.read(y);                 
                  if (number_of_memories > (eeprom_byte_read-49)) {
                    jump_back_to_y = y;
                    jump_back_to_memory_number = memory_number;
                    memory_number = (eeprom_byte_read-49);
                    y = ((memory_start(memory_number)) - 1);
                    if (keyer_machine_mode == KEYER_NORMAL) {
                      primary_serial_port->println();
                      #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
                        secondary_serial_port->println();
                      #endif //FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
                    }
                  }       
                }           
                break;
          
              case 'S': // insert space
                send_char(' ',KEYER_NORMAL);
                break;

              case 88:                         // X - switch transmitter
                y++;
                if (y < (memory_end(memory_number)+1)) {
                  eeprom_byte_read2 = EEPROM.read(y);
                  if ((eeprom_byte_read2 > 48) && (eeprom_byte_read2 < 52)) {
                     switch (eeprom_byte_read2) {
                       case 49: switch_to_tx_silent(1); break;
                       case 50: if ((ptt_tx_2) || (tx_key_line_2)) {switch_to_tx_silent(2); } break;
                       case 51: if ((ptt_tx_3) || (tx_key_line_3)) {switch_to_tx_silent(3); } break;
                       case 52: if ((ptt_tx_4) || (tx_key_line_4)) {switch_to_tx_silent(4); } break;
                       case 53: if ((ptt_tx_5) || (tx_key_line_5)) {switch_to_tx_silent(5); } break;
                       case 54: if ((ptt_tx_6) || (tx_key_line_6)) {switch_to_tx_silent(6); } break;
                     }
                  }

                }
                break;  // case 84

              case 67:                       // C - play serial number with cut numbers T and N, then increment
                  serial_number_string = String(serial_number, DEC);
                  if (serial_number_string.length() < 3 ) {
                    send_char('T',KEYER_NORMAL);
                  }
                  if (serial_number_string.length() == 1) {
                    send_char('T',KEYER_NORMAL);
                  }
                  for (unsigned int a = 0; a < serial_number_string.length(); a++)  {
                    if (serial_number_string[a] == '0') {
                      send_char('T',KEYER_NORMAL);
                    } else {
                     if (serial_number_string[a] == '9') {
                       send_char('N',KEYER_NORMAL);
                     } else {
                       send_char(serial_number_string[a],KEYER_NORMAL);
                     }
                    }
                  }
                  serial_number++;
                break;

              case 68:                      // D - delay for ### seconds
                int_from_macro = 0;
                z = 100;
                input_error = 0;
                for (int x = 1; x < 4; x ++) {
                  y++;
                  if (y < (memory_end(memory_number)+1)) {
                    eeprom_byte_read2 = EEPROM.read(y);
                    if ((eeprom_byte_read2 > 47) && (eeprom_byte_read2 < 58)) {    // ascii 48-57 = "0" - "9")
                      int_from_macro = int_from_macro + ((eeprom_byte_read2 - 48) * z);
                      z = z / 10;
                    } else {
                      x = 4;           // error - exit
                      input_error = 1;
                      y--;             // go back one so we can at least play the errant character
                    }
                  } else {
                    x = 4;
                    input_error = 1;
                  }
                }
                if (input_error != 1) {   // do the delay
                  delay_result = memory_nonblocking_delay(int_from_macro*1000);
                }
                if (delay_result) {   // if a paddle or button0 was hit during the delay, exit
                  return;
                }
                break;  // case 68

              case 69:                       // E - play serial number, then increment
                  serial_number_string = String(serial_number, DEC);
                  for (unsigned int a = 0; a < serial_number_string.length(); a++)  {
                    send_char(serial_number_string[a],KEYER_NORMAL);
                  }
                  serial_number++;
                break;

              case 70:                       // F - change sidetone frequency
                int_from_macro = 0;
                z = 1000;
                input_error = 0;
                for (int x = 1; x < 5; x ++) {
                  y++;
                  if (y < (memory_end(memory_number)+1)) {
                    eeprom_byte_read2 = EEPROM.read(y);
                    if ((eeprom_byte_read2 > 47) && (eeprom_byte_read2 < 58)) {    // ascii 48-57 = "0" - "9")
                      int_from_macro = int_from_macro + ((eeprom_byte_read2 - 48) * z);
                      z = z / 10;
                    } else {
                      x = 5;           // error - exit
                      input_error = 1;
                      y--;             // go back one so we can at least play the errant character
                    }
                  }  else {
                    x = 4;
                    input_error = 1;
                  }
                }
                if ((input_error != 1) && (int_from_macro > SIDETONE_HZ_LOW_LIMIT) && (int_from_macro < SIDETONE_HZ_HIGH_LIMIT)) {
                  configuration.hz_sidetone = int_from_macro;
                }
                break;


              case 72:                       // H - Switch to Hell
                char_send_mode = HELL;
                break;

              case 76:                       // L - Switch to CW
                char_send_mode = CW;
                break;

              case 78:                       // N - decrement serial number (do not play)
                serial_number--;
                break;

              case 43:                       // + - Prosign
                prosign_flag = 1;
                break;

              case 81:                       // Q - QRSS mode and set dit length to ##
                int_from_macro = 0;
                z = 10;
                input_error = 0;
                for (int x = 1; x < 3; x ++) {
                  y++;
                  if (y < (memory_end(memory_number)+1)) {
                    eeprom_byte_read2 = EEPROM.read(y);
                    if ((eeprom_byte_read2 > 47) && (eeprom_byte_read2 < 58)) {    // ascii 48-57 = "0" - "9")
                      int_from_macro = int_from_macro + ((eeprom_byte_read2 - 48) * z);
                      z = z / 10;
                    } else {
                      x = 4;           // error - exit
                      input_error = 1;
                      y--;             // go back one so we can at least play the errant character
                    }
                  } else {
                    x = 4;
                    input_error = 1;
                  }
                }
                if (input_error == 0) {
                  speed_mode = SPEED_QRSS;
                  qrss_dit_length =  int_from_macro;
                  //calculate_element_length();
                }
              break;  //case 81

              case 82:                       // R - regular speed mode
                speed_mode = SPEED_NORMAL;
                //calculate_element_length();
              break;

              case 84:                      // T - transmit for ### seconds
                int_from_macro = 0;
                z = 100;
                input_error = 0;
                for (int x = 1; x < 4; x ++) {
                  y++;
                  if (y < (memory_end(memory_number)+1)) {
                    eeprom_byte_read2 = EEPROM.read(y);
                    if ((eeprom_byte_read2 > 47) && (eeprom_byte_read2 < 58)) {    // ascii 48-57 = "0" - "9")
                      int_from_macro = int_from_macro + ((eeprom_byte_read2 - 48) * z);
                      z = z / 10;
                    } else {
                      x = 4;           // error - exit
                      input_error = 1;
                      y--;             // go back one so we can at least play the errant character
                    }
                  } else {
                    x = 4;
                    input_error = 1;
                  }
                }
                if (input_error != 1) {   // go ahead and transmit
                  tx_and_sidetone_key(1,AUTOMATIC_SENDING);
                  delay_result = memory_nonblocking_delay(int_from_macro*1000);
                  tx_and_sidetone_key(0,AUTOMATIC_SENDING);
                }
                if (delay_result) {   // if a paddle or button0 was hit during the delay, exit
                  return;
                }
                break;  // case 84

              case 85:                      // U - turn on PTT
                manual_ptt_invoke = 1;
                ptt_key();
                break;

              case 86:                      // V - turn off PTT
                manual_ptt_invoke = 0;
                ptt_unkey();
                break;

              case 87:                      // W - change speed to ### WPM
                int_from_macro = 0;
                z = 100;
                input_error = 0;
                for (int x = 1; x < 4; x ++) {
                  y++;
                  if (y < (memory_end(memory_number)+1)) {
                    eeprom_byte_read2 = EEPROM.read(y);
                    if ((eeprom_byte_read2 > 47) && (eeprom_byte_read2 < 58)) {    // ascii 48-57 = "0" - "9")
                      int_from_macro = int_from_macro + ((eeprom_byte_read2 - 48) * z);
                      z = z / 10;
                    } else {
                      x = 4;           // error - exit
                      input_error = 1;
                      y--;             // go back one so we can at least play the errant character
                    }
                  }  else {
                    x = 4;
                    input_error = 1;
                  }
                }
                if (input_error != 1) {
                  speed_mode = SPEED_NORMAL;
                  speed_set(int_from_macro);
                }
                break;  // case 87

                case 89:                // Y - Relative WPM change (positive)
                  y++;
                  if ((y < (memory_end(memory_number)+1)) && (speed_mode == SPEED_NORMAL)) {
                    eeprom_byte_read2 = EEPROM.read(y);
                    if ((eeprom_byte_read2 > 47) && (eeprom_byte_read2 < 58)) {    // ascii 48-57 = "0" - "9")
                      speed_set(configuration.wpm + eeprom_byte_read2 - 48);
                    } else {
                      y--;             // go back one so we can at least play the errant character
                    }
                  } else {
                  }
                  break; // case 89

                case 90:                // Z - Relative WPM change (positive)
                  y++;
                  if ((y < (memory_end(memory_number)+1)) && (speed_mode == SPEED_NORMAL)) {
                    eeprom_byte_read2 = EEPROM.read(y);
                    if ((eeprom_byte_read2 > 47) && (eeprom_byte_read2 < 58)) {    // ascii 48-57 = "0" - "9")
                      speed_set(configuration.wpm - (eeprom_byte_read2 - 48));
                    } else {
                      y--;             // go back one so we can at least play the errant character
                    }
                  } else {
                  }
                  break; // case 90

            }

          }
          #endif //FEATURE_MEMORY_MACROS
        }
        if (keyer_machine_mode != BEACON) {
          #ifdef FEATURE_STRAIGHT_KEY
            if ((dit_buffer) || (dah_buffer) || (button0_buffer) || (digitalRead(pin_straight_key) == STRAIGHT_KEY_ACTIVE_STATE)) {   // exit if the paddle or button0 was hit
              dit_buffer = 0;
              dah_buffer = 0;
              button0_buffer = 0;
              repeat_memory = 255;
              #ifdef FEATURE_COMMAND_BUTTONS
                while (analogbuttonread(0)) {}
              #endif  
              return;
            }
          #else //FEATURE_STRAIGHT_KEY
            if ((dit_buffer) || (dah_buffer) || (button0_buffer)) {   // exit if the paddle or button0 was hit
              dit_buffer = 0;
              dah_buffer = 0;
              button0_buffer = 0;
              repeat_memory = 255;
              #ifdef FEATURE_COMMAND_BUTTONS
                while (analogbuttonread(0)) {}
              #endif  
              return;
            }
          #endif //FEATURE_STRAIGHT_KEY
        }

      } else {
        if (y == (memory_start(memory_number))) {      // memory is totally empty - do a boop
          repeat_memory = 255;
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Memory empty", 0, default_display_msg_delay);
          #else
          boop();
          #endif
        }
        
        // if we had an inserted memory, jump back to the original one
        if (/*(y== (memory_end(memory_number)+1)) &&*/ (jump_back_to_y < 99999) && (jump_back_to_memory_number < 255)) {
          #ifdef DEBUG_PLAY_MEMORY
            debug_serial_port->print(F("\nplay_memory: jump back to original memory:"));
            debug_serial_port->println(jump_back_to_memory_number);
          #endif
          y = jump_back_to_y;
          memory_number = jump_back_to_memory_number;
          jump_back_to_y = 99999;
          jump_back_to_memory_number = 255;
        } else {        
        
        
        
         return;
        }
      }
    } else {
      if (pause_sending_buffer == 0) {
        y = (memory_end(memory_number)+1);   // we got a play_memory_prempt flag, exit out
      } else {
        y--;  // we're in a pause mode, so sit and spin awhile
      }
    }

    last_memory_repeat_time = millis();
    #ifdef DEBUG_PLAY_MEMORY
      debug_serial_port->println(F("\nplay_memory: reset last_memory_repeat_time"));  
      debug_serial_port->print("y: ");
      debug_serial_port->print(y);
      debug_serial_port->print("\tmemory_number: ");
      debug_serial_port->print(memory_number);
      debug_serial_port->print("\tmemory_end: ");
      debug_serial_port->print(memory_end(memory_number));
      debug_serial_port->print("\tjump_back_to_y: ");
      debug_serial_port->print(jump_back_to_y);
      debug_serial_port->print("\tjump_back_to_memory_number: ");
      debug_serial_port->println(jump_back_to_memory_number); 
    #endif
    
    
    // if we had an inserted memory, jump back to the original one
    /*
    if ((y== (memory_end(memory_number)+1)) && (jump_back_to_y < 99999) && (jump_back_to_memory_number < 255)) {
      primary_serial_port->print(F("\nplay_memory: jump back to original memory:"));
      primary_serial_port->println(jump_back_to_memory_number);
      y = jump_back_to_y;
      memory_number = jump_back_to_memory_number;
      jump_back_to_y = 99999;
      jump_back_to_memory_number = 255;
    }
    */
      

  }

}
#endif

//---------------------------------------------------------------------

#ifdef FEATURE_MEMORIES
void program_memory(int memory_number)
{

  if (memory_number > (number_of_memories-1)) {
    boop();
    return;
  }
  
  #ifdef FEATURE_DISPLAY
    String lcd_print_string;
    lcd_print_string.concat("Pgm Memory ");
    lcd_print_string.concat(memory_number+1);
    lcd_center_print_timed(lcd_print_string, 0, default_display_msg_delay);
  #endif

  send_dit(AUTOMATIC_SENDING);

  byte paddle_hit = 0;
  byte loop1 = 1;
  byte loop2 = 1;
  unsigned long last_element_time = 0;
  int memory_location_index = 0;
  long cwchar = 0;
  byte space_count = 0;
  
  #ifdef FEATURE_MEMORY_MACROS
    byte macro_flag = 0;
  #endif //FEATURE_MEMORY_MACROS
  
  #if defined(FEATURE_STRAIGHT_KEY)
    long straight_key_decoded_character = 0;
  #endif

  dit_buffer = 0;
  dah_buffer = 0;
  
  #if defined(FEATURE_COMMAND_BUTTONS) && !defined(FEATURE_STRAIGHT_KEY)
    while ((paddle_pin_read(paddle_left) == HIGH) && (paddle_pin_read(paddle_right) == HIGH) && (!analogbuttonread(0))) { }  // loop until user starts sending or hits the button
  #endif

  #if defined(FEATURE_COMMAND_BUTTONS) && defined(FEATURE_STRAIGHT_KEY)
    while ((paddle_pin_read(paddle_left) == HIGH) && (paddle_pin_read(paddle_right) == HIGH) && (!analogbuttonread(0)) && (digitalRead(pin_straight_key) == HIGH)) { }  // loop until user starts sending or hits the button
  #endif

  while (loop2) {

    #ifdef DEBUG_MEMORY_WRITE
      debug_serial_port->println(F("program_memory: entering loop2\r"));
    #endif

    cwchar = 0;
    paddle_hit = 0;
    loop1 = 1;
    


    while (loop1) {
       check_paddles();
       if (dit_buffer) {
         send_dit(MANUAL_SENDING);
         dit_buffer = 0;
         paddle_hit = 1;
         cwchar = (cwchar * 10) + 1;
         last_element_time = millis();
         #ifdef DEBUG_MEMORY_WRITE
           debug_serial_port->write(".");
         #endif
       }
       if (dah_buffer) {
         send_dah(MANUAL_SENDING);
         dah_buffer = 0;
         paddle_hit = 1;
         cwchar = (cwchar * 10) + 2;
         last_element_time = millis();
         #ifdef DEBUG_MEMORY_WRITE
           debug_serial_port->write("_");
         #endif
       }
       
//zzzzzz       
       #if defined(FEATURE_STRAIGHT_KEY)
         straight_key_decoded_character = service_straight_key();
         if (straight_key_decoded_character != 0){
           cwchar = straight_key_decoded_character;
           paddle_hit = 1;
         }
       #endif       
       
       #if !defined(FEATURE_STRAIGHT_KEY)
         if ((paddle_hit) && (millis() > (last_element_time + (float(600/configuration.wpm) * length_letterspace)))) {   // this character is over
           loop1 = 0;
         }
       #else
         if (((paddle_hit) && (millis() > (last_element_time + (float(600/configuration.wpm) * length_letterspace)))) || (straight_key_decoded_character != 0))  {   // this character is over
           loop1 = 0;
         }             
       #endif


       #ifdef FEATURE_MEMORY_MACROS
         if ((!macro_flag) && (paddle_hit == 0) && (millis() > (last_element_time + ((float(1200/configuration.wpm) * configuration.length_wordspace)))) && (space_count < program_memory_limit_consec_spaces)) {   // we have a space
           loop1 = 0;
           cwchar = 9;
           space_count++;
         }
       #else
         if ((paddle_hit == 0) && (millis() > (last_element_time + ((float(1200/configuration.wpm) * configuration.length_wordspace)))) && (space_count < program_memory_limit_consec_spaces)) {   // we have a space
           loop1 = 0;
           cwchar = 9;
           space_count++;
         }       
       #endif //FEATURE_MEMORY_MACROS

       #ifdef FEATURE_COMMAND_BUTTONS
         while (analogbuttonread(0)) {    // hit the button to get out of command mode if no paddle was hit
           loop1 = 0;
           loop2 = 0;
         }
       #endif
    }  //loop1

    if (cwchar != 9) {
      space_count = 0;
    }

    // write the character to memory
    if (cwchar > 0) {

      #ifdef DEBUG_MEMORY_WRITE
        debug_serial_port->print(F("program_memory: write_character_to_memory"));
        debug_serial_port->print(F(" mem number:"));
        debug_serial_port->print(memory_number);
        debug_serial_port->print(F("  memory_location_index:"));
        debug_serial_port->print(memory_location_index);
        debug_serial_port->print(F("  EEPROM location:"));
        debug_serial_port->print(memory_start[memory_number]+memory_location_index);
        debug_serial_port->print(F("   cwchar:"));
        debug_serial_port->print(cwchar);
        debug_serial_port->print(F("   ascii to write:"));
        debug_serial_port->println(convert_cw_number_to_ascii(cwchar));
      #endif

      EEPROM.write((memory_start(memory_number)+memory_location_index),convert_cw_number_to_ascii(cwchar));
      memory_location_index++;
 
      #ifdef FEATURE_MEMORY_MACROS
      if (!macro_flag) {
        if (convert_cw_number_to_ascii(cwchar) == '\\') {macro_flag = 1;}  // if we got the \ macro character, supress spaces
      } else {
         if (convert_cw_number_to_ascii(cwchar) == '+') {    // if we're building a prosign, supress the next two spaces
           macro_flag = 2; 
         } else {
           macro_flag--; 
         }
      }
      #endif //FEATURE_MEMORY_MACROS
    }

    // are we out of memory locations?
    if ((memory_start(memory_number) + memory_location_index) == memory_end(memory_number)) {
      loop1 = 0;
      loop2 = 0;
      #ifdef DEBUG_MEMORY_WRITE
        debug_serial_port->println(F("program_memory: out of memory location"));
      #endif
    }
  }

  //write terminating 255 at end
  #ifdef DEBUG_MEMORY_WRITE
    debug_serial_port->println(F("program_memory: writing memory termination"));
  #endif

  EEPROM.write((memory_start(memory_number) + memory_location_index),255);

  #ifdef OPTION_PROG_MEM_TRIM_TRAILING_SPACES
  for (int x = (memory_location_index-1); x > 0; x--) {
    if (EEPROM.read((memory_start(memory_number) + x)) == 32) {
      EEPROM.write((memory_start(memory_number) + x),255);
    } else {
      x = 0;
    }
  }
  #endif

  #ifdef FEATURE_DISPLAY
  lcd_center_print_timed("Done", 0, default_display_msg_delay);
  #endif

  play_memory(memory_number);

//  send_dit(AUTOMATIC_SENDING);

}
#endif

//---------------------------------------------------------------------

#ifdef FEATURE_MEMORIES
int memory_start(byte memory_number) {
  return (memory_area_start + (memory_number * ((memory_area_end - memory_area_start) / number_of_memories)));
}
#endif

//---------------------------------------------------------------------

#ifdef FEATURE_MEMORIES
int memory_end(byte memory_number) {
  return (memory_start(memory_number) - 1 + ((memory_area_end - memory_area_start)/number_of_memories));
}
#endif

//---------------------------------------------------------------------

void initialize_pins() {
  
  //#ifndef FEATURE_CAPACITIVE_PADDLE_PINS
  pinMode (paddle_left, INPUT);
  digitalWrite (paddle_left, HIGH);
  pinMode (paddle_right, INPUT);
  digitalWrite (paddle_right, HIGH);
  //#endif //#ifdef FEATURE_CAPACITIVE_PADDLE_PINS
  
  if (tx_key_line_1) {
    pinMode (tx_key_line_1, OUTPUT);
    digitalWrite (tx_key_line_1, LOW);
  }
  if (tx_key_line_2) {
    pinMode (tx_key_line_2, OUTPUT);
    digitalWrite (tx_key_line_2, LOW);
  }
  if (tx_key_line_3) {
    pinMode (tx_key_line_3, OUTPUT);
    digitalWrite (tx_key_line_3, LOW);
  }
  if (tx_key_line_4) {
    pinMode (tx_key_line_4, OUTPUT);
    digitalWrite (tx_key_line_4, LOW);
  }
  if (tx_key_line_5) {
    pinMode (tx_key_line_5, OUTPUT);
    digitalWrite (tx_key_line_5, LOW);
  }
  if (tx_key_line_6) {
    pinMode (tx_key_line_6, OUTPUT);
    digitalWrite (tx_key_line_6, LOW);
  }
    
  
  if (ptt_tx_1) {
    pinMode (ptt_tx_1, OUTPUT);
    digitalWrite (ptt_tx_1, LOW);
  }
  if (ptt_tx_2) {
    pinMode (ptt_tx_2, OUTPUT);
    digitalWrite (ptt_tx_2, LOW);
  }
  if (ptt_tx_3) {
    pinMode (ptt_tx_3, OUTPUT);
    digitalWrite (ptt_tx_3, LOW);
  }
  if (ptt_tx_4) {
    pinMode (ptt_tx_4, OUTPUT);
    digitalWrite (ptt_tx_4, LOW);
  }
  if (ptt_tx_5) {
    pinMode (ptt_tx_5, OUTPUT);
    digitalWrite (ptt_tx_5, LOW);
  }
  if (ptt_tx_6) {
    pinMode (ptt_tx_6, OUTPUT);
    digitalWrite (ptt_tx_6, LOW);
  }
  pinMode (sidetone_line, OUTPUT);
  digitalWrite (sidetone_line, LOW);

  if (tx_key_dit) {
    pinMode (tx_key_dit, OUTPUT);
    digitalWrite (tx_key_dit, LOW);
  }
  if (tx_key_dah) {
    pinMode (tx_key_dah, OUTPUT);
    digitalWrite (tx_key_dah, LOW);
  }

  #ifdef FEATURE_CW_DECODER
    pinMode (cw_decoder_pin, INPUT);

/* 2015090501
    #ifndef OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR
      digitalWrite (cw_decoder_pin, HIGH);
    #else
      digitalWrite (cw_decoder_pin, LOW);
      cwtonedetector.init(cw_decoder_pin);
    #endif //OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR
*/
    digitalWrite (cw_decoder_pin, HIGH);

    #if defined(OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR)
      digitalWrite (cw_decoder_audio_input_pin, LOW);
      cwtonedetector.init(cw_decoder_audio_input_pin);
    #endif //OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR

    if (cw_decoder_indicator){
      pinMode(cw_decoder_indicator,OUTPUT);
      digitalWrite(cw_decoder_indicator, LOW);
    }
  #endif //FEATURE_CW_DECODER
  
  #if defined(FEATURE_COMMAND_BUTTONS) && defined(command_mode_active_led)
    if(command_mode_active_led) {
      pinMode (command_mode_active_led, OUTPUT);
      digitalWrite (command_mode_active_led,LOW);
    }
  #endif //FEATURE_COMMAND_BUTTONS && command_mode_active_led
  
  
  #ifdef FEATURE_LED_RING
    pinMode(led_ring_sdi,OUTPUT);
    pinMode(led_ring_clk,OUTPUT);
    pinMode(led_ring_le,OUTPUT);
  #endif //FEATURE_LED_RING  

  #ifdef FEATURE_ALPHABET_SEND_PRACTICE
    if (correct_answer_led) {
      pinMode(correct_answer_led, OUTPUT);
      digitalWrite(correct_answer_led, LOW);
    }
    if (wrong_answer_led) {
      pinMode(wrong_answer_led, OUTPUT);
      digitalWrite(wrong_answer_led, LOW);
    }
  #endif //FEATURE_ALPHABET_SEND_PRACTICE

  #ifdef FEATURE_PTT_INTERLOCK
    pinMode(ptt_interlock,INPUT);
    if (ptt_interlock_active_state == HIGH){
      digitalWrite(ptt_interlock,LOW);
    } else {
      digitalWrite(ptt_interlock,HIGH);
    }
  #endif //FEATURE_PTT_INTERLOCK

  #ifdef FEATURE_STRAIGHT_KEY
    pinMode(pin_straight_key,INPUT);
    if (STRAIGHT_KEY_ACTIVE_STATE == HIGH){
      digitalWrite (pin_straight_key, LOW);
    } else {
      digitalWrite (pin_straight_key, HIGH);
    }
  #endif //FEATURE_STRAIGHT_KEY

  #if defined(FEATURE_COMPETITION_COMPRESSION_DETECTION)
    pinMode(compression_detection_pin,OUTPUT);
    digitalWrite(compression_detection_pin,LOW);
  #endif //FEATURE_COMPETITION_COMPRESSION_DETECTION
  
}

//---------------------------------------------------------------------

void initialize_debug_startup(){
#ifdef DEBUG_STARTUP

  serial_status(debug_serial_port);  
  #if defined(FEATURE_SERIAL)
  debug_serial_port->println(F("FEATURE_SERIAL"));
  #endif
  #ifdef FEATURE_COMMAND_LINE_INTERFACE
  debug_serial_port->println(F("FEATURE_COMMAND_LINE_INTERFACE"));
  #endif
  #ifndef OPTION_DO_NOT_SAY_HI
  debug_serial_port->println(F("OPTION_DO_NOT_SAY_HI"));
  #endif
  #ifdef FEATURE_MEMORIES
  debug_serial_port->println(F("FEATURE_MEMORIES"));
  #endif
  #ifdef FEATURE_MEMORY_MACROS
  debug_serial_port->println(F("FEATURE_MEMORY_MACROS"));
  #endif
  #ifdef FEATURE_WINKEY_EMULATION
  debug_serial_port->println(F("FEATURE_WINKEY_EMULATION"));
  #endif
  #ifdef OPTION_WINKEY_2_SUPPORT
  debug_serial_port->println(F("OPTION_WINKEY_2_SUPPORT"));
  #endif
  #ifdef FEATURE_BEACON
  debug_serial_port->println(F("FEATURE_BEACON"));
  #endif
  #ifdef FEATURE_CALLSIGN_RECEIVE_PRACTICE
  debug_serial_port->println(F("FEATURE_CALLSIGN_RECEIVE_PRACTICE"));
  #endif
  #ifdef FEATURE_POTENTIOMETER
  debug_serial_port->println(F("FEATURE_POTENTIOMETER"));
  #endif
  #if defined(FEATURE_SERIAL_HELP)
  debug_serial_port->println(F("FEATURE_SERIAL_HELP"));
  #endif
  #ifdef FEATURE_HELL
  debug_serial_port->println(F("FEATURE_HELL"));
  #endif
  #ifdef FEATURE_PS2_KEYBOARD
  debug_serial_port->println(F("FEATURE_PS2_KEYBOARD"));
  #endif
  #ifdef FEATURE_DEAD_OP_WATCHDOG
  debug_serial_port->println(F("FEATURE_DEAD_OP_WATCHDOG"));
  #endif
  #ifdef FEATURE_AUTOSPACE
  debug_serial_port->println(F("FEATURE_AUTOSPACE"));
  #endif
  #ifdef FEATURE_FARNSWORTH
  debug_serial_port->println(F("FEATURE_FARNSWORTH"));
  #endif
  #ifdef FEATURE_DL2SBA_BANKSWITCH
  debug_serial_port->println(F("FEATURE_DL2SBA_BANKSWITCH"));
  #endif
  #ifdef FEATURE_COMMAND_BUTTONS
  debug_serial_port->println(F("FEATURE_COMMAND_BUTTONS"));
  #endif
  #ifdef FEATURE_LCD_4BIT
  debug_serial_port->println(F("FEATURE_LCD_4BIT"));
  #endif  
  debug_serial_port->println(F("setup: exiting, going into loop"));
#endif //DEBUG_STARTUP  
}

 
//--------------------------------------------------------------------- 
  

 
#ifdef FEATURE_CW_DECODER
void service_cw_decoder() {

  static unsigned long last_transition_time = 0;
  static unsigned long last_decode_time = 0;
  static byte last_state = HIGH;
  static int decode_elements[16];                  // this stores received element lengths in mS (positive = tone, minus = no tone)
  static byte decode_element_pointer = 0;
  static float decode_element_tone_average = 0;
  static float decode_element_no_tone_average = 0;
  static int no_tone_count = 0;
  static int tone_count = 0;
  byte decode_it_flag = 0;
  byte cd_decoder_pin_state = HIGH;
  
  int element_duration = 0;
  static float decoder_wpm = configuration.wpm;
  long decode_character = 0;
  static byte space_sent = 0;
  #ifdef FEATURE_COMMAND_LINE_INTERFACE
    static byte screen_column = 0;
    static int last_printed_decoder_wpm = 0;
  #endif

/* 2015090501 
  #if !defined(OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR)
    cd_decoder_pin_state = digitalRead(cw_decoder_pin);
  #else
    if (cwtonedetector.detecttone() == HIGH){  // invert states
      cd_decoder_pin_state = LOW;
    } else {
      cd_decoder_pin_state = HIGH;
    }
  #endif

  */

  cd_decoder_pin_state = digitalRead(cw_decoder_pin);

  #if defined(OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR)
    if (cwtonedetector.detecttone() == HIGH){  // invert states
      cd_decoder_pin_state = LOW;
    } else {
      cd_decoder_pin_state = HIGH;
    }  
  #endif  
 
  #if defined(DEBUG_CW_DECODER_WITH_TONE)
    if (cd_decoder_pin_state == LOW){
      #if defined(GOERTZ_TARGET_FREQ)
        tone(sidetone_line, GOERTZ_TARGET_FREQ);
      #else
        tone(sidetone_line, hz_sidetone);
      #endif //defined(GOERTZ_TARGET_FREQ)
    } else {
     noTone(sidetone_line);
    }
  #endif  //DEBUG_CW_DECODER 
 
  if ((cw_decoder_indicator) && (cd_decoder_pin_state == LOW)){ 
   digitalWrite(cw_decoder_indicator,HIGH);
  } else {
   digitalWrite(cw_decoder_indicator,LOW);      
  }
 
  #ifdef DEBUG_OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR
    static unsigned long last_magnitude_debug_print = 0;
    if ((millis() - last_magnitude_debug_print) > 250){
      //debug_serial_port->print("service_cw_decoder: cwtonedetector magnitude: ");
      //debug_serial_port->print(cwtonedetector.magnitudelimit_low);
      //debug_serial_port->print("\t");
      debug_serial_port->print(cwtonedetector.magnitudelimit);
      debug_serial_port->print("\t");
      debug_serial_port->println(cwtonedetector.magnitude);
      last_magnitude_debug_print = millis();
    }
  #endif
 
  if  (last_transition_time == 0) { 
    if (cd_decoder_pin_state == LOW) {  // is this our first tone?
      last_transition_time = millis();
      last_state = LOW;
      
      #ifdef FEATURE_SLEEP
        last_activity_time = millis(); 
      #endif //FEATURE_SLEEP
      
    } else {
      if ((last_decode_time > 0) && (!space_sent) && ((millis() - last_decode_time) > ((1200/decoder_wpm)*CW_DECODER_SPACE_PRINT_THRESH))) { // should we send a space?
         #if defined(FEATURE_SERIAL)
           #ifdef FEATURE_COMMAND_LINE_INTERFACE
             primary_serial_port->write(32);
             screen_column++;
           #endif //FEATURE_COMMAND_LINE_INTERFACE
         #endif //FEATURE_SERIAL
         #ifdef FEATURE_DISPLAY
           display_scroll_print_char(' ');
         #endif //FEATURE_DISPLAY
         space_sent = 1;

      }
    }
  } else {
    if (cd_decoder_pin_state != last_state) {
      // we have a transition 
      element_duration = millis() - last_transition_time;
      if (element_duration > CW_DECODER_NOISE_FILTER) {                                    // filter out noise
        if (cd_decoder_pin_state == LOW) {  // we have a tone
          decode_elements[decode_element_pointer] = (-1 * element_duration);  // the last element was a space, so make it negative
          no_tone_count++;
          if (decode_element_no_tone_average == 0) {
            decode_element_no_tone_average = element_duration;
          } else {
            decode_element_no_tone_average = (element_duration + decode_element_no_tone_average) / 2;
          }
          decode_element_pointer++;
          last_state = LOW;
        } else {  // we have no tone
          decode_elements[decode_element_pointer] = element_duration;  // the last element was a tone, so make it positive 
          tone_count++;       
          if (decode_element_tone_average == 0) {
            decode_element_tone_average = element_duration;
          } else {
            decode_element_tone_average = (element_duration + decode_element_tone_average) / 2;
          }
          last_state = HIGH;
          decode_element_pointer++;
        }
        last_transition_time = millis();
        if (decode_element_pointer == 16) { decode_it_flag = 1; }  // if we've filled up the array, go ahead and decode it
      }
      
      
    } else {
      // no transition
      element_duration = millis() - last_transition_time;
      if (last_state == HIGH)  {
        // we're still high (no tone) - have we reached character space yet?        
        //if ((element_duration > (decode_element_no_tone_average * 2.5)) || (element_duration > (decode_element_tone_average * 2.5))) {
        if (element_duration > (float(1200/decoder_wpm)*CW_DECODER_SPACE_DECODE_THRESH)) {
          decode_it_flag = 1;
        }
      } else {
        // have we had tone for an outrageous amount of time?  
      }
    }
   }
 
 
 
 
  if (decode_it_flag) {                      // are we ready to decode the element array?

    // adjust the decoder wpm based on what we got
    
    if ((no_tone_count > 0) && (tone_count > 1)){ // NEW
    
      if (decode_element_no_tone_average > 0) {
        if (abs((1200/decode_element_no_tone_average) - decoder_wpm) < 5) {
          decoder_wpm = (decoder_wpm + (1200/decode_element_no_tone_average))/2;
        } else {
          if (abs((1200/decode_element_no_tone_average) - decoder_wpm) < 10) {
            decoder_wpm = (decoder_wpm + decoder_wpm + (1200/decode_element_no_tone_average))/3;
          } else {
            if (abs((1200/decode_element_no_tone_average) - decoder_wpm) < 20) {
              decoder_wpm = (decoder_wpm + decoder_wpm + decoder_wpm + (1200/decode_element_no_tone_average))/4;    
            }      
          }
        }
      }
    
    
    } // NEW
    
    #ifdef DEBUG_CW_DECODER_WPM
      if (abs(decoder_wpm - last_printed_decoder_wpm) > 0.9) {
        debug_serial_port->print("<");
        debug_serial_port->print(int(decoder_wpm));
        debug_serial_port->print(">");
        last_printed_decoder_wpm = decoder_wpm;
      }
    #endif //DEBUG_CW_DECODER_WPM
    
    for (byte x = 0;x < decode_element_pointer; x++) {
      if (decode_elements[x] > 0) {  // is this a tone element?          
        // we have no spaces to time from, use the current wpm
        if ((decode_elements[x]/(1200/decoder_wpm)) < 2.1 /*1.3*/) {  // changed from 1.3 to 2.1 2015-05-12
          decode_character = (decode_character * 10) + 1; // we have a dit
        } else {
          decode_character = (decode_character * 10) + 2; // we have a dah
        }  
      }
      #ifdef DEBUG_CW_DECODER
        debug_serial_port->print(F("service_cw_decoder: decode_elements["));
        debug_serial_port->print(x);
        debug_serial_port->print(F("]: "));
        debug_serial_port->println(decode_elements[x]);
      #endif //DEBUG_CW_DECODER
    }

    #ifdef DEBUG_CW_DECODER
      debug_serial_port->print(F("service_cw_decoder: decode_element_tone_average: "));
      debug_serial_port->println(decode_element_tone_average);
      debug_serial_port->print(F("service_cw_decoder: decode_element_no_tone_average: "));
      debug_serial_port->println(decode_element_no_tone_average);
      debug_serial_port->print(F("service_cw_decoder: decode_element_no_tone_average wpm: "));
      debug_serial_port->println(1200/decode_element_no_tone_average);
      debug_serial_port->print(F("service_cw_decoder: decoder_wpm: "));
      debug_serial_port->println(decoder_wpm);
      debug_serial_port->print(F("service_cw_decoder: decode_character: "));
      debug_serial_port->println(decode_character);
    #endif //DEBUG_CW_DECODER

    #if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
      primary_serial_port->write(convert_cw_number_to_ascii(decode_character));
      #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
        secondary_serial_port->write(convert_cw_number_to_ascii(decode_character));
      #endif
      screen_column++;
    #endif //defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)

    #ifdef FEATURE_DISPLAY
      display_scroll_print_char(convert_cw_number_to_ascii(decode_character));
    #endif //FEATURE_DISPLAY
      
    // reinitialize everything
    last_transition_time = 0;
    last_decode_time = millis();
    decode_element_pointer = 0; 
    decode_element_tone_average = 0;
    decode_element_no_tone_average = 0;
    space_sent = 0;
    no_tone_count = 0;
    tone_count = 0;
  } //if (decode_it_flag)
  
  #if defined(FEATURE_SERIAL)
    #ifdef FEATURE_COMMAND_LINE_INTERFACE
    if (screen_column > CW_DECODER_SCREEN_COLUMNS) {
      primary_serial_port->println();
      #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
        secondary_serial_port->println();
      #endif    
      screen_column = 0;
    }
    #endif //FEATURE_COMMAND_LINE_INTERFACE
  #endif //FEATURE_SERIAL
  
}

#endif //FEATURE_CW_DECODER

//--------------------------------------------------------------------- 

void initialize_keyer_state(){
  
  key_state = 0;
  key_tx = 1;
  configuration.wpm = initial_speed_wpm;

  pot_wpm_low_value = initial_pot_wpm_low_value;
  
  configuration.hz_sidetone = initial_sidetone_freq;
  configuration.memory_repeat_time = default_memory_repeat_time;
  configuration.cmos_super_keyer_iambic_b_timing_percent = default_cmos_super_keyer_iambic_b_timing_percent;
  
  configuration.dah_to_dit_ratio = initial_dah_to_dit_ratio;
  //configuration.current_tx = 1;
  configuration.length_wordspace = default_length_wordspace;
  configuration.weighting = default_weighting;
  
  #ifdef FEATURE_FARNSWORTH
  configuration.wpm_farnsworth = initial_speed_wpm;
  #endif //FEATURE_FARNSWORTH
  
  switch_to_tx_silent(1);

}  

//--------------------------------------------------------------------- 
void initialize_potentiometer(){

  #ifdef FEATURE_POTENTIOMETER
  pinMode(potentiometer,INPUT);
  pot_wpm_high_value = initial_pot_wpm_high_value;
  last_pot_wpm_read = pot_value_wpm();
  configuration.pot_activated = 1;
  #endif
  
}
  
//---------------------------------------------------------------------   
void initialize_rotary_encoder(){  
  
  #ifdef FEATURE_ROTARY_ENCODER
  pinMode(rotary_pin1, INPUT);
  pinMode(rotary_pin2, INPUT);
  #ifdef OPTION_ENCODER_ENABLE_PULLUPS
  digitalWrite(rotary_pin1, HIGH);
  digitalWrite(rotary_pin2, HIGH);
  #endif //OPTION_ENCODER_ENABLE_PULLUPS
  #endif //FEATURE_ROTARY_ENCODER
  
}

//---------------------------------------------------------------------   

void initialize_default_modes(){
  
  
  // setup default modes
  keyer_machine_mode = KEYER_NORMAL;
  configuration.paddle_mode = PADDLE_NORMAL;
  configuration.keyer_mode = IAMBIC_B;
  configuration.sidetone_mode = SIDETONE_ON;
  char_send_mode = CW;
  
  delay(250);  // wait a little bit for the caps to charge up on the paddle lines

}  

//--------------------------------------------------------------------- 

void initialize_watchdog(){
  
  #ifdef OPTION_WATCHDOG_TIMER
  wdt_enable(WDTO_4S);
  #endif //OPTION_WATCHDOG_TIMER

}  

//--------------------------------------------------------------------- 

void check_eeprom_for_initialization(){

  // do an eeprom reset to defaults if paddles are squeezed
  if (paddle_pin_read(paddle_left) == LOW && paddle_pin_read(paddle_right) == LOW) {
    while (paddle_pin_read(paddle_left) == LOW && paddle_pin_read(paddle_right) == LOW) {}
    write_settings_to_eeprom(1);
    beep_boop();
    beep_boop();
    beep_boop();
  }

  // read settings from eeprom and initialize eeprom if it has never been written to
  if (read_settings_from_eeprom()) {
    write_settings_to_eeprom(1);
    beep_boop();
    beep_boop();
    beep_boop();
  }
}

//--------------------------------------------------------------------- 

void check_for_beacon_mode(){
  
  #ifndef OPTION_SAVE_MEMORY_NANOKEYER
  // check for beacon mode (paddle_left == low) or straight key mode (paddle_right == low)
  if (paddle_pin_read(paddle_left) == LOW) {
    #ifdef FEATURE_BEACON
    keyer_machine_mode = BEACON;
    #endif
  } else {
    if (paddle_pin_read(paddle_right) == LOW) {
      configuration.keyer_mode = STRAIGHT;
    }
  }
  #endif //OPTION_SAVE_MEMORY_NANOKEYER
 
}

//--------------------------------------------------------------------- 

void check_for_debug_modes(){

  #ifdef DEBUG_CAPTURE_COM_PORT
  primary_serial_port->begin(primary_serial_port_baud_rate);
  debug_capture();
  #endif

  #ifdef DEBUG_HELL_TEST
  hell_test();
  #endif
}

//--------------------------------------------------------------------- 

void initialize_serial_ports(){

  // initialize serial port
  #if defined(FEATURE_SERIAL)
  
    #if defined(FEATURE_WINKEY_EMULATION) && defined(FEATURE_COMMAND_LINE_INTERFACE) //--------------------------------------------
    
      #ifdef FEATURE_COMMAND_BUTTONS
        if (analogbuttonread(0)) {
          #ifdef OPTION_PRIMARY_SERIAL_PORT_DEFAULT_WINKEY_EMULATION
            primary_serial_port_mode = SERIAL_CLI;
            primary_serial_port_baud_rate = PRIMARY_SERIAL_PORT_BAUD;
          #else
            primary_serial_port_mode = SERIAL_WINKEY_EMULATION;
            primary_serial_port_baud_rate = 1200;
          #endif  //ifndef OPTION_PRIMARY_SERIAL_PORT_DEFAULT_WINKEY_EMULATION
        } else {    
          #ifdef OPTION_PRIMARY_SERIAL_PORT_DEFAULT_WINKEY_EMULATION
            primary_serial_port_mode = SERIAL_WINKEY_EMULATION;
            primary_serial_port_baud_rate = 1200;
          #else
            primary_serial_port_mode = SERIAL_CLI;
            primary_serial_port_baud_rate = PRIMARY_SERIAL_PORT_BAUD;
          #endif  //ifndef OPTION_PRIMARY_SERIAL_PORT_DEFAULT_WINKEY_EMULATION
        }
        while (analogbuttonread(0)) {}
      #else //FEATURE_COMMAND_BUTTONS  
        #ifdef OPTION_PRIMARY_SERIAL_PORT_DEFAULT_WINKEY_EMULATION
          primary_serial_port_mode = SERIAL_WINKEY_EMULATION;
          primary_serial_port_baud_rate = 1200;
        #else
          primary_serial_port_mode = SERIAL_CLI;
          primary_serial_port_baud_rate = PRIMARY_SERIAL_PORT_BAUD;
        #endif  //ifndef OPTION_PRIMARY_SERIAL_PORT_DEFAULT_WINKEY_EMULATION
      #endif //FEATURE_COMMAND_BUTTONS
    #endif //defined(FEATURE_WINKEY_EMULATION) && defined(FEATURE_COMMAND_LINE_INTERFACE)---------------------------------

    #if !defined(FEATURE_WINKEY_EMULATION) && defined(FEATURE_COMMAND_LINE_INTERFACE)
      primary_serial_port_mode = SERIAL_CLI;
      primary_serial_port_baud_rate = PRIMARY_SERIAL_PORT_BAUD;
    #endif  //!defined(FEATURE_WINKEY_EMULATION) && defined(FEATURE_COMMAND_LINE_INTERFACE)

    #if defined(FEATURE_WINKEY_EMULATION) && !defined(FEATURE_COMMAND_LINE_INTERFACE)
      primary_serial_port_mode = SERIAL_WINKEY_EMULATION;
      primary_serial_port_baud_rate = 1200;
    #endif //defined(FEATURE_WINKEY_EMULATION) && !defined(FEATURE_COMMAND_LINE_INTERFACE)
    
    primary_serial_port = PRIMARY_SERIAL_PORT;

    primary_serial_port->begin(primary_serial_port_baud_rate);
    
    #ifdef DEBUG_STARTUP
      debug_serial_port->println(F("setup: serial port opened"));
    #endif //DEBUG_STARTUP

    #if !defined(OPTION_SUPPRESS_SERIAL_BOOT_MSG) && defined(FEATURE_COMMAND_LINE_INTERFACE)
      if (primary_serial_port_mode == SERIAL_CLI) {
        primary_serial_port->print(F("\n\rK3NG Keyer Version "));
        primary_serial_port->write(CODE_VERSION);
        primary_serial_port->println();
        #if defined(FEATURE_SERIAL_HELP)
          primary_serial_port->println(F("\n\rEnter \\? for help\n"));
        #endif
      }
      #ifdef DEBUG_MEMORYCHECK
        memorycheck();
      #endif //DEBUG_MEMORYCHECK
    #endif //!defined(OPTION_SUPPRESS_SERIAL_BOOT_MSG) && defined(FEATURE_COMMAND_LINE_INTERFACE)

    #ifdef DEBUG_AUX_SERIAL_PORT
      debug_port = DEBUG_AUX_SERIAL_PORT;
      debug_serial_port->begin(DEBUG_AUX_SERIAL_PORT_BAUD);
      debug_serial_port->print("debug port open ");
      debug_serial_port->println(CODE_VERSION);
    #endif //DEBUG_AUX_SERIAL_PORT

    #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
      secondary_serial_port = SECONDARY_SERIAL_PORT;
      secondary_serial_port->begin(SECONDARY_SERIAL_PORT_BAUD);
      #if !defined(OPTION_SUPPRESS_SERIAL_BOOT_MSG)
        secondary_serial_port->print(F("\n\rK3NG Keyer Version "));
        secondary_serial_port->write(CODE_VERSION);
        secondary_serial_port->println();
        #if defined(FEATURE_SERIAL_HELP)
          secondary_serial_port->println(F("\n\rEnter \\? for help\n"));
        #endif
      #endif
    #endif //FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT 

    #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
    debug_serial_port = secondary_serial_port;
    #else
    debug_serial_port = primary_serial_port;
    #endif

  #endif //FEATURE_SERIAL
  
  
}

//--------------------------------------------------------------------- 
void initialize_ps2_keyboard(){

  #ifdef FEATURE_PS2_KEYBOARD

  #ifdef OPTION_PS2_KEYBOARD_RESET             // code contributed by Bill, W9BEL
  attachInterrupt(1, ps2int_write, FALLING);
  digitalWrite(ps2_keyboard_data, LOW); // pullup off
  pinMode(ps2_keyboard_data, OUTPUT); // pull clock low
  delay(200);
  #endif //OPTION_PS2_KEYBOARD_RESET


  keyboard.begin(ps2_keyboard_data, ps2_keyboard_clock);
  #endif //FEATURE_PS2_KEYBOARD
  
}
//--------------------------------------------------------------------- 

#if defined(FEATURE_PS2_KEYBOARD) && defined(OPTION_PS2_KEYBOARD_RESET)
void ps2int_write() {

  // code contributed by Bill, W9BEL
  //----- Called from initialize_ps2_keyboard to reset Mini KBD ---------
  // The ISR for the external interrupt in read mode


  uint8_t buffer[45];
  uint8_t head, tail, writeByte = 255;
  uint8_t curbit = 0, parity = 0, ack =0;
 
  if(curbit < 8) {
    if(writeByte & 1) {
      parity ^= 1;
      digitalWrite(ps2_keyboard_data, HIGH);
    } else
      digitalWrite(ps2_keyboard_data, LOW);
    writeByte >>= 1;
  } else if(curbit == 8) { // parity
    if(parity)
      digitalWrite(ps2_keyboard_data, LOW);
    else
      digitalWrite(ps2_keyboard_data, HIGH);
  } else if(curbit == 9) { // time to let go
    pinMode(ps2_keyboard_data, INPUT); // release line
    digitalWrite(ps2_keyboard_data, HIGH); // pullup on
  } else { // time to check device ACK and hold clock again
    //holdClock();
    digitalWrite(ps2_keyboard_clock, LOW); // pullup off
    pinMode(ps2_keyboard_clock, OUTPUT); // pull clock low
    ack = !digitalRead(ps2_keyboard_data);
  }
  curbit++;
}
#endif 

//--------------------------------------------------------------------- 

void initialize_display(){

  #ifdef FEATURE_DISPLAY
  lcd.begin(LCD_COLUMNS, LCD_ROWS);
  #ifdef FEATURE_LCD_ADAFRUIT_I2C
  lcd.setBacklight(lcdcolor);
  #endif //FEATURE_LCD_ADAFRUIT_I2C



  #ifdef OPTION_DISPLAY_NON_ENGLISH_EXTENSIONS  // OZ1JHM provided code, cleaned up by LA3ZA
  // Store bit maps, designed using editor at http://omerk.github.io/lcdchargen/


  byte U_umlaut[8] =   {B01010,B00000,B10001,B10001,B10001,B10001,B01110,B00000}; // 'Ü'  
  byte O_umlaut[8] =   {B01010,B00000,B01110,B10001,B10001,B10001,B01110,B00000}; // 'Ö'  
  byte A_umlaut[8] =   {B01010,B00000,B01110,B10001,B11111,B10001,B10001,B00000}; // 'Ä'    
  byte AE_capital[8] = {B01111,B10100,B10100,B11110,B10100,B10100,B10111,B00000}; // 'Æ' 
  byte OE_capital[8] = {B00001,B01110,B10011,B10101,B11001,B01110,B10000,B00000}; // 'Ø' 
  byte empty[8] =      {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000}; // empty 
  byte AA_capital[8] = {B00100,B00000,B01110,B10001,B11111,B10001,B10001,B00000}; // 'Å'   
  byte Ntilde[8] =     {B01101,B10010,B00000,B11001,B10101,B10011,B10001,B00000}; // 'Ñ' 

  
  
  //     upload 8 charaters to the lcd
  lcd.createChar(0, U_umlaut); //     German
  lcd.createChar(1, O_umlaut); //     German, Swedish
  lcd.createChar(2, A_umlaut); //     German, Swedish 
  lcd.createChar(3, AE_capital); //   Danish, Norwegian
  lcd.createChar(4, OE_capital); //   Danish, Norwegian
  lcd.createChar(5, empty); //        For some reason this one needs to display nothing - otherwise it will display in pauses on serial interface
  lcd.createChar(6, AA_capital); //   Danish, Norwegian, Swedish
  lcd.createChar(7, Ntilde); //       Spanish
  lcd.clear(); // you have to ;o)
  #endif //OPTION_DISPLAY_NON_ENGLISH_EXTENSIONS


  lcd_center_print_timed("K3NG Keyer",0,4000);
  #endif //FEATURE_DISPLAY

  if (keyer_machine_mode != BEACON) {
    #ifndef OPTION_DO_NOT_SAY_HI
    // say HI
    // store current setting (compliments of DL2SBA - http://dl2sba.com/ )
    byte oldKey = key_tx; 
    byte oldSideTone = configuration.sidetone_mode;
    key_tx = 0;
    configuration.sidetone_mode = SIDETONE_ON;     
    
    //delay(201);
    #ifdef FEATURE_DISPLAY
    lcd_center_print_timed("h",1,4000);
    #endif
    send_char('H',KEYER_NORMAL);
    #ifdef FEATURE_DISPLAY
    lcd_center_print_timed("hi",1,4000);
    #endif
    send_char('I',KEYER_NORMAL);
    
    configuration.sidetone_mode = oldSideTone; 
    key_tx = oldKey;     
    #endif //OPTION_DO_NOT_SAY_HI
    
  }
}


//--------------------------------------------------------------------- 
#ifdef FEATURE_USB_KEYBOARD
void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key)	
{
  
  #ifdef FEATURE_MEMORIES  
  enum usb_kbd_states {USB_KEYBOARD_NORMAL, USB_KEYBOARD_WPM_ADJUST, USB_KEYBOARD_FARNS_WPM_ADJUST, USB_KEYBOARD_SN_ENTRY, USB_KEYBOARD_PROGRAM_MEM};
  #else
  enum usb_kbd_states {USB_KEYBOARD_NORMAL, USB_KEYBOARD_WPM_ADJUST, USB_KEYBOARD_FARNS_WPM_ADJUST, USB_KEYBOARD_SN_ENTRY};
  #endif
  
  #define USB_KEYBOARD_SPECIAL_MODE_TIMEOUT 5000
  
  static byte usb_keyboard_mode = USB_KEYBOARD_NORMAL;
  
  static byte user_num_input_places = 0;
  static int user_num_input_lower_limit = 0;
  static int user_num_input_upper_limit = 0;
  static byte user_input_index = 0;
  static byte user_input_array[255];
  static int user_num_input_number_entered = 0;
  byte user_input_process_it = 0;
  #ifdef FEATURE_MEMORIES
  static byte usb_keyboard_program_memory = 0;
  #endif //FEATURE_MEMORIES
  int x = 0;
  
  MODIFIERKEYS modifier;
  *((uint8_t*)&modifier) = mod;  
  
  #ifdef DEBUG_USB_KEYBOARD
  debug_serial_port->print(F("KbdRptParser::OnKeyDown: mod:"));
  debug_serial_port->print(mod);
  debug_serial_port->print(" key:");
  debug_serial_port->print(key);
  debug_serial_port->print("\t");
  debug_serial_port->print((modifier.bmLeftCtrl   == 1) ? "LeftCtrl" : " ");
  debug_serial_port->print((modifier.bmLeftShift  == 1) ? "LeftShift" : " ");
  debug_serial_port->print((modifier.bmLeftAlt    == 1) ? "LeftAlt" : " ");
  debug_serial_port->print((modifier.bmLeftGUI    == 1) ? "LeftGUI" : " ");
  debug_serial_port->print((modifier.bmRightCtrl   == 1) ? "RightCtrl" : " ");
  debug_serial_port->print((modifier.bmRightShift  == 1) ? "RightShift" : " ");
  debug_serial_port->print((modifier.bmRightAlt    == 1) ? "RightAlt" : " ");
  debug_serial_port->print((modifier.bmRightGUI    == 1) ? "RightGUI" : " ");  
  debug_serial_port->print("\t");
  PrintHex<uint8_t>(key, 0x80);
  debug_serial_port->println();    
  #endif //DEBUG_USB_KEYBOARD
    
  byte usb_keyboard_prosign_flag = 0;
  uint8_t keystroke = OemToAscii(mod, key);
  byte keyboard_tune_on = 0;
  
  #ifdef FEATURE_MEMORIES
  if (usb_keyboard_mode == USB_KEYBOARD_PROGRAM_MEM){

    if ((key == 0x2a) && (user_input_index)){  // BACKSPACE
      user_input_index--;
      #ifdef FEATURE_DISPLAY
      keyboard_string = keyboard_string.substring(0,keyboard_string.length()-1);
      lcd_center_print_timed(keyboard_string, 1, 0 /*default_display_msg_delay)*/);
      #endif 
      usb_keyboard_special_mode_start_time = millis();      
      return;
    }  
    if ((key == 0x28) || (key == 0x58)) {user_input_process_it = 1;}  // ENTER
    if (key == 0x29) { // ESCAPE
      #ifdef FEATURE_DISPLAY
      lcd_status = LCD_REVERT;
      #else
      boop();
      #endif    
      user_input_index = 0;
      usb_keyboard_mode = USB_KEYBOARD_NORMAL;  
      return; 
    }         
    if ((keystroke > 31) && (keystroke < 123)) {
      usb_keyboard_special_mode_start_time = millis();
      keystroke = uppercase(keystroke);   
      #ifdef FEATURE_DISPLAY
      keyboard_string.concat(char(keystroke));
      if (keyboard_string.length() > LCD_COLUMNS) {
        lcd_center_print_timed(keyboard_string.substring((keyboard_string.length()-LCD_COLUMNS)), 1, default_display_msg_delay);
      } else {         
        lcd_center_print_timed(keyboard_string, 1, default_display_msg_delay);
      }
      #endif
      user_input_array[user_input_index] = keystroke;
      user_input_index++;
      if (user_input_index > (memory_end(usb_keyboard_program_memory)-memory_start(usb_keyboard_program_memory))) {
        user_input_process_it = 1;
      }   
      #ifdef DEBUG_USB_KEYBOARD 
      debug_serial_port->print(F("KbdRptParser::OnKeyDown: user_input_index: "));
      debug_serial_port->println(user_input_index);
      #endif //DEBUG_USB_KEYBOARD
    }  // if ((keystroke > 31) && (keystroke < 123))
    if (user_input_process_it){
      #ifdef DEBUG_USB_KEYBOARD 
      debug_serial_port->println(F("KbdRptParser::OnKeyDown: user_input_process_it"));
      #endif //DEBUG_USB_KEYBOARD
      for (x = 0;x < user_input_index;x++) {  // write to memory
        EEPROM.write((memory_start(usb_keyboard_program_memory)+x),user_input_array[x]);
        if ((memory_start(usb_keyboard_program_memory) + x) == memory_end(usb_keyboard_program_memory)) {    // are we at last memory location?
          x = user_input_index;
        }
      }
      // write terminating 255
      EEPROM.write((memory_start(usb_keyboard_program_memory)+x),255);
      #ifdef FEATURE_DISPLAY
      lcd_center_print_timed("Done", 0, default_display_msg_delay);
      #else    
      beep();
      #endif 
      user_input_process_it = 0; 
      user_input_index = 0; 
      usb_keyboard_mode = USB_KEYBOARD_NORMAL;           
    } //if (user_input_process_it)  
    return; 
  }  // if (usb_keyboard_mode == USB_KEYBOARD_PROGRAM_MEM)
  #endif //FEATURE_MEMORIES
  
  if ((usb_keyboard_mode == USB_KEYBOARD_WPM_ADJUST) || (usb_keyboard_mode == USB_KEYBOARD_WPM_ADJUST) || (usb_keyboard_mode == USB_KEYBOARD_FARNS_WPM_ADJUST) || (usb_keyboard_mode == USB_KEYBOARD_SN_ENTRY)) {
    if ((key > 29) && (key < 40)) { // convert keyboard code to number
      if (key == 39) {
        user_input_array[user_input_index] = 0;
        #ifdef FEATURE_DISPLAY
        keyboard_string.concat(String(0));
        #endif
      } else {
        user_input_array[user_input_index] = key - 29;
        #ifdef FEATURE_DISPLAY
        keyboard_string.concat(String(key-29));
        #endif 
      }
      #ifdef FEATURE_DISPLAY
      lcd_center_print_timed(keyboard_string, 1, default_display_msg_delay);
      #endif            
      user_input_index++;
      usb_keyboard_special_mode_start_time = millis();
    } else { // not a number key, is it a special key?
      if ((key == 0x2a) && (user_input_index)){ //BACKSPACE
        user_input_index--;
        #ifdef FEATURE_DISPLAY
        keyboard_string = keyboard_string.substring(0,keyboard_string.length()-1);
        lcd_center_print_timed(keyboard_string, 1, default_display_msg_delay);
        #endif               
      } 
      if ((key == 0x28) || (key == 0x58)) {user_input_process_it = 1;}  // ENTER
      if (key == 0x29) { // ESCAPE
        user_input_index = 0;
        usb_keyboard_mode = USB_KEYBOARD_NORMAL;   
      }     
    }
    
    if ((user_input_index >= user_num_input_places) || (user_input_process_it)){  // is the user input ready to be processed?
      user_num_input_number_entered = 0;
      int y = 1;
      for (x = (user_input_index-1); x >= 0; x--){
        user_num_input_number_entered = user_num_input_number_entered + (user_input_array[x] * y);
        y = y * 10;
      }
      if ((user_num_input_number_entered > user_num_input_lower_limit) && (user_num_input_number_entered < user_num_input_upper_limit)){
        switch(usb_keyboard_mode){
          case USB_KEYBOARD_WPM_ADJUST:
            speed_set(user_num_input_number_entered);
            #ifdef FEATURE_DISPLAY
            lcd_status = LCD_REVERT;
            #else
            beep();
            #endif
            config_dirty = 1;         
            break;
          #ifdef FEATURE_FARNSWORTH
          case USB_KEYBOARD_FARNS_WPM_ADJUST:
            configuration.wpm_farnsworth = user_num_input_number_entered;
            #ifdef FEATURE_DISPLAY
            lcd_status = LCD_REVERT;
            #else
            beep();
            #endif
            config_dirty = 1;     
            break;
          #endif //FEATURE_FARNSWORTH
          case USB_KEYBOARD_SN_ENTRY:
            serial_number = user_num_input_number_entered;
            #ifdef FEATURE_DISPLAY
            lcd_status = LCD_REVERT;
            #else             
            beep();
            #endif      
            break;
          default: boop(); break;       
        }
      } else {  
        boop();  // bad user input!
      }     
      // reinitialize everything for the next go around
      user_input_index = 0;
      usb_keyboard_mode = USB_KEYBOARD_NORMAL;
    }
  
    return; 
  }  
  
  // grab the keypad / and * for dit and dah paddling
  if (key == 0x54) {usb_dit = 1; return;}
  if (key == 0x55) {usb_dah = 1; return;}
  if (key == 0x58) {tx_and_sidetone_key(1,MANUAL_SENDING);return;}
  
  if ((modifier.bmLeftShift) || (modifier.bmRightShift)) {
    switch(key){     
      case 0x2a:    // BACKSPACE - decrement serial number
        serial_number--;
        #ifdef FEATURE_DISPLAY
        lcd_center_print_timed("Serial: " + String(serial_number), 0, default_display_msg_delay);
        #endif  
        return;      
        break;  
                     
    } // switch(key)
    #ifdef FEATURE_MEMORIES
    if ((key >= 0x3a) && (key <= 0x45)){ // SHIFT F1-F12 : program memories
      usb_keyboard_program_memory = key - 0x3a; // convert key scan code to memory number; F1 = 0
      if (usb_keyboard_program_memory > (number_of_memories - 1)) {
        boop();
        return;
      }     
      usb_keyboard_special_mode_start_time = millis();
      usb_keyboard_mode = USB_KEYBOARD_PROGRAM_MEM;     
      #ifdef FEATURE_DISPLAY
      String lcd_string = "Program Memory";
      if (usb_keyboard_program_memory < 9) {
        lcd_string.concat(' ');
      }
      keyboard_string = "";
      lcd_string.concat(usb_keyboard_program_memory+1);
      lcd_center_print_timed(lcd_string, 0, default_display_msg_delay);
      #else
      boop_beep();
      #endif
      
      repeat_memory = 255;
      return;
    }        
    #endif //FEATURE_MEMORIES    
    
  } // if ((modifier.bmLeftShift) || (modifier.bmRightShift))
  
  if ((modifier.bmLeftAlt) || (modifier.bmRightAlt)) {
    switch(key){
      #ifdef FEATURE_MEMORIES
      case 0x3a: if (number_of_memories > 0) {repeat_memory_msg(0);} return; break; // F1
      case 0x3b: if (number_of_memories > 1) {repeat_memory_msg(1);} return; break;
      case 0x3c: if (number_of_memories > 2) {repeat_memory_msg(2);} return; break;
      case 0x3d: if (number_of_memories > 3) {repeat_memory_msg(3);} return; break;
      case 0x3e: if (number_of_memories > 4) {repeat_memory_msg(4);} return; break;
      case 0x3f: if (number_of_memories > 5) {repeat_memory_msg(5);} return; break;
      case 0x40: if (number_of_memories > 6) {repeat_memory_msg(6);} return; break;
      case 0x41: if (number_of_memories > 7) {repeat_memory_msg(7);} return; break;
      case 0x42: if (number_of_memories > 8) {repeat_memory_msg(8);} return; break;
      case 0x43: if (number_of_memories > 9) {repeat_memory_msg(9);} return; break;
      case 0x44: if (number_of_memories > 10) {repeat_memory_msg(10);} return; break;
      case 0x45: if (number_of_memories > 11) {repeat_memory_msg(11);} return; break;
      #endif        
    } //switch(key)
  } // if ((modifier.bmLeftAlt) || (modifier.bmRightAlt))

  if ((modifier.bmLeftCtrl) || (modifier.bmRightCtrl)) {
    #ifdef DEBUG_USB_KEYBOARD
    debug_serial_port->print(F("KbdRptParser::OnKeyDown: CTRL-"));
    debug_serial_port->println(keystroke);
    #endif //DEBUG_USB_KEYBOARD
    switch(key){
      case 0x04 : // CTRL-A
        configuration.keyer_mode = IAMBIC_A;
        #ifdef FEATURE_DISPLAY
        lcd_center_print_timed("Iambic A", 0, default_display_msg_delay);
        #endif

        config_dirty = 1;
        break;

      case 0x05 : // CTRL-B
        configuration.keyer_mode = IAMBIC_B;
        #ifdef FEATURE_DISPLAY
        lcd_center_print_timed("Iambic B", 0, default_display_msg_delay);
        #endif          
        config_dirty = 1;
        break;

      case 0x07 : // CTRL-D
        configuration.keyer_mode = ULTIMATIC;
        #ifdef FEATURE_DISPLAY
        lcd_center_print_timed("Ultimatic", 0, default_display_msg_delay);
        #endif        
        config_dirty = 1;
        break;

      case 0x08 : // CTRL-E
        #ifdef FEATURE_DISPLAY
        lcd_center_print_timed("Enter Serial #", 0, default_display_msg_delay);
        #else        
        boop_beep();
        #endif
        usb_keyboard_mode = USB_KEYBOARD_SN_ENTRY;
        user_num_input_places = 4;
        user_num_input_lower_limit = 0;
        user_num_input_upper_limit = 10000;      
        usb_keyboard_special_mode_start_time = millis();      
        break;

      case 0x0a : // CTRL-G
        configuration.keyer_mode = BUG;
        #ifdef FEATURE_DISPLAY
        lcd_center_print_timed("Bug", 0, default_display_msg_delay);
        #endif
        config_dirty = 1;
        break;

      case 0x0b : // CTRL-H
        #ifdef FEATURE_HELL
        if (char_send_mode == CW) {
          char_send_mode = HELL;
          beep();
        } else {
          char_send_mode = CW;
          beep();
        }
        #endif //FEATURE_HELL
        break;

      case 0x0c : // CTRL-I
        if (key_tx) {
          key_tx = 0;
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("TX Off", 0, default_display_msg_delay);
          #endif
          
        } else {
          key_tx = 1;
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("TX On", 0, default_display_msg_delay);
          #endif      
        }
        break;

      case 0x10: // CTRL-M
        #ifdef FEATURE_FARNSWORTH
        #ifdef FEATURE_DISPLAY
        lcd_center_print_timed("Farnsworth WPM", 0, default_display_msg_delay);
        #else          
        boop_beep();
        #endif
        usb_keyboard_mode = USB_KEYBOARD_FARNS_WPM_ADJUST;
        user_num_input_places = 3;
        user_num_input_lower_limit = -1;
        user_num_input_upper_limit = 1000;    
        usb_keyboard_special_mode_start_time = millis();      
        #endif

        break;

      case 0x11 : // CTRL-N
        if (configuration.paddle_mode == PADDLE_NORMAL) {
          configuration.paddle_mode = PADDLE_REVERSE;
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Paddle Reverse", 0, default_display_msg_delay);
          #endif
        } else {
          configuration.paddle_mode = PADDLE_NORMAL;
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Paddle Normal", 0, default_display_msg_delay);
          #endif      
        }
        config_dirty = 1;
        break;

      case 0x12 : // CTRL-O
        if ((configuration.sidetone_mode == SIDETONE_ON) || (configuration.sidetone_mode == SIDETONE_PADDLE_ONLY)){
          configuration.sidetone_mode = SIDETONE_OFF;
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Sidetone Off", 0, default_display_msg_delay);
          #endif      
        } else {
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Sidetone On", 0, default_display_msg_delay);
          #endif      
          configuration.sidetone_mode = SIDETONE_ON;
        }
        config_dirty = 1;
       break;

      case 0x17 : // CTRL-T
        #ifdef FEATURE_MEMORIES
        repeat_memory = 255;
        #endif
        if (keyboard_tune_on) {
          tx_and_sidetone_key(0,MANUAL_SENDING);
          keyboard_tune_on = 0;
          #ifdef FEATURE_DISPLAY
          lcd_status = LCD_REVERT;
          #endif // FEATURE_DISPLAY
        } else {
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Tune", 0, default_display_msg_delay);
          #endif      
          tx_and_sidetone_key(1,MANUAL_SENDING);
          keyboard_tune_on = 1;
        }
        break;

      case 0x18 : // CTRL-U
        if (ptt_line_activated) {
          manual_ptt_invoke = 0;
          ptt_unkey();
          #ifdef FEATURE_DISPLAY
          lcd_status = LCD_REVERT;
          #endif // FEATURE_DISPLAY            
        } else {
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("PTT Invoke", 0, default_display_msg_delay);
          #endif      
          manual_ptt_invoke = 1;
          ptt_key();
        }
        break;

      case 0x1a : // CTRL-W        
        #ifdef FEATURE_DISPLAY
        lcd_center_print_timed("WPM Adjust", 0, default_display_msg_delay);
        #else
        boop_beep();
        #endif
        usb_keyboard_mode = USB_KEYBOARD_WPM_ADJUST;
        user_num_input_places = 3;
        user_num_input_lower_limit = 0;
        user_num_input_upper_limit = 1000;     
        usb_keyboard_special_mode_start_time = millis();   
        break;

      case 0x3a : // CTRL-F1
        switch_to_tx_silent(1);
        #ifdef FEATURE_DISPLAY
        lcd_center_print_timed("TX 1", 0, default_display_msg_delay);
        #endif          
        break;

      case 0x3b : // CTRL-F2
        if ((ptt_tx_2) || (tx_key_line_2)) {
          switch_to_tx_silent(2);           
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("TX 2", 0, default_display_msg_delay);
          #endif                      
        }
        break;

      case 0x3c : // CTRL-F3
        if ((ptt_tx_3)  || (tx_key_line_3)) {
          switch_to_tx_silent(3);                      
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("TX 3", 0, default_display_msg_delay);
          #endif                                  
        }
        break;

      case 0x3d : // CTRL-F4
        if ((ptt_tx_4)  || (tx_key_line_4)) {
          switch_to_tx_silent(4);    
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("TX 4", 0, default_display_msg_delay);
          #endif                                  
        }
        break;

      case 0x3e : // CTRL-F5
        if ((ptt_tx_5)  || (tx_key_line_5)) {
          switch_to_tx_silent(5); 
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("TX 5", 0, default_display_msg_delay);
          #endif                      
        }
        break;

      case 0x3f : // CTRL-F6
        if ((ptt_tx_6)  || (tx_key_line_6)) {
          switch_to_tx_silent(6);
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("TX 6", 0, default_display_msg_delay);
          #endif                                  
        }
        break;

      #ifdef FEATURE_AUTOSPACE
      case 0x1d: // CTRL-Z
        if (configuration.autospace_active) {
          configuration.autospace_active = 0;
          config_dirty = 1;
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Autospace Off", 0, default_display_msg_delay);
          #endif                                  
        } else {
          configuration.autospace_active = 1;
          config_dirty = 1;
          #ifdef FEATURE_DISPLAY
          lcd_center_print_timed("Autospace On", 0, default_display_msg_delay);
          #endif                                  
        }
        break;
      #endif
    } //switch(keystroke)
    return;
  }  //if ((modifier.bmLeftCtrl) || (modifier.bmRightCtrl))

  // special keys with no modifiers
  switch(key){   
    case 0x4b: case 0x61: sidetone_adj(20); return; break;
    case 0x4e: case 0x5b: sidetone_adj(-20); return; break;
    case 0x4f: case 0x5e: adjust_dah_to_dit_ratio(int(configuration.dah_to_dit_ratio/10)); return; break;
    case 0x50: case 0x5c: adjust_dah_to_dit_ratio(-1*int(configuration.dah_to_dit_ratio/10)); return; break;
    case 0x52: case 0x60: speed_set(configuration.wpm+1); return; break;
    case 0x51: case 0x5a: speed_set(configuration.wpm-1); return; break;
    case 0x4a: case 0x5f: //HOME
      configuration.dah_to_dit_ratio = initial_dah_to_dit_ratio;
      key_tx = 1;
      config_dirty = 1;
      #ifdef FEATURE_DISPLAY
      #ifdef OPTION_MORE_DISPLAY_MSGS
      lcd_center_print_timed("Default ratio", 0, default_display_msg_delay);
      service_display();
      #endif
      #endif 
      return;           
      break;
    case 0x2b: case 0x48:  // TAB, PAUSE
      if (pause_sending_buffer) {
        pause_sending_buffer = 0;
        #ifdef FEATURE_DISPLAY
        #ifdef OPTION_MORE_DISPLAY_MSGS
        lcd_center_print_timed("Resume", 0, default_display_msg_delay);
        #endif
        #endif                 
      } else {
        pause_sending_buffer = 1;
        #ifdef FEATURE_DISPLAY
        lcd_center_print_timed("Pause", 0, default_display_msg_delay);
        #endif            
      }
      return; 
    break;  // pause

    case 0x47:   // SCROLL - Prosign next two characters
      usb_keyboard_prosign_flag = 1;
      #ifdef FEATURE_DISPLAY
      #ifdef OPTION_MORE_DISPLAY_MSGS
      lcd_center_print_timed("Prosign", 0, default_display_msg_delay);
      #endif
      #endif    
      return;       
      break;
      
    case 0x46: if (send_buffer_bytes > 0) { send_buffer_bytes--; } return; break;  // DEL
    case 0x29 :  // ESC - clear the serial send buffer and a bunch of other stuff
      if (manual_ptt_invoke) {
        manual_ptt_invoke = 0;
        ptt_unkey();
      }
      if (keyboard_tune_on) {
        tx_and_sidetone_key(0,MANUAL_SENDING);
        keyboard_tune_on = 0;
      }
      if (pause_sending_buffer) {
        pause_sending_buffer = 0;
      }
      clear_send_buffer();
      #ifdef FEATURE_MEMORIES
      //clear_memory_button_buffer();
      play_memory_prempt = 1;
      repeat_memory = 255;
      #endif
      #ifdef FEATURE_DISPLAY
      lcd_center_print_timed("Abort", 0, default_display_msg_delay);
      #endif  
      return;        
      break;
      
    case 0x49: case 0x62:   // INSERT - send serial number and increment
      put_serial_number_in_send_buffer();
      serial_number++;
      return;
      break;

    case 0x4d: case 0x59:      // END - send serial number no increment
      put_serial_number_in_send_buffer();
      return;
      break;          
          
    #ifdef FEATURE_MEMORIES
    case 0x3a: ps2_usb_keyboard_play_memory(0); return; break; // F1
    case 0x3b: ps2_usb_keyboard_play_memory(1); return; break;
    case 0x3c: ps2_usb_keyboard_play_memory(2); return; break;
    case 0x3d: ps2_usb_keyboard_play_memory(3); return; break;
    case 0x3e: ps2_usb_keyboard_play_memory(4); return; break;
    case 0x3f: ps2_usb_keyboard_play_memory(5); return; break;
    case 0x40: ps2_usb_keyboard_play_memory(6); return; break;
    case 0x41: ps2_usb_keyboard_play_memory(7); return; break;
    case 0x42: ps2_usb_keyboard_play_memory(8); return; break;
    case 0x43: ps2_usb_keyboard_play_memory(9); return; break;
    case 0x44: ps2_usb_keyboard_play_memory(10); return; break;
    case 0x45: ps2_usb_keyboard_play_memory(11); return; break;
    #endif
              
  }  // switch(key)



  // regular keys
  if (keystroke) {  
    if ((keystroke > 31) && (keystroke < 123)) {
      if (usb_keyboard_prosign_flag) {
        add_to_send_buffer(SERIAL_SEND_BUFFER_PROSIGN);
        usb_keyboard_prosign_flag = 0;
      }
      keystroke = uppercase(keystroke);
      add_to_send_buffer(keystroke);
      #ifdef FEATURE_MEMORIES
      repeat_memory = 255;
      #endif
    }       
  } //if (keystroke)
  
  // have we been in a special mode too long?
  if ((usb_keyboard_mode != USB_KEYBOARD_NORMAL) && ((millis() - usb_keyboard_special_mode_start_time) > USB_KEYBOARD_SPECIAL_MODE_TIMEOUT)) { 
    usb_keyboard_mode = USB_KEYBOARD_NORMAL;
    user_input_index = 0;
    #ifdef DEBUG_USB_KEYBOARD 
    debug_serial_port->println(F("KbdRptParser::OnKeyDown: usb_keyboard_mode timeout"));
    #endif //DEBUG_USB_KEYBOARD    
    return;
  }
  
}
#endif //FEATURE_USB_KEYBOARD

//--------------------------------------------------------------------- 
#ifdef FEATURE_USB_KEYBOARD
void KbdRptParser::OnKeyUp(uint8_t mod, uint8_t key)	
{
  
  // grab the keypad / and * for dit and dah paddling
  if (key == 0x54) {usb_dit = 0; return;}
  if (key == 0x55) {usb_dah = 0; return;}
  if (key == 0x58) {tx_and_sidetone_key(0,MANUAL_SENDING);return;}
  
}
#endif //FEATURE_USB_KEYBOARD

//--------------------------------------------------------------------- 

void initialize_usb()
{

    #if defined(FEATURE_USB_KEYBOARD) || defined(FEATURE_USB_MOUSE)    
    if (Usb.Init() == -1) {
      #ifdef DEBUG_USB
      debug_serial_port->println(F("\rinitialize_usb: OSC did not start."));
      #endif DEBUG_USB
      return;
    } else {
      #ifdef DEBUG_USB
      debug_serial_port->println(F("\rinitialize_usb: initializing"));
      #endif DEBUG_USB
    }      
    delay(200);
    next_time = millis() + 5000;
    #endif // (FEATURE_USB_KEYBOARD) || defined(FEATURE_USB_MOUSE)
    
    #ifdef FEATURE_USB_KEYBOARD
    HidKeyboard.SetReportParser(0, (HIDReportParser*)&KeyboardPrs);
    #endif //FEATURE_USB_KEYBOARD
    
    #ifdef FEATURE_USB_MOUSE
    HidMouse.SetReportParser(0,(HIDReportParser*)&MousePrs);
    #endif //FEATURE_USB_MOUSE
    
    #if defined(FEATURE_USB_KEYBOARD) || defined(FEATURE_USB_MOUSE)
    unsigned long start_init = millis();
    while ((millis() - start_init) < 2000){
      Usb.Task();
    }
    #ifdef DEBUG_USB
    debug_serial_port->println(F("intialize_usb: initialized"));
    #endif //DEBUG_USB 
    #endif // (FEATURE_USB_KEYBOARD) || defined(FEATURE_USB_MOUSE)
}
//--------------------------------------------------------------------- 
#if defined(FEATURE_USB_KEYBOARD) || defined(FEATURE_USB_MOUSE)
void service_usb(){
 
  Usb.Task();
  
}
#endif //FEATURE_USB_KEYBOARD || FEATURE_USB_MOUSE

//--------------------------------------------------------------------- 
#ifdef FEATURE_USB_MOUSE
void MouseRptParser::OnMouseMove(MOUSEINFO *mi){
    
    /*
    debug_serial_port->print("dx=");
    debug_serial_port->print(mi->dX, DEC);
    debug_serial_port->print(" dy=");
    debug_serial_port->println(mi->dY, DEC);
    */ 
  
    /* this is just me fooling around */  
    
    #ifdef OPTION_MOUSE_MOVEMENT_PADDLE
    static int last_dX = 0;
    static int last_dY = 0;
    int current_dX = (mi->dX);
    int current_dY = (mi->dY);

    /* X/Y method - doesn't work too well
    /*
    if ((current_dX != last_dX) && (abs(current_dX) > abs(current_dY)) && (abs(current_dX) > 3)){
      dit_buffer = 1;
    } 
    if ((current_dY != last_dY)  && (abs(current_dY) > abs(current_dX))  && (abs(current_dY) > 3)){
      dah_buffer = 1;
    } 
    */
    
    /* X only method */
    if ((current_dX != last_dX) && (abs(current_dX) > 8)){
      if (current_dX < 0) {
       dit_buffer = 1;
      } else {
       dah_buffer = 1;
      } 
    }

    last_dX = current_dX;
    last_dY = current_dY;
    #endif  //OPTION_MOUSE_MOVEMENT_PADDLE
    
};

void MouseRptParser::OnLeftButtonUp(MOUSEINFO *mi){
  usb_dit = 0;
};
void MouseRptParser::OnLeftButtonDown(MOUSEINFO *mi){
  usb_dit = 1;
};
void MouseRptParser::OnRightButtonUp(MOUSEINFO *mi){
  usb_dah = 0;
};
void MouseRptParser::OnRightButtonDown(MOUSEINFO *mi){
  usb_dah = 1;
};
void MouseRptParser::OnMiddleButtonUp(MOUSEINFO *mi){
  tx_and_sidetone_key(0,MANUAL_SENDING);
};
void MouseRptParser::OnMiddleButtonDown(MOUSEINFO *mi){
  tx_and_sidetone_key(1,MANUAL_SENDING);
};
#endif //FEATURE_USB_MOUSE
//---------------------------------------------------------------------

#ifdef FEATURE_CAPACITIVE_PADDLE_PINS
uint8_t read_capacitive_pin(int pinToMeasure) {
  
  /*
  
  This code is from http://playground.arduino.cc/Code/CapacitiveSensor
  
  Original code by Mario Becker, Fraunhofer IGD, 2007 http://www.igd.fhg.de/igd-a4
  
  Updated by: Alan Chatham http://unojoy.tumblr.com
  
  Updated by Paul Stoffregen: Replaced '328 specific code with portOutputRegister, etc for compatibility with Arduino Mega, Teensy, Sanguino and other boards
  
  Gratuitous optimization to improve sensitivity by Casey Rodarmor.
  
  */
  


  // Variables used to translate from Arduino to AVR pin naming
  
  volatile uint8_t* port;
  volatile uint8_t* ddr;
  volatile uint8_t* pin;
  
  // Here we translate the input pin number from
  //  Arduino pin number to the AVR PORT, PIN, DDR,
  //  and which bit of those registers we care about.
  
  byte bitmask;
  port = portOutputRegister(digitalPinToPort(pinToMeasure));
  ddr = portModeRegister(digitalPinToPort(pinToMeasure));
  bitmask = digitalPinToBitMask(pinToMeasure);
  pin = portInputRegister(digitalPinToPort(pinToMeasure));
  // Discharge the pin first by setting it low and output
  *port &= ~(bitmask);
  *ddr  |= bitmask;
  delay(1);
  // Prevent the timer IRQ from disturbing our measurement
  noInterrupts();
  // Make the pin an input with the internal pull-up on
  *ddr &= ~(bitmask);
  *port |= bitmask;

  // Now see how long the pin to get pulled up. This manual unrolling of the loop
  // decreases the number of hardware cycles between each read of the pin,
  // thus increasing sensitivity.
  uint8_t cycles = 17;
  /*     if (*pin & bitmask) { cycles =  0;}
  else if (*pin & bitmask) { cycles =  1;}
  else if (*pin & bitmask) { cycles =  2;}
  else if (*pin & bitmask) { cycles =  3;}
  else if (*pin & bitmask) { cycles =  4;}
  else if (*pin & bitmask) { cycles =  5;}
  else if (*pin & bitmask) { cycles =  6;}
  else if (*pin & bitmask) { cycles =  7;}
  else if (*pin & bitmask) { cycles =  8;}
  else if (*pin & bitmask) { cycles =  9;}
  else if (*pin & bitmask) { cycles = 10;}
  else if (*pin & bitmask) { cycles = 11;}
  else if (*pin & bitmask) { cycles = 12;}
  else if (*pin & bitmask) { cycles = 13;}
  else if (*pin & bitmask) { cycles = 14;}
  else if (*pin & bitmask) { cycles = 15;}
  else if (*pin & bitmask) { cycles = 16;}*/
  
  
  if (*pin & bitmask) {
    cycles = 0;
  } else { 
    if (*pin & bitmask) {
      cycles =  1;
    } else { 
      if (*pin & bitmask) {
        cycles =  2;
      } else {
        if (*pin & bitmask) {
          cycles =  3;
        } else {
          if (*pin & bitmask) {
            cycles =  4;
          } else {
            if (*pin & bitmask) {
              cycles =  5;
            } else {
              if (*pin & bitmask) {
                cycles =  6;
              } else {
                if (*pin & bitmask) {
                  cycles =  7;
                } else {
                  if (*pin & bitmask) {
                    cycles =  8;
                  } else {
                    if (*pin & bitmask) {
                      cycles =  9;
                    } else {
                      if (*pin & bitmask) {
                        cycles = 10;
                      } else {
                        if (*pin & bitmask) {
                          cycles = 11;
                        } else {
                          if (*pin & bitmask) {
                            cycles = 12;
                          } else {
                            if (*pin & bitmask) {
                              cycles = 13;
                            } else {
                              if (*pin & bitmask) {
                                cycles = 14;
                              } else {
                                if (*pin & bitmask) {
                                  cycles = 15;
                                } else {
                                  if (*pin & bitmask) {
                                    cycles = 16;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  // End of timing-critical section
  interrupts();

  // Discharge the pin again by setting it low and output
  //  It's important to leave the pins low if you want to 
  //  be able to touch more than 1 sensor at a time - if
  //  the sensor is left pulled high, when you touch
  //  two sensors, your body will transfer the charge between
  //  sensors.
  *port &= ~(bitmask);
  *ddr  |= bitmask;

  #ifdef DEBUG_CAPACITIVE_PADDLE
  static unsigned long last_cap_paddle_debug = 0;
  if ((millis() - last_cap_paddle_debug) > 250){
    debug_serial_port->flush();
    debug_serial_port->print("read_capacitive_pin: pin:");
    debug_serial_port->print(pinToMeasure);
    debug_serial_port->print(" cyc:");
    debug_serial_port->println(cycles);
    last_cap_paddle_debug = millis();
  }
  #endif //DEBUG_CAPACITIVE_PADDLE

  return cycles;

}

#endif //FEATURE_CAPACITIVE_PADDLE_PINS

//---------------------------------------------------------------------
#ifdef FEATURE_LED_RING
void update_led_ring(){

  static int last_leds = 0;
  int leds = 0;
  
  

  leds = map(configuration.wpm,led_ring_low_limit,led_ring_high_limit,0,15);
  if (leds < 0){leds = 0;}
  if (leds > 15){leds = 15;}
    
  if (leds != last_leds){ 
    digitalWrite(led_ring_le,LOW);
    
    digitalWrite(led_ring_sdi,LOW);
    digitalWrite(led_ring_clk,HIGH);
    digitalWrite(led_ring_clk,LOW);
    
    
    for (int x = 15;x > 0;x--){
      if (x <= leds){
        digitalWrite(led_ring_sdi,HIGH);
      } else {
        digitalWrite(led_ring_sdi,LOW);
      }
      digitalWrite(led_ring_clk,HIGH);
      digitalWrite(led_ring_clk,LOW);
    }
    
    //shiftOut(led_ring_sdi,led_ring_clk,MSBFIRST,(sequence[y][x] >> 8));    //High byte first
    //shiftOut(led_ring_sdi,led_ring_clk,MSBFIRST,sequence[y][x]);           //Low byte second
    digitalWrite(led_ring_le,HIGH); 
    
    last_leds = leds;
    digitalWrite(led_ring_sdi,LOW);
  }    
        
}
#endif //FEATURE_LED_RING
//---------------------------------------------------------------------
int paddle_pin_read(int pin_to_read){


  #ifndef FEATURE_CAPACITIVE_PADDLE_PINS
    #ifndef OPTION_INVERT_PADDLE_PIN_LOGIC
      return digitalRead(pin_to_read);
    #else 
      return !digitalRead(pin_to_read);
    #endif
  #else
      if (read_capacitive_pin(pin_to_read) > capacitance_threshold) {
        return LOW;
      } else {
        return HIGH;
      }
  #endif //FEATURE_CAPACITIVE_PADDLE_PINS  

}
//---------------------------------------------------------------------
#ifdef FEATURE_ALPHABET_SEND_PRACTICE
void command_alphabet_send_practice(){

  // contributed by Ryan, KC2ZWM

  int cw_char;
  char letter = 'A';
  
  do
  {
    cw_char = get_cw_input_from_user(0);
    if (letter == (char)(convert_cw_number_to_ascii(cw_char))){  
      if (correct_answer_led) {
        digitalWrite(correct_answer_led, HIGH);
      }
      if (wrong_answer_led) {
        digitalWrite(wrong_answer_led, LOW);
      }      
      beep();

      //send_dit(AUTOMATIC_SENDING);
      if (letter < 'Z')
        letter++;
      else
        letter = 'A';
    }
    else
    if (cw_char != 9) {
      if (wrong_answer_led) {
        digitalWrite(wrong_answer_led, HIGH);
      }  
      if (correct_answer_led) {
        digitalWrite(correct_answer_led, LOW);
      }          
      boop();
      boop();
      //send_dah(AUTOMATIC_SENDING);
    }
  } while (cw_char != 9);


  if (correct_answer_led) {
    digitalWrite(correct_answer_led, LOW);
  }
  if (wrong_answer_led) {
    digitalWrite(wrong_answer_led, LOW);
  }      

}
#endif //FEATURE_ALPHABET_SEND_PRACTICE


//---------------------------------------------------------------------
#ifdef FEATURE_PTT_INTERLOCK
void service_ptt_interlock(){

  static unsigned long last_ptt_interlock_check = 0;

  if ((millis() - last_ptt_interlock_check) > ptt_interlock_check_every_ms){
    if (digitalRead(ptt_interlock) == ptt_interlock_active_state){
      if (!ptt_interlock_active){
        ptt_interlock_active = 1;
        #ifdef FEATURE_DISPLAY
        lcd_center_print_timed("PTT Interlock",0,2000);
        #endif //FEATURE_DISPLAY
      }
    } else {
      if (ptt_interlock_active){
        ptt_interlock_active = 0;
      }
    }
    last_ptt_interlock_check = millis();
  }
}
#endif //FEATURE_PTT_INTERLOCK



//---------------------------------------------------------------------

