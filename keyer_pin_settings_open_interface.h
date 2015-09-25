// This file is for the Open Interface http://remoteqth.com/open-interface.php

/* Pins - you must review these and configure ! */
#ifndef keyer_pin_settings_h
#define keyer_pin_settings_h

#define paddle_left 2
#define paddle_right 5
#define tx_key_line_1 11       // (high = key down/tx on)
#define tx_key_line_2 12
#define tx_key_line_3 0
#define tx_key_line_4 0
#define tx_key_line_5 0
#define tx_key_line_6 0
#define sidetone_line 4         // connect a speaker for sidetone
#define potentiometer A0        // Speed potentiometer (0 to 5 V) Use pot from 1k to 10k
#define ptt_tx_1 0              // PTT ("push to talk") lines
#define ptt_tx_2 0              //   Can be used for keying fox transmitter, T/R switch, or keying slow boatanchors
#define ptt_tx_3 0              //   These are optional - set to 0 if unused
#define ptt_tx_4 0
#define ptt_tx_5 0
#define ptt_tx_6 0
#define tx_key_dit 0            // if defined, goes high for dit (any transmitter)
#define tx_key_dah 0            // if defined, goes high for dah (any transmitter)

#ifdef FEATURE_COMMAND_BUTTONS
	#define analog_buttons_pin A1
	#define command_mode_active_led 0
#endif //FEATURE_COMMAND_BUTTONS

//lcd pins
#ifdef FEATURE_LCD_4BIT
	#define lcd_rs A2
	#define lcd_enable 10
	#define lcd_d4 6
	#define lcd_d5 7
	#define lcd_d6 8
	#define lcd_d7 9
#endif //FEATURE_LCD_4BIT

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

#ifdef FEATURE_ALPHABET_SEND_PRACTICE
	#define correct_answer_led 0
	#define wrong_answer_led 0
#endif //FEATURE_ALPHABET_SEND_PRACTICE

#ifdef FEATURE_PTT_INTERLOCK
	#define ptt_interlock 0  // this pin disables PTT and TX KEY
#endif //FEATURE_PTT_INTERLOCK


#ifdef FEATURE_CW_DECODER
  #define cw_decoder_pin A11 //A5 //A3  
  #ifdef OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR
    #define cw_decoder_audio_input_pin 0 // this must be an analog pin!
  #endif //OPTION_CW_DECODER_GOERTZEL_AUDIO_DETECTOR
  #define cw_decoder_indicator 24
#endif //FEATURE_CW_DECODER

#if defined(FEATURE_COMPETITION_COMPRESSION_DETECTION)
  #define compression_detection_pin 0
#endif //FEATURE_COMPETITION_COMPRESSION_DETECTION

#endif //keyer_pin_settings_h

