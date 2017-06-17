// Initial and hardcoded settings
#define initial_speed_wpm 26             // "factory default" keyer speed setting
#define initial_sidetone_freq 600        // "factory default" sidetone frequency setting
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
#define memory_area_start 30             // the eeprom location where memory space starts
#define memory_area_end 1023             // the eeprom location where memory space ends
#define winkey_c0_wait_time 1            // the number of milliseconds to wait to send 0xc0 byte after send buffer has been sent
#define winkey_command_timeout_ms 5000
#define winkey_discard_bytes_startup 3   // this is used if OPTION_WINKEY_DISCARD_BYTES_AT_STARTUP is enabled above
#define winkey_xoff_threshold 20         // the number of chars in the buffer when we begin sending XOFFs
#define winkey_xon_threshold 10          // the number of chars in the buffer below which we deactivate XOFF
#define default_memory_repeat_time 3000  // time in milliseconds
#define LCD_COLUMNS 20
#define LCD_ROWS 4
#define hell_pixel_microseconds 4025
#define program_memory_limit_consec_spaces 1
#define serial_leading_zeros 1            // set to 1 to activate leading zeros in serial numbers (i.e. #1 = 001)
#define serial_cut_numbers 0              // set to 1 to activate cut numbers in serial numbers (i.e. #10 = 1T, #19 = 1N)
#define go_to_sleep_inactivity_time 10    // minutes - FEATURE_SLEEP
#define default_cmos_super_keyer_iambic_b_timing_percent 33 // use with FEATURE_CMOS_SUPER_KEYER_IAMBIC_B_TIMING; should be between 0 to 99 % (0% = true iambic b;100% = iambic a behavior)
#define cw_echo_timing_factor 0.25
#define potentiometer_always_on 1
#define ptt_interlock_check_every_ms 100
#define ptt_interlock_active_state HIGH
#define unknown_cw_character '*'
#define cli_paddle_echo_on_at_boot 1
#define cli_straight_key_echo_on_at_boot 1
#define tx_key_dit_and_dah_pins_active_state HIGH
#define tx_key_dit_and_dah_pins_inactive_state LOW
#define potentiometer_check_interval_ms 150
#define default_paddle_interruption_quiet_time_element_lengths 0
#define default_wordsworth_wordspace 6
#define default_wordsworth_repetition 1
#define serial_program_memory_buffer_size 500


#ifdef FEATURE_COMMAND_BUTTONS
  #define analog_buttons_number_of_buttons 5
  #define analog_buttons_r1 10
  #define analog_buttons_r2 1
#endif


#if defined(FEATURE_COMMAND_BUTTONS) &&  !defined(FEATURE_PS2_KEYBOARD) && !defined(FEATURE_USB_KEYBOARD) && !defined(FEATURE_COMMAND_LINE_INTERFACE) && !defined(FEATURE_WINKEY_EMULATION)
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
  #ifdef OPTION_WINKEY_UCXLOG_9600_BAUD
    #define WINKEY_DEFAULT_BAUD 9600
  #else
    #define WINKEY_DEFAULT_BAUD 1200
  #endif //OPTION_WINKEY_UCXLOG_9600_BAUD
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

#endif //FEATURE_WINKEY_EMULATION


#define PRIMARY_SERIAL_PORT &Serial
#define PRIMARY_SERIAL_PORT_BAUD 115200     // This applies only when the port is in Command Line Interface mode.  In Winkey mode it will default to 1200.

#ifdef FEATURE_COMMAND_LINE_INTERFACE_ON_SECONDARY_PORT
  #define SECONDARY_SERIAL_PORT &Serial1
  #define SECONDARY_SERIAL_PORT_BAUD 115200
#endif

#define CW_DECODER_SCREEN_COLUMNS 40        // word wrap at this many columns
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

#if defined(FEATURE_ETHERNET)
  // #define FEATURE_ETHERNET_IP {192,168,1,178}                      // default IP address ("192.168.1.178")
  // #define FEATURE_ETHERNET_MAC {0xDE,0xAD,0xBE,0xEF,0xFE,0xED}
  #define FEATURE_ETHERNET_IP {192,168,1,179}                      // default IP address ("192.168.1.178")
  #define FEATURE_ETHERNET_MAC {0xDE,0xAD,0xBE,0xEF,0xFE,0xEE}

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
