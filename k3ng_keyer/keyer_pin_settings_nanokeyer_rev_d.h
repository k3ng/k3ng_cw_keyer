#ifndef keyer_pin_settings_h
#define keyer_pin_settings_h

#define paddle_left 2
#define paddle_right 5
#define tx_key_line_1 11        // (high = key down/tx on)
#define tx_key_line_2 0        // nanoKeyer PTT port (Pin 13) may be used as 2nd keying line for SO2R
#define tx_key_line_3 0
#define tx_key_line_4 0
#define tx_key_line_5 0
#define tx_key_line_6 0
#define sidetone_line 4         // connect a speaker for sidetone
#define potentiometer A0        // Rev D nanoKeyer
#define ptt_tx_1 13             // nanoKeyer PTT port (uncomment if using above as 2nd CW port for SO2R operation)
#define ptt_tx_2 0              // Can be used for keying fox transmitter, T/R switch, or keying slow boatanchors
#define ptt_tx_3 0              // These are optional - set to 0 if unused
#define ptt_tx_4 0
#define ptt_tx_5 0
#define ptt_tx_6 0
#define analog_buttons_pin A1   // Rev D nanokeyer
#define lcd_rs A2
#define lcd_enable 10
#define lcd_d4 6
#define lcd_d5 7
#define lcd_d6 8
#define lcd_d7 9
#define ps2_keyboard_data A3    // Rev D nanokeyer
#define ps2_keyboard_clock 3
#define tx_key_dit 0            // if defined, goes active for dit (any transmitter) - customized with tx_key_dit_and_dah_pins_active_state and tx_key_dit_and_dah_pins_inactive_state
#define tx_key_dah 0            // if defined, goes active for dah (any transmitter) - customized with tx_key_dit_and_dah_pins_active_state and tx_key_dit_and_dah_pins_inactive_state

#define potentiometer_enable_pin 0  // if defined, the potentiometer will be enabled only when this pin is held low; set to 0 to ignore this pin

#if defined(FEATURE_SLEEP)
  #define keyer_awake 13       // Goes active when keyer is awake, inactive when in sleep mode; change active and inactive states in keyer_settings file
#endif

#if defined(FEATURE_LCD_BACKLIGHT_AUTO_DIM)
  #define keyer_power_led 0   // must be a PWM-capable pin
#endif

#if defined(FEATURE_CAPACITIVE_PADDLE_PINS)
  #define capactive_paddle_pin_inhibit_pin 0     // if this pin is defined and is set high, the capacitive paddle pins will switch to normal (non-capacitive) sensing mode
#endif

/*
FEATURE_SIDETONE_SWITCH
  Enabling this feature and an external toggle switch  adds switch control for playing cw sidetone.
  ST Switch status is displayed in the status command.  This feature will override the software control of the sidetone (\o).
  Arduino pin is assigned by SIDETONE_SWITCH 
*/

#ifdef FEATURE_SIDETONE_SWITCH
  #define SIDETONE_SWITCH 8
#endif //FEATURE_SIDETONE_SWITCH

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
