// Initial and hardcoded settings
#define initial_speed_wpm 26             // "factory default" keyer speed setting
#define initial_command_mode_speed_wpm 20 // "factory default" command mode speed setting 
#define initial_sidetone_freq 600        // "factory default" sidetone frequency setting
#define sidetone_hz_limit_low 299
#define sidetone_hz_limit_high 2001
#define hz_high_beep 1500                // frequency in hertz of high beep
#define hz_low_beep 400                  // frequency in hertz of low beep
#define initial_dah_to_dit_ratio 300     // 300 = 3 / normal 3:1 ratio
#define initial_ptt_lead_time_tx1 0         // PTT lead time in mS
#define initial_ptt_tail_time_tx1 10         // PTT tail time in mS
#define initial_ptt_lead_time_tx2 0         // PTT lead time in mS
#define initial_ptt_tail_time_tx2 10         // PTT tail time in mS
#define initial_ptt_lead_time_tx3 0         // PTT lead time in mS
#define initial_ptt_tail_time_tx3 10         // PTT tail time in mS
#define initial_ptt_lead_time_tx4 0         // PTT lead time in mS
#define initial_ptt_tail_time_tx4 10         // PTT tail time in mS
#define initial_ptt_lead_time_tx5 0         // PTT lead time in mS
#define initial_ptt_tail_time_tx5 10         // PTT tail time in mS
#define initial_ptt_lead_time_tx6 0         // PTT lead time in mS
#define initial_ptt_tail_time_tx6 10         // PTT tail time in mS
#define initial_qrss_dit_length 1        // QRSS dit length in seconds
#define initial_pot_wpm_low_value 13     // Potentiometer WPM fully CCW
#define initial_pot_wpm_high_value 35    // Potentiometer WPM fully CW
#define wpm_limit_low 5
#define wpm_limit_high 60
#define potentiometer_change_threshold 0.9 // don't change the keyer speed until pot wpm has changed more than this
#define send_buffer_size 150
#define default_length_letterspace 3
#define default_length_wordspace 7
#define default_keying_compensation 0    // number of milliseconds to extend all dits and dahs - for QSK on boatanchors
#define default_first_extension_time 0   // number of milliseconds to extend first sent dit or dah
#define default_pot_full_scale_reading 1023
#define default_weighting 50             // 50 = weighting factor of 1 (normal)
#define default_ptt_hang_time_wordspace_units 0.0
#define winkey_c0_wait_time 1            // the number of milliseconds to wait to send 0xc0 byte after send buffer has been sent
#define winkey_command_timeout_ms 5000
#define winkey_discard_bytes_startup 3   // this is used if OPTION_WINKEY_DISCARD_BYTES_AT_STARTUP is enabled above
#define winkey_xoff_threshold 20         // the number of chars in the buffer when we begin sending XOFFs
#define winkey_xon_threshold 10          // the number of chars in the buffer below which we deactivate XOFF
#define default_memory_repeat_time 3000  // time in milliseconds
#define LCD_COLUMNS 11
#define LCD_ROWS 4
#define lcd_i2c_address_mathertel_PCF8574 0x27             // I2C address of display for FEATURE_LCD_MATHERTEL_PCF8574
#define lcd_i2c_address_fdebrander_lcd 0x27                // I2C address of display for FEATURE_LCD_I2C_FDEBRABANDER
#define lcd_i2c_address_ydv1_lcd 0x27                      // I2C address of display for FEATURE_LCD_YDv1
//#define lcd_i2c_address_ydv1_lcd 0x38                    // I2C address of display for FEATURE_LCD_YDv1
#define lcd_i2c_address_sainsmart_lcd 0x27                // I2C address of display for FEATURE_LCD_SAINSMART_I2C 
#define oled_i2c_address_ssd1306 0x3C                     // I2C address of display for FEATURE_OLED_SSD1306
#define lcd_i2c_address_twiliquidcrystal_lcd 0x27                // I2C address of display for FEATURE_LCD_TWILIQUIDCRYSTAL 
#define hell_pixel_microseconds 4025
#define program_memory_limit_consec_spaces 1
#define serial_leading_zeros 1            // set to 1 to activate leading zeros in serial numbers (i.e. #1 = 001)
#define serial_cut_numbers 0              // set to 1 to activate cut numbers in serial numbers (i.e. #10 = 1T, #19 = 1N)
#define go_to_sleep_inactivity_time 10    // minutes - FEATURE_SLEEP
#define dim_backlight_inactive_time 5     // minutes - FEATURE_LCD_BACKLIGHT_AUTO_DIM
#define default_cmos_super_keyer_iambic_b_timing_percent 33 // use with FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING; should be between 0 to 99 % (0% = true iambic b;100% = iambic a behavior)
#define default_cw_echo_timing_factor 1.75 // "factory default" setting
#define default_autospace_timing_factor 2.0 // "factory default" setting
#define winkey_paddle_echo_buffer_decode_timing_factor 0.25
#define potentiometer_always_on 0
#define ptt_interlock_check_every_ms 100
#define ptt_interlock_active_state HIGH
#define unknown_cw_character '*'
#define cli_paddle_echo_on_at_boot 1
#define cli_straight_key_echo_on_at_boot 1
#define tx_key_dit_and_dah_pins_active_state HIGH
#define tx_key_dit_and_dah_pins_inactive_state LOW
#define potentiometer_check_interval_ms 150
#define potentiometer_reading_threshold 1 
#define default_paddle_interruption_quiet_time_element_lengths 0
#define default_wordsworth_wordspace 6
#define default_wordsworth_repetition 1
#define serial_program_memory_buffer_size 500
#define eeprom_write_time_ms 30000

#ifdef FEATURE_BUTTONS
  #define analog_buttons_number_of_buttons 4  // includes the command button (command button + 3 memory buttons = 4)
  #define analog_buttons_r1 10
  #define analog_buttons_r2 1
#endif


#if defined(FEATURE_BUTTONS) &&  !defined(FEATURE_PS2_KEYBOARD) && !defined(FEATURE_USB_KEYBOARD) && !defined(FEATURE_COMMAND_LINE_INTERFACE) && !defined(FEATURE_WINKEY_EMULATION)
  #define number_of_memories byte(analog_buttons_number_of_buttons-1)
#else
  #define number_of_memories byte(12)
#endif

#ifdef FEATURE_CAPACITIVE_PADDLE_PINS
  #define capacitance_threshold 2
#endif //FEATURE_CAPACITIVE_PADDLE_PINS

#ifdef FEATURE_LED_RING
  #define led_ring_low_limit 10
  #define led_ring_high_limit 50
#endif //FEATURE_LED_RING

#ifdef FEATURE_QLF
  #define qlf_dit_max 125
  #define qlf_dit_min 75
  #define qlf_dah_max 200
  #define qlf_dah_min 100
  #define qlf_on_by_default 0
#endif //FEATURE_QLF


#ifdef FEATURE_WINKEY_EMULATION
  #if defined(OPTION_WINKEY_UCXLOG_9600_BAUD) || defined(FEATURE_SO2R_BASE)
    #define WINKEY_DEFAULT_BAUD 9600
  #else
    #define WINKEY_DEFAULT_BAUD 1200
  #endif //OPTION_WINKEY_UCXLOG_9600_BAUD  || FEATURE_SO2R_BASE
// alter these below to map alternate sidetones for Winkey interface protocol emulation
#ifdef OPTION_WINKEY_2_SUPPORT
	#define WINKEY_SIDETONE_1 3759
	#define WINKEY_SIDETONE_2 1879
	#define WINKEY_SIDETONE_3 1252
	#define WINKEY_SIDETONE_4 940
	#define WINKEY_SIDETONE_5 752
	#define WINKEY_SIDETONE_6 625
	#define WINKEY_SIDETONE_7 535
	#define WINKEY_SIDETONE_8 469
	#define WINKEY_SIDETONE_9 417
	#define WINKEY_SIDETONE_10 375
#else //OPTION_WINKEY_2_SUPPORT
	#define WINKEY_SIDETONE_1 4000
	#define WINKEY_SIDETONE_2 2000
	#define WINKEY_SIDETONE_3 1333
	#define WINKEY_SIDETONE_4 1000
	#define WINKEY_SIDETONE_5 800
	#define WINKEY_SIDETONE_6 666
	#define WINKEY_SIDETONE_7 571
	#define WINKEY_SIDETONE_8 500
	#define WINKEY_SIDETONE_9 444
	#define WINKEY_SIDETONE_10 400
#endif //OPTION_WINKEY_2_SUPPORT

#define WINKEY_1_REPORT_VERSION_NUMBER 10
#define WINKEY_2_REPORT_VERSION_NUMBER 23

// alter these to map to alternate hang time wordspace units
#define WINKEY_HANG_TIME_1_0 1.0
#define WINKEY_HANG_TIME_1_33 1.33
#define WINKEY_HANG_TIME_1_66 1.66
#define WINKEY_HANG_TIME_2_0 2.0

#define WINKEY_RETURN_THIS_FOR_ADMIN_GET_CAL 0x16
#define WINKEY_RETURN_THIS_FOR_ADMIN_PADDLE_A2D 0xEE
#define WINKEY_RETURN_THIS_FOR_ADMIN_SPEED_A2D 0x00

#endif //FEATURE_WINKEY_EMULATION

#define PRIMARY_SERIAL_PORT &Serial
#define PRIMARY_SERIAL_PORT_BAUD 115200     // This applies only when the port is in Command Line Interface mode.  In Winkey mode it will default to 1200.

#ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
  #define SECONDARY_SERIAL_PORT &Serial1
  #define SECONDARY_SERIAL_PORT_BAUD 115200
#endif


#define CW_DECODER_SCREEN_COLUMNS 120        // word wrap at this many columns
#define CW_DECODER_SPACE_PRINT_THRESH 4.5   // print space if no tone for this many element lengths
#define CW_DECODER_SPACE_DECODE_THRESH 2.0  // invoke character decode if no tone for this many element lengths
#define CW_DECODER_NOISE_FILTER 20          // ignore elements shorter than this (mS)

#define STRAIGHT_KEY_ACTIVE_STATE LOW

#ifdef FEATURE_DYNAMIC_DAH_TO_DIT_RATIO
  #define DYNAMIC_DAH_TO_DIT_RATIO_LOWER_LIMIT_WPM 30
  #define DYNAMIC_DAH_TO_DIT_RATIO_LOWER_LIMIT_RATIO 300 // 300 = 3:1 ratio
  #define DYNAMIC_DAH_TO_DIT_RATIO_UPPER_LIMIT_WPM 70
  #define DYNAMIC_DAH_TO_DIT_RATIO_UPPER_LIMIT_RATIO 240 // 240 = 2.4:1 ratio
#endif //FEATURE_DYNAMIC_DAH_TO_DIT_RATIO

#if defined(FEATURE_COMPETITION_COMPRESSION_DETECTION)
  #define COMPETITION_COMPRESSION_DETECTION_ARRAY_SIZE 16
  #define COMPETITION_COMPRESSION_DETECTION_TIME_INTERCHAR_LOWER_LIMIT 1
  #define COMPETITION_COMPRESSION_DETECTION_TIME_INTERCHAR_UPPER_LIMIT 6.0
  #define COMPETITION_COMPRESSION_DETECTION_AVERAGE_ALARM_THRESHOLD 3.0
#endif //FEATURE_COMPETITION_COMPRESSION_DETECTION

#if defined(FEATURE_SLEEP)
  #define KEYER_AWAKE_PIN_AWAKE_STATE HIGH
  #define KEYER_AWAKE_PIN_ASLEEP_STATE LOW
#endif

#if defined(FEATURE_LCD_BACKLIGHT_AUTO_DIM)
  #define keyer_power_led_awake_duty 255   // PWM duty cycle. 0 is 0%, 255 is 100%
  #define keyer_power_led_asleep_duty 25   // 25 is quite dim. Use 0 for off
#endif

#if defined(FEATURE_ETHERNET)
  // #define FEATURE_ETHERNET_IP {192,168,1,178}                      // default IP address ("192.168.1.178")
  // #define FEATURE_ETHERNET_MAC {0xDE,0xAD,0xBE,0xEF,0xFE,0xED}
  #define FEATURE_ETHERNET_IP {192,168,1,179}                      // default IP address ("192.168.1.179")
  #define FEATURE_ETHERNET_MAC {0xDE,0xAD,0xBE,0xEF,0xFE,0xEE}
  #define FEATURE_ETHERNET_DNS {8,8,8,8} 

  #define FEATURE_ETHERNET_GATEWAY {192,168,1,1}                   // default gateway
  #define FEATURE_ETHERNET_SUBNET_MASK {255,255,255,0}                  // default subnet mask
  #define FEATURE_ETHERNET_WEB_LISTENER_PORT 80
  #define FEATURE_UDP_SEND_BUFFER_SIZE 128
  #define FEATURE_UDP_RECEIVE_BUFFER_SIZE 128
#endif //FEATURE_ETHERNET

#define WEB_SERVER_CONTROL_TX_KEY_TIME_LIMIT_SECS 10

#define FEATURE_INTERNET_LINK_MAX_LINKS 2
#define FEATURE_INTERNET_LINK_DEFAULT_RCV_UDP_PORT 8888
#define FEATURE_INTERNET_LINK_BUFFER_TIME_MS 500 
#define FEATURE_INTERNET_LINK_SVC_DURING_LOOP_TIME_MS 20
#define FEATURE_INTERNET_LINK_KEY_DOWN_TIMEOUT_SECS 8

#if defined(FEATURE_4x4_KEYPAD) || defined(FEATURE_3x4_KEYPAD)
  #define KEYPAD_ROWS 4 //KeyPad Rows
  #if defined(FEATURE_4x4_KEYPAD)
    #define KEYPAD_COLS 4 //keypad Columns
  #else
    #define KEYPAD_COLS 3
  #endif
  #define mem1 0 //Memory numbers for Keypad: Actual memory numbers start with "0"
  #define mem2 1
  #define mem3 2
  #define mem4 3
  #define mem5 4
  #define mem6 5
  #define mem7 6
  #define mem8 7
  #define mem9 8
  #define mem10 9
  #define mem11 10
  #define mem12 11
#endif //#if defined(FEATURE_4x4_KEYPAD) || defined(FEATURE_3x4_KEYPAD)

#define initial_sidetone_mode 1            // Sidetone mode, 0=OFF, 1=ON, 2=PADDLE_ONLY

#define sd_card_spi_ss_line 4

#if defined(OPTION_DFROBOT_LCD_COMMAND_BUTTONS)

  // For V1.1 board use these values
  #define dfrobot_btnRIGHT_analog 50
  #define dfrobot_btnUP_analog 250
  #define dfrobot_btnDOWN_analog 450
  #define dfrobot_btnLEFT_analog 650
  #define dfrobot_btnSELECT_analog 850  

  // For V1.0 board use these values
  // #define dfrobot_btnRIGHT_analog 50
  // #define dfrobot_btnUP_analog 195
  // #define dfrobot_btnDOWN_analog 380
  // #define dfrobot_btnLEFT_analog 555
  // #define dfrobot_btnSELECT_analog 790  
  
  // button to memory mappings (0 = command button, 1 = memory 1, 2 = memory 2, etc.)
  #define dfrobot_btnRIGHT  2
  #define dfrobot_btnUP     1
  #define dfrobot_btnDOWN   3
  #define dfrobot_btnLEFT   4
  #define dfrobot_btnSELECT 0
  #define dfrobot_btnNONE   255 // do not change

#endif

#define sequencer_pins_active_state HIGH
#define sequencer_pins_inactive_state LOW
#define ptt_line_active_state HIGH
#define ptt_line_inactive_state LOW
#define tx_key_line_active_state HIGH
#define tx_key_line_inactive_state LOW
#define ptt_input_pin_active_state LOW
#define ptt_input_pin_inactive_state HIGH
#define tx_inhibit_pin_active_state LOW
#define tx_inhibit_pin_inactive_state HIGH
#define tx_pause_pin_active_state LOW
#define tx_pause_pin_inactive_state HIGH
#define sidetone_line_active_state HIGH
#define sidetone_line_inactive_state LOW

#if defined(ARDUINO_MAPLE_MINI)
  #define button_value_factor 4095  //sp5iou contributed
#else
  #define button_value_factor 1023
#endif

#define farnsworth_timing_calibration 1.15

#define sidetone_volume_low_limit 10
#define sidetone_volume_high_limit 500

#define custom_startup_field "your custom text here"   // an example could be callsign and name, eg. "AB1XYZ Bob", (or "Worlds best operator" which requires a 20 column display), string length shouldo be no more than the number of columns on the display

#define command_mode_acknowledgement_character 'R'

#if defined(FEATURE_COMMAND_MODE_ENHANCED_CMD_ACKNOWLEDGEMENT)
  #define command_a_iambic_a "A"
  #define command_b_iambic_b "B"
  #define command_c_single_paddle "SINGLE"
  #define command_d_ultimatic "ULT"
  #define command_h_weight_dit_dah_ratio_default "R"
  #define command_i_tx_on  "TX ON"
  #define command_i_tx_off "TX OFF"
  #define command_k_dit_dah_buffers_on "ON"
  #define command_k_dit_dah_buffers_off "OFF"
  #define command_n_paddle_reverse "REV"
  #define command_n_paddle_normal "NORM"
  #define command_o_sidetone_off "ST OFF"
  #define command_o_sidetone_paddle_only "ST PD ONLY"
  #define command_o_sidetone_on "ST ON"
  #define command_t_tune_mode "TUNE"
  #define command_v_potentiometer_on "POT ON"
  #define command_v_potentiometer_off "POT OFF"

  #define command_error "ERR"

#endif //FEATURE_COMMAND_MODE_ENHANCED_CMD_ACKNOWLEDGEMENT

#define HI_TEXT "HI"  // Must be in UPPER case
