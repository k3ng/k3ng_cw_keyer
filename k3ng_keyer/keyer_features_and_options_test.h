
// ######## ########  ######  ######## 
//    ##    ##       ##    ##    ##    
//    ##    ##       ##          ##    
//    ##    ######    ######     ##    
//    ##    ##             ##    ##    
//    ##    ##       ##    ##    ##    
//    ##    ########  ######     ##    

#define TEST_CONFIG_1
// #define TEST_CONFIG_2

#if defined(TEST_CONFIG_1)


#define FEATURE_BUTTONS
#define FEATURE_COMMAND_MODE
#define FEATURE_COMMAND_LINE_INTERFACE  // Command Line Interface functionality
#define FEATURE_MEMORIES             // on the Arduino Due, you must have FEATURE_EEPROM_E24C1024 and E24C1024 EEPROM hardware in order to compile this
#define FEATURE_MEMORY_MACROS
// #define FEATURE_WINKEY_EMULATION    // disabling Automatic Software Reset is highly recommended (see documentation)
// #define FEATURE_BEACON                // Go into beacon mode if paddle_left pin is LOW at boot up
// #define FEATURE_BEACON_SETTING        // Go into beacon mode at boot up if EEPROM setting is enabled (\_ CLI Command)
// #define FEATURE_TRAINING_COMMAND_LINE_INTERFACE
// #define FEATURE_POTENTIOMETER         // do not enable unless you have a potentiometer connected, otherwise noise will falsely trigger wpm changes
// #define FEATURE_SIDETONE_SWITCH   // adds switch control for the sidetone output. requires an external toggle switch (assigned to an arduino pin - see keyer_pin_settings.h). 
// #define FEATURE_SIDETONE_NEWTONE      // Use the NewTone library, ~1k smaller code size than the standard tone library. Uses timer1 (pins 9 or 10)  https://bitbucket.org/teckel12/arduino-new-tone/wiki/Home
// #define FEATURE_SERIAL_HELP
// #define FEATURE_HELL
// #define FEATURE_PS2_KEYBOARD        // Use a PS2 keyboard to send code - Change keyboard layout (non-US) in K3NG_PS2Keyboard.h.  Additional options below.
// #define FEATURE_USB_KEYBOARD          // Use a USB keyboard to send code - Uncomment three lines in k3ng_keyer.ino (search for note_usb_uncomment_lines)
// #define FEATURE_CW_COMPUTER_KEYBOARD  // Have an Arduino Due or Leonardo act as a USB HID (Human Interface Device) keyboard and use the paddle to "type" characters on the computer
// #define FEATURE_DEAD_OP_WATCHDOG
#define FEATURE_AUTOSPACE
// #define FEATURE_FARNSWORTH
// #define FEATURE_DL2SBA_BANKSWITCH       // Switch memory banks feature as described here: http://dl2sba.com/index.php?option=com_content&view=article&id=131:nanokeyer&catid=15:shack&Itemid=27#english
// #define FEATURE_LCD_4BIT                // classic LCD display using 4 I/O lines
// #define FEATURE_LCD_8BIT                // classic LCD display using 8 I/O lines
// #define FEATURE_LCD_ADAFRUIT_I2C          // Adafruit I2C LCD display using MCP23017 at addr 0x20
// #define FEATURE_LCD_ADAFRUIT_BACKPACK    // Adafruit I2C LCD Backup using MCP23008 (courtesy Josiah Ritchie, KE0BLL)
// #define FEATURE_LCD_YDv1                // YourDuino I2C LCD display with old LCM 1602 V1 ic
// #define FEATURE_LCD1602_N07DH      // http://linksprite.com/wiki/index.php5?title=16_X_2_LCD_Keypad_Shield_for_Arduino
// #define FEATURE_LCD_SAINSMART_I2C
// #define FEATURE_LCD_FABO_PCF8574  // https://github.com/FaBoPlatform/FaBoLCD-PCF8574-Library
// #define FEATURE_LCD_MATHERTEL_PCF8574 // https://github.com/mathertel/LiquidCrystal_PCF8574
// #define FEATURE_LCD_I2C_FDEBRABANDER //https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library
// #define FEATURE_CW_DECODER              // https://github.com/k3ng/k3ng_cw_keyer/wiki/385-Feature:-CW-Decoder 
// #define FEATURE_SLEEP                   // go to sleep after x minutes to conserve battery power (not compatible with Arduino DUE, may have mixed results with Mega and Mega ADK)
// #define FEATURE_LCD_BACKLIGHT_AUTO_DIM  // turn off LCD backlight and/or dim Power Indicator LED after x minutes (LED requires a PWM pin)
// #define FEATURE_ROTARY_ENCODER          // rotary encoder speed control
// #define FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
// #define FEATURE_USB_MOUSE               // Uncomment three lines in k3ng_keyer.ino (search for note_usb_uncomment_lines)
// #define FEATURE_CAPACITIVE_PADDLE_PINS  // remove the bypass capacitors on the paddle_left and paddle_right lines when using capactive paddles
// #define FEATURE_LED_RING                // Mayhew Labs Led Ring support
// #define FEATURE_ALPHABET_SEND_PRACTICE  // enables command mode S command - created by Ryan, KC2ZWM
// #define FEATURE_COMMAND_MODE_PROGRESSIVE_5_CHAR_ECHO_PRACTICE // enables command mode U
// #define FEATURE_PTT_INTERLOCK 
// #define FEATURE_QLF
// #define FEATURE_EEPROM_E24C1024
// #define FEATURE_STRAIGHT_KEY
// #define FEATURE_DYNAMIC_DAH_TO_DIT_RATIO
#define FEATURE_PADDLE_ECHO
// #define FEATURE_STRAIGHT_KEY_ECHO
// #define FEATURE_AMERICAN_MORSE
// #define FEATURE_4x4_KEYPAD          // code contributed by Jack, W0XR - documentation: https://github.com/k3ng/k3ng_cw_keyer/wiki/380-Feature:-Keypad
// #define FEATURE_3x4_KEYPAD          // code contributed by Jack, W0XR - documentation: https://github.com/k3ng/k3ng_cw_keyer/wiki/380-Feature:-Keypad
// #define FEATURE_EXPERIMENTAL_DDS_SINEWAVE_SIDETONE_MEGA // DDS output Mega Digital Pin 46
// #define FEATURE_CLOCK  // NOT FINISHED YET
// #define FEATURE_SEQUENCER
// #define FEATURE_SD_CARD_SUPPORT
// #define FEATURE_SO2R_BASE           // SO2R Box base protocol extensions
// #define FEATURE_SO2R_SWITCHES       // SO2R Box TX and RX switches
// #define FEATURE_SO2R_ANTENNA        // SO2R Box antenna selection (not fully implemented)
#define FEATURE_COMMAND_MODE_ENHANCED_CMD_ACKNOWLEDGEMENT
// #define FEATURE_WEB_SERVER      // Details: https://github.com/k3ng/k3ng_cw_keyer/wiki/390-Feature:-Ethernet,-Web-Server,-and-Internet-Linking
// #define FEATURE_INTERNET_LINK   // Details: https://github.com/k3ng/k3ng_cw_keyer/wiki/390-Feature:-Ethernet,-Web-Server,-and-Internet-Linking

// UNDER DEVELOPMENT
// #define FEATURE_SINEWAVE_SIDETONE_USING_TIMER_1  // Arduino Uno: sidetone_line = 9 or 10 ; Mega: sidetone_line = 11, 12, or 13 (Further info: https://www.pjrc.com/teensy/td_libs_TimerOne.html )
// #define FEATURE_SINEWAVE_SIDETONE_USING_TIMER_3  // Arduino Mega: sidetone_line = 2, 3, or 5  (Further info: https://www.pjrc.com/teensy/td_libs_TimerOne.html)


#define FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT     // Activate the Command Line interface on the secondary serial port
#define OPTION_PRIMARY_SERIAL_PORT_DEFAULT_WINKEY_EMULATION  // Use when activating both FEATURE_WINKEY_EMULATION and FEATURE_COMMAND_LINE_INTERFACE 
                                                             //    simultaneously.  This will make Winkey emulation be the default at boot up; 
                                                             //    hold command button down at boot up to activate CLI mode

// #define OPTION_SUPPRESS_SERIAL_BOOT_MSG
#define OPTION_INCLUDE_PTT_TAIL_FOR_MANUAL_SENDING
#define OPTION_EXCLUDE_PTT_HANG_TIME_FOR_MANUAL_SENDING
// #define OPTION_WINKEY_DISCARD_BYTES_AT_STARTUP     // if ASR is not disabled, you may need this to discard errant serial port bytes at startup
// #define OPTION_WINKEY_STRICT_EEPROM_WRITES_MAY_WEAR_OUT_EEPROM // with this activated the unit will write non-volatile settings to EEPROM when set by Winkey commands
// #define OPTION_WINKEY_SEND_WORDSPACE_AT_END_OF_BUFFER
#define OPTION_WINKEY_STRICT_HOST_OPEN               // require an admin host open Winkey command before doing any other commands
#define OPTION_WINKEY_2_SUPPORT                      // comment out to revert to Winkey version 1 emulation
//this is removed from other features files - may depricate totally - 2016-09-28 - #define OPTION_WINKEY_SEND_BREAKIN_STATUS_BYTE       // additional code to check_dit_paddle() and check_dah_paddle() to send 0xC2 status byte when paddles are hit
#define OPTION_WINKEY_INTERRUPTS_MEMORY_REPEAT
// #define OPTION_WINKEY_UCXLOG_9600_BAUD          // use this only with UCXLog configured for Winkey 9600 baud mode
// #define OPTION_WINKEY_UCXLOG_SUPRESS_C4_STATUS_BYTE  // use this only with UCXlog if having issues with function key macros
#define OPTION_WINKEY_2_HOST_CLOSE_NO_SERIAL_PORT_RESET  // activate this when using Winkey 2 emulation and Win-Test
// #define OPTION_WINKEY_FREQUENT_STATUS_REPORT         // activate this to make Winkey emulation play better with RUMlog and RUMped
// #define OPTION_WINKEY_EXTENDED_COMMANDS_WITH_DOLLAR_SIGNS // experimental
#define OPTION_WINKEY_IGNORE_LOWERCASE               // Enable for typical K1EL Winkeyer behavior (use for SkookumLogger version 1.10.14 and prior to workaround "r" bug)
// #define OPTION_WINKEY_BLINK_PTT_ON_HOST_OPEN
// #define OPTION_WINKEY_ECHO_7C_BYTE                    // For debugging purposes only (only in this test feature and options file) (7C = half space character)
// #define OPTION_WINKEY_DO_NOT_SEND_7C_BYTE_HALF_SPACE         // For debugging purposes only (only in this test feature and options file)
// #define OPTION_WINKEY_SEND_VERSION_ON_HOST_CLOSE
// #define OPTION_WINKEY_PINCONFIG_PTT_CONTROLS_PTT_LINE  // Have Winkeyer PTT setting activate/deactivate PTT line rather than control buffered character PTT hold 
// #define OPTION_REVERSE_BUTTON_ORDER                // This is mainly for the DJ0MY NanoKeyer http://nanokeyer.wordpress.com/
#define OPTION_PROG_MEM_TRIM_TRAILING_SPACES         // trim trailing spaces from memory when programming in command mode
#define OPTION_DIT_PADDLE_NO_SEND_ON_MEM_RPT         // this makes dit paddle memory interruption a little smoother
// #define OPTION_MORE_DISPLAY_MSGS                     // additional optional display messages - comment out to save memory
// #define OPTION_WATCHDOG_TIMER                        // this enables a four second ATmega48/88/168/328 watchdog timer; use for unattended/remote operation only
// #define OPTION_MOUSE_MOVEMENT_PADDLE               // experimental (just fooling around) - mouse movement will act like a paddle
// #define OPTION_NON_ENGLISH_EXTENSIONS  // add support for additional CW characters (i.e. À, Å, Þ, etc.)
// #define OPTION_DISPLAY_NON_ENGLISH_EXTENSIONS  // LCD display suport for non-English (NO/DK/DE) characters - Courtesy of OZ1JHM
// #define OPTION_UNKNOWN_CHARACTER_ERROR_TONE
// #define OPTION_DO_NOT_SAY_HI
// #define OPTION_BLINK_HI_ON_PTT
// #define OPTION_PS2_NON_ENGLISH_CHAR_LCD_DISPLAY_SUPPORT // makes some non-English characters from the PS2 keyboard display correctly in the LCD display (donated by Marcin sp5iou)
// #define OPTION_PS2_KEYBOARD_RESET // reset the PS2 keyboard upon startup with 0xFF (contributed by Bill, W9BEL)
// #define OPTION_SAVE_MEMORY_NANOKEYER
#define OPTION_CW_KEYBOARD_CAPSLOCK_BEEP
// #define OPTION_CW_KEYBOARD_ITALIAN
// #define OPTION_CW_KEYBOARD_GERMAN
#define OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR
// #define OPTION_INVERT_PADDLE_PIN_LOGIC
#define OPTION_ADVANCED_SPEED_DISPLAY //enables "nerd" speed visualization on display: wpm, cpm (char per min), duration of dit and dah in milliseconds and ratio (contributed by Giorgio, IZ2XBZ)
// #define OPTION_PROSIGN_SUPPORT    // additional prosign support for paddle and straight key echo on display, CLI, and in memory storage
// #define OPTION_RUSSIAN_LANGUAGE_SEND_CLI // Russian language CLI sending support (contributed by Павел Бирюков, UA1AQC)
#define OPTION_DO_NOT_SEND_UNKNOWN_CHAR_QUESTION
// #define OPTION_INTERNET_LINK_NO_UDP_SVC_DURING_KEY_DOWN
// #define OPTION_CMOS_SUPER_KEYER_IAMBIC_B_TIMING_ON_BY_DEFAULT
// #define OPTION_SIDETONE_DIGITAL_OUTPUT_NO_SQUARE_WAVE

// #define OPTION_WORDSWORTH_CZECH
// #define OPTION_WORDSWORTH_DEUTSCH
// #define OPTION_WORDSWORTH_NORSK

// #define FEATURE_COMPETITION_COMPRESSION_DETECTION //(Experimental)

// #define OPTION_DIRECT_PADDLE_PIN_READS_MEGA   // only works with Mega and pins 2 and 5 - minor performance increase
// #define OPTION_DIRECT_PADDLE_PIN_READS_UNO    // Unos or Nanos pins 2 and 5 - do not enable on a nanoKeyer, it uses different pins

// #define OPTION_EXCLUDE_EXTENDED_CLI_COMMANDS

// #define OPTION_DFROBOT_LCD_COMMAND_BUTTONS

#define OPTION_EXCLUDE_MILL_MODE
// #define OPTION_NO_ULTIMATIC // reduce memory usage by removing ultimatic code.


// #define OPTION_DISABLE_SERIAL_PORT_CHECKING_WHILE_SENDING_CW
// #define OPTION_PERSONALIZED_STARTUP_SCREEN        // displays a user defined string of characters on the second or fourth row of the screen during startup. 1602 display requires OPTION_DO_NOT_SAY_HI
// #define OPTION_SWAP_PADDLE_PARAMETER_CHANGE_DIRECTION        // reverses the up/down direction when using the paddles to change the wpm or sidetone frequency
// #define OPTION_DISPLAY_MEMORY_CONTENTS_COMMAND_MODE

// #define OPTION_BEACON_MODE_MEMORY_REPEAT_TIME        // to space out the repeated playing of memory 1 when in beacon mode
// #define OPTION_BEACON_MODE_PTT_TAIL_TIME             // adds the ptt tail time to each playing of memory 1 in beacon mode

//  #define OPTION_WINKEY_PROSIGN_COMPATIBILITY  // Additional character mappings to support K1EL Winkey emulation prosigns


#endif




//*********************************************************************************************************************
//*********************************************************************************************************************
//*********************************************************************************************************************
//*********************************************************************************************************************
//*********************************************************************************************************************

#if defined(TEST_CONFIG_2)



#endif //TEST_CONFIG_2

// ######## ########  ######  ######## 
//    ##    ##       ##    ##    ##    
//    ##    ##       ##          ##    
//    ##    ######    ######     ##    
//    ##    ##             ##    ##    
//    ##    ##       ##    ##    ##    
//    ##    ########  ######     ##    
