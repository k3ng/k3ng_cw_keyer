/*  keyer_hardware.h


  Use this file to enable specific hardware and feature configurations.

  When enabling a hardware option below, the standard keyer_pin_settings.h, keyer_features_and_options.h, and keyer_settings.h files are not compiled.
  See the comments on each line to see what files are used.


*/

// #define HARDWARE_NANOKEYER_REV_B   // https://nanokeyer.wordpress.com/nanokeyer-info/  files: keyer_pin_settings_nanokeyer_rev_b.h, keyer_features_and_options_nanokeyer_rev_b.h, keyer_settings_nanokeyer_rev_b.h
// #define HARDWARE_NANOKEYER_REV_D   // https://nanokeyer.wordpress.com/nanokeyer-info/  files: keyer_pin_settings_nanokeyer_rev_d.h, keyer_features_and_options_nanokeyer_rev_d.h, keyer_settings_nanokeyer_rev_d.h  
// #define HARDWARE_OPEN_INTERFACE   // http://remoteqth.com/open-interface.php   files: keyer_pin_settings_open_interface.h, keyer_features_and_options_open_interface.h, keyer_settings_open_interface.h
// #define HARDWARE_TEST

// The models which can compile this sketch without error, has these pre-defined macros. Not tested.
// ARDUINO_AVR_UNO
// ARDUINO_SAM_DUE
// ARDUINO_MAPLE_MINI // http://dan.drown.org/arduino/package_STM32duino_index.json
// ARDUINO_AVR_PROMICRO // https://raw.githubusercontent.com/sparkfun/Arduino_Boards/master/IDE_Board_Manager/package_sparkfun_index.json

// do not touch anything below this line

#if defined(HARDWARE_NANOKEYER_REV_B) || defined(HARDWARE_NANOKEYER_REV_D) || defined(HARDWARE_OPEN_INTERFACE) || defined(HARDWARE_TEST)
  #define HARDWARE_CUSTOM
#endif

#if defined(ARDUINO_MAPLE_MINI)
#define PRIMARY_SERIAL_CLS USBSerial // for &Serial
#elif defined(ARDUINO_AVR_PROMICRO)
#define PRIMARY_SERIAL_CLS Serial_ // for &Serial
#else
#define PRIMARY_SERIAL_CLS HardwareSerial // for &Serial
#endif
#define SECONDARY_SERIAL_CLS HardwareSerial  // for &Serial1
