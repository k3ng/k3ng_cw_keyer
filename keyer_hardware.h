/*  keyer_hardware.h


  Use this file to enable specific hardware and feature configurations.

  When enabling a hardware option below, the standard keyer_pin_settings.h, keyer_features_and_options.h, and keyer_settings.h files are not compiled.
  See the comments on each line to see what files are used.


*/

//#define HARDWARE_NANOKEYER_REV_B   // files: keyer_pin_settings_nanokeyer_rev_b.h, keyer_features_and_options_nanokeyer_rev_b.h, keyer_settings_nanokeyer_rev_b.h




// do not touch anything below this line

#if defined(HARDWARE_NANOKEYER_REV_B)
#define HARDWARE_CUSTOM
#endif