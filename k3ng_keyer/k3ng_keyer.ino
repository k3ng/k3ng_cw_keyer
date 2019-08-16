/*

 K3NG Arduino CW Keyer

 Copyright 2010 - 2019 Anthony Good, K3NG
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

Full documentation can be found at https://github.com/k3ng/k3ng_cw_keyer/wiki .  Please read it before requesting help.

For help, please post on the Radio Artisan group: https://groups.io/g/radioartisan .  Please do not email the developer directly for support.  Thanks

Wordsworth CW training method created by George Allison, K1IG
English code training word lists from gen_cw_words.pl by Andy Stewart, KB1OIQ

 Command Line Interface ("CLI") (USB Port) (Note: turn on carriage return if using Arduino Serial Monitor program)

    CW Keyboard: type what you want the keyer to send (all commands are preceded with a backslash ( \ )
    \?     Help                                      (requires FEATURE_SERIAL_HELP)
    \/     Paged Help                                (requires FEATURE_SERIAL_HELP)
    \#     Play memory #                             (requires FEATURES_MEMORIES; play memories 1 - 10 (0 = memory 10) )
    \a     Iambic A mode
    \b     Iambic B mode
    \c     Single Paddle mode
    \d     Ultimatic mode
    \e#### Set serial number to ####
    \f#### Set sidetone frequency to #### hertz
    \g     Bug mode
    \h     Toggle between CW and Hell sending                    (requires FEATURE_HELL)
    \i     Transmit enable/disable
    \j###  Dah to dit ratio (300 = 3.00, do \j alone to set to default)
    \k     CW Training Module                                     (requires FEATURE_TRAINING_COMMAND_LINE_INTERFACE)
    \l##   Set weighting (50 = normal, do \l alone to set to default)
    \m###  Set Farnsworth speed
    \n     Toggle paddle reverse
    \o     Toggle sidetone on/off
    \p#(#) Program memory #
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
    \|#### Set memory repeat (milliseconds)  (backslash and pipe)
    \*     Toggle paddle echo
    \`     Toggle straight key echo
    \^     Toggle wait for carriage return to send CW / send CW immediately
    \&     Toggle CMOS Super Keyer Timing on/off
    \%##   Set CMOS Super Keyer Timing %     
    \.     Toggle dit buffer on/off
    \-     Toggle dah buffer on/off
    \~     Reset unit
    \;     Toggle cw send echo
    \{     QLF mode on/off
    \>     Send serial number, then increment
    \<     Send current serial number
    \(     Send current serial number in cut numbers
    \)     Send serial number with cut numbers, then increment
    \[     Set Quiet Paddle Interruption 
    \=     Toggle American Morse mode    (requires FEATURE_AMERICAN_MORSE)
    \@     Mill Mode
    \}#### Set potentiometer range - low ## / high ##
    \"     Hold PTT active with buffered characters
    \;     FUTURE
    \]     FUTURE
    \_     FUTURE - Set Clock
    \\     Immediately clear the buffer, stop memory sending, etc.
    \:     Extended CLLI commands
            eepromdump              - do a byte dump of EEPROM for troubleshooting
            saveeeprom <filename>   - store EEPROM in a file
            loadeeprom <filename>   - load into EEPROM from a file
            printlog                - print the SD card log
            clearlog                - clear the SD card log
            ls <directory>          - list files in SD card directory
            cat <filename>          - print filename on SD card
            pl <transmitter> <mS>   - Set PTT lead time
            pt <transmitter> <mS>   - Set PTT tail time


 Buttons
    button 0: command mode / command mode exit
    button 0 + left paddle:  increase cw speed
    button 0 + right paddle: decrease cw speed
    button 1 - 12 hold + left paddle: repeat memory
    button 1 - 6 half second hold: switch to TX # 1 - 6

 Command Mode (press button0 to enter command mode and press again to exit)
    A  Switch to Iambic A mode
    B  Switch to Iambic B mode
    C  Switch to Single Paddle Mode
    D  Switch to Ultimatic mode
    E  Announce speed
    F  Adjust sidetone frequency
    G  Switch to bug mode
    H  Set weighting and dah to dit ratio to defaults
    I  TX enable / disable
    J  Dah to dit ratio adjust
    K  Toggle Dit and Dah Buffers on and off (Ultimatic Mode)
    L  Adjust weighting
    M  Change command mode speed
    N  Toggle paddle reverse
    O  Toggle sidetone on / off
    P#(#) Program a memory
    R####  Set serial number to ####
    S  Alphabet code practice (FEATURE_ALPHABET_SEND_PRACTICE)
    T  Tune mode
    U  Receive / Send Echo Practice
    V  Toggle potentiometer active / inactive
    W  Change speed
    X  Exit command mode (you can also press the command button (button0) to exit)
    Y#### Change memory repeat delay to #### mS
    Z  Autospace On/Off
    #  Play a memory without transmitting
    ?  Status
         1. Speed in WPM
         2. Keyer Mode (A = Iambic A, B = Iambic B, G = Bug, S = Single Paddle, U = Ultimatic)
         3. Weighting
         4. Dah to Dit Ratio

 Memory Macros
    \#     Jump to memory #
    \c     Play serial number with cut numbers, then increment
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
   CTRL-C           Single Paddle
   CTRL-D           Ultimatic
   CTRL-E           Set Serial Number
   CTRL-G           Bug
   CTRL-H           Toggle Hell Mode On/Off              (requires FEATURE_HELL)
   CTRL-I           TX enable / disable
   CTRL-M           Set Farnsworth Speed (0 = disabled)  (requires FEATURE_FARNSWORTH)
   CTRL-N           Paddle Reverse
   CTRL-O           Toggle Sidetone On/Off  
   CTRL-S           CMOS Superkeyer Timing On/Off 
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
   Keypad ENTER     Tune / Straight Key (USB Keyboard Only)
   
 USB Mouse
 
   Left Button      Dit
   Right Button     Dah
   Middle Button    Tune / Straight Key

 PS2 Keyboard Notes (FEATURE_PS2_KEYBOARD)

    To use FEATURE_PS2_KEYBOARD you need the K3NG_PS2Keyboard.h and K3NG_PS2Keyboard.cpp library files from https://github.com/k3ng/k3ng_cw_keyer/tree/master/libraries

    Some keyboards may require a reset sequence upon startup.  This is activated with OPTION_PS2_KEYBOARD_RESET.

 USB Keyboard Notes (FEATURE_USB_KEYBOARD)
 
    To use a USB keyboard you need to download and install this library: https://github.com/felis/USB_Host_Shield_2.0 .  You may use an Arduino Mega
    ADK board (which has a built in USB host interface, get or Circuits@Home USB shield (http://www.circuitsathome.com/products-page/arduino-shields/usb-host-shield-2-0-for-arduino),
    or built your own MAX3421 based USB port.
    
    If you are using an Arduino Mega ADK with Arduino IDE older than version 1.5.5, you must customize the USB Host Shield Library settings.h file!

    If you are using Arduino IDE older than version 1.5.5 and you experience a compiler error, you may need to add these lines to your keyer.h file:

        #define HID_PROTOCOL_KEYBOARD 1
        #define HID_PROTOCOL_MOUSE 2

    (Thanks Raimo, DL1HTB, for the two notes above.)

    Option Usb Computer Keyboard Emulation FEATURE_CW_COMPUTER_KEYBOARD
    (Arduino Due, Leonardo only)

       You can use your cw key as a computer keyboard. Your computer recognize the K3NG keyer as a normal keyboard.
       Language available English and Italian (more languages to add)
       Use following prosign to emulate Enter Key, Caps Lock, space and backspace:
       Prosign AA "Enter"
       Prosign DO "Caps Lock" (enable and disable)
       "......" or more "Backspace"
       "------" or more "Space"

  SIDETONE_SWITCH
       Enabling this feature and an external toggle switch  adds switch control for playing cw sidetone.
       ST Switch status is displayed in the status command.  This feature will override the software control of the sidetone (\o).
       
 
Useful Stuff
    Reset to defaults: squeeze both paddles at power up (good to use if you dorked up the speed and don't have the CLI)
    Press the right paddle to enter straight key mode at power up
    Press the left  paddle at power up to enter and stay forever in beacon mode

Recent Update History

    2.2.2015040402 More work on ARDUINO_SAM_DUE (documented)

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

    2.2.2015111501
      Fixed storage of KN prosign in memory (Thank Stefan, DL1SMF)

    2.2.2015120401  
      Fixed compiler warning: large integer implicitly truncated to unsigned type - jump_back_to_y = 99999;

    2.2.2015121901
      OPTION_PROSIGN_SUPPORT - additional prosign support for memory storage

    2.2.2015122001
      OPTION_PROSIGN_SUPPORT - updated; forgot to add functionality to paddle echo

    2.2.2015122801
      void send_the_dits_and_dahs(char * cw_to_send) compile warning fix

    2.2.2016010301
      Fixed compiler error when OPTION_SAVE_MEMORY_NANOKEYER and FEATURE_COMMAND_LINE_INTERFACE are enabled (Thanks, Gerd, DD4DA)
      void play_memory (byte memory_number) near line 10049 - static String serial_number_string - removed static declration to fix compiler warning (Thanks, Gerd, DD4DA)
      
    2.2.2016010302  
      Winkey emulation pin config bug fix (Thanks, Gerd, DD4DA)

    2.2.2016011801
      New and improved FEATURE_SLEEP code contributed by Graeme, ZL2APV

    2.2.2016012001
      Fixed compile error involving serial_number, FEATURE_PS2_KEYBOARD, and HARDWARE_NANOKEYER_REV_D (Thanks, Kari, OH6FSG)

    2.2.2016012002
      HARDWARE_TEST
      Enhanced FEATURE_SLEEP to have pin that indicates sleep state: define keyer_awake 0 ; KEYER_AWAKE_PIN_AWAKE_STATE, KEYER_AWAKE_PIN_ASLEEP_STATE   

    2.2.2016012003
      Fixed compiler warning for void play_memory() and returns; (Thanks, Gerd, DD4DA)

    2.2.2016012004
      Modified includes so library files can be put in \libraries\ folder rather than ino directory so Arduino 1.6.7 works (thanks Giorgio, IZ2XBZ)) 

    2.2.2016012101
      Beta testing FEATURE_INTERRUPT_PADDLE_READS

    2.2.2016012301
      Fixed compilation error: 10306: error: return-statement with no value, in function returning byte (thanks Giorgio, IZ2XBZ))

    2.2.2016012302
      Merge of bug fix from JG2RZF: Winkey - CTESTWIN sends 0x00 as "HSCW Speed Change" to keyer (thanks JG2RZF)

    2.2.2016012501
      loop_element_lengths - minor change to paddle reading that may have an effect at high speeds

    2.2.2016012502
      tx_key_dit_and_dah_pins_active_state and tx_key_dit_and_dah_pins_inactive_state settings
      OPTION_RUSSIAN_LANGUAGE_SEND_CLI contributed by Павел Бирюков, UA1AQC

    2.2.2016012601 
      Winkey emulation support for 0x1D HSCW overloaded command to switch transmitters (thanks JG2RZF)
      Moved stuff from keyer_settings*.h to keyer.h (no need to tweak these or have different entries for different hardware)
     
    2.2.2016012801
      Fixed issue with goertzel.h being required for compilation even when it wasn't needed

    2.2.2016012901
      Removed experimental feature  

    2.2.2016012902
      FEATURE_LCD_ADAFRUIT_BACKPACK - support for Adafruit I2C LCD Backup using MCP23008 (courtesy Josiah Ritchie, KE0BLL)

    2.2.2016020801
      PROSIGN_HH (courtesy of Vincenzo, IZ0RUS)
    
    2.2.2016020802
      OPTION_DO_NOT_SEND_UNKNOWN_CHAR_QUESTION

    2.2.2016030501
      FEATURE_LCD_SAINSMART_I2C

    2.2.2016030701
      Fixed FEATURE_LCD_SAINSMART_I2C initialization

    2.2.2016030801
      Fixed FEATURE_LCD_SAINSMART_I2C again

    2.2.2016031801
      Ethernet, web server and Internet linking functionality in beta / development (DEFINEs are in HARDWARE_TEST files only right now)
      #define FEATURE_WEB_SERVER
      #define FEATURE_INTERNET_LINK

      #define OPTION_INTERNET_LINK_NO_UDP_SVC_DURING_KEY_DOWN

      #define FEATURE_ETHERNET_IP {192,168,1,179}                      // default IP address
      #define FEATURE_ETHERNET_MAC {0xDE,0xAD,0xBE,0xEF,0xFE,0xEE}

      #define FEATURE_ETHERNET_GATEWAY {192,168,1,1}                   // default gateway
      #define FEATURE_ETHERNET_SUBNET_MASK {255,255,255,0}                  // default subnet mask
      #define FEATURE_ETHERNET_WEB_LISTENER_PORT 80
      #define FEATURE_UDP_SEND_BUFFER_SIZE 128
      #define FEATURE_UDP_RECEIVE_BUFFER_SIZE 128

      #define FEATURE_INTERNET_LINK_MAX_LINKS 2
      #define FEATURE_INTERNET_LINK_DEFAULT_RCV_UDP_PORT 8888
      #define FEATURE_INTERNET_LINK_BUFFER_TIME_MS 500 

    2.2.2016040501
      Fixed bug with OPTION_DO_NOT_SEND_UNKNOWN_CHAR_QUESTION and ? character not being sent with keyboard and Winkey operation
      Still working on web server functionality

    2.2.2016042601
      More web server functionality work   
      #define FEATURE_INTERNET_LINK_KEY_DOWN_TIMEOUT_SECS 8 
      \P command now can program memories above #10

    2.2.2016053001
      Additional DEBUG_WINKEY messages for Winkeyer troubleshooting  
      #define WINKEY_DEFAULT_BAUD 1200 (added setting for UCXLog 9600 baud Winkey setting)
      Fixed minor Winkey emulation bug with recognizing byte 0x7C as a half dit space when OPTION_WINKEY_IGNORE_LOWERCASE is enabled

    2.2.2016062101
      New CLI commands:
        \>     Send serial number, then increment
        \<     Send current serial number
        \(     Send current serial number in cut numbers
        \)     Send serial number with cut numbers, then increment


    2.2.2016070701
      Corrected Nanokeyer Rev B and Rev D configurations

    2.2.2016070702
      Setting for speed potentiometer check interval: #define potentiometer_check_interval_ms 150  

    2.2.2016071001
      OPTION_WINKEY_UCXLOG_9600_BAUD for UCXLog 9600 baud support (I can't get UCXlog to work at 1200 baud)
    
    2.2.2016071801
      Now have FEATURE_AUTOSPACE and FEATURE_DEAD_OP_WATCHDOG disabled by default for HARDWARE_NANOKEYER_REV_D

    2.2.2016071802
      FEATURE_CAPACITIVE_PADDLE_PINS: capactive_paddle_pin_inhibit_pin

    2.2.2016072301
      Added dependency check for FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
      More Winkey emulation debugging; working on strange issues with UcxLog interoperability.  UcxLog working with normal 1200 baud mode today.  Hmmm.

    2.2.2016080101
      Troubleshooting some UCXLog Winkey weirdness some users are experiencing.  Created OPTION_WINKEY_UCXLOG_SUPRESS_C4_STATUS_BYTE

    2.2.2016080301
      Disabled echoing of 7C (half space character) byte in Winkey emulation

    2.2.2016080601
      More messing around with UCXlog...
      OPTION_WINKEY_DO_NOT_ECHO_7C_BYTE                    // Might need for UCXlog? (7C = half space character)
      OPTION_WINKEY_DO_NOT_SEND_7C_BYTE_HALF_SPACE 

    2.2.2016081201
      OPTION_WINKEY_DO_NOT_ECHO_7C_BYTE is changed to OPTION_WINKEY_ECHO_7C_BYTE and only in the test feature and options file for testing/debugging purposes
      OPTION_WINKEY_DO_NOT_SEND_7C_BYTE_HALF_SPACE - not placing this into production.  this was to troubleshoot issues with UCXLog 

    2.2.2016081601
      Updated paddle echo to work with bug mode 

    2.2.2016090701
      More efficient code suggestion from Paul, K1XM, implemented in loop_element_lengths()

    2.2.2016090801
      Removed legacy option: OPTION_USE_ORIGINAL_VERSION_2_1_PS2KEYBOARD_LIB

    2.2.2016090802
      Corrected error in FEATURE_ROTARY_ENCODER ttable (thanks, frye.dale)  

    2.2.2016091401
      More frequent PTT line tail time checking 

    2.2.2016091602
      Reversing munged GitHub merge 

    2.2.2016091901
      Manual merge of toyo pull request #22  
      It is no longer necessary to specify HARDWARE_ARDUINO_DUE in keyer_hardware.h.  It is automatically detected now.

    2.2.2016092701
      Command Mode: command L - adjust weighting  

    2.2.2016092702
      Winkey Emulation - changed paddle interrupt behavior to send 0xC2 and then 0xC0 rather than just 0xC0  

    2.2.2016092801
      Winkey Emulation - changed paddle interrupt behavior to send 0xC6,0xC0 rather than 0x64,0xC0

    2.2.2016092802
      Fixed issue with configuration in eeprom colliding with memory 0 (1) (Thanks, Ivan, IX1FJG) 

    2.2.2016092803
      Winkey Emulation - changed paddle interrupt behavior to also clear send buffer 

    2.2.2016092901
      Improved opposite paddle dit/dah insertion in Ultimatic mode  

    2.2.2016100601
      Improved paddle break in for memory playing and Winkey interruption
      Fixed various compile bugs that have crept into the code  

    2.2.2016102401
      Updated \J (dah to dit ratio) and \L (weighting) CLI commands so that without arguments they set the parameters to defaults 

    2.2.2016102801
      Single Paddle mode, C command  

    2.2.2016103101
      Quiet Paddle Interruption feature - set with \[ command in CLI.  Value is 0 to 20 element lengths; 0 = off   

    2.2.2016110801
      Integrated OK1RR Tiny Keyer hardware files - HARDWARE_TINYKEYER in keyer_hardware.h file

    2.2.2016110802
      New command mode command H - set weighting and dah to dit ratio to defaults
      New command mode command ? - Status

    2.2.2016111701
      FEATURE_CW_COMPUTER_KEYBOARD enhancements from Giorgio IZ2XBZ
   
    2.2.2016111702
      Eliminated FEATURE_DIT_DAH_BUFFER_CONTROL code; it's compiled in with core code now.  Also depricated OPTION_DIT_DAH_BUFFERS_OFF_BY_DEFAULT_FOR_FEATURE_DIT_DAH_BUFFER_CONTROL

    2.2.2016112301
      New command mode command K: toggle dit and dah buffer on and off

    2.2.2016112302
      Updated keyer_hardware.h to accomodate Leonardo, Yun, Esplora, and other boards to compile with Serial related functionality. 

    2.2.2016112401
      Updated dit and dah buffer control to change automatically with Iambic A & B and Ultimatic  

    2.2.2016112501
      Code comment update

    2.2.2016112502
      Merged in GitHub pull request 24 https://github.com/k3ng/k3ng_cw_keyer/pull/24 from Giorgio IZ2XBZ  

    2.2.2016112701
      Improved performance when sending large macros from logging and contest programs using Winkey emulation.  Thanks, Martin OK1RR for discovery and testing   

    2.2.2016112702
      Updated command mode K command to work only when in Ultimatic mode

    2.2.2016112901
      Fixed bug with command mode status command reporting wrong keyer mode.  Also fixed CLI status query reporting wrong keyer mode while in command mode

    2.2.2016120101
      Compilation of serial related functionality for TEENSYDUINO
    
    2.2.2016120102
      Comilation issue fix for ARDUINO_MAPLE_MINI.  Thanks, Edgar, KC2UEZ

    2.2.2016120401
      Added keyer_stm32duino.h with function declarations to make ARDUINO_MAPLE_MINI compilation work.  Thanks, Edgar, KC2UEZ

    2.2.2016120901
      Merged pull request STM32duino compatibilty 30. Thanks, Edgar, KC2UEZ

    2.2.2016120902
      Fixed bug in command mode when OPTION_WATCHDOG_TIMER is enabled.  Thanks, disneysw.

    2.2.2016121001
      Support for FUNtronics FK-10 contributed by disneysw. HARDWARE_FK_10 in keyer_hardware.h; files: keyer_pin_settings_fk_10.h, keyer_features_and_options_fk_10.h, keyer_settings_fk_10.h

    2.2.2016121201
      Additional work on web interface

    2.2.2016121202
      Additional work on web interface
      Mainstreamed FEATURE_HI_PRECISION_LOOP_TIMING code.  No longer an option.  (Need to clean out of keyer_feature_and_options files)

    2.2.2017010301
      FEATURE_AMERICAN_MORSE - American Morse Code sending mode.  \= command in the CLI switches to American Morse Code https://en.wikipedia.org/wiki/American_Morse_code

    2.2.2017011701
      FEATURE_LCD1602_N07DH - added include for Wire.h (Thanks, Hjalmar, OZ1JHM)

    2.2.2017011702
      Pull request 32 https://github.com/k3ng/k3ng_cw_keyer/pull/32 merged which adds FEATURE_SIDETONE_SWITCH.  Also fixed up additional features and pins files. (Thanks, dfannin)

    2.2.2017011703
      Added OPTION_CW_KEYBOARD_GERMAN (Thanks, Raimo, DL1HTB)

    2.2.2017012101
      New command mode command R: set serial number  

    2.2.2017020701
      WD9DMP contributed fixes and changes
        Reconciled CLI Command/Memory Macro Help code with front comments and actual code so all commands now display with /?
        Removed unimplemented Memory Macros from CLI Help
        Updated descriptions of CLI Command/Memory Macro functions in help display (some missing serial number lack increment description where present in code)
        Fixed issue where the TX ON/TX Off LCD display state in Command Mode could get out of sync with the actual key_tx state
        Fixed serial numbers not displaying in LCD and CLI when playing back from Macro or CLI command (please check conditional compilations)
        Fixed capialization in HELP display and Status output to be consistent
        Changed "$" at end of non-empty memory contents in CLI status display to "_" to help determine if a trailing space is present.

    2.2.2017020702
      Fixed typo 

    2.2.2017021001 
      Fixed typo - 'include <Keyboard.h>' was commented out (thanks Raimo, DL1HTB)

    2017.02.12.01  
      WD9DMP contributed addition fixes
      Changed version number scheme.  The 2.2 really isn't significant anymore.

    2017.02.12.02
      loop_element_lengths sending_mode code error fixed.  (Thanks, WD9DMP)

    2017.02.16.01
      Added note: Have a problem with Keyboard.h not found?  See https://github.com/k3ng/k3ng_cw_keyer/issues/35

    2017.03.12.01
      WD9DMP contribution: Added checks to see that keyer is NOT in command mode before allowing keyboards or CLI to toggle key_tx flag state, otherwise key commands could key transmitter
      Added library.properties file to K3NG_PS2Keyboard library to support the Arduino IDE eye candy bloatware Library Manager

    2017.03.12.02
      Added CTRL-S keystroke to toggle CMOS Superkeyer Timing on and off in FEATURE_PS2_KEYBOARD and FEATURE_USB_KEYBOARD  

    2017.03.22.01
      Commented out include <Keyboard.h> due to unexplained compilation error in Arduino 1.8.1

    2017.03.30.01
      FEATURE_4x4_KEYPAD and FEATURE_3x4_KEYPAD code contributed by Jack, W0XR

    2017.04.19.01
      Minor change in keyer.h to prevent errors with some versions of Arduino IDE when compiling USB HID features

    2017.04.19.02
      OPTION_CMOS_SUPER_KEYER_IAMBIC_B_TIMING_ON_BY_DEFAULT and two code fixes contributed by Raimo, DL1HTB, thanks!

    2017.04.22.01
      Webserver About screen now handles millis() uptime rollover 
      Bug fix in loop_element_lengths and Internet Linking functionality UDP packet handling 

    2017.04.27.01
      Added bounds checking for void speed_set()

    2017.05.03.01
      FEATURE_TRAINING_COMMAND_LINE_INTERFACE
      First release of Wordsworth training functionality

    2017.05.05.01
      keyer_training_text_czech.h contributed by Martin, OK1RR
      Czech language support for Wordsworth training: OPTION_WORDSWORTH_CZECH

    2017.05.06.01
      Lots of new functionality in FEATURE_TRAINING_COMMAND_LINE_INTERFACE
      keyer_training_text_norsk.h content contributed by Karl, LA3FY
      Norwegian language support for Wordsworth training: OPTION_WORDSWORTH_NORSK

    2017.05.09.01
      FEATURE_TRAINING_COMMAND_LINE_INTERFACE - fixed issue with carriage returns and line feeds causing menus to reprint

    2017.05.09.02
      Updated FEATURE_4x4_KEYPAD and FEATURE_3x4_KEYPAD to allow memory stacking

    2017.05.12.01
      Fixed bug with \< and \> commands and carriage returns, and now handle serial number sending through the send buffer rather than direct sending
      Fixed issue with non-English characters in Wordsworth by implementing OPTION_NON_ENGLISH_EXTENSIONS within Wordsworth

    2017.05.12.02
      Added DEBUG_MEMORY_LOCATIONS
  
    2017.05.13.01
      Improved reading of serial receive buffer in serial_program_memory to facilitate programming of large memories.  Related parameter: serial_program_memory_buffer_size

    2017.05.13.02
      Added random code group practice

    2017.05.14.01
      Optimization of serial_program_memory()

    2017.06.03.01
      Fixed a bug I introduced back in version 2017.05.12.01 or so with memory serial number macros not playing in right sequence (Thanks, Fred, VK2EFL)

    2017.06.03.02
      Added OPTION_SIDETONE_DIGITAL_OUTPUT_NO_SQUARE_WAVE which changes the sidetone line to go high/low rather than output square wave, for driving an external audio amplifier

    2017.06.14.02
      Fixed command line interface bug with /> and /< commands and carriage returns

    2017.06.28.01
      Fixed bug with \T command when FEATURE_COMMAND_BUTTONS is not activated. (Thanks, Павел Бирюков)

    2017.06.28.02
      Keyer now reports rotary encoder speed changes in K1EL Winkey emulation (Thanks, Marc-Andre, VE2EVN)

    2017.07.24.01
      Fixed keypad asterisk and pound definitions (Thanks, Fred, VK2EFL)  

    2017.07.31.01
      Fixed bug with memory macro \X not switching to transmitters 4, 5, or 6 (Thanks, Larry, DL6YY)

    2018.01.05.01
      When entering into program memory mode in command mode, a beep is now emitted rather than a dit
      Implemented CLI Receive / Transmit Echo Practice  (\K E)

    2018.01.06.01  
      Enhancements to CLI CW Training module

    2018.01.13.01
      O command in command mode, keyboard input, and CLI enhanced to cycle through sidetone on / off / paddle only; code provided by Marc-Andre, VE2EVN  

    2018.01.13.02
      Improvements to LCD display in practice modes; code provided by Fred, VK2EFL
      Minor tweaks to handle LCD displays with lesser number of columns
      Bug fixes involving practice modes and garbage left in paddle_echo_buffer

    2018.01.14.01
      Added \/ (backslash slash) CLI command for Paged Help
      Added /@ CLI command for Mill Mode
      ESC in CLI will now dump type ahead buffer and stop memory repeat, just like \\
      Added /} CLI command to set potentiometer range

    2018.01.25.01
      Fixed bug in FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING  

    2018.01.28.01
      Added carriage return and newline to the beginning of several CLI command responses  
      Add command mode command M - set command mode WPM (command mode now has a speed setting independent of regular keyer speed)

    2018.01.29.01
      Working on FEATURE_CLI_EXPERT_MENU and FEATURE_SD_CARD_SUPPORT
      CLI status now shows speed potentiometer range 

    2018.02.01.01
      Changed Toggle cw send echo CLI command from \: to \;
      Deprecated FEATURE_CLI_EXPERT_MENU
      Working on Extended CLI Commands /:
      Added OPTION_EXCLUDE_EXTENDED_CLI_COMMANDS
      Extended CLI Commands
        eepromdump
        saveeeprom <filename>
        loadeeprom <filename>
        printlog
        clearlog
        ls <directory>
        cat <filename>
      Added serial support for ARDUINO_AVR_LEONARDO_ETH 

    2018.02.01.02
      Fixed bug with dit_buffer_off and dah_buffer_off not being initialized from eeprom settings at boot up (Thanks, YU7MW)

    2018.02.05.01
      Typo fix: ifdef defined(__AVR__) (Thanks, Glen, N1XF https://github.com/k3ng/k3ng_cw_keyer/issues/19) 

    2018.02.05.02
      Fixed https://github.com/k3ng/k3ng_cw_keyer/issues/40 (Thanks, Glen, N1XF)

    2018.02.07.01
      Added support for 8 column LCD displays  

    2018.02.25.01
        FEATURE_SIDETONE_SWITCH switch line is now set for internal pullup so it won't cause a problem if left floating 

    2018.03.04.01
      Changed wpm_command_mode from uint8_t to unsigned int
      Fixed minor bug with junk left in paddle echo buffer after exiting command mode

    2018.03.04.02
      Added OPTION_DFROBOT_LCD_COMMAND_BUTTONS to use this board https://www.dfrobot.com/wiki/index.php/Arduino_LCD_KeyPad_Shield_(SKU:_DFR0009) with FEATURE_COMMAND_BUTTONS

    2018.03.08.01
      Additional OPTION_DFROBOT_LCD_COMMAND_BUTTONS code and corresponding DEBUG_BUTTONS code

    2018.03.08.02
      Added OPTION_EXCLUDE_MILL_MODE

    2018.03.11.01
      New feature! FEATURE_SEQUENCER  Wiki: https://github.com/k3ng/k3ng_cw_keyer/wiki/383-Feature:-Sequencer
      define sequencer_1_pin 0
      define sequencer_2_pin 0
      define sequencer_3_pin 0
      define sequencer_4_pin 0
      define sequencer_5_pin 0
      define ptt_input_pin 0
      define sequencer_pins_active_state HIGH
      define sequencer_pins_inactive_state LOW
      define ptt_line_active_state HIGH
      define ptt_line_inactive_state LOW
      define tx_key_line_active_state HIGH
      define tx_key_line_inactive_state LOW   
      define ptt_input_pin_active_state LOW
      define ptt_input_pin_inactive_state HIGH  
      New commands:
        \:pl <tx_number> <time_in_mS> - set PTT lead time
        \:pt <tx_number> <time_in_mS> - set PTT tail time
        \:pa <sequencer_number> <time_in_mS> - PTT active to sequencer active time
        \:pi <sequencer_number> <time_in_mS> - PTT inactive to sequencer inactive time
        \:timing - show all current timing settings
      PTT lead and tail times are now stored in EEPROM and setable at runtime with extended commands \:pl and \:pt
      Additional documentation: https://github.com/k3ng/k3ng_cw_keyer/wiki/225-Sidetone,-PTT,-and-TX-Key-Lines

    2018.03.14.01
      FEATURE_LCD_FABO_PCF8574 - Added support for FaBo LCD https://github.com/FaBoPlatform/FaBoLCD-PCF8574-Library 

    2018.03.16.01
      Fixed compile error involving lcd_string (Thanks, Jeff, N0MII)  

    2018.03.23.01
      Bug with automatic sending interruption fixed (Thanks, Larry, F6FVY)  

    2018.03.23.02
      Fixed compilation bug with FEATURE_PTT_INTERLOCK when FEATURE_WINKEY_EMULATION was disabled  

    2018.03.24.01
      Support for ARDUINO_MAPLE_MINI contributed by Marcin SP5IOU
      HARDWARE_MAPLE_MINI hardware profile in keyer_hardware.h

    2018.03.29.01
      Support for ARDUINO_GENERIC_STM32F103C (Blue pill boards) contributed by Marcin SP5IOU
      HARDWARE_GENERIC_STM32F103C hardware profile in keyer_hardware.h
      How to deal with those boards with Arduino: https://www.techshopbd.com/uploads/product_document/STM32bluepillarduinoguide(1).pdf

    2018.03.30.01
      tx_inhibit and tx_pause pins implemented for use with contest station interlock controllers.  Documentation: https://github.com/k3ng/k3ng_cw_keyer/wiki/225-Sidetone,-PTT,-and-TX-Key-Lines#tx-inhibit-and-pause
 
    2018.03.31.01
      Now have OPTION_WINKEY_2_HOST_CLOSE_NO_SERIAL_PORT_RESET activated in feature files by default.

    2018.04.07.01
      Improved tx_pause when buffer or memory sending is paused mid-character

    2018.04.15.01
      Added HARDWARE_MORTTY  

    2018.04.16.01
      Added OPTION_WINKEY_BLINK_PTT_ON_HOST_OPEN - visual cue that Winkey HOST OPEN has occurred

    2018.04.20.01
      FEATURE_WINKEY_EMULATION - Now clear manual ptt invoke upon host open, host close, and 0A commands  

    2018.04.22.01
      Added OPTION_BLINK_HI_ON_PTT - on units that lack a sidetone speaker, this will blink HI on the PTT line on boot up
      Fixed issue in keyer_pin_settings_mortty.h  
      Added TX Inhibit and TX Pause status in Command Line Interface Status \S command

    2018.04.23.01
      OPTION_KEEP_PTT_KEYED_WHEN_CHARS_BUFFERED - when Winkeyer Pause command is received, PTT is now de-asserted until Pause is cleared

    2018.04.29.01
      Deprecated OPTION_KEEP_PTT_KEYED_WHEN_CHARS_BUFFERED.  Winkey PINCONFIG PTT bit now sets / unsets ptt_buffer_hold_active
      New CLI command \" to activate/deactivate PTT Hold Active When Characters Buffered functionality

    2018.05.04.01
      Winkey Emulation - minor addition to filtering of values echoed from send_char() 

    2018.05.05.01
      Winkey Emulation - minor bug fix with handling of PTT tail time setting.  Also added support in Admin Get Values command to report PTT lead and tail time  

    2018.05.08.01
      Fixed bug in CLI with multiple backspaces / backspaces exceeding number of characters in buffer locking up the keyer (Thanks, WF3T)

    2018.05.10.01
      Removed OPTION_N1MM_WINKEY_TAB_BUG_WORKAROUND.  The bug appears to be gone when testing a recent version of N1MM+.

    2018.05.17.01
      Updated to better handle STM32 board compilation (Thanks, Marcin, SP5IOU) 

    2018.05.28.01
      Addressed potential issue with random pauses when using Winkey emulation with Writelog and Wintest: Changed check_for_dirty_configuration so it won't write to eeprom when there are characters buffered or PTT is active.  Also, Winkey Pinconfig command no longer sets config_dirty.   

    2018.05.31.01
      Fixed design flaw with ptt_input_pin and manual PTT invoke commands not working independently (Thanks, Mek, SQ3RX)

    2018.07.15.01
      Added FEATURE_LCD_8BIT for controlling standard LCD displays with 8 data lines

    2018.08.03.01
      Fixed bug FEATURE_FARNSWORTH that was inadvertently introduced with command mode speed feature (Thanks, Jim, W5LA) 

    2018.08.04.01
      Added additional checking of serial port while sending automatic CW in order to better interrupt character sending (Thanks, Max, NG7M)
      Added OPTION_DISABLE_SERIAL_PORT_CHECKING_WHILE_SENDING_CW to disable this additional checking if desired or for troubleshooting 

    2018.08.13.01
      More accurate Farnsworth timing; code contributed by Jim, W5LA 

    2018.08.21.01
      Merged pull request https://github.com/k3ng/k3ng_cw_keyer/pull/50
      HARDWARE_YAACWK contributed by Federico Pietro Briata, IZ1GLG <federico@briata.org>

    2018.08.21.02  
      Different Farnsworth timing calculation.  Introduced farnsworth_timing_calibration in settings files.

    2018.08.23.01
      Fixed bug with Farnsworth timing not occurring during intercharacter time, however now overall WPM timing not right...  

    2018.08.25.01
      More work on Farnsworth timing.  The timing appears correct now with PARIS testing, however using farnsworth_timing_calibration = 0.35  
      Now allow /M0 command to disable Farnsworth

    2018.08.30.01
      Think we got Farnsworth timing right now.  Thanks, Jim, W5LA !  

    2018.10.17.01
      PTT lead and tail times, and sequencer times can now be set up to 65,535 mS  
      Updated help text with extended commands

    2018.10.17.02
      Fixed bug in K1EL Winkeyer Emulation paddle echo 

    2018.10.17.03
      Improved potentiometer noise immunity, added potentiometer_reading_threshold in settings (Thanks, Wolf, DK7OB)
      Fixed non-optimal potentiometer speed change comparison (Thanks, Wolf, DK7OB)

    2018.10.19.01
      Enabling OPTION_DISABLE_SERIAL_PORT_CHECKING_WHILE_SENDING_CW by default.  There appear to be lock ups caused by the serial port checking while sending functionality.  Investigating.  

    2018.10.21.01
      Fixed Funtronics FK-10 LCD pin definitions that were broken in 2018.07.15.01 (Thanks, Jeff, N0MII )

    2018.11.09.01
      Fixed bug with K1EL Winkey emulation with Admin Get Values PTT Hang Time value returned (Thanks, Dariusz, SP2MKI)  
      Improved reporting of K1EL Winkey emulation PTT tail time and also now have tail time change dynamically with WPM changes to better follow specification
      Fixed bug in Beacon Mode where dit and dah paddle would interrupt beacon code
      Fixed bug with K1EL Winkey emulation with dead op watchdog enabling / disabling, and reporting (Thanks, Dariusz, SP2MKI)  
      K1EL Winkey emulation PINCONFIG and Winkeyer Mode commands now write to eeprom

    2018.11.09.02
      CLI Status now shows paddle and straight key echo state  

    2018.12.25.01
      Fixed potential bug in sleep functionality timing 

    2019.02.05.01
      Fixed bug in command mode K command when in ultimatic mode (Thanks, Rich)
      Under Development: FEATURE_SINEWAVE_SIDETONE_USING_TIMER_1 and FEATURE_SINEWAVE_SIDETONE_USING_TIMER_3 in keyer_features_and_options_test.h  

    2019.02.05.02
      Improvement in how K1EL Winkey emulation buffered speed command speed changing and clearing is handled

    2019.04.06.01
      OPTION_DISABLE_SERIAL_PORT_CHECKING_WHILE_SENDING_CW has been flipped and changed to OPTION_ENABLE_SERIAL_PORT_CHECKING_WHILE_SENDING_CW_MAY_CAUSE_PROBLEMS
      Fixed some compiler warnings

    2019.04.07.01
      Fixed additional compiler warnings

    2019.04.27.01
      FEATURE_DISPLAY - fixed issue with cpm label and FunKeyer.  (Thanks, Fred, VK2EFL)
      Fixed bug introduced in version 2019.02.05.01 with not being able to switch between CLI and Winkey at startup using command button when FEATURE_COMMAND_LINE_INTERFACE and FEATURE_WINKEY_EMULATION both compiled in (Thanks, Dave, G8PGO)

    2019.04.27.02
      Merge of pull request 59 https://github.com/k3ng/k3ng_cw_keyer/pull/59 - HARDWARE_K5BCQ added.  (Thanks, woodjrx)

    2019.04.27.03
      Merge of pull request 51 https://github.com/k3ng/k3ng_cw_keyer/pull/51 - Yaacwk dev (Thanks, federicobriata)

    2019.04.27.04
      Merge of pull request 60 https://github.com/k3ng/k3ng_cw_keyer/pull/60 - Add support for generic PCF8574 based I2C display (Thanks, W6IPA) 

    2019.04.27.05
      Fixed bug with I2C displays and \+ memory macros with pauses in between prosigned characters (Thanks, Fred, VK2EFL)

    2019.04.28.01
      Implemented asynchronous EEPROM writes   

    2019.04.29.01
      Fixed bug introduced in 2019.04.27.05 with display of second prosign character (Thanks, Fred, VK2EFL)

    2019.05.03.01
      Merged pull request https://github.com/k3ng/k3ng_cw_keyer/pull/61  (Thanks, W6IPA) 
      Merged pull request https://github.com/k3ng/k3ng_cw_keyer/pull/62  (Thanks, W6IPA) 
      Merged pull request https://github.com/k3ng/k3ng_cw_keyer/pull/63  (Thanks, W6IPA) 
      New hardware profile: HARDWARE_MEGAKEYER  https://github.com/w6ipa/megakeyer    (Thanks, W6IPA) {needs documented}

    2019.05.03.02
      Added potentiometer_enable_pin {needs documented}
      Merged pull request https://github.com/k3ng/k3ng_cw_keyer/pull/64  (Thanks, W6IPA)

    2019.05.15.01
      Merged pull request https://github.com/k3ng/k3ng_cw_keyer/pull/65 (Thanks, federicobriata); yaacwk FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
      Merged pull request https://github.com/k3ng/k3ng_cw_keyer/pull/67 (Thanks, OK1CDJ); New hardware profile: HARDWARE_OPENCWKEYER_MK2 https://github.com/ok1cdj/OpenCWKeyerMK2
      Merged pull request https://github.com/k3ng/k3ng_cw_keyer/pull/66 (Thanks, woodjrx); Last update for K5BCQ
      
    2019.05.16.01
      Fixed issue with factory reset functionality and asynchronous EEPROM write feature (Thanks, Fred, VK2EFL)
      Relocated sidetone_hz_limit_low and sidetone_hz_limit_high setting from ino file to settings.h files (Thanks, Fred, VK2EFL) {needs documented}

    2019.05.17.01
      service_async_eeprom_write(): Changed EEPROM.write to EEPROM.update to lessen wear and tear on EEPROM and also reduce writing time.  (Each EEPROM.write = 3.3 mS)  
      
    2019.05.17.02
      OPTION_DIRECT_PADDLE_PIN_READS_UNO (Thanks, Fred, VK2EFL) {needs documented}
      OPTION_SAVE_MEMORY_NANOKEYER now does direct pin reads rather than digitalRead (Thanks, Fred, VK2EFL) 
      FEATURE_SD_CARD_SUPPORT - Rolled out SD card support to main keyer_features_and_options.h files {needs documented}

    2019.05.28.01
      FEATURE_WINKEY_EMULATION - fixed prosign lock up issue with Win-Test (Thanks, Bob, N6TV)  

    2019.05.29.01
      FEATURE_WINKEY_EMULATION - fixed issues with paddle echo (Thanks, Bob, N6TV) 
      Settings - winkey_paddle_echo_buffer_decode_time_factor changed to winkey_paddle_echo_buffer_decode_timing_factor
      Fixed keyer_pin_settings_nanokeyer_rev_*.h to include potentiometer_enable_pin (https://github.com/k3ng/k3ng_cw_keyer/issues/68) (Thanks, rificity)
      convert_cw_number_to_ascii() was returning exclamation and not comma (Thanks, W6IPA)
      FEATURE_AMERICAN_MORSE - fixed errant submitted change in send_char() (Thanks, Sverre, LA3ZA)

    2019.06.18.01
      Fixed bug with OPTION_SAVE_MEMORY_NANOKEYER and reading left (dit) paddle

  This code is currently maintained for and compiled with Arduino 1.8.x.  Your mileage may vary with other versions.

  ATTENTION: LIBRARY FILES MUST BE PUT IN LIBRARIES DIRECTORIES AND NOT THE INO SKETCH DIRECTORY !!!!

  FOR EXAMPLE:

    K3NG_PS2Keyboard.h, K3NG_PS2Keyboard.cpp ----->  \Arduino\Sketchbook\libraries\K3NG_PS2Keyboard\
    Goertz.h, Goertz.cpp ------------------------>   \Arduino\Sketchbook\libraries\Goertz\

  
  "Make good code and share it with friends."

*/

#define CODE_VERSION "2019.06.18.01"
#define eeprom_magic_number 35               // you can change this number to have the unit re-initialize EEPROM

#include <stdio.h>
#include "keyer_hardware.h"

#if defined(ARDUINO_SAM_DUE)  
  #include <SPI.h>
  #include <Wire.h>
  #define tone toneDUE
  #define noTone noToneDUE
#elif defined(ARDUINO_MAPLE_MINI)|| defined(ARDUINO_GENERIC_STM32F103C) || defined(__STM32F1__)
  #include <SPI.h>
  #include <Wire.h>
  #include <EEPROM.h> 
  #include "keyer_stm32duino.h" 
#elif defined(_BOARD_PIC32_PINGUINO_)
  #include <EEPROM.h>
#else
  #include <avr/pgmspace.h>
  #include <avr/wdt.h>
  #include <EEPROM.h>  
#endif //ARDUINO_SAM_DUE

#if defined(HARDWARE_OPENCWKEYER_MK2)
  #include "keyer_features_and_options_opencwkeyer_mk2.h"
#elif defined(HARDWARE_NANOKEYER_REV_B)
  #include "keyer_features_and_options_nanokeyer_rev_b.h"
#elif defined(HARDWARE_NANOKEYER_REV_D)
  #include "keyer_features_and_options_nanokeyer_rev_d.h"
#elif defined(HARDWARE_OPEN_INTERFACE)
  #include "keyer_features_and_options_open_interface.h"
#elif defined(HARDWARE_TINYKEYER)
  #include "keyer_features_and_options_tinykeyer.h"
#elif defined(HARDWARE_FK_10)
  #include "keyer_features_and_options_fk_10.h"  
#elif defined(HARDWARE_MAPLE_MINI)//sp5iou 20180328
  #include "keyer_features_and_options_maple_mini.h"
#elif defined(HARDWARE_GENERIC_STM32F103C)//sp5iou 20180329
  #include "keyer_features_and_options_generic_STM32F103C.h"
#elif defined(HARDWARE_MORTTY)
  #include "keyer_features_and_options_mortty.h"
#elif defined(HARDWARE_K5BCQ)
  #include "keyer_features_and_options_k5bcq.h"
#elif defined(HARDWARE_MEGAKEYER)
  #include "keyer_features_and_options_megakeyer.h"
#elif defined(HARDWARE_TEST_EVERYTHING)
  #include "keyer_features_and_options_test_everything.h"
#elif defined(HARDWARE_YAACWK)
  #include "keyer_features_and_options_yaacwk.h"
#elif defined(HARDWARE_TEST)
  #include "keyer_features_and_options_test.h"
#elif defined(HARDWARE_IZ3GME)
  #include "keyer_features_and_options_iz3gme.h"
#else
  #include "keyer_features_and_options.h"
#endif

#include "keyer.h"

#ifdef FEATURE_EEPROM_E24C1024
  #include <E24C1024.h>
  #define EEPROM EEPROM1024
#endif 

#include "keyer_dependencies.h"
#include "keyer_debug.h"

#if defined(HARDWARE_OPENCWKEYER_MK2)
  #include "keyer_pin_settings_opencwkeyer_mk2.h"
  #include "keyer_settings_opencwkeyer_mk2.h"
#elif defined(HARDWARE_NANOKEYER_REV_B)
  #include "keyer_pin_settings_nanokeyer_rev_b.h"
  #include "keyer_settings_nanokeyer_rev_b.h"
#elif defined(HARDWARE_NANOKEYER_REV_D)
  #include "keyer_pin_settings_nanokeyer_rev_d.h"
  #include "keyer_settings_nanokeyer_rev_d.h"
#elif defined(HARDWARE_OPEN_INTERFACE)
  #include "keyer_pin_settings_open_interface.h"
  #include "keyer_settings_open_interface.h"
#elif defined(HARDWARE_TINYKEYER)
  #include "keyer_pin_settings_tinykeyer.h"
  #include "keyer_settings_tinykeyer.h"
#elif defined(HARDWARE_FK_10)
  #include "keyer_pin_settings_fk_10.h"
  #include "keyer_settings_fk_10.h"
#elif defined(HARDWARE_MAPLE_MINI)
  #include "keyer_pin_settings_maple_mini.h"
  #include "keyer_settings_maple_mini.h"
#elif defined(HARDWARE_GENERIC_STM32F103C)
  #include "keyer_pin_settings_generic_STM32F103C.h"
  #include "keyer_settings_generic_STM32F103C.h"
#elif defined(HARDWARE_MORTTY)
  #include "keyer_pin_settings_mortty.h"
  #include "keyer_settings_mortty.h"  
#elif defined(HARDWARE_K5BCQ)
  #include "keyer_pin_settings_k5bcq.h"
  #include "keyer_settings_k5bcq.h"
#elif defined(HARDWARE_MEGAKEYER)
  #include "keyer_pin_settings_megakeyer.h"
  #include "keyer_settings_megakeyer.h"
#elif defined(HARDWARE_TEST_EVERYTHING)
  #include "keyer_pin_settings_test_everything.h"
  #include "keyer_settings_test_everything.h"
#elif defined(HARDWARE_YAACWK)
  #include "keyer_pin_settings_yaacwk.h"
  #include "keyer_settings_yaacwk.h"
#elif defined(HARDWARE_TEST)
  #include "keyer_pin_settings_test.h"
  #include "keyer_settings_test.h"
#elif defined(HARDWARE_IZ3GME)
  #include "keyer_pin_settings_iz3gme.h"
  #include "keyer_settings_iz3gme.h"
#else
  #include "keyer_pin_settings.h"
  #include "keyer_settings.h"
#endif

#if defined(FEATURE_SLEEP)
  #include <avr/sleep.h>  // It should be different library for ARM sp5iou
#endif 

#if defined(FEATURE_PS2_KEYBOARD)
  #include <K3NG_PS2Keyboard.h>
#endif

#if defined(FEATURE_LCD_4BIT) || defined(FEATURE_LCD1602_N07DH) || defined (FEATURE_LCD_8BIT) // works on 3.2V supply and logic, but do not work on every pins (SP5IOU)
  #include <LiquidCrystal.h>
  #include <Wire.h>
#endif

#if defined(FEATURE_LCD_ADAFRUIT_I2C) || defined(FEATURE_LCD_ADAFRUIT_BACKPACK) || defined(FEATURE_LCD_YDv1) || defined(FEATURE_LCD_SAINSMART_I2C) || defined(FEATURE_LCD_FABO_PCF8574) || defined(FEATURE_LCD_MATHERTEL_PCF8574)
  #include <Wire.h>
#endif

#if defined(FEATURE_LCD_YDv1)
  #include <LiquidCrystal_I2C.h>
#endif

#if defined(FEATURE_LCD_ADAFRUIT_I2C)
  #include <Adafruit_MCP23017.h>
  #include <Adafruit_RGBLCDShield.h>
#endif

#if defined(FEATURE_LCD_ADAFRUIT_BACKPACK)
  #include <Adafruit_LiquidCrystal.h>
#endif

#if defined(FEATURE_LCD_SAINSMART_I2C)
  #include <LiquidCrystal_I2C.h>
#endif //FEATURE_SAINSMART_I2C_LCD  

#if defined(FEATURE_LCD_FABO_PCF8574)
  #include <FaBoLCD_PCF8574.h>
#endif  

#if defined(FEATURE_LCD_MATHERTEL_PCF8574)
  #include <LiquidCrystal_PCF8574.h>
#endif

#if defined(FEATURE_LCD_HD44780)
  #include <Wire.h>
  #include <hd44780.h>
  #include <hd44780ioClass/hd44780_I2Cexp.h>
  #define WIRECLOCK 400000L
#endif

#if defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE)
 // #include <BasicTerm.h>
#endif

#if defined(FEATURE_CW_DECODER) && defined(OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR)
  #include <goertzel.h>
#endif

#if defined(FEATURE_ETHERNET)
#if !defined(ARDUINO_MAPLE_MINI) && !defined(ARDUINO_GENERIC_STM32F103C) //sp5iou 20180329
  #include <Ethernet.h>  // if this is not included, compilation fails even though all ethernet code is #ifdef'ed out
  #if defined(FEATURE_INTERNET_LINK)
    #include <EthernetUdp.h>
  #endif //FEATURE_INTERNET_LINK
#endif //!defined(ARDUINO_MAPLE_MINI) && !defined(ARDUINO_GENERIC_STM32F103C) //sp5iou 20180329  
#endif //FEATURE_ETHERNET


#if defined(FEATURE_USB_KEYBOARD) || defined(FEATURE_USB_MOUSE)  // note_usb_uncomment_lines
  // #include <hidboot.h>  // Arduino 1.6.x (and maybe 1.5.x) has issues with these three lines, moreover we noted that Arduino 1.8.6 it's not afected by an issue during USB Shield SPI init see https://github.com/felis/USB_Host_Shield_2.0/issues/390
  // #include <usbhub.h>   // Uncomment the three lines if you are using FEATURE_USB_KEYBOARD or FEATURE_USB_MOUSE
  // #include <Usb.h>      // Note: the most updated USB Library can be downloaded at https://github.com/felis/USB_Host_Shield_2.0
#endif

#if defined(FEATURE_CW_COMPUTER_KEYBOARD) 
  #include <Keyboard.h>  // Have a problem with Keyboard.h not found?  See https://github.com/k3ng/k3ng_cw_keyer/issues/35
                           // For some unknown reason this line uncommented in Arduino 1.8.1 <sometimes?> causes compilation error (sigh) 
#endif //defined(FEATURE_CW_COMPUTER_KEYBOARD)

#if defined(FEATURE_4x4_KEYPAD)|| defined (FEATURE_3x4_KEYPAD)
  #include <Keypad.h>
#endif

#if defined(FEATURE_SD_CARD_SUPPORT)
  #include <SPI.h>
  #include <SD.h>
#endif //FEATURE_SD_CARD_SUPPORT


// #if defined(FEATURE_SINEWAVE_SIDETONE)
//   #if defined(FEATURE_SINEWAVE_SIDETONE_USING_TIMER_1)
//     #include <TimerOne.h> 
//   #endif
//   #if defined(FEATURE_SINEWAVE_SIDETONE_USING_TIMER_3)
//     #include <TimerThree.h> 
//   #endif
//   #define tone sinetone
//   #define noTone nosineTone
// #endif //FEATURE_SINEWAVE_SIDETONE  

#define memory_area_start 113

// Variables and stuff
struct config_t {  // 111 bytes total
  
  uint8_t paddle_mode;                                                   
  uint8_t keyer_mode;            
  uint8_t sidetone_mode;
  uint8_t pot_activated;
  uint8_t length_wordspace;
  uint8_t autospace_active;
  uint8_t current_ptt_line;
  uint8_t current_tx;
  uint8_t weighting;
  uint8_t dit_buffer_off;
  uint8_t dah_buffer_off;
  uint8_t cmos_super_keyer_iambic_b_timing_percent;
  uint8_t cmos_super_keyer_iambic_b_timing_on;
  uint8_t link_receive_enabled;
  uint8_t paddle_interruption_quiet_time_element_lengths;
  uint8_t wordsworth_wordspace;
  uint8_t wordsworth_repetition;
  uint8_t cli_mode;
  uint8_t ptt_buffer_hold_active;
    // 19 bytes

  unsigned int wpm;
  unsigned int hz_sidetone;
  unsigned int dah_to_dit_ratio;
  unsigned int wpm_farnsworth;
  unsigned int memory_repeat_time;
  unsigned int wpm_command_mode;
  unsigned int link_receive_udp_port; 
    

  unsigned int wpm_ps2_usb_keyboard;
  unsigned int wpm_cli;
  unsigned int wpm_winkey;
    // 20 bytes 

  uint8_t ip[4];
  uint8_t gateway[4];  
  uint8_t subnet[4]; 
    // 12 bytes

  uint8_t link_send_ip[4][FEATURE_INTERNET_LINK_MAX_LINKS];   // FEATURE_INTERNET_LINK_MAX_LINKS = 2
  uint8_t link_send_enabled[FEATURE_INTERNET_LINK_MAX_LINKS];
  unsigned int link_send_udp_port[FEATURE_INTERNET_LINK_MAX_LINKS];
    // 14 bytes

  unsigned int ptt_lead_time[6];
  unsigned int ptt_tail_time[6];
  unsigned int ptt_active_to_sequencer_active_time[5];
  unsigned int ptt_inactive_to_sequencer_inactive_time[5];
    // 44 bytes

  int sidetone_volume;
    // 2 bytes

} configuration;



byte sending_mode = UNDEFINED_SENDING;
byte command_mode_disable_tx = 0;
byte current_tx_key_line = tx_key_line_1;
byte manual_ptt_invoke = 0;
byte qrss_dit_length = initial_qrss_dit_length;
byte keyer_machine_mode = KEYER_NORMAL;   // KEYER_NORMAL, BEACON, KEYER_COMMAND_MODE
byte char_send_mode = 0; // CW, HELL, AMERICAN_MORSE
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
#if defined(FEATURE_COMMAND_LINE_INTERFACE) || defined(FEATURE_PS2_KEYBOARD) || defined(FEATURE_MEMORY_MACROS) || defined(FEATURE_MEMORIES) || defined(FEATURE_COMMAND_BUTTONS)
  unsigned int serial_number = 1;
#endif
byte pause_sending_buffer = 0;
byte length_letterspace = default_length_letterspace;
byte keying_compensation = default_keying_compensation;
byte first_extension_time = default_first_extension_time;
byte ultimatic_mode = ULTIMATIC_NORMAL;
float ptt_hang_time_wordspace_units = default_ptt_hang_time_wordspace_units;
byte last_sending_mode = MANUAL_SENDING;
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
  #if defined(OPTION_ENABLE_SERIAL_PORT_CHECKING_WHILE_SENDING_CW_MAY_CAUSE_PROBLEMS)
    byte loop_element_lengths_breakout_flag;
    byte dump_current_character_flag;
  #endif
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
  byte winkey_speed_state = WINKEY_UNBUFFERED_SPEED;
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
  byte winkey_session_ptt_tail = 0;
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
      {0x6, 0x0, 0x4,  0x0}, {0x6, 0x5, 0x0, 0x20},
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

#if defined(FEATURE_LCD_8BIT)
  LiquidCrystal lcd(lcd_rs, lcd_enable, lcd_d0, lcd_d1, lcd_d2, lcd_d3, lcd_d4, lcd_d5, lcd_d6, lcd_d7);
#endif  

#if defined(FEATURE_LCD_ADAFRUIT_I2C)
  Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();
#endif

#if defined(FEATURE_LCD_ADAFRUIT_BACKPACK)
  Adafruit_LiquidCrystal lcd(0);
#endif

#if defined(FEATURE_LCD_SAINSMART_I2C)
  // #define I2C_ADDR      0x27
  // #define BACKLIGHT_PIN 3
  // #define En_pin        2
  // #define Rw_pin        1
  // #define Rs_pin        0
  // #define D4_pin        4
  // #define D5_pin        5
  // #define D6_pin        6
  // #define D7_pin        7
  // LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin, BACKLIGHT_PIN, POSITIVE);  
  LiquidCrystal_I2C lcd(0x27,20,4);
#endif //FEATURE_SAINSMART_I2C_LCD    

#if defined(FEATURE_LCD_YDv1)
  //LiquidCrystal_I2C lcd(0x38);
  LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // for FEATURE_LCD_YDv1; set the LCD I2C address needed for LCM1602 IC V1
#endif

#if defined(FEATURE_LCD_FABO_PCF8574)
  FaBoLCD_PCF8574 lcd;
#endif  

#if defined(FEATURE_LCD_MATHERTEL_PCF8574)
  LiquidCrystal_PCF8574 lcd(lcd_i2c_address_mathertel_PCF8574);
#endif

#if defined(FEATURE_LCD_HD44780)
  hd44780_I2Cexp lcd;
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

#if defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE)
  //BasicTerm term(&Serial);
#endif

PRIMARY_SERIAL_CLS * primary_serial_port;

#if defined(FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT)
  SECONDARY_SERIAL_CLS * secondary_serial_port;
#endif

PRIMARY_SERIAL_CLS * debug_serial_port;

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


#if defined(OPTION_WINKEY_SEND_BREAKIN_STATUS_BYTE) && defined(FEATURE_WINKEY_EMULATION)
  byte send_winkey_breakin_byte_flag = 0;
#endif //defined(OPTION_WINKEY_SEND_BREAKIN_STATUS_BYTE) && defined(FEATURE_WINKEY_EMULATION) 

#if defined(FEATURE_ETHERNET)
  uint8_t default_ip[] = FEATURE_ETHERNET_IP;                      // default IP address ("192.168.1.178")
  uint8_t default_gateway[] = FEATURE_ETHERNET_GATEWAY;                   // default gateway
  uint8_t default_subnet[] = FEATURE_ETHERNET_SUBNET_MASK;                  // default subnet mask
  uint8_t mac[] = FEATURE_ETHERNET_MAC;   // default physical mac address
  uint8_t restart_networking = 0;

  #if defined(FEATURE_WEB_SERVER)
    #define MAX_WEB_REQUEST 512  
    String web_server_incoming_string;
    uint8_t valid_request = 0;
    EthernetServer server(FEATURE_ETHERNET_WEB_LISTENER_PORT);                             // default server port 
    #define MAX_PARSE_RESULTS 32
    struct parse_get_result_t{
      String parameter;
      String value_string;
      long value_long;
    };
    struct parse_get_result_t parse_get_results[MAX_PARSE_RESULTS];
    int parse_get_results_index = 0;
    unsigned long web_control_tx_key_time = 0;
  #endif //FEATURE_WEB_SERVER

  #if defined(FEATURE_UDP)
    unsigned int udp_listener_port = FEATURE_INTERNET_LINK_DEFAULT_RCV_UDP_PORT;
    EthernetUDP Udp;
    #if defined(FEATURE_INTERNET_LINK)
      uint8_t udp_send_buffer[FEATURE_UDP_SEND_BUFFER_SIZE];
      uint8_t udp_send_buffer_bytes = 0;
      uint8_t udp_receive_packet_buffer[FEATURE_UDP_RECEIVE_BUFFER_SIZE];
      uint8_t udp_receive_packet_buffer_bytes = 0;     
    #endif //FEATURE_INTERNET_LINK
  #endif
#endif //FEATURE_ETHERNET

unsigned long automatic_sending_interruption_time = 0;     

#ifdef FEATURE_4x4_KEYPAD
  // Define the Keymap for 4x4 matrix keypad
  char keys[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  };
#endif

#ifdef FEATURE_3x4_KEYPAD
  // Define the Keymap for 3x4 matrix keypad
  char keys[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
  };
#endif

// Setup for 4x4 matrix keypad
#ifdef FEATURE_4x4_KEYPAD
  byte rowPins[KEYPAD_ROWS] = {Row3,Row2,Row1,Row0}; //Arduino Mega Pins: 30,31,32,33---Keypad Pins 5,6,7,8
  byte colPins[KEYPAD_COLS] = {Col3,Col2,Col1,Col0}; //Arduino Mega Pins: 34,35,36,37---Keypad Pins 1,2,3,4
#endif

#ifdef FEATURE_3x4_KEYPAD
  byte rowPins [KEYPAD_ROWS] = {Row3,Row2,Row1,Row0}; //Arduino Mega Pins: 30,31,32,33--Keypad Pins 4,6,7,2
  byte colPins [KEYPAD_COLS] = {Col2,Col1,Col0}; //Arduino Mega Pins: 34,35,36-----Keypad Pins 5,1,3
#endif

#if defined(FEATURE_4x4_KEYPAD) || defined(FEATURE_3x4_KEYPAD)
  Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS);
#endif

unsigned long millis_rollover = 0;

#if defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE)
  byte check_serial_override = 0;
  #if defined(OPTION_WORDSWORTH_CZECH)
    #include "keyer_training_text_czech.h"
  #elif defined(OPTION_WORDSWORTH_DEUTCSH)
    #include "keyer_training_text_deutsch.h"
  #elif defined(OPTION_WORDSWORTH_NORSK)
    #include "keyer_training_text_norsk.h"  
  #else
    #include "keyer_training_text_english.h"
  #endif

  #include "keyer_callsign_prefixes.h"
#endif


#ifdef FEATURE_CLOCK
  unsigned long clock_years = 0;
  unsigned long clock_months = 0;
  unsigned long clock_days = 0;
  unsigned long clock_hours = 0;
  unsigned long clock_minutes = 0;
  unsigned long clock_seconds = 0;
  long local_clock_years = 0;
  long local_clock_months = 0;
  long local_clock_days = 0;
  long local_clock_hours = 0;
  long local_clock_minutes = 0;
  long local_clock_seconds = 0;
  int clock_year_set = 2017;
  byte clock_month_set = 1;
  byte clock_day_set = 1;
  byte clock_sec_set = 0;
  unsigned long clock_hour_set = 0;
  unsigned long clock_min_set = 0;
  unsigned long millis_at_last_calibration = 0;
#endif // FEATURE_CLOCK

#if defined(FEATURE_SD_CARD_SUPPORT)
  uint8_t sd_card_state = SD_CARD_UNINITIALIZED;
  File sdfile;
  File sdlogfile;
  uint8_t sd_card_log_state = SD_CARD_LOG_NOT_OPEN;
#endif //FEATURE_SD_CARD_SUPPORT  

#ifdef FEATURE_SEQUENCER
  unsigned long sequencer_ptt_inactive_time = 0;
  byte sequencer_1_active = 0;
  byte sequencer_2_active = 0;
  byte sequencer_3_active = 0;
  byte sequencer_4_active = 0;
  byte sequencer_5_active = 0;
#endif  


// #if defined(FEATURE_SINEWAVE_SIDETONE)  //DL2DBG contributed
//   const float pi = 3.14159 ;
//   const float T = 100 ;    // sample time in microseconds
//         float freq = 800 ;  // frequency of tone in hertz
//         float omega = 2*pi*freq ;
//         float A = 490 ;  // amplitude
        
//   // next line initializes oscillation with amplitude A
//   float  a[]={0.0, A*sin(omega*T/1000000.0),0.0};
//   // c1 is the difference equation coefficient
//   float c1 = (8.0 - 2.0*pow(omega*T/1000000.0,2))/(4.0+pow(omega*T/1000000.0,2));
// #endif //FEATURE_SINEWAVE_SIDETONE

byte async_eeprom_write = 0;

/*---------------------------------------------------------------------------------------------------------


 “What we do for ourselves dies with us. What we do for others and the world remains and is immortal.” 

― Albert Pike


---------------------------------------------------------------------------------------------------------*/

void setup()
{

  initialize_pins();
  // initialize_serial_ports();        // Goody - this is available for testing startup issues
  // initialize_debug_startup();       // Goody - this is available for testing startup issues
  // debug_blink();                    // Goody - this is available for testing startup issues
  initialize_keyer_state();
  initialize_potentiometer();
  initialize_rotary_encoder();
  initialize_default_modes();
  initialize_watchdog();
  initialize_ethernet_variables();
  check_eeprom_for_initialization();
  check_for_beacon_mode();
  check_for_debug_modes();
  initialize_analog_button_array();
  initialize_serial_ports();

  // #if defined(FEATURE_SINEWAVE_SIDETONE)  // UNDER DEVELOPMENT
  //   initialize_tonsin();
  // #endif  
  
  initialize_ps2_keyboard();
  initialize_usb();
  initialize_cw_keyboard();
  initialize_display();
  initialize_ethernet();
  initialize_udp();
  initialize_web_server();
  initialize_sd_card();  
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
          add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
          add_to_send_buffer(0);
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

    #if defined(OPTION_WINKEY_SEND_BREAKIN_STATUS_BYTE) && defined(FEATURE_WINKEY_EMULATION)
      service_winkey_breakin();
    #endif //defined(OPTION_WINKEY_SEND_BREAKIN_STATUS_BYTE) && defined(FEATURE_WINKEY_EMULATION)    

    #if defined(FEATURE_ETHERNET)
      check_for_network_restart();
      #if defined(FEATURE_WEB_SERVER)
        service_web_server();
      #endif
      #if defined(FEATURE_INTERNET_LINK)
        service_udp_send_buffer();
        service_udp_receive();
        service_internet_link_udp_receive_buffer();
      #endif
    #endif  

    #ifdef FEATURE_SIDETONE_SWITCH
      check_sidetone_switch();
    #endif //FEATURE_SIDETONE_SWITCH

    #if defined(FEATURE_4x4_KEYPAD) || defined(FEATURE_3x4_KEYPAD)
      service_keypad();
    #endif


    #ifdef FEATURE_SD_CARD_SUPPORT
      service_sd_card();    
    #endif

    #ifdef FEATURE_SEQUENCER
      check_sequencer_tail_time();
    #endif  

    service_async_eeprom_write();
    
  }

  service_millis_rollover();

  
}

// Subroutines --------------------------------------------------------------------------------------------


// Are you a radio artisan ?


byte service_tx_inhibit_and_pause(){

  byte return_code = 0;
  static byte pause_sending_buffer_active = 0;

  if (tx_inhibit_pin){
    if ((digitalRead(tx_inhibit_pin) == tx_inhibit_pin_active_state)){
      dit_buffer = 0;
      dah_buffer = 0; 
      return_code = 1;
      if (send_buffer_bytes){
        clear_send_buffer();
        send_buffer_status = SERIAL_SEND_BUFFER_NORMAL;
        #ifdef FEATURE_MEMORIES
          play_memory_prempt = 1;
          repeat_memory = 255;
        #endif
        #ifdef FEATURE_WINKEY_EMULATION
          if (winkey_sending && winkey_host_open) {
            winkey_port_write(0xc2|winkey_sending|winkey_xoff,0); // 0xc2 - BREAKIN bit set high
            winkey_interrupted = 1;
          }
        #endif
      }
    }
  }

  if (tx_pause_pin){
    if ((digitalRead(tx_pause_pin) == tx_pause_pin_active_state)){
      dit_buffer = 0;
      dah_buffer = 0; 
      return_code = 1;
      if (!pause_sending_buffer_active){
        pause_sending_buffer = 1;
        pause_sending_buffer_active = 1;
        delay(10);
      }
    } else {
      if (pause_sending_buffer_active){
        pause_sending_buffer = 0;
        pause_sending_buffer_active = 0;
        delay(10);
      } 
    }

    
  }  

  return return_code;

}

//-------------------------------------------------------------------------------------------------------


#if defined(FEATURE_COMPETITION_COMPRESSION_DETECTION)
  void service_competition_compression_detection(){


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

#if defined(FEATURE_4x4_KEYPAD) || defined(FEATURE_3x4_KEYPAD)
void service_keypad(){

  // Code contributed by Jack, W0XR

  char key = kpd.getKey();

  if(key){ // Check for a valid key.

    #if defined(DEBUG_KEYPAD_SERIAL)
      debug_serial_port->print("service_keypad: key:");
      debug_serial_port->println(key);
    #endif

    switch(key){
      case '1':
        add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
        add_to_send_buffer(mem1);
        //play_memory(mem1); //MEMORY 1
        break;
      case '2':
        add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
        add_to_send_buffer(mem2);      
        //play_memory(mem2); //MEMORY 2
        break;
      case '3':
        add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
        add_to_send_buffer(mem3);      
        //play_memory(mem3); //MEMORY 3
        break;
      case '4':
        add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
        add_to_send_buffer(mem4);      
        //play_memory(mem4); //MEMORY 4
        break;
      case '5':
        add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
        add_to_send_buffer(mem5);      
        //play_memory(mem5); //MEMORY 5
        break;
      case '6':
        add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
        add_to_send_buffer(mem6);      
        //play_memory(mem6); //MEMORY 6
        break;
      case '7':
        add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
        add_to_send_buffer(mem7);      
        //play_memory(mem7); //MEMORY 7
        break;
      case '8':
        add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
        add_to_send_buffer(mem8);      
        //play_memory(mem8); //MEMORY 8
        break;
      case '9':
        add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
        add_to_send_buffer(mem9);      
        //play_memory(mem9); //MEMORY 9
        break;
      case '0':
        add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
        add_to_send_buffer(mem10);      
        //play_memory(mem10); //MEMORY 10
        break;
      case '#':
        beep_boop();
        break;
      case '*':
        beep_boop();
        break;
      case 'A':
        beep_boop();
        break;
      case 'B':
        beep_boop();
        break;
      case 'C':
        command_mode();
        break;
      case 'D':
        beep_boop();
        break;
    }

  } //if(key)

} // service_keypad()
#endif //defined(FEATURE_4x4_KEYPAD) || defined(FEATURE_3x4_KEYPAD)

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_STRAIGHT_KEY
  long service_straight_key(){

    static byte last_straight_key_state = 0;

    if (digitalRead(pin_straight_key) == STRAIGHT_KEY_ACTIVE_STATE){
      if (!last_straight_key_state){
        sending_mode = MANUAL_SENDING;
        tx_and_sidetone_key(1);
        last_straight_key_state = 1;


        #ifdef FEATURE_MEMORIES
          clear_send_buffer();
          repeat_memory = 255;
        #endif

      }
    } else {
      if (last_straight_key_state){
        sending_mode = MANUAL_SENDING;
        tx_and_sidetone_key(0);
        last_straight_key_state = 0;
      }
    }


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


      #if defined(OPTION_PROSIGN_SUPPORT)
        byte cw_ascii_temp = convert_cw_number_to_ascii(decode_character);
        static char * prosign_char = (char*)"";

        if ((cw_ascii_temp > PROSIGN_START) && (cw_ascii_temp < PROSIGN_END)){  // if we have a prosign code, convert it to chars
          prosign_char = convert_prosign(cw_ascii_temp);
          cw_ascii_temp = 0;
        }

        #if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && defined(FEATURE_STRAIGHT_KEY_ECHO)
          if (cli_straight_key_echo){
            if (cw_ascii_temp){
              primary_serial_port->write(cw_ascii_temp);
            } else {
              primary_serial_port->write(prosign_char[0]);
              primary_serial_port->write(prosign_char[1]);
            }
            #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
              if (cw_ascii_temp){
                secondary_serial_port->write(cw_ascii_temp);
              } else {
                secondary_serial_port->write(prosign_char[0]);
                secondary_serial_port->write(prosign_char[1]);
              }
            #endif
            screen_column++;
          }
        #endif //defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)

        #if defined(FEATURE_DISPLAY) && defined(FEATURE_STRAIGHT_KEY_ECHO)
          if (cli_straight_key_echo){
            if (cw_ascii_temp){
              display_scroll_print_char(cw_ascii_temp);
            } else {
              display_scroll_print_char(prosign_char[0]);
              display_scroll_print_char(prosign_char[1]);
            }
          }
        #endif //FEATURE_DISPLAY        


      #else //OPTION_PROSIGN_SUPPORT  

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

      #endif //OPTION_PROSIGN_SUPPORT
 



      #if defined(FEATURE_CW_COMPUTER_KEYBOARD)       
        switch (decode_character){
          case 111111:
          case 1111111:
          case 11111111:
          case 111111111:
            Keyboard.write(KEY_BACKSPACE); // backspace
            cw_keyboard_no_space = 1;
            break;
          case 222222:
          case 2222222:
          case 22222222:
          case 222222222:
            Keyboard.write(32); // space
            no_space = 1;
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

#ifdef ARDUINO_SAM_DUE

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
#endif
/*
//sp5iou 2018/0329 This is already in stm32 SDK standard library
#elif defined(ARDUINO_MAPLE_MINI) || defined(ARDUINO_GENERIC_STM32F103C) //HARDWARE_ARDUINO_DUE
//This code from http://www.stm32duino.com/viewtopic.php?t=496
     
///////////////////////////////////////////////////////////////////////
//
// tone(pin,frequency[,duration]) generate a tone on a given pin
//
// noTone(pin)                    switch of the tone on the pin
//
///////////////////////////////////////////////////////////////////////

//#include "Arduino.h"
//#include <HardwareTimer.h>

#ifndef TONE_TIMER
  #define TONE_TIMER 2
#endif

HardwareTimer tone_timer(TONE_TIMER);

bool tone_state = true;             // last pin state for toggling
short tone_pin = -1;                // pin for outputting sound
short tone_freq = 444;              // tone frequency (0=pause)
unsigned tone_micros = 500000/444;  // tone have wave time in usec
int tone_counts = 0;                // tone duration in units of half waves

// timer hander for tone with no duration specified, 
// will keep going until noTone() is called
void tone_handler_1(void) {
  tone_state = !tone_state;
  digitalWrite(tone_pin,tone_state);
}

// timer hander for tone with a specified duration,
// will stop automatically when duration time is up.
void tone_handler_2(void) {   // check duration
  if(tone_freq>0){
   tone_state = !tone_state;
   digitalWrite(tone_pin,tone_state);
  }
  if(!--tone_counts){
   tone_timer.pause();
   pinMode(tone_pin, INPUT);
  }
}

//  play a tone on given pin with given frequency and optional duration in msec
void tone(uint8_t pin, unsigned short freq, unsigned duration = 0) {
  tone_pin = pin;
  tone_freq = freq;
  tone_micros = 500000/(freq>0?freq:1000);
  tone_counts = 0;

  tone_timer.pause();

  if(freq >= 0){
    if(duration > 0)tone_counts = ((long)duration)*1000/tone_micros;
    pinMode(tone_pin, OUTPUT);

    // set timer to half period in microseconds
    tone_timer.setPeriod(tone_micros);

    // Set up an interrupt on channel 1
    tone_timer.setChannel1Mode(TIMER_OUTPUT_COMPARE);
    tone_timer.setCompare(TIMER_CH1, 1);  // Interrupt 1 count after each update
    tone_timer.attachCompare1Interrupt(tone_counts?tone_handler_2:tone_handler_1);

    // Refresh the tone timer
    tone_timer.refresh();

    // Start the timer counting
    tone_timer.resume();
  } else {
    pinMode(tone_pin, INPUT);
  }
}

// disable tone on specified pin, if any
void noTone(uint8_t pin){
  tone(pin,-1);
}


#endif //ARDUINO_MAPLE_MINI / ARDUINO_SAM_DUE
*/

//-------------------------------------------------------------------------------------------------------

/*   Sleep code prior to 2016-01-18
#ifdef FEATURE_SLEEP
void wakeup() {
  detachInterrupt(0);
}
#endif //FEATURE_SLEEP
*/

#ifdef FEATURE_SLEEP     // Code contributed by Graeme, ZL2APV 2016-01-18
void wakeup() {
  sleep_disable();
  detachInterrupt (0);
}  // end of wakeup

ISR (PCINT1_vect)
  {
  PCICR = 0;  // cancel pin change interrupts
  sleep_disable();
  } // end of ISR (PCINT1_vect)

ISR (PCINT2_vect)
  {
  PCICR = 0;  // turn off all pin change interrupt ports
  sleep_disable();
  } // end of ISR (PCINT2_vect)
#endif //FEATURE_SLEEP

//-------------------------------------------------------------------------------------------------------
/*  Sleep code prior to 2016-01-18
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
*/


#ifdef FEATURE_SLEEP   // Code contributed by Graeme, ZL2APV  2016-01-18
void check_sleep(){

  if ((millis() - last_activity_time) > ((unsigned long)go_to_sleep_inactivity_time*60000)){

    if (config_dirty) {  // force a configuration write to EEPROM if the config is dirty
      last_config_write = 0;
      check_for_dirty_configuration();
    }

    byte old_ADCSRA = ADCSRA;
    // disable ADC to save power
    ADCSRA = 0;

    set_sleep_mode (SLEEP_MODE_PWR_DOWN);
    sleep_enable();

    // Do not interrupt before we go to sleep, or the ISR will detach interrupts and we won't wake.
    noInterrupts ();

    // will be called when pin D2, D5 or A1 goes low
    attachInterrupt(0, wakeup, FALLING);
    EIFR = bit(INTF0);  // clear flag for interrupt 0
    PCIFR = 0; // Clear all pin change flags
    PCICR  = 0b00000110;    //Turn on ports C and D only
    PCMSK2 = bit(PCINT21);  //Turn on pin D5
    PCMSK1 = bit(PCINT9);   //Turn on pin A1

    // turn off brown-out enable in software
    // BODS must be set to one and BODSE must be set to zero within four clock cycles
    #if !defined(__AVR_ATmega2560__)
      MCUCR = bit (BODS) | bit (BODSE);
      // The BODS bit is automatically cleared after three clock cycles
      MCUCR = bit (BODS);
    #endif

    #ifdef DEBUG_SLEEP
      debug_serial_port->println(F("check_sleep: entering sleep"));
      delay(1000);
    #endif //DEBUG_SLEEP

    if (keyer_awake){
      digitalWrite(keyer_awake,KEYER_AWAKE_PIN_ASLEEP_STATE);
    }

    interrupts();
    sleep_cpu();

    // shhhhh! we are asleep here !!

    // An interrupt on digital 2 will call the wake() interrupt service routine
    // and then return us to here while a change on D5 or A1 will vector to their
    // interrupt handler and also return to here.

    detachInterrupt (0);
    PCICR  = 0;    //Turn off all ports
    PCMSK2 = 0;    //Turn off pin D5
    PCMSK1 = 0;    //Turn off pin A1

    ADCSRA = old_ADCSRA;   // re-enable ADC conversion

    if (keyer_awake){
      digitalWrite(keyer_awake,KEYER_AWAKE_PIN_AWAKE_STATE);
    }

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
  switch (byte(charin)){
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
  lcd.noCursor();//sp5iou 20180328
 lcd_status = LCD_CLEAR;

}
#endif
//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_DISPLAY
void lcd_center_print_timed(String lcd_print_string, byte row_number, unsigned int duration)
{
  lcd.noCursor();//sp5iou 20180328
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
  lcd.noCursor();//sp5iou 20180328
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

  //if ((config_dirty) && ((millis()-last_config_write)>30000) && (!send_buffer_bytes) && (!ptt_line_activated)) {
  if ((config_dirty) && ((millis()-last_config_write)>eeprom_write_time_ms) && (!send_buffer_bytes) && (!ptt_line_activated) && (!dit_buffer) && (!dah_buffer) && (!async_eeprom_write) && (paddle_pin_read(paddle_left) == HIGH)  && (paddle_pin_read(paddle_right) == HIGH) ) {
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
      if (LCD_COLUMNS < 9){
        lcd_center_print_timed("RptMem" + String(memory_number+1), 0, default_display_msg_delay); 
      } else {
        lcd_center_print_timed("Repeat Memory " + String(memory_number+1), 0, default_display_msg_delay); 
      }
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
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("DfltRtio", 0, default_display_msg_delay);
              } else {
                lcd_center_print_timed("Default ratio", 0, default_display_msg_delay);
              }
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

        case PS2_DELETE : if (send_buffer_bytes) { send_buffer_bytes--; } break;
        case PS2_ESC :  // clear the serial send buffer and a bunch of other stuff
          if (manual_ptt_invoke) {
            manual_ptt_invoke = 0;
            ptt_unkey();
          }
          if (keyboard_tune_on) {
            sending_mode = MANUAL_SENDING;
            tx_and_sidetone_key(0);
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
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("SN " + String(serial_number), 0, default_display_msg_delay);
              } else {
                lcd_center_print_timed("Serial: " + String(serial_number), 0, default_display_msg_delay);
              }
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

        case PS2_C_CTRL :
          configuration.keyer_mode = SINGLE_PADDLE;
          #ifdef FEATURE_DISPLAY
            if (LCD_COLUMNS < 9){
              lcd_center_print_timed("SnglePdl", 0, default_display_msg_delay);
            } else {
              lcd_center_print_timed("Single Paddle", 0, default_display_msg_delay);
            }
          #endif          
          config_dirty = 1;
          break;

        case PS2_D_CTRL :
          configuration.keyer_mode = ULTIMATIC;
          #ifdef FEATURE_DISPLAY
            if (LCD_COLUMNS < 9){
              lcd_center_print_timed("Ultimatc", 0, default_display_msg_delay);
            } else {
              lcd_center_print_timed("Ultimatic", 0, default_display_msg_delay);
            }          
          #endif        
          config_dirty = 1;
          break;

        #ifndef OPTION_SAVE_MEMORY_NANOKEYER
          case PS2_E_CTRL :
            #ifdef FEATURE_DISPLAY
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("EnterSN", 0, default_display_msg_delay);
              } else {
                lcd_center_print_timed("Enter Serial #", 0, default_display_msg_delay);
              }            
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
          if (key_tx && keyer_machine_mode != KEYER_COMMAND_MODE) { //Added check that keyer is NOT in command mode or keyer might be enabled for paddle commands (WD9DMP)
            key_tx = 0;
            #ifdef FEATURE_DISPLAY
              lcd_center_print_timed("TX off", 0, default_display_msg_delay);
            #endif
            
          } else if (!key_tx && keyer_machine_mode != KEYER_COMMAND_MODE) { //Added check that keyer is NOT in command mode or keyer might be enabled for paddle commands (WD9DMP)
            key_tx = 1;
            #ifdef FEATURE_DISPLAY
              lcd_center_print_timed("TX on", 0, default_display_msg_delay);
            #endif      
          }
          break;

        #ifdef FEATURE_FARNSWORTH
          case PS2_M_CTRL:         
            #ifdef FEATURE_DISPLAY
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("Frnswrth", 0, default_display_msg_delay);
              } else {
                lcd_center_print_timed("Farnsworth WPM", 0, default_display_msg_delay);
              }
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
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("Pdl Rev", 0, default_display_msg_delay);
              } else {
                lcd_center_print_timed("Paddle Reverse", 0, default_display_msg_delay);
              }
            #endif
          } else {
            configuration.paddle_mode = PADDLE_NORMAL;
            #ifdef FEATURE_DISPLAY
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("Pdl Norm", 0, default_display_msg_delay);
              } else {
                lcd_center_print_timed("Paddle Normal", 0, default_display_msg_delay);
              }      
            #endif      
          }
          config_dirty = 1;
          break;

        case PS2_O_CTRL : // CTRL-O - cycle through sidetone modes on, paddle only and off - New code Marc-Andre, VE2EVN
          if (configuration.sidetone_mode == SIDETONE_PADDLE_ONLY) {
            configuration.sidetone_mode = SIDETONE_OFF;
            boop();      
            #ifdef FEATURE_DISPLAY
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("ST Off", 0, default_display_msg_delay);
              } else {
                lcd_center_print_timed("Sidetone Off", 0, default_display_msg_delay);
              }
            #endif
          } else if (configuration.sidetone_mode == SIDETONE_ON) {
            configuration.sidetone_mode = SIDETONE_PADDLE_ONLY;
            beep();
            delay(200);
            beep();
            #ifdef FEATURE_DISPLAY
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("ST Pdl O", 0, default_display_msg_delay);
              }            
              if (LCD_COLUMNS > 19){
                lcd_center_print_timed("Sidetone Paddle Only", 0, default_display_msg_delay);
              } else {
                lcd_center_print_timed("Sidetone", 0, default_display_msg_delay);
                lcd_center_print_timed("Paddle Only", 1, default_display_msg_delay);
              }
            #endif
          } else {
            #ifdef FEATURE_DISPLAY
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("ST On", 0, default_display_msg_delay);
              } else {            
                lcd_center_print_timed("Sidetone On", 0, default_display_msg_delay);
              }
            #endif      
            configuration.sidetone_mode = SIDETONE_ON;
            beep();
          }
          config_dirty = 1;
         break;

        
        #if defined(FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING)
          case PS2_S_CTRL :
            if (configuration.cmos_super_keyer_iambic_b_timing_on){
              configuration.cmos_super_keyer_iambic_b_timing_on = 0;
              #ifdef FEATURE_DISPLAY
                lcd_center_print_timed("CMOS Superkeyer Off", 0, default_display_msg_delay);
              #endif      
            } else {
              #ifdef FEATURE_DISPLAY
                lcd_center_print_timed("CMOS Superkeyer On", 0, default_display_msg_delay);
              #endif      
              configuration.cmos_super_keyer_iambic_b_timing_on = 1;
            }
            config_dirty = 1;
            break;
        #endif //FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING

        case PS2_T_CTRL :
          #ifdef FEATURE_MEMORIES
            repeat_memory = 255;
          #endif
          if (keyboard_tune_on) {
            sending_mode = MANUAL_SENDING;
            tx_and_sidetone_key(0);
            keyboard_tune_on = 0;
            #ifdef FEATURE_DISPLAY
              lcd_status = LCD_REVERT;
            #endif // FEATURE_DISPLAY
          } else {
            #ifdef FEATURE_DISPLAY
              lcd_center_print_timed("Tune", 0, default_display_msg_delay);
            #endif      
            sending_mode = MANUAL_SENDING;
            tx_and_sidetone_key(1);
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
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("PTTInvk", 0, default_display_msg_delay);
              } else {
                lcd_center_print_timed("PTT Invoke", 0, default_display_msg_delay);
              }
            #endif      
            manual_ptt_invoke = 1;
            ptt_key();
          }
          break;

        case PS2_W_CTRL :
          #ifdef FEATURE_DISPLAY
            if (LCD_COLUMNS < 9){
              lcd_center_print_timed("WPM Adj", 0, default_display_msg_delay);
            } else {
              lcd_center_print_timed("WPM Adjust", 0, default_display_msg_delay);
            }        
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
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("AutoSOff", 0, default_display_msg_delay);
              } else {
                lcd_center_print_timed("Autospace Off", 0, default_display_msg_delay);
              }
            #endif                                  
          } else {
            configuration.autospace_active = 1;
            config_dirty = 1;
            #ifdef FEATURE_DISPLAY
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("AutoSpOn", 0, default_display_msg_delay);
              } else {
                lcd_center_print_timed("Autospace On", 0, default_display_msg_delay);
              }            
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
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("DfltRtio", 0, default_display_msg_delay);
              } else {
                lcd_center_print_timed("Default ratio", 0, default_display_msg_delay);
              }
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

        case PS2_DELETE : if (send_buffer_bytes) { send_buffer_bytes--; } break;
        case PS2_ESC :  // clear the serial send buffer and a bunch of other stuff
          if (manual_ptt_invoke) {
            manual_ptt_invoke = 0;
            ptt_unkey();
          }
          if (keyboard_tune_on) {
            sending_mode = MANUAL_SENDING;
            tx_and_sidetone_key(0);
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
            if (LCD_COLUMNS < 9){
              lcd_center_print_timed("SN " + String(serial_number), 0, default_display_msg_delay);
            } else {
              lcd_center_print_timed("Serial: " + String(serial_number), 0, default_display_msg_delay);
            }
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

        case PS2_C_CTRL :
          configuration.keyer_mode = SINGLE_PADDLE;
          #ifdef FEATURE_DISPLAY
            if (LCD_COLUMNS < 9){
              lcd_center_print_timed("Sngl Pdl", 0, default_display_msg_delay);
            } else {
              lcd_center_print_timed("Single Paddle", 0, default_display_msg_delay);
            }
          #endif          
          config_dirty = 1;
          break;

        case PS2_D_CTRL :
          configuration.keyer_mode = ULTIMATIC;
          #ifdef FEATURE_DISPLAY
            if (LCD_COLUMNS < 9){
              lcd_center_print_timed("Ultimatc", 0, default_display_msg_delay);
            } else {
              lcd_center_print_timed("Ultimatic", 0, default_display_msg_delay);
            }          
          #endif        
          config_dirty = 1;
          break;

        case PS2_E_CTRL :
          #ifdef FEATURE_DISPLAY
            if (LCD_COLUMNS < 9){
              lcd_center_print_timed("Enter SN", 0, default_display_msg_delay);
            } else {
              lcd_center_print_timed("Enter Serial #", 0, default_display_msg_delay);
            }            
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
          if (key_tx && keyer_machine_mode != KEYER_COMMAND_MODE) { //Added check that keyer is NOT in command mode or keyer might be enabled for paddle commands (WD9DMP-1)
            key_tx = 0;
            #ifdef FEATURE_DISPLAY
              lcd_center_print_timed("TX Off", 0, default_display_msg_delay);
            #endif
            
          } else if (!key_tx && keyer_machine_mode != KEYER_COMMAND_MODE) { //Added check that keyer is NOT in command mode or keyer might be enabled for paddle commands (WD9DMP-1)
            key_tx = 1;
            #ifdef FEATURE_DISPLAY
              lcd_center_print_timed("TX On", 0, default_display_msg_delay);
            #endif      
          }
          break;

        case PS2_M_CTRL:
          #ifdef FEATURE_FARNSWORTH
            #ifdef FEATURE_DISPLAY
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("Frnswrth", 0, default_display_msg_delay);
              } else {
                lcd_center_print_timed("Farnsworth WPM", 0, default_display_msg_delay);
              }        
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
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("Pdl Rev", 0, default_display_msg_delay);
              } else {
                lcd_center_print_timed("Paddle Reverse", 0, default_display_msg_delay);
              }                    
            #endif
          } else {
            configuration.paddle_mode = PADDLE_NORMAL;
            #ifdef FEATURE_DISPLAY
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("Pdl Norm", 0, default_display_msg_delay);
              } else {
                lcd_center_print_timed("Paddle Normal", 0, default_display_msg_delay);
              }                    
            #endif      
          }
          config_dirty = 1;
          break;

        case PS2_O_CTRL : // CTRL-O - cycle through sidetone modes on, paddle only and off - New code Marc-Andre, VE2EVN
          if (configuration.sidetone_mode == SIDETONE_PADDLE_ONLY) {
            configuration.sidetone_mode = SIDETONE_OFF;
            boop();      
            #ifdef FEATURE_DISPLAY
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("ST Off", 0, default_display_msg_delay);
              } else {            
                lcd_center_print_timed("Sidetone Off", 0, default_display_msg_delay);
              }
            #endif
          } else if (configuration.sidetone_mode == SIDETONE_ON) {
            configuration.sidetone_mode = SIDETONE_PADDLE_ONLY;
            beep();
            delay(200);
            beep();
            #ifdef FEATURE_DISPLAY
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("ST Pdl O", 0, default_display_msg_delay);
              }
              if (LCD_COLUMNS > 19){
                lcd_center_print_timed("Sidetone Paddle Only", 0, default_display_msg_delay);
              } else {
                lcd_center_print_timed("Sidetone", 0, default_display_msg_delay);
                lcd_center_print_timed("Paddle Only", 1, default_display_msg_delay);
              }
            #endif
          } else {
            #ifdef FEATURE_DISPLAY
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("ST On", 0, default_display_msg_delay);
              } else {
                lcd_center_print_timed("Sidetone On", 0, default_display_msg_delay);
              }
            #endif      
            configuration.sidetone_mode = SIDETONE_ON;
            beep();
          }
          config_dirty = 1;
         break;         

        case PS2_T_CTRL :
          #ifdef FEATURE_MEMORIES
            repeat_memory = 255;
          #endif
          if (keyboard_tune_on) {
            sending_mode = MANUAL_SENDING;
            tx_and_sidetone_key(0);
            keyboard_tune_on = 0;
            #ifdef FEATURE_DISPLAY
              lcd_status = LCD_REVERT;
            #endif // FEATURE_DISPLAY
          } else {
            #ifdef FEATURE_DISPLAY
              lcd_center_print_timed("Tune", 0, default_display_msg_delay);
            #endif      
            sending_mode = MANUAL_SENDING;
            tx_and_sidetone_key(1);
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
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("PTT Invk", 0, default_display_msg_delay);
              } else {            
                lcd_center_print_timed("PTT Invoke", 0, default_display_msg_delay);
              }            
            #endif      
            manual_ptt_invoke = 1;
            ptt_key();
          }
          break;

        case PS2_W_CTRL :
          #ifdef FEATURE_DISPLAY
            if (LCD_COLUMNS < 9){
              lcd_center_print_timed("WPM Adj", 0, default_display_msg_delay);
            } else {            
              lcd_center_print_timed("WPM Adjust", 0, default_display_msg_delay);
            }        
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

        #ifdef FEATURE_AUTOSPACE
          case PS2_Z_CTRL:
            if (configuration.autospace_active) {
              configuration.autospace_active = 0;
              config_dirty = 1;
              #ifdef FEATURE_DISPLAY
                if (LCD_COLUMNS < 9){
                  lcd_center_print_timed("AutoSOff", 0, default_display_msg_delay);
                } else {            
                  lcd_center_print_timed("Autospace Off", 0, default_display_msg_delay);
                }             
              #endif                                  
            } else {
              configuration.autospace_active = 1;
              config_dirty = 1;
              #ifdef FEATURE_DISPLAY
                if (LCD_COLUMNS < 9){
                  lcd_center_print_timed("AutoS On", 0, default_display_msg_delay);
                } else {            
                  lcd_center_print_timed("Autospace On", 0, default_display_msg_delay);
                }              
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

  #ifdef FEATURE_DISPLAY
    String lcd_string;
    if (LCD_COLUMNS < 9){
      lcd_string = "Pgm Mem";
    } else {
      lcd_string = "Program Memory";
    }
  #endif


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

        #ifdef FEATURE_SIDETONE_SWITCH
          check_sidetone_switch();
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
        send_dit();
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
int chk_rotary_encoder(){

  static unsigned long timestamp[5];

  unsigned char pinstate = (digitalRead(rotary_pin2) << 1) | digitalRead(rotary_pin1);
  state = ttable[state & 0xf][pinstate];
  unsigned char result = (state & 0x30);
  if (result) {
    timestamp[0] = timestamp[1];                    // Encoder step timer
    timestamp[1] = timestamp[2]; 
    timestamp[2] = timestamp[3]; 
    timestamp[3] = timestamp[4]; 
    timestamp[4] = millis();
    
    unsigned long elapsed_time = (timestamp[4] - timestamp[0]); // Encoder step time difference for 10's step
 
    if (result == DIR_CW) {
      if (elapsed_time < 250) {return 2;} else {return 1;};
    }
    if (result == DIR_CCW) {
      if (elapsed_time < 250) {return -2;} else {return -1;};
    }
  }
  return 0;
}

void check_rotary_encoder(){

  int step = chk_rotary_encoder();

  if (step != 0) {
    speed_change(step);
     
    // Start of Winkey Speed change mod for Rotary Encoder -- VE2EVN
    #ifdef FEATURE_WINKEY_EMULATION
      if ((primary_serial_port_mode == SERIAL_WINKEY_EMULATION) && (winkey_host_open)) {
        winkey_port_write(((configuration.wpm-pot_wpm_low_value)|128),0);
        winkey_last_unbuffered_speed_wpm = configuration.wpm;
      }
    #endif    
    // End of Winkey Speed change mod for Rotary Encoder -- VE2EVN

  } // if (step != 0)
  
}
#endif //FEATURE_ROTARY_ENCODER
//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_SIDETONE_SWITCH
void check_sidetone_switch()
{
	static unsigned long lastcheck = 0 ; 

    if ( millis() - lastcheck < 250 ) return ;

    lastcheck = millis() ;

    int ss_read = sidetone_switch_value();

    if ( (ss_read == HIGH)  && ( (configuration.sidetone_mode == SIDETONE_ON) ||
                               (configuration.sidetone_mode == SIDETONE_PADDLE_ONLY) )){
        return ;
    }
    if ( (ss_read == LOW)  && configuration.sidetone_mode == SIDETONE_OFF ){
        return ;
    }
    config_dirty = 1;
    #ifdef FEATURE_SLEEP
     last_activity_time = millis(); 
    #endif //FEATURE_SLEEP

    if ( ss_read == HIGH ) {
        configuration.sidetone_mode = SIDETONE_ON;
        return ;
    }
    if ( ss_read == LOW ){
        configuration.sidetone_mode = SIDETONE_OFF;
        return ;
    }
}

int sidetone_switch_value()
{
    return digitalRead(SIDETONE_SWITCH);
}

#endif


//-------------------------------------------------------------------------------------------------------


#ifdef FEATURE_POTENTIOMETER
void check_potentiometer()
{
  #ifdef DEBUG_LOOP
    debug_serial_port->println(F("loop: entering check_potentiometer")); 
  #endif

  static unsigned long last_pot_check_time = 0;
  
  if ((configuration.pot_activated || potentiometer_always_on) && ((millis() - last_pot_check_time) > potentiometer_check_interval_ms)) {
    last_pot_check_time = millis();
    if ((potentiometer_enable_pin) && (digitalRead(potentiometer_enable_pin) == HIGH)){
      return; 
    }
    byte pot_value_wpm_read = pot_value_wpm();
    if (((abs(pot_value_wpm_read - last_pot_wpm_read) * 10) > (potentiometer_change_threshold * 10))) {
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
          winkey_port_write(((pot_value_wpm_read-pot_wpm_low_value)|128),0);
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
  // int pot_read = analogRead(potentiometer);
  // byte return_value = map(pot_read, 0, pot_full_scale_reading, pot_wpm_low_value, pot_wpm_high_value);
  // return return_value;


  static int last_pot_read = 0;
  static byte return_value = 0;
  int pot_read = analogRead(potentiometer);
  if (abs(pot_read - last_pot_read) > potentiometer_reading_threshold ) {
    return_value = map(pot_read, 0, pot_full_scale_reading, pot_wpm_low_value, pot_wpm_high_value);
    last_pot_read = pot_read;
  }
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
  transmit_hell_char('!');//sp5iou
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
  sending_mode = AUTOMATIC_SENDING;
  if (hellbit) {
    tx_and_sidetone_key(1);
  } else {
    tx_and_sidetone_key(0);
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
          winkey_port_write(0xc0|winkey_sending|winkey_xoff,0);
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

  if (keyer_machine_mode == BEACON){return;}

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
    } else {  // if (ultimatic_mode == ULTIMATIC_NORMAL)
     if ((dit_buffer) && (dah_buffer)) {   // dit or dah priority mode
       if (ultimatic_mode == ULTIMATIC_DIT_PRIORITY) {
         dah_buffer = 0;
       } else {
         dit_buffer = 0;
       }
     }
    } // if (ultimatic_mode == ULTIMATIC_NORMAL)
  } // if (configuration.keyer_mode == ULTIMATIC)

  if (configuration.keyer_mode == SINGLE_PADDLE){
    switch (last_closure) {
      case DIT_CLOSURE_DAH_OFF:
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

      case DIT_CLOSURE_DAH_ON:

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

        

      case DAH_CLOSURE_DIT_OFF:
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

      case DAH_CLOSURE_DIT_ON:
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
  } //if (configuration.keyer_mode == SINGLE_PADDLE)

  service_tx_inhibit_and_pause();

}

//-------------------------------------------------------------------------------------------------------

void ptt_key(){

  unsigned long ptt_activation_time = millis();
  byte all_delays_satisfied = 0;
  
  #ifdef FEATURE_SEQUENCER
    byte sequencer_1_ok = 0;
    byte sequencer_2_ok = 0;
    byte sequencer_3_ok = 0;
    byte sequencer_4_ok = 0;
    byte sequencer_5_ok = 0;
  #endif 

  if (ptt_line_activated == 0) {   // if PTT is currently deactivated, bring it up and insert PTT lead time delay
    if (configuration.current_ptt_line) {
      digitalWrite (configuration.current_ptt_line, ptt_line_active_state);    
      #if defined(OPTION_WINKEY_2_SUPPORT) && defined(FEATURE_WINKEY_EMULATION)
        if ((wk2_both_tx_activated) && (ptt_tx_2)) {
          digitalWrite (ptt_tx_2, ptt_line_active_state);
        }
      #endif
      //delay(configuration.ptt_lead_time[configuration.current_tx-1]);
      #ifdef FEATURE_SEQUENCER
        sequencer_ptt_inactive_time = 0;
      #endif  
    }
    while (!all_delays_satisfied){
      #ifdef FEATURE_SEQUENCER
        if (sequencer_1_pin){
          if (((millis() - ptt_activation_time) >= configuration.ptt_active_to_sequencer_active_time[0]) || sequencer_1_active){
            digitalWrite(sequencer_1_pin,sequencer_pins_active_state);
            sequencer_1_ok = 1;
            sequencer_1_active = 1;
          }          
        } else {
          sequencer_1_ok = 1;
        }
        if (sequencer_2_pin){
          if (((millis() - ptt_activation_time) >= configuration.ptt_active_to_sequencer_active_time[1]) || sequencer_2_active){
            digitalWrite(sequencer_2_pin,sequencer_pins_active_state);
            sequencer_2_ok = 1;
            sequencer_2_active = 1;
          } 
        } else {
          sequencer_2_ok = 1;
        }
        if (sequencer_3_pin){
          if (((millis() - ptt_activation_time) >= configuration.ptt_active_to_sequencer_active_time[2]) || sequencer_3_active){
            digitalWrite(sequencer_3_pin,sequencer_pins_active_state);
            sequencer_3_ok = 1;
            sequencer_3_active = 1;
          } 
        } else {
          sequencer_3_ok = 1;
        }
        if (sequencer_4_pin){
          if (((millis() - ptt_activation_time) >= configuration.ptt_active_to_sequencer_active_time[3]) || sequencer_4_active){
            digitalWrite(sequencer_4_pin,sequencer_pins_active_state);
            sequencer_4_ok = 1;
            sequencer_4_active = 1;
          } 
        } else {
          sequencer_4_ok = 1;
        }
        if (sequencer_5_pin){
          if (((millis() - ptt_activation_time) >= configuration.ptt_active_to_sequencer_active_time[4]) || sequencer_5_active){
            digitalWrite(sequencer_5_pin,sequencer_pins_active_state);
            sequencer_5_ok = 1;
            sequencer_5_active = 1;
          } 
        } else {
          sequencer_5_ok = 1;
        }

        if (((millis() - ptt_activation_time) >= configuration.ptt_lead_time[configuration.current_tx-1]) && sequencer_1_ok && sequencer_2_ok && sequencer_3_ok && sequencer_4_ok && sequencer_5_ok){
          all_delays_satisfied = 1;
        }

      #else //FEATURE_SEQUENCER
        if ((millis() - ptt_activation_time) >= configuration.ptt_lead_time[configuration.current_tx-1]){
          all_delays_satisfied = 1;
        }
      #endif //FEATURE_SEQUENCER

    } //while (!all_delays_satisfied)
    ptt_line_activated = 1;
  }
  ptt_time = millis();
}
//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_SEQUENCER
void check_sequencer_tail_time(){

  if (sequencer_ptt_inactive_time){
    if (sequencer_1_pin){
      if (sequencer_1_active && ((millis() - sequencer_ptt_inactive_time) >= configuration.ptt_inactive_to_sequencer_inactive_time[0])){
        digitalWrite(sequencer_1_pin,sequencer_pins_inactive_state);
        sequencer_1_active = 0;
      }          
    }
    if (sequencer_2_pin){
      if (sequencer_2_active && ((millis() - sequencer_ptt_inactive_time) >= configuration.ptt_inactive_to_sequencer_inactive_time[1])){
        digitalWrite(sequencer_2_pin,sequencer_pins_inactive_state);
        sequencer_2_active = 0;
      } 
    }
    if (sequencer_3_pin){
      if (sequencer_3_active && ((millis() - sequencer_ptt_inactive_time) >= configuration.ptt_inactive_to_sequencer_inactive_time[2])){
        digitalWrite(sequencer_3_pin,sequencer_pins_inactive_state);
        sequencer_3_active = 0;
      } 
    }
    if (sequencer_4_pin){
      if (sequencer_4_active && ((millis() - sequencer_ptt_inactive_time) >= configuration.ptt_inactive_to_sequencer_inactive_time[3])){
        digitalWrite(sequencer_4_pin,sequencer_pins_inactive_state);
        sequencer_4_active = 0;
      } 
    }
    if (sequencer_5_pin){
      if (sequencer_5_active && ((millis() - sequencer_ptt_inactive_time) >= configuration.ptt_inactive_to_sequencer_inactive_time[4])){
        digitalWrite(sequencer_5_pin,sequencer_pins_inactive_state);
        sequencer_5_active = 0;
      } 
    }
  }

  if (!sequencer_1_active && !sequencer_2_active && !sequencer_3_active && !sequencer_4_active && !sequencer_5_active){
    sequencer_ptt_inactive_time = 0;
  }


}
#endif //FEATURE_SEQUENCER

//-------------------------------------------------------------------------------------------------------
void ptt_unkey(){



  if (ptt_line_activated) {

    if (configuration.current_ptt_line) {
      digitalWrite (configuration.current_ptt_line, ptt_line_inactive_state);
      #if defined(OPTION_WINKEY_2_SUPPORT) && defined(FEATURE_WINKEY_EMULATION)
        if ((wk2_both_tx_activated) && (ptt_tx_2)) {
          digitalWrite (ptt_tx_2, ptt_line_inactive_state);
        }
      #endif

    }
    ptt_line_activated = 0;
    #ifdef FEATURE_SEQUENCER
      sequencer_ptt_inactive_time = millis();
    #endif
  }
}

//-------------------------------------------------------------------------------------------------------
void check_ptt_tail()
{
  #ifdef DEBUG_LOOP
    debug_serial_port->println(F("loop: entering check_ptt_tail"));
  #endif

  static byte manual_ptt_invoke_ptt_input_pin = 0;


  if (ptt_input_pin){
    if ((digitalRead(ptt_input_pin) == ptt_input_pin_active_state)){
      if (!manual_ptt_invoke){
        manual_ptt_invoke = 1;
        manual_ptt_invoke_ptt_input_pin = 1;
        ptt_key();
        return; 
      }
    } else {
      if ((manual_ptt_invoke) && (manual_ptt_invoke_ptt_input_pin)){
        manual_ptt_invoke = 0;
        manual_ptt_invoke_ptt_input_pin = 0;
        if (!key_state){
          ptt_unkey();
        }
      }
    }  
  }


  #if !defined(FEATURE_WINKEY_EMULATION)
    if (key_state) {
      ptt_time = millis();
    } else {
      if ((ptt_line_activated) && (manual_ptt_invoke == 0)) {
        //if ((millis() - ptt_time) > ptt_tail_time) {
        if (last_sending_mode == MANUAL_SENDING) {
          #ifndef OPTION_INCLUDE_PTT_TAIL_FOR_MANUAL_SENDING

            // PTT Tail Time: N     PTT Hang Time: Y

            if ((millis() - ptt_time) >= ((configuration.length_wordspace*ptt_hang_time_wordspace_units)*float(1200/configuration.wpm)) ) {
              ptt_unkey();
            }          
          #else //ndef OPTION_INCLUDE_PTT_TAIL_FOR_MANUAL_SENDING
            #ifndef OPTION_EXCLUDE_PTT_HANG_TIME_FOR_MANUAL_SENDING

              // PTT Tail Time: Y     PTT Hang Time: Y

              if ((millis() - ptt_time) >= (((configuration.length_wordspace*ptt_hang_time_wordspace_units)*float(1200/configuration.wpm))+configuration.ptt_tail_time[configuration.current_tx-1])) {       
                ptt_unkey();
              }
            #else //OPTION_EXCLUDE_PTT_HANG_TIME_FOR_MANUAL_SENDING
            if ((millis() - ptt_time) >= configuration.ptt_tail_time[configuration.current_tx-1]) {  


              // PTT Tail Time: Y    PTT Hang Time: N

              ptt_unkey();
            }
            #endif //OPTION_EXCLUDE_PTT_HANG_TIME_FOR_MANUAL_SENDING
          #endif //ndef OPTION_INCLUDE_PTT_TAIL_FOR_MANUAL_SENDING
        } else { // automatic sending
          if (((millis() - ptt_time) > configuration.ptt_tail_time[configuration.current_tx-1]) && ( !configuration.ptt_buffer_hold_active || ((!send_buffer_bytes) && configuration.ptt_buffer_hold_active) || (pause_sending_buffer))){
            ptt_unkey();
          }
        }
      }
    }
  #else //FEATURE_WINKEY_EMULATION

    if (key_state) {
      ptt_time = millis();
    } else {
      if ((ptt_line_activated) && (manual_ptt_invoke == 0)) {
        //if ((millis() - ptt_time) > ptt_tail_time) {
        if (last_sending_mode == MANUAL_SENDING) {
          #ifndef OPTION_INCLUDE_PTT_TAIL_FOR_MANUAL_SENDING

            // PTT Tail Time: N     PTT Hang Time: Y

            if ((millis() - ptt_time) >= ((configuration.length_wordspace*ptt_hang_time_wordspace_units)*float(1200/configuration.wpm)) ) {
              ptt_unkey();
            }          
          #else //ndef OPTION_INCLUDE_PTT_TAIL_FOR_MANUAL_SENDING
            #ifndef OPTION_EXCLUDE_PTT_HANG_TIME_FOR_MANUAL_SENDING

              // PTT Tail Time: Y     PTT Hang Time: Y
              
            if (winkey_host_open){
              if ((millis() - ptt_time) >= (((configuration.length_wordspace*ptt_hang_time_wordspace_units)*float(1200/configuration.wpm))+ (int(winkey_session_ptt_tail) * 10) + (3 * (1200/configuration.wpm)) )) {       
                ptt_unkey();
              }
            } else { 
              if ((millis() - ptt_time) >= (((configuration.length_wordspace*ptt_hang_time_wordspace_units)*float(1200/configuration.wpm))+configuration.ptt_tail_time[configuration.current_tx-1])) {       
                ptt_unkey();
              }
            }



            #else //OPTION_EXCLUDE_PTT_HANG_TIME_FOR_MANUAL_SENDING
            if (winkey_host_open){
              if ((millis() - ptt_time) >= ((int(winkey_session_ptt_tail) * 10) + (3 * (1200/configuration.wpm)))) {  

                // PTT Tail Time: Y    PTT Hang Time: N

                ptt_unkey();
              }
            } else {
              if ((millis() - ptt_time) >= configuration.ptt_tail_time[configuration.current_tx-1]) {  


                // PTT Tail Time: Y    PTT Hang Time: N

                ptt_unkey();
              }
            }





            #endif //OPTION_EXCLUDE_PTT_HANG_TIME_FOR_MANUAL_SENDING
          #endif //ndef OPTION_INCLUDE_PTT_TAIL_FOR_MANUAL_SENDING
        } else { // automatic sending
          if (winkey_host_open){
            if (((millis() - ptt_time) > ((int(winkey_session_ptt_tail) * 10) + (3 * (1200/configuration.wpm)))) && ( !configuration.ptt_buffer_hold_active || ((!send_buffer_bytes) && configuration.ptt_buffer_hold_active) || (pause_sending_buffer))) {
              ptt_unkey();
            }
          } else {
            if (((millis() - ptt_time) > configuration.ptt_tail_time[configuration.current_tx-1]) && ( !configuration.ptt_buffer_hold_active || ((!send_buffer_bytes) && configuration.ptt_buffer_hold_active) || (pause_sending_buffer))){
              ptt_unkey();
            }            
          }  
        }
      }
    }





  #endif //FEATURE_WINKEY_EMULATION  





}

//-------------------------------------------------------------------------------------------------------
//void write_settings_to_eeprom(int initialize_eeprom) {  //zzzzzz
// 
//  #if !defined(ARDUINO_SAM_DUE) || (defined(ARDUINO_SAM_DUE) && defined(FEATURE_EEPROM_E24C1024))
//  
//  if (initialize_eeprom) {
//    //configuration.magic_number = eeprom_magic_number;
//    EEPROM.write(0,eeprom_magic_number);
//    #ifdef FEATURE_MEMORIES
//      initialize_eeprom_memories();
//    #endif  //FEATURE_MEMORIES    
//  }
//
//  const byte* p = (const byte*)(const void*)&configuration;
//  unsigned int i;
//  int ee = 1;  // starting point of configuration struct
//  for (i = 0; i < sizeof(configuration); i++){
//    EEPROM.write(ee++, *p++);  
//  }
//  
//  #endif //!defined(ARDUINO_SAM_DUE) || (defined(ARDUINO_SAM_DUE) && defined(FEATURE_EEPROM_E24C1024))
//  
//  config_dirty = 0;
//  
//  
//}


void write_settings_to_eeprom(int initialize_eeprom) {  
 
  #if !defined(ARDUINO_SAM_DUE) || (defined(ARDUINO_SAM_DUE) && defined(FEATURE_EEPROM_E24C1024))
  
    if (initialize_eeprom) {
      //configuration.magic_number = eeprom_magic_number;
      EEPROM.write(0,eeprom_magic_number);
      #ifdef FEATURE_MEMORIES
        initialize_eeprom_memories();
      #endif  //FEATURE_MEMORIES  
      const byte* p = (const byte*)(const void*)&configuration;
      unsigned int i;
      int ee = 1;  // starting point of configuration struct
      for (i = 0; i < sizeof(configuration); i++){
        EEPROM.write(ee++, *p++);  
      }        
    } else {

      async_eeprom_write = 1;  // initiate an asyncrhonous eeprom write

    }
  
  #endif //!defined(ARDUINO_SAM_DUE) || (defined(ARDUINO_SAM_DUE) && defined(FEATURE_EEPROM_E24C1024))

  config_dirty = 0;
  
}

//-------------------------------------------------------------------------------------------------------

void service_async_eeprom_write(){

  // This writes one byte out to EEPROM each time it is called

  static byte last_async_eeprom_write_status = 0;
  static int ee = 0;
  static unsigned int i = 0;
  static const byte* p;

  if ((async_eeprom_write) && (!send_buffer_bytes) && (!ptt_line_activated) && (!dit_buffer) && (!dah_buffer) && (paddle_pin_read(paddle_left) == HIGH)  && (paddle_pin_read(paddle_right) == HIGH)) {  
    if (last_async_eeprom_write_status){ // we have an ansynchronous write to eeprom in progress

#if defined(_BOARD_PIC32_PINGUINO_)
      if (EEPROM.read(ee) != *p) {
        EEPROM.write(ee, *p);
      }
      ee++;
      p++;
#else
      EEPROM.update(ee++, *p++);
#endif

      if (i < sizeof(configuration)){
        #if defined(DEBUG_ASYNC_EEPROM_WRITE)
          debug_serial_port->print(F("service_async_eeprom_write: write: "));
          debug_serial_port->println(i);
        #endif        
        i++;
      } else { // we're done
        async_eeprom_write = 0;
        last_async_eeprom_write_status = 0;
        #if defined(DEBUG_ASYNC_EEPROM_WRITE)
          debug_serial_port->println(F("service_async_eeprom_write: complete"));
        #endif        
      }

    } else { // we don't have one in progress - initialize things

      p = (const byte*)(const void*)&configuration;
      ee = 1;  // starting point of configuration struct
      i = 0;
      last_async_eeprom_write_status = 1;
      #if defined(DEBUG_ASYNC_EEPROM_WRITE)
        debug_serial_port->println(F("service_async_eeprom_write: init"));
      #endif
    }
  }

}

//-------------------------------------------------------------------------------------------------------

int read_settings_from_eeprom() {

  // returns 0 if eeprom had valid settings, returns 1 if eeprom needs initialized

  #if defined(DEBUG_FORCE_RESET)
    return 1;
  #endif
  
  #if !defined(ARDUINO_SAM_DUE) || (defined(ARDUINO_SAM_DUE) && defined(FEATURE_EEPROM_E24C1024))

    if (EEPROM.read(0) == eeprom_magic_number){
    
      byte* p = (byte*)(void*)&configuration;
      unsigned int i;
      int ee = 1; // starting point of configuration struct
      for (i = 0; i < sizeof(configuration); i++){
        *p++ = EEPROM.read(ee++);  
      }
    
      switch_to_tx_silent(configuration.current_tx);
      config_dirty = 0;

      // #if defined(FEATURE_SINEWAVE_SIDETONE)
      //   initialize_tonsin();
      // #endif 

      return 0;
    } else {
      return 1;
    }
  
  #endif //!defined(ARDUINO_SAM_DUE) || (defined(ARDUINO_SAM_DUE) && defined(FEATURE_EEPROM_E24C1024))


 
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
      sending_mode = MANUAL_SENDING;
      loop_element_lengths(3,0,configuration.wpm);
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
        send_winkey_breakin_byte_flag = 1;
        // winkey_port_write(0xc2|winkey_sending|winkey_xoff); // 0xc2 - BREAKIN bit set high
        // winkey_interrupted = 1;

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
        send_winkey_breakin_byte_flag = 1;
        dah_buffer = 0;
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

void send_dit(){

  // notes: key_compensation is a straight x mS lengthening or shortening of the key down time
  //        weighting is

  unsigned int character_wpm = configuration.wpm;


  #ifdef FEATURE_FARNSWORTH
    if ((sending_mode == AUTOMATIC_SENDING) && (configuration.wpm_farnsworth > configuration.wpm)) {
      character_wpm = configuration.wpm_farnsworth;
      #if defined(DEBUG_FARNSWORTH)
        debug_serial_port->println(F("send_dit: farns act"));
      #endif
    } 
      #if defined(DEBUG_FARNSWORTH)

    else {
      debug_serial_port->println(F("send_dit: farns inact"));
    }
    #endif
  #endif //FEATURE_FARNSWORTH

  if (keyer_machine_mode == KEYER_COMMAND_MODE){
    character_wpm = configuration.wpm_command_mode;
  }

  being_sent = SENDING_DIT;
  tx_and_sidetone_key(1);
  #ifdef DEBUG_VARIABLE_DUMP
    dit_start_time = millis();
  #endif
  if ((tx_key_dit) && (key_tx)) {digitalWrite(tx_key_dit,tx_key_dit_and_dah_pins_active_state);}


  #ifdef FEATURE_QLF
    if (qlf_active){
      loop_element_lengths((1.0*(float(configuration.weighting)/50)*(random(qlf_dit_min,qlf_dit_max)/100.0)),keying_compensation,character_wpm);
    } else {
      loop_element_lengths((1.0*(float(configuration.weighting)/50)),keying_compensation,character_wpm);
    }
  #else //FEATURE_QLF 
    loop_element_lengths((1.0*(float(configuration.weighting)/50)),keying_compensation,character_wpm);
  #endif //FEATURE_QLF


  
  if ((tx_key_dit) && (key_tx)) {digitalWrite(tx_key_dit,tx_key_dit_and_dah_pins_inactive_state);}
  #ifdef DEBUG_VARIABLE_DUMP
    dit_end_time = millis();
  #endif
  tx_and_sidetone_key(0);


  loop_element_lengths((2.0-(float(configuration.weighting)/50)),(-1.0*keying_compensation),character_wpm);

  #ifdef FEATURE_AUTOSPACE

    byte autospace_end_of_character_flag = 0;

    if ((sending_mode == MANUAL_SENDING) && (configuration.autospace_active)) {
      check_paddles();
    }
    if ((sending_mode == MANUAL_SENDING) && (configuration.autospace_active) && (dit_buffer == 0) && (dah_buffer == 0)) {
      loop_element_lengths(2,0,configuration.wpm);
      autospace_end_of_character_flag = 1;
    }
  #endif

  #ifdef FEATURE_WINKEY_EMULATION
    if ((winkey_host_open) && (winkey_paddle_echo_activated) && (sending_mode == MANUAL_SENDING)) {
      winkey_paddle_echo_buffer = (winkey_paddle_echo_buffer * 10) + 1;
      //winkey_paddle_echo_buffer_decode_time = millis() + (float(winkey_paddle_echo_buffer_decode_time_factor/float(configuration.wpm))*length_letterspace);
      winkey_paddle_echo_buffer_decode_time = millis() + (float(winkey_paddle_echo_buffer_decode_timing_factor*1200.0/float(configuration.wpm))*length_letterspace);
      
      #ifdef FEATURE_AUTOSPACE
        if (autospace_end_of_character_flag){winkey_paddle_echo_buffer_decode_time = 0;}
      #endif //FEATURE_AUTOSPACE    
    }
  #endif


  #ifdef FEATURE_PADDLE_ECHO
    if (sending_mode == MANUAL_SENDING) {
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
  last_sending_mode = sending_mode;
  
  check_paddles();

}

//-------------------------------------------------------------------------------------------------------

void send_dah(){

  unsigned int character_wpm  = configuration.wpm;

  #ifdef FEATURE_FARNSWORTH
    if ((sending_mode == AUTOMATIC_SENDING) && (configuration.wpm_farnsworth > configuration.wpm)) {
      character_wpm = configuration.wpm_farnsworth;
    }
  #endif //FEATURE_FARNSWORTH

  if (keyer_machine_mode == KEYER_COMMAND_MODE){
    character_wpm = configuration.wpm_command_mode;
  }

  being_sent = SENDING_DAH;
  tx_and_sidetone_key(1);
  #ifdef DEBUG_VARIABLE_DUMP
    dah_start_time = millis();
  #endif
  if ((tx_key_dah) && (key_tx)) {digitalWrite(tx_key_dah,tx_key_dit_and_dah_pins_active_state);}

  #ifdef FEATURE_QLF
    if (qlf_active){
      loop_element_lengths((float(configuration.dah_to_dit_ratio/100.0)*(float(configuration.weighting)/50)*(random(qlf_dah_min,qlf_dah_max)/100.0)),keying_compensation,character_wpm);
    } else {
      loop_element_lengths((float(configuration.dah_to_dit_ratio/100.0)*(float(configuration.weighting)/50)),keying_compensation,character_wpm);
    }
  #else //FEATURE_QLF 
    loop_element_lengths((float(configuration.dah_to_dit_ratio/100.0)*(float(configuration.weighting)/50)),keying_compensation,character_wpm);
  #endif //FEATURE_QLF 

  if ((tx_key_dah) && (key_tx)) {digitalWrite(tx_key_dah,tx_key_dit_and_dah_pins_inactive_state);}

  #ifdef DEBUG_VARIABLE_DUMP
    dah_end_time = millis();
  #endif

  tx_and_sidetone_key(0);

  loop_element_lengths((4.0-(3.0*(float(configuration.weighting)/50))),(-1.0*keying_compensation),character_wpm);

  #ifdef FEATURE_AUTOSPACE

    byte autospace_end_of_character_flag = 0;

    if ((sending_mode == MANUAL_SENDING) && (configuration.autospace_active)) {
      check_paddles();
    }
    if ((sending_mode == MANUAL_SENDING) && (configuration.autospace_active) && (dit_buffer == 0) && (dah_buffer == 0)) {
      loop_element_lengths(2,0,configuration.wpm);
      autospace_end_of_character_flag = 1;
    }
  #endif

  #ifdef FEATURE_WINKEY_EMULATION
    if ((winkey_host_open) && (winkey_paddle_echo_activated) && (sending_mode == MANUAL_SENDING)) {
      winkey_paddle_echo_buffer = (winkey_paddle_echo_buffer * 10) + 2;
      //winkey_paddle_echo_buffer_decode_time = millis() + (float(winkey_paddle_echo_buffer_decode_time_factor/float(configuration.wpm))*length_letterspace);
      winkey_paddle_echo_buffer_decode_time = millis() + (float(winkey_paddle_echo_buffer_decode_timing_factor*1200.0/float(configuration.wpm))*length_letterspace);      
      #ifdef FEATURE_AUTOSPACE
        if (autospace_end_of_character_flag){winkey_paddle_echo_buffer_decode_time = 0;}
      #endif //FEATURE_AUTOSPACE
    }
  #endif
 
  #ifdef FEATURE_PADDLE_ECHO
    if (sending_mode == MANUAL_SENDING) {
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

  check_paddles();

  being_sent = SENDING_NOTHING;
  last_sending_mode = sending_mode;

}

/* 

    The Dash
    
    by Linda Ellis


    I read of a man who stood to speak at a funeral of a friend.  He referred to the dates on the tombstone from the beginning...to the end.

    He noted that first came the date of birth and spoke of the following date with tears, but said what mattered most of all was the dash
     between those years.

    For that dash represents all the time they spent alive on earth and now only those who loved them know what that little line is worth.

    For it matters not, how much we own, the cars..the house...the cash.

      What matters is how we lived and loved and how we spend our dash.

    So think about this long and hard; are there things you'd like to change?

      For you never know how much time is left that still can be rearranged.

    To be less quick to anger and show appreciation more and love the people in our lives like we've never loved before.

    If we treat each other with respect and more often wear a smile...remembering that this special dash might only last a little while.

    So when your eulogy is being read, with your life's actions to rehash,


     would you be proud of the things they say about how you lived your dash?



*/


//-------------------------------------------------------------------------------------------------------

void tx_and_sidetone_key (int state)
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
        if (current_tx_key_line) {digitalWrite (current_tx_key_line, tx_key_line_active_state);}
        #if defined(OPTION_WINKEY_2_SUPPORT) && defined(FEATURE_WINKEY_EMULATION)
          if ((wk2_both_tx_activated) && (tx_key_line_2)) {
            digitalWrite (tx_key_line_2, HIGH);
          }
        #endif
        if ((first_extension_time) && (previous_ptt_line_activated == 0)) {
          delay(first_extension_time);
        }
      }
      if ((configuration.sidetone_mode == SIDETONE_ON) || (keyer_machine_mode == KEYER_COMMAND_MODE) || ((configuration.sidetone_mode == SIDETONE_PADDLE_ONLY) && (sending_mode == MANUAL_SENDING))) {
        #if !defined(OPTION_SIDETONE_DIGITAL_OUTPUT_NO_SQUARE_WAVE)
          tone(sidetone_line, configuration.hz_sidetone);
        #else
          digitalWrite(sidetone_line, HIGH);
        #endif
      }
      key_state = 1;
    } else {
      if ((state == 0) && (key_state)) {
        if (key_tx) {
          if (current_tx_key_line) {digitalWrite (current_tx_key_line, tx_key_line_inactive_state);}
          #if defined(OPTION_WINKEY_2_SUPPORT) && defined(FEATURE_WINKEY_EMULATION)
            if ((wk2_both_tx_activated) && (tx_key_line_2)) {
              digitalWrite (tx_key_line_2, LOW);
            }
          #endif        
          ptt_key();
        }
        if ((configuration.sidetone_mode == SIDETONE_ON) || (keyer_machine_mode == KEYER_COMMAND_MODE) || ((configuration.sidetone_mode == SIDETONE_PADDLE_ONLY) && (sending_mode == MANUAL_SENDING))) {
          #if !defined(OPTION_SIDETONE_DIGITAL_OUTPUT_NO_SQUARE_WAVE)
            noTone(sidetone_line);
          #else
            digitalWrite(sidetone_line, LOW);
          #endif
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
        if (current_tx_key_line) {digitalWrite (current_tx_key_line, tx_key_line_active_state);}
        #if defined(OPTION_WINKEY_2_SUPPORT) && defined(FEATURE_WINKEY_EMULATION)
          if ((wk2_both_tx_activated) && (tx_key_line_2)) {
            digitalWrite (tx_key_line_2, HIGH);
          }
        #endif
        if ((first_extension_time) && (previous_ptt_line_activated == 0)) {
          delay(first_extension_time);
        }
      }
      if ((configuration.sidetone_mode == SIDETONE_ON) || (keyer_machine_mode == KEYER_COMMAND_MODE) || ((configuration.sidetone_mode == SIDETONE_PADDLE_ONLY) && (sending_mode == MANUAL_SENDING))) {
        #if !defined(OPTION_SIDETONE_DIGITAL_OUTPUT_NO_SQUARE_WAVE)
          tone(sidetone_line, configuration.hz_sidetone);
        #else
          digitalWrite(sidetone_line, HIGH);
        #endif          
      }
      key_state = 1;
    } else {
      if ((state == 0) && (key_state)) {
        if (key_tx) {
          if (current_tx_key_line) {digitalWrite (current_tx_key_line, tx_key_line_inactive_state);}
          #if defined(OPTION_WINKEY_2_SUPPORT) && defined(FEATURE_WINKEY_EMULATION)
            if ((wk2_both_tx_activated) && (tx_key_line_2)) {
              digitalWrite (tx_key_line_2, LOW);
            }
          #endif        
          if (!ptt_interlock_active) {
            ptt_key();
          }
        }
        if ((configuration.sidetone_mode == SIDETONE_ON) || (keyer_machine_mode == KEYER_COMMAND_MODE) || ((configuration.sidetone_mode == SIDETONE_PADDLE_ONLY) && (sending_mode == MANUAL_SENDING))) {
          #if !defined(OPTION_SIDETONE_DIGITAL_OUTPUT_NO_SQUARE_WAVE)
            noTone(sidetone_line);
          #else
            digitalWrite(sidetone_line, LOW);
          #endif
        }
        key_state = 0;
      }
    }

  #endif //FEATURE_PTT_INTERLOCK

  #if defined(FEATURE_INTERNET_LINK)
    link_key(state);
  #endif

  check_ptt_tail();


}


//-------------------------------------------------------------------------------------------------------

void loop_element_lengths(float lengths, float additional_time_ms, int speed_wpm_in){

    #if defined(FEATURE_SERIAL) && defined(OPTION_ENABLE_SERIAL_PORT_CHECKING_WHILE_SENDING_CW_MAY_CAUSE_PROBLEMS)
      loop_element_lengths_breakout_flag = 1;
    #endif //FEATURE_SERIAL  
    
    if ((lengths == 0) or (lengths < 0)) {
     return;
    }

    float element_length;

    #if defined(FEATURE_FARNSWORTH)

      if ((lengths == 1) && (speed_wpm_in == 0)){
        element_length = additional_time_ms;
      } else {
        if (speed_mode == SPEED_NORMAL) {
          element_length = 1200/speed_wpm_in;   
        } else {
          element_length = qrss_dit_length * 1000;
        }
      }

    #else //FEATURE_FARNSWORTH
      if (speed_mode == SPEED_NORMAL) {
        element_length = 1200/speed_wpm_in;   
      } else {
        element_length = qrss_dit_length * 1000;
      }
    #endif //FEATURE_FARNSWORTH


    unsigned long ticks = long(element_length*lengths*1000) + long(additional_time_ms*1000); // improvement from Paul, K1XM
    unsigned long start = micros();
    //unsigned long endtime = micros() + long(element_length*lengths*1000) + long(additional_time_ms*1000);

    #if defined(FEATURE_SERIAL) && defined(OPTION_ENABLE_SERIAL_PORT_CHECKING_WHILE_SENDING_CW_MAY_CAUSE_PROBLEMS)
    while (((micros() - start) < ticks) && (service_tx_inhibit_and_pause() == 0) && loop_element_lengths_breakout_flag ){
    #else
    while (((micros() - start) < ticks) && (service_tx_inhibit_and_pause() == 0)){
    #endif

      check_ptt_tail();
      
      #if defined(FEATURE_SERIAL) && defined(OPTION_ENABLE_SERIAL_PORT_CHECKING_WHILE_SENDING_CW_MAY_CAUSE_PROBLEMS)
        if ((ticks - (micros() - start)) > (10 * 1000)) {
          check_serial();
          if (loop_element_lengths_breakout_flag == 0){
            dump_current_character_flag = 1;
          }
        }
      #endif //FEATURE_SERIAL

       #if defined(FEATURE_INTERNET_LINK) /*&& !defined(OPTION_INTERNET_LINK_NO_UDP_SVC_DURING_KEY_DOWN)*/
         if ((millis() > 1000)  && ((millis()-start) > FEATURE_INTERNET_LINK_SVC_DURING_LOOP_TIME_MS)){
           service_udp_send_buffer();
           service_udp_receive();
           service_internet_link_udp_receive_buffer();
         }
       #endif //FEATURE_INTERNET_LINK

       #if defined(OPTION_WATCHDOG_TIMER)
         wdt_reset();
       #endif  //OPTION_WATCHDOG_TIMER
      
       #if defined(FEATURE_ROTARY_ENCODER)
         check_rotary_encoder();
       #endif //FEATURE_ROTARY_ENCODER    
      
       #if defined(FEATURE_USB_KEYBOARD) || defined(FEATURE_USB_MOUSE)
         service_usb();
       #endif //FEATURE_USB_KEYBOARD || FEATURE_USB_MOUSE

       #if defined(FEATURE_PTT_INTERLOCK)
         service_ptt_interlock();
       #endif //FEATURE_PTT_INTERLOCK

       #if defined(FEATURE_4x4_KEYPAD) || defined(FEATURE_3x4_KEYPAD)
         service_keypad();
       #endif
      
       if ((configuration.keyer_mode != ULTIMATIC) && (configuration.keyer_mode != SINGLE_PADDLE)) {
         if ((configuration.keyer_mode == IAMBIC_A) && (paddle_pin_read(paddle_left) == LOW ) && (paddle_pin_read(paddle_right) == LOW )) {
             iambic_flag = 1;
         }    
     
         #ifndef FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
           if (being_sent == SENDING_DIT) {
             check_dah_paddle();
           } else {
             if (being_sent == SENDING_DAH) {
               check_dit_paddle();
             } else {
               check_dah_paddle();
               check_dit_paddle();                
             }
           }            
         #else ////FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
           if (configuration.cmos_super_keyer_iambic_b_timing_on){
             if ((float(float(micros()-start)/float(ticks))*100) >= configuration.cmos_super_keyer_iambic_b_timing_percent) {
             //if ((float(float(millis()-starttime)/float(starttime-ticks))*100) >= configuration.cmos_super_keyer_iambic_b_timing_percent) {
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
           } else {
             if (being_sent == SENDING_DIT) {
               check_dah_paddle();
             } else {
               if (being_sent == SENDING_DAH) {
                 check_dit_paddle();
               } else {
                 check_dah_paddle();
                 check_dit_paddle();                
               }
             }  
           }  
         #endif //FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING

       } else { //(configuration.keyer_mode != ULTIMATIC)


           if (being_sent == SENDING_DIT) {
             check_dah_paddle();
           } else {
             if (being_sent == SENDING_DAH) {
               check_dit_paddle();
             } else {
               check_dah_paddle();
               check_dit_paddle();                
             }
           }   

       }
      
       #if defined(FEATURE_MEMORIES) && defined(FEATURE_COMMAND_BUTTONS)
         check_the_memory_buttons();
       #endif

       // blow out prematurely if we're automatic sending and a paddle gets hit
       #ifdef FEATURE_COMMAND_BUTTONS
         if (sending_mode == AUTOMATIC_SENDING && (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || analogbuttonread(0) || dit_buffer || dah_buffer)) {
           if (keyer_machine_mode == KEYER_NORMAL) {
             sending_mode = AUTOMATIC_SENDING_INTERRUPTED;
             automatic_sending_interruption_time = millis(); 
             return;
           }
         }   
       #else
         if (sending_mode == AUTOMATIC_SENDING && (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || dit_buffer || dah_buffer)) {
           if (keyer_machine_mode == KEYER_NORMAL) {
             sending_mode = AUTOMATIC_SENDING_INTERRUPTED;
             automatic_sending_interruption_time = millis(); 
             return;
           }
         }   
       #endif

       #ifdef FEATURE_STRAIGHT_KEY
         service_straight_key();
       #endif //FEATURE_STRAIGHT_KEY


        #if defined(FEATURE_WEB_SERVER)
          if (speed_mode == SPEED_QRSS){
            service_web_server();
          }
        #endif //FEATURE_WEB_SERVER
        
     }  //while ((millis() < endtime) && (millis() > 200))




   
     if ((configuration.keyer_mode == IAMBIC_A) && (iambic_flag) && (paddle_pin_read(paddle_left) == HIGH ) && (paddle_pin_read(paddle_right) == HIGH )) {
         iambic_flag = 0;
         dit_buffer = 0;
         dah_buffer = 0;
     }    
   
     if ((being_sent == SENDING_DIT) || (being_sent == SENDING_DAH)){
       if (configuration.dit_buffer_off) {dit_buffer = 0;}
       if (configuration.dah_buffer_off) {dah_buffer = 0;}
     }  

   

} //void loop_element_lengths


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

void speed_change_command_mode(int change)
{
  if (((configuration.wpm_command_mode + change) > wpm_limit_low) && ((configuration.wpm_command_mode + change) < wpm_limit_high)) {
    configuration.wpm_command_mode = configuration.wpm_command_mode + change;
    config_dirty = 1;
  }
  

  #ifdef FEATURE_DISPLAY
    lcd_center_print_timed(String(configuration.wpm_command_mode) + " wpm", 0, default_display_msg_delay);
  #endif
}

//-------------------------------------------------------------------------------------------------------

void speed_set(int wpm_set){


  if ((wpm_set > 0) && (wpm_set < 1000)){
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
}
//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_DISPLAY
  void lcd_center_print_timed_wpm(){


    #if defined(OPTION_ADVANCED_SPEED_DISPLAY)
      lcd_center_print_timed(String(configuration.wpm) + " wpm - " + (configuration.wpm*5) + " cpm", 0, default_display_msg_delay);
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

    #ifdef OPTION_WATCHDOG_TIMER
      wdt_reset();
    #endif  //OPTION_WATCHDOG_TIMER

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
      sending_mode = MANUAL_SENDING;
      send_dit();
      dit_buffer = 0;
      paddle_hit = 1;
      cw_char = (cw_char * 10) + 1;
      last_element_time = millis();
    }
    if (dah_buffer) {
      sending_mode = MANUAL_SENDING;
      send_dah();
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
void command_mode()
{

  keyer_machine_mode = KEYER_COMMAND_MODE;
  
  #ifdef DEBUG_COMMAND_MODE
    debug_serial_port->println(F("command_mode: entering"));
  #endif

  #ifdef OPTION_WATCHDOG_TIMER
    wdt_disable();
  #endif //OPTION_WATCHDOG_TIMER

  
  byte looping;
  byte button_that_was_pressed = 0;
  byte paddle_hit = 0;
  unsigned long last_element_time = 0;
  unsigned long cw_char;
  byte stay_in_command_mode = 1;
  byte speed_mode_before = speed_mode;
  speed_mode = SPEED_NORMAL;                 // put us in normal speed mode (life is too short to do command mode in QRSS)
  byte keyer_mode_before = configuration.keyer_mode;
  char c[4];
  if ((configuration.keyer_mode != IAMBIC_A) && (configuration.keyer_mode != IAMBIC_B) && (configuration.keyer_mode != ULTIMATIC)) {
  //if ((configuration.keyer_mode != IAMBIC_A) && (configuration.keyer_mode != IAMBIC_B)) {
    configuration.keyer_mode = IAMBIC_B;                   // we got to be in iambic mode (life is too short to make this work in bug mode)
  }

  // command_mode_disable_tx = 0;  //Removed disable TX state every time Command Mode is entered - now set to actual key_tx status on CM entry (WD9DMP)

  boop_beep();
  #ifdef command_mode_active_led
    if (command_mode_active_led) {digitalWrite(command_mode_active_led,HIGH);}
  #endif //command_mode_active_led

  #ifdef FEATURE_DISPLAY
    lcd_clear();
    if (LCD_COLUMNS < 9){
      lcd_center_print_timed("Cmd Mode", 0, default_display_msg_delay);
    } else {
      lcd_center_print_timed("Command Mode", 0, default_display_msg_delay);
    }
  #endif 

  #if defined(FEATURE_WINKEY_EMULATION) && defined(OPTION_WINKEY_SEND_BREAKIN_STATUS_BYTE)
    winkey_breakin_status_byte_inhibit = 1;
  #endif

  while (stay_in_command_mode) {
    cw_char = 0;

    // #ifdef OPTION_WATCHDOG_TIMER
    //   wdt_reset();
    // #endif  //OPTION_WATCHDOG_TIMER

    looping = 1;
    while (looping) {

          #ifdef FEATURE_DISPLAY
            service_display();
          #endif

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
        sending_mode = MANUAL_SENDING;
        send_dit();
        dit_buffer = 0;
        paddle_hit = 1;
        cw_char = (cw_char * 10) + 1;
        last_element_time = millis();
      }
      if (dah_buffer) {
        sending_mode = MANUAL_SENDING;
        send_dah();
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
        configuration.keyer_mode = keyer_mode_before;
        check_serial();
        if ((configuration.keyer_mode != IAMBIC_A) && (configuration.keyer_mode != IAMBIC_B) && (configuration.keyer_mode != ULTIMATIC)  && (configuration.keyer_mode != SINGLE_PADDLE)) {
          configuration.keyer_mode = IAMBIC_B;                   
        }
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
          configuration.dit_buffer_off = 0;
          configuration.dah_buffer_off = 0;
          config_dirty = 1;
          #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Iambic A", 0, default_display_msg_delay);
          #endif
          send_dit();
          break; 
        case 2111: // B - Iambic mode
          configuration.keyer_mode = IAMBIC_B;
          keyer_mode_before = IAMBIC_B;
          configuration.dit_buffer_off = 0;
          configuration.dah_buffer_off = 0;          
          config_dirty = 1;
          #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Iambic B", 0, default_display_msg_delay);
          #endif          
          send_dit();
          break;
        case 2121: // C - Single paddle mode
          configuration.keyer_mode = SINGLE_PADDLE;
          keyer_mode_before = SINGLE_PADDLE;
          config_dirty = 1;
          #ifdef FEATURE_DISPLAY
            if (LCD_COLUMNS < 9){
              lcd_center_print_timed("Sngl Pdl", 0, default_display_msg_delay);
            } else {
              lcd_center_print_timed("Single Paddle", 0, default_display_msg_delay);
            }
          #endif          
          send_dit();
          break;          
        case 1: // E - announce spEed
          delay(250);
          sprintf(c, "%d", configuration.wpm);
          send_char(c[0],KEYER_NORMAL);
          send_char(c[1],KEYER_NORMAL);
          break; 
        case 211: // D - Ultimatic mode
          configuration.keyer_mode = ULTIMATIC;
          keyer_mode_before = ULTIMATIC;
          configuration.dit_buffer_off = 1;
          configuration.dah_buffer_off = 1;           
          config_dirty = 1;
          #ifdef FEATURE_DISPLAY
            if (LCD_COLUMNS < 9){
              lcd_center_print_timed("Ultimatc", 0, default_display_msg_delay);
            } else {
              lcd_center_print_timed("Ultimatic", 0, default_display_msg_delay);
            }          
          #endif                    
          send_dit();
          break; 
        #if !defined(OPTION_SIDETONE_DIGITAL_OUTPUT_NO_SQUARE_WAVE)
          case 1121: command_sidetone_freq_adj(); break;                    // F - adjust sidetone frequency
          // #if defined(FEATURE_SINEWAVE_SIDETONE)
          //   case 2212: command_sidetone_volume_adj(); break;                    // Q - adjust sinewave sidetone volume
          // #endif
        #endif
        case 221: // G - switch to buG mode
          configuration.keyer_mode = BUG;
          keyer_mode_before = BUG;
          config_dirty = 1;
          #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Bug", 0, default_display_msg_delay);
          #endif          
          send_dit();
          break;  
        case 1111:   // H - set weighting and dah to dit ratio to defaults
          configuration.weighting = default_weighting;
          configuration.dah_to_dit_ratio = initial_dah_to_dit_ratio;
          config_dirty = 1;
          #ifdef FEATURE_DISPLAY
            if (LCD_COLUMNS < 9){
              lcd_center_print_timed("Dflt W+R", 0, default_display_msg_delay); 
            } else {
              lcd_center_print_timed("Dflt Wght & Ratio", 0, default_display_msg_delay); 
            }              
          #endif         
          send_dit();
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
          send_dit();
          break;
        case 1222: command_dah_to_dit_ratio_adjust(); break;                        // J - dah to dit ratio adjust
        case 212:                                                                   // K - turn dit and dah buffers on and off
          if (configuration.keyer_mode == ULTIMATIC){
            send_char('O',KEYER_NORMAL);
            if (configuration.dit_buffer_off){
              configuration.dit_buffer_off = 0;
              configuration.dah_buffer_off = 0;
              #ifdef FEATURE_DISPLAY
                if (LCD_COLUMNS < 9){
                  lcd_center_print_timed("BffersOn", 0, default_display_msg_delay);
                }
                if (LCD_COLUMNS > 17){
                  lcd_center_print_timed("Dit Dah Buffers On", 0, default_display_msg_delay);                  
                } else {
                  lcd_center_print_timed("Buffers On", 0, default_display_msg_delay);
                }                 
              #endif
              send_char('N',KEYER_NORMAL);           
            } else {
              configuration.dit_buffer_off = 1;
              configuration.dah_buffer_off = 1;
              #ifdef FEATURE_DISPLAY
                if (LCD_COLUMNS < 9){
                  lcd_center_print_timed("BffrsOff", 0, default_display_msg_delay);
                }
                if (LCD_COLUMNS > 18){
                  lcd_center_print_timed("Dit Dah Buffers Off", 0, default_display_msg_delay);                  
                } else {
                  lcd_center_print_timed("Buffers Off", 0, default_display_msg_delay);
                }                                  
              #endif 
              send_char('F',KEYER_NORMAL);
              send_char('F',KEYER_NORMAL);             
            }
          } else {
            #ifdef FEATURE_DISPLAY
              lcd_center_print_timed("Error", 0, default_display_msg_delay);
            #endif             
            send_char('E',KEYER_NORMAL);
            send_char('R',KEYER_NORMAL);
            send_char('R',KEYER_NORMAL);
          }
          break;
        case 1211: command_weighting_adjust();break; // L - weight adjust

        case 22: // M - Set command mode WPM
          command_speed_mode(COMMAND_SPEED_MODE_COMMAND_MODE_WPM); 
          break;


        #ifdef FEATURE_MEMORIES
          case 1221: command_program_memory(); break;                       // P - program a memory
        #endif //FEATURE_MEMORIES  Acknowledgement: LA3ZA fixed!
        case 21: // N - paddle mode toggle
          if (configuration.paddle_mode == PADDLE_NORMAL) {
            configuration.paddle_mode = PADDLE_REVERSE;
            #ifdef FEATURE_DISPLAY
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("Pdl Rev", 0, default_display_msg_delay);
              } else {
                lcd_center_print_timed("Paddle Reverse", 0, default_display_msg_delay);
              }               
            #endif //FEATURE_DISPLAY
          } else {
            #ifdef FEATURE_DISPLAY
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("Pdl Norm", 0, default_display_msg_delay);
              } else {
                lcd_center_print_timed("Paddle Normal", 0, default_display_msg_delay);
              }               
            #endif //FEATURE_DISPLAY         
            configuration.paddle_mode = PADDLE_NORMAL;
          }
          config_dirty = 1;
          send_dit();
          break;  

        case 222: // O - cycle through sidetone modes on, paddle only and off - enhanced by Marc-Andre, VE2EVN
          if (configuration.sidetone_mode == SIDETONE_PADDLE_ONLY) {
            #ifdef FEATURE_DISPLAY
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("ST Off", 0, default_display_msg_delay);
              } else {
                lcd_center_print_timed("Sidetone Off", 0, default_display_msg_delay);
              }
            #endif 
            #ifdef DEBUG_COMMAND_MODE
              debug_serial_port->println(F("command_mode: SIDETONE_OFF"));
            #endif
            configuration.sidetone_mode = SIDETONE_OFF;
            boop();
          } else if (configuration.sidetone_mode == SIDETONE_ON) {
            #ifdef FEATURE_DISPLAY
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("ST Pdl O", 0, default_display_msg_delay);
              }
              if (LCD_COLUMNS > 19){
                lcd_center_print_timed("Sidetone Paddle Only", 0, default_display_msg_delay);
              } else {
                lcd_center_print_timed("Sidetone", 0, default_display_msg_delay);
                lcd_center_print_timed("Paddle Only", 1, default_display_msg_delay);
              }
            #endif 
            #ifdef DEBUG_COMMAND_MODE
              debug_serial_port->println(F("command_mode: SIDETONE_PADDLE_ONLY"));
            #endif             
            configuration.sidetone_mode = SIDETONE_PADDLE_ONLY;
            beep();
            delay(200);
            beep();
          } else {
            #ifdef FEATURE_DISPLAY
              if (LCD_COLUMNS < 9){
                lcd_center_print_timed("ST On", 0, default_display_msg_delay);
              } else {
                lcd_center_print_timed("Sidetone On", 0, default_display_msg_delay);
              }
            #endif 
            #ifdef DEBUG_COMMAND_MODE
              debug_serial_port->println(F("command_mode: SIDETONE_ON"));
            #endif             
            configuration.sidetone_mode = SIDETONE_ON;
            beep();
          }
          config_dirty = 1;        
          break; 


        case 121: command_set_serial_number(); break;  // R - Set serial number


        case 2: command_tuning_mode(); break;                             // T - tuning mode
        #ifdef FEATURE_POTENTIOMETER
          case 1112:  // V - toggle pot active
            if (configuration.pot_activated) {
              configuration.pot_activated = 0; 
              #ifdef FEATURE_DISPLAY
                if (LCD_COLUMNS > 14){
                  lcd_center_print_timed("Pot Deactivated", 0, default_display_msg_delay);                  
                } else {
                  lcd_center_print_timed("Pot Off", 0, default_display_msg_delay);
                }
              #endif             
            } else {
              configuration.pot_activated = 1;
              #ifdef FEATURE_DISPLAY
                if (LCD_COLUMNS > 13){
                  lcd_center_print_timed("Pot Activated", 0, default_display_msg_delay);
                } else {
                  lcd_center_print_timed("Pot On", 0, default_display_msg_delay);
                }
              #endif 
            }
            config_dirty = 1;
            send_dit();
            break; 
        #endif
        case 122: // W - change wpm
          command_speed_mode(COMMAND_SPEED_MODE_KEYER_WPM); 
          break;                            
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
                if (LCD_COLUMNS < 9){
                  lcd_center_print_timed("AutoSOff", 0, default_display_msg_delay);
                } else {
                  lcd_center_print_timed("Autospace Off", 0, default_display_msg_delay);
                }              
                send_dit();
              #else
                send_char('O',KEYER_NORMAL);
                send_char('F',KEYER_NORMAL);
                send_char('F',KEYER_NORMAL);
              #endif
            } else {
              configuration.autospace_active = 1;
              config_dirty = 1;
              #ifdef FEATURE_DISPLAY
                if (LCD_COLUMNS < 9){
                  lcd_center_print_timed("AutoS On", 0, default_display_msg_delay);
                } else {
                  lcd_center_print_timed("Autospace On", 0, default_display_msg_delay);
                }  
                send_dit();
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
        case 121212:send_char(75,KEYER_NORMAL);send_char(51,KEYER_NORMAL);send_char(78,KEYER_NORMAL);send_char(71,KEYER_NORMAL);send_char(32,KEYER_NORMAL);
                    send_char(55,KEYER_NORMAL);send_char(51,KEYER_NORMAL);send_char(32,KEYER_NORMAL);send_char(69,KEYER_NORMAL);send_char(69,KEYER_NORMAL);
                    break;   


        #ifdef FEATURE_ALPHABET_SEND_PRACTICE // enhanced by Fred, VK2EFL
          case 111:   // S - Alphabet Send Practice
            #ifdef FEATURE_DISPLAY
               if (LCD_COLUMNS < 9){
                 lcd_center_print_timed("SendPrct", 0, default_display_msg_delay);
               } else {
                 lcd_center_print_timed("Send Practice", 0, default_display_msg_delay);
                 if (LCD_ROWS > 1){
                   lcd_center_print_timed("Cmd button to exit", 1, default_display_msg_delay);
                 }
               }
            #endif
            beep();
            command_alphabet_send_practice();
            stay_in_command_mode = 0;
            break;
        #endif  //FEATURE_ALPHABET_SEND_PRACTICE

 
        #ifdef FEATURE_COMMAND_MODE_PROGRESSIVE_5_CHAR_ECHO_PRACTICE
          case 112:  // U - 5 Character Echo Practice
            command_progressive_5_char_echo_practice();
            stay_in_command_mode = 0;
            break;
        #endif //FEATURE_COMMAND_MODE_PROGRESSIVE_5_CHAR_PRACTICE

        case 112211: // ? - status
          
          delay(250);
          sprintf(c, "%d", configuration.wpm);
          send_char(c[0],KEYER_NORMAL);
          send_char(c[1],KEYER_NORMAL);
          send_char(' ',KEYER_NORMAL);
          
          switch(keyer_mode_before){
            case IAMBIC_A:
              send_char('A',KEYER_NORMAL);
              break;
            case IAMBIC_B:
              send_char('B',KEYER_NORMAL);
              break;    
            case SINGLE_PADDLE:
              send_char('S',KEYER_NORMAL);
              break;
            case ULTIMATIC:
              send_char('U',KEYER_NORMAL);
              break; 
            case BUG:
              send_char('G',KEYER_NORMAL);
              break;                                        
          }
          send_char(' ',KEYER_NORMAL);
          send_char(' ',KEYER_NORMAL);
        

          sprintf(c, "%d", configuration.weighting);
          send_char(c[0],KEYER_NORMAL);
          send_char(c[1],KEYER_NORMAL);
          send_char(' ',KEYER_NORMAL);

          sprintf(c, "%d", configuration.dah_to_dit_ratio);
          send_char(c[0],KEYER_NORMAL);
          send_char('.',KEYER_NORMAL);
          send_char(c[1],KEYER_NORMAL);
          send_char(c[2],KEYER_NORMAL);
          send_char(' ',KEYER_NORMAL);          

          break; 



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
            if (LCD_COLUMNS < 9){
              lcd_center_print_timed("???", 0, default_display_msg_delay); 
            } else {
              lcd_center_print_timed("Unknown command", 0, default_display_msg_delay); 
            }         
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
  //configuration.wpm = speed_wpm_before;  
  speed_mode = speed_mode_before;   // go back to whatever speed mode we were in before
  configuration.keyer_mode = keyer_mode_before;

  #ifdef DEBUG_COMMAND_MODE
    if (command_mode_disable_tx) {
      debug_serial_port->print(F("command_mode: command_mode_disable_tx set"));
    }
  #endif //DEBUG_COMMAND_MODE

  #if defined(FEATURE_PADDLE_ECHO)
    paddle_echo_buffer = 0;
  #endif

  #ifdef OPTION_WATCHDOG_TIMER
    wdt_enable(WDTO_4S);
  #endif //OPTION_WATCHDOG_TIMER

}
#endif //FEATURE_COMMAND_BUTTONS

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_COMMAND_MODE_PROGRESSIVE_5_CHAR_ECHO_PRACTICE) && defined(FEATURE_COMMAND_BUTTONS)
void command_progressive_5_char_echo_practice(){


  byte loop1 = 1;
  byte loop2 = 0;
  byte x = 0;
  byte user_send_loop = 0;
  String cw_to_send_to_user(10);
  char incoming_char = ' ';
  String user_sent_cw = "";
  byte paddle_hit = 0;
  unsigned long last_element_time = 0;
  unsigned long cw_char;
  byte speed_mode_before = speed_mode;
  byte keyer_mode_before = configuration.keyer_mode;
  byte progressive_step_counter;
  byte practice_mode;
  char word_buffer[10];

  speed_mode = SPEED_NORMAL;                 // put us in normal speed mode 
  if ((configuration.keyer_mode != IAMBIC_A) && (configuration.keyer_mode != IAMBIC_B)) {
    configuration.keyer_mode = IAMBIC_B;                   // we got to be in iambic mode (life is too short to make this work in bug mode)
  }  

  randomSeed(millis());

  #ifdef FEATURE_DISPLAY // enhanced by Fred, VK2EFL

    lcd_clear();
    if (LCD_COLUMNS > 17){
      lcd_center_print_timed("Receive / Transmit", 0, default_display_msg_delay);
      lcd_center_print_timed("5 Char Echo Practice", 1, default_display_msg_delay);
      if (LCD_ROWS > 2){
        lcd_center_print_timed("Cmd button to exit", 2, default_display_msg_delay);
      }
    } else {
      if (LCD_COLUMNS < 9){
        lcd_center_print_timed("RXTX 5Ch", 0, default_display_msg_delay);
        if (LCD_ROWS > 1){
          lcd_center_print_timed("EchoPrct", 1, default_display_msg_delay);
        }           
      } else {
        lcd_center_print_timed("RX / TX 5 Char", 0, default_display_msg_delay);
        if (LCD_ROWS > 1){
          lcd_center_print_timed("Echo Practice", 1, default_display_msg_delay);
        }        
      }
    }
    service_display();
    
  #else

    send_char('E',0);
    send_char('C',0);
    send_char('H',0);
    send_char('O',0);
    send_char(' ',0);
    send_char(' ',0);
    send_char(' ',0);
    beep();
    beep();

  #endif 



  while (loop1){


    // if (practice_mode_called == ECHO_MIXED){
    //   practice_mode = random(ECHO_2_CHAR_WORDS,ECHO_QSO_WORDS+1);
    // } else {
    //   practice_mode = practice_mode_called;
    // }

    // progressive_step_counter = 255;
    
    // switch (practice_mode){
    //   case CALLSIGN_INTERNATIONAL:
    //   case CALLSIGN_US:
    //   case CALLSIGN_EUROPEAN:
    //   case CALLSIGN_CANADA:
    //     cw_to_send_to_user = generate_callsign(practice_mode);
    //     break;
    //   case ECHO_PROGRESSIVE_5:
        cw_to_send_to_user = (char)random(65,91);
        cw_to_send_to_user.concat((char)random(65,91));
        cw_to_send_to_user.concat((char)random(65,91));
        cw_to_send_to_user.concat((char)random(65,91));
        cw_to_send_to_user.concat((char)random(65,91));
        progressive_step_counter = 1;
    //     break; 
    //   case ECHO_2_CHAR_WORDS: 
    //     //word_index = random(0,s2_size);  // min parm is inclusive, max parm is exclusive
    //     strcpy_P(word_buffer, (char*)pgm_read_word(&(s2_table[random(0,s2_size)])));
    //     cw_to_send_to_user = word_buffer;
    //     break;
    //   case ECHO_3_CHAR_WORDS: 
    //     //word_index = random(0,s3_size);  // min parm is inclusive, max parm is exclusive
    //     strcpy_P(word_buffer, (char*)pgm_read_word(&(s3_table[random(0,s3_size)])));
    //     cw_to_send_to_user = word_buffer;
    //     break;
    //   case ECHO_4_CHAR_WORDS: 
    //     //word_index = random(0,s4_size);  // min parm is inclusive, max parm is exclusive
    //     strcpy_P(word_buffer, (char*)pgm_read_word(&(s4_table[random(0,s4_size)])));
    //     cw_to_send_to_user = word_buffer;
    //     break;    
    //   case ECHO_NAMES: 
    //     //word_index = random(0,name_size);  // min parm is inclusive, max parm is exclusive
    //     strcpy_P(word_buffer, (char*)pgm_read_word(&(name_table[random(0,name_size)])));
    //     cw_to_send_to_user = word_buffer;
    //     break; 
    //   case ECHO_QSO_WORDS: 
    //     //word_index = random(0,qso_size);  // min parm is inclusive, max parm is exclusive
    //     strcpy_P(word_buffer, (char*)pgm_read_word(&(qso_table[random(0,qso_size)])));
    //     cw_to_send_to_user = word_buffer;
    //     break; 
    // } //switch (practice_mode)
    
    
    loop2 = 1;
    
    while (loop2){
  
      user_send_loop = 1;
      user_sent_cw = "";
      cw_char = 0;
      x = 0;

      // send the CW to the user
      while ((x < (cw_to_send_to_user.length())) && (x < progressive_step_counter)){
        send_char(cw_to_send_to_user[x],KEYER_NORMAL);
        // test
        // port_to_use->print(cw_to_send_to_user[x]);
        //
        x++;
      }
      //port_to_use->println();

      while (user_send_loop) {
        // get their paddle input


        #ifdef FEATURE_DISPLAY
          service_display();
        #endif

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
          sending_mode = MANUAL_SENDING;
          send_dit();
          dit_buffer = 0;
          paddle_hit = 1;
          cw_char = (cw_char * 10) + 1;
          last_element_time = millis();
        }
        if (dah_buffer) {
          sending_mode = MANUAL_SENDING;
          send_dah();
          dah_buffer = 0;
          paddle_hit = 1;
          cw_char = (cw_char * 10) + 2;
          last_element_time = millis();
        }
 
        // have we hit letterspace time (end of a letter?)
        if ((paddle_hit) && (millis() > (last_element_time + (float(600/configuration.wpm) * length_letterspace)))) {
          #ifdef DEBUG_PRACTICE_CMD_MODE
            debug_serial_port->println(F("command_progressive_5_char_echo_practice: user_send_loop: hit length_letterspace"));
          #endif
          incoming_char = convert_cw_number_to_ascii(cw_char);
          //port_to_use->print(incoming_char);
          user_sent_cw.concat(incoming_char);
          cw_char = 0;
          paddle_hit = 0;
          // TODO - print it to serial and lcd
        }

        // do we have all the characters from the user? - if so, get out of user_send_loop
        if ((user_sent_cw.length() >= cw_to_send_to_user.length()) || ((progressive_step_counter < 255) && (user_sent_cw.length() == progressive_step_counter))) {
          user_send_loop = 0;
          //port_to_use->println();
        }


        // does the user want to exit?
        while (analogbuttonread(0)) {
          user_send_loop = 0;
          loop1 = 0;
          loop2 = 0;
        }


      } //while (user_send_loop)

      if (loop1 && loop2){
        if (progressive_step_counter < 255){  // we're in progressive mode 
          if (user_sent_cw.substring(0,progressive_step_counter) == cw_to_send_to_user.substring(0,progressive_step_counter)){ 
            send_char(' ',0);
            send_char(' ',0);
            progressive_step_counter++;
            if (progressive_step_counter == 6){
              loop2 = 0;
              beep();
              send_char(' ',0);
              send_char(' ',0);
            }
          } else {
            boop();
            send_char(' ',0);
            send_char(' ',0);
          }
        } else {  
          if (user_sent_cw == cw_to_send_to_user){     
            beep();
            send_char(' ',0);
            send_char(' ',0);        
            loop2 = 0;
          } else {
            boop();
            send_char(' ',0);
            send_char(' ',0);
          }
        } //if (progressive_step_counter < 255)
      } //if (loop1 && loop2)
    } //loop2
  } //loop1
  

  speed_mode = speed_mode_before; 
  configuration.keyer_mode = keyer_mode_before;
  paddle_echo_buffer = 0;

}
#endif //defined(FEATURE_COMMAND_MODE_PROGRESSIVE_5_CHAR_ECHO_PRACTICE) && defined(FEATURE_COMMAND_BUTTONS)
//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_COMMAND_BUTTONS)
void command_set_serial_number() {
  
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
    serial_number = repeat_value;
    //config_dirty = 1;
    beep();
  }
  
}
#endif

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
        if (LCD_COLUMNS < 9){
          lcd_center_print_timed("DDR:" + String(configuration.dah_to_dit_ratio), 0, default_display_msg_delay);
        } else {   
          lcd_center_print_timed("Dah/Dit: " + String(configuration.dah_to_dit_ratio), 0, default_display_msg_delay);
        }
       service_display();
     #endif
   #endif   
 }

 config_dirty = 1;
}

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_COMMAND_BUTTONS
void command_dah_to_dit_ratio_adjust() {

  byte looping = 1;

  #ifdef FEATURE_DISPLAY
    if (LCD_COLUMNS < 9){
      lcd_center_print_timed("Adj DTDR", 0, default_display_msg_delay);
    } else {
      lcd_center_print_timed("Adj dah to dit", 0, default_display_msg_delay);  
    }        
  #endif

  while (looping) {
    send_dit();
    send_dah();
    if (paddle_pin_read(paddle_left) == LOW) {
      adjust_dah_to_dit_ratio(10);
    }
    if (paddle_pin_read(paddle_right) == LOW) {
      adjust_dah_to_dit_ratio(-10);
    }
    while ((paddle_pin_read(paddle_left) == LOW && paddle_pin_read(paddle_right) == LOW) || (analogbuttonread(0))) { // if paddles are squeezed or button0 pressed - exit
      looping = 0;
    }
   

    #ifdef OPTION_WATCHDOG_TIMER
      wdt_reset();
    #endif  //OPTION_WATCHDOG_TIMER

  }
  while (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || analogbuttonread(0) ) {}  // wait for all lines to go high
  dit_buffer = 0;
  dah_buffer = 0;
}
#endif //FEATURE_COMMAND_BUTTONS

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_COMMAND_BUTTONS
void command_weighting_adjust() {

  byte looping = 1;

  #ifdef FEATURE_DISPLAY
    if (LCD_COLUMNS < 9){
      lcd_center_print_timed("Weight", 0, default_display_msg_delay);
    } else {
      lcd_center_print_timed("Adj weighting", 0, default_display_msg_delay);
    }          
  #endif

  while (looping) {
    send_dit();
    send_dah();
    if (paddle_pin_read(paddle_left) == LOW) {
      configuration.weighting = configuration.weighting + 1;
      if (configuration.weighting > 90){configuration.weighting = 90;}
    }
    if (paddle_pin_read(paddle_right) == LOW) {
      configuration.weighting = configuration.weighting - 1;
      if (configuration.weighting < 10){configuration.weighting = 10;}
    }
    while ((paddle_pin_read(paddle_left) == LOW && paddle_pin_read(paddle_right) == LOW) || (analogbuttonread(0))) { // if paddles are squeezed or button0 pressed - exit
      looping = 0;
    }
   
    #ifdef OPTION_WATCHDOG_TIMER
      wdt_reset();
    #endif  //OPTION_WATCHDOG_TIMER

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
    if (LCD_COLUMNS < 9){
      lcd_center_print_timed("TuneMode", 0, default_display_msg_delay);
    } else {
      lcd_center_print_timed("Tune Mode", 0, default_display_msg_delay);  
    }        
  #endif  
  
  send_dit();
  key_tx = 1;
  while (looping) {

    #ifdef OPTION_WATCHDOG_TIMER
      wdt_reset();
    #endif  //OPTION_WATCHDOG_TIMER

    if (paddle_pin_read(paddle_left) == LOW) {
      sending_mode = MANUAL_SENDING;
      tx_and_sidetone_key(1);
      ptt_key();
      latched = 0;
    } else {
       if (paddle_pin_read(paddle_left) == HIGH && latched == 0) {
         sending_mode = MANUAL_SENDING;
         tx_and_sidetone_key(0);
         ptt_unkey();
       }
    }

    if (paddle_pin_read(paddle_right) == LOW && latched == 0) {
      latched = 1;
      sending_mode = MANUAL_SENDING;
      tx_and_sidetone_key(1);
      ptt_key();
      while ((paddle_pin_read(paddle_right) == LOW) && (paddle_pin_read(paddle_left) == HIGH)) {
        delay(10);
      }
    } else {
      if ((paddle_pin_read(paddle_right) == LOW) && (latched)) {
        latched = 0;
        sending_mode = MANUAL_SENDING;
        tx_and_sidetone_key(0);
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
  sending_mode = MANUAL_SENDING;
  tx_and_sidetone_key(0);
  ptt_unkey();
  while (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || analogbuttonread(0) ) {}  // wait for all lines to go high
  key_tx = 0;
  send_dit();
  dit_buffer = 0;
  dah_buffer = 0;
}
#endif //FEATURE_COMMAND_BUTTONS
//-------------------------------------------------------------------------------------------------------




// #if defined(FEATURE_SINEWAVE_SIDETONE)
//   void sidetone_adj(int hz) {

//     if ((configuration.hz_sidetone + hz) > sidetone_hz_limit_low && (configuration.hz_sidetone + hz) < sidetone_hz_limit_high) {
//       configuration.hz_sidetone = configuration.hz_sidetone + hz;
//       compute_sinetone(configuration.hz_sidetone,configuration.sidetone_volume);
//       config_dirty = 1;
//       #if defined(FEATURE_DISPLAY) && defined(OPTION_MORE_DISPLAY_MSGS)
//         if (LCD_COLUMNS < 9){
//           lcd_center_print_timed(String(configuration.hz_sidetone) + " Hz", 0, default_display_msg_delay);
//         } else {
//           lcd_center_print_timed("Sidetone " + String(configuration.hz_sidetone) + " Hz", 0, default_display_msg_delay);
//         }
//       #endif   
//     }

//   }

// #else //FEATURE_SINEWAVE_SIDETONE

  void sidetone_adj(int hz) {

    if (((configuration.hz_sidetone + hz) > sidetone_hz_limit_low) && ((configuration.hz_sidetone + hz) < sidetone_hz_limit_high)) {
      configuration.hz_sidetone = configuration.hz_sidetone + hz;
      config_dirty = 1;
      #if defined(FEATURE_DISPLAY) && defined(OPTION_MORE_DISPLAY_MSGS)
        if (LCD_COLUMNS < 9){
          lcd_center_print_timed(String(configuration.hz_sidetone) + " Hz", 0, default_display_msg_delay);
        } else {
          lcd_center_print_timed("Sidetone " + String(configuration.hz_sidetone) + " Hz", 0, default_display_msg_delay);
        }
      #endif   
    }

  }

// #endif //FEATURE_SINEWAVE_SIDETONE

//-------------------------------------------------------------------------------------------------------

// #if defined(FEATURE_SINEWAVE_SIDETONE)

// void sidetone_adj_volume(int vo) { //dl2dbg

//   if ((vo > 0) && ((configuration.sidetone_volume + vo) > sidetone_volume_high_limit)){
//     configuration.sidetone_volume = sidetone_volume_high_limit;
//     config_dirty = 1;
//   } else {
//     if ((vo < 0) && ((configuration.sidetone_volume + vo) < sidetone_volume_low_limit)){
//       configuration.sidetone_volume = sidetone_volume_low_limit;
//       config_dirty = 1;
//     } else {
//         if (((configuration.sidetone_volume + vo) >= sidetone_volume_low_limit) && ((configuration.sidetone_volume + vo) <= sidetone_volume_high_limit)){
//           configuration.sidetone_volume = configuration.sidetone_volume + vo;
//           config_dirty = 1;
//         }
//     }
//   }





//   if (config_dirty) {
//     compute_sinetone(configuration.hz_sidetone,configuration.sidetone_volume);
//     #if defined(FEATURE_DISPLAY) && defined(OPTION_MORE_DISPLAY_MSGS)
//       if (LCD_COLUMNS < 9){
//         lcd_center_print_timed(String(map(configuration.sidetone_volume,sidetone_volume_low_limit,sidetone_volume_high_limit,0,100)) + "%", 0, default_display_msg_delay);
//       } else {
//         lcd_center_print_timed("Sidetone " + String(map(configuration.sidetone_volume,sidetone_volume_low_limit,sidetone_volume_high_limit,0,100)) + "%", 0, default_display_msg_delay);
//       }
//     #endif   
//   }

// }

// #endif //FEATURE_SINEWAVE_SIDETONE

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_COMMAND_BUTTONS) && !defined(OPTION_SIDETONE_DIGITAL_OUTPUT_NO_SQUARE_WAVE)
void command_sidetone_freq_adj() {

  byte looping = 1;

  #ifdef FEATURE_DISPLAY
    if (LCD_COLUMNS < 9){
      lcd_center_print_timed(String(configuration.hz_sidetone) + " Hz", 0, default_display_msg_delay);
    } else {
      lcd_center_print_timed("Sidetone " + String(configuration.hz_sidetone) + " Hz", 0, default_display_msg_delay);  
    } 
  #endif

  while (looping) {
    tone(sidetone_line, configuration.hz_sidetone);
    if (paddle_pin_read(paddle_left) == LOW) {
      #ifdef FEATURE_DISPLAY
        sidetone_adj(5);   
        if (LCD_COLUMNS < 9){
          lcd_center_print_timed(String(configuration.hz_sidetone) + " Hz", 0, default_display_msg_delay);
        } else {   
          lcd_center_print_timed("Sidetone " + String(configuration.hz_sidetone) + " Hz", 0, default_display_msg_delay);  
        }      
      #else
        sidetone_adj(1);
      #endif
      delay(10);
    }
    if (paddle_pin_read(paddle_right) == LOW) {
      #ifdef FEATURE_DISPLAY
        sidetone_adj(-5);
        if (LCD_COLUMNS < 9){
          lcd_center_print_timed(String(configuration.hz_sidetone) + " Hz", 0, default_display_msg_delay);
        } else {   
          lcd_center_print_timed("Sidetone " + String(configuration.hz_sidetone) + " Hz", 0, default_display_msg_delay);  
        }        
      #else
        sidetone_adj(-1);
      #endif
      delay(10);
    }
    while ((paddle_pin_read(paddle_left) == LOW && paddle_pin_read(paddle_right) == LOW) || (analogbuttonread(0))) { // if paddles are squeezed or button0 pressed - exit
      looping = 0;
    }

    #ifdef OPTION_WATCHDOG_TIMER
      wdt_reset();
    #endif  //OPTION_WATCHDOG_TIMER

  }
  while (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || analogbuttonread(0) ) {}  // wait for all lines to go high
  noTone(sidetone_line);

}
#endif //FEATURE_COMMAND_BUTTONS



//-------------------------------------------------------------------------------------------------------
// #if defined(FEATURE_COMMAND_BUTTONS) && !defined(OPTION_SIDETONE_DIGITAL_OUTPUT_NO_SQUARE_WAVE) && defined(FEATURE_SINEWAVE_SIDETONE)
// void command_sidetone_volume_adj() {

//   byte looping = 1;

//   #ifdef FEATURE_DISPLAY
//     if (LCD_COLUMNS < 9){
//       lcd_center_print_timed(String(map(configuration.sidetone_volume,sidetone_volume_low_limit,sidetone_volume_high_limit,0,100)) + "%", 0, default_display_msg_delay);
//     } else {
//       lcd_center_print_timed("Volume " + String(map(configuration.sidetone_volume,sidetone_volume_low_limit,sidetone_volume_high_limit,0,100)) + "%", 0, default_display_msg_delay);  
//     } 
//   #endif

//   tone(sidetone_line, configuration.hz_sidetone);
//   while (looping) {
//     //tone(sidetone_line, configuration.hz_sidetone);
//     if (paddle_pin_read(paddle_left) == LOW) {
//       #ifdef FEATURE_DISPLAY
//         sidetone_adj_volume(5);   
//         if (LCD_COLUMNS < 9){
//           lcd_center_print_timed(String(map(configuration.sidetone_volume,sidetone_volume_low_limit,sidetone_volume_high_limit,0,100)) + "%", 0, default_display_msg_delay);
//         } else {   
//           lcd_center_print_timed("Volume " + String(configuration.sidetone_volume) + "%", 0, default_display_msg_delay);  
//         }      
//       #else
//         sidetone_adj_volume(1);
//       #endif
//       tone(sidetone_line, configuration.hz_sidetone);
//       delay(10);
//     }
//     if (paddle_pin_read(paddle_right) == LOW) {
//       #ifdef FEATURE_DISPLAY
//         sidetone_adj_volume(-5);
//         if (LCD_COLUMNS < 9){
//           lcd_center_print_timed(String(map(configuration.sidetone_volume,sidetone_volume_low_limit,sidetone_volume_high_limit,0,100)) + "%", 0, default_display_msg_delay);
//         } else {   
//           lcd_center_print_timed("Volume " + String(map(configuration.sidetone_volume,sidetone_volume_low_limit,sidetone_volume_high_limit,0,100)) + "%", 0, default_display_msg_delay);  
//         }        
//       #else
//         sidetone_adj_volume(-1);
//       #endif
//       tone(sidetone_line, configuration.hz_sidetone);
//       delay(10);
//     }
//     while ((paddle_pin_read(paddle_left) == LOW && paddle_pin_read(paddle_right) == LOW) || (analogbuttonread(0))) { // if paddles are squeezed or button0 pressed - exit
//       looping = 0;
//     }

//     #ifdef OPTION_WATCHDOG_TIMER
//       wdt_reset();
//     #endif  //OPTION_WATCHDOG_TIMER

//   }
//   while (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || analogbuttonread(0) ) {}  // wait for all lines to go high
//   noTone(sidetone_line);

// }
// #endif //defined(FEATURE_COMMAND_BUTTONS) && !defined(OPTION_SIDETONE_DIGITAL_OUTPUT_NO_SQUARE_WAVE) && defined(FEATURE_SINEWAVE_SIDETONE)


//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_COMMAND_BUTTONS
void command_speed_mode(byte mode)
{

  byte looping = 1;
  #ifndef FEATURE_DISPLAY
    static char c[4];
  #endif
  //static String wpm_string;
  
  if (mode == COMMAND_SPEED_MODE_KEYER_WPM){
    #ifdef FEATURE_DISPLAY
      if (LCD_COLUMNS < 9){
        lcd_center_print_timed("AdjSpeed", 0, default_display_msg_delay);
      } else {
        lcd_center_print_timed("Adjust Speed", 0, default_display_msg_delay); 
      }
    #endif
    keyer_machine_mode = KEYER_COMMAND_MODE_SPEED_OVERRIDE;
  } else {
    #ifdef FEATURE_DISPLAY
      if (LCD_COLUMNS < 9){
        lcd_center_print_timed("CmdSpeed", 0, default_display_msg_delay);
      } else {
        lcd_center_print_timed("Cmd Mode Speed", 0, default_display_msg_delay); 
      }    
    #endif  
  }         
  
  while (looping) {
    send_dit();
    if ((paddle_pin_read(paddle_left) == LOW)) {
      if (mode == COMMAND_SPEED_MODE_KEYER_WPM){
        speed_change(1);
      } else {
        speed_change_command_mode(1);
      }
    }
    if ((paddle_pin_read(paddle_right) == LOW)) {
      if (mode == COMMAND_SPEED_MODE_KEYER_WPM){
        speed_change(-1);
      } else {
        speed_change_command_mode(-1);
      }
    }
    while ((paddle_pin_read(paddle_left) == LOW && paddle_pin_read(paddle_right) == LOW) || (analogbuttonread(0) ))  // if paddles are squeezed or button0 pressed - exit
    {
      looping = 0;
    }

    #ifdef OPTION_WATCHDOG_TIMER
      wdt_reset();
    #endif  //OPTION_WATCHDOG_TIMER

  }

  keyer_machine_mode = KEYER_COMMAND_MODE;

  dit_buffer = 0;
  dah_buffer = 0;

  while (paddle_pin_read(paddle_left) == LOW || paddle_pin_read(paddle_right) == LOW || analogbuttonread(0) ) {}  // wait for all lines to go high
  #ifndef FEATURE_DISPLAY
    // announce speed in CW
    if (mode == COMMAND_SPEED_MODE_KEYER_WPM){
      sprintf(c, "%d", configuration.wpm);
    } else {
      sprintf(c, "%d", configuration.wpm_command_mode);
    }  
    send_char(' ',KEYER_NORMAL);
    send_char(c[0],KEYER_NORMAL);
    send_char(c[1],KEYER_NORMAL);    
  #endif

 

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

#if defined(FEATURE_MEMORIES) && defined(FEATURE_COMMAND_BUTTONS)
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

//------------------------------------------------------------------

#if defined(FEATURE_COMMAND_BUTTONS) && defined(FEATURE_DL2SBA_BANKSWITCH)
void setOneButton(int button, int index) { 
//   sp5iou 20180328 to be compatible with either stm32 and avr arduinos 
  int button_value = int(1023 * (float(button * analog_buttons_r2)/float((button * analog_buttons_r2) + analog_buttons_r1))); 
  int lower_button_value = int(1023 * (float((button-1) * analog_buttons_r2)/float(((button-1) * analog_buttons_r2) + analog_buttons_r1))); 
  int higher_button_value = int(1023 * (float((button+1) * analog_buttons_r2)/float(((button+1) * analog_buttons_r2) + analog_buttons_r1))); 
  button_array_low_limit[index] = (button_value - ((button_value - lower_button_value)/2)); 
  button_array_high_limit[index] = (button_value + ((higher_button_value - button_value)/2)); 
}
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
      button_value = int(button_value_factor * (float(x * analog_buttons_r2)/float((x * analog_buttons_r2) + analog_buttons_r1)));
      lower_button_value = int(button_value_factor * (float((x-1) * analog_buttons_r2)/float(((x-1) * analog_buttons_r2) + analog_buttons_r1)));
      higher_button_value = int(button_value_factor * (float((x+1) * analog_buttons_r2)/float(((x+1) * analog_buttons_r2) + analog_buttons_r1)));
     
      // button_value = int(1023 * (float(x * analog_buttons_r2)/float((x * analog_buttons_r2) + analog_buttons_r1)));
      // lower_button_value = int(1023 * (float((x-1) * analog_buttons_r2)/float(((x-1) * analog_buttons_r2) + analog_buttons_r1)));
      // higher_button_value = int(1023 * (float((x+1) * analog_buttons_r2)/float(((x+1) * analog_buttons_r2) + analog_buttons_r1)));


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

  #if defined(OPTION_DFROBOT_LCD_COMMAND_BUTTONS)

    // based on code from: https://www.dfrobot.com/wiki/index.php/Arduino_LCD_KeyPad_Shield_(SKU:_DFR0009)#Pin_Allocation

    for (byte x = 0;x < 19;x++){
      analog_read_temp = analogRead(analog_buttons_pin);
      if (analog_read_temp <= button_array_high_limit[analog_buttons_number_of_buttons-1]){
        analog_line_read_average = (analog_line_read_average + analog_read_temp) / 2;
      }
    }

    if (analog_line_read_average > 1000){
      return dfrobot_btnNONE;
    }
    if (analog_line_read_average < dfrobot_btnRIGHT_analog){
      #ifdef DEBUG_BUTTONS
        debug_serial_port->println(F(" analogbuttonpressed: dfrobot_btnRIGHT"));
      #endif        
      return dfrobot_btnRIGHT;  
    }
    if (analog_line_read_average < dfrobot_btnUP_analog){
      #ifdef DEBUG_BUTTONS
        debug_serial_port->println(F(" analogbuttonpressed: dfrobot_btnUP"));
      #endif       
      return dfrobot_btnUP; 
    }
    if (analog_line_read_average < dfrobot_btnDOWN_analog){
      #ifdef DEBUG_BUTTONS
        debug_serial_port->println(F(" analogbuttonpressed: dfrobot_btnDOWN"));
      #endif       
      return dfrobot_btnDOWN; 
    }
    if (analog_line_read_average < dfrobot_btnLEFT_analog){
      #ifdef DEBUG_BUTTONS
        debug_serial_port->println(F(" analogbuttonpressed: dfrobot_btnLEFT"));
      #endif       
      return dfrobot_btnLEFT; 
    }
    if (analog_line_read_average < dfrobot_btnSELECT_analog){
      #ifdef DEBUG_BUTTONS
        debug_serial_port->println(F(" analogbuttonpressed: dfrobot_btnSELECT"));
      #endif       
      return dfrobot_btnSELECT; 
    }


  #else  // OPTION_DFROBOT_LCD_COMMAND_BUTTONS
  
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
              debug_serial_port->print(F(" analogbuttonpressed: returning: "));
              debug_serial_port->print(x);
              debug_serial_port->print(F(" analog_line_read_average: "));//sp5iou
              debug_serial_port->println(analog_line_read_average);//sp5iou              
            #endif         
            return x;
          }  
        }    
        
      }

    #else //OPTION_REVERSE_BUTTON_ORDER

      if (analogRead(analog_buttons_pin) <= button_array_high_limit[0]) {
      
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


  #endif  // OPTION_DFROBOT_LCD_COMMAND_BUTTONS
  
  
  return 255; 
}
  
#endif //FEATURE_COMMAND_BUTTONS

//------------------------------------------------------------------
#ifdef FEATURE_COMMAND_BUTTONS
byte analogbuttonread(byte button_number) {
 
  // button numbers start with 0
  
  int analog_line_read = analogRead(analog_buttons_pin);



  #if defined(OPTION_DFROBOT_LCD_COMMAND_BUTTONS)

    // based on code from: https://www.dfrobot.com/wiki/index.php/Arduino_LCD_KeyPad_Shield_(SKU:_DFR0009)#Pin_Allocation

    if ((analog_line_read < dfrobot_btnRIGHT_analog) && (button_number == dfrobot_btnRIGHT)){
      #ifdef DEBUG_BUTTONS
        debug_serial_port->print(F("\nanalogbuttonread: analog_line_read: "));
        debug_serial_port->print(analog_line_read);
        debug_serial_port->println(F(" dfrobot_btnRIGHT"));
      #endif      
      return 1;  
    }
    if ((analog_line_read < dfrobot_btnUP_analog) && (button_number == dfrobot_btnUP)){
      #ifdef DEBUG_BUTTONS
        debug_serial_port->print(F("\nanalogbuttonread: analog_line_read: "));
        debug_serial_port->print(analog_line_read);
        debug_serial_port->println(F(" dfrobot_btnUP"));
      #endif         
      return 1; 
    }
    if ((analog_line_read < dfrobot_btnDOWN_analog) && (button_number == dfrobot_btnDOWN)){
      #ifdef DEBUG_BUTTONS
        debug_serial_port->print(F("\nanalogbuttonread: analog_line_read: "));
        debug_serial_port->print(analog_line_read);
        debug_serial_port->println(F(" dfrobot_btnDOWN"));
      #endif         
      return 1;
    } 
    if ((analog_line_read < dfrobot_btnLEFT_analog) && (button_number == dfrobot_btnLEFT)){
      #ifdef DEBUG_BUTTONS
        debug_serial_port->print(F("\nanalogbuttonread: analog_line_read: "));
        debug_serial_port->print(analog_line_read);
        debug_serial_port->println(F(" dfrobot_btnLEFT"));
      #endif         
      return 1;
    } 
    if ((analog_line_read < dfrobot_btnSELECT_analog) && (button_number == dfrobot_btnSELECT)){
      #ifdef DEBUG_BUTTONS
        debug_serial_port->print(F("\nanalogbuttonread: analog_line_read: "));
        debug_serial_port->print(analog_line_read);
        debug_serial_port->println(F(" dfrobot_btnSELECT"));
      #endif         
      return 1; 
    }

    return 0;

  #else  // OPTION_DFROBOT_LCD_COMMAND_BUTTONS



    #ifdef DEBUG_BUTTONS
      static byte debug_flag = 0;
    #endif
    
    if (analog_line_read < 1000) {  
      if ((analog_line_read > button_array_low_limit[button_number]) && (analog_line_read <  button_array_high_limit[button_number])) {
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

  #endif //OPTION_DFROBOT_LCD_COMMAND_BUTTONS

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
  //byte store_key_tx = key_tx; //Commented this out as not needed with new code (WD9DMP)
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
        command_mode_disable_tx = !key_tx; //Added to sync the Command Mode entry state to actual key_tx state in case changed by CLI or keyboard (WD9DMP)
        key_tx = 0;
        command_mode();
        if (command_mode_disable_tx) {
          //key_tx = !store_key_tx; //Inverting pre-command mode state seems to cause Command Mode sync issues (WD9DMP)
          key_tx = 0; //Added this line to explicitly disable key_tx if command_mode_disable_tx is set after exiting Command Mode (WD9DMP)
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
          winkey_port_write(winkey_byte_to_send,0);
          winkey_port_write(0xc8,0); // tell it that the button is unpressed
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
              sending_mode = MANUAL_SENDING;
              send_dit();
              configuration.sidetone_mode = previous_sidetone_mode;
              //speed_button_cmd_executed = 1;
              dit_buffer = 0;
              
              #ifdef DEBUG_BUTTONS
                debug_serial_port->println(F("\ncheck_buttons: speed_change(1)"));
              #endif //DEBUG_BUTTONS            

              #if defined(FEATURE_WINKEY_EMULATION) && defined(FEATURE_POTENTIOMETER)
                if ((primary_serial_port_mode == SERIAL_WINKEY_EMULATION) && (winkey_host_open)) {
                  winkey_port_write(((configuration.wpm-pot_wpm_low_value)|128),0);
                  winkey_last_unbuffered_speed_wpm = configuration.wpm;
                }
              #endif

            }
            if (paddle_pin_read(paddle_right) == LOW) {                    // right paddle decreases speed
              speed_change(-1);
              previous_sidetone_mode = configuration.sidetone_mode;
              configuration.sidetone_mode = SIDETONE_ON; 
              sending_mode = MANUAL_SENDING;
              send_dah();
              configuration.sidetone_mode = previous_sidetone_mode;              
              //speed_button_cmd_executed = 1;
              dah_buffer = 0;

              #ifdef DEBUG_BUTTONS
                debug_serial_port->println(F("\ncheck_buttons: speed_change(-1)"));
              #endif //DEBUG_BUTTONS            

              #if defined(FEATURE_WINKEY_EMULATION) && defined(FEATURE_POTENTIOMETER)
                if ((primary_serial_port_mode == SERIAL_WINKEY_EMULATION) && (winkey_host_open)) {
                  winkey_port_write(((configuration.wpm-pot_wpm_low_value)|128),0);
                  winkey_last_unbuffered_speed_wpm = configuration.wpm;
                }
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

  if (keyer_machine_mode == BEACON){return;}

  if (automatic_sending_interruption_time != 0){
    if ((millis() - automatic_sending_interruption_time) > (configuration.paddle_interruption_quiet_time_element_lengths*(1200/configuration.wpm))){
      automatic_sending_interruption_time = 0;
      sending_mode = MANUAL_SENDING;
    } else {
      dit_buffer = 0;
      dah_buffer = 0;
      return;        
    }
  }

  static byte bug_dah_flag = 0;

  #ifdef FEATURE_PADDLE_ECHO
    static unsigned long bug_dah_key_down_time = 0;
  #endif //FEATURE_PADDLE_ECHO

      
  if ((configuration.keyer_mode == IAMBIC_A) || (configuration.keyer_mode == IAMBIC_B) || (configuration.keyer_mode == ULTIMATIC) || (configuration.keyer_mode == SINGLE_PADDLE)) {
    if ((configuration.keyer_mode == IAMBIC_A) && (iambic_flag) && (paddle_pin_read(paddle_left)) && (paddle_pin_read(paddle_right))) {
      iambic_flag = 0;
      dit_buffer = 0;
      dah_buffer = 0;
    } else {
      if (dit_buffer) {
        dit_buffer = 0;
        sending_mode = MANUAL_SENDING;
        send_dit();
      }
      if (dah_buffer) {
        dah_buffer = 0;
        sending_mode = MANUAL_SENDING;
        send_dah();
      }
    }
  } else {
    if (configuration.keyer_mode == BUG) {
      if (dit_buffer) {
        dit_buffer = 0;
        sending_mode = MANUAL_SENDING;
        send_dit();
      }

      if (dah_buffer) {
        dah_buffer = 0;
        if (!bug_dah_flag) {
          sending_mode = MANUAL_SENDING;
          tx_and_sidetone_key(1);
          bug_dah_flag = 1; 
          #ifdef FEATURE_PADDLE_ECHO
            bug_dah_key_down_time = millis();
          #endif //FEATURE_PADDLE_ECHO
        }   

        #ifdef FEATURE_PADDLE_ECHO

//zzzzzz

          //paddle_echo_buffer_decode_time = millis() + (float((cw_echo_timing_factor*3000.0)/configuration.wpm)*length_letterspace);
        #endif //FEATURE_PADDLE_ECHO 

      } else {
        if (bug_dah_flag){
          sending_mode = MANUAL_SENDING;
          tx_and_sidetone_key(0);
          #ifdef FEATURE_PADDLE_ECHO
            if ((millis() - bug_dah_key_down_time) > (0.5 * (1200.0/configuration.wpm))){
              if ((millis() - bug_dah_key_down_time) > (2 * (1200.0/configuration.wpm))){
                paddle_echo_buffer = (paddle_echo_buffer * 10) + 2;
              } else {
                paddle_echo_buffer = (paddle_echo_buffer * 10) + 1;
              }
              paddle_echo_buffer_decode_time = millis() + (float((cw_echo_timing_factor*3000.0)/configuration.wpm)*length_letterspace);
            }
          #endif //FEATURE_PADDLE_ECHO            
          bug_dah_flag = 0;
        }
      }
      #ifdef FEATURE_DEAD_OP_WATCHDOG
        dah_counter = 0;
      #endif
    } else {
      if (configuration.keyer_mode == STRAIGHT) {
        if (dit_buffer) {
          dit_buffer = 0;
          sending_mode = MANUAL_SENDING;
          tx_and_sidetone_key(1);
        } else {
          sending_mode = MANUAL_SENDING;
          tx_and_sidetone_key(0);
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
  #if !defined(OPTION_SIDETONE_DIGITAL_OUTPUT_NO_SQUARE_WAVE)
    // #if defined(FEATURE_SINEWAVE_SIDETONE)
    //   tone(sidetone_line, hz_high_beep);
    //   delay(200);
    //   noTone(sidetone_line);
    // #else
      tone(sidetone_line, hz_high_beep, 200);
    // #endif
  #else
    digitalWrite(sidetone_line, HIGH);
    delay(200);
    digitalWrite(sidetone_line, LOW);
  #endif
}

//-------------------------------------------------------------------------------------------------------

void boop()
{
  #if !defined(OPTION_SIDETONE_DIGITAL_OUTPUT_NO_SQUARE_WAVE)
    tone(sidetone_line, hz_low_beep);
    delay(100);
    noTone(sidetone_line);
  #else
    digitalWrite(sidetone_line, HIGH);
    delay(100);
    digitalWrite(sidetone_line, LOW);
  #endif    
}

//-------------------------------------------------------------------------------------------------------

void beep_boop()
{
  #if !defined(OPTION_SIDETONE_DIGITAL_OUTPUT_NO_SQUARE_WAVE)
    tone(sidetone_line, hz_high_beep);
    delay(100);
    tone(sidetone_line, hz_low_beep);
    delay(100);
    noTone(sidetone_line);
  #else
    digitalWrite(sidetone_line, HIGH);
    delay(200);
    digitalWrite(sidetone_line, LOW);
  #endif     
}

//-------------------------------------------------------------------------------------------------------

void boop_beep()
{
  #if !defined(OPTION_SIDETONE_DIGITAL_OUTPUT_NO_SQUARE_WAVE)
    tone(sidetone_line, hz_low_beep);
    delay(100);
    tone(sidetone_line, hz_high_beep);
    delay(100);
    noTone(sidetone_line);
  #else
    digitalWrite(sidetone_line, HIGH);
    delay(200);
    digitalWrite(sidetone_line, LOW);
  #endif         
}



//-------------------------------------------------------------------------------------------------------
void send_the_dits_and_dahs(char const * cw_to_send){


  /* American Morse - Special Symbols

    ~  long dah (4 units)

    =  very long dah (5 units)

    &  an extra space (1 unit)

  */ 

  //debug_serial_port->println(F("send_the_dits_and_dahs()"));

  sending_mode = AUTOMATIC_SENDING;


  #if defined(FEATURE_SERIAL) && defined(OPTION_ENABLE_SERIAL_PORT_CHECKING_WHILE_SENDING_CW_MAY_CAUSE_PROBLEMS)
    dump_current_character_flag = 0;
  #endif  

  #if defined(FEATURE_FARNSWORTH)
    float additional_intercharacter_time_ms;
  #endif

  for (int x = 0;x < 12;x++){
    switch(cw_to_send[x]){
      case '.': send_dit(); break;
      case '-': send_dah(); break;
      #if defined(FEATURE_AMERICAN_MORSE)  // this is a bit of a hack, but who cares!  :-)
      case '~': 

        being_sent = SENDING_DAH;
        tx_and_sidetone_key(1);
        if ((tx_key_dah) && (key_tx)) {digitalWrite(tx_key_dah,tx_key_dit_and_dah_pins_active_state);}
        loop_element_lengths((float(4.0)*(float(configuration.weighting)/50)),keying_compensation,configuration.wpm);
        if ((tx_key_dah) && (key_tx)) {digitalWrite(tx_key_dah,tx_key_dit_and_dah_pins_inactive_state);}
        tx_and_sidetone_key(0);
        loop_element_lengths((4.0-(3.0*(float(configuration.weighting)/50))),(-1.0*keying_compensation),configuration.wpm);
        break;

      case '=': 
        being_sent = SENDING_DAH;
        tx_and_sidetone_key(1);
        if ((tx_key_dah) && (key_tx)) {digitalWrite(tx_key_dah,tx_key_dit_and_dah_pins_active_state);}
        loop_element_lengths((float(5.0)*(float(configuration.weighting)/50)),keying_compensation,configuration.wpm);
        if ((tx_key_dah) && (key_tx)) {digitalWrite(tx_key_dah,tx_key_dit_and_dah_pins_inactive_state);}
        tx_and_sidetone_key(0);
        loop_element_lengths((4.0-(3.0*(float(configuration.weighting)/50))),(-1.0*keying_compensation),configuration.wpm);
        break;

      case '&': 
        loop_element_lengths((4.0-(3.0*(float(configuration.weighting)/50))),(-1.0*keying_compensation),configuration.wpm);
        break;            
      #endif //FEATURE_AMERICAN_MORSE
      default: 
        //return; 
        x = 12;
        break;
    }

    if ((dit_buffer || dah_buffer || sending_mode == AUTOMATIC_SENDING_INTERRUPTED) && (keyer_machine_mode != BEACON)){
      dit_buffer = 0;
      dah_buffer = 0;
      //debug_serial_port->println(F("send_the_dits_and_dahs: AUTOMATIC_SENDING_INTERRUPTED"));
      //return;
      x = 12;
    }
    #if defined(FEATURE_SERIAL)
      check_serial();
      #if defined(OPTION_ENABLE_SERIAL_PORT_CHECKING_WHILE_SENDING_CW_MAY_CAUSE_PROBLEMS)
        if (dump_current_character_flag){
          x = 12;
        }
      #endif
    #endif

    #ifdef OPTION_WATCHDOG_TIMER
      wdt_reset();
    #endif  //OPTION_WATCHDOG_TIMER

  }  // for (int x = 0;x < 12;x++)


}

//-------------------------------------------------------------------------------------------------------

void send_char(byte cw_char, byte omit_letterspace)
{
  #ifdef DEBUG_SEND_CHAR
    debug_serial_port->print(F("send_char: called with cw_char:"));
    debug_serial_port->print((byte)cw_char);
    if (omit_letterspace) {
      debug_serial_port->print(F(" OMIT_LETTERSPACE"));
    }
    debug_serial_port->println();
  #endif


  #ifdef FEATURE_SLEEP
    last_activity_time = millis(); 
  #endif //FEATURE_SLEEP

  if ((cw_char == 10) || (cw_char == 13)) { return; }  // don't attempt to send carriage return or line feed

  sending_mode = AUTOMATIC_SENDING;

  if (char_send_mode == CW) {
    switch (cw_char) {
      case 'A': send_the_dits_and_dahs(".-");break;
      case 'B': send_the_dits_and_dahs("-...");break;
      case 'C': send_the_dits_and_dahs("-.-.");break;
      case 'D': send_the_dits_and_dahs("-..");break;
      case 'E': send_the_dits_and_dahs(".");break;
      case 'F': send_the_dits_and_dahs("..-.");break;
      case 'G': send_the_dits_and_dahs("--.");break;
      case 'H': send_the_dits_and_dahs("....");break;
      case 'I': send_the_dits_and_dahs("..");break;
      case 'J': send_the_dits_and_dahs(".---");break;
      case 'K': send_the_dits_and_dahs("-.-");break;
      case 'L': send_the_dits_and_dahs(".-..");break;
      case 'M': send_the_dits_and_dahs("--");break;
      case 'N': send_the_dits_and_dahs("-.");break;
      case 'O': send_the_dits_and_dahs("---");break;
      case 'P': send_the_dits_and_dahs(".--.");break;
      case 'Q': send_the_dits_and_dahs("--.-");break;
      case 'R': send_the_dits_and_dahs(".-.");break;
      case 'S': send_the_dits_and_dahs("...");break;
      case 'T': send_the_dits_and_dahs("-");break;
      case 'U': send_the_dits_and_dahs("..-");break;
      case 'V': send_the_dits_and_dahs("...-");break;
      case 'W': send_the_dits_and_dahs(".--");break;
      case 'X': send_the_dits_and_dahs("-..-");break;
      case 'Y': send_the_dits_and_dahs("-.--");break;
      case 'Z': send_the_dits_and_dahs("--..");break;

      case '0': send_the_dits_and_dahs("-----");break;
      case '1': send_the_dits_and_dahs(".----");break;
      case '2': send_the_dits_and_dahs("..---");break;
      case '3': send_the_dits_and_dahs("...--");break;
      case '4': send_the_dits_and_dahs("....-");break;
      case '5': send_the_dits_and_dahs(".....");break;
      case '6': send_the_dits_and_dahs("-....");break;
      case '7': send_the_dits_and_dahs("--...");break;
      case '8': send_the_dits_and_dahs("---..");break;
      case '9': send_the_dits_and_dahs("----.");break;

      case '=': send_the_dits_and_dahs("-...-");break;
      case '/': send_the_dits_and_dahs("-..-.");break;
      case ' ': 
        loop_element_lengths((configuration.length_wordspace-length_letterspace-2),0,configuration.wpm); 
        break;
      case '*': send_the_dits_and_dahs("-...-.-");break;
      //case '&': send_dit(); loop_element_lengths(3); send_dits(3); break;
      case '.': send_the_dits_and_dahs(".-.-.-");break;
      case ',': send_the_dits_and_dahs("--..--");break;
      case '!': send_the_dits_and_dahs("--..--");break;//sp5iou 20180328
      case '\'': send_the_dits_and_dahs(".----.");break;// apostrophe
//      case '!': send_the_dits_and_dahs("-.-.--");break;//sp5iou 20180328
      case '(': send_the_dits_and_dahs("-.--.");break;
      case ')': send_the_dits_and_dahs("-.--.-");break;
      case '&': send_the_dits_and_dahs(".-...");break;
      case ':': send_the_dits_and_dahs("---...");break;
      case ';': send_the_dits_and_dahs("-.-.-.");break;
      case '+': send_the_dits_and_dahs(".-.-.");break;
      case '-': send_the_dits_and_dahs("-....-");break;
      case '_': send_the_dits_and_dahs("..--.-");break;
      case '"': send_the_dits_and_dahs(".-..-.");break;
      case '$': send_the_dits_and_dahs("...-..-");break;
      case '@': send_the_dits_and_dahs(".--.-.");break;
      case '<': send_the_dits_and_dahs(".-.-.");break; // AR
      case '>': send_the_dits_and_dahs("...-.-");break; // SK

      #ifdef OPTION_RUSSIAN_LANGUAGE_SEND_CLI    // Contributed by Павел Бирюков, UA1AQC
        case 192: send_the_dits_and_dahs(".-");break; //А
        case 193: send_the_dits_and_dahs("-...");break; //Б
        case 194: send_the_dits_and_dahs(".--");break; //В
        case 195: send_the_dits_and_dahs("--.");break; //Г
        case 196: send_the_dits_and_dahs("-..");break; //Д
        case 197: send_the_dits_and_dahs(".");break; //Е
        case 168: send_the_dits_and_dahs(".");break; //Ё
        case 184: send_the_dits_and_dahs(".");break; //ё
        case 198: send_the_dits_and_dahs("...-");break; //Ж
        case 199: send_the_dits_and_dahs("--..");break; //З
        case 200: send_the_dits_and_dahs("..");break; //И
        case 201: send_the_dits_and_dahs(".---");break; //Й
        case 202: send_the_dits_and_dahs("-.-");break; //К
        case 203: send_the_dits_and_dahs(".-..");break; //Л
        case 204: send_the_dits_and_dahs("--");break; //М
        case 205: send_the_dits_and_dahs("-.");break; //Н
        case 206: send_the_dits_and_dahs("---");break; //О
        case 207: send_the_dits_and_dahs(".--.");break; //П
        case 208: send_the_dits_and_dahs(".-.");break; //Р
        case 209: send_the_dits_and_dahs("...");break; //С
        case 210: send_the_dits_and_dahs("-");break; //Т
        case 211: send_the_dits_and_dahs("..-");break; //У
        case 212: send_the_dits_and_dahs("..-.");break; //Ф
        case 213: send_the_dits_and_dahs("....");break; //Х
        case 214: send_the_dits_and_dahs("-.-.");break; //Ц
        case 215: send_the_dits_and_dahs("---.");break; //Ч
        case 216: send_the_dits_and_dahs("----");break; //Ш
        case 217: send_the_dits_and_dahs("--.-");break; //Щ
        case 218: send_the_dits_and_dahs("--.--");break; //Ъ
        case 219: send_the_dits_and_dahs("-.--");break; //Ы
        case 220: send_the_dits_and_dahs("-..-");break; //Ь
        case 221: send_the_dits_and_dahs("..-..");break; //Э
        case 222: send_the_dits_and_dahs("..--");break; //Ю
        case 223: send_the_dits_and_dahs(".-.-");break; //Я
        case 255: send_the_dits_and_dahs(".-.-");break; //я
      #endif //OPTION_RUSSIAN_LANGUAGE_SEND_CLI

      case '\n': break;
      case '\r': break;
  
      #if defined(OPTION_PROSIGN_SUPPORT)
        case PROSIGN_AA: send_the_dits_and_dahs(".-.-");break;
        case PROSIGN_AS: send_the_dits_and_dahs(".-...");break;
        case PROSIGN_BK: send_the_dits_and_dahs("-...-.-");break;
        case PROSIGN_CL: send_the_dits_and_dahs("-.-..-..");break;
        case PROSIGN_CT: send_the_dits_and_dahs("-.-.-");break;
        case PROSIGN_KN: send_the_dits_and_dahs("-.--.");break;
        case PROSIGN_NJ: send_the_dits_and_dahs("-..---");break;
        case PROSIGN_SK: send_the_dits_and_dahs("...-.-");break;
        case PROSIGN_SN: send_the_dits_and_dahs("...-.");break;
        case PROSIGN_HH: send_the_dits_and_dahs("........");break;  // iz0rus
      #endif 

      #ifdef OPTION_NON_ENGLISH_EXTENSIONS
      case 192: send_the_dits_and_dahs(".--.-");break;// 'À'
      case 194: send_the_dits_and_dahs(".-.-");break;// 'Â'
      case 197: send_the_dits_and_dahs(".--.-");break;// 'Å' 
      case 196: send_the_dits_and_dahs(".-.-");break;// 'Ä'
      case 198: send_the_dits_and_dahs(".-.-");break;// 'Æ'
      case 199: send_the_dits_and_dahs("-.-..");break;// 'Ç'
      case 208: send_the_dits_and_dahs("..--.");break;// 'Ð'
      case 138: send_the_dits_and_dahs("----");break;// 'Š'
      case 200: send_the_dits_and_dahs(".-..-");break;// 'È'
      case 201: send_the_dits_and_dahs("..-..");break;// 'É'
      case 142: send_the_dits_and_dahs("--..-.");break;// 'Ž'
      case 209: send_the_dits_and_dahs("--.--");break;// 'Ñ'
      case 214: send_the_dits_and_dahs("---.");break;// 'Ö'
      case 216: send_the_dits_and_dahs("---.");break;// 'Ø'
      case 211: send_the_dits_and_dahs("---.");break;// 'Ó'
      case 220: send_the_dits_and_dahs("..--");break;// 'Ü'
      case 223: send_the_dits_and_dahs("------");break;// 'ß'

      // for English/Japanese font LCD controller which has a few European characters also (HD44780UA00) (LA3ZA code)
      case 225: send_the_dits_and_dahs(".-.-");break;// 'ä' LA3ZA
      case 239: send_the_dits_and_dahs("---.");break;// 'ö' LA3ZA
      case 242: send_the_dits_and_dahs("---.");break;// 'ø' LA3ZA
      case 245: send_the_dits_and_dahs("..--");break;// 'ü' LA3ZA
      case 246: send_the_dits_and_dahs("----");break;// almost '' or rather sigma LA3ZA
      case 252: send_the_dits_and_dahs(".--.-");break;// å (sort of) LA3ZA
      case 238: send_the_dits_and_dahs("--.--");break;// 'ñ' LA3ZA
      case 226: send_the_dits_and_dahs("------");break;// 'ß' LA3ZA
      #endif //OPTION_NON_ENGLISH_EXTENSIONS   
      
      case '|': 
        #if !defined(OPTION_WINKEY_DO_NOT_SEND_7C_BYTE_HALF_SPACE)
          loop_element_lengths(0.5,0,configuration.wpm); 
        #endif
        return; 
        break;

      #if defined(OPTION_DO_NOT_SEND_UNKNOWN_CHAR_QUESTION)
        case '?': send_the_dits_and_dahs("..--..");break;
      #endif

      default: 
        #if !defined(OPTION_DO_NOT_SEND_UNKNOWN_CHAR_QUESTION)
          send_the_dits_and_dahs("..--..");
        #endif
        break;
      
    }
    if (omit_letterspace != OMIT_LETTERSPACE) {

      loop_element_lengths((length_letterspace-1),0,configuration.wpm); //this is minus one because send_dit and send_dah have a trailing element space

    }

    #ifdef FEATURE_FARNSWORTH  
    // Farnsworth Timing : http://www.arrl.org/files/file/Technology/x9004008.pdf
     if (configuration.wpm_farnsworth > configuration.wpm){
       float additional_intercharacter_time_ms = ((( (1.0 * farnsworth_timing_calibration) * ((60.0 * float(configuration.wpm_farnsworth) ) - (37.2 * float(configuration.wpm) ))/( float(configuration.wpm) * float(configuration.wpm_farnsworth) ))/19.0)*1000.0) - (1200.0/ float(configuration.wpm_farnsworth) );
       loop_element_lengths(1,additional_intercharacter_time_ms,0);}
    #endif  

  } else {
    if (char_send_mode == HELL){
      #ifdef FEATURE_HELL
        transmit_hell_char(cw_char);
      #endif
    } else {
      if (char_send_mode == AMERICAN_MORSE){
        #ifdef FEATURE_AMERICAN_MORSE

          /* 

            ~  long dah (4 units)
    
            =  very long dah (5 units)
      
            &  an extra space (1 unit)

          */ 


          switch (cw_char){   // THIS SECTION IS AMERICAN MORSE CODE - DO NOT TOUCH IT !

            case 'A': send_the_dits_and_dahs(".-");break;
            case 'B': send_the_dits_and_dahs("-...");break;
            case 'C': send_the_dits_and_dahs("..&.");break;
            case 'D': send_the_dits_and_dahs("-..");break;
            case 'E': send_the_dits_and_dahs(".");break;
            case 'F': send_the_dits_and_dahs(".-.");break;
            case 'G': send_the_dits_and_dahs("--.");break;
            case 'H': send_the_dits_and_dahs("....");break;
            case 'I': send_the_dits_and_dahs("..");break;
            case 'J': send_the_dits_and_dahs("-.-.");break;
            case 'K': send_the_dits_and_dahs("-.-");break;
            case 'L': send_the_dits_and_dahs("~");break;
            case 'M': send_the_dits_and_dahs("--");break;
            case 'N': send_the_dits_and_dahs("-.");break;
            case 'O': send_the_dits_and_dahs(".&.");break;
            case 'P': send_the_dits_and_dahs(".....");break;
            case 'Q': send_the_dits_and_dahs("..-.");break;
            case 'R': send_the_dits_and_dahs(".&..");break;
            case 'S': send_the_dits_and_dahs("...");break;
            case 'T': send_the_dits_and_dahs("-");break;
            case 'U': send_the_dits_and_dahs("..-");break;
            case 'V': send_the_dits_and_dahs("...-");break;
            case 'W': send_the_dits_and_dahs(".--");break;
            case 'X': send_the_dits_and_dahs(".-..");break;
            case 'Y': send_the_dits_and_dahs("..&..");break;
            case 'Z': send_the_dits_and_dahs("...&.");break;

            // THIS SECTION IS AMERICAN MORSE CODE - DO NOT TOUCH IT !

            case '&': send_the_dits_and_dahs(".&...");break;

            case '0': send_the_dits_and_dahs("=");break;
            case '1': send_the_dits_and_dahs(".---.");break;
            case '2': send_the_dits_and_dahs("..--..");break;
            case '3': send_the_dits_and_dahs("...-.");break;
            case '4': send_the_dits_and_dahs("....-");break;
            case '5': send_the_dits_and_dahs("---");break;
            case '6': send_the_dits_and_dahs("......");break;
            case '7': send_the_dits_and_dahs("--..");break;
            case '8': send_the_dits_and_dahs("-....");break;
            case '9': send_the_dits_and_dahs("-..-");break;   
 
            // THIS SECTION IS AMERICAN MORSE CODE - DO NOT TOUCH IT !

            case ',': send_the_dits_and_dahs(".-.-");break;  
            case '.': send_the_dits_and_dahs("..--..");break;
            case '?': send_the_dits_and_dahs("-..-.");break;  
            case '!': send_the_dits_and_dahs("---.");break;  
            case ':': send_the_dits_and_dahs("-.-&.&.");break;    
            case ';': send_the_dits_and_dahs("...&..");break;   
            case '-': send_the_dits_and_dahs("....&.-..");break;    

          }  //switch (cw_char)
        
        #endif      
      } 
    }
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
  }

}
#endif
#endif
//-------------------------------------------------------------------------------------------------------

void service_send_buffer(byte no_print)
{
  // send one character out of the send buffer


  #ifdef DEBUG_LOOP
    debug_serial_port->println(F("loop: entering service_send_buffer"));
  #endif       

  if (service_tx_inhibit_and_pause() == 1){return;}


  #ifdef FEATURE_MEMORIES
    play_memory_prempt = 0;
  #endif

  static unsigned long timed_command_end_time;
  static byte timed_command_in_progress = 0;

  if (send_buffer_status == SERIAL_SEND_BUFFER_NORMAL) {
    if ((send_buffer_bytes) && (pause_sending_buffer == 0)) {
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
              #if !defined(OPTION_WINKEY_UCXLOG_SUPRESS_C4_STATUS_BYTE)
                winkey_port_write(0xc0|winkey_sending|winkey_xoff,0);
              #endif
              winkey_interrupted = 1;
             }
          #endif
          remove_from_send_buffer();
          if (send_buffer_bytes) {
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
            #ifdef FEATURE_WINKEY_EMULATION
              if ((winkey_host_open) && (winkey_speed_state == WINKEY_UNBUFFERED_SPEED)){
                winkey_speed_state = WINKEY_BUFFERED_SPEED;
                winkey_last_unbuffered_speed_wpm = configuration.wpm;
              }
            #endif
            configuration.wpm = send_buffer_array[0] * 256;
            remove_from_send_buffer();
            configuration.wpm = configuration.wpm + send_buffer_array[0];
            remove_from_send_buffer();
            
            #ifdef FEATURE_LED_RING
              update_led_ring();
            #endif //FEATURE_LED_RING            
            
          }
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_TX_CHANGE) {  // one byte for transmitter #
          remove_from_send_buffer();
          if (send_buffer_bytes > 1) {
            if ((send_buffer_array[0] > 0) && (send_buffer_array[0] < 7)){
              switch_to_tx_silent(send_buffer_array[0]);
            }
            remove_from_send_buffer();          
          }
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_NULL) {
          remove_from_send_buffer();
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_PROSIGN) {
          remove_from_send_buffer();
          if (send_buffer_bytes) {
            send_char(send_buffer_array[0],OMIT_LETTERSPACE);
            #ifdef FEATURE_WINKEY_EMULATION
              if (winkey_host_open){
                // Must echo back PROSIGN characters sent  N6TV
                winkey_port_write(0xc4|winkey_sending|winkey_xoff,0);  // N6TV
                winkey_port_write(send_buffer_array[0],0);  // N6TV  
              }          
            #endif //FEATURE_WINKEY_EMULATION
            remove_from_send_buffer();
          }
          if (send_buffer_bytes) {
            send_char(send_buffer_array[0],KEYER_NORMAL);
            #ifdef FEATURE_WINKEY_EMULATION
              if (winkey_host_open){
                // Must echo back PROSIGN characters sent  N6TV
                winkey_port_write(0xc4|winkey_sending|winkey_xoff,0);  // N6TV
                winkey_port_write(send_buffer_array[0],0);  // N6TV  
              }          
            #endif //FEATURE_WINKEY_EMULATION
            remove_from_send_buffer();
          }
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_TIMED_KEY_DOWN) {
          remove_from_send_buffer();
          if (send_buffer_bytes) {
            send_buffer_status = SERIAL_SEND_BUFFER_TIMED_COMMAND;
            sending_mode = AUTOMATIC_SENDING;
            tx_and_sidetone_key(1);
            timed_command_end_time = millis() + (send_buffer_array[0] * 1000);
            timed_command_in_progress = SERIAL_SEND_BUFFER_TIMED_KEY_DOWN;
            remove_from_send_buffer();
          }
        }

        if (send_buffer_array[0] == SERIAL_SEND_BUFFER_TIMED_WAIT) {
          remove_from_send_buffer();
          if (send_buffer_bytes) {
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
            #if defined(OPTION_WINKEY_ECHO_7C_BYTE)
              if (send_buffer_array[0] > 30) {winkey_port_write(send_buffer_array[0],0);}
            #else
              if ((send_buffer_array[0]!= 0x7C) && (send_buffer_array[0] > 30)) {winkey_port_write(send_buffer_array[0],0);}
            #endif
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
        if (!pause_sending_buffer){
          remove_from_send_buffer();
        }
      }
    }

  } else {

    if (send_buffer_status == SERIAL_SEND_BUFFER_TIMED_COMMAND) {    // we're in a timed command

      if ((timed_command_in_progress == SERIAL_SEND_BUFFER_TIMED_KEY_DOWN) && (millis() > timed_command_end_time)) {
        sending_mode = AUTOMATIC_SENDING;
        tx_and_sidetone_key(0);
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
  if (((dit_buffer || dah_buffer) && (send_buffer_bytes)) && (keyer_machine_mode != BEACON)) {
    clear_send_buffer();
    send_buffer_status = SERIAL_SEND_BUFFER_NORMAL;
    dit_buffer = 0;
    dah_buffer = 0;    
    #ifdef FEATURE_MEMORIES
      repeat_memory = 255;
    #endif
    #ifdef FEATURE_WINKEY_EMULATION
      if (winkey_sending && winkey_host_open) {
        winkey_port_write(0xc2|winkey_sending|winkey_xoff,0); // 0xc2 - BREAKIN bit set high
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
      winkey_port_write(0xc0|winkey_sending|winkey_xoff,0); //send status /XOFF
    }
  #endif
  
  if (send_buffer_bytes) {
    send_buffer_bytes--;
  }
  if (send_buffer_bytes) {
    for (int x = 0;x < send_buffer_bytes;x++) {
      send_buffer_array[x] = send_buffer_array[x+1];
    }
    #if defined(FEATURE_WINKEY_EMULATION) && defined(OPTION_WINKEY_FREQUENT_STATUS_REPORT)
      winkey_port_write(0xc0|winkey_sending|winkey_xoff,0);
    #endif
  }
}

//-------------------------------------------------------------------------------------------------------

void add_to_send_buffer(byte incoming_serial_byte)
{

  if (send_buffer_bytes < send_buffer_size) {
    if (incoming_serial_byte != 127) {
      send_buffer_bytes++;
      send_buffer_array[send_buffer_bytes - 1] = incoming_serial_byte;
  
      #ifdef FEATURE_WINKEY_EMULATION
        if ((send_buffer_bytes>winkey_xoff_threshold) && winkey_host_open) {
          winkey_xoff=1;
          winkey_port_write(0xc0|winkey_sending|winkey_xoff,0); //send XOFF status         
        }
      #endif
            
    } else {  // we got a backspace
      if (send_buffer_bytes){
        send_buffer_bytes--;
      }
    }
  }

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
    winkey_speed_state == WINKEY_UNBUFFERED_SPEED;
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
  #ifdef DEBUG_WINKEY_PROTOCOL_USING_CW
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
  #if !defined(DEBUG_WINKEY_DISABLE_LEAD_IN_TIME_SETTING)
    configuration.ptt_lead_time[configuration.current_tx-1] = (incoming_serial_byte*10);
  #else
    configuration.ptt_lead_time[configuration.current_tx-1] = 0;
  #endif
  #ifdef DEBUG_WINKEY_PROTOCOL_USING_CW
    send_char('P',KEYER_NORMAL);
    send_char('1',KEYER_NORMAL);
  #endif
}
#endif //FEATURE_WINKEY_EMULATION
//-------------------------------------------------------------------------------------------------------
#ifdef FEATURE_WINKEY_EMULATION
void winkey_ptt_times_parm2_command(byte incoming_serial_byte) {

  configuration.ptt_tail_time[configuration.current_tx-1] = (3*int(1200/configuration.wpm)) + (incoming_serial_byte*10);
  winkey_session_ptt_tail = incoming_serial_byte;
  #ifdef DEBUG_WINKEY_PROTOCOL_USING_CW
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


  config_dirty = 1;

  if (incoming_serial_byte & 4) {  //serial echo enable
    #ifdef DEBUG_WINKEY_PROTOCOL_USING_CW
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
      #ifdef DEBUG_WINKEY_PROTOCOL_USING_CW
      send_char('B',KEYER_NORMAL);
      #endif
      break;
    case 16: configuration.keyer_mode = IAMBIC_A;
      #ifdef DEBUG_WINKEY_PROTOCOL_USING_CW
      send_char('A',KEYER_NORMAL);
      #endif
      break;
    case 32: configuration.keyer_mode = ULTIMATIC;
      #ifdef DEBUG_WINKEY_PROTOCOL_USING_CW
      send_char('U',KEYER_NORMAL);
      #endif
      break;
    case 48: configuration.keyer_mode = BUG;
      #ifdef DEBUG_WINKEY_PROTOCOL_USING_CW
      send_char('G',KEYER_NORMAL);
      #endif
      break;
  }
  #ifdef FEATURE_DEAD_OP_WATCHDOG
  if ((incoming_serial_byte & 128) == 128) {  //1xxxxxxx = paddle watchdog (1 = disable)
     dead_op_watchdog_active = 0;
  } else {
     dead_op_watchdog_active = 1;
  }
  #endif
  #ifdef FEATURE_AUTOSPACE
  if ((incoming_serial_byte & 2) == 2) {  //xxxxxx1x = autospace
     configuration.autospace_active = 1;
     #ifdef DEBUG_WINKEY_PROTOCOL_USING_CW
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
  
  if (incoming_serial_byte & 1) {
    configuration.ptt_buffer_hold_active = 1;
  } else {
    configuration.ptt_buffer_hold_active = 0;
  }

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

    config_dirty = 1;

}
#endif

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_WINKEY_EMULATION
void winkey_load_settings_command(byte winkey_status,byte incoming_serial_byte) {

  switch(winkey_status) {
     case WINKEY_LOAD_SETTINGS_PARM_1_COMMAND:
       #ifdef DEBUG_WINKEY
         debug_serial_port->println("winkey_load_settings_command: WINKEY_LOAD_SETTINGS_PARM_1_COMMAND");
       #endif //DEBUG_WINKEY       
       winkey_setmode_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_2_COMMAND:
       #ifdef DEBUG_WINKEY
         debug_serial_port->println("winkey_load_settings_command: WINKEY_LOAD_SETTINGS_PARM_2_COMMAND");
       #endif //DEBUG_WINKEY       
       winkey_unbuffered_speed_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_3_COMMAND:
       #ifdef DEBUG_WINKEY
         debug_serial_port->println("winkey_load_settings_command: WINKEY_LOAD_SETTINGS_PARM_3_COMMAND");
       #endif //DEBUG_WINKEY       
       winkey_sidetone_freq_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_4_COMMAND:
       #ifdef DEBUG_WINKEY
         debug_serial_port->println("winkey_load_settings_command: WINKEY_LOAD_SETTINGS_PARM_4_COMMAND");
       #endif //DEBUG_WINKEY       
       winkey_weighting_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_5_COMMAND:
       #ifdef DEBUG_WINKEY
         debug_serial_port->println("winkey_load_settings_command: WINKEY_LOAD_SETTINGS_PARM_5_COMMAND");
       #endif //DEBUG_WINKEY       
       winkey_ptt_times_parm1_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_6_COMMAND:
       #ifdef DEBUG_WINKEY
         debug_serial_port->println("winkey_load_settings_command: WINKEY_LOAD_SETTINGS_PARM_6_COMMAND");
       #endif //DEBUG_WINKEY       
       winkey_ptt_times_parm2_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_7_COMMAND:
       #ifdef DEBUG_WINKEY
         debug_serial_port->println("winkey_load_settings_command: WINKEY_LOAD_SETTINGS_PARM_7_COMMAND");
       #endif //DEBUG_WINKEY       
       winkey_set_pot_parm1_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_8_COMMAND:
       #ifdef DEBUG_WINKEY
         debug_serial_port->println("winkey_load_settings_command: WINKEY_LOAD_SETTINGS_PARM_8_COMMAND");
       #endif //DEBUG_WINKEY       
       winkey_set_pot_parm2_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_9_COMMAND:
       #ifdef DEBUG_WINKEY
         debug_serial_port->println("winkey_load_settings_command: WINKEY_LOAD_SETTINGS_PARM_9_COMMAND");
       #endif //DEBUG_WINKEY       
       winkey_first_extension_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_10_COMMAND:
       #ifdef DEBUG_WINKEY
         debug_serial_port->println("winkey_load_settings_command: WINKEY_LOAD_SETTINGS_PARM_10_COMMAND");
       #endif //DEBUG_WINKEY       
       winkey_keying_compensation_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_11_COMMAND:
       #ifdef DEBUG_WINKEY
         debug_serial_port->println("winkey_load_settings_command: WINKEY_LOAD_SETTINGS_PARM_11_COMMAND");
       #endif //DEBUG_WINKEY       
       winkey_farnsworth_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_12_COMMAND:  // paddle switchpoint - don't need to support
       #ifdef DEBUG_WINKEY
         debug_serial_port->println("winkey_load_settings_command: WINKEY_LOAD_SETTINGS_PARM_12_COMMAND");
       #endif //DEBUG_WINKEY  
       break;
     case WINKEY_LOAD_SETTINGS_PARM_13_COMMAND:
       #ifdef DEBUG_WINKEY
         debug_serial_port->println("winkey_load_settings_command: WINKEY_LOAD_SETTINGS_PARM_13_COMMAND");
       #endif //DEBUG_WINKEY       
       winkey_dah_to_dit_ratio_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_14_COMMAND:
       #ifdef DEBUG_WINKEY
         debug_serial_port->println("winkey_load_settings_command: WINKEY_LOAD_SETTINGS_PARM_14_COMMAND");
       #endif //DEBUG_WINKEY       
       winkey_set_pinconfig_command(incoming_serial_byte);
       break;
     case WINKEY_LOAD_SETTINGS_PARM_15_COMMAND:
       #ifdef DEBUG_WINKEY
         debug_serial_port->println("winkey_load_settings_command: WINKEY_LOAD_SETTINGS_PARM_15_COMMAND");
       #endif //DEBUG_WINKEY       
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
  if (!dead_op_watchdog_active) {
    byte_to_send = byte_to_send | 128;
  }
  #endif //FEATURE_DEAD_OP_WATCHDOG
  winkey_port_write(byte_to_send,1);

  // 2 - speed
  if (configuration.wpm > 99) {
    winkey_port_write(99,1);
  } else {
    byte_to_send = configuration.wpm;
    winkey_port_write(byte_to_send,1);
  }

  // 3 - sidetone
  switch(configuration.hz_sidetone) {
    case WINKEY_SIDETONE_1 : winkey_port_write(1,1); break;
    case WINKEY_SIDETONE_2 : winkey_port_write(2,1); break;
    case WINKEY_SIDETONE_3 : winkey_port_write(3,1); break;
    case WINKEY_SIDETONE_4 : winkey_port_write(4,1); break;
    case WINKEY_SIDETONE_5 : winkey_port_write(5,1); break;
    case WINKEY_SIDETONE_6 : winkey_port_write(6,1); break;
    case WINKEY_SIDETONE_7 : winkey_port_write(7,1); break;
    case WINKEY_SIDETONE_8 : winkey_port_write(8,1); break;
    case WINKEY_SIDETONE_9 : winkey_port_write(9,1); break;
    case WINKEY_SIDETONE_10 : winkey_port_write(10,1); break;
    default: winkey_port_write(5,1); break;
  }

  // 4 - weight
  winkey_port_write(configuration.weighting,1);

  // 5 - ptt lead
  if (configuration.ptt_lead_time[configuration.current_tx-1] < 256){
    winkey_port_write(configuration.ptt_lead_time[configuration.current_tx-1]/10,1);
  } else {
    winkey_port_write(255,1);
  }

  // 6 - ptt tail
  //if (configuration.ptt_tail_time[configuration.current_tx-1] < 256){
    //winkey_port_write((configuration.ptt_tail_time[configuration.current_tx-1] - (3*int(1200/configuration.wpm)))/10,1);
    winkey_port_write(winkey_session_ptt_tail,1);
  // } else {
  //   winkey_port_write(winkey_port_write(255,1);
  // }

  // 7 - pot min wpm
  #ifdef FEATURE_POTENTIOMETER
    winkey_port_write(pot_wpm_low_value,1);
  #else
    winkey_port_write(15,1);
  #endif

  // 8 - pot wpm range
  #ifdef FEATURE_POTENTIOMETER
    winkey_port_write(pot_wpm_high_value - pot_wpm_low_value,1);
  #else
    winkey_port_write(20,1);
  #endif

  // 9 - 1st extension
  winkey_port_write(first_extension_time,1);

  // 10 - compensation
  winkey_port_write(keying_compensation,1);

  // 11 - farnsworth wpm
  #ifdef FEATURE_FARNSWORTH
    winkey_port_write(configuration.wpm_farnsworth,1);
  #else
    winkey_port_write(zero,1);
  #endif

  // 12 - paddle setpoint
  winkey_port_write(50,1);  // default value

  // 13 - dah to dit ratio
  winkey_port_write(50,1);  // TODO -backwards calculate

  // 14 - pin config
  #ifdef OPTION_WINKEY_2_SUPPORT
    byte_to_send = 0;
    if (configuration.current_ptt_line != 0) {byte_to_send = byte_to_send | 1;}
    if ((configuration.sidetone_mode == SIDETONE_ON) || (configuration.sidetone_mode == SIDETONE_PADDLE_ONLY)) {byte_to_send = byte_to_send | 2;}
    if (current_tx_key_line == tx_key_line_1) {byte_to_send = byte_to_send | 4;}
    if (current_tx_key_line == tx_key_line_2) {byte_to_send = byte_to_send | 8;}
    if (wk2_both_tx_activated) {byte_to_send = byte_to_send | 12;}
    if (ultimatic_mode == ULTIMATIC_DIT_PRIORITY) {byte_to_send = byte_to_send | 128;}
    if (ultimatic_mode == ULTIMATIC_DAH_PRIORITY) {byte_to_send = byte_to_send | 64;}  
    if (ptt_hang_time_wordspace_units == 1.33) {byte_to_send = byte_to_send | 16;}
    if (ptt_hang_time_wordspace_units == 1.66) {byte_to_send = byte_to_send | 32;}
    if (ptt_hang_time_wordspace_units == 2.0) {byte_to_send = byte_to_send | 48;}
    winkey_port_write(byte_to_send,1);
  #else
    winkey_port_write(5,1); // default value
  #endif

  // 15 - pot range
  #ifdef OPTION_WINKEY_2_SUPPORT
    winkey_port_write(zero,1);
  #else
    winkey_port_write(0xFF,1);
  #endif

}
#endif


/*

Chapter One

It was late on a rainy Sunday evening.  Static crashes on the direct conversion receiver signaled a distant thunderstorm, due to arrive in an hour or so.  Colin knew he would have to disconnect the little microcontroller circuit from the receiver and all the station antennas soon, but it was getting late and he had to get his sleep for work the next day.

The contraption was a tangled mess on his desk, something only a radio amateur or mad scientist could appreciate.  Alligator clips connected the I and Q audio from the simple receiver to the microcontroller.  Colin had been learning about fast Fourier analysis.  This was his first attempt at actually running the code in an effort to decode RTTY signals.   The microcontroller probably lacked the horsepower to do it, and Colin knew expecting any sort of performance from his creation was a long shot.

Colin tuned to some RTTY signals but couldn't copy anything, despite carefully and slowly tuning the receiver in hopes of hitting that sweet spot where perhaps the microcontroller would blurt out some intelligence, some discernable word or text.  Just one recognizable snippet would give him the feeling of accomplishment or even victory, even if his design never proved to be usable in his nightly hobby.

The static crashes grew stronger and more frequent.  Colin had resigned himself to the fact that success would not be achieved this evening.  The approaching storm along with his growing fatigue convinced him to shut things down and head upstairs to bed.  Just then a burst of noise, different from the thunderstorm static crashes, but a type that you normally hear on 80 meters each night blurted out.  The microcontroller sent out its serial port a string of random characters, in a vain attempt to decode the sounds:

GEHZCVFNOVTZBEBA

Colin went about the process of disconnecting the power to everything and disconnecting antennas and went to bed.

The next evening after supper with his family, Colin went to his basement radio room again, determined to work again on his project but perhaps less eager than before due to the increasing futility of his efforts.  The microcontroller sat connected to the receiver, and the controller to the computer.  He listened to the receiver in the background while responding to emails.  There was a QSO in progress, an old man talking about his dog itching a lot.  The two old men in the conversation droned on forever, with Colin chuckling to himself, but too caught up in his email to reach over and tune the rig to another frequency in hopes of finding a more interesting conversation.

A burst of noise came through the rig again, much like the night before, though much stronger.  The simple receiver lacked automatic gain control and the strong signal produced a rather loud, annoying noise emanating from the rig, prompting Colin to reach over and turn the volume down.  Colin noticed on his serial terminal program another random string of characters which the microcontroller dutifully decoded:

GEHZCVFNOVTZBEBA

The string looked familiar to Colin.  He copied and pasted the string into search on his computer.  The search produced one hit, the terminal program log from the previous evening.  Colin opened the file and saw the matching string, 16 characters.  "What are the chances of that happening?", he thought.  He looked through his code again, looking for some sort of mistake, pattern in the code algorithm, or some plausible explanation. The receiver belched again:

GEHZCVFNOVTZBEBA

At this point Colin had no plausible explanation why the same random string of characters would be decoded last night and this evening, from mere noise bursts.  Frustrated, he decided to post a message on an Internet group describing the strange behavior and the random characters, and then walked away from his radios to watch TV with the family.  After almost an hour of watching mindless sitcoms, it was time for the kids to go to bed.  After they were tucked into bed, Colin came back to his desk to catch up on email.

The receiver, still powered up with the random noise of the universe coming out of the speaker at a low level, and the connected microcontroller circuit sat idle, waiting for some signal to decode.  An AM roundtable comes up on frequency and he listens awhile, while he continues to web surf, looking for something to occupy his mind.  A static crash comes through the speaks and the microcontroller terminal comes alive again, spewing characters:

COLINMEETME@40-10-45.5&75-10-52.6@SAT1200Z

"Wow" Colin exclaims, almost involuntarily.  He pauses for a moment, hoping his wife in the next room hasn't heard him.  She doesn't respond, continuing to watch TV.  "That's my name....coordinates, and a day and time.  That can't be a coincidence.  What in the world have I stumbled upon?" he thinks.  Nervously he brings up Google Earth and enters  the coordinates.  It's a coffee shop, about an hour and twenty minutes south. " Whoever sent this wants to meet me?"

Chapter Two

Colin barely slept the rest of the nights that week thinking about the message.  He stays out of his radio room which is very unlike him.  His wife is out of town this weekend, and Colin rationalizes that there's no excuse to not go to the coffee shop.  Early Saturday morning he quickly gets up, and nervously gets dressed.  He worries if he's given himself enough time to get there.  It's near the city and the surrounding suburban area where the coffee shop is located is notorious for bad traffic.  He decides to take a toll road and exit where he can take back roads to avoid the main thoroughfares.

He arrived at the coffee with a few minutes to spare, takes an out of the way parking spot towards the rear of the restaurant, backing in so he can see anyone pulling in or out, and the side entrance of the coffee shop.  He sits in the vehicle and surveys the parking lot.   Opening the glove compartment he pulls out a pistol in a holster.  Although licensed for carrying a sidearm, Colin rarely, if ever actual wore it in public.  He strapped it on to his belt and double-checked that his jacket concealed it.  His hands shook nervously, but he reassured himself he was somewhat prepared in case the proverbial "men in black" attempted to swoop down and throw him into a black van and drive off.

Looking up, Colin sees an old man in the parking lot looking his way.  They make eye contact.  Colin looks away but it's clear the old man is has somehow identified him.  Colin sighs.  "Perhaps he saw all the antennas on my vehicle, or my callsign plate."  He gets out of the vehicle, locks it, and walks over to the old man.

"Hello" he says in a somewhat frail voice.  "You Colin?"

"Yes" replies Colin, nervously.

The old man nods and his face lightens up.  "Come inside, let's talk."

They go inside and get in line.  The old man orders a coffee, and Colin, never acquiring a taste for coffee, get a hot chocolate.  They grab a table towards the back, away from everyone else.  The old man looks around to make sure they're out of earshot of others.

The old man leans inward, "So you copied my transmission the other day?"

"Yes."  Colin tells him the story of how he came upon the transmission.

"Well, congratulations.  You've stumbled upon something I think you're going to be very happy about.  You're in amateur radio?"  Colin nods.  "You've come upon a secret society.  We've been around a long time, since World War II.  Some of us are hams, others aren't.  We're everywhere.  You've heard us anytime you've turned on a radio, you just didn't know it.  We're the people you don't normally find on the air....the academics, scientists, progressives, politicians, famous people...activists...introverts...geniuses...people close to world leaders.  We communicate via encrypted messaging.  Those noise bursts you heard were transmissions from me.  Some of our communications are noise bursts.  Sometime we communicate with pure noise, indistinguishable from the normal noise you hear on your receiver everyday.  We hide out in the open."

"But how do you do this?"  Colin's technical curiosity emerges.  "How do you communicate with noise?"

The old man takes a sip from his coffee.  "We use a pseudo-random bit stream and quadrature modulate a digital signal taken from a special alphabet, somewhat like ASCII.  It's amazingly simple but nearly impossible to break without the bit stream.  You were just lucky to receive it.  Apparently the buggy code in your microcontroller digital signal processing generates part of the pseudo random stream under the right conditions.  Everyone thinks 80 meters is noisy.  It's really not, there's just a lot of us talking on it.  You ever turn on your radio and it's S9 noise everywhere?"

"Yes" replies Colin.

"Sometimes that's us.  We sometimes modulate wideband noise when we have a particularly large message to send out, something important.  The technology is really interesting.  It pushes the limits of Shannon's Equation." he pauses.  "You ever hear of long delay echos?"

"I've never experienced one, but I've read about them and heard they're somewhat common." Colin says.

He smiles.  "That's us.  Sometime we communicate by receiving someone's signal on the air, we delay it, modulate the noise on it, and re-transmit it.  We do that for fun.  People seem to get a kick out of it."

"Why does this society exist?"  asks Colin.

"We serve a higher purpose." pointing above, he says.  "It came out of the Resistance in World War II and was originally intended to prevent atrocities like the Holocaust from happening again, but since then it's grown to encompass other things.  Many of us started off as radio amateurs and got bored with it.  We dropped out.  We're the radio guys you don't see at hamfests or on the Internet.  Those of us who are licensed amateurs usually lay low and don't get on the air, at least in a way you can hear us.  Amateur radio is to us as CB is to amateur radio.  Few of us fit in with them. Members communicate about important stuff, like scientific discoveries or secret information from governments that could save lives or change the world.  We've provided information that has ended wars, and started some.  Some say we provided the information that started the fall of the USSR.  We operate without borders or recognition of nationality.   I'm not sure how many of us there are, but it's perhaps in the thousands, worldwide."

Colin asks "Are you spies?"

"We're not spies, we're communicators." he replies.

"Does the government know of this network?" 

"Perhaps, but not at a high level or in any official capacity that we know of.  We definitely have members close to people high up, advisers of sorts.  Undoubtedly there are members in intelligence agencies in various governments.  But they don't dare divulge knowledge of the network.  It's too valuable.  To them it's a tool, and they know they would be denied that tool, purged from the network, should they let others know of it.  But they are free to use the information they receive, as they see fit.  But they know they have a responsibility to use it for the greater good."

The old man clears his throat and takes another gulp of coffee.  "Communications is a weapon, more powerful than any weapon you can carry.  That phone," he said, pointing to my iPhone lying on the table, " is just as powerful as the weapon you have on your belt, just in a different way."

Colin tries to hide a puzzled look, wondering how the old man knew of his weapon.  Changing the subject, he asks "How do people get into this?"

"Membership is by invitation only.  We have 16 character identity strings.  You received mine.  An identity string is what you would call a callsign in amateur radio.  You're the first person I've ever heard of receiving the signal without knowledge of the code.  There's no process for someone like you to join.  But I'm getting old and I need to hand off my encryption stream to someone before I die, to keep it going.  You seem to be a nice enough guy, qualified to join, from what I have seen and heard about you."

"But.... this sounds like a network of rather smart and powerful people.  I'm just an ordinary guy who likes to play with radios and occasionally build something.  I'm not a scientist or someone powerful.  Is there some role I will have, something I need to do?" Colin asks.

"Some members just have fun with this, somewhat like a hobby.  They don't have roles, for now.  You will have a role, you just don't know what it is yet.  Do not seek out a role.  Do not try to make yourself important or identify some great thing to do.  Those who invent things to do, create crises, or give themselves power get purged from the network.  Your role will become known in due time and you will know it when you encounter it.  Trust me." 

He goes on, "You're going to receive more information.  It will explain the encryption algorithm.  You know how to program, so with a little bit of work you should be able to write the software for a transceiver that will work reliably.  I'll also give you an identity string.  It's derived from mine and you'll eventually be able to trace it back mathematically to previous identity strings and others in the hierarchy.  The more you communicate, your identity string will establish a trust relationship with other identity strings, other operators.  The more operators you gain trust with, you will get more of the algorithm and more of the bit stream.  With more of the algorithm and bit stream, the more signals you will be able to receive and you will be able to communicate with more people in the network hierarchy.  With perseverance and patience you'll get to know some high level members, perhaps even people you see on the news."

"I said before that there are thousands of operators.  The truth is I don't know how many operators there are.  No one does.  As more of the bit stream is revealed, more members appear.  For all we know there could be millions of members.  There could be extra-terrestrials in the network."  He chuckles.  "Some have theorized that some of the noise we receive from outer space could be actually intelligence encrypted in the noise, like we do.  We just don't have the information or computing power yet to decode it."

The smile leaves old man's face.  "You have to keep this a secret.  If you reveal this to the wrong people, the results would be disastrous.  Those who reveal the code of the noise are purged from the network, sometimes not seen again."
Before Colin could ask his next question, the old man got up, handed him a card with characters written in bold black marker:

8^fGwq9(:lLDPu6$

"Congratulations.  This is your identity string.  Memorize it.  Guard it with your life."  He offers his right hand and they shake hands.

Colin follows the old man out the door, wanting to ask more questions. "Where will I would get the information on the algorithm, how do I build a transceiver?"  he frantically asks.

"You have to listen to the noise."  he said as he walked to his car, got in, and drove off.

Colin drove home in somewhat of a daze, not sure what to make of all this.  Was the old man crazy, or was all this real?  Colin went about my business for a few days, thinking about the old man and wondering what would be next.  "Would I get something in the mail?  Perhaps an email?  Would he contact me again?"

A few days later while watching the local news, a story came on about the death of a prominent researcher.  Colin was shocked to see a grainy photo of the old man he had met at the coffee shop, the photo perhaps from the 60s as he looked younger, more Colin's age today.  Walter was his name.  He had worked at Bell Labs in New Jersey as a physicist and had made many discoveries in communications which were patented in the 60s and 70s.  Walter was a quiet man but was known for his community work.  He fled Germany with his family as a young boy prior to World War II breaking out.  His father was a poor potato farmer who later helped the allies in cryptography after he devised a code based on the patterns of eyes on potatoes.  His wife had passed before him several years earlier.  Walter died alone at his home, of unknown causes and his death was under investigation.  Investigators doubted there was foul play, but there was a rather odd paper he was writing with codes on it found next to him.  He was survived by two children and some grandchildren residing in Florida.  Colin thought perhaps he could contact his family, but he knew he couldn't risk revealing what he had heard from the man if what he said was true.  Colin sat dumbfounded, wondering if he had lost his one connection to the secret network.

Later that night Colin once again turned on his receiver to 80 meters.  The little circuit sat idle with alligator clips connecting the rig audio to it.  His original goal of copying a RTTY signal now seemed pointless and insignificant in the grand scheme of things with the new knowledge he had.  He wanted to write more code and figure out the algorithm, all of it.  But Colin had no idea what next step to take, no clue what the algorithm was that would grant him access to a whole new world.  He pulled the card out of his wallet with his identity string and stared at the seemingly random 16 characters.  It contained uppercase, lowercase, numbers, symbols, just about everything.  Perhaps it was a base 64 character set?  What secrets were in it?  His thoughts were a disorganized jumble, and feeling a headache coming on he stopped himself from thinking further about it.

He was no longer interested in listening to Morse code signals or voice conversations.  That was merely just meaningless noise, a distraction from what he was really looking for.  Every little pop and crackle on the receiver caught his attention.  Was it just random atmospheric noise leftover from the Big Bang or some noisy electrical appliance, or was there intelligence in each seemingly random sounds?  For hours he scanned through the band, hoping to catch the right signal in hopes that his little contraption might pick up some clue that would lead him to the next step, perhaps someone else in the network since his contact had passed away.  BZZZZZT bursts from the receiver and the microcontroller terminal screen came alive:

 8^fGwq9(:lLDPu6$ : KEEP LISTENING TO THE NOISE AND AWAIT FURTHER INFO.

*/


//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_WINKEY_EMULATION) && defined(OPTION_WINKEY_2_SUPPORT)

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
  
  winkey_port_write(0xa5,1); // 01 magic byte
  winkey_admin_get_values_command(); // 02-16
  
  winkey_port_write(byte(configuration.wpm),1); // 17 cmdwpm
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
    winkey_port_write(zero,1);
  }  
}
#endif //defined(FEATURE_SERIAL) && defined(FEATURE_WINKEY_EMULATION) && defined(OPTION_WINKEY_2_SUPPORT)


//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_WINKEY_EMULATION
void winkey_port_write(byte byte_to_send,byte override_filter){

  #ifdef DEBUG_WINKEY_PORT_WRITE
  if ((byte_to_send > 4) && (byte_to_send < 31)){
    boop();
    delay(500);
    boop();
    delay(500);
    boop();
    //return;
  }
  #endif

  if (((byte_to_send > 4) && (byte_to_send < 31)) && (!override_filter)){
    #ifdef DEBUG_WINKEY
      debug_serial_port->print("Winkey Port TX: FILTERED: ");    
      if ((byte_to_send > 31) && (byte_to_send < 127)){
        debug_serial_port->write(byte_to_send);
      } else {
        debug_serial_port->print(".");
      }
      debug_serial_port->print(" [");
      debug_serial_port->print(byte_to_send);
      debug_serial_port->print("] [0x");
      debug_serial_port->print(byte_to_send,HEX);
      debug_serial_port->println("]");
    #endif
    return;
  }

  primary_serial_port->write(byte_to_send);
  #ifdef DEBUG_WINKEY
    debug_serial_port->print("Winkey Port TX: ");    
    if ((byte_to_send > 31) && (byte_to_send < 127)){
      debug_serial_port->write(byte_to_send);
    } else {
      debug_serial_port->print(".");
    }
    debug_serial_port->print(" [");
    debug_serial_port->print(byte_to_send);
    debug_serial_port->print("] [0x");
    debug_serial_port->print(byte_to_send,HEX);
    debug_serial_port->println("]");
  #endif
}

#endif //FEATURE_WINKEY_EMULATION

//-------------------------------------------------------------------------------------------------------

#ifdef FEATURE_WINKEY_EMULATION
void service_winkey(byte action) {
   
  static byte winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
  static int winkey_parmcount = 0;
  static unsigned long winkey_last_activity;
  byte status_byte_to_send;
  static byte winkey_paddle_echo_space_sent = 1;

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

  #ifdef DEBUG_WINKEY_SEND_ERRANT_BYTE
  byte i_sent_it = 0;

  if ((millis() > 30000) && (!i_sent_it)){
    winkey_port_write(30,1);
    i_sent_it = 1;
  }

  #endif

  
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
        #ifdef DEBUG_WINKEY
          debug_serial_port->println("\r\nservice_winkey: sending unsolicited status byte due to paddle interrupt...");
        #endif //DEBUG_WINKEY       
        winkey_sending = 0;
        clear_send_buffer();

        #ifdef FEATURE_MEMORIES
        //clear_memory_button_buffer();
        play_memory_prempt = 1;
        repeat_memory = 255;
        #endif          

        winkey_interrupted = 0;
        //winkey_port_write(0xc2|winkey_sending|winkey_xoff);  
        winkey_port_write(0xc6,0);    //<- this alone makes N1MM logger get borked (0xC2 = paddle interrupt)
        winkey_port_write(0xc0,0);    // so let's send a 0xC0 to keep N1MM logger happy 
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
        #ifdef DEBUG_WINKEY
          debug_serial_port->println("\r\nservice_winkey: sending unsolicited status byte...");
        #endif //DEBUG_WINKEY           
        winkey_sending = 0;
        winkey_port_write(0xc0|winkey_sending|winkey_xoff,0);    // tell the host we've sent everything
        winkey_buffer_counter = 0;
        winkey_buffer_pointer = 0;
      }
    }
    // failsafe check - if we've been in some command status for awhile waiting for something, clear things out
    if ((winkey_status != WINKEY_NO_COMMAND_IN_PROGRESS) && ((millis() - winkey_last_activity) > winkey_command_timeout_ms)) {
      #ifdef DEBUG_WINKEY
        debug_serial_port->println("\r\nservice_winkey: command timeout! ->WINKEY_NO_COMMAND_IN_PROGRESS");
      #endif //DEBUG_WINKEY      
      winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      winkey_buffer_counter = 0;
      winkey_buffer_pointer = 0;
      winkey_port_write(0xc0|winkey_sending|winkey_xoff,0);    //send a status byte back for giggles
    }  
    if ((winkey_host_open) && (winkey_paddle_echo_buffer) && (winkey_paddle_echo_activated) && (millis() > winkey_paddle_echo_buffer_decode_time)) {
      #ifdef DEBUG_WINKEY
        debug_serial_port->println("\r\nservice_winkey: sending paddle echo char...");
      #endif //DEBUG_WINKEY       
      winkey_port_write(byte(convert_cw_number_to_ascii(winkey_paddle_echo_buffer)),0);
      winkey_paddle_echo_buffer = 0;
      winkey_paddle_echo_buffer_decode_time = millis() + (float(600/configuration.wpm)*length_letterspace);
      winkey_paddle_echo_space_sent = 0;
    }
    if ((winkey_host_open) && (winkey_paddle_echo_buffer == 0) && (winkey_paddle_echo_activated) && (millis() > (winkey_paddle_echo_buffer_decode_time + (float(1200/configuration.wpm)*(configuration.length_wordspace-length_letterspace)))) && (!winkey_paddle_echo_space_sent)) {
      #ifdef DEBUG_WINKEY
        debug_serial_port->println("\r\nservice_winkey: sending paddle echo space...");
      #endif //DEBUG_WINKEY        
      winkey_port_write(' ',0);
      winkey_paddle_echo_space_sent = 1;
    }
  }  // if (action == WINKEY_HOUSEKEEPING)

  if (action == SERVICE_SERIAL_BYTE) {
    #ifdef DEBUG_WINKEY
      debug_serial_port->print("Winkey Port RX: ");
      if ((incoming_serial_byte > 31) && (incoming_serial_byte < 127)){
        debug_serial_port->write(incoming_serial_byte);
      } else {
        debug_serial_port->print(".");
      }
      debug_serial_port->print(" [");
      debug_serial_port->print(incoming_serial_byte);
      debug_serial_port->print("]");
      debug_serial_port->print(" [0x");
      if (incoming_serial_byte < 16){debug_serial_port->print("0");}
      debug_serial_port->print(incoming_serial_byte,HEX);
      debug_serial_port->println("]");      
    #endif //DEBUG_WINKEY

    winkey_last_activity = millis();
    if (winkey_status == WINKEY_NO_COMMAND_IN_PROGRESS) {

      #if defined(OPTION_WINKEY_EXTENDED_COMMANDS_WITH_DOLLAR_SIGNS)

        #if !defined(OPTION_WINKEY_IGNORE_LOWERCASE)
          if ((incoming_serial_byte > 31) && (incoming_serial_byte != 36)) {  // ascii 36 = '$'
        #else
          if ((((incoming_serial_byte > 31) && (incoming_serial_byte < 97)) || (incoming_serial_byte == 124)) && (incoming_serial_byte != 36)) {  // 124 = ascii | = half dit
        #endif
          
      #else

        #if !defined(OPTION_WINKEY_IGNORE_LOWERCASE)
          if (incoming_serial_byte > 31) {
        #else
          if (((incoming_serial_byte > 31) && (incoming_serial_byte < 97)) || (incoming_serial_byte == 124)) {  // 124 = ascii | = half dit
        #endif

      #endif

        #if !defined(OPTION_WINKEY_IGNORE_LOWERCASE)
          if ((incoming_serial_byte > 96) && (incoming_serial_byte < 123)){incoming_serial_byte = incoming_serial_byte - 32;}
        #endif //!defined(OPTION_WINKEY_IGNORE_LOWERCASE)
      
        byte serial_buffer_position_to_overwrite;

        if (winkey_buffer_pointer > 0) {
          serial_buffer_position_to_overwrite = send_buffer_bytes - (winkey_buffer_counter - winkey_buffer_pointer) - 1;
          if ((send_buffer_bytes) && (serial_buffer_position_to_overwrite < send_buffer_bytes )) {
            send_buffer_array[serial_buffer_position_to_overwrite] = incoming_serial_byte;
          }
          winkey_buffer_pointer++;
        } else {


          #ifdef DEBUG_WINKEY
            // debug_serial_port->println("service_winkey: adding char to send buffer");
          #endif //DEBUG_WINKEY      

          add_to_send_buffer(incoming_serial_byte);
          #if defined(OPTION_WINKEY_INTERRUPTS_MEMORY_REPEAT) && defined(FEATURE_MEMORIES)
            play_memory_prempt = 1;
            repeat_memory = 255;
          #endif
          winkey_buffer_counter++;

        }

        if (!winkey_sending) {
          #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: status byte: starting to send...");
          #endif //DEBUG_WINKEY          
          winkey_sending=0x04;
          #if !defined(OPTION_WINKEY_UCXLOG_SUPRESS_C4_STATUS_BYTE)
            winkey_port_write(0xc4|winkey_sending|winkey_xoff,0);  // tell the client we're starting to send
          #endif //OPTION_WINKEY_UCXLOG_SUPRESS_C4_STATUS_BYTE
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
              winkey_port_write(((pot_value_wpm()-pot_wpm_low_value)|128),0);
            #endif
            #ifndef FEATURE_POTENTIOMETER
              winkey_port_write((byte(configuration.wpm-pot_wpm_low_value)|128),0);
            #endif
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: report pot");
            #endif //DEBUG_WINKEY               
            break;
          case 0x08:    // backspace command
            if (send_buffer_bytes) {
              send_buffer_bytes--;
            }
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: backspace");
            #endif //DEBUG_WINKEY               
            break;
          case 0x09:
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: WINKEY_SET_PINCONFIG_COMMAND");
            #endif //DEBUG_WINKEY             
            winkey_status = WINKEY_SET_PINCONFIG_COMMAND;
            break;
          case 0x0a:                 // 0A - clear buffer - no parms
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: 0A clear buffer");
            #endif //DEBUG_WINKEY             
            if (winkey_sending) {
              clear_send_buffer();
              winkey_sending = 0;
              winkey_port_write(0xc0|winkey_sending|winkey_xoff,0);
            }
            pause_sending_buffer = 0;
            winkey_buffer_counter = 0;
            winkey_buffer_pointer = 0;
            #if defined(OPTION_ENABLE_SERIAL_PORT_CHECKING_WHILE_SENDING_CW_MAY_CAUSE_PROBLEMS)
              loop_element_lengths_breakout_flag = 0;
            #endif
            #ifdef FEATURE_MEMORIES
              repeat_memory = 255;
            #endif
            sending_mode = AUTOMATIC_SENDING;
            manual_ptt_invoke = 0;
            tx_and_sidetone_key(0); 
            winkey_speed_state = WINKEY_UNBUFFERED_SPEED;
            configuration.wpm = winkey_last_unbuffered_speed_wpm;                      
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
              winkey_port_write(status_byte_to_send,0);
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
                winkey_port_write(status_byte_to_send,0);
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

          #ifdef OPTION_WINKEY_EXTENDED_COMMANDS_WITH_DOLLAR_SIGNS
            case 36:
              winkey_status = WINKEY_EXTENDED_COMMAND;
              beep();
              #ifdef DEBUG_WINKEY
                debug_serial_port->println("service_winkey: WINKEY_EXTENDED_COMMAND");
              #endif //DEBUG_WINKEY  
              break;
          #endif //OPTION_WINKEY_EXTENDED_COMMANDS_WITH_DOLLAR_SIGNS
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
          winkey_port_write(0xc0|winkey_sending|winkey_xoff,0);           
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
         #ifdef DEBUG_WINKEY
           debug_serial_port->println("service_winkey: WINKEY_LOAD_SETTINGS_PARM_15 -> WINKEY_NO_COMMAND_IN_PROGRESS");
         #endif //DEBUG_WINKEY            
        }
      }

      #ifdef OPTION_WINKEY_EXTENDED_COMMANDS_WITH_DOLLAR_SIGNS
        if (winkey_status == WINKEY_EXTENDED_COMMAND) {  
          //if (incoming_serial_byte != 36){
            //beep();
          //} else {
            boop();
            beep();
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
          //}
        }
      #endif //OPTION_WINKEY_EXTENDED_COMMANDS_WITH_DOLLAR_SIGNS

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
        if (incoming_serial_byte > 1){  // the HSCW command is overloaded; 0 = buffered TX 1, 1 = buffered TX 2, > 1 = HSCW WPM
          unsigned int send_buffer_wpm = ((incoming_serial_byte*100)/5);
          add_to_send_buffer(SERIAL_SEND_BUFFER_WPM_CHANGE);
          add_to_send_buffer(highByte(send_buffer_wpm));
          add_to_send_buffer(lowByte(send_buffer_wpm));
        } else {
          add_to_send_buffer(SERIAL_SEND_BUFFER_TX_CHANGE);
          add_to_send_buffer(incoming_serial_byte+1);
        }
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
        winkey_speed_state = WINKEY_UNBUFFERED_SPEED;
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
            if ((send_buffer_bytes) && (serial_buffer_position_to_overwrite < send_buffer_bytes )) {
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
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: WINKEY_POINTER_01_COMMAND");
            #endif //DEBUG_WINKEY              
            break;
          case 0x02:
            winkey_status = WINKEY_POINTER_02_COMMAND;  // move to new position in append mode
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: WINKEY_POINTER_02_COMMAND");
            #endif //DEBUG_WINKEY            
            break;
          case 0x03:
            winkey_status = WINKEY_POINTER_03_COMMAND;
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: WINKEY_POINTER_03_COMMAND");
            #endif //DEBUG_WINKEY            
            break;
          default:
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: WINKEY_POINTER_COMMAND -> WINKEY_NO_COMMAND_IN_PROGRESS");
            #endif //DEBUG_WINKEY            
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
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND 0x01");
            #endif //DEBUG_WINKEY          
            #if defined(__AVR__) //#ifndef ARDUINO_SAM_DUE
              asm volatile ("jmp 0"); /*wdt_enable(WDTO_30MS); while(1) {};*/ 
            #else
              setup();
            #endif //__AVR__
            break;  // reset command
          case 0x02:  // host open command - send version back to host
            #ifdef OPTION_WINKEY_2_SUPPORT
              winkey_port_write(WINKEY_2_REPORT_VERSION_NUMBER,1);
            #else //OPTION_WINKEY_2_SUPPORT
              winkey_port_write(WINKEY_1_REPORT_VERSION_NUMBER,1);
            #endif //OPTION_WINKEY_2_SUPPORT
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            manual_ptt_invoke = 0;
            winkey_host_open = 1;
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND host open");
            #endif //DEBUG_WINKEY  
            #if defined(OPTION_WINKEY_BLINK_PTT_ON_HOST_OPEN)    
              blink_ptt_dits_and_dahs("..");
            #else
              boop_beep();
            #endif         
            break;
          case 0x03: // host close command
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            manual_ptt_invoke = 0;
            winkey_host_open = 0;
            #ifdef OPTION_WINKEY_2_SUPPORT
              winkey_port_write(WINKEY_2_REPORT_VERSION_NUMBER,1);
            #else //OPTION_WINKEY_2_SUPPORT
              winkey_port_write(WINKEY_1_REPORT_VERSION_NUMBER,1);
            #endif //OPTION_WINKEY_2_SUPPORT            
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND host close");
            #endif //DEBUG_WINKEY                  
            beep_boop();
            config_dirty = 1;
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
            winkey_port_write(WINKEY_RETURN_THIS_FOR_ADMIN_PADDLE_A2D,0);
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND paddle A2D");
            #endif //DEBUG_WINKEY              
            break;
          case 0x06: // speed A2D
            winkey_port_write(WINKEY_RETURN_THIS_FOR_ADMIN_SPEED_A2D,0);
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND speed A2D");
            #endif //DEBUG_WINKEY              
            break;
          case 0x07: // Get values
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND winkey_admin_get_values");
            #endif //DEBUG_WINKEY             
            winkey_admin_get_values_command();
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            break;
          case 0x08: // reserved
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND 0x08 reserved - WTF?");
            #endif //DEBUG_WINKEY              
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            break;  
          case 0x09: // get cal
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND get cal");
            #endif //DEBUG_WINKEY           
            winkey_port_write(WINKEY_RETURN_THIS_FOR_ADMIN_GET_CAL,0);
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            break;
          #ifdef OPTION_WINKEY_2_SUPPORT
          case 0x0a: // set wk1 mode (10)
            wk2_mode = 1;
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND wk2_mode = 1");
            #endif //DEBUG_WINKEY              
            break;
          case 0x0b: // set wk2 mode (11)
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND wk2_mode = 2");
            #endif //DEBUG_WINKEY              
            beep();
            beep();
            wk2_mode = 2;
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            break;            
          case 0x0c: // download EEPPROM 256 bytes (12)
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND winkey_eeprom_download");
            #endif //DEBUG_WINKEY           
            winkey_eeprom_download();
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            break;   
          case 0x0d: // upload EEPROM 256 bytes (13)
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND upload EEPROM");
            #endif //DEBUG_WINKEY           
            winkey_status = WINKEY_UNSUPPORTED_COMMAND;  // upload EEPROM 256 bytes
            winkey_parmcount = 256;
            break;       
          case 0x0e: //(14)
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND WINKEY_SEND_MSG");
            #endif //DEBUG_WINKEY          
            winkey_status = WINKEY_SEND_MSG;
            break;
          case 0x0f: // load xmode (15)
            winkey_status = WINKEY_UNSUPPORTED_COMMAND;
            winkey_parmcount = 1;
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND load xmode");
            #endif //DEBUG_WINKEY            
            break;            
          case 0x10: // reserved (16)
            winkey_port_write(zero,0);
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            break;
          case 0x11: // set high baud rate (17)
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND set high baud rate");
            #endif //DEBUG_WINKEY            
            primary_serial_port->end();
            primary_serial_port->begin(9600);
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            break;
          case 0x12: // set low baud rate (18)
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND set low baud rate");
            #endif //DEBUG_WINKEY           
            primary_serial_port->end();
            primary_serial_port->begin(1200);
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            break;
          #endif //OPTION_WINKEY_2_SUPPORT  
          default:
            winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
            #ifdef DEBUG_WINKEY
              debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND -> WINKEY_NO_COMMAND_IN_PROGRESS");
            #endif //DEBUG_WINKEY             
            break;
          }
      } else {
        if (winkey_status == WINKEY_ADMIN_COMMAND_ECHO) {
          #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND echoing a byte...");
          #endif //DEBUG_WINKEY  
          winkey_port_write(incoming_serial_byte,1);
          winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
        }
      }

      if (winkey_status == WINKEY_KEYING_COMPENSATION_COMMAND) {
        #ifdef DEBUG_WINKEY
          debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND WINKEY_KEYING_COMPENSATION_COMMAND byte");
        #endif //DEBUG_WINKEY         
        keying_compensation = incoming_serial_byte;
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status == WINKEY_FIRST_EXTENSION_COMMAND) {
        #ifdef DEBUG_WINKEY
          debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND WINKEY_FIRST_EXTENSION_COMMAND byte");
        #endif //DEBUG_WINKEY              
        first_extension_time = incoming_serial_byte;
        #ifdef DEBUG_WINKEY_PROTOCOL_USING_CW
          send_char('X',KEYER_NORMAL);
        #endif
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status == WINKEY_PAUSE_COMMAND) {
        if (incoming_serial_byte) {
          #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND WINKEY_PAUSE_COMMAND pause");
          #endif //DEBUG_WINKEY           
          pause_sending_buffer = 1;
        } else {
          #ifdef DEBUG_WINKEY
            debug_serial_port->println("service_winkey: WINKEY_ADMIN_COMMAND WINKEY_PAUSE_COMMAND unpause");
          #endif //DEBUG_WINKEY             
          pause_sending_buffer = 0;
        }
        winkey_status = WINKEY_NO_COMMAND_IN_PROGRESS;
      }

      if (winkey_status ==  WINKEY_KEY_COMMAND) {
        #ifdef FEATURE_MEMORIES
        repeat_memory = 255;
        #endif
        sending_mode = AUTOMATIC_SENDING;
        if (incoming_serial_byte) {
          tx_and_sidetone_key(1);
        } else {
          tx_and_sidetone_key(0);
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
          case 1: winkey_dit_invoke = 0; winkey_dah_invoke = 1; break;
          case 2: winkey_dit_invoke = 1; winkey_dah_invoke = 0; break;
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
void service_command_line_interface(PRIMARY_SERIAL_CLS * port_to_use) {
 
  static byte cli_wait_for_cr_flag = 0; 
  
  if (serial_backslash_command == 0) {
    incoming_serial_byte = uppercase(incoming_serial_byte);
    if ((incoming_serial_byte != 92) && (incoming_serial_byte != 27)) { // we do not have a backslash or ESC


      #if !defined(OPTION_EXCLUDE_MILL_MODE)
        if (configuration.cli_mode == CLI_NORMAL_MODE){
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
        } else {  // configuration.cli_mode != CLI_NORMAL_MODE
          if (configuration.cli_mode == CLI_MILL_MODE_KEYBOARD_RECEIVE){
            port_to_use->write(incoming_serial_byte);
            if (incoming_serial_byte == 13){port_to_use->println();}
            #ifdef FEATURE_SD_CARD_SUPPORT
              sd_card_log("",incoming_serial_byte);
            #endif            

          } else { // configuration.cli_mode == CLI_MILL_MODE_PADDLE_SEND
            port_to_use->println();
            port_to_use->println();
            if (incoming_serial_byte == 13){port_to_use->println();}
            port_to_use->write(incoming_serial_byte);
            configuration.cli_mode = CLI_MILL_MODE_KEYBOARD_RECEIVE;
            #ifdef FEATURE_SD_CARD_SUPPORT
              sd_card_log("\r\nRX:",0);
              sd_card_log("",incoming_serial_byte);
            #endif          
          }
        } //if (configuration.cli_mode == CLI_NORMAL_MODE)

      #else //!defined(OPTION_EXCLUDE_MILL_MODE)

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

      #endif // !defined(OPTION_EXCLUDE_MILL_MODE)

      #ifdef FEATURE_MEMORIES
        if ((incoming_serial_byte != 13) && (incoming_serial_byte != 10)) {repeat_memory = 255;}
      #endif
    } else {     //if ((incoming_serial_byte != 92) && (incoming_serial_byte != 27)) -- we got a backslash or ESC
      if (incoming_serial_byte == 92){  // backslash
        serial_backslash_command = 1;
        port_to_use->write(incoming_serial_byte);
      } else {  // escape
        clear_send_buffer();
        #ifdef FEATURE_MEMORIES
          play_memory_prempt = 1;
          repeat_memory = 255;
        #endif
      }  
    }
  } else { // (serial_backslash_command == 0) -- we already got a backslash
      incoming_serial_byte = uppercase(incoming_serial_byte);
      port_to_use->write(incoming_serial_byte);
      process_serial_command(port_to_use);
      serial_backslash_command = 0;
      port_to_use->println();
  }
}
#endif //FEATURE_COMMAND_LINE_INTERFACE

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_SERIAL)
void check_serial(){
  

  #if defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE)
    if (check_serial_override){return;}
  #endif

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
      #endif //DEBUG_SERIAL_SEND_CW_CALLOUT
      service_command_line_interface(secondary_serial_port);
    } //  while (secondary_serial_port->available() > 0)  
  #endif //FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT


}
#endif //defined(FEATURE_SERIAL)

//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL_HELP) && defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_page_pause(PRIMARY_SERIAL_CLS * port_to_use,byte seconds_timeout){

  
  unsigned long pause_start_time = millis();

  port_to_use->println("\r\nPress enter...");
  while ((!port_to_use->available()) && (((millis()-pause_start_time)/1000) < seconds_timeout)){}
  while (port_to_use->available()){port_to_use->read();}


}
#endif //defined(FEATURE_SERIAL_HELP) && defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)

//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL_HELP) && defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void print_serial_help(PRIMARY_SERIAL_CLS * port_to_use,byte paged_help){

  port_to_use->println(F("\n\rK3NG Keyer Help\n\r"));
  port_to_use->println(F("CLI commands:"));
  port_to_use->println(F("\\#\t\t: Play memory # x")); //Upper case to first letter only(WD9DMP)
  port_to_use->println(F("\\A\t\t: Iambic A"));
  port_to_use->println(F("\\B\t\t: Iambic B"));
  port_to_use->println(F("\\C\t\t: Single paddle")); //Upper case to first letter only(WD9DMP)
  port_to_use->println(F("\\D\t\t: Ultimatic"));
  port_to_use->println(F("\\E####\t\t: Set serial number to ####"));
  port_to_use->println(F("\\F####\t\t: Set sidetone to #### hz"));
  port_to_use->println(F("\\G\t\t: Switch to bug mode")); //Upper case to first letter only(WD9DMP)
  #ifdef FEATURE_HELL
    port_to_use->println(F("\\H\t\t: Toggle CW / Hell mode"));
  #endif
  port_to_use->println(F("\\I\t\t: TX line disable/enable"));
  port_to_use->println(F("\\J###\t\t: Set dah to dit ratio")); //Upper case to first letter only(WD9DMP)
  #ifdef FEATURE_TRAINING_COMMAND_LINE_INTERFACE
    port_to_use->println(F("\\K\t\t: Training"));
  #endif
  port_to_use->println(F("\\L##\t\t: Set weighting (50 = normal)"));
  #ifdef FEATURE_FARNSWORTH
    port_to_use->println(F("\\M###\t\t: Set Farnsworth speed")); //Upper case to first letter only(WD9DMP)
  #endif
  if (paged_help) {serial_page_pause(port_to_use,10);}
  port_to_use->println(F("\\N\t\t: Toggle paddle reverse")); //Upper case to first letter only(WD9DMP)
  port_to_use->println(F("\\O\t\t: Toggle sidetone on/off")); //Added missing command (WD9DMP)
  port_to_use->println(F("\\Px<string>\t: Program memory #x with <string>")); //Upper case to first letter only(WD9DMP)
  port_to_use->println(F("\\Q#[#]\t\t: Switch to QRSS mode with ## second dit length"));
  port_to_use->println(F("\\R\t\t: Switch to regular speed (wpm) mode"));
  port_to_use->println(F("\\S\t\t: Status report")); //Upper case to first letter only(WD9DMP)
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
  port_to_use->println(F("\\+\t\t: Create prosign")); //Changed description to match change log at top (WD9DMP)
  port_to_use->println(F("\\!##\t\t: Repeat play memory")); //Added missing command(WD9DMP)
  port_to_use->println(F("\\|####\t\t: Set memory repeat (milliseconds)")); //Added missing command(WD9DMP)
  port_to_use->println(F("\\*\t\t: Toggle paddle echo")); //Added missing command(WD9DMP) 
  port_to_use->println(F("\\`\t\t: Toggle straight key echo")); //Added missing command(WD9DMP) 
  port_to_use->println(F("\\^\t\t: Toggle wait for carriage return to send CW / send CW immediately")); //Added missing command(WD9DMP)
  #ifdef FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
    port_to_use->println(F("\\&\t\t: Toggle CMOS Super Keyer timing on/off")); //Upper case to first letter only(WD9DMP)
    port_to_use->println(F("\\%##\t\t: Set CMOS Super Keyer timing %")); //Upper case to first letter only(WD9DMP)
  #endif //FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
  port_to_use->println(F("\\.\t\t: Toggle dit buffer on/off"));
  port_to_use->println(F("\\-\t\t: Toggle dah buffer on/off"));
  port_to_use->println(F("\\~\t\t: Reset unit")); //Added missing command(WD9DMP)
  port_to_use->println(F("\\:\t\t: Toggle cw send echo")); //Added missing command(WD9DMP)
  port_to_use->println(F("\\{\t\t: QLF mode on/off")); //Added missing command(WD9DMP)
  port_to_use->println(F("\\>\t\t: Send serial number, then increment")); //Added missing command(WD9DMP)
  port_to_use->println(F("\\<\t\t: Send current serial number")); //Added missing command(WD9DMP)
  port_to_use->println(F("\\(\t\t: Send current serial number in cut numbers")); //Added missing command(WD9DMP)
  port_to_use->println(F("\\)\t\t: Send serial number with cut numbers, then increment")); //Added missing command(WD9DMP)
  port_to_use->println(F("\\[\t\t: Set quiet paddle interruption - 0 to 20 element lengths; 0 = off")); //Added missing command(WD9DMP)
  #ifdef FEATURE_AMERICAN_MORSE
    port_to_use->println(F("\\=\t\t: Toggle American Morse mode")); //Added missing command(WD9DMP)
  #endif
  #ifdef FEATURE_POTENTIOMETER
    port_to_use->println(F("\\}####\t\t: Set Potentiometer range"));
  #endif //FEATURE_POTENTIOMETER  
  #if !defined(OPTION_EXCLUDE_MILL_MODE)
    port_to_use->println(F("\\@\t\t: Mill Mode"));
  #endif
  port_to_use->println(F("\\\\\t\t: Empty keyboard send buffer")); //Moved to end of command list (WD9DMP)
  if (paged_help) {serial_page_pause(port_to_use,10);}
  //Memory Macros below (WD9DMP)
  #ifdef FEATURE_MEMORY_MACROS
  port_to_use->println(F("\nMemory Macros:"));
  port_to_use->println(F("\\#\t\t: Jump to memory #"));
  port_to_use->println(F("\\C\t\t: Send serial number with cut numbers, then increment"));//Added "then increment" (WD9DMP)
  port_to_use->println(F("\\D###\t\t: Delay for ### seconds"));
  port_to_use->println(F("\\E\t\t: Send serial number, then increment"));//Added "then increment" (WD9DMP)
  port_to_use->println(F("\\F####\t\t: Set sidetone to #### hz"));
  #ifdef FEATURE_HELL
    port_to_use->println(F("\\H\t\t: Switch to Hell mode"));
  #endif //FEATURE_HELL
  port_to_use->println(F("\\I\t\t: Insert memory #"));//Added missing macro (WD9DMP)
  #ifdef FEATURE_HELL
    port_to_use->println(F("\\L\t\t: Switch to CW (from Hell mode)"));
  #endif //FEATURE_HELL    
  port_to_use->println(F("\\N\t\t: Decrement serial number - do not send"));//Added "do not send" (WD9DMP)
  port_to_use->println(F("\\Q##\t\t: Switch to QRSS with ## second dit length"));
  port_to_use->println(F("\\R\t\t: Switch to regular speed mode"));
  port_to_use->println(F("\\S\t\t: Insert space"));//Added missing macro (WD9DMP)
  port_to_use->println(F("\\T###\t\t: Transmit for ### seconds"));
  port_to_use->println(F("\\U\t\t: Key PTT")); //Upper case to first letter only(WD9DMP)
  port_to_use->println(F("\\V\t\t: Unkey PTT")); //Upper case to first letter only(WD9DMP)
  port_to_use->println(F("\\W###\t\t: Change WPM to ###"));
  port_to_use->println(F("\\X#\t\t: Switch to transmitter #"));
  port_to_use->println(F("\\Y#\t\t: Increase speed # WPM"));
  port_to_use->println(F("\\Z#\t\t: Decrease speed # WPM"));
  port_to_use->println(F("\\+\t\t: Prosign the next two characters"));//Added "the next two characters" (WD9DMP)
  #endif //FEATURE_MEMORY_MACROS
  
  #if !defined(OPTION_EXCLUDE_EXTENDED_CLI_COMMANDS)
    if (paged_help) {serial_page_pause(port_to_use,10);}
    port_to_use->println(F("\r\n\\:\tExtended CLLI commands"));
    port_to_use->println(F("\t\teepromdump\t\t- do a byte dump of EEPROM for troubleshooting"));
    port_to_use->println(F("\t\tsaveeeprom <filename>\t- store EEPROM in a file"));
    port_to_use->println(F("\t\tloadeeprom <filename> \t- load into EEPROM from a file"));
    port_to_use->println(F("\t\tprintlog\t\t- print the SD card log"));
    port_to_use->println(F("\t\tclearlog\t\t- clear the SD card log"));
    port_to_use->println(F("\t\tls <directory>\t\t- list files in SD card directory"));
    port_to_use->println(F("\t\tcat <filename>\t\t- print filename on SD card"));
    port_to_use->println(F("\t\tpl <transmitter> <mS>\t- Set PTT lead time"));
    port_to_use->println(F("\t\tpt <transmitter> <mS> \t- Set PTT tail time"));
  #endif //OPTION_EXCLUDE_EXTENDED_CLI_COMMANDS


  port_to_use->println(F("\r\n\\/\t\t: Paginated help"));

}
#endif
//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void process_serial_command(PRIMARY_SERIAL_CLS * port_to_use) {
  
  int user_input_temp = 0;

  #ifdef FEATURE_AMERICAN_MORSE
    static int previous_dah_to_dit_ratio = 300;
  #endif //FEATURE_AMERICAN_MORSE
        
  //port_to_use->println();
  switch (incoming_serial_byte) {
    case '~':
      #if defined(__AVR__)
        asm volatile ("jmp 0"); /*wdt_enable(WDTO_30MS); while(1) {} ;*/ 
      #else //__AVR__
        setup();
      #endif //__AVR__
      break;  // ~ - reset unit
    case '*':                                                // * - paddle echo on / off
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
    case '+': cli_prosign_flag = 1; break;
    #if defined(FEATURE_SERIAL_HELP)
      case '?': print_serial_help(port_to_use,0); break;                         // ? = print help
      case '/': print_serial_help(port_to_use,1); break;                         // / = paged help
    #endif //FEATURE_SERIAL_HELP
    case 'A':  // A - Iambic A mode
      configuration.keyer_mode = IAMBIC_A; 
      configuration.dit_buffer_off = 0;
      configuration.dah_buffer_off = 0;
      config_dirty = 1; 
      port_to_use->println(F("\r\nIambic A")); 
      break;    
    case 'B':  // B - Iambic B mode
      configuration.keyer_mode = IAMBIC_B;
      configuration.dit_buffer_off = 0;
      configuration.dah_buffer_off = 0;      
      config_dirty = 1;
      port_to_use->println(F("\r\nIambic B")); 
      break;    
    case 'C':  // C - single paddle mode
      configuration.keyer_mode = SINGLE_PADDLE; 
      config_dirty = 1; port_to_use->println(F("\r\nSingle Paddle")); 
      break;    
    case 'D': // D - Ultimatic mode
      configuration.keyer_mode = ULTIMATIC; 
      configuration.dit_buffer_off = 1;
      configuration.dah_buffer_off = 1;        
      config_dirty = 1; 
      port_to_use->println(F("\r\nUltimatic")); 
      break;  
    case 'E': serial_set_serial_number(port_to_use); break;                                   // E - set serial number
    case 'F': serial_set_sidetone_freq(port_to_use); break;                                   // F - set sidetone frequency
    case 'G': configuration.keyer_mode = BUG; config_dirty = 1; port_to_use->println(F("\r\nBug")); break;              // G - Bug mode
    #ifdef FEATURE_HELL
      case 'H': // H - Hell mode
        if ((char_send_mode == CW) || (char_send_mode == AMERICAN_MORSE)){
          char_send_mode = HELL; port_to_use->println(F("\r\nHell mode"));
        } else {
          char_send_mode = CW; port_to_use->println(F("\r\nCW mode"));
        }  
        break;         
    #endif //FEATURE_HELL
    #ifdef FEATURE_AMERICAN_MORSE
      case '=': // = - American Morse
        if ((char_send_mode == CW) || (char_send_mode == HELL)){
          char_send_mode = AMERICAN_MORSE; port_to_use->println(F("\r\nAmerican Morse mode"));
          previous_dah_to_dit_ratio = configuration.dah_to_dit_ratio;
          configuration.dah_to_dit_ratio = 200;
        } else {
          char_send_mode = CW; port_to_use->println(F("\r\nInternational CW mode"));
          configuration.dah_to_dit_ratio = previous_dah_to_dit_ratio;
        }  
        break;         
    #endif //FEATURE_AMERICAN_MORSE


    case 'I':                                                                      // I - transmit line on/off
      //port_to_use->print(F("\r\nTX o")); //WD9DMP-1
      if (key_tx && keyer_machine_mode != KEYER_COMMAND_MODE) { //Added check that keyer is NOT in command mode or keyer might be enabled for paddle commands (WD9DMP-1)
        key_tx = 0;
        port_to_use->println(F("\r\nTX off")); //WD9DMP-1
      } else if (!key_tx && keyer_machine_mode != KEYER_COMMAND_MODE) { //Added check that keyer is NOT in command mode or keyer might be enabled for paddle commands (WD9DMP-1)
        key_tx = 1;
        port_to_use->println(F("\r\nTX on")); //WD9DMP-1
      }
      else {port_to_use->print(F("\r\nERROR: Keyer in Command Mode\r\n"));} //Print error message if keyer in Command Mode and user tries to change tx line(s) on/off. (WD9DMP-1)
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
    case 'Q': serial_qrss_mode(); break; // Q - activate QRSS mode
    case 'R': speed_mode = SPEED_NORMAL; port_to_use->println(F("\r\nQRSS Off")); break; // R - activate regular timing mode
    case 'S': serial_status(port_to_use); break;                                              // S - Status command
    case 'J': serial_set_dit_to_dah_ratio(port_to_use); break;                          // J - dit to dah ratio
    #ifdef FEATURE_TRAINING_COMMAND_LINE_INTERFACE
      case 'K': serial_cw_practice(port_to_use); break;                     // K - CW practice
    #endif //FEATURE_TRAINING_COMMAND_LINE_INTERFACE
    case 'L': serial_set_weighting(port_to_use); break;
    #ifdef FEATURE_FARNSWORTH
      case 'M': serial_set_farnsworth(port_to_use); break;                                // M - set Farnsworth speed
    #endif
    case 'N':                                                                // N - paddle reverse
      port_to_use->print(F("\r\nPaddles "));
      if (configuration.paddle_mode == PADDLE_NORMAL) {
        configuration.paddle_mode = PADDLE_REVERSE;
        port_to_use->println(F("reversed"));
      } else {
        configuration.paddle_mode = PADDLE_NORMAL;
        port_to_use->println(F("normal"));
      }
      config_dirty = 1;
    break;
    case 'O': // O - cycle through sidetone modes on, paddle only and off - enhanced by Marc-Andre, VE2EVN
      port_to_use->print(F("\r\nSidetone "));
      if (configuration.sidetone_mode == SIDETONE_PADDLE_ONLY) {
        configuration.sidetone_mode = SIDETONE_OFF;
        boop();      
        port_to_use->println(F("OFF"));
      } else if (configuration.sidetone_mode == SIDETONE_ON) {
        configuration.sidetone_mode = SIDETONE_PADDLE_ONLY;
        beep();
        delay(200);
        beep();
        port_to_use->println(F("PADDLE ONLY"));
      } else {
        configuration.sidetone_mode = SIDETONE_ON;
        beep();
        port_to_use->println(F("ON"));
      }
      config_dirty = 1;
    break;


    case 'T': // T - tune
      #ifdef FEATURE_MEMORIES
        repeat_memory = 255;
      #endif
      serial_tune_command(port_to_use); break;
    case 'U':
      port_to_use->print(F("\r\nPTT o"));
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
      case 'V':                // V - toggle pot activation
        port_to_use->print(F("\r\nPotentiometer "));
        configuration.pot_activated = !configuration.pot_activated;
        if (configuration.pot_activated) {
          port_to_use->print(F("A"));
        } else {
          port_to_use->print(F("Dea"));
        }
        port_to_use->println(F("ctivated"));
        config_dirty = 1;
        break;
      case '}':
        serial_set_pot_low_high(port_to_use);
        break;
    #endif
    case 'W': serial_wpm_set(port_to_use);break;                                        // W - set WPM
    case 'X': serial_switch_tx(port_to_use);break;                                      // X - switch transmitter
    case 'Y': serial_change_wordspace(port_to_use); break;
    #ifdef FEATURE_AUTOSPACE
      case 'Z':
        port_to_use->print(F("\r\nAutospace O"));
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
    
    case 92:  // \ - double backslash - clear serial send buffer
      clear_send_buffer();
      #if defined(OPTION_ENABLE_SERIAL_PORT_CHECKING_WHILE_SENDING_CW_MAY_CAUSE_PROBLEMS)
        loop_element_lengths_breakout_flag = 0;
      #endif
      #ifdef FEATURE_MEMORIES
        play_memory_prempt = 1;
        repeat_memory = 255;
      #endif
      break;                           
  
    case '^':                           // ^ - toggle send CW send immediately
       if (cli_wait_for_cr_to_send_cw) {
         cli_wait_for_cr_to_send_cw = 0;
         port_to_use->println(F("\r\nSend CW immediately"));
       } else {
         cli_wait_for_cr_to_send_cw = 1;
         port_to_use->println(F("\r\nWait for CR to send CW"));
       }
      break;
    #ifdef FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
      case '&':
        port_to_use->print(F("\r\nCMOS Super Keyer Timing O"));
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
        user_input_temp = serial_get_number_input(2,-1,100,port_to_use, RAISE_ERROR_MSG);
        if ((user_input_temp >= 0) && (user_input_temp < 100)) {
          configuration.cmos_super_keyer_iambic_b_timing_percent = user_input_temp;
          port_to_use->println(F("\r\nCMOS Super Keyer Timing Set."));
        }
        config_dirty = 1;
        break;
    #endif //FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
    case '.':
      port_to_use->print(F("\r\nDit Buffer O"));
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
      port_to_use->print(F("\r\nDah Buffer O"));
      if (configuration.dah_buffer_off) {
        configuration.dah_buffer_off = 0;
        port_to_use->println(F("n"));
      } else {
        configuration.dah_buffer_off = 1;
        port_to_use->println(F("ff"));
      }
      config_dirty = 1;    
      break;
    case ';':
      if (cw_send_echo_inhibit) cw_send_echo_inhibit = 0; else cw_send_echo_inhibit = 1;
      break;
    #ifdef FEATURE_QLF
      case '{':
        port_to_use->print(F("\r\nQLF: O"));
        if (qlf_active){
            qlf_active = 0;
            port_to_use->println(F("ff"));
          } else {
            qlf_active = 1;
            port_to_use->println(F("n"));
          }
        break;
    #endif //FEATURE_QLF

    case '>':
      send_serial_number(0,1,1);
      break;
    case '<': 
      send_serial_number(0,0,1);
      break;
    case '(':
      send_serial_number(1,0,1);
      break;
    case ')':
      send_serial_number(1,1,1);
      break;
    case '[':
      user_input_temp = serial_get_number_input(2,-1,21,port_to_use,RAISE_ERROR_MSG);
      if ((user_input_temp >= 0) && (user_input_temp < 21)) {
        configuration.paddle_interruption_quiet_time_element_lengths = user_input_temp;
        port_to_use->println(F("\r\nPaddle Interruption Quiet Time set."));
      }
      config_dirty = 1;      
      break;
    #if !defined(OPTION_EXCLUDE_MILL_MODE)
      case '@':
        switch(configuration.cli_mode){
          case CLI_NORMAL_MODE:
            configuration.cli_mode = CLI_MILL_MODE_KEYBOARD_RECEIVE;
            port_to_use->println(F("\r\nMill Mode On"));
            break;
          case CLI_MILL_MODE_PADDLE_SEND:
          case CLI_MILL_MODE_KEYBOARD_RECEIVE:
            configuration.cli_mode = CLI_NORMAL_MODE;
            port_to_use->println(F("\r\nMill Mode Off"));
            break;  
        }  
        config_dirty = 1;
        break;
    #endif // !defined(OPTION_EXCLUDE_MILL_MODE)
    case '"':
      port_to_use->print(F("\r\nPTT buffered character hold active O"));
      if (configuration.ptt_buffer_hold_active){
        configuration.ptt_buffer_hold_active = 0;
        port_to_use->println(F("ff"));
      } else {
        configuration.ptt_buffer_hold_active = 1;
        port_to_use->println(F("n"));
      }
      config_dirty = 1;
      break;
    #if !defined(OPTION_EXCLUDE_EXTENDED_CLI_COMMANDS) 
    case ':':
      cli_extended_commands(port_to_use);
      break;    
    #endif 

    default: port_to_use->println(F("\r\nUnknown command")); break;
  }

}
#endif //defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)


//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && !defined(OPTION_EXCLUDE_EXTENDED_CLI_COMMANDS)
void cli_extended_commands(PRIMARY_SERIAL_CLS * port_to_use)
{
  byte incoming_serial_byte = 0;
  byte looping = 1;
  String userinput = "";

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
      port_to_use->write(incoming_serial_byte);
      if ((incoming_serial_byte == 8) || (incoming_serial_byte == 127)){   // backspace / DEL
        userinput.remove(userinput.length()-1,1);
      }        
      incoming_serial_byte = uppercase(incoming_serial_byte);
      if ((incoming_serial_byte > 31) && (incoming_serial_byte < 127)) {
        userinput.concat((char)incoming_serial_byte);
      }
      if (incoming_serial_byte == 13) {   // carriage return - get out
        looping = 0;
      }
    }
  } //while (looping)

  if (userinput.startsWith("EEPROMDUMP")){cli_eeprom_dump(port_to_use);return;}
  if (userinput.startsWith("TIMING")){cli_timing_print(port_to_use);return;}
  if (userinput.startsWith("PL ")){cli_timing_command(port_to_use,userinput.substring(3),COMMAND_PL);return;}
  if (userinput.startsWith("PT ")){cli_timing_command(port_to_use,userinput.substring(3),COMMAND_PT);return;}
  #if defined(FEATURE_SEQUENCER)
    if (userinput.startsWith("PA ")){cli_timing_command(port_to_use,userinput.substring(3),COMMAND_PA);return;}
    if (userinput.startsWith("PI ")){cli_timing_command(port_to_use,userinput.substring(3),COMMAND_PI);return;}
  #endif //FEATURE_SEQUENCER
  #if defined(FEATURE_SD_CARD_SUPPORT)
    if (userinput.startsWith("SAVEEEPROM ")){sd_card_save_eeprom_to_file(port_to_use,userinput.substring(11));return;}
    if (userinput.startsWith("LOADEEPROM ")){sd_card_load_eeprom_from_file(port_to_use,userinput.substring(11));return;}
    if (userinput.startsWith("PRINTLOG")){sd_card_print_file(port_to_use,"/keyer/keyer.log");return;}
    if (userinput.startsWith("CLEARLOG")){sd_card_clear_log_file(port_to_use,"/keyer/keyer.log");return;}
    if (userinput.startsWith("LS ")){cli_sd_ls_command(port_to_use,userinput.substring(3));return;}
    if (userinput.startsWith("CAT ")){sd_card_print_file(port_to_use,userinput.substring(4));return;}    
  #endif // defined(FEATURE_SD_CARD_SUPPORT)

  port_to_use->println(F("\r\nError"));

}
#endif
//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && !defined(OPTION_EXCLUDE_EXTENDED_CLI_COMMANDS)
void cli_timing_command(PRIMARY_SERIAL_CLS * port_to_use,String command_arguments,byte command_called){

  byte valid_command = 0;
  unsigned int parm1 = 0;
  unsigned int parm2 = 0;
  String temp_string;

  temp_string = command_arguments.substring(0,1);
  parm1 = temp_string.toInt();
  temp_string = command_arguments.substring(2);
  parm2 = temp_string.toInt();
  if ((command_called == COMMAND_PL) || (command_called == COMMAND_PT)){
    if ((parm1 > 0) && (parm1 < 7)){
      if (command_called == COMMAND_PL){
        configuration.ptt_lead_time[parm1 - 1] = parm2;
      } else {
        configuration.ptt_tail_time[parm1 - 1] = parm2;
      }
      valid_command = 1;
    }    
  }

  #if defined(FEATURE_SEQUENCER)
    if ((command_called == COMMAND_PA) || (command_called == COMMAND_PI)){
      if ((parm1 > 0) && (parm1 < 6)){
        if (command_called == COMMAND_PA){
          configuration.ptt_active_to_sequencer_active_time[parm1 - 1] = parm2;
        } else {
          configuration.ptt_inactive_to_sequencer_inactive_time[parm1 - 1] = parm2;
        }
        valid_command = 1;
      }    
    }
  #endif //FEATURE_SEQUENCER

  if (!valid_command){
    port_to_use->println(F("\r\nError."));
  } else {
    config_dirty = 1;
  }

}
#endif //defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && !defined(OPTION_EXCLUDE_EXTENDED_CLI_COMMANDS)
//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && !defined(OPTION_EXCLUDE_EXTENDED_CLI_COMMANDS)
void cli_timing_print(PRIMARY_SERIAL_CLS * port_to_use){


  port_to_use->println(F("\r\nTimings (mS)"));
  port_to_use->println(F("\r\nPTT"));
  port_to_use->println(F("TX\tLead\tTail"));
  port_to_use->println(F("--\t----\t----"));
  for (int x = 0; x < 6; x++){
    port_to_use->print(x+1);
    port_to_use->print("\t");
    port_to_use->print(configuration.ptt_lead_time[x]);
    port_to_use->print("\t");
    port_to_use->println(configuration.ptt_tail_time[x]);
  }
  #if defined(FEATURE_SEQUENCER)
  port_to_use->println(F("\r\nSequencer"));
  port_to_use->println(F("#\tPTT Active to Sequencer Active\tPTT Inactive to Sequencer Inactive"));
  port_to_use->println(F("-\t------------------------------\t----------------------------------"));
  for (int x = 0; x < 5; x++){
    port_to_use->print(x+1);
    port_to_use->print("\t\t\t");
    port_to_use->print(configuration.ptt_active_to_sequencer_active_time[x]);
    port_to_use->print("\t\t\t\t");
    port_to_use->println(configuration.ptt_inactive_to_sequencer_inactive_time[x]);
  }  
  #endif //FEATURE_SEQUENCER
  port_to_use->println(F("\r\nCommand Hints\r\n"));
  port_to_use->println(F("pl <transmitter> <mS>\tSet PTT lead time"));
  port_to_use->println(F("pt <transmitter> <mS>\tSet PTT tail time"));
  #if defined(FEATURE_SEQUENCER)
    port_to_use->println(F("pa <#> <mS>\t\tSet PTT active to Sequencer active time"));
    port_to_use->println(F("pi <#> <mS>\t\tSet PTT inactive to Sequencer inactive time"));
  #endif //FEATURE_SEQUENCER

}
#endif //defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && !defined(OPTION_EXCLUDE_EXTENDED_CLI_COMMANDS)

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && !defined(OPTION_EXCLUDE_EXTENDED_CLI_COMMANDS)  && defined(FEATURE_SD_CARD_SUPPORT)
void cli_sd_ls_command(PRIMARY_SERIAL_CLS * port_to_use,String directory){

  port_to_use->println();

  File dir = SD.open(directory);

  while (true) {
    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    if (entry.isDirectory()) {
      port_to_use->print("/");
      port_to_use->println(entry.name());
    } else {
      // files have sizes, directories do not
      port_to_use->print(entry.name());
      port_to_use->print("\t\t");
      port_to_use->println(entry.size(), DEC);
    }
    entry.close();
  }
}
#endif //defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && !defined(OPTION_EXCLUDE_EXTENDED_CLI_COMMANDS)  && defined(FEATURE_SD_CARD_SUPPORT)

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && !defined(OPTION_EXCLUDE_EXTENDED_CLI_COMMANDS) && defined(FEATURE_SD_CARD_SUPPORT)
void sd_card_clear_log_file(PRIMARY_SERIAL_CLS * port_to_use,String filename) {

  if(sd_card_log_state == SD_CARD_LOG_OPEN){
    sdlogfile.close();
  }
  SD.remove(filename);
  sdlogfile = SD.open(filename,FILE_WRITE);
  sd_card_log_state = SD_CARD_LOG_NOT_OPEN;
  if (!sdfile){
    port_to_use->println(F("Unable to open file "));
    sd_card_state = SD_CARD_ERROR;
    sd_card_log_state = SD_CARD_LOG_ERROR;
  }
  sdlogfile.close();

}
#endif
//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && !defined(OPTION_EXCLUDE_EXTENDED_CLI_COMMANDS) && defined(FEATURE_SD_CARD_SUPPORT)
void sd_card_print_file(PRIMARY_SERIAL_CLS * port_to_use,String filename) {

  sdfile = SD.open(filename);
  if (!sdfile){
    port_to_use->print(F("Unable to open file "));
    port_to_use->println(filename);
  } else {
    port_to_use->println(F("\r\nSTART"));
    while(sdfile.available()){
      port_to_use->write(sdfile.read());
    }
    port_to_use->println(F("\r\nEND"));
  }

}
#endif
//---------------------------------------------------------------------


#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && !defined(OPTION_EXCLUDE_EXTENDED_CLI_COMMANDS) && defined(FEATURE_SD_CARD_SUPPORT)
void sd_card_load_eeprom_from_file(PRIMARY_SERIAL_CLS * port_to_use,String filename) {

  uint8_t eeprom_byte_;
  unsigned int x;



  sdfile = SD.open(filename, FILE_READ);

  if (sdfile) {
    port_to_use->print(F("Loading eeprom from "));
    port_to_use->print(filename);
  } else {
    port_to_use->println(F("Error opening file.  Exiting."));
    return;
  }

  for (x = 0; x < memory_area_end; x++) {
    if (sdfile.available()){
      EEPROM.write(x,sdfile.read());
      if ((x % 16) == 0){port_to_use->print("#");}
    } else {
      x = memory_area_end;
      port_to_use->println(F("\r\nHit end of file before end of eeprom"));
    }
  }

  sdfile.close();
  port_to_use->println(F("\r\nReading settings from eeprom."));
  read_settings_from_eeprom();
  port_to_use->println(F("Done."));



}

#endif //defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && !defined(OPTION_EXCLUDE_EXTENDED_CLI_COMMANDS) && defined(FEATURE_SD_CARD_SUPPORT)

//---------------------------------------------------------------------


#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && !defined(OPTION_EXCLUDE_EXTENDED_CLI_COMMANDS) && defined(FEATURE_SD_CARD_SUPPORT)
void sd_card_save_eeprom_to_file(PRIMARY_SERIAL_CLS * port_to_use,String filename) {

  uint8_t eeprom_byte_in;
  unsigned int x;

  SD.remove(filename);
  sdfile = SD.open(filename, FILE_WRITE);

  if (sdfile) {
    port_to_use->print(F("Writing to "));
    port_to_use->print(filename);
  } else {
    port_to_use->println(F("Error opening file.  Exiting."));
    return;
  }

  for (x = 0; x < memory_area_end; x++) {
    eeprom_byte_in = EEPROM.read(x);
    sdfile.write(eeprom_byte_in);
    if ((x % 16) == 0){port_to_use->print(".");}
  }

  sdfile.close();
  port_to_use->println(F("Done."));

}

#endif //defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && d!defined(OPTION_EXCLUDE_EXTENDED_CLI_COMMANDS)
//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && !defined(OPTION_EXCLUDE_EXTENDED_CLI_COMMANDS)
void cli_eeprom_dump(PRIMARY_SERIAL_CLS * port_to_use){

  byte eeprom_byte_in;
  byte y = 0;
  int w = 0;
  int x = 0;

  #define EEPROM_DUMP_COLUMNS 32
  #define EEPROM_DUMP_LINES 30

  for (x = 0; x < memory_area_end; x++) {
    if (y == 0){
      port_to_use->print("\r\n");
      if (x < 0x1000){port_to_use->print("0");}
      if (x < 0x100){port_to_use->print("0");}
      if (x < 0x10){port_to_use->print("0");}
      port_to_use->print(x,HEX);
      port_to_use->print("\t");
    }
    eeprom_byte_in = EEPROM.read(x);
    if (eeprom_byte_in < 0x10){port_to_use->print("0");}
    port_to_use->print(eeprom_byte_in,HEX);
    port_to_use->write(" ");
    y++;
    if (y > (EEPROM_DUMP_COLUMNS - 1)){
      port_to_use->print("\t");
      for (int z = x - y; z < x; z++) {
        eeprom_byte_in = EEPROM.read(z);
        if ((eeprom_byte_in > 31) && (eeprom_byte_in < 127)){
          port_to_use->write(eeprom_byte_in);
        } else {
          port_to_use->print(".");
        }  
      }
      y = 0;
      w++;
      if (w > EEPROM_DUMP_LINES){
        port_to_use->println(F("\r\nPress enter..."));
        while(!port_to_use->available()){}
        while(port_to_use->available()){port_to_use->read();}
        w = 0;
      }
    }
  }
  if (y > 0){
    for (int z = (EEPROM_DUMP_COLUMNS - y); z > 0; z--){
      port_to_use->write("   ");
    }
    port_to_use->print("\t");
    for (int z = x - y; z < x; z++) {
      eeprom_byte_in = EEPROM.read(z);
      if ((eeprom_byte_in > 31) && (eeprom_byte_in < 127)){
        port_to_use->write(eeprom_byte_in);
      } else {
        port_to_use->print(".");
      }  
    }    
  }

}
#endif //defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && !defined(OPTION_EXCLUDE_EXTENDED_CLI_COMMANDS)
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

  #if defined(OPTION_PROSIGN_SUPPORT)
    byte byte_temp = 0;
    static char * prosign_temp = (char*)"";
  #endif
  
  #if defined(FEATURE_DISPLAY) && defined(OPTION_DISPLAY_NON_ENGLISH_EXTENSIONS)
    byte ascii_temp = 0;
  #endif //defined(FEATURE_DISPLAY) && defined(OPTION_DISPLAY_NON_ENGLISH_EXTENSIONS)

  
  #if defined(FEATURE_CW_COMPUTER_KEYBOARD)
    static byte backspace_flag = 0;
    if (paddle_echo_buffer == 111111) {paddle_echo_buffer_decode_time = 0; backspace_flag = 1;}  //this is a special hack to make repeating backspace work
  #endif //defined(FEATURE_CW_COMPUTER_KEYBOARD)
  
  #ifdef FEATURE_SD_CARD_SUPPORT
    char temp_string[2];
  #endif  

  
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
      #ifdef OPTION_CW_KEYBOARD_GERMAN  // DL1HTB changed sign AA for return to BK
      case 2111212:  // return prosign BK
      #else
      case 1212:  // prosign AA
      #endif //OPTION_CW_KEYBOARD_GERMAN // #end DL1HTB changed sign AA for return to BK
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
        
      #ifdef OPTION_CW_KEYBOARD_GERMAN  // DL1HTB added german keyboard mapping
        case 122121: // "@"
          Keyboard.press(KEY_RIGHT_ALT);
          Keyboard.write('q');
          Keyboard.releaseAll();
          break;
        case 112211: // "?"
          Keyboard.write(95);
          break;
        case 11221: // "!"
          Keyboard.write(33);
          break;
        case 21121: // "/"
          Keyboard.write(38);
          break;
        case 222222: // "\"
          Keyboard.press(KEY_RIGHT_ALT);
          Keyboard.write('-');
          Keyboard.releaseAll();
          // Keyboard.write(92);
          break;
        case 21112: // "=" or "BT"
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.write('0');
          Keyboard.releaseAll();
          break;
        case 1212: // "ä"
          Keyboard.write(39);  
          break;
        case 2221: // "ö"
          Keyboard.write(59);  
          break;
        case 1122: // "ü"
          Keyboard.write(91);  
          break;
        case 2222: // "ch"
          Keyboard.write(99);  
          Keyboard.write(104);  
          break;
        case 2122: // "y"
          Keyboard.write(122);  
          break;
        case 2211: // "z"
          Keyboard.write(121);  
          break;
        case 21221: // "("
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.write('8');
          Keyboard.releaseAll();
          break;
        case 212212: // ")"
          Keyboard.write(40);  
          break;
        case 12111: // "&" "AS"
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.write('6');
          Keyboard.releaseAll();
          break;
        case 222111: // ":"
          Keyboard.write(62);  
          break;
        case 212121: // ";"
          Keyboard.write(60);  
          break;
        case 12121: // "+"
          Keyboard.write(93);  
          break;
        case 211112: // "-"
          Keyboard.write(47);  
          break;   
      #endif //OPTION_CW_KEYBOARD_GERMAN // #end DL1HTB added german keyboard mapping
      
      default:
        character_to_send = convert_cw_number_to_ascii(paddle_echo_buffer);
        // if ((character_to_send > 64) && (character_to_send < 91)) {character_to_send = character_to_send + 32;}
        if ((cw_keyboard_capslock_on == 0) && (character_to_send > 64) && (character_to_send < 91)) {character_to_send = character_to_send + 32;}
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
        #if defined(OPTION_PROSIGN_SUPPORT)
          #ifndef OPTION_DISPLAY_NON_ENGLISH_EXTENSIONS
            byte_temp = convert_cw_number_to_ascii(paddle_echo_buffer);
            if ((byte_temp > PROSIGN_START) && (byte_temp < PROSIGN_END)){
              prosign_temp = convert_prosign(byte_temp);
              display_scroll_print_char(prosign_temp[0]);
              display_scroll_print_char(prosign_temp[1]);
            } else {
              display_scroll_print_char(byte(convert_cw_number_to_ascii(paddle_echo_buffer)));
            }
          #else //OPTION_DISPLAY_NON_ENGLISH_EXTENSIONS
            ascii_temp = byte(convert_cw_number_to_ascii(paddle_echo_buffer));
            if ((ascii_temp > PROSIGN_START) && (ascii_temp < PROSIGN_END)){
              prosign_temp = convert_prosign(ascii_temp);
              display_scroll_print_char(prosign_temp[0]);
              display_scroll_print_char(prosign_temp[1]);
            } else {
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
            }
          #endif //OPTION_DISPLAY_NON_ENGLISH_EXTENSIONS

        #else // ! OPTION_PROSIGN_SUPPORT

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

        #endif //OPTION_PROSIGN_SUPPORT



      }
    #endif //FEATURE_DISPLAY
    
    #if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
      #if defined(OPTION_PROSIGN_SUPPORT)
        byte_temp = convert_cw_number_to_ascii(paddle_echo_buffer);
        if (cli_paddle_echo){


          if ((byte_temp > PROSIGN_START) && (byte_temp < PROSIGN_END)){
            primary_serial_port->print(prosign_temp[0]);
            primary_serial_port->print(prosign_temp[1]);
            #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
              secondary_serial_port->print(prosign_temp[0]);
              secondary_serial_port->print(prosign_temp[1]);
            #endif //FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT                      
          } else {

            if (configuration.cli_mode == CLI_MILL_MODE_KEYBOARD_RECEIVE){
              primary_serial_port->println();
              primary_serial_port->println();
              #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
                secondary_serial_port->println();
                secondary_serial_port->println();
              #endif    
              #ifdef FEATURE_SD_CARD_SUPPORT
                sd_card_log("\r\nTX:",0);
              #endif                        
              configuration.cli_mode = CLI_MILL_MODE_PADDLE_SEND;
            }  
            primary_serial_port->write(byte_temp);
            #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT             
              secondary_serial_port->write(byte_temp);
            #endif //FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
            #ifdef FEATURE_SD_CARD_SUPPORT
              sd_card_log("",incoming_serial_byte);
            #endif                  
          }

        } 

      #else  // ! OPTION_PROSIGN_SUPPORT
        if (cli_paddle_echo){
          if (configuration.cli_mode == CLI_MILL_MODE_KEYBOARD_RECEIVE){
            primary_serial_port->println();
            primary_serial_port->println();
            #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
              secondary_serial_port->println();
              secondary_serial_port->println();
            #endif
            #ifdef FEATURE_SD_CARD_SUPPORT
              sd_card_log("\r\nTX:",0);
            #endif
            configuration.cli_mode = CLI_MILL_MODE_PADDLE_SEND;
          }
          primary_serial_port->write(byte(convert_cw_number_to_ascii(paddle_echo_buffer)));
          #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT      
            secondary_serial_port->write(byte(convert_cw_number_to_ascii(paddle_echo_buffer)));
          #endif
          #ifdef FEATURE_SD_CARD_SUPPORT
            sd_card_log("",convert_cw_number_to_ascii(paddle_echo_buffer));
          #endif            
        } 
      #endif //OPTION_PROSIGN_SUPPORT
    #endif //defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)   
   
    paddle_echo_buffer = 0;
    paddle_echo_buffer_decode_time = millis() + (float(600/configuration.wpm)*length_letterspace);
    paddle_echo_space_sent = 0;
  }
  
  // is it time to echo a space?
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

    #ifdef FEATURE_SD_CARD_SUPPORT
      sd_card_log(" ",0);
    #endif     
    
    paddle_echo_space_sent = 1;
  }
  
}
#endif //FEATURE_PADDLE_ECHO

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && defined(FEATURE_MEMORIES)
void serial_set_memory_repeat(PRIMARY_SERIAL_CLS * port_to_use) {

  int temp_int = serial_get_number_input(5, -1, 32000, port_to_use, RAISE_ERROR_MSG);
  if (temp_int > -1) {
    configuration.memory_repeat_time = temp_int;
    config_dirty = 1;
  }

}
#endif
//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && defined(FEATURE_MEMORIES)
void repeat_play_memory(PRIMARY_SERIAL_CLS * port_to_use) {

  byte memory_number = serial_get_number_input(2,0, (number_of_memories+1), port_to_use, RAISE_ERROR_MSG);
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
int serial_get_number_input(byte places,int lower_limit, int upper_limit,PRIMARY_SERIAL_CLS * port_to_use,int raise_error_message)
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
      port_to_use->write(incoming_serial_byte);
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
    if (raise_error_message == RAISE_ERROR_MSG){
      port_to_use->println(F("Error..."));
    }
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
      if (raise_error_message == RAISE_ERROR_MSG){
        port_to_use->println(F("Error..."));
      }
      return(-1);
    }
  }
}
#endif

//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_change_wordspace(PRIMARY_SERIAL_CLS * port_to_use)
{
  int set_wordspace_to = serial_get_number_input(2,0,100,port_to_use, RAISE_ERROR_MSG);
  if (set_wordspace_to > 0) {
    config_dirty = 1;
    configuration.length_wordspace = set_wordspace_to;
    port_to_use->write("\r\nWordspace set to ");
    port_to_use->println(set_wordspace_to,DEC);
  }
}
#endif

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_switch_tx(PRIMARY_SERIAL_CLS * port_to_use)
{
  int set_tx_to = serial_get_number_input(1,0,7,port_to_use,RAISE_ERROR_MSG);
  if (set_tx_to > 0) {
    switch (set_tx_to){
      case 1: switch_to_tx_silent(1); port_to_use->print(F("\r\nSwitching to TX #")); port_to_use->println(F("1")); break;
      case 2: if ((ptt_tx_2) || (tx_key_line_2)) {switch_to_tx_silent(2); port_to_use->print(F("\r\nSwitching to TX #"));} port_to_use->println(F("2")); break;
      case 3: if ((ptt_tx_3) || (tx_key_line_3)) {switch_to_tx_silent(3); port_to_use->print(F("\r\nSwitching to TX #"));} port_to_use->println(F("3")); break;
      case 4: if ((ptt_tx_4) || (tx_key_line_4)) {switch_to_tx_silent(4); port_to_use->print(F("\r\nSwitching to TX #"));} port_to_use->println(F("4")); break;
      case 5: if ((ptt_tx_5) || (tx_key_line_5)) {switch_to_tx_silent(5); port_to_use->print(F("\r\nSwitching to TX #"));} port_to_use->println(F("5")); break;
      case 6: if ((ptt_tx_6) || (tx_key_line_6)) {switch_to_tx_silent(6); port_to_use->print(F("\r\nSwitching to TX #"));} port_to_use->println(F("6")); break;
    }
  }
}
#endif

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_set_dit_to_dah_ratio(PRIMARY_SERIAL_CLS * port_to_use)
{
    int set_ratio_to = serial_get_number_input(4, 99, 1000, port_to_use, DONT_RAISE_ERROR_MSG);
    // if ((set_ratio_to > 99) && (set_ratio_to < 1000)) {
    //   configuration.dah_to_dit_ratio = set_ratio_to;
    //   port_to_use->print(F("Setting dah to dit ratio to "));
    //   port_to_use->println((float(configuration.dah_to_dit_ratio)/100));
    //   config_dirty = 1;
    // }

    if ((set_ratio_to < 100) || (set_ratio_to > 999)) {
      set_ratio_to = 300;
    }
    configuration.dah_to_dit_ratio = set_ratio_to;
    port_to_use->write("\r\nDah to dit ratio set to ");
    port_to_use->println((float(configuration.dah_to_dit_ratio)/100));
    config_dirty = 1;
   
}
#endif

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_set_serial_number(PRIMARY_SERIAL_CLS * port_to_use)
{
  int set_serial_number_to = serial_get_number_input(4,0,10000, port_to_use,RAISE_ERROR_MSG);
  if (set_serial_number_to > 0) {
    serial_number = set_serial_number_to;
    port_to_use->write("\r\nSetting serial number to ");
    port_to_use->println(serial_number);
  }
}
#endif

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && defined(FEATURE_POTENTIOMETER)
void serial_set_pot_low_high(PRIMARY_SERIAL_CLS * port_to_use)
{
  int serial_get_number = serial_get_number_input(4,500,10000, port_to_use,RAISE_ERROR_MSG);
  int low_number = (serial_get_number / 100);
  int high_number = serial_get_number % (int(serial_get_number / 100)*100);
  if ((low_number < high_number) && (low_number >= wpm_limit_low) && (high_number <= wpm_limit_high)){
    port_to_use->print(F("\r\nSetting potentiometer range to "));
    port_to_use->print(low_number);
    port_to_use->print(F(" - "));
    port_to_use->print(high_number);
    port_to_use->println(F(" WPM"));
    pot_wpm_low_value = low_number;
    pot_wpm_high_value = high_number;
  } else {
    port_to_use->println(F("\nError"));
  }
}
#endif

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_set_sidetone_freq(PRIMARY_SERIAL_CLS * port_to_use)
{
  int set_sidetone_hz = serial_get_number_input(4,(sidetone_hz_limit_low-1),(sidetone_hz_limit_high+1), port_to_use, RAISE_ERROR_MSG);
  if ((set_sidetone_hz > sidetone_hz_limit_low) && (set_sidetone_hz < sidetone_hz_limit_high)) {
    port_to_use->write("\r\nSetting sidetone to ");
    port_to_use->print(set_sidetone_hz,DEC);
    port_to_use->println(F(" hz"));
    configuration.hz_sidetone = set_sidetone_hz;
    config_dirty = 1;
  }
}
#endif

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_wpm_set(PRIMARY_SERIAL_CLS * port_to_use)
{
  int set_wpm = serial_get_number_input(3,0,1000, port_to_use, RAISE_ERROR_MSG);
  if (set_wpm > 0) {
    speed_set(set_wpm);
    port_to_use->write("\r\nSetting WPM to ");
    port_to_use->println(set_wpm,DEC);
    config_dirty = 1;
  }
}
#endif

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE) && defined(FEATURE_FARNSWORTH)
void serial_set_farnsworth(PRIMARY_SERIAL_CLS * port_to_use)
{
  int set_farnsworth_wpm = serial_get_number_input(3,-1,1000, port_to_use, RAISE_ERROR_MSG);
  if ((set_farnsworth_wpm > 0) || (set_farnsworth_wpm == 0)) {
    configuration.wpm_farnsworth = set_farnsworth_wpm;
    port_to_use->write("\r\nSetting Farnsworth WPM to ");
    port_to_use->println(set_farnsworth_wpm,DEC);
    config_dirty = 1;
  }
}
#endif

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_set_weighting(PRIMARY_SERIAL_CLS * port_to_use)
{
  int set_weighting = serial_get_number_input(2,9,91,port_to_use, DONT_RAISE_ERROR_MSG);
  if (set_weighting < 1) {
    set_weighting = 50;
  }
  configuration.weighting = set_weighting;
  port_to_use->write("\r\nSetting weighting to ");
  port_to_use->println(set_weighting,DEC);
}
#endif

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_tune_command (PRIMARY_SERIAL_CLS * port_to_use)
{
  byte incoming;

  delay(100);
  while (port_to_use->available() > 0) {  // clear out the buffer if anything is there
    incoming = port_to_use->read();
  }

  sending_mode = MANUAL_SENDING;
  tx_and_sidetone_key(1);
  port_to_use->println(F("\r\nKeying tx - press a key to unkey"));
  #ifdef FEATURE_COMMAND_BUTTONS
    while ((port_to_use->available() == 0) && (!analogbuttonread(0))) {}  // keystroke or button0 hit gets us out of here
  #else
    while (port_to_use->available() == 0) {}
  #endif
  while (port_to_use->available() > 0) {  // clear out the buffer if anything is there
    incoming = port_to_use->read();
  }
  tx_and_sidetone_key(0);

}
#endif
//---------------------------------------------------------------------
#ifdef FEATURE_TRAINING_COMMAND_LINE_INTERFACE

String generate_callsign(byte callsign_mode) {

  static String callsign(10);
  char nextchar;
  char word_buffer[10];

  callsign = "";

  if (callsign_mode == CALLSIGN_INTERNATIONAL){
    if (random(1,101) < 96) {
      // start with a letter 96% of the time
      nextchar = random(65,91);
      callsign = callsign + nextchar;
      if (random(1,101) < 20) {   // randomly add second prefix letter 20% of the time
        nextchar = random(65,91);
        callsign = callsign + nextchar;
      }
    } else {
      // start with a number
      nextchar = random(49,58);    // generate the number
      callsign = callsign + nextchar;
      nextchar = random(65,91);   // must add a letter next
      callsign = callsign + nextchar;
    }
  } //CALLSIGN_INTERNATIONAL

  if (callsign_mode == CALLSIGN_US){
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
      // randomly add a second letter for K, W, N prefixes
      if (random(1,101) < 51) {
        nextchar = random(65,91);
        callsign = callsign + nextchar;
      }
    }
  } //CALLSIGN_US

  if (callsign_mode == CALLSIGN_CANADA){
    strcpy_P(word_buffer, (char*)pgm_read_word(&(canadian_prefix_table[random(0,canadian_prefix_size)])));
    callsign = word_buffer;
  }

  if (callsign_mode == CALLSIGN_EUROPEAN){

    strcpy_P(word_buffer, (char*)pgm_read_word(&(eu_prefix_table[random(0,eu_prefix_size)])));
    callsign = word_buffer;
  }

  if (callsign_mode != CALLSIGN_CANADA){
    nextchar = random(48,58);               // generate the number
    callsign = callsign + nextchar;
  }


  nextchar = random(65,91);               // generate first letter after number
  callsign = callsign + nextchar;
  if ((random(1,101) < 40) || (callsign_mode == CALLSIGN_CANADA)) {                  // randomly put a second character after the number
    nextchar = random(65,91);
    callsign = callsign + nextchar;
    if ((random(1,101) < 96) || (callsign_mode == CALLSIGN_CANADA)) {              // randomly put a third character after the number
      nextchar = random(65,91);
      callsign = callsign + nextchar;
    }
  }

  if (random(1,101) < 10) {                // randomly put a slash something on the end like /QRP or /#
    if (random(1,101) < 25) {
      callsign = callsign + "/QRP";
    } else {
       nextchar = random(48,58);
       callsign = callsign + "/" + nextchar;
    }
  }

  return callsign;
}

#endif //FEATURE_TRAINING_COMMAND_LINE_INTERFACE
//---------------------------------------------------------------------
// #if defined(FEATURE_SERIAL) && defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE) && defined(FEATURE_COMMAND_LINE_INTERFACE)
// void paqso_practice(PRIMARY_SERIAL_CLS * port_to_use){
  
//   // VT100 emulation in Linux: screen /dev/ttyACM1 115200 term vt100
  
  
//   #define CONTEST_PRACTICE_IDLE 0
//   #define CONTEST_PRACTICE_CQ_SENT 1
//   #define CONTEST_PRACTICE_REPORT_SENT 2
  
  
//   #define FIELD_CALLSIGN 0
//   #define FIELD_NR 1
//   #define FIELD_SECTION 2
  
  
//   byte overall_state = CONTEST_PRACTICE_IDLE;
//   byte loop1 = 1;
//   byte user_input_buffer[10];
//   byte user_input_buffer_characters = 0;
//   byte incoming_char = 0;
//   byte process_user_input_buffer = 0;
//   unsigned long escape_flag_time = 0;
//   String callsign;
//   String nr;
//   String section;
//   byte cq_answered = 0;
//   unsigned long transition_time = 0;
//   byte current_field = FIELD_CALLSIGN;

//   int previous_sidetone = configuration.hz_sidetone;
//   int previous_wpm = configuration.wpm;
//   int caller_sidetone = 0;
//   int caller_wpm_delta = 0;

//   while (port_to_use->available() > 0) {  // clear out the buffer if anything is there
//     port_to_use->read();
//   }  

//   term.init();
//   term.cls(); 
//   term.position(0,0);  
//   term.println(F("\nPA QSO Party Practice\n"));
//   term.println(F("This requires VT100 emulation!\n"));
//   term.println(F("F1 - Call CQ"));
//   term.println(F("F2 - Exchange"));
//   term.println(F("F3 - TU"));
//   term.println(F("Insert - Callsign + Exchange"));
//   term.println(F("\\ - Exit\n"));
//   term.println(F("Callsign  NR  Section"));
//   term.println(F("-------- ---- -------\n\n"));    
  
//   while (loop1){
    
    
//     // get user keyboard input
//     if (port_to_use->available()){      
//       user_input_buffer[user_input_buffer_characters] = toupper(port_to_use->read());
//       switch(user_input_buffer[user_input_buffer_characters]){                    
//         case 27: //escape
//           escape_flag_time = millis();
//           user_input_buffer_characters++;
//         case 13: //return
//         case 32: //space
//           process_user_input_buffer = 1;
//           break;
//         case 127:
//         case 8: //backspace
//           if (user_input_buffer_characters > 0){user_input_buffer_characters--;}
//           port_to_use->write(27);
//           port_to_use->write(91);
//           port_to_use->write(49);
//           port_to_use->write(68);
//           break;

          
//         default:
//           if (!(((user_input_buffer[user_input_buffer_characters-1] == 27) && (user_input_buffer[user_input_buffer_characters] == 79) && (user_input_buffer_characters>0)) ||
//           ((user_input_buffer[user_input_buffer_characters-2] == 27) && (user_input_buffer[user_input_buffer_characters-1] == 79) && (user_input_buffer_characters>1)))){
//             port_to_use->write(user_input_buffer[user_input_buffer_characters]);
//           }
//           user_input_buffer_characters++;
//           break;                 
//       } //switch(user_input_buffer[user_input_buffer_characters])
//       if (user_input_buffer_characters == 10){process_user_input_buffer = 1;}
        
//     }//(port_to_use->available())
    
    
//     // process user keyboard input
//     if ((process_user_input_buffer) && ((escape_flag_time == 0) || ((millis()-escape_flag_time) > 100))){ 
   
//       #ifdef DEBUG_CW_PRACTICE
//       debug_serial_port->print(F("escape_flag_time: process_user_input_buffer user_input_buffer_characters:"));
//       debug_serial_port->println(user_input_buffer_characters);
//       #endif
      
//       if (user_input_buffer_characters > 0){
//         if (user_input_buffer[0] == '\\'){  // does user want to exit?
//           loop1 = 0;
//         } else {
//           if (user_input_buffer[0] == 27){
//             if (user_input_buffer_characters == 3){
//               if ((user_input_buffer[1] == 79) && (user_input_buffer[2] == 80)) {  //VT100 F1 key
//                 configuration.hz_sidetone = previous_sidetone;
//                 configuration.wpm = previous_wpm;
//                 add_to_send_buffer('C');
//                 add_to_send_buffer('Q');
//                 add_to_send_buffer(' ');
//                 add_to_send_buffer('T');
//                 add_to_send_buffer('E');
//                 add_to_send_buffer('S');
//                 add_to_send_buffer('T');
//                 add_to_send_buffer(' ');
//                 add_to_send_buffer('D');
//                 add_to_send_buffer('E');
//                 add_to_send_buffer(' ');
//                 add_to_send_buffer('K');
//                 add_to_send_buffer('3');
//                 add_to_send_buffer('N');
//                 add_to_send_buffer('G');
//                 overall_state = CONTEST_PRACTICE_CQ_SENT;
//                 transition_time = millis();
//               } //((user_input_buffer[1] == 79) && (user_input_buffer[2] == 80)) VT100 F1 key       
//             } //(user_input_buffer_characters == 3)
//             if (user_input_buffer_characters == 4){
//               if ((user_input_buffer[1] == 91) && (user_input_buffer[2] == 50)  && (user_input_buffer[3] == 126)) { //VT100 INS key
//                 for (byte x = 0; x < user_input_buffer_characters; x++) {
//                   add_to_send_buffer(user_input_buffer[x]);
//                 }    
//                 add_to_send_buffer(' ');         
//                 add_to_send_buffer('0');
//                 add_to_send_buffer('0');
//                 add_to_send_buffer('1');
//                 add_to_send_buffer(' ');
//                 add_to_send_buffer('C');
//                 add_to_send_buffer('A');
//                 add_to_send_buffer('R');
//                 configuration.hz_sidetone = previous_sidetone;
//                 configuration.wpm = previous_wpm;              
//                 overall_state = CONTEST_PRACTICE_REPORT_SENT;
//               }
//             } //(user_input_buffer_characters == 4)

//           } else { //(user_input_buffer[0] == 27)
          
//           // we have a callsign, nr, or section
          
//             switch(current_field){
//               case FIELD_CALLSIGN:
//                 callsign = "";
//                 for (byte x = 0; x < user_input_buffer_characters; x++) {
//                   callsign.concat(char(user_input_buffer[x]));
//                 } 
//                 current_field = FIELD_NR;
//                 break;
                
//               case FIELD_NR:
//                 nr = "";
//                 for (byte x = 0; x < user_input_buffer_characters; x++) {
//                   nr.concat(char(user_input_buffer[x]));
//                 }               
//                 current_field = FIELD_SECTION;
//                 break;
                
//               case FIELD_SECTION:
//                 section = "";
//                 for (byte x = 0; x < user_input_buffer_characters; x++) {
//                   section.concat(char(user_input_buffer[x]));
//                 }               
//                 current_field = FIELD_CALLSIGN;
//                 break;
              
//             }
//             term.position(13,0);
//             term.print(callsign);
//             term.position(13,9);
//             term.print(nr);
//             term.position(13,14);
//             term.println(section);
//             term.position(15,0);
//             term.print(F("                     ")); 
//             term.position(15,0);           
            
//           }

//         } //(user_input_buffer[0] == '\\')
//       } //(user_input_buffer_characters > 0)
//       process_user_input_buffer = 0; 
//       user_input_buffer_characters = 0;    
//       escape_flag_time = 0;
//     } //((process_user_input_buffer) && ((escape_flag_time == 0) || ((millis() -escape_flag_time) > 100)))
  
//     //do autonomous events
//     service_send_buffer(NOPRINT);
    
//     switch(overall_state){
//       case CONTEST_PRACTICE_CQ_SENT:
//         if (send_buffer_bytes == 0){
//           if (!cq_answered){
//             if (((millis() - transition_time) > random(250,1500))){  // add some random delay
//               callsign = generate_callsign();
//               caller_sidetone = random(500,1000);
//               configuration.hz_sidetone = caller_sidetone;
//               caller_wpm_delta = random(-5,5);
//               configuration.wpm = configuration.wpm + caller_wpm_delta;
//               for (byte x = 0; x < (callsign.length()); x++) {
//                 add_to_send_buffer(callsign[x]);
//               }
//               cq_answered = 1;
//               transition_time = millis();
//             }
//           } else {  //send it again
//             if ((cq_answered) && ((millis() - transition_time) > random(2000,4000))){
//               configuration.hz_sidetone = caller_sidetone;
//               configuration.wpm = configuration.wpm + caller_wpm_delta;
//               for (byte x = 0; x < (callsign.length()); x++) {
//                 add_to_send_buffer(callsign[x]);
//               }            
//               cq_answered++;
//               transition_time = millis();            
//             }
//           }
//         } else {
//           transition_time = millis();
//         } //send_buffer_bytes == 0
//         break;  //CONTEST_PRACTICE_CQ_SENT
      
      
//     } //switch(overall_state)
    

//   } //while (loop1)
  
//   configuration.hz_sidetone = previous_sidetone;
//   configuration.wpm = previous_wpm;
//   send_buffer_bytes = 0;

// }  
// #endif

//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_cw_practice(PRIMARY_SERIAL_CLS * port_to_use){
  

  byte menu_loop = 1;
  byte menu_loop2 = 1;
  char incoming_char = ' ';

  check_serial_override = 1;

  byte previous_key_tx_state = key_tx;
  key_tx = 0;
  
  while(menu_loop){
  
    while (port_to_use->available() > 0) {  // clear out the buffer if anything is there
      port_to_use->read();
    }  
   
    port_to_use->println(F("\r\n\nCW Training Menu\n"));
    port_to_use->println(F("C - Receive Practice"));
    port_to_use->println(F("I - Keyboard Interactive Receive Practice"));
    port_to_use->println(F("R - Random Groups Receive Practice"));
    port_to_use->println(F("W - Wordsworth Receive Practice"));
    port_to_use->println(F("E - Receive / Transmit Echo Practice"));
    //port_to_use->println("2 - PA QSO Party");   // Don't think this is working right / wasn't finished - Goody 2017-05-01
    port_to_use->println(F("\nX - Exit\n"));
    
    menu_loop2 = 1;
    
    while (menu_loop2){
    
      if (port_to_use->available()){
        incoming_char = port_to_use->read();
        if ((incoming_char != 10) && (incoming_char != 13)){
          menu_loop2 = 0;
        }
      }
    }
      
      
    incoming_char = toUpperCase(incoming_char);
    
    switch(incoming_char){
      case 'X': menu_loop = 0; break;
      case 'C': serial_receive_practice_menu(port_to_use,PRACTICE_NON_INTERACTIVE); break;
      case 'I': serial_receive_practice_menu(port_to_use,PRACTICE_INTERACTIVE); break;
      case 'R': serial_random_menu(port_to_use); break;
      case 'W': serial_wordsworth_menu(port_to_use); break;
      case 'E': serial_receive_transmit_echo_menu(port_to_use); break;
      //case '2': paqso_practice(port_to_use); break;
    } //switch(incoming_char)
    
  } //while(menu_loop)
      
  port_to_use->println(F("Exiting Training module..."));
  check_serial_override = 0;
  key_tx = previous_key_tx_state;
  paddle_echo_buffer = 0;
  
}
#endif




//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_receive_transmit_echo_menu(PRIMARY_SERIAL_CLS * port_to_use){
  

  byte menu_loop = 1;
  byte menu_loop2 = 1;
  char incoming_char = ' ';
  
  while(menu_loop){
  
    while (port_to_use->available() > 0) {  // clear out the buffer if anything is there
      port_to_use->read();
    }  
   
    port_to_use->println(F("\r\n\nReceive / Transmit Echo Practice Menu\n"));
    port_to_use->println(F("I - International Callsigns"));
    port_to_use->println(F("U - US Callsigns"));
    port_to_use->println(F("E - European Callsigns"));
    port_to_use->println(F("C - Canadian Callsigns"));
    port_to_use->println(F("P - Progressive 5 Character Groups"));
    port_to_use->println(F("2 - Two Letter Words"));
    port_to_use->println(F("3 - Three Letter Words"));
    port_to_use->println(F("4 - Four Letter Words"));
    port_to_use->println(F("N - Names"));
    port_to_use->println(F("Q - QSO Words"));
    port_to_use->println(F("M - Mixed\n"));
    port_to_use->println(F("\nX - Exit\n"));
    
    menu_loop2 = 1;
    
    while (menu_loop2){
    
      if (port_to_use->available()){
        incoming_char = port_to_use->read();
        if ((incoming_char != 10) && (incoming_char != 13)){
          menu_loop2 = 0;
        }
      }
    }
      
    incoming_char = toUpperCase(incoming_char);
    

    switch(incoming_char){
      case 'X': menu_loop = 0; break;
      case 'I': receive_transmit_echo_practice(port_to_use,CALLSIGN_INTERNATIONAL); break;
      case 'U': receive_transmit_echo_practice(port_to_use,CALLSIGN_US); break;
      case 'E': receive_transmit_echo_practice(port_to_use,CALLSIGN_EUROPEAN); break;
      case 'C': receive_transmit_echo_practice(port_to_use,CALLSIGN_CANADA); break; 
      case 'P': receive_transmit_echo_practice(port_to_use,ECHO_PROGRESSIVE_5); break;   
      case '2': receive_transmit_echo_practice(port_to_use,ECHO_2_CHAR_WORDS); break;
      case '3': receive_transmit_echo_practice(port_to_use,ECHO_3_CHAR_WORDS); break;
      case '4': receive_transmit_echo_practice(port_to_use,ECHO_4_CHAR_WORDS); break;
      case 'N': receive_transmit_echo_practice(port_to_use,ECHO_NAMES); break;
      case 'M': receive_transmit_echo_practice(port_to_use,ECHO_MIXED); break;
      case 'Q': receive_transmit_echo_practice(port_to_use,ECHO_QSO_WORDS); break;          
    } //switch(incoming_char)

  } //while(menu_loop)
      
  port_to_use->println(F("Exiting receive / transmit echo practice..."));
  
}
#endif

//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void receive_transmit_echo_practice(PRIMARY_SERIAL_CLS * port_to_use,byte practice_mode_called){




  byte loop1 = 1;
  byte loop2 = 0;
  byte x = 0;
  byte user_send_loop = 0;
  String cw_to_send_to_user(10);
  char incoming_char = ' ';
  String user_sent_cw = "";
  byte paddle_hit = 0;
  unsigned long last_element_time = 0;
  unsigned long cw_char;
  byte speed_mode_before = speed_mode;
  byte keyer_mode_before = configuration.keyer_mode;
  byte progressive_step_counter;
  byte practice_mode;
  char word_buffer[10];

  speed_mode = SPEED_NORMAL;                 // put us in normal speed mode 
  if ((configuration.keyer_mode != IAMBIC_A) && (configuration.keyer_mode != IAMBIC_B)) {
    configuration.keyer_mode = IAMBIC_B;                   // we got to be in iambic mode (life is too short to make this work in bug mode)
  }  

  randomSeed(millis());

  #ifdef FEATURE_DISPLAY
    lcd_clear();
    if (LCD_COLUMNS > 17){
      lcd_center_print_timed("Receive / Transmit", 0, default_display_msg_delay);
      lcd_center_print_timed("Echo Practice", 1, default_display_msg_delay);
    } else {
      lcd_center_print_timed("RX / TX", 0, default_display_msg_delay);
      if (LCD_ROWS > 1){
        if (LCD_COLUMNS < 9){
          lcd_center_print_timed("EchoPrct", 1, default_display_msg_delay);
        } else {
          lcd_center_print_timed("Echo Practice", 1, default_display_msg_delay); 
        }
      }     
    }
    service_display();
  #endif 

  port_to_use->println(F("Receive / Transmit Echo Practice\r\n\r\nCopy the code and send it back using the paddle."));
  port_to_use->println(F("Enter a blackslash \\ to exit.\r\n"));
  while (port_to_use->available() > 0) {  // clear out the buffer if anything is there
    incoming_char = port_to_use->read();
  }
  port_to_use->print(F("Press enter to start...\r\n"));
  while (port_to_use->available() == 0) {
  }
  while (port_to_use->available() > 0) {  // clear out the buffer if anything is there
    incoming_char = port_to_use->read();
  }

  while (loop1){


    if (practice_mode_called == ECHO_MIXED){
      practice_mode = random(ECHO_2_CHAR_WORDS,ECHO_QSO_WORDS+1);
    } else {
      practice_mode = practice_mode_called;
    }

    progressive_step_counter = 255;
    
    switch (practice_mode){
      case CALLSIGN_INTERNATIONAL:
      case CALLSIGN_US:
      case CALLSIGN_EUROPEAN:
      case CALLSIGN_CANADA:
        cw_to_send_to_user = generate_callsign(practice_mode);
        break;
      case ECHO_PROGRESSIVE_5:
        cw_to_send_to_user = (char)random(65,91);
        cw_to_send_to_user.concat((char)random(65,91));
        cw_to_send_to_user.concat((char)random(65,91));
        cw_to_send_to_user.concat((char)random(65,91));
        cw_to_send_to_user.concat((char)random(65,91));
        progressive_step_counter = 1;
        break; 
      case ECHO_2_CHAR_WORDS: 
        strcpy_P(word_buffer, (char*)pgm_read_word(&(s2_table[random(0,s2_size)])));
        cw_to_send_to_user = word_buffer;
        break;
      case ECHO_3_CHAR_WORDS: 
        strcpy_P(word_buffer, (char*)pgm_read_word(&(s3_table[random(0,s3_size)])));
        cw_to_send_to_user = word_buffer;
        break;
      case ECHO_4_CHAR_WORDS: 
        strcpy_P(word_buffer, (char*)pgm_read_word(&(s4_table[random(0,s4_size)])));
        cw_to_send_to_user = word_buffer;
        break;    
      case ECHO_NAMES: 
        strcpy_P(word_buffer, (char*)pgm_read_word(&(name_table[random(0,name_size)])));
        cw_to_send_to_user = word_buffer;
        break; 
      case ECHO_QSO_WORDS: 
        strcpy_P(word_buffer, (char*)pgm_read_word(&(qso_table[random(0,qso_size)])));
        cw_to_send_to_user = word_buffer;
        break; 
    } //switch (practice_mode)
    
    
    loop2 = 1;
    
    while (loop2){
  
      user_send_loop = 1;
      user_sent_cw = "";
      cw_char = 0;
      x = 0;

      // send the CW to the user
      while ((x < (cw_to_send_to_user.length())) && (x < progressive_step_counter)){
        send_char(cw_to_send_to_user[x],KEYER_NORMAL);
        // test
        port_to_use->print(cw_to_send_to_user[x]);
        //
        x++;
      }
      port_to_use->println();

      while (user_send_loop) {
        // get their paddle input


        #ifdef FEATURE_DISPLAY
          service_display();
        #endif

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
          sending_mode = MANUAL_SENDING;
          send_dit();
          dit_buffer = 0;
          paddle_hit = 1;
          cw_char = (cw_char * 10) + 1;
          last_element_time = millis();
        }
        if (dah_buffer) {
          sending_mode = MANUAL_SENDING;
          send_dah();
          dah_buffer = 0;
          paddle_hit = 1;
          cw_char = (cw_char * 10) + 2;
          last_element_time = millis();
        }
 
        // have we hit letterspace time (end of a letter?)
        if ((paddle_hit) && (millis() > (last_element_time + (float(600/configuration.wpm) * length_letterspace)))) {
          #ifdef DEBUG_PRACTICE_SERIAL
            debug_serial_port->println(F("receive_transmit_echo_practice: user_send_loop: hit length_letterspace"));
          #endif
          incoming_char = convert_cw_number_to_ascii(cw_char);
          port_to_use->print(incoming_char);
          #ifdef FEATURE_DISPLAY
            display_scroll_print_char(incoming_char);
            service_display();
          #endif
          user_sent_cw.concat(incoming_char);
          cw_char = 0;
          paddle_hit = 0;
          // TODO - print it to serial and lcd
        }

        // do we have all the characters from the user? - if so, get out of user_send_loop
        if ((user_sent_cw.length() >= cw_to_send_to_user.length()) || ((progressive_step_counter < 255) && (user_sent_cw.length() == progressive_step_counter))) {
          user_send_loop = 0;
          port_to_use->println();
          #ifdef FEATURE_DISPLAY
            display_scroll_print_char(' ');
            service_display();
          #endif

        }


        // does the user want to exit?
        while(port_to_use->available() > 0) {
          incoming_char = port_to_use->read();
          user_send_loop = 0;
          loop1 = 0;
          loop2 = 0;
        }
        #ifdef FEATURE_COMMAND_BUTTONS
          while (analogbuttonread(0)) {
            user_send_loop = 0;
            loop1 = 0;
            loop2 = 0;
          }
        #endif 


      } //while (user_send_loop)

      if (loop1 && loop2){

        if (progressive_step_counter < 255){  // we're in progressive mode
          if (user_sent_cw.substring(0,progressive_step_counter) == cw_to_send_to_user.substring(0,progressive_step_counter)){ 
            send_char(' ',0);
            send_char(' ',0);
            progressive_step_counter++;
            if (progressive_step_counter == 6){
              loop2 = 0;
              beep();
              send_char(' ',0);
              send_char(' ',0);
            }
          } else {
            boop();
            send_char(' ',0);
            send_char(' ',0);
          }
        } else {  
          if (user_sent_cw == cw_to_send_to_user){     
            beep();
            send_char(' ',0);
            send_char(' ',0);        
            loop2 = 0;
          } else {
            boop();
            send_char(' ',0);
            send_char(' ',0);
          }
        }
      }

    } //loop2
  } //loop1
  
  speed_mode = speed_mode_before; 
  configuration.keyer_mode = keyer_mode_before;
  paddle_echo_buffer = 0;

}
#endif //defined(FEATURE_SERIAL) && defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE) && defined(FEATURE_COMMAND_LINE_INTERFACE)


//---------------------------------------------------------------------
#if defined(FEATURE_SERIAL) && defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_receive_practice_menu(PRIMARY_SERIAL_CLS * port_to_use,byte practice_mode){
  

  byte menu_loop = 1;
  byte menu_loop2 = 1;
  char incoming_char = ' ';
  
  while(menu_loop){
  
    while (port_to_use->available() > 0) {  // clear out the buffer if anything is there
      port_to_use->read();
    }  
   
    if (practice_mode == PRACTICE_INTERACTIVE){
      port_to_use->println(F("\r\n\nInteractive Receive Practice Menu\n"));
    } else {
      port_to_use->println(F("\r\n\nReceive Practice Menu\n"));
    }
    port_to_use->println(F("I - International Callsigns"));
    port_to_use->println(F("U - US Callsigns"));
    port_to_use->println(F("E - European Callsigns"));
    port_to_use->println(F("C - Canadian Callsigns"));
    port_to_use->println(F("2 - Two Letter Words"));
    port_to_use->println(F("3 - Three Letter Words"));
    port_to_use->println(F("4 - Four Letter Words"));
    port_to_use->println(F("N - Names"));
    port_to_use->println(F("Q - QSO Words"));
    port_to_use->println(F("M - Mixed Words\n"));    
    port_to_use->println(F("\nX - Exit\n"));
    menu_loop2 = 1;
    
    while (menu_loop2){
    
      if (port_to_use->available()){
        incoming_char = port_to_use->read();
        if ((incoming_char != 10) && (incoming_char != 13)){
          menu_loop2 = 0;
        }
      }
    }
      
    incoming_char = toUpperCase(incoming_char);
    
    if (practice_mode == PRACTICE_INTERACTIVE){
      switch(incoming_char){
        case 'X': menu_loop = 0; break;
        case 'I': serial_practice_interactive(port_to_use,CALLSIGN_INTERNATIONAL); break;
        case 'U': serial_practice_interactive(port_to_use,CALLSIGN_US); break;
        case 'E': serial_practice_interactive(port_to_use,CALLSIGN_EUROPEAN); break;
        case 'C': serial_practice_interactive(port_to_use,CALLSIGN_CANADA); break;  
        case '2': serial_practice_interactive(port_to_use,PRACTICE_2_CHAR_WORDS); break;
        case '3': serial_practice_interactive(port_to_use,PRACTICE_3_CHAR_WORDS); break;
        case '4': serial_practice_interactive(port_to_use,PRACTICE_4_CHAR_WORDS); break;
        case 'N': serial_practice_interactive(port_to_use,PRACTICE_NAMES); break;
        case 'M': serial_practice_interactive(port_to_use,PRACTICE_MIXED); break;
        case 'Q': serial_practice_interactive(port_to_use,PRACTICE_QSO_WORDS); break;
      } //switch(incoming_char)
    } else {
      switch(incoming_char){
        case 'X': menu_loop = 0; break;
        case 'I': serial_practice_non_interactive(port_to_use,CALLSIGN_INTERNATIONAL); break;
        case 'U': serial_practice_non_interactive(port_to_use,CALLSIGN_US); break;
        case 'E': serial_practice_non_interactive(port_to_use,CALLSIGN_EUROPEAN); break;
        case 'C': serial_practice_non_interactive(port_to_use,CALLSIGN_CANADA); break; 
        case '2': serial_practice_non_interactive(port_to_use,PRACTICE_2_CHAR_WORDS); break;
        case '3': serial_practice_non_interactive(port_to_use,PRACTICE_3_CHAR_WORDS); break;
        case '4': serial_practice_non_interactive(port_to_use,PRACTICE_4_CHAR_WORDS); break;
        case 'N': serial_practice_non_interactive(port_to_use,PRACTICE_NAMES); break;
        case 'M': serial_practice_non_interactive(port_to_use,PRACTICE_MIXED); break;
        case 'Q': serial_practice_non_interactive(port_to_use,PRACTICE_QSO_WORDS); break;               
      } //switch(incoming_char)

    }
  } //while(menu_loop)
      
  port_to_use->println(F("Exiting callsign training..."));
  
}
#endif

//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_set_wordspace_parameters(PRIMARY_SERIAL_CLS * port_to_use,byte mode_select){

  byte menu_loop = 1;
  byte menu_loop2 = 1;
  char incoming_char = ' ';
  unsigned int temp_value;

  
  while(menu_loop){
  
    while (port_to_use->available() > 0) {  // clear out the buffer if anything is there
      port_to_use->read();
    }  
  
    switch(mode_select){
      case WORDSWORTH_WORDSPACE: port_to_use->print(F("\r\nEnter Wordspace >")); break;
      case WORDSWORTH_WPM: port_to_use->print(F("\r\nEnter WPM >")); break;
      case WORDSWORTH_REPETITION: port_to_use->print(F("\r\nEnter Repetition >")); break;
    }


    menu_loop2 = 1;
    temp_value = 0;
    
    while (menu_loop2){
    
      if (port_to_use->available()){
        incoming_char = port_to_use->read();
        if ((incoming_char > 47) && (incoming_char < 58)){
          port_to_use->print(incoming_char);
          temp_value = (temp_value * 10) + (incoming_char - 48);
        }
        if (incoming_char == 13){  // Enter Key
          menu_loop2 = 0;
        }
      }
    }
      
    // validate value     
    if (temp_value == 0){
      menu_loop = 0;        // just blow out if nothing was entered
    } else {
      if ((temp_value > 0) && (temp_value < 101) && (mode_select == WORDSWORTH_WPM)){
        configuration.wpm = temp_value;
        config_dirty = 1;
        menu_loop = 0;
      } else {
        if ((temp_value > 1) && (temp_value < 13) && (mode_select == WORDSWORTH_WORDSPACE)){
          configuration.wordsworth_wordspace = temp_value;
          config_dirty = 1;
          menu_loop = 0;     
        } else { 
          if ((temp_value > 0) && (temp_value < 11) && (mode_select == WORDSWORTH_REPETITION)){
            configuration.wordsworth_repetition = temp_value;
            config_dirty = 1;
            menu_loop = 0;     
          } else {           
            port_to_use->println(F("\r\nOMG that's an invalid value. Try again, OM..."));
          }
        }
      }
    }
    
  } //while(menu_loop)
      
}
#endif //defined(FEATURE_SERIAL) && defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE) && defined(FEATURE_COMMAND_LINE_INTERFACE)


//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_random_menu(PRIMARY_SERIAL_CLS * port_to_use){

  byte menu_loop = 1;
  byte menu_loop2 = 1;
  char incoming_char = ' ';
  
  while(menu_loop){
  
    while (port_to_use->available() > 0) {  // clear out the buffer if anything is there
      port_to_use->read();
    }  
    
    port_to_use->println(F("\r\n\nRandom Code Receive Practice Menu\n"));
    port_to_use->println(F("A - Letter Groups"));
    port_to_use->println(F("1 - Number Groups"));
    port_to_use->println(F("M - Mixed Groups"));
    port_to_use->println(F("\nX - Exit\n"));

    menu_loop2 = 1;
    
    while (menu_loop2){
    
      if (port_to_use->available()){
        incoming_char = port_to_use->read();
        if ((incoming_char != 10) && (incoming_char != 13)){
          menu_loop2 = 0;
        }
      }
    }

    incoming_char = toUpperCase(incoming_char);

    switch(incoming_char){
      case 'A': random_practice(port_to_use,RANDOM_LETTER_GROUPS,5); break;
      case '1': random_practice(port_to_use,RANDOM_NUMBER_GROUPS,5); break;
      case 'M': random_practice(port_to_use,RANDOM_MIXED_GROUPS,5); break;
      case 'X': menu_loop = 0; break;        
    } //switch(incoming_char)
    
  } //while(menu_loop)
      
  port_to_use->println(F("Exiting Random code module..."));


}
#endif //defined(FEATURE_SERIAL) && defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE) && defined(FEATURE_COMMAND_LINE_INTERFACE)

//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void random_practice(PRIMARY_SERIAL_CLS * port_to_use,byte random_mode,byte group_size)
{

  byte loop1 = 1;
  byte x = 0;
  byte y = 0;
  char incoming_char = ' ';
  char random_character = 0;

  randomSeed(millis());
  port_to_use->println(F("Random group practice\r\n"));

  #ifdef FEATURE_DISPLAY
    lcd_clear();
    if (LCD_COLUMNS < 9){
      lcd_center_print_timed("RndGroup", 0, default_display_msg_delay);
    } else {
      lcd_center_print_timed("Random Group", 0, default_display_msg_delay);
    }
    if (LCD_ROWS > 1){
      lcd_center_print_timed("Practice", 1, default_display_msg_delay);
    }
    service_display();
  #endif

  while (port_to_use->available() > 0) {  // clear out the buffer if anything is there
    incoming_char = port_to_use->read();
  }

  while (loop1){

    switch(random_mode){
      case RANDOM_LETTER_GROUPS: random_character = random(65,91); break;
      case RANDOM_NUMBER_GROUPS: random_character = random(48,58); break;
      case RANDOM_MIXED_GROUPS: 
        random_character = random(65,101);
        if (random_character > 90) {random_character = random_character - 43;};
        break;
    }

    send_char(random_character,KEYER_NORMAL);
    port_to_use->print(random_character);
    #ifdef FEATURE_DISPLAY
      display_scroll_print_char(random_character);
      service_display();
    #endif


    x++;

    if (x == group_size){
      send_char(' ',KEYER_NORMAL);
      port_to_use->print(" ");
      #ifdef FEATURE_DISPLAY
        display_scroll_print_char(' ');
        service_display();
      #endif
      x = 0;
      y++;
    }

    if (y > 4){
      port_to_use->println("");
      y = 0;
    }

    if (port_to_use->available()){
      port_to_use->read();
      loop1 = 0;
    }

    #ifdef FEATURE_COMMAND_BUTTONS
      while ((paddle_pin_read(paddle_left) == LOW) || (paddle_pin_read(paddle_right) == LOW) || (analogbuttonread(0))) {
        loop1 = 0;
      }
    #else 
      while ((paddle_pin_read(paddle_left) == LOW) || (paddle_pin_read(paddle_right) == LOW)) {
        loop1 = 0;
      }    
    #endif //FEATURE_COMMAND_BUTTONS

  } //loop1
  

}
#endif //defined(FEATURE_SERIAL) && defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE) && defined(FEATURE_COMMAND_LINE_INTERFACE)

//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_wordsworth_menu(PRIMARY_SERIAL_CLS * port_to_use){

  byte menu_loop = 1;
  byte menu_loop2 = 1;
  char incoming_char = ' ';
  byte effective_wpm_factor[] = {100,93,86,81,76,71,68,64,61,58,56,53};
  
  while(menu_loop){
  
    while (port_to_use->available() > 0) {  // clear out the buffer if anything is there
      port_to_use->read();
    }  
    
    port_to_use->println(F("\r\n\nWordsworth Menu\n"));
    port_to_use->println(F("2 - Two Letter Words"));
    port_to_use->println(F("3 - Three Letter Words"));
    port_to_use->println(F("4 - Four Letter Words"));
    port_to_use->println(F("N - Names"));
    port_to_use->println(F("Q - QSO Words"));
    port_to_use->println(F("M - Mixed\n"));
    port_to_use->println(F("O - Set Wordspace"));
    port_to_use->println(F("W - Set WPM"));
    port_to_use->println(F("R - Set Repetition"));
    port_to_use->println(F("\nX - Exit\n"));
    port_to_use->print(F("WPM:"));
    port_to_use->print(configuration.wpm);
    port_to_use->print(F(" Wordspace:"));
    port_to_use->print(configuration.wordsworth_wordspace);
    port_to_use->print(F(" Effective WPM:"));
    port_to_use->print(configuration.wpm * (effective_wpm_factor[configuration.wordsworth_wordspace-1]/100.0),0);
    port_to_use->print(F(" Repetition:"));
    port_to_use->println(configuration.wordsworth_repetition);
    port_to_use->println("\r\n\nEnter choice >");

    menu_loop2 = 1;
    
    while (menu_loop2){
    
      if (port_to_use->available()){
        incoming_char = port_to_use->read();
        if ((incoming_char != 10) && (incoming_char != 13)){
          menu_loop2 = 0;
        }
      }
    }

    incoming_char = toUpperCase(incoming_char);

    switch(incoming_char){
      case '2': wordsworth_practice(port_to_use,WORDSWORTH_2_CHAR_WORDS); break;
      case '3': wordsworth_practice(port_to_use,WORDSWORTH_3_CHAR_WORDS); break;
      case '4': wordsworth_practice(port_to_use,WORDSWORTH_4_CHAR_WORDS); break;
      case 'N': wordsworth_practice(port_to_use,WORDSWORTH_NAMES); break;
      case 'M': wordsworth_practice(port_to_use,WORDSWORTH_MIXED); break;
      case 'Q': wordsworth_practice(port_to_use,WORDSWORTH_QSO_WORDS); break;
      case 'W': serial_set_wordspace_parameters(port_to_use,WORDSWORTH_WPM); break;
      case 'O': serial_set_wordspace_parameters(port_to_use,WORDSWORTH_WORDSPACE); break;
      case 'R': serial_set_wordspace_parameters(port_to_use,WORDSWORTH_REPETITION); break;
      case 'X': menu_loop = 0; break;        
    } //switch(incoming_char)
    
 
    
  } //while(menu_loop)
      
  port_to_use->println(F("Exiting Wordsworth module..."));


}
#endif //defined(FEATURE_SERIAL) && defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE) && defined(FEATURE_COMMAND_LINE_INTERFACE)


//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void wordsworth_practice(PRIMARY_SERIAL_CLS * port_to_use,byte practice_type)
{

  byte loop1 = 1;
  byte loop2;
  byte loop3;
  unsigned int word_index;
  char word_buffer[10];
  byte x;
  byte not_printed;
  byte practice_type_called = practice_type;
  byte repetitions;


  randomSeed(millis());
  port_to_use->println(F("Wordsworth practice...\n"));

  #ifdef FEATURE_DISPLAY
    lcd_clear();
    if (LCD_COLUMNS < 9){
      lcd_center_print_timed("Wrdswrth", 0, default_display_msg_delay);
    } else {
      lcd_center_print_timed("Wordsworth", 0, default_display_msg_delay);      
    }
    if (LCD_ROWS > 1){
      lcd_center_print_timed("Practice", 1, default_display_msg_delay);
    }
    service_display();
  #endif

  while (port_to_use->available() > 0) {  // clear out the buffer if anything is there
    port_to_use->read();
  }


  while (loop1){

    if (practice_type_called == WORDSWORTH_MIXED){
      practice_type = random(WORDSWORTH_2_CHAR_WORDS,WORDSWORTH_QSO_WORDS+1);
    } else {
      practice_type = practice_type_called;
    }

    switch(practice_type){
      case WORDSWORTH_2_CHAR_WORDS: 
        word_index = random(0,s2_size);  // min parm is inclusive, max parm is exclusive
        strcpy_P(word_buffer, (char*)pgm_read_word(&(s2_table[word_index])));
        break;
      case WORDSWORTH_3_CHAR_WORDS: 
        word_index = random(0,s3_size);  // min parm is inclusive, max parm is exclusive
        strcpy_P(word_buffer, (char*)pgm_read_word(&(s3_table[word_index])));
        break;
      case WORDSWORTH_4_CHAR_WORDS: 
        word_index = random(0,s4_size);  // min parm is inclusive, max parm is exclusive
        strcpy_P(word_buffer, (char*)pgm_read_word(&(s4_table[word_index])));
        break;    
      case WORDSWORTH_NAMES: 
        word_index = random(0,name_size);  // min parm is inclusive, max parm is exclusive
        strcpy_P(word_buffer, (char*)pgm_read_word(&(name_table[word_index])));
        break; 
      case WORDSWORTH_QSO_WORDS: 
        word_index = random(0,qso_size);  // min parm is inclusive, max parm is exclusive
        strcpy_P(word_buffer, (char*)pgm_read_word(&(qso_table[word_index])));
        break; 
    }

    #if defined(DEBUG_WORDSWORTH)
      debug_serial_port->print("wordsworth_practice: word_index:");
      debug_serial_port->println(word_index);
      debug_serial_port->print("wordsworth_practice: word_buffer:");
      debug_serial_port->println(word_buffer);
    #endif
    
    loop3 = 1;
    repetitions = 0;

    while ((loop3) && (repetitions < configuration.wordsworth_repetition)){ // word sending loop

      loop2 = 1;
      x = 0;

      while (loop2){ //character sending loop

        #if defined(DEBUG_WORDSWORTH)
          debug_serial_port->print("wordsworth_practice: send_char:");
          debug_serial_port->print(word_buffer[x]);
          debug_serial_port->print(" ");
          debug_serial_port->println((byte)word_buffer[x]);
        #endif

        //word_buffer[x] = toUpperCase(word_buffer[x]); // word files should be in CAPS

        #if defined(OPTION_NON_ENGLISH_EXTENSIONS)
          if (((byte)word_buffer[x] == 195) || ((byte)word_buffer[x] == 197)){  // do we have a unicode character?
            x++;
            if ((word_buffer[x] != 0) && (x < 10)){
              send_char(convert_unicode_to_send_char_code((byte)word_buffer[x-1],(byte)word_buffer[x]),KEYER_NORMAL);
              #ifdef FEATURE_DISPLAY
                display_scroll_print_char(convert_unicode_to_send_char_code((byte)word_buffer[x-1],(byte)word_buffer[x]));
                service_display();
              #endif                 
              x++;
            }
          } else {
            send_char(word_buffer[x],KEYER_NORMAL);
            #ifdef FEATURE_DISPLAY
              display_scroll_print_char(word_buffer[x]);
              service_display();
            #endif            
            x++;
          }
        #else //OPTION_NON_ENGLISH_EXTENSIONS
          send_char(word_buffer[x],KEYER_NORMAL);
          #ifdef FEATURE_DISPLAY
            display_scroll_print_char(word_buffer[x]);
            service_display();
          #endif             
          x++;
        #endif //OPTION_NON_ENGLISH_EXTENSIONS

        not_printed = 1;

        if ((word_buffer[x] == 0) || (x > 9)){ // are we at the end of the word?
          loop2 = 0;
          for (int y = 0;y < (configuration.wordsworth_wordspace-1);y++){  // send extra word spaces
            send_char(' ',KEYER_NORMAL);
            #ifdef FEATURE_DISPLAY
              display_scroll_print_char(' ');
              service_display();
            #endif                 
            if (((y > ((configuration.wordsworth_wordspace-1)/2)) || (configuration.wordsworth_wordspace < 4)) && (not_printed)){
              port_to_use->println(word_buffer);
              not_printed = 0;
            }
            if (port_to_use->available()){
              port_to_use->read();
              y = 99;
              loop1 = 0;
              loop2 = 0;
              loop3 = 0;
            }
          }
        }

        if (port_to_use->available()){
          port_to_use->read();
          loop1 = 0;
          loop2 = 0;
          loop3 = 0;
        }
      }  //loop2

      repetitions++;

    } //loop3

  } //loop1
  
 

}
#endif //defined(FEATURE_SERIAL) && defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE) && defined(FEATURE_COMMAND_LINE_INTERFACE)

//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_practice_interactive(PRIMARY_SERIAL_CLS * port_to_use,byte practice_type_called)
{

  byte loop1 = 1;
  byte loop2 = 0;
  byte x = 0;
  byte serialwaitloop = 0;
  String cw_to_send_to_user(10);
  char incoming_char = ' ';
  String user_entered_cw = "";
  byte practice_type = 0;
  char word_buffer[10];

  randomSeed(millis());

  #ifdef FEATURE_DISPLAY
    lcd_clear();
    if (LCD_COLUMNS < 9){
      lcd_center_print_timed("IntrctRX", 0, default_display_msg_delay);
    } else {
      lcd_center_print_timed("Interactive RX", 0, default_display_msg_delay);      
    }
    if (LCD_ROWS > 1){
      lcd_center_print_timed("Practice", 1, default_display_msg_delay);
    }
    service_display();
  #endif

  port_to_use->println(F("Interactive receive practice\r\n\r\nCopy the code, type it in, and hit ENTER."));
  port_to_use->println(F("If you are using the Arduino serial monitor, select \"Carriage Return\" line ending."));
  port_to_use->println(F("Enter a blackslash \\ to exit.\r\n"));
  while (port_to_use->available() > 0) {  // clear out the buffer if anything is there
    incoming_char = port_to_use->read();
  }
  port_to_use->print(F("Press enter to start...\r\n"));
  while (port_to_use->available() == 0) {
  }
  while (port_to_use->available() > 0) {  // clear out the buffer if anything is there
    incoming_char = port_to_use->read();
  }

  while (loop1){

    if (practice_type_called == PRACTICE_MIXED){
      practice_type = random(PRACTICE_2_CHAR_WORDS,PRACTICE_QSO_WORDS+1);
    } else {
      practice_type = practice_type_called;
    }

    switch(practice_type){
      case CALLSIGN_INTERNATIONAL:
      case CALLSIGN_US:
      case CALLSIGN_EUROPEAN:
      case CALLSIGN_CANADA:  
        cw_to_send_to_user = generate_callsign(practice_type);
        break;
      case PRACTICE_2_CHAR_WORDS: 
        strcpy_P(word_buffer, (char*)pgm_read_word(&(s2_table[random(0,s2_size)])));
        cw_to_send_to_user = word_buffer;
        #ifdef DEBUG_PRACTICE_SERIAL
          debug_serial_port->print("serial_practice_interactive: PRACTICE_2_CHAR_WORDS:");
        #endif
        break;
      case PRACTICE_3_CHAR_WORDS:
        strcpy_P(word_buffer, (char*)pgm_read_word(&(s3_table[random(0,s3_size)])));
        cw_to_send_to_user = word_buffer;
        #ifdef DEBUG_PRACTICE_SERIAL
          debug_serial_port->print("serial_practice_interactive: PRACTICE_3_CHAR_WORDS:");
        #endif        
        break;
      case PRACTICE_4_CHAR_WORDS: 
        strcpy_P(word_buffer, (char*)pgm_read_word(&(s4_table[random(0,s4_size)])));
        cw_to_send_to_user = word_buffer;
        #ifdef DEBUG_PRACTICE_SERIAL
          debug_serial_port->print("serial_practice_interactive: PRACTICE_4_CHAR_WORDS:");
        #endif        
        break;    
      case PRACTICE_NAMES: 
        strcpy_P(word_buffer, (char*)pgm_read_word(&(name_table[random(0,name_size)])));
        cw_to_send_to_user = word_buffer;
        #ifdef DEBUG_PRACTICE_SERIAL
          debug_serial_port->print("serial_practice_interactive: PRACTICE_NAMES:");
        #endif        
        break; 
      case PRACTICE_QSO_WORDS: 
        strcpy_P(word_buffer, (char*)pgm_read_word(&(qso_table[random(0,qso_size)])));
        cw_to_send_to_user = word_buffer;
        #ifdef DEBUG_PRACTICE_SERIAL
          debug_serial_port->print("serial_practice_interactive: PRACTICE_QSO_WORDS:");
        #endif        
        break; 
    } //switch(practice_type)

    loop2 = 1;
    
    while (loop2){
  
      #if defined(DEBUG_CALLSIGN_PRACTICE_SHOW_CALLSIGN)
        port_to_use->println(callsign);
      #endif
  
      serialwaitloop = 1;
      user_entered_cw = "";
      x = 0;
      while (serialwaitloop) {

        if(x < (cw_to_send_to_user.length())){
          send_char(cw_to_send_to_user[x],KEYER_NORMAL);
          #ifdef FEATURE_DISPLAY
            display_scroll_print_char(cw_to_send_to_user[x]);
            service_display();
          #endif    
          x++;
        }

        while(port_to_use->available() > 0) {
          incoming_char = port_to_use->read();
          incoming_char = toUpperCase(incoming_char);
          port_to_use->print(incoming_char);
          if (incoming_char == 13) {
            serialwaitloop = 0;
          } else {
            if (incoming_char != 10) {
              user_entered_cw = user_entered_cw + incoming_char;
            }
          }
        }
      }
  
      if (user_entered_cw[0] != '?') {
        if ((user_entered_cw[0] == '\\')){
          port_to_use->println(F("Exiting...\n"));
          loop1 = 0;
          loop2 = 0;
        } else {
          user_entered_cw.toUpperCase();  // the toUpperCase function was modified in 1.0; now it changes string in place
          if (cw_to_send_to_user.compareTo(user_entered_cw) == 0) {
            port_to_use->println(F("\nCorrect!"));
            #ifdef FEATURE_DISPLAY
              lcd_clear();
              lcd_center_print_timed("Correct!", 0, default_display_msg_delay);
              service_display();
            #endif
            loop2 = 0;
          } else {
            port_to_use->println(F("\nWrong!"));
            #ifdef FEATURE_DISPLAY
              lcd_clear();
              lcd_center_print_timed("Wrong!", 0, default_display_msg_delay);
              service_display();
            #endif            
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
  

}
#endif //defined(FEATURE_SERIAL) && defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE) && defined(FEATURE_COMMAND_LINE_INTERFACE)

//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_practice_non_interactive(PRIMARY_SERIAL_CLS * port_to_use,byte practice_type_called)
{

  byte loop1 = 1;
  byte loop2;
  byte x;
  String cw_to_send_to_user(10);
  char incoming_char = ' ';
  byte practice_type;
  char word_buffer[10];

  key_tx = 0;
  randomSeed(millis());

  #ifdef FEATURE_DISPLAY
    lcd_clear();
    if (LCD_COLUMNS < 9){
      lcd_center_print_timed("Call RX", 0, default_display_msg_delay);
    } else {
      lcd_center_print_timed("Callsign RX", 0, default_display_msg_delay);      
    }
    if (LCD_ROWS > 1){
      lcd_center_print_timed("Practice", 1, default_display_msg_delay);
    }
    service_display();
  #endif

  port_to_use->println(F("Callsign receive practice\r\n"));

  while (port_to_use->available() > 0) {  // clear out the buffer if anything is there
    incoming_char = port_to_use->read();
  }



  while (loop1){



    if (practice_type_called == PRACTICE_MIXED){
      practice_type = random(PRACTICE_2_CHAR_WORDS,PRACTICE_QSO_WORDS+1);
    } else {
      practice_type = practice_type_called;
    }

    switch(practice_type){
      case CALLSIGN_INTERNATIONAL:
      case CALLSIGN_US:
      case CALLSIGN_EUROPEAN:
      case CALLSIGN_CANADA:  
        cw_to_send_to_user = generate_callsign(practice_type);
        break;
      case PRACTICE_2_CHAR_WORDS: 
        strcpy_P(word_buffer, (char*)pgm_read_word(&(s2_table[random(0,s2_size)])));
        cw_to_send_to_user = word_buffer;
        #ifdef DEBUG_PRACTICE_SERIAL
          debug_serial_port->print("serial_practice_non_interactive: PRACTICE_2_CHAR_WORDS:");
        #endif
        break;
      case PRACTICE_3_CHAR_WORDS:
        strcpy_P(word_buffer, (char*)pgm_read_word(&(s3_table[random(0,s3_size)])));
        cw_to_send_to_user = word_buffer;
        #ifdef DEBUG_PRACTICE_SERIAL
          debug_serial_port->print("serial_practice_non_interactive: PRACTICE_3_CHAR_WORDS:");
        #endif        
        break;
      case PRACTICE_4_CHAR_WORDS: 
        strcpy_P(word_buffer, (char*)pgm_read_word(&(s4_table[random(0,s4_size)])));
        cw_to_send_to_user = word_buffer;
        #ifdef DEBUG_PRACTICE_SERIAL
          debug_serial_port->print("serial_practice_non_interactive: PRACTICE_4_CHAR_WORDS:");
        #endif        
        break;    
      case PRACTICE_NAMES: 
        strcpy_P(word_buffer, (char*)pgm_read_word(&(name_table[random(0,name_size)])));
        cw_to_send_to_user = word_buffer;
        #ifdef DEBUG_PRACTICE_SERIAL
          debug_serial_port->print("serial_practice_non_interactive: PRACTICE_NAMES:");
        #endif        
        break; 
      case PRACTICE_QSO_WORDS: 
        strcpy_P(word_buffer, (char*)pgm_read_word(&(qso_table[random(0,qso_size)])));
        cw_to_send_to_user = word_buffer;
        #ifdef DEBUG_PRACTICE_SERIAL
          debug_serial_port->print("serial_practice_non_interactive: PRACTICE_QSO_WORDS:");
        #endif        
        break; 
    } //switch(practice_type)


    cw_to_send_to_user = cw_to_send_to_user + "    ";


    loop2 = 1;
    x = 0;

    while ((loop2) && (x < (cw_to_send_to_user.length()))) {

      send_char(cw_to_send_to_user[x],KEYER_NORMAL);
      #ifdef FEATURE_DISPLAY
        display_scroll_print_char(cw_to_send_to_user[x]);
        service_display();
      #endif  
      x++;
    
      if (port_to_use->available()){
        port_to_use->read();
        loop1 = 0;
        loop2 = 0;
        x = 99;
      }

      #ifdef FEATURE_COMMAND_BUTTONS
        while ((paddle_pin_read(paddle_left) == LOW) || (paddle_pin_read(paddle_right) == LOW) || (analogbuttonread(0))) {
          loop1 = 0;
          loop2 = 0;
          x = 99;
        }
      #else 
        while ((paddle_pin_read(paddle_left) == LOW) || (paddle_pin_read(paddle_right) == LOW)) {
          loop1 = 0;
          loop2 = 0;
          x = 99;
        }    
      #endif //FEATURE_COMMAND_BUTTONS

    } //loop2

    port_to_use->println(cw_to_send_to_user);

  } //loop1


}
#endif //defined(FEATURE_SERIAL) && defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE) && defined(FEATURE_COMMAND_LINE_INTERFACE)

//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_status(PRIMARY_SERIAL_CLS * port_to_use) {

  port_to_use->println();
  #if defined(FEATURE_AMERICAN_MORSE)
    if (char_send_mode == AMERICAN_MORSE){port_to_use->println(F("American Morse"));}
  #endif 
  #if defined(FEATURE_HELL)
    if (char_send_mode == HELL){port_to_use->println(F("Hellschreiber"));}
  #endif 
  switch (configuration.keyer_mode) {
    case IAMBIC_A: port_to_use->print(F("Iambic A")); break;
    case IAMBIC_B: port_to_use->print(F("Iambic B")); 
      #ifdef FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
        port_to_use->print(F(" / CMOS Super Keyer Timing: O"));
        if (configuration.cmos_super_keyer_iambic_b_timing_on) {
          port_to_use->print("n ");
          port_to_use->print(configuration.cmos_super_keyer_iambic_b_timing_percent);
          port_to_use->print("%");
        } else {
         port_to_use->print(F("ff"));
        }
      #endif //FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
      break;
    case BUG: port_to_use->print(F("Bug")); break;
    case STRAIGHT: port_to_use->print(F("Straight Key")); break;
    case ULTIMATIC: 
      port_to_use->print(F("Ultimatic ")); 
      switch(ultimatic_mode){
        // case ULTIMATIC_NORMAL:
        //   port_to_use->print(F("Normal")); 
        //   break;
        case ULTIMATIC_DIT_PRIORITY:
          port_to_use->print(F("Dit Priority")); 
          break;
        case ULTIMATIC_DAH_PRIORITY:
          port_to_use->print(F("Dah Priority")); 
          break;        
      }
    break;
    case SINGLE_PADDLE: port_to_use->print(F("Single Paddle")); break;

    break;
  }
  port_to_use->println();
  port_to_use->print(F("Buffers: Dit O"));
  if (configuration.dit_buffer_off){
    port_to_use->print(F("ff"));
  } else {
    port_to_use->print(F("n"));
  }
  port_to_use->print(F(" Dah O"));
  if (configuration.dah_buffer_off){
    port_to_use->println(F("ff"));
  } else {
    port_to_use->println(F("n"));
  }
  if (speed_mode == SPEED_NORMAL) {
    port_to_use->print(F("WPM: "));
    port_to_use->println(configuration.wpm,DEC);
    port_to_use->print(F("Command Mode WPM: "));
    port_to_use->println(configuration.wpm_command_mode,DEC);
    #ifdef FEATURE_FARNSWORTH
      port_to_use->print(F("Farnsworth WPM: "));
      if (configuration.wpm_farnsworth < configuration.wpm) {
        port_to_use->println(F("Disabled")); //(WD9DMP)
      } else {
        port_to_use->println(configuration.wpm_farnsworth,DEC);
      }
    #endif //FEATURE_FARNSWORTH
  } else {
    port_to_use->print(F("QRSS Mode Activated - Dit Length: "));
    port_to_use->print(qrss_dit_length,DEC);
    port_to_use->println(F(" seconds"));
  }
  port_to_use->print(F("Sidetone: "));
  switch (configuration.sidetone_mode) {
    case SIDETONE_ON: port_to_use->print(F("On")); break; //(WD9DMP)
    case SIDETONE_OFF: port_to_use->print(F("Off")); break; //(WD9DMP)
    case SIDETONE_PADDLE_ONLY: port_to_use->print(F("Paddle Only")); break;
  }
  port_to_use->print(" ");
  port_to_use->print(configuration.hz_sidetone,DEC);
  port_to_use->println(" hz");

  // #if defined(FEATURE_SINEWAVE_SIDETONE)
  //   port_to_use->print(F("Sidetone Volume: "));
  //   port_to_use->print(map(configuration.sidetone_volume,sidetone_volume_low_limit,sidetone_volume_high_limit,0,100));
  //   port_to_use->println(F("%"));
  //   port_to_use->println(configuration.sidetone_volume);
  // #endif //FEATURE_SINEWAVE_SIDETONE   

  #ifdef FEATURE_SIDETONE_SWITCH
    port_to_use->print(F("Sidetone Switch: "));
    port_to_use->println(sidetone_switch_value() ? F("On") : F("Off")); //(WD9DMP)
  #endif // FEATURE_SIDETONE_SWITCH
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
      port_to_use->print(F("Not "));
    }
    port_to_use->print(F("Activated) Range: "));
    port_to_use->print(pot_wpm_low_value);
    port_to_use->print(" - ");
    port_to_use->print(pot_wpm_high_value);
    port_to_use->println(F(" WPM"));
  #endif
  #ifdef FEATURE_AUTOSPACE
    port_to_use->print(F("Autospace O"));
    if (configuration.autospace_active) {
      port_to_use->println(F("n"));
    } else {
      port_to_use->println(F("ff"));
    }
  #endif
  port_to_use->print(F("Wordspace: "));
  port_to_use->println(configuration.length_wordspace,DEC);
  port_to_use->print(F("TX: "));
  port_to_use->println(configuration.current_tx);  


  #ifdef FEATURE_QLF
    port_to_use->print(F("QLF: O"));
    if (qlf_active){
      port_to_use->println(F("n"));
    } else {
      port_to_use->println(F("ff"));
    }
  #endif //FEATURE_QLF

  port_to_use->print(F("Quiet Paddle Interrupt: "));
  if (configuration.paddle_interruption_quiet_time_element_lengths > 0){
    port_to_use->println(configuration.paddle_interruption_quiet_time_element_lengths);
  } else {
    port_to_use->println(F("Off"));
  }

  #if !defined(OPTION_EXCLUDE_MILL_MODE)
    port_to_use->print(F("Mill Mode: O"));
    if (configuration.cli_mode == CLI_NORMAL_MODE){
      port_to_use->println(F("ff"));
    } else {
      port_to_use->println(F("n"));
    }
  #endif // !defined(OPTION_EXCLUDE_MILL_MODE)

  port_to_use->print(F("PTT buffered character hold active: O"));
  if (configuration.ptt_buffer_hold_active){
    port_to_use->println(F("n"));
  } else {
    port_to_use->println(F("ff"));
  }  

  port_to_use->print(F("TX Inhibit: O"));
  if ((digitalRead(tx_inhibit_pin) == tx_inhibit_pin_active_state)){
    port_to_use->println(F("n"));
  } else {
    port_to_use->println(F("ff"));
  }  
  port_to_use->print(F("TX Pause: O"));
  if ((digitalRead(tx_pause_pin) == tx_pause_pin_active_state)){
    port_to_use->println(F("n"));
  } else {
    port_to_use->println(F("ff"));
  }  

  #if defined(FEATURE_PADDLE_ECHO) //qqqqqq
    port_to_use->print(F("Paddle Echo: O"));
    if (cli_paddle_echo){
      port_to_use->println(F("n"));
    } else {
      port_to_use->println(F("ff"));
    }  
  #endif

  #if defined(FEATURE_STRAIGHT_KEY_ECHO)
    port_to_use->print(F("Straight Key Echo: O"));
    if (cli_straight_key_echo){
      port_to_use->println(F("n"));
    } else {
      port_to_use->println(F("ff"));
    }  
  #endif



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
//aaaaaaa
  #if defined(FEATURE_ETHERNET)
    port_to_use->print(F("Ethernet: "));
    port_to_use->print(configuration.ip[0]);
    port_to_use->print(F("."));
    port_to_use->print(configuration.ip[1]);
    port_to_use->print(F("."));
    port_to_use->print(configuration.ip[2]);
    port_to_use->print(F("."));
    port_to_use->println(configuration.ip[3]);      
  #endif

  port_to_use->println(F(">"));
  
}
#endif

//---------------------------------------------------------------------



#if defined(OPTION_PROSIGN_SUPPORT)
char * convert_prosign(byte prosign_code)
{

  switch(prosign_code){
    case PROSIGN_AA: return((char*)"AA"); break;
    case PROSIGN_AS: return((char*)"AS"); break;
    case PROSIGN_BK: return((char*)"BK"); break;
    case PROSIGN_CL: return((char*)"CL"); break;
    case PROSIGN_CT: return((char*)"CT"); break;
    case PROSIGN_KN: return((char*)"KN"); break;
    case PROSIGN_NJ: return((char*)"NJ"); break;
    case PROSIGN_SK: return((char*)"SK"); break;
    case PROSIGN_SN: return((char*)"SN"); break;
    case PROSIGN_HH: return((char*)"HH"); break; // iz0rus
    default: return((char*)""); break;

  }

}
#endif //OPTION_PROSIGN_SUPPORT

//---------------------------------------------------------------------

int convert_cw_number_to_ascii (long number_in)
{

  // number_in:  1 = dit, 2 = dah, 9 = a space

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
    #if !defined(OPTION_PROSIGN_SUPPORT)
      case 2111212: return '*'; break; // BK 
    #endif 
//    case 221122: return 44; break;  // ,
//    case 221122: return '!'; break;  // ! sp5iou 20180328
    case 221122: return ','; break; 
    case 121212: return '.'; break;
    case 122121: return '@'; break;
    case 222222: return 92; break;  // special hack; six dahs = \ (backslash)
    case 21112: return '='; break;  // BT
    //case 2222222: return '+'; break;
    case 9: return 32; break;       // special 9 = space

    #ifndef OPTION_PS2_NON_ENGLISH_CHAR_LCD_DISPLAY_SUPPORT
      case 12121: return '+'; break;
    #else
      case 211112: return 45; break; // - // sp5iou
      case 212122: return 33; break; // ! //sp5iou
      case 1112112: return 36; break; // $ //sp5iou
      #if !defined(OPTION_PROSIGN_SUPPORT)
        case 12111: return 38; break; // & // sp5iou
      #endif  
      case 122221: return 39; break; // ' // sp5iou
      case 121121: return 34; break; // " // sp5iou
      case 112212: return 95; break; // _ // sp5iou
      case 212121: return 59; break; // ; // sp5iou
      case 222111: return 58; break; // : // sp5iou
      case 212212: return 41; break; // KK (stored as ascii ) ) // sp5iou
      #if !defined(OPTION_PROSIGN_SUPPORT)
        case 111212: return 62; break; // SK (stored as ascii > ) // sp5iou
      #endif
      case 12121: return 60; break; // AR (store as ascii < ) // sp5iou
    #endif //OPTION_PS2_NON_ENGLISH_CHAR_LCD_DISPLAY_SUPPORT


    #if defined(OPTION_PROSIGN_SUPPORT)
      #if !defined(OPTION_NON_ENGLISH_EXTENSIONS)
        case 1212:   return PROSIGN_AA; break;
      #endif
      case 12111:    return PROSIGN_AS; break;
      case 2111212:  return PROSIGN_BK; break;
      case 21211211: return PROSIGN_CL; break;
      case 21212:    return PROSIGN_CT; break;
      case 21221:    return PROSIGN_KN; break;
      case 211222:   return PROSIGN_NJ; break;
      case 111212:   return PROSIGN_SK; break;
      case 11121:    return PROSIGN_SN; break;
      case 11111111: return PROSIGN_HH; break;  // iz0rus
    #else //OPTION_PROSIGN_SUPPORT
      case 21221: return 40; break; // (KN store as ascii ( ) //sp5iou //aaaaaaa
    #endif //OPTION_PROSIGN_SUPPORT

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
      case 21211: return 199; break;     // Ç
      case 11221: return 208; break;     // Ð
      case 12112: return 200; break;     // È
      case 11211: return 201; break;     // É
      case 221121: return 142; break;    // Ž
    #endif //OPTION_NON_ENGLISH_EXTENSIONS


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

  // if (free > 2048) {
  //   free = 0;
  // }
  
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
void serial_status_memories(PRIMARY_SERIAL_CLS * port_to_use)
{
  int last_memory_location;

  #if defined(OPTION_PROSIGN_SUPPORT)
    byte eeprom_temp = 0;
    static char * prosign_temp = 0;
  #endif

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
          #if defined(OPTION_PROSIGN_SUPPORT)
            eeprom_temp = EEPROM.read(y);
            if ((eeprom_temp > PROSIGN_START) && (eeprom_temp < PROSIGN_END)){
              prosign_temp = convert_prosign(eeprom_temp);
              port_to_use->print(prosign_temp[0]);
              port_to_use->print(prosign_temp[1]);
            } else {
              port_to_use->write(eeprom_temp);
            }
          #else         
            if ((EEPROM.read(y) == 32) && ((EEPROM.read(y+1) == 255) || ((y+1) >= last_memory_location))){
              port_to_use->write("_");
            } else {
              port_to_use->write(EEPROM.read(y));
            }
          #endif //OPTION_PROSIGN_SUPPORT
        } else {
          //port_to_use->write("$");
          y = last_memory_location;
        }
      }
    }

    #if defined(DEBUG_MEMORY_LOCATIONS)
      port_to_use->print("  start: ");
      port_to_use->print(memory_start(x));
      port_to_use->print(" end: ");
      port_to_use->print(memory_end(x));
      port_to_use->print(" size: ");
      port_to_use->print(memory_end(x)-memory_start(x));
    #endif

    port_to_use->println();
  }
}
#endif

//---------------------------------------------------------------------

#if defined(FEATURE_SERIAL) && defined(FEATURE_MEMORIES) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_program_memory(PRIMARY_SERIAL_CLS * port_to_use)
{


  /*

  CLI memory programming test string

  WE LOVE RADIO AND SMALL COMPUTING DEVICES AND WE COMBINE THE TWO TO AUTOMATE EXPERIMENT OR JUST SEE IF SOMETHING CAN BE DONE WE BELIEVE ITS BETTER TO BUILD SOMETHING WITH OUR OWN HANDS HOWEVER SMALL OR IMPERFECT AND IMPROVE AND EXPAND IT OVER TIME WE SUPPORT EXPERIMENTERS OF ALL LEVELS AND EXCHANGE IDEAS ABOUT AMATEUR RADIO HARDWARE HOMEBREWING AND SOFTWARE DEVELOPMENT

  */

  uint8_t incoming_serial_byte = 0;
  uint8_t memory_number = 0;
  uint8_t looping = 1;
  int memory_index = 0;
  uint8_t memory_number_entered = 0;
  uint8_t memory_data_entered = 0;
  uint8_t error_flag = 0;
  uint8_t memory_1_or_1x_flag = 0;

  
  uint8_t incoming_serial_byte_buffer[serial_program_memory_buffer_size];
  unsigned int incoming_serial_byte_buffer_size = 0;


  while (looping){
    if (keyer_machine_mode == KEYER_NORMAL) {          // might as well do something while we're waiting
      check_paddles();
      service_dit_dah_buffers();
    }

    while ((port_to_use->available()) && (incoming_serial_byte_buffer_size < serial_program_memory_buffer_size)){  // get serial data if available
      incoming_serial_byte_buffer[incoming_serial_byte_buffer_size] = uppercase(port_to_use->read()); 
      incoming_serial_byte_buffer_size++;
    }

    if (incoming_serial_byte_buffer_size){
      incoming_serial_byte = incoming_serial_byte_buffer[0];
      port_to_use->write(incoming_serial_byte);
      for (unsigned int x = 0;x < (incoming_serial_byte_buffer_size - 1);x++){
        incoming_serial_byte_buffer[x] = incoming_serial_byte_buffer[x+1];
      }
      incoming_serial_byte_buffer_size--;

      if ((memory_1_or_1x_flag) && ((incoming_serial_byte < 48) || (incoming_serial_byte > 57))){  // do we have something other than a number?
        memory_1_or_1x_flag = 0;
        memory_number_entered = 1;
      }

      if (!memory_number_entered) {
        if ((incoming_serial_byte > 47) && (incoming_serial_byte < 58)) {  // do we have a number?
          if (memory_1_or_1x_flag){    
            memory_number = incoming_serial_byte - 48 + 10;
            memory_1_or_1x_flag = 0;
            memory_number_entered = 1;
          } else {
            memory_number = incoming_serial_byte - 48;
            if ((memory_number == 1) && (number_of_memories > 9)) {
              memory_1_or_1x_flag = 1;
            } else {
              memory_number_entered = 1;
            }
          }
          // memory number out of range check
          if (memory_number > number_of_memories){
            looping = 0;
            error_flag = 1;
          }
        } else {
          looping = 0;
          error_flag = 1;
        }

      } else {

        if (incoming_serial_byte == 13){  // we got a carriage return
          looping = 0;
          EEPROM.write((memory_start(memory_number-1)+memory_index),255);
        } else {  // looking for memory data
          memory_data_entered = 1;
          #if !defined(OPTION_SAVE_MEMORY_NANOKEYER)
            while ((port_to_use->available()) && (incoming_serial_byte_buffer_size < serial_program_memory_buffer_size)){  // get serial data if available
              incoming_serial_byte_buffer[incoming_serial_byte_buffer_size] = uppercase(port_to_use->read()); 
              incoming_serial_byte_buffer_size++;
            }  
          #endif           
          EEPROM.write((memory_start(memory_number-1)+memory_index),incoming_serial_byte);
          #if !defined(OPTION_SAVE_MEMORY_NANOKEYER)
            while ((port_to_use->available()) && (incoming_serial_byte_buffer_size < serial_program_memory_buffer_size)){  // get serial data if available
              incoming_serial_byte_buffer[incoming_serial_byte_buffer_size] = uppercase(port_to_use->read()); 
              incoming_serial_byte_buffer_size++;
            }   
          #endif              
          #ifdef DEBUG_EEPROM
            debug_serial_port->print(F("serial_program_memory: wrote "));
            debug_serial_port->print(incoming_serial_byte);
            debug_serial_port->print(F(" to location "));
            debug_serial_port->println((memory_start(memory_number-1)+memory_index));
          #endif
          memory_index++;
          if ((memory_start(memory_number-1) + memory_index) > (memory_end(memory_number-1)-2)) {    // are we at last memory location?
            looping = 0;
            EEPROM.write((memory_start(memory_number-1)+memory_index),255);
            port_to_use->println(F("Memory full, truncating."));
          }

        }

      } //
    }

  }

  if ((memory_number_entered) && (memory_data_entered) && (!error_flag)){
    port_to_use->print(F("\n\rWrote memory "));
    port_to_use->println(memory_number);
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
#if defined(FEATURE_MEMORIES) || defined(FEATURE_COMMAND_LINE_INTERFACE)
void send_serial_number(byte cut_numbers,int increment_serial_number,byte buffered_sending){

  String serial_number_string;

  serial_number_string = String(serial_number, DEC);
  if (serial_number_string.length() < 3 ) {
    if (cut_numbers){
      if (buffered_sending){
        add_to_send_buffer('T');
      } else {
        if (keyer_machine_mode != KEYER_COMMAND_MODE){display_serial_number_character('T');} //Display the SN as well as play it unless playing back after programming for verification(WD9DMP)
        send_char('T',KEYER_NORMAL);
      }
    } else {
      if (buffered_sending){
        add_to_send_buffer('0');
      } else {
        if (keyer_machine_mode != KEYER_COMMAND_MODE){display_serial_number_character('0');} //Display the SN as well as play it unless playing back after programming for verification(WD9DMP)
        send_char('0',KEYER_NORMAL);
      }
    }
  }
  if (serial_number_string.length() == 1) {
    if (cut_numbers){
      if (buffered_sending){
        add_to_send_buffer('T');
      } else {
        if (keyer_machine_mode != KEYER_COMMAND_MODE){display_serial_number_character('T');} //Display the SN as well as play it unless playing back after programming for verification(WD9DMP)
        send_char('T',KEYER_NORMAL);
      }
    } else {
      if (buffered_sending){
        add_to_send_buffer('0');
      } else {
        if (keyer_machine_mode != KEYER_COMMAND_MODE){display_serial_number_character('0');} //Display the SN as well as play it unless playing back after programming for verification(WD9DMP)
        send_char('0',KEYER_NORMAL);
      }
    }
  }
  for (unsigned int a = 0; a < serial_number_string.length(); a++)  {
    if ((serial_number_string[a] == '0') && (cut_numbers)){
      if (buffered_sending){
        add_to_send_buffer('T');
      } else {
        if (keyer_machine_mode != KEYER_COMMAND_MODE){display_serial_number_character('T');} //Display the SN as well as play it unless playing back after programming for verification(WD9DMP)
        send_char('T',KEYER_NORMAL);
      }
    } else {
      if ((serial_number_string[a] == '9') && (cut_numbers)) {
        if (buffered_sending){
          add_to_send_buffer('N');
        } else {
          if (keyer_machine_mode != KEYER_COMMAND_MODE){display_serial_number_character('N');} //Display the SN as well as play it unless playing back after programming for verification(WD9DMP)
          send_char('N',KEYER_NORMAL);
        }
      } else {
        if (buffered_sending){
          add_to_send_buffer(serial_number_string[a]);        
        } else {
          if (keyer_machine_mode != KEYER_COMMAND_MODE){display_serial_number_character(serial_number_string[a]);} //Display the SN as well as play it unless playing back after programming for verification(WD9DMP)
          send_char(serial_number_string[a],KEYER_NORMAL);
        }

     }
    }
  }

  serial_number = serial_number + increment_serial_number;

}

#endif
//New function below to send serial number character to CLI as well as LCD (WD9DMP)
//---------------------------------------------------------------------
#if defined(FEATURE_MEMORIES) || defined(FEATURE_COMMAND_LINE_INTERFACE)
void display_serial_number_character(char snumchar){
  #if defined(FEATURE_SERIAL)
  #ifdef FEATURE_COMMAND_LINE_INTERFACE
    primary_serial_port->write(snumchar);
    #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
      secondary_serial_port->write(snumchar);
    #endif //FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
  #endif //FEATURE_COMMAND_LINE_INTERFACE
#endif // (FEATURE_SERIAL)
#ifdef FEATURE_DISPLAY
  if (lcd_send_echo) {
    display_scroll_print_char(snumchar);
    service_display();
    }
#endif // FEATURE_DISPLAY
}

#endif
//---------------------------------------------------------------------
#ifdef FEATURE_MEMORIES
byte play_memory(byte memory_number)
{
  
  unsigned int jump_back_to_y = 9999;
  byte jump_back_to_memory_number = 255;
  static byte prosign_flag = 0;
  static byte prosign_before_flag = 0;
  byte eeprom_byte_read = 0;  
  byte pause_sending_buffer_backspace = 0;

  play_memory_prempt = 0;

  #if defined(OPTION_PROSIGN_SUPPORT)
    byte eeprom_temp = 0;
    static char * prosign_temp = 0;
  #endif  

  if (memory_number > (number_of_memories - 1)) {
    boop();
    return 0;
  }

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

    service_tx_inhibit_and_pause();

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

      pause_sending_buffer_backspace = 0;

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

            #if defined(OPTION_PROSIGN_SUPPORT)
              eeprom_temp = eeprom_byte_read;
              if ((eeprom_temp > PROSIGN_START) && (eeprom_temp < PROSIGN_END)){
                prosign_temp = convert_prosign(eeprom_temp);
              }
            #endif //OPTION_PROSIGN_SUPPORT

            #if defined(FEATURE_SERIAL)
              #ifndef FEATURE_WINKEY_EMULATION
                if (!cw_send_echo_inhibit) {
                  #if defined(OPTION_PROSIGN_SUPPORT)
                    if ((eeprom_temp > PROSIGN_START) && (eeprom_temp < PROSIGN_END)){
                      primary_serial_port->print(prosign_temp[0]);
                      primary_serial_port->print(prosign_temp[1]);
                      #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
                        secondary_serial_port->print(prosign_temp[0]);
                        secondary_serial_port->print(prosign_temp[1]);
                      #endif //FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT                      
                    } else {
                      primary_serial_port->write(eeprom_byte_read);
                      #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
                        secondary_serial_port->write(eeprom_byte_read);
                      #endif //FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
                    }
                  #else
                    primary_serial_port->write(eeprom_byte_read);
                    #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
                      secondary_serial_port->write(eeprom_byte_read);
                    #endif //FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
                  #endif // OPTION_PROSIGN_SUPPORT
                }
              #else  //FEATURE_WINKEY_EMULATION
                if (((primary_serial_port_mode == SERIAL_WINKEY_EMULATION) && (winkey_paddle_echo_activated) && (winkey_host_open)) || (primary_serial_port_mode != SERIAL_WINKEY_EMULATION)) {
  
                  #if defined(OPTION_PROSIGN_SUPPORT)
                    if ((eeprom_temp > PROSIGN_START) && (eeprom_temp < PROSIGN_END)){
                      winkey_port_write(prosign_temp[0],0);
                      winkey_port_write(prosign_temp[1],0);                 
                    } else {
                      winkey_port_write(eeprom_byte_read,0);
                    }
                  #else
                    winkey_port_write(eeprom_byte_read,0);
                  #endif // OPTION_PROSIGN_SUPPORT



                }
                #ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
                  #if defined(OPTION_PROSIGN_SUPPORT)
                    if ((eeprom_temp > PROSIGN_START) && (eeprom_temp < PROSIGN_END)){
                      secondary_serial_port->print(prosign_temp[0]);
                      secondary_serial_port->print(prosign_temp[1]);                      
                    } else {
                      secondary_serial_port->write(eeprom_byte_read);
                    }
                  #else
                    secondary_serial_port->write(eeprom_byte_read);
                  #endif // OPTION_PROSIGN_SUPPORT
                #endif //FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT  

              #endif //FEATURE_WINKEY_EMULATION
            #endif //FEATURE_SERIAL

            #ifdef FEATURE_DISPLAY
              if (lcd_send_echo) {
                #if defined(OPTION_PROSIGN_SUPPORT)
                    if ((eeprom_temp > PROSIGN_START) && (eeprom_temp < PROSIGN_END)){
                      display_scroll_print_char(prosign_temp[0]);
                      display_scroll_print_char(prosign_temp[1]);                    
                    } else {
                      if (prosign_flag){
                        display_scroll_print_char(eeprom_byte_read); 
                        display_scroll_print_char(EEPROM.read(y+1));
                        prosign_before_flag = 1;
                      } else {
                        if (prosign_before_flag){  
                          prosign_before_flag = 0; 
                        } else {
                          display_scroll_print_char(eeprom_byte_read);
                        }
                      }
                    }
                #else 
                  if (prosign_flag){
                    display_scroll_print_char(eeprom_byte_read); 
                    display_scroll_print_char(EEPROM.read(y+1));
                    prosign_before_flag = 1;
                  } else {
                    if (prosign_before_flag){  
                      prosign_before_flag = 0; 
                    } else {
                      display_scroll_print_char(eeprom_byte_read);
                    }
                  }
                #endif
                service_display();
              }
            #endif    // FEATURE_DISPLAY

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

              case 'X':                         // X - switch transmitter
                y++;
                if (y < (memory_end(memory_number)+1)) {
                  eeprom_byte_read2 = EEPROM.read(y);
                  if ((eeprom_byte_read2 > 48) && (eeprom_byte_read2 < 55)) {
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
                break;  // case X

              case 'C':                       // C - play serial number with cut numbers T and N, then increment
                  send_serial_number(1,1,0);
                break;

              case 'D':                      // D - delay for ### seconds
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
                  return 0;
                }
                break;  // case D

              case 'E':                       // E - play serial number, then increment
                  send_serial_number(0,1,0);
                break;

              case 'F':                       // F - change sidetone frequency
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
                if ((input_error != 1) && (int_from_macro > sidetone_hz_limit_low) && (int_from_macro < sidetone_hz_limit_high)) {
                  configuration.hz_sidetone = int_from_macro;
                }
                break;


              case 'H':                       // H - Switch to Hell
                char_send_mode = HELL;
                break;

              case 'L':                       // L - Switch to CW
                char_send_mode = CW;
                break;

              case 'N':                       // N - decrement serial number (do not play)
                serial_number--;
                break;

              case '+':                       // + - Prosign
                prosign_flag = 1;
                break;

              case 'Q':                       // Q - QRSS mode and set dit length to ##
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
              break;  //case Q

              case 'R':                       // R - regular speed mode
                speed_mode = SPEED_NORMAL;
                //calculate_element_length();
              break;

              case 'T':                      // T - transmit for ### seconds
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
                sending_mode = AUTOMATIC_SENDING;
                if (input_error != 1) {   // go ahead and transmit
                  tx_and_sidetone_key(1);
                  delay_result = memory_nonblocking_delay(int_from_macro*1000);
                  tx_and_sidetone_key(0);
                }
                if (delay_result) {   // if a paddle or button0 was hit during the delay, exit
                  return 0;
                }
                break;  // case T

              case 'U':                      // U - turn on PTT
                manual_ptt_invoke = 1;
                ptt_key();
                break;

              case 'V':                      // V - turn off PTT
                manual_ptt_invoke = 0;
                ptt_unkey();
                break;

              case 'W':                      // W - change speed to ### WPM
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
                break;  // case W

                case 'Y':                // Y - Relative WPM change (positive)
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
                  break; // case Y

                case 'Z':                // Z - Relative WPM change (positive)
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
                  break; // case Z

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
              return 0;
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
              return 0;
            }
          #endif //FEATURE_STRAIGHT_KEY
        }

      } else {
        if (y == (memory_start(memory_number))) {      // memory is totally empty - do a boop
          repeat_memory = 255;
          #ifdef FEATURE_DISPLAY
            if (LCD_COLUMNS < 9){
              lcd_center_print_timed("MemEmpty", 0, default_display_msg_delay);
            } else {
              lcd_center_print_timed("Memory empty", 0, default_display_msg_delay);            
            }
          #else
            boop();
          #endif
        }
        
        // if we had an inserted memory, jump back to the original one
        if (/*(y== (memory_end(memory_number)+1)) &&*/ (jump_back_to_y < 9999) && (jump_back_to_memory_number < 255)) {
          #ifdef DEBUG_PLAY_MEMORY
            debug_serial_port->print(F("\nplay_memory: jump back to original memory:"));
            debug_serial_port->println(jump_back_to_memory_number);
          #endif
          y = jump_back_to_y;
          memory_number = jump_back_to_memory_number;
          jump_back_to_y = 9999;
          jump_back_to_memory_number = 255;
        } else {        
        
        
        
         return 0;
        }
      }
    } else {
      if (pause_sending_buffer == 0) {
        y = (memory_end(memory_number)+1);   // we got a play_memory_prempt flag, exit out
      } else {
        y--;  // we're in a pause mode, so sit and spin awhile
        if ((y > (memory_start(memory_number)) && (!pause_sending_buffer_backspace))){
          y--;
          pause_sending_buffer_backspace = 1;
        }
        check_ptt_tail();
        #if defined(FEATURE_SEQUENCER)
          check_sequencer_tail_time();
        #endif
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
      

  } //for (int y = (memory_start(memory_number)); (y < (memory_end(memory_number)+1)); y++)

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
    if (LCD_COLUMNS < 9){
      lcd_print_string.concat("PgmMem");
    } else {
      lcd_print_string.concat("Pgm Memory ");
    }
    lcd_print_string.concat(memory_number+1);
    lcd_center_print_timed(lcd_print_string, 0, default_display_msg_delay);
  #endif

  //send_dit();
  beep();

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
         sending_mode = MANUAL_SENDING;
         send_dit();
         dit_buffer = 0;
         paddle_hit = 1;
         cwchar = (cwchar * 10) + 1;
         last_element_time = millis();
         #ifdef DEBUG_MEMORY_WRITE
           debug_serial_port->write(".");
         #endif
       }
       if (dah_buffer) {
        sending_mode = MANUAL_SENDING;
        send_dah();
        dah_buffer = 0;
        paddle_hit = 1;
         cwchar = (cwchar * 10) + 2;
         last_element_time = millis();
         #ifdef DEBUG_MEMORY_WRITE
           debug_serial_port->write("_");
         #endif
       }
    
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


// TODO - need to add something here to handle straight key leading space
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
        debug_serial_port->print(memory_start(memory_number)+memory_location_index);
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
  
#if defined (ARDUINO_MAPLE_MINI)||defined(ARDUINO_GENERIC_STM32F103C) //sp5iou 20180329
  pinMode (paddle_left, INPUT_PULLUP);
  pinMode (paddle_right, INPUT_PULLUP);
#else
  pinMode (paddle_left, INPUT);
  digitalWrite (paddle_left, HIGH);
  pinMode (paddle_right, INPUT);
  digitalWrite (paddle_right, HIGH);
#endif //defined (ARDUINO_MAPLE_MINI)||defined(ARDUINO_GENERIC_STM32F103C) sp5iou 20180329

  #if defined(FEATURE_CAPACITIVE_PADDLE_PINS)
    if (capactive_paddle_pin_inhibit_pin){
      pinMode (capactive_paddle_pin_inhibit_pin, INPUT);
      digitalWrite (capactive_paddle_pin_inhibit_pin, LOW);    
    }
  #endif //FEATURE_CAPACITIVE_PADDLE_PINS
  
  if (tx_key_line_1) {
    pinMode (tx_key_line_1, OUTPUT);
    digitalWrite (tx_key_line_1, tx_key_line_inactive_state);
  }
  if (tx_key_line_2) {
    pinMode (tx_key_line_2, OUTPUT);
    digitalWrite (tx_key_line_2, tx_key_line_inactive_state);
  }
  if (tx_key_line_3) {
    pinMode (tx_key_line_3, OUTPUT);
    digitalWrite (tx_key_line_3, tx_key_line_inactive_state);
  }
  if (tx_key_line_4) {
    pinMode (tx_key_line_4, OUTPUT);
    digitalWrite (tx_key_line_4, tx_key_line_inactive_state);
  }
  if (tx_key_line_5) {
    pinMode (tx_key_line_5, OUTPUT);
    digitalWrite (tx_key_line_5, tx_key_line_inactive_state);
  }
  if (tx_key_line_6) {
    pinMode (tx_key_line_6, OUTPUT);
    digitalWrite (tx_key_line_6, tx_key_line_inactive_state);
  }
    
  
  if (ptt_tx_1) {
    pinMode (ptt_tx_1, OUTPUT);
    digitalWrite (ptt_tx_1, ptt_line_inactive_state);
  }
  if (ptt_tx_2) {
    pinMode (ptt_tx_2, OUTPUT);
    digitalWrite (ptt_tx_2, ptt_line_inactive_state);
  }
  if (ptt_tx_3) {
    pinMode (ptt_tx_3, OUTPUT);
    digitalWrite (ptt_tx_3, ptt_line_inactive_state);
  }
  if (ptt_tx_4) {
    pinMode (ptt_tx_4, OUTPUT);
    digitalWrite (ptt_tx_4, ptt_line_inactive_state);
  }
  if (ptt_tx_5) {
    pinMode (ptt_tx_5, OUTPUT);
    digitalWrite (ptt_tx_5, ptt_line_inactive_state);
  }
  if (ptt_tx_6) {
    pinMode (ptt_tx_6, OUTPUT);
    digitalWrite (ptt_tx_6, ptt_line_inactive_state);
  }
  pinMode (sidetone_line, OUTPUT);
  digitalWrite (sidetone_line, LOW);

  if (tx_key_dit) {
    pinMode (tx_key_dit, OUTPUT);
    digitalWrite (tx_key_dit, tx_key_dit_and_dah_pins_inactive_state);
  }
  if (tx_key_dah) {
    pinMode (tx_key_dah, OUTPUT);
    digitalWrite (tx_key_dah, tx_key_dit_and_dah_pins_inactive_state);
  }

  #ifdef FEATURE_CW_DECODER
    pinMode (cw_decoder_pin, INPUT_PULLUP);
    // pinMode (cw_decoder_pin, INPUT);
    // digitalWrite (cw_decoder_pin, HIGH);

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
    pinMode(ptt_interlock,INPUT_PULLUP);
    // pinMode(ptt_interlock,INPUT);
    // if (ptt_interlock_active_state == HIGH){
    //   digitalWrite(ptt_interlock,LOW);
    // } else {
    //   digitalWrite(ptt_interlock,HIGH);
    // }
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

  #if defined(FEATURE_SLEEP)
    if (keyer_awake){
      pinMode(keyer_awake,OUTPUT);
      digitalWrite(keyer_awake,KEYER_AWAKE_PIN_AWAKE_STATE);
    }
  #endif //FEATURE_SLEEP

  #ifdef FEATURE_SIDETONE_SWITCH
    pinMode(SIDETONE_SWITCH,INPUT_PULLUP);
  #endif //FEATURE_SIDETONE_SWITCH

  #if defined (FEATURE_4x4_KEYPAD)||defined(FEATURE_3x4_KEYPAD)
    pinMode(Row3,INPUT_PULLUP);
    pinMode(Row2,INPUT_PULLUP);
    pinMode(Row1,INPUT_PULLUP);
    pinMode(Row0,INPUT_PULLUP);
    pinMode(Col2,INPUT_PULLUP);
    pinMode(Col1,INPUT_PULLUP);
    pinMode(Col0,INPUT_PULLUP);
  #endif

  #if defined (FEATURE_4x4_KEYPAD)
    pinMode(Col3,INPUT_PULLUP);        //Col3 not used if 3x4 keypad is defined.
  #endif

  #ifdef FEATURE_SEQUENCER
    if (sequencer_1_pin){
      pinMode(sequencer_1_pin,OUTPUT);
      digitalWrite(sequencer_1_pin,sequencer_pins_inactive_state);
    }
    if (sequencer_2_pin){
      pinMode(sequencer_2_pin,OUTPUT);
      digitalWrite(sequencer_2_pin,sequencer_pins_inactive_state);
    }
    if (sequencer_3_pin){
      pinMode(sequencer_3_pin,OUTPUT);
      digitalWrite(sequencer_3_pin,sequencer_pins_inactive_state);
    }
    if (sequencer_4_pin){
      pinMode(sequencer_4_pin,OUTPUT);
      digitalWrite(sequencer_4_pin,sequencer_pins_inactive_state);
    }
    if (sequencer_5_pin){
      pinMode(sequencer_5_pin,OUTPUT);
      digitalWrite(sequencer_5_pin,sequencer_pins_inactive_state);
    }
  #endif //FEATURE_SEQUENCER

  if (ptt_input_pin){
    pinMode(ptt_input_pin,INPUT_PULLUP);
  }

  if (tx_inhibit_pin){
    pinMode(tx_inhibit_pin,INPUT_PULLUP);
  }

  if (tx_pause_pin){
    pinMode(tx_pause_pin,INPUT_PULLUP);
  }

  if (potentiometer_enable_pin){
    pinMode(potentiometer_enable_pin,INPUT_PULLUP);
  }
  
} //initialize_pins()

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
  #ifdef FEATURE_TRAINING_COMMAND_LINE_INTERFACE
  debug_serial_port->println(F("FEATURE_TRAINING_COMMAND_LINE_INTERFACE"));
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
  #ifdef FEATURE_AMERICAN_MORSE
  debug_serial_port->println(F("FEATURE_AMERICAN_MORSE"));
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
  #ifdef FEATURE_LCD_8BIT
  debug_serial_port->println(F("FEATURE_LCD_8BIT"));
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
  configuration.paddle_interruption_quiet_time_element_lengths = default_paddle_interruption_quiet_time_element_lengths;
  configuration.hz_sidetone = initial_sidetone_freq;
  configuration.memory_repeat_time = default_memory_repeat_time;
  configuration.cmos_super_keyer_iambic_b_timing_percent = default_cmos_super_keyer_iambic_b_timing_percent;
  configuration.dah_to_dit_ratio = initial_dah_to_dit_ratio;
  configuration.length_wordspace = default_length_wordspace;
  configuration.weighting = default_weighting;
  configuration.wordsworth_wordspace = default_wordsworth_wordspace;
  configuration.wordsworth_repetition = default_wordsworth_repetition;
  configuration.wpm_farnsworth = initial_speed_wpm;
  configuration.cli_mode = CLI_NORMAL_MODE;
  configuration.wpm_command_mode = initial_command_mode_speed_wpm;
  configuration.ptt_buffer_hold_active = 0;
  configuration.sidetone_volume = sidetone_volume_low_limit + ((sidetone_volume_high_limit - sidetone_volume_low_limit) / 2);

  configuration.ptt_lead_time[0] = initial_ptt_lead_time_tx1;
  configuration.ptt_tail_time[0] = initial_ptt_tail_time_tx1;
  configuration.ptt_lead_time[1] = initial_ptt_lead_time_tx2;
  configuration.ptt_tail_time[1] = initial_ptt_tail_time_tx2;
  #if !defined(OPTION_SAVE_MEMORY_NANOKEYER)
    configuration.ptt_lead_time[2] = initial_ptt_lead_time_tx3;
    configuration.ptt_tail_time[2] = initial_ptt_tail_time_tx3;
    configuration.ptt_lead_time[3] = initial_ptt_lead_time_tx4;
    configuration.ptt_tail_time[3] = initial_ptt_tail_time_tx4;
    configuration.ptt_lead_time[4] = initial_ptt_lead_time_tx5;
    configuration.ptt_tail_time[4] = initial_ptt_tail_time_tx5;
    configuration.ptt_lead_time[5] = initial_ptt_lead_time_tx6;
    configuration.ptt_tail_time[5] = initial_ptt_tail_time_tx6;  

    for (int x = 0; x < 5; x++){
      configuration.ptt_active_to_sequencer_active_time[x] = 0;
      configuration.ptt_inactive_to_sequencer_inactive_time[x] = 0;
    }
  #endif //OPTION_SAVE_MEMORY_NANOKEYER        

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
    #ifdef OPTION_ENCODER_ENABLE_PULLUPS
      #if defined (ARDUINO_MAPLE_MINI)||defined(ARDUINO_GENERIC_STM32F103C) //sp5iou 20180329
        pinMode(rotary_pin1, INPUT_PULLUP);//sp5iou 20180329
        pinMode(rotary_pin2, INPUT_PULLUP);//sp5iou 20180329
      #else // (ARDUINO_MAPLE_MINI)||defined(ARDUINO_GENERIC_STM32F103C) //sp5iou 20180329
        pinMode(rotary_pin1, INPUT);
        pinMode(rotary_pin2, INPUT);
        digitalWrite(rotary_pin1, HIGH);
        digitalWrite(rotary_pin2, HIGH);
       #endif 
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

  #ifdef initial_sidetone_mode
    configuration.sidetone_mode = initial_sidetone_mode;
  #endif

  char_send_mode = CW;
  
  #if defined(FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING) && defined(OPTION_CMOS_SUPER_KEYER_IAMBIC_B_TIMING_ON_BY_DEFAULT) // DL1HTB initialize CMOS Super Keyer if feature is enabled
    configuration.cmos_super_keyer_iambic_b_timing_on = 1;
  #endif //FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING // #end DL1HTB initialize CMOS Super Keyer if feature is enabled

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
    initialize_eeprom();
  }

  // read settings from eeprom and initialize eeprom if it has never been written to
  if (read_settings_from_eeprom()) {
    #if defined(HARDWARE_GENERIC_STM32F103C)
      EEPROM.init(); //sp5iou 20180328 to reinitialize / initialize EEPROM
      EEPROM.format();//sp5iou 20180328 to reinitialize / format EEPROM
    #endif
    initialize_eeprom();
  }
}

//--------------------------------------------------------------------- 

void initialize_eeprom(){
  
  write_settings_to_eeprom(1);
  // #if defined(FEATURE_SINEWAVE_SIDETONE)
  //   initialize_tonsin();
  // #endif 
  beep_boop();
  beep_boop();
  beep_boop();    

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
            primary_serial_port_baud_rate = WINKEY_DEFAULT_BAUD;
          #endif  //ifndef OPTION_PRIMARY_SERIAL_PORT_DEFAULT_WINKEY_EMULATION
        } else {    
          #ifdef OPTION_PRIMARY_SERIAL_PORT_DEFAULT_WINKEY_EMULATION
            primary_serial_port_mode = SERIAL_WINKEY_EMULATION;
            primary_serial_port_baud_rate = WINKEY_DEFAULT_BAUD;
          #else
            primary_serial_port_mode = SERIAL_CLI;
            primary_serial_port_baud_rate = PRIMARY_SERIAL_PORT_BAUD;
          #endif  //ifndef OPTION_PRIMARY_SERIAL_PORT_DEFAULT_WINKEY_EMULATION
        }
        while (analogbuttonread(0)) {}
      #else //FEATURE_COMMAND_BUTTONS  
        #ifdef OPTION_PRIMARY_SERIAL_PORT_DEFAULT_WINKEY_EMULATION
          primary_serial_port_mode = SERIAL_WINKEY_EMULATION;
          primary_serial_port_baud_rate = WINKEY_DEFAULT_BAUD;
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
      primary_serial_port_baud_rate = WINKEY_DEFAULT_BAUD;
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
        while(primary_serial_port->available()){primary_serial_port->read();}  //clear out buffer at boot
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
        while(secondary_serial_port->available()){secondary_serial_port->read();}  //clear out buffer at boot
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
    #if defined(FEATURE_LCD_SAINSMART_I2C)
      lcd.begin();
      lcd.home();
    #else
      lcd.begin(LCD_COLUMNS, LCD_ROWS);
    #endif
    #ifdef FEATURE_LCD_ADAFRUIT_I2C
      lcd.setBacklight(lcdcolor);
    #endif //FEATURE_LCD_ADAFRUIT_I2C

    #ifdef FEATURE_LCD_ADAFRUIT_BACKPACK 
      lcd.setBacklight(HIGH);
    #endif
    #ifdef FEATURE_LCD_MATHERTEL_PCF8574 
      lcd.setBacklight(HIGH);
    #endif

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

    if (LCD_COLUMNS < 9){
      lcd_center_print_timed("K3NGKeyr",0,4000);
    } else {
      lcd_center_print_timed("K3NG Keyer",0,4000);
    }
  #endif //FEATURE_DISPLAY

  if (keyer_machine_mode != BEACON) {
    #ifndef OPTION_DO_NOT_SAY_HI
      // say HI
      // store current setting (compliments of DL2SBA - http://dl2sba.com/ )
      byte oldKey = key_tx; 
      byte oldSideTone = configuration.sidetone_mode;
      key_tx = 0;
      configuration.sidetone_mode = SIDETONE_ON;     
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
    #ifdef OPTION_BLINK_HI_ON_PTT
      blink_ptt_dits_and_dahs(".... ..");
    #endif

  }
}

//-------------------------------------------------------------------------------------------------------
#if defined(OPTION_BLINK_HI_ON_PTT) || (defined(OPTION_WINKEY_BLINK_PTT_ON_HOST_OPEN) && defined(FEATURE_WINKEY_EMULATION))
void blink_ptt_dits_and_dahs(char const * cw_to_send){


  sending_mode = AUTOMATIC_SENDING;

  for (int x = 0;x < 12;x++){
    switch(cw_to_send[x]){
      case '.':
        ptt_key();
        delay(100);
        ptt_unkey();
        delay(100);
        break;
      case '-':
        ptt_key();
        delay(300);
        ptt_unkey();
        delay(100);
        break;
      case ' ':
        delay(400);
        break;        
    }


    #ifdef OPTION_WATCHDOG_TIMER
      wdt_reset();
    #endif  //OPTION_WATCHDOG_TIMER

  }

}
#endif //defined(OPTION_BLINK_HI_ON_PTT) || (defined(OPTION_WINKEY_BLINK_PTT_ON_HOST_OPEN) && defined(FEATURE_WINKEY_EMULATION))

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

  #ifdef FEATURE_DISPLAY
    String lcd_string;
  #endif    
  
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
  if (key == 0x58) {sending_mode = MANUAL_SENDING;tx_and_sidetone_key(1);return;}
  
  if ((modifier.bmLeftShift) || (modifier.bmRightShift)) {
    switch(key){     
      case 0x2a:    // BACKSPACE - decrement serial number
        serial_number--;
        #ifdef FEATURE_DISPLAY
          if (LCD_COLUMNS < 9){
            lcd_center_print_timed("SN " + String(serial_number), 0, default_display_msg_delay);
          } else {
            lcd_center_print_timed("Serial: " + String(serial_number), 0, default_display_msg_delay);
          }
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
          if (LCD_COLUMNS < 9){
            lcd_string = "PgmMem";
          } else {
            lcd_string = "Program Memory";
          }
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

      case 0x06 : // CTRL-C
        configuration.keyer_mode = SINGLE_PADDLE;
        #ifdef FEATURE_DISPLAY
          if (LCD_COLUMNS < 9){
            lcd_center_print_timed("SnglePdl", 0, default_display_msg_delay);
          } else {
            lcd_center_print_timed("Single Paddle", 0, default_display_msg_delay);
          }
        #endif          
        config_dirty = 1;
        break;

      case 0x07 : // CTRL-D
        configuration.keyer_mode = ULTIMATIC;
        #ifdef FEATURE_DISPLAY
          if (LCD_COLUMNS < 9){
            lcd_center_print_timed("Ultimatc", 0, default_display_msg_delay);
          } else {
            lcd_center_print_timed("Ultimatic", 0, default_display_msg_delay);            
          }        
        #endif        
        config_dirty = 1;
        break;

      case 0x08 : // CTRL-E
        #ifdef FEATURE_DISPLAY
          if (LCD_COLUMNS < 9){
            lcd_center_print_timed("Entr SN", 0, default_display_msg_delay);
          } else {
            lcd_center_print_timed("Enter Serial #", 0, default_display_msg_delay);            
          }      
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
        if (key_tx && keyer_machine_mode != KEYER_COMMAND_MODE) { //Added check that keyer is NOT in command mode or keyer might be enabled for paddle commands (WD9DMP-1)
          key_tx = 0;
          #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("TX Off", 0, default_display_msg_delay);
          #endif
          
        } else if (!key_tx && keyer_machine_mode != KEYER_COMMAND_MODE) { //Added check that keyer is NOT in command mode or keyer might be enabled for paddle commands (WD9DMP)
          key_tx = 1;
          #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("TX On", 0, default_display_msg_delay);
          #endif      
        }
        break;

      case 0x10: // CTRL-M
        #ifdef FEATURE_FARNSWORTH
          #ifdef FEATURE_DISPLAY
            if (LCD_COLUMNS < 9){
              lcd_center_print_timed("Frns WPM", 0, default_display_msg_delay);
            } else {
              lcd_center_print_timed("Farnsworth WPM", 0, default_display_msg_delay);
            }
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
            if (LCD_COLUMNS < 9){
              lcd_center_print_timed("Pdl Rev", 0, default_display_msg_delay);
            } else {
              lcd_center_print_timed("Paddle Reverse", 0, default_display_msg_delay);
            }          
          #endif
        } else {
          configuration.paddle_mode = PADDLE_NORMAL;
          #ifdef FEATURE_DISPLAY
            if (LCD_COLUMNS < 9){
              lcd_center_print_timed("Pdl Norm", 0, default_display_msg_delay);
            } else {
              lcd_center_print_timed("Paddle Normal", 0, default_display_msg_delay);
            }          
          #endif      
        }
        config_dirty = 1;
        break;

      case 0x12 : // CTRL-O - cycle through sidetone modes on, paddle only and off - enhanced by Marc-Andre, VE2EVN  
        if (configuration.sidetone_mode == SIDETONE_PADDLE_ONLY) {
          configuration.sidetone_mode = SIDETONE_OFF;
          #ifdef FEATURE_DISPLAY
            if (LCD_COLUMNS < 9){
              lcd_center_print_timed("ST Off", 0, default_display_msg_delay);
            } else {
              lcd_center_print_timed("Sidetone Off", 0, default_display_msg_delay);
            }
          #endif
          boop();
        } else if (configuration.sidetone_mode == SIDETONE_ON) {
          configuration.sidetone_mode = SIDETONE_PADDLE_ONLY;
          beep();
             delay(200);
          beep();
          #ifdef FEATURE_DISPLAY
            if (LCD_COLUMNS < 9){
              lcd_center_print_timed("ST Pdl O", 0, default_display_msg_delay);
            }          
            if (LCD_COLUMNS > 19){
              lcd_center_print_timed("Sidetone Paddle Only", 0, default_display_msg_delay);
            } else {
              lcd_center_print_timed("Sidetone", 0, default_display_msg_delay);
              lcd_center_print_timed("Paddle Only", 1, default_display_msg_delay);
            }
          #endif      
        } else {
          #ifdef FEATURE_DISPLAY
            if (LCD_COLUMNS < 9){
              lcd_center_print_timed("ST On", 0, default_display_msg_delay);
            } else {            
              lcd_center_print_timed("Sidetone On", 0, default_display_msg_delay);
            }
          #endif      
          configuration.sidetone_mode = SIDETONE_ON;
          beep();
        }
        config_dirty = 1;
       break;

        #if defined(FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING)
          case 0x16 :  // CTRL-S
            if (configuration.cmos_super_keyer_iambic_b_timing_on){
              configuration.cmos_super_keyer_iambic_b_timing_on = 0;
              #ifdef FEATURE_DISPLAY
                if (LCD_COLUMNS < 9){
                  lcd_center_print_timed("CMOS Off", 0, default_display_msg_delay);
                }
                if (LCD_COLUMNS > 18){
                  lcd_center_print_timed("CMOS Superkeyer Off", 0, default_display_msg_delay);                  
                } else {            
                  lcd_center_print_timed("CMOS SK Off", 0, default_display_msg_delay);
                }              
              #endif      
            } else {
              #ifdef FEATURE_DISPLAY
                if (LCD_COLUMNS < 9){
                  lcd_center_print_timed("CMOS On", 0, default_display_msg_delay);
                } 
                if (LCD_COLUMNS > 17){
                  lcd_center_print_timed("CMOS Superkeyer On", 0, default_display_msg_delay);                  
                } else {            
                  lcd_center_print_timed("CMOS SK On", 0, default_display_msg_delay);
                }                
              #endif      
              configuration.cmos_super_keyer_iambic_b_timing_on = 1;
            }
            config_dirty = 1;
            break;
        #endif //FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING


      case 0x17 : // CTRL-T
        #ifdef FEATURE_MEMORIES
        repeat_memory = 255;
        #endif
        if (keyboard_tune_on) {
          sending_mode = MANUAL_SENDING;
          tx_and_sidetone_key(0);
          keyboard_tune_on = 0;
          #ifdef FEATURE_DISPLAY
            lcd_status = LCD_REVERT;
          #endif // FEATURE_DISPLAY
        } else {
          #ifdef FEATURE_DISPLAY
            lcd_center_print_timed("Tune", 0, default_display_msg_delay);
          #endif 
          sending_mode = MANUAL_SENDING;     
          tx_and_sidetone_key(1);
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
            if (LCD_COLUMNS < 9){
              lcd_center_print_timed("PTTInvke", 0, default_display_msg_delay);
            } else {
              lcd_center_print_timed("PTT Invoke", 0, default_display_msg_delay);
            }
          #endif      
          manual_ptt_invoke = 1;
          ptt_key();
        }
        break;

      case 0x1a : // CTRL-W        
        #ifdef FEATURE_DISPLAY
          if (LCD_COLUMNS < 9){
            lcd_center_print_timed("WPM Adj", 0, default_display_msg_delay);
          } else {
            lcd_center_print_timed("WPM Adjust", 0, default_display_msg_delay);
          }
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
            if (LCD_COLUMNS < 9){
              lcd_center_print_timed("AutoSOff", 0, default_display_msg_delay);
            } else {
              lcd_center_print_timed("Autospace Off", 0, default_display_msg_delay);              
            }
          #endif                                  
        } else {
          configuration.autospace_active = 1;
          config_dirty = 1;
          #ifdef FEATURE_DISPLAY
            if (LCD_COLUMNS < 9){
              lcd_center_print_timed("AutoS On", 0, default_display_msg_delay);
            } else {
              lcd_center_print_timed("Autospace On", 0, default_display_msg_delay);              
            }          
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
          if (LCD_COLUMNS < 9){
            lcd_center_print_timed("DfltRtio", 0, default_display_msg_delay);
          } else {
            lcd_center_print_timed("Default ratio", 0, default_display_msg_delay);
          }
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
      
    case 0x46: if (send_buffer_bytes) { send_buffer_bytes--; } return; break;  // DEL
    case 0x29 :  // ESC - clear the serial send buffer and a bunch of other stuff
      if (manual_ptt_invoke) {
        manual_ptt_invoke = 0;
        ptt_unkey();
      }
      if (keyboard_tune_on) {
        sending_mode = MANUAL_SENDING;
        tx_and_sidetone_key(0);
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
  if (key == 0x58) {sending_mode = MANUAL_SENDING;tx_and_sidetone_key(0);return;}
  
}
#endif //FEATURE_USB_KEYBOARD

//--------------------------------------------------------------------- 

void initialize_usb()
{

    #if defined(FEATURE_USB_KEYBOARD) || defined(FEATURE_USB_MOUSE)    
    if (Usb.Init() == -1) {
      #ifdef DEBUG_USB
      debug_serial_port->println(F("\rinitialize_usb: OSC did not start."));
      #endif //DEBUG_USB
      return;
    } else {
      #ifdef DEBUG_USB
      debug_serial_port->println(F("\rinitialize_usb: initializing"));
      #endif //DEBUG_USB
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
  sending_mode = MANUAL_SENDING;
  tx_and_sidetone_key(0);
};
void MouseRptParser::OnMiddleButtonDown(MOUSEINFO *mi){
  sending_mode = MANUAL_SENDING;
  tx_and_sidetone_key(1);
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

  // Updated code provided by Fred, VK2EFL
  // 
  // Note on OPTION_DIRECT_PADDLE_PIN_READS_MEGA, OPTION_DIRECT_PADDLE_PIN_READS_UNO, OPTION_SAVE_MEMORY_NANOKEYER
  // For Mega2560 and Uno/Nano speed up paddle pin reads by direct read of the register
  // it saves about 340 bytes of code too


  #ifndef FEATURE_CAPACITIVE_PADDLE_PINS
    #ifndef OPTION_INVERT_PADDLE_PIN_LOGIC
      #ifdef OPTION_DIRECT_PADDLE_PIN_READS_MEGA              // after April 2019, if this option is not defined then a direct read of the pins can never occur
        switch(pin_to_read) {
          case 2: return(bitRead(PINE, 4)); break;
          case 5: return(bitRead(PINE, 3)); break;
        }                                                     // end switch
      #endif                                                  // OPTION_DIRECT_PADDLE_READS_MEGA
      #ifdef OPTION_DIRECT_PADDLE_PIN_READS_UNO               // since with this verion, April 2019, this option is not defined then a direct read of the pins can never occur
        return (bitRead(PIND, pin_to_read));                  // use this line on Unos and Nanos
      #endif                                                  // OPTION_DIRECT_PADDLE_PIN_READS_UNO
      #ifdef OPTION_SAVE_MEMORY_NANOKEYER                     // 
        switch(pin_to_read) {
          case 2: return(bitRead(PIND, 2)); break;
          case 5: return(bitRead(PIND, 5)); break;
          case 8: return(bitRead(PINB, 0)); break;
        }                                                     // end switch
      #endif                                                  // OPTION_SAVE_MEMORY_NANOKEYER
      #if !defined(OPTION_DIRECT_PADDLE_PIN_READS_UNO) && !defined(OPTION_DIRECT_PADDLE_PIN_READS_MEGA) && !defined(OPTION_SAVE_MEMORY_NANOKEYER)
        return digitalRead(pin_to_read);                      // code using digitalRead
      #endif                                                  // !defined(OPTION_DIRECT_PADDLE_PIN_READS_UNO) && !defined(OPTION_DIRECT_PADDLE_PIN_READS_MEGA)
    #else                                                     // !OPTION_INVERT_PADDLE_PIN_LOGIC
      return !digitalRead(pin_to_read);                       // we do the regular digitalRead() if none of the direct register read options are valid
    #endif                                                    // !OPTION_INVERT_PADDLE_PIN_LOGIC
  #else                                                       // !FEATURE_CAPACITIVE_PADDLE_PINS
    if (capactive_paddle_pin_inhibit_pin) {
      if (digitalRead(capactive_paddle_pin_inhibit_pin) == HIGH) {
        return digitalRead(pin_to_read);
      }                                                       // end if
    }                                                         // end if (capactive_paddle_pin_inhibit_pin)
    if (read_capacitive_pin(pin_to_read) > capacitance_threshold) return LOW;
    else return HIGH;
  #endif                                                      // !FEATURE_CAPACITIVE_PADDLE_PINS



  // #ifndef FEATURE_CAPACITIVE_PADDLE_PINS
  //   #ifndef OPTION_INVERT_PADDLE_PIN_LOGIC
  //     #if defined(OPTION_DIRECT_PADDLE_PIN_READS_MEGA)
  //       switch(pin_to_read){
  //         case 2: return(bitRead(PINE,4));break;
  //         case 5: return(bitRead(PINE,3));break;
  //       }
  //     #else //OPTION_DIRECT_PADDLE_READS_MEGA
  //       return digitalRead(pin_to_read);
  //     #endif //OPTION_DIRECT_PADDLE_READS_MEGA
  //   #else 
  //     return !digitalRead(pin_to_read);
  //   #endif
  // #else
  //     if (capactive_paddle_pin_inhibit_pin){ 
  //       if (digitalRead(capactive_paddle_pin_inhibit_pin) == HIGH){
  //         return digitalRead(pin_to_read);
  //       }

  //     }

  //     if (read_capacitive_pin(pin_to_read) > capacitance_threshold) {
  //       return LOW;
  //     } else {
  //       return HIGH;
  //     }
      
  // #endif //FEATURE_CAPACITIVE_PADDLE_PINS  

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

      //send_dit();
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
      //send_dah();
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
          if (LCD_COLUMNS < 9){
            lcd_center_print_timed("PTT Lock",0,2000);
          } else {
            lcd_center_print_timed("PTT Interlock",0,2000);
          }
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

#if defined(OPTION_WINKEY_SEND_BREAKIN_STATUS_BYTE) && defined(FEATURE_WINKEY_EMULATION)
void service_winkey_breakin(){


  if (send_winkey_breakin_byte_flag){
    winkey_port_write(0xc2|winkey_sending|winkey_xoff,0); // 0xc2 - BREAKIN bit set high
    winkey_interrupted = 1;
    send_winkey_breakin_byte_flag = 0;
    #ifdef DEBUG_WINKEY
      debug_serial_port->println("service_winkey_breakin: winkey_interrupted = 1");
    #endif
  }   
   
}
#endif //defined(OPTION_WINKEY_SEND_BREAKIN_STATUS_BYTE) && defined(FEATURE_WINKEY_EMULATION) 

//---------------------------------------------------------------------

void initialize_ethernet_variables(){

  #if defined(FEATURE_ETHERNET)
    for (int x = 0;x < 4;x++){
      configuration.ip[x] = default_ip[x];
      configuration.gateway[x] = default_gateway[x];
      configuration.subnet[x] = default_subnet[x]; 
      for (int y = 0;y < FEATURE_INTERNET_LINK_MAX_LINKS;y++){
        configuration.link_send_ip[x][y] = 0;
        configuration.link_send_enabled[y] = 0;
        configuration.link_send_udp_port[y] = FEATURE_INTERNET_LINK_DEFAULT_RCV_UDP_PORT;
      }
    }  
    configuration.link_receive_udp_port = FEATURE_INTERNET_LINK_DEFAULT_RCV_UDP_PORT;
    configuration.link_receive_enabled = 0;  
  #endif //FEATURE_ETHERNET
}

//-------------------------------------------------------------------------------------------------------
void initialize_ethernet(){

  #if defined(FEATURE_ETHERNET)
    Ethernet.begin(mac, configuration.ip, configuration.gateway, configuration.subnet);
  #endif

}



//-------------------------------------------------------------------------------------------------------

void initialize_udp(){

  #if defined(FEATURE_UDP)
  int udpbegin_result = Udp.begin(udp_listener_port);

    #if defined(DEBUG_UDP)
      if (!udpbegin_result){
        debug_serial_port->println("initialize_udp: Udp.begin error");
      }
    #endif
  #endif //FEATURE_UDP
}


//-------------------------------------------------------------------------------------------------------


void initialize_web_server(){
  #if defined(FEATURE_WEB_SERVER)

  server.begin();

    #ifdef DEBUG_WEB_SERVER
      debug_serial_port->print(F("initialize_web_server: server is at "));
      debug_serial_port->println(Ethernet.localIP());
    #endif 

  #endif //FEATURE_WEB_SERVER  
}


//-------------------------------------------------------------------------------------------------------



#if defined(FEATURE_ETHERNET)
void check_for_network_restart(){

  if (restart_networking){
    initialize_web_server();
    restart_networking = 0;
  }
}
#endif //FEATURE_ETHERNET

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void service_web_server() {


  if ((web_control_tx_key_time > 0) && ((millis()-web_control_tx_key_time) > (WEB_SERVER_CONTROL_TX_KEY_TIME_LIMIT_SECS*1000))){
    tx_and_sidetone_key(0);
    web_control_tx_key_time = 0;
  }

  // Create a client connection
  EthernetClient client = server.available();
  if (client) {

    valid_request = 0;

    while (client.connected()){   
      if (client.available()){
        char c = client.read();
     
        //read char by char HTTP request
        if (web_server_incoming_string.length() < MAX_WEB_REQUEST){
          //store characters to string
          web_server_incoming_string += c;
          #if defined(DEBUG_WEB_SERVER_READS)
            debug_serial_port->print("service_web_server: read: ");
            debug_serial_port->print(c);
          #endif //DEBUG_WEB_SERVER_READS  
        } else {
          // web_server_incoming_string = "";
        }

        //has HTTP request ended?
        if (c == '\n'){ 

          #if defined(DEBUG_WEB_SERVER_READS)
            debug_serial_port->println(web_server_incoming_string); //print to serial monitor for debuging     
          #endif //DEBUG_WEB_SERVER_READS

          if (web_server_incoming_string.startsWith("GET / ")){
            valid_request = 1;
            web_print_page_main_menu(client);
          }

          if (web_server_incoming_string.startsWith("GET /About")){
            valid_request = 1;
            web_print_page_about(client);
          }

          if (web_server_incoming_string.startsWith("GET /KeyerSettings")){
            valid_request = 1;
            // are there form results being posted?
            if (web_server_incoming_string.indexOf("?") > 0){
              web_print_page_keyer_settings_process(client);
            } else {
              web_print_page_keyer_settings(client);
            }
          }

          if (web_server_incoming_string.startsWith("GET /NetworkSettings")){
            valid_request = 1;
            // are there form results being posted?
            if (web_server_incoming_string.indexOf("?ip0=") > 0){
              web_print_page_network_settings_process(client);
            } else {
              web_print_page_network_settings(client);
            }
          }

          #if defined(FEATURE_INTERNET_LINK)
            if (web_server_incoming_string.startsWith("GET /LinkSettings")){
              valid_request = 1;
              // are there form results being posted?
              if (web_server_incoming_string.indexOf("?ip") > 0){
                web_print_page_link_settings_process(client);
              } else {
                web_print_page_link_settings(client);
              }
            }
          #endif //FEATURE_INTERNET_LINK
          if (web_server_incoming_string.startsWith("GET /ctrl")){
            valid_request = 1;
            web_print_page_control(client); 
          }

          #if defined(FEATURE_MEMORIES)
            if (web_server_incoming_string.startsWith("GET /mem")){
              valid_request = 1;
              // are there form results being posted?
              // if (web_server_incoming_string.indexOf("?") > 0){
              //   web_print_page_memories_process(client);
              // } else {
                web_print_page_memories(client);
              // }
            }
          #endif //FEATURE_MEMORIES


          if (!valid_request){
            web_print_page_404(client);                      
          }

          delay(1);
          client.stop();
          web_server_incoming_string = "";  
         }
       }
    }
  }

}
#endif //FEATURE_WEB_SERVER
//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)
void web_print_200OK(EthernetClient client){

  web_client_print(client,F("HTTP/1.1 200 OK\nContent-Type: text/html\n\n"));  

}
#endif //FEATURE_WEB_SERVER
//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)
void web_print_header(EthernetClient client){

  web_print_200OK(client);  
  web_client_println(client,F("<HTML><HEAD><meta name='apple-mobile-web-app-capable' content='yes' /><meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />"));

}
#endif //FEATURE_WEB_SERVER
//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)
void web_print_style_sheet(EthernetClient client){

  web_client_print(client,F("<style>body{margin:60px 0px; padding:0px;text-align:center;font-family:\"Trebuchet MS\", Arial, Helvetica, sans-serif;}h1{text-align: center;font-family:Arial, \"Trebuchet MS\", Helvetica,"));
  web_client_print(client,F("sans-serif;}h2{text-align: center;font-family:\"Trebuchet MS\", Arial, Helvetica, sans-serif;}"));

  // internal hyperlinks
  web_client_print(client,F("a.internal{text-decoration:none;width:75px;height:50px;border-color:black;border-top:2px solid;border-bottom:2px solid;border-right:2px solid;border-left:2px solid;border-radius:10px 10px 10px;"));
  web_client_print(client,F("-o-border-radius:10px 10px 10px;-webkit-border-radius:10px 10px 10px;font-family:\"Trebuchet MS\",Arial, Helvetica, sans-serif;"));
  web_client_print(client,F("-moz-border-radius:10px 10px 10px;background-color:#293F5E;padding:8px;text-align:center;}"));
  web_client_print(client,F("a.internal:link {color:white;} a.internal:visited {color:white;}"));
  web_client_print(client,F(" a.internal:hover {color:white;} a.internal:active {color:white;}"));

  // control screen buttons
  web_client_print(client,F("a.ctrl{text-decoration:none;width:75px;height:50px;border-color:black;border-top:2px solid;border-bottom:2px solid;border-right:2px solid;border-left:2px solid;border-radius:10px 10px 10px;"));
  web_client_print(client,F("-o-border-radius:10px 10px 10px;-webkit-border-radius:10px 10px 10px;font-family:\"Trebuchet MS\",Arial, Helvetica, sans-serif;"));
  web_client_print(client,F("-moz-border-radius:10px 10px 10px;background-color:#293F5E;padding:15px;text-align:center;}"));
  web_client_print(client,F("a.ctrl:link {color:white;} a.ctrl:visited {color:white;}"));
  web_client_print(client,F(" a.ctrl:hover {color:white;} a.ctrl:active {color:white;}"));

  // external hyperlinks
  web_client_print(client,F("a.external{"));
  web_client_print(client,F("font-family:\"Trebuchet MS\",Arial, Helvetica, sans-serif;"));
  web_client_print(client,F("text-align:center;}"));
  web_client_print(client,F("a.external:link {color:blue;} a.external:visited {color:purple;}"));
  web_client_println(client,F(" a.external:hover {color:red;} a.external:active {color:green;}"));

  // ip address text blocks
  web_client_println(client,F(".addr {width: 30px; text-align:center }"));

  // ip port text blocks
  web_client_println(client,F(".ipprt {width: 45px; text-align:center }"));

  web_client_println(client,F(".container {display: flex;}"));

 /*for demo purposes only */
  // web_client_println(client,F(".column {flex: 1; background: #f2f2f2; border: 1px solid #e6e6e6; box-sizing: border-box;}"));
  // web_client_println(client,F(".column-1 {order: 1;} .column-2 {order: 2;} .column-3 {order: 3;} .column-4 {order: 4;} .column-5 {order: 5;}"));

  web_client_println(client,F("</style>"));

}
#endif //FEATURE_WEB_SERVER
//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)
void web_print_home_link(EthernetClient client){

  web_client_println(client,F("<br><a href=\"\x2F\" class=\"internal\">Home</a><br />"));

}
#endif //FEATURE_WEB_SERVER
//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)
void web_print_footer(EthernetClient client){


  web_client_println(client,F("<br></BODY></HTML>"));


}
#endif //FEATURE_WEB_SERVER
//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)
void web_print_title(EthernetClient client){


  web_client_println(client,F("<TITLE>K3NG CW Keyer</TITLE></HEAD><BODY>"));

}
#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)

void web_print_page_network_settings(EthernetClient client){

  web_print_header(client);

  web_print_style_sheet(client);

  web_print_title(client);

  web_client_println(client,F("<H1>Network Settings</H1><hr><br>"));

  // input form
  web_client_print(client,F("<br><br><form>IP: <input type=\"text\" name=\"ip0\" class=\"addr\" value=\""));
  web_client_print(client,configuration.ip[0]);
  web_client_print(client,F("\">.<input type=\"text\" name=\"ip1\" class=\"addr\" value=\""));
  web_client_print(client,configuration.ip[1]);  
  web_client_print(client,F("\">.<input type=\"text\" name=\"ip2\" class=\"addr\" value=\""));
  web_client_print(client,configuration.ip[2]);
  web_client_print(client,F("\">.<input type=\"text\" name=\"ip3\" class=\"addr\" value=\""));
  web_client_print(client,configuration.ip[3]);
  web_client_println(client,"\">");  


  web_client_print(client,F("<br><br>Gateway: <input type=\"text\" name=\"gw0\" class=\"addr\" value=\""));
  web_client_print(client,configuration.gateway[0]);
  web_client_print(client,F("\">.<input type=\"text\" name=\"gw1\" class=\"addr\" value=\""));
  web_client_print(client,configuration.gateway[1]); 
  web_client_print(client,F("\">.<input type=\"text\" name=\"gw2\" class=\"addr\" value=\""));
  web_client_print(client,configuration.gateway[2]);  
  web_client_print(client,F("\">.<input type=\"text\" name=\"gw3\" class=\"addr\" value=\""));
  web_client_print(client,configuration.gateway[3]);
  web_client_println(client,"\">");

  web_client_print(client,F("<br><br>Subnet Mask: <input type=\"text\" name=\"sn0\" class=\"addr\" value=\""));
  web_client_print(client,configuration.subnet[0]);
  web_client_print(client,F("\">.<input type=\"text\" name=\"sn1\" class=\"addr\" value=\""));
  web_client_print(client,configuration.subnet[1]); 
  web_client_print(client,F("\">.<input type=\"text\" name=\"sn2\" class=\"addr\" value=\""));
  web_client_print(client,configuration.subnet[2]);
  web_client_print(client,F("\">.<input type=\"text\" name=\"sn3\" class=\"addr\" value=\""));
  web_client_print(client,configuration.subnet[3]);
  web_client_println(client,"\"><br><br><input type=\"submit\" value=\"Save\"></form>");


  web_print_home_link(client);
  
  web_print_footer(client); 

}


#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER) && defined(FEATURE_INTERNET_LINK)

void web_print_page_link_settings(EthernetClient client){

  web_print_header(client);

  web_print_style_sheet(client);

  web_print_title(client);

  web_client_println(client,F("<H1>Link Settings</H1><hr><br><H2>Link Send Settings</H2><form>"));


  // input form
  for (int x = 0;x < FEATURE_INTERNET_LINK_MAX_LINKS;x++){
    web_client_print(client,"<br><br>Link ");
    web_client_print(client,x+1);
    web_client_print(client,": IP: <input type=\"text\" name=\"ip");
    web_client_print(client,x);
    web_client_print(client,"0\" class=\"addr\" value=\"");
    web_client_print(client,configuration.link_send_ip[0][x]);
    web_client_print(client,"\"");
    web_client_print(client,">.<input type=\"text\" name=\"ip");
    web_client_print(client,x);
    web_client_print(client,"1\" class=\"addr\" value=\"");
    web_client_print(client,configuration.link_send_ip[1][x]);
    web_client_print(client,"\"");  
    web_client_print(client,">.<input type=\"text\" name=\"ip");
    web_client_print(client,x);
    web_client_print(client,"2\" class=\"addr\" value=\"");
    web_client_print(client,configuration.link_send_ip[2][x]);
    web_client_print(client,"\"");  
    web_client_print(client,">.<input type=\"text\" name=\"ip");
    web_client_print(client,x);
    web_client_print(client,"3\" class=\"addr\" value=\"");
    web_client_print(client,configuration.link_send_ip[3][x]);
    web_client_println(client,"\">");  

    web_client_print(client," UDP Port: <input type=\"text\" name=\"sp");
    web_client_print(client,x);
    web_client_print(client,"\" class=\"ipprt\" value=\"");
    web_client_print(client,configuration.link_send_udp_port[x]);
    web_client_print(client,"\">  ");

    // link active/inactive radio buttons
    web_client_print(client,"<input type=\"radio\" name=\"act");
    web_client_print(client,x);
    web_client_print(client,"\" value=\"1\" ");
    if (configuration.link_send_enabled[x]) {web_client_print(client,"checked");}
    web_client_print(client,">Enabled <input type=\"radio\" name=\"act");
    web_client_print(client,x);
    web_client_print(client,"\" value=\"0\" ");
    if (!(configuration.link_send_enabled[x])) {web_client_print(client,"checked");}
    web_client_print(client,">Disabled<br>");

  }

  web_client_print(client,F("<br><br><H2>Link Receive Settings</H2><br><br>UDP Receive Port: <input type=\"text\" name=\"ud\" class=\"ipprt\" value=\""));
  web_client_print(client,configuration.link_receive_udp_port);
  web_client_println(client,"\">");

  web_client_print(client,"<input type=\"radio\" name=\"lr");
  web_client_print(client,"\" value=\"1\" ");
  if (configuration.link_receive_enabled) {web_client_print(client,"checked");}
  web_client_print(client,">Enabled <input type=\"radio\" name=\"lr");
  web_client_print(client,"\" value=\"0\" ");
  if (!(configuration.link_receive_enabled)) {web_client_print(client,"checked");}
  web_client_print(client,">Disabled<br>");

  web_client_println(client,"<br><br><input type=\"submit\" value=\"Save\"></form>");

  web_print_home_link(client);
  
  web_print_footer(client); 

}


#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)

void web_print_page_404(EthernetClient client){

  web_client_println(client,F("HTTP/1.1 404 NOT FOUND"));
  web_client_println(client,F("Content-Type: text/html\n"));            
  web_client_println(client,F("<HTML><HEAD></HEAD><BODY>Sorry, dude.  Page not found."));
  web_print_home_link(client);            
  web_print_footer(client); 

}

#endif //FEATURE_WEB_SERVER
//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)

void web_print_page_about(EthernetClient client){

  web_print_header(client);

  web_client_println(client,F("<meta http-equiv=\"refresh\" content=\"5\"/>"));

  web_print_style_sheet(client);

  web_print_title(client);

  web_client_println(client,F("<H1>About</H1><hr><br>"));
  web_client_println(client,CODE_VERSION);
  web_client_println(client,"<br>");

  void* HP = malloc(4);
  if (HP){
    free (HP);
  }
  unsigned long free = (unsigned long)SP - (unsigned long)HP;

  // web_client_print(client,"Heap = 0x");
  // web_client_println(client,(unsigned long)HP,HEX);
  // web_client_println(client,"<br />");           
  // web_client_print(client,"Stack = 0x");
  // web_client_println(client,(unsigned long)SP,HEX);
  // web_client_println(client,"<br />");           
            
  web_client_print(client,free);
  web_client_println(client,F(" bytes free<br><br>"));


  

  unsigned long seconds = (millis() / 1000L) + ((pow(2,32)/ 1000L) *  millis_rollover);


  int days = seconds / 86400L;
  seconds = seconds - (long(days) * 86400L);
  
  int hours = seconds / 3600L;
  seconds = seconds - (long(hours) * 3600L);
  
  int minutes = seconds / 60L;
  seconds = seconds - (minutes * 60);

  web_client_print(client,days);
  web_client_print(client,":");
  if (hours < 10) {web_client_print(client,"0");}
  web_client_print(client,hours);
  web_client_print(client,":");
  if (minutes < 10) {web_client_print(client,"0");}
  web_client_print(client,minutes);
  web_client_print(client,":");
  if (seconds < 10) {web_client_print(client,"0");}
  web_client_print(client,seconds);    
  web_client_println(client,F(" dd:hh:mm:ss uptime<br>"));

  web_client_println(client,F("<br><br><br>Anthony Good, K3NG<br>anthony.good@gmail.com<br><a href=\"http://blog.radioartisan.com/\"\" class=\"external\">Radio Artisan</a><br><br>"));

  web_print_home_link(client);

  web_print_footer(client);
} 

#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)
void parse_get(String str){

  String workstring = "";
  String parameter = "";
  String value = "";

  for(int x = 0;x < MAX_PARSE_RESULTS;x++){
    parse_get_results[x].parameter = "";
    parse_get_results[x].value_string = "";
    parse_get_results[x].value_long = 0;
  }
  parse_get_results_index = 0;

  #if defined(DEBUG_WEB_PARSE_GET)
    debug_serial_port->print("parse_get: raw workstring: ");
    Serial.println(str);
  #endif  

  workstring = str.substring(str.indexOf("?")+1);

  #if defined(DEBUG_WEB_PARSE_GET)
    debug_serial_port->print("parse_get: workstring: ");
    Serial.println(workstring);
  #endif  

  while(workstring.indexOf("=") > 0){
    parameter = workstring.substring(0,workstring.indexOf("="));
    if(workstring.indexOf("&") > 0){
      value = workstring.substring(workstring.indexOf("=")+1,workstring.indexOf("&"));
      workstring = workstring.substring(workstring.indexOf("&")+1);
    } else {
      value = workstring.substring(workstring.indexOf("=")+1,workstring.indexOf(" "));
      // value = workstring.substring(workstring.indexOf("=")+1);
      workstring = "";
    }
    #if defined(DEBUG_WEB_PARSE_GET)
      debug_serial_port->print("parse_get: parameter: ");
      debug_serial_port->print(parameter);
      debug_serial_port->print(" value: ");
      debug_serial_port->println(value);   
    #endif //DEBUG_WEB_PARSE_GET

    if (parse_get_results_index < MAX_PARSE_RESULTS){
      parse_get_results[parse_get_results_index].parameter = parameter;
      parse_get_results[parse_get_results_index].value_string = value;
      parse_get_results[parse_get_results_index].value_long = value.toInt();
      
      // Serial.print(parse_get_results_index);
      // Serial.print(":");      
      // Serial.print(parse_get_results[parse_get_results_index].parameter);
      // Serial.print(":");
      // Serial.print(parse_get_results[parse_get_results_index].value_string);
      // Serial.print(":");    
      // Serial.print(parse_get_results[parse_get_results_index].value_long);
      // Serial.println("$");

      parse_get_results_index++;
    }
  }


}
#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)

void web_print_page_main_menu(EthernetClient client){


  web_print_header(client);

  web_print_style_sheet(client);

  web_print_title(client);

  web_client_println(client,F("<H1>K3NG CW Keyer</H1><hr><br><br><a href=\"ctrl\"\" class=\"internal\">Control</a><br><br>"));
  #if defined(FEATURE_MEMORIES)
    web_client_println(client,F("<a href=\"mem\"\" class=\"internal\">Memories</a><br><br>"));
  #endif //FEATURE_MEMORIES
  web_client_println(client,F("<a href=\"KeyerSettings\"\" class=\"internal\">Keyer Settings</a><br><br>")); 
  #if defined(FEATURE_INTERNET_LINK)
    web_client_println(client,F("<a href=\"LinkSettings\"\" class=\"internal\">Link Settings</a><br><br>"));
  #endif //FEATURE_INTERNET_LINK
  web_client_println(client,F("<a href=\"NetworkSettings\"\" class=\"internal\">Network Settings</a><br><br><a href=\"About\"\" class=\"internal\">About</a><br>"));        

  web_print_footer(client); 

}

#endif //FEATURE_WEB_SERVER          


//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)

void web_print_control_radio(EthernetClient client,const char *name,int value,uint8_t checked,const char *caption){

  web_client_print(client,F("<label><input type=\"radio\" name=\""));
  web_client_print(client,name);
  web_client_print(client,F("\" value=\""));
  web_client_print(client,value);
  web_client_print(client,"\"");
  if (checked) {web_client_print(client,F(" checked"));}
  web_client_print(client,">");
  web_client_print(client,caption);
  web_client_print(client,F("</label>"));

}
#endif //FEATURE_WEB_SERVER 

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)

void web_print_control_checkbox(EthernetClient client,const char *name,uint8_t checked,const char *caption){

    web_client_print(client,F("<label><input type=\"checkbox\" id=\"cbox"));
    web_client_print(client,name);
    web_client_print(client,F("\" value=\""));
    web_client_print(client,name);
    web_client_print(client,F("\""));
    if (checked) {web_client_print(client,F(" checked"));}
    web_client_print(client,F(">"));
    web_client_print(client,caption);
    web_client_print(client,F("</label>"));

}
#endif //FEATURE_WEB_SERVER 

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)

void web_print_control_textbox(EthernetClient client,const char *name,const char *textbox_class,int textbox_value,const char *front_caption,const char *back_caption){

  web_client_print(client,F("<label>"));
  web_client_print(client,front_caption);
  web_client_print(client,F("<input type=\"text\" name=\""));
  web_client_print(client,name);
  web_client_print(client,F("\" class=\""));
  web_client_print(client,textbox_class);
  web_client_print(client,F("\" value=\""));
  web_client_print(client,textbox_value);
  web_client_print(client,F("\">"));
  web_client_print(client,back_caption);
  web_client_print(client,F("</label>"));

}
#endif //FEATURE_WEB_SERVER 

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)

void web_print_control_textbox(EthernetClient client,const char *name,const char *textbox_class,float textbox_value,const char *front_caption,const char *back_caption){

  web_client_print(client,F("<label>"));
  web_client_print(client,front_caption);
  web_client_print(client,F("<input type=\"text\" name=\""));
  web_client_print(client,name);
  web_client_print(client,F("\" class=\""));
  web_client_print(client,textbox_class);
  web_client_print(client,F("\" value=\""));
  web_client_print(client,textbox_value);
  web_client_print(client,F("\">"));
  web_client_print(client,back_caption);
  web_client_print(client,F("</label>"));

}
#endif //FEATURE_WEB_SERVER 

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)

void web_print_page_keyer_settings(EthernetClient client){

  uint8_t pin_read = 0;

  web_print_header(client);

  web_print_style_sheet(client);

  web_print_title(client);

  web_client_println(client,F("<H1>Keyer Settings</H1><hr><br><form>"));

  web_print_control_radio(client,"md",IAMBIC_A,(configuration.keyer_mode == IAMBIC_A)?1:0,"Iambic A ");
  web_print_control_radio(client,"md",IAMBIC_B,(configuration.keyer_mode == IAMBIC_B)?1:0,"Iambic B ");
  web_print_control_radio(client,"md",BUG,(configuration.keyer_mode == BUG)?1:0,"Bug ");
  web_print_control_radio(client,"md",STRAIGHT,(configuration.keyer_mode == STRAIGHT)?1:0,"Straight Key");
  web_print_control_radio(client,"md",ULTIMATIC,(configuration.keyer_mode == ULTIMATIC)?1:0,"Ultimatic");
  web_print_control_radio(client,"md",SINGLE_PADDLE,(configuration.keyer_mode == SINGLE_PADDLE)?1:0,"Single Paddle");
  web_client_println(client,"<br>");  

    
  #ifdef FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING
    web_print_control_checkbox(client,"cs",(configuration.cmos_super_keyer_iambic_b_timing_on)?1:0," CMOS Superkeyer Iambic B Timing ");
    web_print_control_textbox(client,"cp","addr",configuration.cmos_super_keyer_iambic_b_timing_percent,"","%");
    web_client_println(client,"<br>");
  #endif
  
  //web_print_control_checkbox(client,"di",(!configuration.dit_buffer_off)?1:0," Dit Buffer ");  // couldn't get checkboxes working correctly 2016-12-11

  web_client_print(client,"Dit Buffer"); 
  web_print_control_radio(client,"di",0,(configuration.dit_buffer_off)?0:1,"On ");
  web_print_control_radio(client,"di",1,(configuration.dit_buffer_off)?1:0,"Off   ");
  web_client_println(client,"<br>");

  // web_print_control_checkbox(client,"da",(!configuration.dah_buffer_off)?1:0," Dah Buffer<br>");

  web_client_print(client,"Dah Buffer"); 
  web_print_control_radio(client,"da",0,(configuration.dah_buffer_off)?0:1,"On ");
  web_print_control_radio(client,"da",1,(configuration.dah_buffer_off)?1:0,"Off");
  web_client_println(client,"<br>");

  web_print_control_radio(client,"sm",SPEED_NORMAL,(speed_mode == SPEED_NORMAL)?1:0,"Normal Speed Mode ");

  web_print_control_textbox(client,"wp","addr",(int)configuration.wpm,""," WPM ");

  #if defined(FEATURE_FARNSWORTH)
    web_print_control_textbox(client,"fw","addr",(int)configuration.wpm_farnsworth,""," Farnsworth WPM");
  #endif //FEATURE_FARNSWORTH

  web_client_println(client,"<br>");

  web_print_control_radio(client,"sm",SPEED_QRSS,(speed_mode == SPEED_QRSS)?1:0,"QRSS Mode   Dit Length ");
  web_client_print(client,F("<label><input type=\"text\" name=\"qd\" class=\"addr\" value=\""));
  web_client_println(client,qrss_dit_length);
  web_client_print(client,F("\"> s</label>"));
  web_client_println(client,F("<br>"));

  web_client_print(client,F("Sidetone: "));
  web_print_control_radio(client,"st",SIDETONE_ON,(configuration.sidetone_mode == SIDETONE_ON)?1:0,"On ");
  web_print_control_radio(client,"st",SIDETONE_OFF,(configuration.sidetone_mode == SIDETONE_OFF)?1:0,"Off ");
  web_print_control_radio(client,"st",SIDETONE_PADDLE_ONLY,(configuration.sidetone_mode == SIDETONE_PADDLE_ONLY)?1:0,"Paddle Only ");
  web_print_control_textbox(client,"hz","addr",(int)configuration.hz_sidetone,""," hz");
  web_client_println(client,F("<br>"));

  web_print_control_textbox(client,"dd","addr",float(configuration.dah_to_dit_ratio/100.0),""," Dah/Dit Ratio");
  web_client_println(client,F("<br>"));

  web_print_control_textbox(client,"wt","addr",(int)configuration.weighting,"Weighting ","");
  web_client_println(client,F("<br>"));

  #ifdef FEATURE_COMMAND_LINE_INTERFACE
    web_print_control_textbox(client,"sn","addr",(int)serial_number,"Serial # ","");
    web_client_println(client,F("<br>"));;
  #endif 

  #if defined(FEATURE_POTENTIOMETER)
    //web_print_control_textbox(client,"po","addr",(int)pot_value_wpm(),"Potentiometer "," WPM ");
    //web_print_control_checkbox(client,"pa",(configuration.pot_activated)?1:0," Active");
    web_client_print(client,"Potentiometer ");
    web_print_control_radio(client,"pa",1,(configuration.pot_activated)?1:0,"Active ");
    web_print_control_radio(client,"pa",0,(configuration.pot_activated)?0:1,"Inactive");    
    web_client_println(client,F("<br>"));
  #endif

  #if defined(FEATURE_AUTOSPACE)
    //web_print_control_checkbox(client,"as",(configuration.autospace_active)?1:0," Autospace<br>");
    web_client_print(client,"Autospace"); 
    web_print_control_radio(client,"as",1,(configuration.autospace_active)?1:0,"On ");
    web_print_control_radio(client,"as",0,(configuration.autospace_active)?0:1,"Off");
    web_client_println(client,"<br>");    
  #endif //FEATURE_AUTOSPACE

  web_print_control_textbox(client,"ws","addr",(int)configuration.length_wordspace,"Wordspace ","");
  web_client_println(client,F("<br>"));

  web_print_control_textbox(client,"tx","addr",(int)configuration.current_tx,"TX ","");
  web_client_println(client,F("<br>"));

  #if defined(FEATURE_QLF)
    //web_print_control_checkbox(client,"ql",(qlf_active)?1:0," QLF<br>");

    web_client_print(client,"QLF"); 
    web_print_control_radio(client,"ql",1,(qlf_active)?1:0,"On ");
    web_print_control_radio(client,"ql",0,(qlf_active)?0:1,"Off");
    web_client_println(client,"<br>");

  #endif //FEATURE_QLF

  web_client_println(client,F("<br><br><input type=\"submit\" value=\"Save\"></form>"));

  web_print_home_link(client);

  web_print_footer(client);

}
#endif //FEATURE_WEB_SERVER 
             
//-------------------------------------------------------------------------------------------------------



#if defined(FEATURE_WEB_SERVER)

void web_print_page_keyer_settings_process(EthernetClient client){


  uint8_t invalid_data = 0;

  unsigned int ud = 0;

  uint8_t temp_keyer_mode = 0;
  uint8_t temp_dit_buffer_off = 0;
  uint8_t temp_dah_buffer_off = 0;  
  uint8_t temp_speed_mode = 0;
  unsigned int temp_wpm = 0;
  unsigned int temp_qrss_dit_length = 0;
  uint8_t temp_sidetone_mode = 0;
  unsigned int temp_sidetone_hz = 0;
  String temp_string_dit_dah_ratio;
  uint8_t temp_weight = 0;
  unsigned int temp_serial = 0;
  uint8_t temp_wordspace = 0;
  uint8_t temp_tx = 0;  

  #if defined(FEATURE_QLF)
    uint8_t temp_qlf = 0;
  #endif //FEATURE_QLF

  #if defined(FEATURE_POTENTIOMETER)
    uint8_t temp_pot_activated = 0;
  #endif //FEATURE_POTENTIOMETER
    
  #if defined(FEATURE_AUTOSPACE)
    uint8_t temp_autospace_active = 0;
  #endif //FEATURE_AUTOSPACE

  #if defined(FEATURE_FARNSWORTH)
    unsigned int temp_farnsworth = 0;
  #endif //FEATURE_FARNSWORTH

  parse_get(web_server_incoming_string);

  if (parse_get_results_index){



    for (int x = 0; x < parse_get_results_index; x++){ 
      if (parse_get_results[x].parameter == "md"){temp_keyer_mode = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "di"){temp_dit_buffer_off = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "da"){temp_dah_buffer_off = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "sm"){temp_speed_mode = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "wp"){temp_wpm = parse_get_results[x].value_long;}
      #if defined(FEATURE_FARNSWORTH)
        if (parse_get_results[x].parameter == "fw"){temp_farnsworth = parse_get_results[x].value_long;}
      #endif //FEATURE_FARNSWORTH
      if (parse_get_results[x].parameter == "qd"){temp_qrss_dit_length = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "st"){temp_sidetone_mode = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "hz"){temp_sidetone_hz = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "dd"){temp_string_dit_dah_ratio = parse_get_results[x].value_string;}
      if (parse_get_results[x].parameter == "wt"){temp_weight = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "sn"){temp_serial = parse_get_results[x].value_long;}
      // po - nothing to do for potentiometer value
      #if defined(FEATURE_POTENTIOMETER)
        if (parse_get_results[x].parameter == "pa"){temp_pot_activated = parse_get_results[x].value_long;}
      #endif //FEATURE_POTENTIOMETER
      #if defined(FEATURE_AUTOSPACE)
        if (parse_get_results[x].parameter == "as"){temp_autospace_active = parse_get_results[x].value_long;}
      #endif //FEATURE_AUTOSPACE        
      if (parse_get_results[x].parameter == "ws"){temp_wordspace = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "tx"){temp_tx = parse_get_results[x].value_long;}
      #if defined(FEATURE_QLF)
        if (parse_get_results[x].parameter == "ql"){temp_qlf = parse_get_results[x].value_long;}
      #endif //FEATURE_QLF      


    }
    

    // data validation
    

    // TODO !  data validation


    if (invalid_data){

      web_print_header(client);
      web_print_meta_refresh(client,configuration.ip[0],configuration.ip[1],configuration.ip[2],configuration.ip[3],2);                                                   
      web_client_println(client,F("\/KeyerSettings'\" />"));      
      web_print_style_sheet(client);
      web_print_title(client);
      web_client_println(client,F("<br>Bad data!<br>"));
      web_print_home_link(client);
      web_print_footer(client);

    } else { 

    // assign to variables
           
      configuration.keyer_mode = temp_keyer_mode;
      configuration.dit_buffer_off = temp_dit_buffer_off;
      configuration.dah_buffer_off = temp_dah_buffer_off;
      speed_mode = temp_speed_mode;
      configuration.wpm = temp_wpm;
      qrss_dit_length = temp_qrss_dit_length;
      configuration.sidetone_mode = temp_sidetone_mode;
      configuration.hz_sidetone = temp_sidetone_hz;
      temp_string_dit_dah_ratio.replace(".","");
      configuration.dah_to_dit_ratio =  temp_string_dit_dah_ratio.toInt();
      configuration.weighting = temp_weight;
      serial_number = temp_serial;
      configuration.length_wordspace = temp_wordspace;
      configuration.current_tx = temp_tx;
      #if defined(FEATURE_QLF)
        qlf_active = temp_qlf;
      #endif //FEATURE_QLF  
      #if defined(FEATURE_POTENTIOMETER)
        configuration.pot_activated = temp_pot_activated;
      #endif //FEATURE_POTENTIOMETER  
      #if defined(FEATURE_AUTOSPACE)
        configuration.autospace_active = temp_autospace_active;
      #endif //FEATURE_AUTOSPACE  
      #if defined(FEATURE_FARNSWORTH)
        configuration.wpm_farnsworth = temp_farnsworth;
      #endif //FEATURE_FARNSWORTH

      web_print_header(client);
      web_print_meta_refresh(client,configuration.ip[0],configuration.ip[1],configuration.ip[2],configuration.ip[3],2);                                                   
      web_client_println(client,F("\/KeyerSettings'\" />"));
      web_print_style_sheet(client);
      web_print_title(client);
      web_client_println(client,F("<br>Configuration saved<br><br>"));
      web_print_home_link(client);
      web_print_footer(client);
      config_dirty = 1;
    }
  }
}
#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------


#if defined(FEATURE_WEB_SERVER) && defined(FEATURE_MEMORIES)

void web_print_page_memories(EthernetClient client){



  int memory_number_to_send = 0;
  int last_memory_location;

  #if defined(OPTION_PROSIGN_SUPPORT)
    byte eeprom_temp = 0;
    static char * prosign_temp = 0;
  #endif




  web_print_header(client);

  web_print_style_sheet(client);

  web_print_title(client);

  web_client_println(client,F("<H1>Memories</H1><hr><br>"));

  web_client_print(client,F("<br><br>"));

  //if (web_server_incoming_string.length() > 14){web_server_incoming_string.remove(14);}

  if ((web_server_incoming_string.indexOf("?m") > 0) && (web_server_incoming_string.length() > (web_server_incoming_string.indexOf("?m")+2))) {
    memory_number_to_send = ((web_server_incoming_string.charAt(web_server_incoming_string.indexOf("?m")+2)-48)*10) + (web_server_incoming_string.charAt(web_server_incoming_string.indexOf("?m")+3)-48);


// web_client_print(client,web_server_incoming_string);
// web_client_print(client,F("<br><br>"));

// web_client_print(client,F("mem number: "));
// web_client_print(client,memory_number_to_send);
// web_client_print(client,F("<br><br>"));

// web_client_print(client,web_server_incoming_string.charAt(web_server_incoming_string.indexOf("?m")+1));
// web_client_print(client,web_server_incoming_string.charAt(web_server_incoming_string.indexOf("?m")+2));
// web_client_print(client,F("<br><br>"));

    add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
    add_to_send_buffer(memory_number_to_send-1);
  }


  for(int i = 0;i < number_of_memories;i++){
    web_client_print(client,F("<a href=\"/mem?m"));
    if(i < 9){web_client_print(client,"0");}
    web_client_print(client,i+1);
    web_client_print(client,"\" class=\"ctrl\">");
    web_client_print(client,i+1);
    

  
    last_memory_location = memory_end(i) + 1;

    if (EEPROM.read(memory_start(i)) == 255) {
      // web_client_print(client,F("{empty}"));
      web_client_print(client,F("       "));
    } else {
      web_client_print(client,") ");
      for (int y = (memory_start(i)); (y < last_memory_location); y++) {
        if (EEPROM.read(y) < 255) {
          #if defined(OPTION_PROSIGN_SUPPORT)
            eeprom_temp = EEPROM.read(y);
            if ((eeprom_temp > PROSIGN_START) && (eeprom_temp < PROSIGN_END)){
              prosign_temp = convert_prosign(eeprom_temp);
              web_client_write(client,prosign_temp[0]);
              web_client_write(client,prosign_temp[1]);
            } else {
              web_client_write(client,eeprom_temp);
            }
          #else         
            web_client_write(client,EEPROM.read(y));
          #endif //OPTION_PROSIGN_SUPPORT
        } else {
          y = last_memory_location;
        }
      }
    }


    web_client_print(client,"</a>");
    // web_client_print(client,"<br><br><br>");
    if (number_of_memories > 4){
      if (((i+1) % 4) == 0){web_client_print(client,"<br><br><br>");}
    }
  }

  web_client_print(client,F("<br>")); 

  web_print_home_link(client);

  web_print_footer(client);


  

}
#endif //FEATURE_WEB_SERVER && FEATURE_MEMORIES


//-------------------------------------------------------------------------------------------------------


#if defined(FEATURE_WEB_SERVER)

void web_print_page_control(EthernetClient client){

  /*

    /ctrl - regular page

    /ctrlnd - no display

    /ctrlnd?st<TEXTTOSEND>/

    http://192.168.1.178/ctrlnd?sttest/


  */

  uint8_t pin_read = 0;

  #if defined(FEATURE_MEMORIES)
    uint8_t memory_number_to_send = 0;
  #endif //FEATURE_MEMORIES

  int search_string_start_position = 0;

  String url_sub_string; 

  if ((web_server_incoming_string.indexOf("ctrl?") > 0) || (web_server_incoming_string.indexOf("ctrlnd?") > 0)){
    url_sub_string = web_server_incoming_string;
    if (url_sub_string.length() > 14){url_sub_string.remove(14);}
    if (url_sub_string.indexOf("?ky") > 0){
      sending_mode = AUTOMATIC_SENDING;
      web_control_tx_key_time = millis();
      tx_and_sidetone_key(1);
    }
    if (url_sub_string.indexOf("?uk") > 0){
      sending_mode = AUTOMATIC_SENDING;
      tx_and_sidetone_key(0);
      web_control_tx_key_time = 0;
    }
    if (url_sub_string.indexOf("?wn") > 0){
      speed_change(-2);
    }
    if (url_sub_string.indexOf("?wp") > 0){
      speed_change(2);
    }
    #if defined(FEATURE_MEMORIES)
      if ((web_server_incoming_string.indexOf("?m") > 0) & (web_server_incoming_string.length() > (web_server_incoming_string.indexOf("?m")+2))) {
        memory_number_to_send = ((web_server_incoming_string.charAt(web_server_incoming_string.indexOf("m")+1)-48)*10) + (web_server_incoming_string.charAt(web_server_incoming_string.indexOf("m")+2)-48);
        add_to_send_buffer(SERIAL_SEND_BUFFER_MEMORY_NUMBER);
        add_to_send_buffer(memory_number_to_send-1);
      }
    #endif //FEATURE_MEMORIES
    if (url_sub_string.indexOf("?st") > 0){
      for (int x = (web_server_incoming_string.indexOf("st")+2);x < web_server_incoming_string.length();x++){
        if (web_server_incoming_string.charAt(x) == '/'){
          x = web_server_incoming_string.length();      
        } else {
          if (web_server_incoming_string.charAt(x) == '%'){  // do we have a http hex code?
            add_to_send_buffer((((uint8_t)web_server_incoming_string.charAt(x+1)-48)<<4)+((uint8_t)web_server_incoming_string.charAt(x+2)-48));
            x = x + 2;
          } else {
            add_to_send_buffer(uppercase(web_server_incoming_string.charAt(x)));
          }
        }
      }
    }
  }

  

  if (web_server_incoming_string.indexOf("nd") > 0){ // no display option

    web_print_200OK(client);

  } else {

    web_print_header(client);

    web_print_style_sheet(client);

    web_print_title(client);

    web_client_println(client,F("<H1>Control</H1><hr><br>"));


// web_client_print(client,"web_server_incoming_string: ");
// web_client_print(client,web_server_incoming_string);
// web_client_print(client,"url_sub_string: ");
// web_client_print(client,url_sub_string);
// web_client_println(client,F("<br><br>"));

    #if defined(FEATURE_MEMORIES)
    web_client_print(client,F("<br><br>"));
    for(int i = 0;i < number_of_memories;i++){
      web_client_print(client,F("<a href=\"/ctrl?m"));
      if(i < 9){web_client_print(client,"0");}
      web_client_print(client,i+1);
      web_client_print(client,"\" class=\"ctrl\">");
      web_client_print(client,i+1);
      web_client_print(client,"</a>");
      if (number_of_memories > 4){
        if (((i+1) % 4) == 0){web_client_print(client,"<br><br><br>");}
      }
    }

    web_client_print(client,F("<br>"));

    #endif //FEATURE_MEMORIES
    
    web_client_println(client,F("<br><a href=\"/ctrl?wn\" class=\"ctrl\">WPM -2</a><a href=\"/ctrl?wp\" class=\"ctrl\">WPM +2</a><br><br><br>"));  

    web_client_println(client,F("<br><a href=\"/ctrl?ky\" class=\"ctrl\">Key</a><a href=\"/ctrl?uk\" class=\"ctrl\">Unkey</a><br><br><br>"));  

    web_print_home_link(client);

    web_print_footer(client);

  }

  

}
#endif //FEATURE_WEB_SERVER         


//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_println(EthernetClient client,const __FlashStringHelper *str){

  web_client_print(client,str);
  client.println();

}

#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_print(EthernetClient client,const __FlashStringHelper *str){

  char c;
  if(!str) return;
  char charstring[255] = "";
  int charstringindex = 0;
  
  /* since str is a const we can't increment it, so do this instead */
  char *p = (char *)str;
  
  /* keep going until we find the null */
  while((c = pgm_read_byte(p++))){
    if (charstringindex < 254){
      charstring[charstringindex] = c;
      charstringindex++;
    }

  }
  charstring[charstringindex] = 0;
  client.print(charstring);

}

#endif //FEATURE_WEB_SERVER


//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_print(EthernetClient client,String str){

  client.print(str);

}

#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_print(EthernetClient client,const char *str){

  client.print(str);

}

#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_println(EthernetClient client,const char *str){

  client.println(str);

}

#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_print(EthernetClient client,int i){

  client.print(i);

}
#endif //FEATURE_WEB_SERVER



//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_print(EthernetClient client,float f){

  client.print(f);

}
#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_print(EthernetClient client,unsigned long i){

  client.print(i);

}
#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_print(EthernetClient client,unsigned int i){

  client.print(i);

}
#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_println(EthernetClient client,unsigned long i){

  client.println(i);

}
#endif //FEATURE_WEB_SERVER
//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_println(EthernetClient client,unsigned long i,int something){

  client.println(i,something);

}
#endif //FEATURE_WEB_SERVER
//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_WEB_SERVER)
void web_client_write(EthernetClient client,uint8_t i){

  client.write(i);

}
#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)

void web_print_page_link_settings_process(EthernetClient client){

  uint8_t parsed_link_ip[4][FEATURE_INTERNET_LINK_MAX_LINKS];
  uint8_t parsed_link_enabled[FEATURE_INTERNET_LINK_MAX_LINKS];
  int parsed_link_send_udp_port[FEATURE_INTERNET_LINK_MAX_LINKS];
  int parsed_link_receive_udp_port = 0;
  uint8_t parsed_link_receive_enabled = 0;


  uint8_t invalid_data = 0;

  unsigned int ud = 0;

  parse_get(web_server_incoming_string);
  if (parse_get_results_index){

    for (int x = 0; x < parse_get_results_index; x++){   // TODO - rewrite this to scale...
      if (parse_get_results[x].parameter == "ip00"){parsed_link_ip[0][0] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip01"){parsed_link_ip[1][0] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip02"){parsed_link_ip[2][0] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip03"){parsed_link_ip[3][0] = parse_get_results[x].value_long;}

      if (parse_get_results[x].parameter == "ip10"){parsed_link_ip[0][1] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip11"){parsed_link_ip[1][1] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip12"){parsed_link_ip[2][1] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip13"){parsed_link_ip[3][1] = parse_get_results[x].value_long;}

      if (parse_get_results[x].parameter == "ip20"){parsed_link_ip[0][2] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip21"){parsed_link_ip[1][2] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip22"){parsed_link_ip[2][2] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip23"){parsed_link_ip[3][2] = parse_get_results[x].value_long;}      

      if (parse_get_results[x].parameter == "act0"){parsed_link_enabled[0] = parse_get_results[x].value_long;}  
      if (parse_get_results[x].parameter == "act1"){parsed_link_enabled[1] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "act2"){parsed_link_enabled[2] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "act3"){parsed_link_enabled[3] = parse_get_results[x].value_long;}
          
      if (parse_get_results[x].parameter == "sp0"){parsed_link_send_udp_port[0] = parse_get_results[x].value_long;}  
      if (parse_get_results[x].parameter == "sp1"){parsed_link_send_udp_port[1] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "sp2"){parsed_link_send_udp_port[2] = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "sp3"){parsed_link_send_udp_port[3] = parse_get_results[x].value_long;}

      if (parse_get_results[x].parameter == "ud"){parsed_link_receive_udp_port = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "lr"){parsed_link_receive_enabled = parse_get_results[x].value_long;}

    }
    

    // data validation

    for (int x = 0;x < FEATURE_INTERNET_LINK_MAX_LINKS;x++){
      if (parsed_link_enabled[x]){
        for (int y = 0;y < 4;y++){
          if ((parsed_link_ip[y][x] < 0) || (parsed_link_ip[y][x] > 255)){
            invalid_data = 1;
          }
        }
        if ((parsed_link_ip[3][x] == 0) || (parsed_link_ip[3][x] == 255) || (parsed_link_ip[0][x] == 0) || (parsed_link_ip[0][x] == 255)){
          invalid_data = 1;
        }
        if ((parsed_link_send_udp_port[x] < 1) || (parsed_link_send_udp_port[x] > 65535)){
          invalid_data = 1;
        }
      }
    }
    

    if (invalid_data){

      web_print_header(client);
      web_print_meta_refresh(client,configuration.ip[0],configuration.ip[1],configuration.ip[2],configuration.ip[3],2);                                                   
      web_client_println(client,F("\/LinkSettings'\" />"));      
      web_print_style_sheet(client);
      web_print_title(client);
      web_client_println(client,F("<br>Bad data!<br>"));
      web_print_home_link(client);
      web_print_footer(client);

    } else { 

      for (int x = 0;x < FEATURE_INTERNET_LINK_MAX_LINKS;x++){

        configuration.link_send_ip[0][x] = parsed_link_ip[0][x];
        configuration.link_send_ip[1][x] = parsed_link_ip[1][x];
        configuration.link_send_ip[2][x] = parsed_link_ip[2][x];
        configuration.link_send_ip[3][x] = parsed_link_ip[3][x];

        configuration.link_send_udp_port[x] = parsed_link_send_udp_port[x];

        configuration.link_send_enabled[x] = parsed_link_enabled[x];
      }
           
      configuration.link_receive_udp_port = parsed_link_receive_udp_port;
      configuration.link_receive_enabled = parsed_link_receive_enabled;
           

      web_print_header(client);
      web_print_meta_refresh(client,configuration.ip[0],configuration.ip[1],configuration.ip[2],configuration.ip[3],5);                                                   
      web_client_println(client,F("\/LinkSettings'\" />"));
      web_print_style_sheet(client);
      web_print_title(client);
      web_client_println(client,F("<br>Configuration saved<br><br>"));
      web_print_home_link(client);
      web_print_footer(client);
      config_dirty = 1;
    }
  }
}
#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)

void web_print_page_network_settings_process(EthernetClient client){

  uint8_t ip0 = 0;
  uint8_t ip1 = 0;
  uint8_t ip2 = 0;
  uint8_t ip3 = 0;
  uint8_t gw0 = 0;
  uint8_t gw1 = 0;
  uint8_t gw2 = 0;
  uint8_t gw3 = 0;              
  uint8_t sn0 = 0;
  uint8_t sn1 = 0;
  uint8_t sn2 = 0;
  uint8_t sn3 = 0;

  uint8_t invalid_data = 0;

  unsigned int ud = 0;

  parse_get(web_server_incoming_string);
  if (parse_get_results_index){

    for (int x = 0; x < parse_get_results_index; x++){
      if (parse_get_results[x].parameter == "ip0"){ip0 = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip1"){ip1 = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip2"){ip2 = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "ip3"){ip3 = parse_get_results[x].value_long;}

      if (parse_get_results[x].parameter == "gw0"){gw0 = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "gw1"){gw1 = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "gw2"){gw2 = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "gw3"){gw3 = parse_get_results[x].value_long;}

      if (parse_get_results[x].parameter == "sn0"){sn0 = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "sn1"){sn1 = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "sn2"){sn2 = parse_get_results[x].value_long;}
      if (parse_get_results[x].parameter == "sn3"){sn3 = parse_get_results[x].value_long;} 

                                 
    }

    //invalid_data = 1;


    // data validation

    if ((ip0 == 0) || (ip3 == 255) || (ip3 == 0)) {invalid_data = 1;}
    if (((ip0 & sn0) != (gw0 & sn0)) || ((ip1 & sn1) != (gw1 & sn1)) || ((ip2 & sn2) != (gw2 & sn2)) || ((ip3 & sn3) != (gw3 & sn3))) {invalid_data = 1;}
    if ((sn0 == 0) || (sn1 > sn0) || (sn2 > sn1) || (sn3 > sn2) || (sn3 > 252)) {invalid_data = 1;}

    if (invalid_data){

      web_print_header(client);
      web_print_style_sheet(client);
      web_print_title(client);
      web_client_println(client,F("<br>Bad data!<br>"));
      web_print_home_link(client);
      web_print_footer(client);

    } else {

      configuration.ip[0] = ip0;
      configuration.ip[1] = ip1;
      configuration.ip[2] = ip2;
      configuration.ip[3] = ip3; 

      configuration.gateway[0] = gw0;
      configuration.gateway[1] = gw1;
      configuration.gateway[2] = gw2;
      configuration.gateway[3] = gw3; 

      configuration.subnet[0] = sn0;
      configuration.subnet[1] = sn1;
      configuration.subnet[2] = sn2;
      configuration.subnet[3] = sn3;  
           

      web_print_header(client);
      web_print_meta_refresh(client,ip0,ip1,ip2,ip3,5);
      web_client_println(client,F("'\" />"));
      web_print_style_sheet(client);
      web_print_title(client);
      web_client_println(client,F("<br>Configuration saved<br>Restarting networking<br><br>You will be redirected to new address in 5 seconds...<br>"));
      web_print_home_link(client);
      web_print_footer(client);
      restart_networking = 1;
      config_dirty = 1;
    }
  }
}
#endif //FEATURE_WEB_SERVER

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_WEB_SERVER)

void web_print_meta_refresh(EthernetClient client,uint8_t ip0,uint8_t ip1,uint8_t ip2,uint8_t ip3,uint8_t refresh_time){

  web_client_print(client,F("<meta http-equiv=\"refresh\" content=\""));
  web_client_print(client,refresh_time);
  web_client_print(client,F("; URL='http://"));
  web_client_print(client,ip0);
  web_client_print(client,".");
  web_client_print(client,ip1);
  web_client_print(client,".");
  web_client_print(client,ip2);
  web_client_print(client,".");  
  web_client_print(client,ip3);                                                    

}
#endif //FEATURE_WEB_SERVER
//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_INTERNET_LINK)
void link_key(uint8_t link_key_state){

  static unsigned long last_link_key_action_time = 0;
  static uint8_t current_link_key_state = 0;
  static uint8_t buffered_key_down = 0;
  uint8_t bytes_to_send[8];
  uint8_t bytes_to_send_counter = 0;

  if (link_key_state != current_link_key_state){

    if (((millis()-last_link_key_action_time) < FEATURE_INTERNET_LINK_BUFFER_TIME_MS) && (last_link_key_action_time != 0)){
      if (link_key_state){
        #if defined(DEBUG_INTERNET_LINKING_SEND)
          debug_serial_port->print("link_key: D");
        #endif //DEBUG_INTERNET_LINKING_SEND
        bytes_to_send[0] = 'D';
        add_to_udp_send_buffer(bytes_to_send,1);
      } else {
        if (buffered_key_down){
          #if defined(DEBUG_INTERNET_LINKING_SEND)
            debug_serial_port->print("link_key: V");
          #endif //DEBUG_INTERNET_LINKING_SEND  
          bytes_to_send[0] = 'V';
          add_to_udp_send_buffer(bytes_to_send,1);            
          buffered_key_down = 0;
        } else { 
          #if defined(DEBUG_INTERNET_LINKING_SEND)
            debug_serial_port->print("link_key: U");
          #endif //DEBUG_INTERNET_LINKING_SEND  
          bytes_to_send[0] = 'U';
          add_to_udp_send_buffer(bytes_to_send,1);            
        }
      }
      #if defined(DEBUG_INTERNET_LINKING_SEND)
        debug_serial_port->print(millis()-last_link_key_action_time);
      #endif //DEBUG_INTERNET_LINKING_SEND  
      unsigned int number_to_send = millis()-last_link_key_action_time;
      if ((number_to_send / 10000) > 0){
        bytes_to_send[0] = (number_to_send / 10000) + 48;
        number_to_send = number_to_send % 10000;
        bytes_to_send_counter++;
      }
      if ((number_to_send / 1000) > 0){
        bytes_to_send[bytes_to_send_counter] = (number_to_send / 1000) + 48;
        number_to_send = number_to_send % 1000;
        bytes_to_send_counter++;
      }
      if ((number_to_send / 100) > 0){
        bytes_to_send[bytes_to_send_counter] = (number_to_send / 100) + 48;
        number_to_send = number_to_send % 100;
        bytes_to_send_counter++;
      }
      if ((number_to_send / 10) > 0){
        bytes_to_send[bytes_to_send_counter] = (number_to_send / 10) + 48;
        number_to_send = number_to_send % 10;
        bytes_to_send_counter++;
      }     
      bytes_to_send[bytes_to_send_counter] = number_to_send + 48;
      bytes_to_send_counter++;
      add_to_udp_send_buffer(bytes_to_send,bytes_to_send_counter);
    } else {
      buffered_key_down = 1;
    }
    #if defined(DEBUG_INTERNET_LINKING_SEND)
      debug_serial_port->println("");
    #endif //DEBUG_INTERNET_LINKING_SEND  
    current_link_key_state = link_key_state;
    last_link_key_action_time = millis();
  }
}


#endif //FEATURE_INTERNET_LINK

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_INTERNET_LINK)
void add_to_udp_send_buffer(uint8_t bytes_to_send[8],uint8_t number_of_bytes){

  for (int x = 0;x < number_of_bytes;x++){
    if (udp_send_buffer_bytes < FEATURE_UDP_SEND_BUFFER_SIZE){
      udp_send_buffer[udp_send_buffer_bytes] = bytes_to_send[x];
      udp_send_buffer_bytes++;
    }
  }
}

#endif //FEATURE_INTERNET_LINK
//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_INTERNET_LINK)
void service_udp_send_buffer(){

  static uint8_t link_send_buffer[FEATURE_INTERNET_LINK_MAX_LINKS][FEATURE_UDP_SEND_BUFFER_SIZE];
  static uint8_t link_send_buffer_bytes[FEATURE_INTERNET_LINK_MAX_LINKS];
  static uint8_t link_send_buffer_bytes_initialized = 0;

  if (!link_send_buffer_bytes_initialized){
    for (int x = 0;x < FEATURE_INTERNET_LINK_MAX_LINKS;x++){
      link_send_buffer_bytes[x] = 0;
    }
    link_send_buffer_bytes_initialized = 1;
  }

  // load up the bytes sitting in the udp_send_buffer into the individual link buffers
  if (udp_send_buffer_bytes){
    for (int y = 0;y < FEATURE_INTERNET_LINK_MAX_LINKS;y++){   // enumerate the individual links
      for (int x = 0;x < udp_send_buffer_bytes;x++){           // loop through the bytes in the udp_send_buffer
        if (configuration.link_send_enabled[y]){
          if (link_send_buffer_bytes[y] < FEATURE_UDP_SEND_BUFFER_SIZE){
            link_send_buffer[y][link_send_buffer_bytes[y]] = udp_send_buffer[x];
            link_send_buffer_bytes[y]++;
          } else {
            #if defined(DEBUG_UDP)
              debug_serial_port->println("service_udp_send_buffer: link_send_buffer_overflow");
            #endif
          }
        }
      }
    }
    udp_send_buffer_bytes = 0;
    return;
  }

  // send out a packet for the first link that has packets in the buffer (don't do them all at once so we don't hog up the CPU)
  for (int y = 0;y < FEATURE_INTERNET_LINK_MAX_LINKS;y++){
    if ((configuration.link_send_enabled[y]) && (link_send_buffer_bytes[y])){
      IPAddress ip(configuration.link_send_ip[0][y],configuration.link_send_ip[1][y],configuration.link_send_ip[2][y],configuration.link_send_ip[3][y]);
      #if defined(DEBUG_UDP)
        debug_serial_port->print(F("service_udp_send_buffer: beginPacket "));
        debug_serial_port->print(configuration.link_send_ip[0][y]);
        debug_serial_port->print(F("."));
        debug_serial_port->print(configuration.link_send_ip[1][y]);
        debug_serial_port->print(F("."));
        debug_serial_port->print(configuration.link_send_ip[2][y]);
        debug_serial_port->print(F("."));
        debug_serial_port->print(configuration.link_send_ip[3][y]);
        debug_serial_port->print(F(":"));   
        debug_serial_port->println(configuration.link_send_udp_port[y]);                        
      #endif   
      
      Udp.beginPacket(ip, configuration.link_send_udp_port[y]);

      for (int x = 0;x < link_send_buffer_bytes[y];x++){
        udp_write(link_send_buffer[y][x]);
      }
      #if defined(DEBUG_UDP)
        debug_serial_port->print("\n\rservice_udp_send_buffer: endPacket ");
        unsigned long beginPacket_start = millis();
      #endif
      int endpacket_result = Udp.endPacket();
      #if defined(DEBUG_UDP)
        unsigned long beginPacket_end = millis();
        if (!endpacket_result){
          debug_serial_port->print("error");
        } else {
          debug_serial_port->print("OK");
        }
        debug_serial_port->print(" time:");
        debug_serial_port->print(beginPacket_end - beginPacket_start);
        debug_serial_port->println(" mS");
      #endif
      link_send_buffer_bytes[y] = 0;
      y = FEATURE_INTERNET_LINK_MAX_LINKS;  // exit after we've process one buffer with bytes
    }

  }

}

#endif //FEATURE_INTERNET_LINK

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_UDP)
void udp_write(uint8_t byte_to_write){

  Udp.write(byte_to_write);

  #if defined(DEBUG_UDP_WRITE)

    static char ascii_sent[17] = "";

    debug_serial_port->print(" ");
    if (byte_to_write < 16){
      debug_serial_port->print("0");
    }
    debug_serial_port->print(byte_to_write,HEX);
    debug_serial_port->print(" ");
    debug_serial_port->write(byte_to_write);
  #endif //DEBUG_UDP_WRITE

}
#endif //FEATURE_UDP

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_UDP)
void service_udp_receive(){

  char udp_char_receive_packet_buffer[FEATURE_UDP_RECEIVE_BUFFER_SIZE];


  if (configuration.link_receive_enabled){
    int packet_size = Udp.parsePacket();
    if (packet_size) {

      Udp.read(udp_char_receive_packet_buffer, FEATURE_UDP_RECEIVE_BUFFER_SIZE);

      #if defined(DEBUG_UDP_PACKET_RECEIVE)
        debug_serial_port->print(F("service_udp_receive: received packet: size "));
        debug_serial_port->print(packet_size);
        debug_serial_port->print(" from ");
        IPAddress remote = Udp.remoteIP();
        for (int i = 0; i < 4; i++) {
          debug_serial_port->print(remote[i], DEC);
          if (i < 3) {
            debug_serial_port->print(".");
          }
        }
        debug_serial_port->print(":");
        debug_serial_port->print(Udp.remotePort());
        debug_serial_port->print(" contents: ");
        for (int x = 0;x < packet_size;x++){
          debug_serial_port->print(udp_char_receive_packet_buffer[x]);
        }
        debug_serial_port->println("$");
      #endif //DEBUG_UDP

     if (packet_size > FEATURE_UDP_RECEIVE_BUFFER_SIZE){ packet_size = FEATURE_UDP_RECEIVE_BUFFER_SIZE;}

      for (int x = 0; x < packet_size; x++){
        if (udp_receive_packet_buffer_bytes < FEATURE_UDP_RECEIVE_BUFFER_SIZE){
          udp_receive_packet_buffer[udp_receive_packet_buffer_bytes] = udp_char_receive_packet_buffer[x];
          udp_receive_packet_buffer_bytes++;
        }
      }
    }
  }
}

#endif //FEATURE_UDP

//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_UDP)
uint8_t get_udp_receive_buffer_byte(){


  if (udp_receive_packet_buffer_bytes){

    uint8_t byte_to_return = udp_receive_packet_buffer[0];

    udp_receive_packet_buffer_bytes--;

    if (udp_receive_packet_buffer_bytes){
      for (int x = 0; x < udp_receive_packet_buffer_bytes; x++){
        udp_receive_packet_buffer[x] = udp_receive_packet_buffer[x+1]; 
      }
    }

    #if defined(DEBUG_UDP_PACKET_RECEIVE)
      debug_serial_port->print(F("get_udp_receive_buffer_byte: returning: "));
      debug_serial_port->write(byte_to_return);
      debug_serial_port->print(F(" udp_receive_packet_buffer_bytes: "));
      debug_serial_port->println(udp_receive_packet_buffer_bytes);
    #endif //DEBUG_UDP_PACKET_RECEIVE


    return byte_to_return;
   
  } else {
    return 0;
  }


}
#endif //FEATURE_UDP
//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_UDP)
uint8_t get_udp_receive_buffer_link_command(uint8_t * command,unsigned int * parameter){

  // this extracts received link commands from the udp_receive_packet_buffer

  uint8_t incoming_byte = 0;
  uint8_t return_value = 0;
  static uint8_t static_return_value = 0;
  static uint8_t command_value = 0;
  static uint8_t hit_vdu_command = 0;
  static unsigned int parameter_value = 0;
  static uint8_t digits = 0;

  static unsigned long last_byte_receive_time = 0;

  if (((millis() - last_byte_receive_time) > 500) && (hit_vdu_command)){
    #if defined(DEBUG_INTERNET_LINKING_RECEIVE)
      if (static_return_value){
        debug_serial_port->println(F("get_udp_receive_buffer_link_command: expired buffer"));
      }
    #endif //DEBUG_INTERNET_LINKING_RECEIVE
    parameter_value = 0;
    hit_vdu_command = 0;
    digits = 0;
    //command_value = 0;
    static_return_value = 0;
  }
  

  if (udp_receive_packet_buffer_bytes){

    for (int x = 0;((x < udp_receive_packet_buffer_bytes) && (static_return_value == 0)); x++){
      incoming_byte = get_udp_receive_buffer_byte();
      last_byte_receive_time = millis();
      #if defined(DEBUG_INTERNET_LINKING_RECEIVE)
        // debug_serial_port->print(F("get_udp_receive_buffer_link_command: incoming_byte: "));
        // debug_serial_port->write(incoming_byte);
        // debug_serial_port->print(F(" hit_vdu_command: "));
        // debug_serial_port->println(hit_vdu_command);
      #endif //DEBUG_INTERNET_LINKING_RECEIVE      
      if (!hit_vdu_command){
        #if defined(DEBUG_INTERNET_LINKING_RECEIVE)
          // debug_serial_port->println(F("get_udp_receive_buffer_link_command: looking for V D U"));
        #endif //DEBUG_INTERNET_LINKING_RECEIVE         
        if ((incoming_byte == 'V') || (incoming_byte == 'D') || (incoming_byte == 'U')) { 
          command_value = incoming_byte;
          hit_vdu_command = 1;
          parameter_value = 0;
          digits = 0;
          #if defined(DEBUG_INTERNET_LINKING_RECEIVE)
            // debug_serial_port->println(F("get_udp_receive_buffer_link_command: hit_vdu_command"));
          #endif //DEBUG_INTERNET_LINKING_RECEIVE           
        }
      } else { // we've hit a V, D, or U command
        #if defined(DEBUG_INTERNET_LINKING_RECEIVE)
          // debug_serial_port->println(F("get_udp_receive_buffer_link_command: looking for a number"));
        #endif //DEBUG_INTERNET_LINKING_RECEIVE         
        if ((incoming_byte > 47) && (incoming_byte < 58)){
          parameter_value = (parameter_value * 10) + (incoming_byte - 48);
          digits++;
          #if defined(DEBUG_INTERNET_LINKING_RECEIVE)
            // debug_serial_port->print(F("get_udp_receive_buffer_link_command: parameter_value: "));
            // debug_serial_port->print(parameter_value);
            // debug_serial_port->print(F(" digits: "));
            // debug_serial_port->println(digits);
          #endif //DEBUG_INTERNET_LINKING_RECEIVE           
          // peek at next byte to see if we're at the end
          service_udp_receive();
          if (((udp_receive_packet_buffer_bytes > 0) && ((udp_receive_packet_buffer[0] == 'V') || (udp_receive_packet_buffer[0] == 'D') || (udp_receive_packet_buffer[0] == 'U'))) ||
            (udp_receive_packet_buffer_bytes == 0) || (digits > 4)) {
            static_return_value = 1;
          }
        } else { //something bogus came in - reset everything
          #if defined(DEBUG_INTERNET_LINKING_RECEIVE)
            debug_serial_port->print(F("get_udp_receive_buffer_link_command: reset digits:"));
            debug_serial_port->print(digits);
            debug_serial_port->print(F(" incoming_byte:"));
            debug_serial_port->write(incoming_byte);
            debug_serial_port->println();
          #endif //DEBUG_INTERNET_LINKING_RECEIVE             
          //parameter_value = 0;
          //digits = 0;
          //command_value = 0;  
          hit_vdu_command = 0;
        }
      }
    }


  } 

  #if defined(DEBUG_INTERNET_LINKING_RECEIVE)
    if (static_return_value){
      debug_serial_port->print(F("get_udp_receive_buffer_link_command: exiting: cmd: "));
      debug_serial_port->write(command_value);
      debug_serial_port->print(F(" parameter: "));
      debug_serial_port->println(parameter_value);
    }
  #endif //DEBUG_INTERNET_LINKING_RECEIVE

  if (static_return_value){
    *command = command_value;
    *parameter = parameter_value;
    //parameter_value = 0;
    //digits = 0;
    //command_value = 0;
    static_return_value = 0;
    hit_vdu_command = 0;
    return_value = 1;
  }

  return return_value;


}
#endif //FEATURE_UDP
//-------------------------------------------------------------------------------------------------------

#if defined(FEATURE_UDP)
void service_internet_link_udp_receive_buffer(){

  //  Vxxxxx = key down immediately, stay keyed down for xxxxx mS, then key up
  //  Dxxxxx = key down xxxxx mS after last command
  //  Uxxxxx = key up xxxxx mS after last command


  #define LINK_NO_COMMAND 0
  #define LINK_V_COMMAND_IN_PROGRESS 1
  #define LINK_U_COMMAND_BUFFERED 2
  #define LINK_D_COMMAND_BUFFERED 3

  uint8_t incoming_link_command = 0;
  unsigned int incoming_link_command_parameter = 0;

  static uint8_t current_link_control_state = LINK_NO_COMMAND;
  static unsigned long v_command_key_down_expire_time = 0;
  static unsigned long last_command_completion_time = 0;
  static unsigned long buffered_command_execution_time = 0;
  static unsigned long key_down_time = 0;


  if ((key_down_time > 0) && ((millis()-key_down_time) > (FEATURE_INTERNET_LINK_KEY_DOWN_TIMEOUT_SECS * 1000))){
    tx_and_sidetone_key(0);
    key_down_time = 0;
  }


  switch(current_link_control_state){
    case LINK_NO_COMMAND:
      // is there a command in the buffer, if so read it and execute
      if (get_udp_receive_buffer_link_command(&incoming_link_command, &incoming_link_command_parameter)){
        #if defined(DEBUG_INTERNET_LINKING_RECEIVE)
          debug_serial_port->print(F("service_internet_link_udp_receive_buffer: incoming_link_command: "));
          debug_serial_port->write(incoming_link_command);
          debug_serial_port->print(F(" incoming_link_command_parameter: "));
          debug_serial_port->println(incoming_link_command_parameter);
        #endif //DEBUG_INTERNET_LINKING_RECEIVE
        if (incoming_link_command == 'V'){ // key down immediately for incoming_link_parameter mS
          tx_and_sidetone_key(1);
          key_down_time = millis();
          #if defined(DEBUG_INTERNET_LINKING_RECEIVE)
            debug_serial_port->println(F("service_internet_link_udp_receive_buffer: LINK_V_COMMAND_IN_PROGRESS tx_and_sidetone_key: 1"));
          #endif //DEBUG_INTERNET_LINKING_RECEIVE
          v_command_key_down_expire_time = millis() + incoming_link_command_parameter;
          current_link_control_state = LINK_V_COMMAND_IN_PROGRESS;
        }
        if (incoming_link_command == 'U'){
          current_link_control_state = LINK_U_COMMAND_BUFFERED;
          buffered_command_execution_time = last_command_completion_time + incoming_link_command_parameter;
          #if defined(DEBUG_INTERNET_LINKING_RECEIVE)
            debug_serial_port->println(F("service_internet_link_udp_receive_buffer: LINK_U_COMMAND_BUFFERED"));
          #endif //DEBUG_INTERNET_LINKING_RECEIVE 
        }        
        if (incoming_link_command == 'D'){
          current_link_control_state = LINK_D_COMMAND_BUFFERED;
          buffered_command_execution_time = last_command_completion_time + incoming_link_command_parameter;
          #if defined(DEBUG_INTERNET_LINKING_RECEIVE)
            debug_serial_port->println(F("service_internet_link_udp_receive_buffer: LINK_D_COMMAND_BUFFERED"));
          #endif //DEBUG_INTERNET_LINKING_RECEIVE                  
        }
      }
      break;
    case LINK_U_COMMAND_BUFFERED: // key up after last command time has passed
      if (millis() >= buffered_command_execution_time){
        tx_and_sidetone_key(0);
        key_down_time = 0;
        last_command_completion_time = millis();
        current_link_control_state = LINK_NO_COMMAND;     
        #if defined(DEBUG_INTERNET_LINKING_RECEIVE)
          debug_serial_port->println(F("service_internet_link_udp_receive_buffer: LINK_U_COMMAND_BUFFERED->LINK_NO_COMMAND tx_and_sidetone_key: 0"));
        #endif //DEBUG_INTERNET_LINKING_RECEIVE           
      }
      break;
    case LINK_D_COMMAND_BUFFERED: // key down after last command time has passed
      if (millis() >= buffered_command_execution_time){
        tx_and_sidetone_key(1);
        key_down_time = millis();
        last_command_completion_time = millis();
        current_link_control_state = LINK_NO_COMMAND;  
        #if defined(DEBUG_INTERNET_LINKING_RECEIVE)
          debug_serial_port->println(F("service_internet_link_udp_receive_buffer: LINK_D_COMMAND_BUFFERED->LINK_NO_COMMAND tx_and_sidetone_key: 1"));
        #endif //DEBUG_INTERNET_LINKING_RECEIVE                
      }
      break;
    case LINK_V_COMMAND_IN_PROGRESS: // we're in key down, check if it time to key up and complete
      if (millis() >= v_command_key_down_expire_time){
        tx_and_sidetone_key(0);
        key_down_time = 0;
        v_command_key_down_expire_time = 0;
        last_command_completion_time = millis();
        current_link_control_state = LINK_NO_COMMAND;
        #if defined(DEBUG_INTERNET_LINKING_RECEIVE)
          debug_serial_port->println(F("service_internet_link_udp_receive_buffer: LINK_V_COMMAND_IN_PROGRESS->LINK_NO_COMMAND tx_and_sidetone_key: 0"));
        #endif //DEBUG_INTERNET_LINKING_RECEIVE          
      }
      break;

  } //switch(current_link_control_state)

}

#endif //FEATURE_UDP

//-------------------------------------------------------------------------------------------------------

void service_millis_rollover(){

  static unsigned long last_millis = 0;

  if (millis() < last_millis){
    millis_rollover++;
  }
  last_millis = millis();

}
//-------------------------------------------------------------------------------------------------------
#ifdef OPTION_NON_ENGLISH_EXTENSIONS
byte convert_unicode_to_send_char_code(byte first_byte,byte second_byte){


  if (first_byte == 195){
    switch(second_byte){
      case 133: return 197; // Å AA_capital (OZ, LA, SM)
      case 134: return 198; // Æ (OZ, LA)
      case 152: return 216; // Ø (OZ, LA)
      case 128: return 192; // À - A accent   
      case 132: return 196; // Ä - A_umlaut (D, SM, OH, ...)
      case 145: return 209; // Ñ - (EA)               
      case 150: return 214; // Ö – O_umlaut  (D, SM, OH, ...)
      case 146: return 211; // Ò - O accent  
      case 156: return 220; // Ü - U_umlaut     (D, ...)  
      case 135: return 199; // Ç
      case 144: return 208; // Ð
      case 136: return 200; // È
      case 137: return 201; // É
    }

    if (first_byte == 197){
      switch(second_byte){
        case 189: return 142; // Ž
      }
    }

  }

  return(0);

}
#endif

//-------------------------------------------------------------------------------------------------------

void initialize_sd_card(){

  #if defined(FEATURE_SD_CARD_SUPPORT)
    if (!SD.begin(sd_card_spi_ss_line)) {
      #if defined(DEBUG_SD_CARD)
        debug_serial_port->println(F("initialize_sd_card: initialization failed"));
      #endif
      return;
    }

    sd_card_state = SD_CARD_AVAILABLE;

    // This causes a problem with directory listing...
    // if (!SD.exists("/keyer")){
    //  SD.mkdir("/keyer");
    //   #if defined(DEBUG_SD_CARD)
    //     debug_serial_port->println(F("initialize_sd_card: created /keyer"));
    //   #endif      
    // }

    if (SD.exists("/keyer/beacon.txt")){
      sd_card_state = SD_CARD_AVAILABLE_BEACON_FILE_FOUND;
    }

    #if defined(DEBUG_SD_CARD)
      debug_serial_port->println(F("initialize_sd_card: initialization done"));
    #endif  

  #endif //FEATURE_SD_CARD_SUPPORT

}

//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_SD_CARD_SUPPORT)
void service_sd_card(){

  static unsigned long last_sd_log_file_save = 0;

  if (sd_card_state == SD_CARD_AVAILABLE_BEACON_FILE_RUNNING){
    if (dit_buffer || dah_buffer){
      sd_card_state = SD_CARD_AVAILABLE;
      sdfile.close();
    } else {
      if (send_buffer_bytes == 0){
        if (sdfile.available()){
          add_to_send_buffer(uppercase(sdfile.read()));
        } else {
          sdfile.seek(0);
        }
      }
    }
  }


  if (sd_card_state == SD_CARD_AVAILABLE_BEACON_FILE_FOUND){
    sdfile = SD.open("/keyer/beacon.txt");
    if (sdfile){
      sd_card_state = SD_CARD_AVAILABLE_BEACON_FILE_RUNNING;
    } else {
      sd_card_state = SD_CARD_ERROR;
    }
  }


  if ((sd_card_log_state == SD_CARD_LOG_OPEN) && ((millis() - last_sd_log_file_save) > 60000)){
    sdlogfile.flush();
    last_sd_log_file_save = millis();
  }

}
#endif //FEATURE_SD_CARD_SUPPORT
//-------------------------------------------------------------------------------------------------------
byte is_visible_character(byte char_in){

  if((char_in > 31) || (char_in == 9) || (char_in == 10) || (char_in == 13)){
    return 1;
  } else {
    return 0;
  }

}


//-------------------------------------------------------------------------------------------------------
#if defined(FEATURE_SD_CARD_SUPPORT)
void sd_card_log(String string_to_log,byte byte_to_log){

  char logchar[10];

  if (sd_card_log_state == SD_CARD_LOG_OPEN){
    if (string_to_log.length() > 0){
      string_to_log.toCharArray(logchar,9);
      sdlogfile.print(logchar);
    } else {
      if (is_visible_character(byte_to_log)){
        sdlogfile.write(byte_to_log);
      }
    }
  }



  if ((sd_card_log_state == SD_CARD_LOG_NOT_OPEN) && (sd_card_state == SD_CARD_AVAILABLE)){
    sdlogfile = SD.open("/keyer/keyer.log",FILE_WRITE);
    if (!sdlogfile){
      sd_card_log_state = SD_CARD_LOG_ERROR;
    } else {
      sd_card_log_state = SD_CARD_LOG_OPEN; 
      sdlogfile.println("\r\nstart of log ");
      if (configuration.cli_mode == CLI_MILL_MODE_PADDLE_SEND){
        sdlogfile.print("TX:");
        sdlogfile.flush();
      } else {
        sdlogfile.print("RX:");
        sdlogfile.flush();
      }
    }
  }

}
#endif //FEATURE_SD_CARD_SUPPORT

//-------------------------------------------------------------------------------------------------------

// DL2DBG contributed code (adapted into code by Goody K3NG)
// Based on https://forum.arduino.cc/index.php?topic=446209.15


// #if defined(FEATURE_SINEWAVE_SIDETONE)

// void compute_sinetone(int hz, int volume){ //dl2dbg 


//   omega = 2*pi*hz ;
//   c1 = (8.0 - 2.0*pow(omega*T/1000000.0,2))/(4.0+pow(omega*T/1000000.0,2));
//   #if defined(FEATURE_SINEWAVE_SIDETONE_USING_TIMER_1)
//     Timer1.detachInterrupt();
//   #endif  
//   #if defined(FEATURE_SINEWAVE_SIDETONE_USING_TIMER_3)
//     Timer3.detachInterrupt();
//   #endif
//   a[0]= 0.0;
//   a[1]= volume*sin(omega*T/1000000.0);
//   a[2]= 0.0;
//   #if defined(FEATURE_SINEWAVE_SIDETONE_USING_TIMER_1)
//     Timer1.attachInterrupt(sinewave_interrupt_compute);
//   #endif  
//   #if defined(FEATURE_SINEWAVE_SIDETONE_USING_TIMER_3)
//     Timer3.attachInterrupt(sinewave_interrupt_compute);
//   #endif


// }
// #endif //FEATURE_SINEWAVE_SIDETONE

//-------------------------------------------------------------------------------------------------------

// #if defined(FEATURE_SINEWAVE_SIDETONE)

// void sinewave_interrupt_compute(){ //dl2dbg

//   a[2] = c1 * a[1] - a[0];
//   a[0] = a[1] ;
//   a[1] = a[2] ;  
//   #if defined(FEATURE_SINEWAVE_SIDETONE_USING_TIMER_1)
//     Timer1.setPwmDuty(sidetone_line, map( a[2],-512, 512, 0, 1000));
//   #endif  
//   #if defined(FEATURE_SINEWAVE_SIDETONE_USING_TIMER_3)
//     Timer3.setPwmDuty(sidetone_line, map( a[2],-512, 512, 0, 1000));
//   #endif

  

// }
// #endif //FEATURE_SINEWAVE_SIDETONE

//-------------------------------------------------------------------------------------------------------
// #if defined(FEATURE_SINEWAVE_SIDETONE)

// void initialize_tonsin(){ //dl2dbg

//   //configuration.sidetone_volume = sidetone_volume_low_limit + ((sidetone_volume_high_limit - sidetone_volume_low_limit) / 2);
//   compute_sinetone(configuration.hz_sidetone,configuration.sidetone_volume);
//   #if defined(FEATURE_SINEWAVE_SIDETONE_USING_TIMER_1)
//     Timer1.initialize(T);  // set sample time for discrete tone signal
//     Timer1.pwm(sidetone_line, 0, T);
//     Timer1.attachInterrupt(sinewave_interrupt_compute);
//     Timer1.stop();
//   #endif  
//   #if defined(FEATURE_SINEWAVE_SIDETONE_USING_TIMER_3)
//     Timer3.initialize(T);  // set sample time for discrete tone signal
//     Timer3.pwm(sidetone_line, 0, T);
//     Timer3.attachInterrupt(sinewave_interrupt_compute);
//     Timer3.stop();
//   #endif





// }
// #endif //FEATURE_SINEWAVE_SIDETONE
//-------------------------------------------------------------------------------------------------------

// #if defined(FEATURE_SINEWAVE_SIDETONE)
// void sinetone(uint8_t pin_dummy_variable, unsigned short freq){  //dl2dbg

//   static int last_freq;
//   static int last_volume;

//   if ((freq != last_freq) || (configuration.sidetone_volume != last_volume)){ 
//     compute_sinetone(freq,configuration.sidetone_volume);
//     last_freq = freq;
//     last_volume = configuration.sidetone_volume;
//   }

//   //delay (2); compute_sinetone(freq,sidetone_volume/4);
//   //delay (2); compute_sinetone(freq,sidetone_volume/2);
//   //compute_sinetone(freq,configuration.sidetone_volume); 

//   #if defined(FEATURE_SINEWAVE_SIDETONE_USING_TIMER_1)
//     Timer1.restart();
//   #endif  
//   #if defined(FEATURE_SINEWAVE_SIDETONE_USING_TIMER_3)
//     Timer3.restart();
//   #endif

  


// }
// #endif //FEATURE_SINEWAVE_SIDETONE

//------------------------------------------------------------------------------------------------------- 

// #if defined(FEATURE_SINEWAVE_SIDETONE)
// void nosineTone(uint8_t pin_dummy_variable){    // disable tone on specified pin, if any    dl2dbg

//   //delay (2); compute_sinetone(freq,sidetone_volume/2);
//   //delay (2); compute_sinetone(freq,sidetone_volume/4);
//   // compute_sinetone(configuration.hz_sidetone,0);


//   #if defined(FEATURE_SINEWAVE_SIDETONE_USING_TIMER_1)
//     Timer1.stop();
//   #endif  
//   #if defined(FEATURE_SINEWAVE_SIDETONE_USING_TIMER_3)
//     Timer3.stop();
//   #endif
  

//   //digitalWrite(sidetone_line,LOW);

// }

// #endif //FEATURE_SINEWAVE_SIDETONE

//-------------------------------------------------------------------------------------------------------

void debug_blink(){
  #if defined(DEBUG_STARTUP_BLINKS)
    digitalWrite(13,HIGH);
    delay(250);
    digitalWrite(13,LOW);
    delay(1000);
  #endif //DEBUG_STARTUP
}    

//-------------------------------------------------------------------------------------------------------

//
//
// Congratulations.  You've gotten to the end.  But this is just the beginning.
//
//






/*



  #ifdef FEATURE_CLOCK
    int temp_year = 0;
    byte temp_month = 0;
    byte temp_day = 0;
    byte temp_minute = 0;
    byte temp_hour = 0;
    byte negative_flag = 0;
  #endif // FEATURE_CLOCK



    #ifdef FEATURE_CLOCK
    case 'C':         // show clock
      update_time();
      sprintf(return_string, "%s", timezone_modified_clock_string());


      break;
    case 'O':         // set clock UTC time
      temp_year = ((input_buffer[2] - 48) * 1000) + ((input_buffer[3] - 48) * 100) + ((input_buffer[4] - 48) * 10) + (input_buffer[5] - 48);
      temp_month = ((input_buffer[6] - 48) * 10) + (input_buffer[7] - 48);
      temp_day = ((input_buffer[8] - 48) * 10) + (input_buffer[9] - 48);
      temp_hour = ((input_buffer[10] - 48) * 10) + (input_buffer[11] - 48);
      temp_minute = ((input_buffer[12] - 48) * 10) + (input_buffer[13] - 48);
      if ((temp_year > 2013) && (temp_year < 2070) &&
          (temp_month > 0) && (temp_month < 13) &&
          (temp_day > 0) && (temp_day < 32) &&
          (temp_hour >= 0) && (temp_hour < 24) &&
          (temp_minute >= 0) && (temp_minute < 60) &&
          (input_buffer_index == 14)) {

        clock_year_set = temp_year;
        clock_month_set = temp_month;
        clock_day_set = temp_day;
        clock_hour_set = temp_hour;
        clock_min_set = temp_minute;
        clock_sec_set = 0;
        millis_at_last_calibration = millis();

        #if defined(FEATURE_RTC_DS1307)
        rtc.adjust(DateTime(temp_year, temp_month, temp_day, temp_hour, temp_minute, 0));
        #endif // defined(FEATURE_RTC_DS1307)
        #if defined(FEATURE_RTC_PCF8583)
        rtc.year = temp_year;
        rtc.month = temp_month;
        rtc.day = temp_day;
        rtc.hour  = temp_hour;
        rtc.minute = temp_minute;
        rtc.second = 0;
        rtc.set_time();
        #endif // defined(FEATURE_RTC_PCF8583)

        #if (!defined(FEATURE_RTC_DS1307) && !defined(FEATURE_RTC_PCF8583))
        strcpy(return_string, "Clock set to ");
        update_time();
        strcat(return_string, timezone_modified_clock_string());
        #else
        strcpy(return_string, "Internal clock and RTC set to ");
        update_time();
        strcat(return_string, timezone_modified_clock_string());
        #endif
      } else {
        strcpy(return_string, "Error. Usage: \\OYYYYMMDDHHmm");
      }
      break;

    case 'V': //  \Vx[xxx][.][xxxx]   Set time zone offset
      negative_flag = 0;
      place_multiplier = 1;
      for (int x = input_buffer_index - 1; x > 1; x--) {
        if (char(input_buffer[x]) == '-') {
          negative_flag = 1;
        } else {
          if (char(input_buffer[x]) != '.') {
            tempfloat += (input_buffer[x] - 48) * place_multiplier;
            place_multiplier = place_multiplier * 10;
          } else {
            decimalplace = x;
          }
        }
      }
      if (decimalplace) {
        tempfloat = tempfloat / pow(10, (input_buffer_index - decimalplace - 1));
      }
      if (negative_flag){tempfloat = tempfloat * -1.0;}
      if ((tempfloat >= -24.0) && (tempfloat <= 24.0)) {
        configuration.clock_timezone_offset = tempfloat;
        configuration_dirty = 1;
        strcpy(return_string, "Timezone offset set to ");
        dtostrf(tempfloat, 0, 2, temp_string);
        strcat(return_string, temp_string);
      } else {
        strcpy(return_string, "Error.");
      }
      break;
    #endif // FEATURE_CLOCK

// --------------------------------------------------------------

#ifdef FEATURE_CLOCK
char * timezone_modified_clock_string(){

  static char return_string[32] = "";
  char temp_string[16] = "";


  dtostrf(local_clock_years, 0, 0, temp_string);
  strcpy(return_string, temp_string);
  strcat(return_string, "-");
  if (local_clock_months < 10) {
    strcat(return_string, "0");
  }
  dtostrf(local_clock_months, 0, 0, temp_string);
  strcat(return_string, temp_string);
  strcat(return_string, "-");
  if (local_clock_days < 10) {
    strcat(return_string, "0");
  }
  dtostrf(local_clock_days, 0, 0, temp_string);
  strcat(return_string, temp_string);
  strcat(return_string, " ");

  if (local_clock_hours < 10) {
    strcat(return_string, "0");
  }
  dtostrf(local_clock_hours, 0, 0, temp_string);
  strcat(return_string, temp_string);
  strcat(return_string, ":");
  if (local_clock_minutes < 10) {
    strcat(return_string, "0");
  }
  dtostrf(local_clock_minutes, 0, 0, temp_string);
  strcat(return_string, temp_string);
  strcat(return_string, ":");
  if (local_clock_seconds < 10) {
    strcat(return_string, "0");
  }
  dtostrf(local_clock_seconds, 0, 0, temp_string);
  strcat(return_string, temp_string);
  if (configuration.clock_timezone_offset == 0){
    strcat(return_string,"Z");
  }
  return return_string;

} // clock_string
#endif // FEATURE_CLOCK

// --------------------------------------------------------------

#ifdef FEATURE_CLOCK
char * zulu_clock_string(){

  static char return_string[32] = "";
  char temp_string[16] = "";


  dtostrf(clock_years, 0, 0, temp_string);
  strcpy(return_string, temp_string);
  strcat(return_string, "-");
  if (clock_months < 10) {
    strcat(return_string, "0");
  }
  dtostrf(clock_months, 0, 0, temp_string);
  strcat(return_string, temp_string);
  strcat(return_string, "-");
  if (clock_days < 10) {
    strcat(return_string, "0");
  }
  dtostrf(clock_days, 0, 0, temp_string);
  strcat(return_string, temp_string);
  strcat(return_string, " ");

  if (clock_hours < 10) {
    strcat(return_string, "0");
  }
  dtostrf(clock_hours, 0, 0, temp_string);
  strcat(return_string, temp_string);
  strcat(return_string, ":");
  if (clock_minutes < 10) {
    strcat(return_string, "0");
  }
  dtostrf(clock_minutes, 0, 0, temp_string);
  strcat(return_string, temp_string);
  strcat(return_string, ":");
  if (clock_seconds < 10) {
    strcat(return_string, "0");
  }
  dtostrf(clock_seconds, 0, 0, temp_string);
  strcat(return_string, temp_string);
  strcat(return_string,"Z");
  return return_string;

} // zulu_clock_string
#endif // FEATURE_CLOCK

// --------------------------------------------------------------

#ifdef FEATURE_CLOCK
void update_time(){
  unsigned long runtime = millis() - millis_at_last_calibration;

  // calculate UTC

  unsigned long time = (3600L * clock_hour_set) + (60L * clock_min_set) + clock_sec_set + ((runtime + (runtime * INTERNAL_CLOCK_CORRECTION)) / 1000.0);

  clock_years = clock_year_set;
  clock_months = clock_month_set;
  clock_days = time / 86400L;
  time -= clock_days * 86400L;
  clock_days += clock_day_set;
  clock_hours = time / 3600L;

  switch (clock_months) {

    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      if (clock_days > 31) {
        clock_days = 1; clock_months++;
      }
      break;

    case 2:
      if ((float(clock_years) / 4.0) == 0.0) {  // do we have a leap year?
        if (clock_days > 29) {
          clock_days = 1; clock_months++;
        }
      } else {
        if (clock_days > 28) {
          clock_days = 1; clock_months++;
        }
      }
      break;

    case 4:
    case 6:
    case 9:
    case 11:
      if (clock_days > 30) {
        clock_days = 1; clock_months++;
      }
      break;
  } // switch

  if (clock_months > 12) {
    clock_months = 1; clock_years++;
  }

  time -= clock_hours * 3600L;
  clock_minutes  = time / 60L;
  time -= clock_minutes * 60L;
  clock_seconds = time;


  // calculate local time

  long local_time = (configuration.clock_timezone_offset * 60L * 60L) + (3600L * clock_hour_set) + (60L * clock_min_set) + clock_sec_set + ((runtime + (runtime * INTERNAL_CLOCK_CORRECTION)) / 1000.0);

  local_clock_years = clock_year_set;
  local_clock_months = clock_month_set;
  local_clock_days = clock_day_set;

  if (local_time < 0){
    local_time = local_time + (24L * 60L * 60L) - 1;
    local_clock_days--;
    if (local_clock_days < 1){
      local_clock_months--;
      switch (local_clock_months) {
        case 0:
          local_clock_months = 12;
          local_clock_days = 31;
          local_clock_years--;
          break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
          local_clock_days = 31;
          break;
        case 2: //February
          if ((float(local_clock_years) / 4.0) == 0.0) {  // do we have a leap year?
            local_clock_days = 29;
          } else {
            local_clock_days = 28;
          }
          break;
        case 4:
        case 6:
        case 9:
        case 11:
          local_clock_days = 30;
          break;
      } // switch   
    }
    local_clock_hours = local_time / 3600L;
    local_time -= local_clock_hours * 3600L;
    local_clock_minutes  = local_time / 60L;
    local_time -= local_clock_minutes * 60L;
    local_clock_seconds = local_time;  

  } else {  //(local_time < 0)

    local_clock_days = local_time / 86400L;
    local_time -= local_clock_days * 86400L;
    local_clock_days += clock_day_set;
    local_clock_hours = local_time / 3600L;

    switch (local_clock_months) {

      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
        if (local_clock_days > 31) {
          local_clock_days = 1;
          local_clock_months++;
        }
        break;

      case 2:
        if ((float(local_clock_years) / 4.0) == 0.0) {  // do we have a leap year?
          if (local_clock_days > 29) {
            local_clock_days = 1; 
            local_clock_months++;
          }
        } else {
          if (local_clock_days > 28) {
            local_clock_days = 1;
            local_clock_months++;
          }
        }
        break;

      case 4:
      case 6:
      case 9:
      case 11:
        if (local_clock_days > 30) {
          local_clock_days = 1;
          local_clock_months++;
        }
        break;
    } // switch

    if (local_clock_months > 12) {
      local_clock_months = 1; 
      local_clock_years++;
    }

    local_time -= local_clock_hours * 3600L;
    local_clock_minutes  = local_time / 60L;
    local_time -= local_clock_minutes * 60L;
    local_clock_seconds = local_time;  


  }  //(local_time < 0)
  

} // update_time
#endif // FEATURE_CLOCK
// --------------------------------------------------------------   
*/
