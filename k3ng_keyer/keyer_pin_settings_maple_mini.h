/*

                                                        
#    #      ##      #####     #         ######          #    #    #    #    #    # 
##  ##     #  #     #    #    #         #               ##  ##    #    ##   #    # 
# ## #    #    #    #    #    #         #####           # ## #    #    # #  #    # 
#    #    ######    #####     #         #               #    #    #    #  # #    # 
#    #    #    #    #         #         #               #    #    #    #   ##    # 
#    #    #    #    #         ######    ######          #    #    #    #    #    # 
                                                                                   

*/

/* Pins - you must review these and configure ! */
#ifndef keyer_pin_settings_h
#define keyer_pin_settings_h

#define paddle_left 10
#define paddle_right 11
#define tx_key_line_1 12       // (high = key down/tx on)
#define tx_key_line_2 15
#define tx_key_line_3 0
#define tx_key_line_4 0
#define tx_key_line_5 0
#define tx_key_line_6 0
//#define sidetone_line 8         // connect a speaker for sidetone
uint8_t sidetone_line = 8;        // sp5iou must be variable declaration instead of #define... for STM32 boards.
#define potentiometer 4        // Speed potentiometer (0 to 5 V) Use pot from 1k to 10k
#define ptt_tx_1 13              // PTT ("push to talk") lines
#define ptt_tx_2 16              //   Can be used for keying fox transmitter, T/R switch, or keying slow boatanchors
#define ptt_tx_3 0              //   These are optional - set to 0 if unused
#define ptt_tx_4 0
#define ptt_tx_5 0
#define ptt_tx_6 0
#define tx_key_dit 0            // if defined, goes active for dit (any transmitter) - customized with tx_key_dit_and_dah_pins_active_state and tx_key_dit_and_dah_pins_inactive_state
#define tx_key_dah 0            // if defined, goes active for dah (any transmitter) - customized with tx_key_dit_and_dah_pins_active_state and tx_key_dit_and_dah_pins_inactive_state

#define potentiometer_enable_pin 0  // if defined, the potentiometer will be enabled only when this pin is held low; set to 0 to ignore this pin

#ifdef FEATURE_BUTTONS
  #define analog_buttons_pin 3
  #define command_mode_active_led PB1
#endif //FEATURE_BUTTONS

/*
FEATURE_SIDETONE_SWITCH
  Enabling this feature and an external toggle switch  adds switch control for playing cw sidetone.
  ST Switch status is displayed in the status command.  This feature will override the software control of the sidetone (\o).
  Arduino pin is assigned by SIDETONE_SWITCH 
*/

#ifdef FEATURE_SIDETONE_SWITCH
  #define SIDETONE_SWITCH 0
#endif //FEATURE_SIDETONE_SWITCH


//lcd pins
#ifdef FEATURE_LCD_4BIT
  #define lcd_rs 17
  #define lcd_enable 18
  #define lcd_d4 19
  #define lcd_d5 20
  #define lcd_d6 21
  #define lcd_d7 22
#endif //FEATURE_LCD_4BIT

#if defined(FEATURE_LCD_8BIT) // addition four data lines for 8 bit LCD control
  #define lcd_d0 23
  #define lcd_d1 24
  #define lcd_d2 25
  #define lcd_d3 26
#endif //FEATURE_LCD_4BIT || defined(FEATURE_LCD_8BIT)

#ifdef FEATURE_LCD1602_N07DH
  #define lcd_rs 17
  #define lcd_enable 18
  #define lcd_d4 19
  #define lcd_d5 20
  #define lcd_d6 21
  #define lcd_d7 22
#endif //FEATURE_LCD1602_N07DH

//ps2 keyboard pins
#ifdef FEATURE_PS2_KEYBOARD
  #define ps2_keyboard_data A3 // for maple it can not be Ax - muste use pin numbers only or PBx, PCx etc... sp5iou
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
  #define keyer_awake 6
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

#define ptt_input_pin 0

#define tx_inhibit_pin 0
#define tx_pause_pin 0   

#define pin_sending_mode_automatic 0  // goes HIGH when keyer is sending code automatically
#define pin_sending_mode_manual 0     // goes HIGH when keyer is sending code manually (i.e. the paddle or straight key)

#else

  #error "Multiple pin_settings.h files included somehow..."

#endif //keyer_pin_settings_h

