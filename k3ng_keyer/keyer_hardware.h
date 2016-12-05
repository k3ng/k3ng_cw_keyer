/*  keyer_hardware.h


  Use this file to enable specific hardware and feature configurations.

  When enabling a hardware option below, the standard keyer_pin_settings.h, keyer_features_and_options.h, and keyer_settings.h files are not compiled.
  See the comments on each line to see what files are used.


*/

// #define HARDWARE_NANOKEYER_REV_B   // https://nanokeyer.wordpress.com/nanokeyer-info/  files: keyer_pin_settings_nanokeyer_rev_b.h, keyer_features_and_options_nanokeyer_rev_b.h, keyer_settings_nanokeyer_rev_b.h
// #define HARDWARE_NANOKEYER_REV_D   // https://nanokeyer.wordpress.com/nanokeyer-info/  files: keyer_pin_settings_nanokeyer_rev_d.h, keyer_features_and_options_nanokeyer_rev_d.h, keyer_settings_nanokeyer_rev_d.h  
// #define HARDWARE_OPEN_INTERFACE   // http://remoteqth.com/open-interface.php   files: keyer_pin_settings_open_interface.h, keyer_features_and_options_open_interface.h, keyer_settings_open_interface.h   
// #define HARDWARE_TINYKEYER   // http://www.ok1rr.com/index.php/technical-topics/122-the-tinykeyer   files: keyer_pin_settings_tinykeyer_rev_d.h, keyer_features_and_options_tinykeyer_rev_d.h, keyer_settings_tinykeyer_rev_d.h
// #define HARDWARE_TEST

// Note: it is no longer necessary to uncomment HARDWARE_ARDUINO_DUE to compile for the Arduino Due


// do not touch anything below this line

#if defined(HARDWARE_NANOKEYER_REV_B) || defined(HARDWARE_NANOKEYER_REV_D) || defined(HARDWARE_OPEN_INTERFACE) || defined(HARDWARE_TINYKEYER) || defined(HARDWARE_TEST)
  #define HARDWARE_CUSTOM
#endif

// Serial port class definitions for various devices


#if defined(ARDUINO_MAPLE_MINI)
  #define PRIMARY_SERIAL_CLS USBSerial
  #define SECONDARY_SERIAL_CLS USBSerial 
#elif defined(ARDUINO_AVR_PROMICRO) || defined(ARDUINO_AVR_LEONARDO) || defined(ARDUINO_AVR_MICRO) || defined(ARDUINO_AVR_YUN) || defined(ARDUINO_AVR_ESPLORA) || defined(ARDUINO_AVR_LILYPAD_USB) || defined(ARDUINO_AVR_ROBOT_CONTROL) || defined(ARDUINO_AVR_ROBOT_MOTOR)
  #define PRIMARY_SERIAL_CLS Serial_
  #define SECONDARY_SERIAL_CLS Serial_ 
#elif defined(TEENSYDUINO)
  #define PRIMARY_SERIAL_CLS usb_serial_class
  #define SECONDARY_SERIAL_CLS usb_serial_class
#else
  #define PRIMARY_SERIAL_CLS HardwareSerial
  #define SECONDARY_SERIAL_CLS HardwareSerial 
#endif
  
 // for &Serial1

