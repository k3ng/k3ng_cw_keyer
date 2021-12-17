/* Pins - you must review these and configure ! */
#ifndef keyer_pin_settings_h
#define keyer_pin_settings_h

#define paddle_left 6
#define paddle_right 7

#define tx_key_line_1 5         // (high = key down/tx on)
#define tx_key_line_2 4
#define tx_key_line_3 0
#define tx_key_line_4 0
#define tx_key_line_5 0
#define tx_key_line_6 0
#define sidetone_line 0         // connect a buzzer for sidetone (optional, set to zero if not used)
#define potentiometer A7        // Speed potentiometer (0 to 5 V) Use pot from 1k to 10k
#define ptt_tx_1 3              // Radio 1 PTT ("push to talk") line
#define ptt_tx_2 2              // Radio 2 PTT ("push to talk") line
#define ptt_tx_3 0              //   These are optional - set to 0 if unused
#define ptt_tx_4 0
#define ptt_tx_5 0
#define ptt_tx_6 0
#define tx_key_dit 0            // if defined, goes active for dit (any transmitter) - customized with tx_key_dit_and_dah_pins_active_state and tx_key_dit_and_dah_pins_inactive_state
#define tx_key_dah 0            // if defined, goes active for dah (any transmitter) - customized with tx_key_dit_and_dah_pins_active_state and tx_key_dit_and_dah_pins_inactive_state

#define so2r_tx_1 0             // Radio 1 transmitter selected (optional, set to zero if not used)
#define so2r_tx_2 11            // Radio 2 transmitter selected (optional, set to zero if not used)
#define so2r_rx_1 0             // Radio 1 receiver selected (optional, set to zero if not used)
#define so2r_rx_2 0             // Radio 2 receiver selected (optional, set to zero if not used)
#define so2r_rx_1s 0            // Radio 1 receiver or stereo selected (optional, set to zero if not used)
#define so2r_rx_2s 9            // Radio 2 receiver or stereo selected (optional, set to zero if not used)
#define so2r_rx_s 10            // Stereo receive selected (optional, set to zero if not used)

#ifdef FEATURE_SO2R_SWITCHES
  #define so2r_tx_switch A5     // TX switch, low if TX1, high if TX2
  #define so2r_rx1_switch A4    // RX 1 switch, low if RX1, high if RX2 or stereo
  #define so2r_rx2_switch A3    // RX 2 switch, low if RX2, high if RX1 or stereo
#endif

#define potentiometer_enable_pin 0  // if defined, the potentiometer will be enabled only when this pin is held low; set to 0 to ignore this pin

#ifdef FEATURE_BUTTONS
  #define analog_buttons_pin A1
  #define command_mode_active_led 0
#endif //FEATURE_BUTTONS

/*
FEATURE_SIDETONE_SWITCH
  Enabling this feature and an external toggle switch  adds switch control for playing cw sidetone.
  ST Switch status is displayed in the status command.  This feature will override the software control of the sidetone (\o).
  Arduino pin is assigned by SIDETONE_SWITCH 
*/

#ifdef FEATURE_SIDETONE_SWITCH
  #define SIDETONE_SWITCH 8
#endif //FEATURE_SIDETONE_SWITCH


//lcd pins
#if defined(FEATURE_LCD_4BIT) || defined(FEATURE_LCD_8BIT)
  #define lcd_rs A2
  #define lcd_enable 10  // pin 10 is used by Ethernet shield and will conflict with that
  #define lcd_d4 6
  #define lcd_d5 7
  #define lcd_d6 8
  #define lcd_d7 9
#endif //FEATURE_LCD_4BIT || defined(FEATURE_LCD_8BIT)

#if defined(FEATURE_LCD_8BIT) // addition four data lines for 8 bit LCD control
  #define lcd_d0 20
  #define lcd_d1 21
  #define lcd_d2 22
  #define lcd_d3 23
#endif //FEATURE_LCD_4BIT || defined(FEATURE_LCD_8BIT)

#ifdef FEATURE_LCD1602_N07DH
  #define lcd_rs 8
  #define lcd_enable 9
  #define lcd_d4 4
  #define lcd_d5 5
  #define lcd_d6 6
  #define lcd_d7 7
#endif //FEATURE_LCD1602_N07DH

//ps2 keyboard pins
#ifdef FEATURE_PS2_KEYBOARD
  #define ps2_keyboard_data A3
  #define ps2_keyboard_clock 3    // this must be on an interrupt capable pin!
#endif //FEATURE_PS2_KEYBOARD

// rotary encoder pins and options - rotary encoder code from Jim Balls M0CKE
#ifdef FEATURE_ROTARY_ENCODER
  #define OPTION_ENCODER_HALF_STEP_MODE     // Half-step mode?
  #define rotary_pin1 0                      // CW Encoder Pin
  #define rotary_pin2 0                    // CCW Encoder Pin
  #define OPTION_ENCODER_ENABLE_PULLUPS     // define to enable weak pullups.
#endif //FEATURE_ROTARY_ENCODER

#ifdef FEATURE_LED_RING
  #define led_ring_sdi    A10 //2    //Data
  #define led_ring_clk    A9 //3    //Clock
  #define led_ring_le     A8 //4    //Latch
#endif //FEATURE_LED_RING

#define correct_answer_led 0
#define wrong_answer_led 0

#ifdef FEATURE_PTT_INTERLOCK
  #define ptt_interlock 0  // this pin disables PTT and TX KEY
#endif //FEATURE_PTT_INTERLOCK

#ifdef FEATURE_STRAIGHT_KEY
  #define pin_straight_key 52
#endif //FEATURE_STRAIGHT_KEY

// FEATURE_CW_DECODER & OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR
// See https://github.com/k3ng/k3ng_cw_keyer/wiki/385-Feature:-CW-Decoder for details
#define cw_decoder_pin 0             // This is for use with external decoding hardware
#define cw_decoder_audio_input_pin 0 // This is for audio detection decoding using OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR; this must be an analog pin!
#define cw_decoder_indicator 0       // Output - goes HIGH when cw tone is detected by OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR


#if defined(FEATURE_COMPETITION_COMPRESSION_DETECTION)
  #define compression_detection_pin 13
#endif //FEATURE_COMPETITION_COMPRESSION_DETECTION

#if defined(FEATURE_SLEEP)
  #define keyer_awake 0
#endif

#if defined(FEATURE_LCD_BACKLIGHT_AUTO_DIM)
  #define keyer_power_led 0   // must be a PWM-capable pin
#endif

#if defined(FEATURE_CAPACITIVE_PADDLE_PINS)
  #define capactive_paddle_pin_inhibit_pin 0     // if this pin is defined and is set high, the capacitive paddle pins will switch to normal (non-capacitive) sensing mode
#endif

#ifdef FEATURE_4x4_KEYPAD
  #define Row3 33
  #define Row2 32
  #define Row1 31
  #define Row0 30
  #define Col3 37
  #define Col2 36
  #define Col1 35
  #define Col0 34
#endif

#ifdef FEATURE_3x4_KEYPAD
  #define Row3 33
  #define Row2 32
  #define Row1 31
  #define Row0 30
  #define Col2 36
  #define Col1 35
  #define Col0 34
#endif

#ifdef FEATURE_SEQUENCER
  #define sequencer_1_pin 0
  #define sequencer_2_pin 0
  #define sequencer_3_pin 0
  #define sequencer_4_pin 0
  #define sequencer_5_pin 0
#endif //FEATURE_SEQUENCER

#define ptt_input_pin 8

#define tx_inhibit_pin 0
#define tx_pause_pin 0 

#define pin_sending_mode_automatic 0  // goes HIGH when keyer is sending code automatically
#define pin_sending_mode_manual 0     // goes HIGH when keyer is sending code manually (i.e. the paddle or straight key)

#else

  #error "Multiple pin_settings.h files included somehow..."

#endif //keyer_pin_settings_h
