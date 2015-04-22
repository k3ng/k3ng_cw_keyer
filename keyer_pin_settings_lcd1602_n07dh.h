// This file is for the LinkSprite SHD_LCD_1602 Rev A and Rev B Arduino shield
// also sold as Maplin N07DH in the UK
// http://linksprite.com/wiki/index.php5?title=16_X_2_LCD_Keypad_Shield_for_Arduino

/* Pins - you must review these and configure ! */
#ifndef keyer_pin_settings_h
#define paddle_left 2
#define paddle_right 3
#define tx_key_line_1 11       // (high = key down/tx on)
#define tx_key_line_2 12
#define tx_key_line_3 0
#define tx_key_line_4 0
#define tx_key_line_5 0
#define tx_key_line_6 0
#define sidetone_line 10         // connect a speaker for sidetone
#define potentiometer A1        // Speed potentiometer (0 to 5 V) Use pot from 1k to 10k
#define ptt_tx_1 0              // PTT ("push to talk") lines
#define ptt_tx_2 0              //   Can be used for keying fox transmitter, T/R switch, or keying slow boatanchors
#define ptt_tx_3 0              //   These are optional - set to 0 if unused
#define ptt_tx_4 0
#define ptt_tx_5 0
#define ptt_tx_6 0
#define cw_decoder_pin A5 //A3
#define tx_key_dit 0            // if defined, goes high for dit (any transmitter)
#define tx_key_dah 0            // if defined, goes high for dah (any transmitter)

#ifdef FEATURE_COMMAND_BUTTONS
#define analog_buttons_pin A0
#define command_mode_active_led 0
#endif //FEATURE_COMMAND_BUTTONS


//lcd pins
#ifdef FEATURE_LCD_4BIT
#define lcd_rs 8
#define lcd_enable 9
#define lcd_d4 4
#define lcd_d5 5
#define lcd_d6 6
#define lcd_d7 7
#endif //FEATURE_LCD_4BIT
#endif //keyer_pin_settings_h

//ps2 keyboard pins
#ifdef FEATURE_PS2_KEYBOARD
#define ps2_keyboard_data A3
#define ps2_keyboard_clock 3    // this must be on an interrupt capable pin!
#endif //FEATURE_PS2_KEYBOARD

#ifdef FEATURE_ALPHABET_SEND_PRACTICE
#define correct_answer_led 0
#define wrong_answer_led 0
#endif //FEATURE_ALPHABET_SEND_PRACTICE

#ifdef FEATURE_PTT_INTERLOCK
#define ptt_interlock 0  // this pin disables PTT and TX KEY
#endif //FEATURE_PTT_INTERLOCK

