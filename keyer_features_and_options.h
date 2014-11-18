// compile time features and options - comment or uncomment to add or delete features
// FEATURES add more bytes to the compiled binary, OPTIONS change code behavior

//#define FEATURE_SERIAL
//#define FEATURE_COMMAND_LINE_INTERFACE        // this requires FEATURE_SERIAL
//#define FEATURE_COMMAND_BUTTONS  // do not enable unless you have the corresponding resistors connected to the analog_buttons_pin
#define FEATURE_SAY_HI
//#define FEATURE_MEMORIES
//#define FEATURE_MEMORY_MACROS
//#define FEATURE_WINKEY_EMULATION    // this requires FEATURE_SERIAL - disabling Automatic Software Reset is highly recommended (see documentation)
//#define OPTION_WINKEY_2_SUPPORT     // requires FEATURE_WINKEY_EMULATION
//#define FEATURE_BEACON
//#define FEATURE_CALLSIGN_RECEIVE_PRACTICE
//#define FEATURE_POTENTIOMETER         // do not enable unless you have a potentiometer connected, otherwise noise will falsely trigger wpm changes
//#define FEATURE_SERIAL_HELP
//#define FEATURE_HELL
//#define FEATURE_PS2_KEYBOARD        // also uncomment PS2Keyboard line below and PS2Keyboard.h include at the top (requires FEATURE_SERIAL)
//#define FEATURE_USB_KEYBOARD         // also uncomment FEATURE_USB_KEYBOARD section below
//#define FEATURE_DEAD_OP_WATCHDOG
//#define FEATURE_AUTOSPACE
//#define FEATURE_FARNSWORTH
//#define FEATURE_DL2SBA_BANKSWITCH  // Switch memory banks feature as described here: http://dl2sba.com/index.php?option=com_content&view=article&id=131:nanokeyer&catid=15:shack&Itemid=27#english
//#define FEATURE_DISPLAY            // LCD display support (include one of the hardware options below)
//#define FEATURE_LCD_4BIT           // classic LCD disidefplay using 4 I/O lines
//#define FEATURE_LCD_ADAFRUIT_I2C            // Adafruit I2C LCD display using MCP23017 at addr 0x20
//#define FEATURE_LCD_YDv1          // YourDuino I2C LCD display with old LCM 1602 V1 ic
//#define FEATURE_CW_DECODER
//#define FEATURE_SLEEP                // go to sleep after x minutes to conserve battery power
//#define FEATURE_ROTARY_ENCODER       // rotary encoder speed control
//#define FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
//#define FEATURE_DIT_DAH_BUFFER_CONTROL
//#define FEATURE_HI_PRECISION_LOOP_TIMING
//#define FEATURE_USB_MOUSE
//#define FEATURE_CAPACITIVE_PADDLE_PINS // remove the bypass capacitors on the paddle_left and paddle_right lines when using capactive paddles
//#define FEATURE_LED_RING  // Mayhew Labs Led Ring support
//#define FEATURE_ALPHABET_SEND_PRACTICE  // enables command mode S command - created by Ryan, KC2ZWM

//#define OPTION_SUPPRESS_SERIAL_BOOT_MSG
#define OPTION_INCLUDE_PTT_TAIL_FOR_MANUAL_SENDING
#define OPTION_EXCLUDE_PTT_HANG_TIME_FOR_MANUAL_SENDING
#define OPTION_SERIAL_PORT_DEFAULT_WINKEY_EMULATION  // this will make Winkey emulation be the default at boot up; hold command button down at boot up to activate CLI mode
//#define OPTION_WINKEY_DISCARD_BYTES_AT_STARTUP     // if ASR is not disabled, you may need this to discard errant serial port bytes at startup
//#define OPTION_WINKEY_STRICT_EEPROM_WRITES_MAY_WEAR_OUT_EEPROM // with this activated the unit will write non-volatile settings to EEPROM when set by Winkey commands
//#define OPTION_WINKEY_SEND_WORDSPACE_AT_END_OF_BUFFER
#define OPTION_WINKEY_STRICT_HOST_OPEN               // require an admin host open Winkey command before doing any other commands
//#define OPTION_WINKEY_EXTENDED_COMMANDS            // in development
#define OPTION_WINKEY_SEND_BREAKIN_STATUS_BYTE       // additional code to check_dit_paddle() and check_dah_paddle() to send 0xC2 status byte when paddles are hit
#define OPTION_WINKEY_INTERRUPTS_MEMORY_REPEAT
#define OPTION_WINKEY_2_HOST_CLOSE_NO_SERIAL_PORT_RESET  // activate this when using Winkey 2 emulation and Win-Test
//#define OPTION_WINKEY_FREQUENT_STATUS_REPORT         // activate this to make things play better with RUMlog and RUMped
//#define OPTION_REVERSE_BUTTON_ORDER                // This is mainly for the DJ0MY NanoKeyer http://nanokeyer.wordpress.com/
#define OPTION_PROG_MEM_TRIM_TRAILING_SPACES         // trim trailing spaces from memory when programming in command mode
#define OPTION_DIT_PADDLE_NO_SEND_ON_MEM_RPT         // this makes dit paddle memory interruption a little smoother
//#define OPTION_MORE_DISPLAY_MSGS                     // additional optional display messages - comment out to save memory
//#define OPTION_N1MM_WINKEY_TAB_BUG_WORKAROUND        // enable this to ignore the TAB key in the Send CW window (this breaks SO2R functionality in N1MM)
//#define OPTION_WATCHDOG_TIMER                        // this enables a four second ATmega48/88/168/328 watchdog timer; use for unattended/remote operation only
//#define OPTION_MOUSE_MOVEMENT_PADDLE               // experimental (just fooling around) - mouse movement will act like a paddle
#define OPTION_NON_ENGLISH_EXTENSIONS  // add support for additional CW characters (i.e. À, Å, Þ, etc.)
//#define OPTION_PS2_NON_ENGLISH_CHAR_LCD_DISPLAY_SUPPORT // makes some non-English characters from the PS2 keyboard display correctly in the LCD display (donated by Marcin sp5iou)
//#define OPTION_KEEP_PTT_KEYED_WHEN_CHARS_BUFFERED    // this option keeps PTT high if there are characters buffered from the keyboard, the serial interface, or Winkey
#define OPTION_DISPLAY_NON_ENGLISH_EXTENSIONS  // LCD display suport for non-English (NO/DK/DE) characters - Courtesy of OZ1JHM