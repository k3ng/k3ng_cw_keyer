// features & options for TinyKeyer by OK1RR
#ifndef keyer_pin_settings_h
#define keyer_pin_settings_h

#define paddle_left 2          // dit
#define paddle_right 5         // dah
#define tx_key_line_1 12       // tinykeyer keyed port (high = key down/tx on)
#define tx_key_line_2 0
#define tx_key_line_3 0
#define tx_key_line_4 0
#define tx_key_line_5 0
#define tx_key_line_6 0
#define sidetone_line 4         // connect a speaker for sidetone
#define potentiometer 0         // tinykeyer no pot used
#define ptt_tx_1 0              // (put 13 instead 0 to activate) tinykeyer PTT port (high = PTT down/PTT on)
#define ptt_tx_2 0              // Can be used for keying fox transmitter, T/R switch, or keying slow boatanchors
#define ptt_tx_3 0              // These are optional - set to 0 if unused
#define ptt_tx_4 0
#define ptt_tx_5 0
#define ptt_tx_6 0
#define analog_buttons_pin A1   // tinykeyer
#define command_mode_active_led 9  // tinykeyer - command mode LED indicator
#define tx_key_dit 0            // if defined, goes active for dit (any transmitter) - customized with tx_key_dit_and_dah_pins_active_state and tx_key_dit_and_dah_pins_inactive_state
#define tx_key_dah 0            // if defined, goes active for dah (any transmitter) - customized with tx_key_dit_and_dah_pins_active_state and tx_key_dit_and_dah_pins_inactive_state

// rotary encoder pins and options - rotary encoder code from Jim Balls M0CKE
#ifdef FEATURE_ROTARY_ENCODER
  #define OPTION_ENCODER_HALF_STEP_MODE     // Half-step mode?
  #define rotary_pin1 11                    // CW Encoder Pin
  #define rotary_pin2 10                    // CCW Encoder Pin
  #define OPTION_ENCODER_ENABLE_PULLUPS     // define to enable weak pullups.
#endif //FEATURE_ROTARY_ENCODER

#if defined(FEATURE_SLEEP)
  #define keyer_awake 8       // Goes active when keyer is awake, inactive when in sleep mode; change active and inactive states in keyer_settings file
#endif

#else

  #error "Multiple pin_settings.h files included somehow..."

#endif //keyer_pin_settings_h