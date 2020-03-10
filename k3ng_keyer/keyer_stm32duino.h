/*  keyer_stm32fduino.h


  Use this file to enables clean compilation using the STM32duino board support for STM32 ARM
  processors. This requires the installation of https://github.com/rogerclarkmelbourne/Arduino_STM32
  
  For more information about STM32duino visit the primary support forum: http://www.stm32duino.com/

*/

  void initialize_pins(void);
  void initialize_keyer_state(void);
  void initialize_potentiometer(void);
  void initialize_rotary_encoder(void);
  void initialize_default_modes(void);
  void initialize_watchdog(void);
  void initialize_ethernet_variables(void);
  void check_eeprom_for_initialization(void);
  void check_for_beacon_mode(void);
  void check_for_debug_modes(void);
  void initialize_analog_button_array(void);
  void initialize_serial_ports(void);
  void initialize_ps2_keyboard(void);
  void initialize_usb(void);
  void initialize_cw_keyboard(void);
  void initialize_display(void);
  void initialize_ethernet(void);
  void initialize_udp(void);
  void initialize_web_server(void);
  void initialize_debug_startup(void);
  
  void check_paddles(void);
  void service_dit_dah_buffers(void);
  void service_send_buffer(byte);
  void check_ptt_tail(void);
  void check_for_dirty_configuration(void);
  void tone(uint32_t, uint32_t, uint32_t);
  void noTone(uint32_t);
  void serial_status(PRIMARY_SERIAL_CLS*);
