/*  keyer_hardware.h


  Use this file to enable specific hardware and feature configurations.

  When enabling a hardware option below, the standard keyer_pin_settings.h, keyer_features_and_options.h, and keyer_settings.h files are not compiled.
  See the comments on each line to see what files are used.


*/

//#define HARDWARE_NANOKEYER_REV_B   // https://nanokeyer.wordpress.com/nanokeyer-info/  files: keyer_pin_settings_nanokeyer_rev_b.h, keyer_features_and_options_nanokeyer_rev_b.h, keyer_settings_nanokeyer_rev_b.h
//#define HARDWARE_NANOKEYER_REV_D   // https://nanokeyer.wordpress.com/nanokeyer-info/  files: keyer_pin_settings_nanokeyer_rev_d.h, keyer_features_and_options_nanokeyer_rev_d.h, keyer_settings_nanokeyer_rev_d.h  
//#define HARDWARE_OPEN_INTERFACE   // http://remoteqth.com/open-interface.php   files: keyer_pin_settings_open_interface.h, keyer_features_and_options_open_interface.h, keyer_settings_open_interface.h
//#define HARDWARE_ARDUINO_DUE   



// do not touch anything below this line

#if defined(HARDWARE_NANOKEYER_REV_B) || defined(HARDWARE_NANOKEYER_REV_D) || defined(HARDWARE_OPEN_INTERFACE)
  #define HARDWARE_CUSTOM
#endif
