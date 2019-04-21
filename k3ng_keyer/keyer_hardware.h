/*  keyer_hardware.h


  Edit this file to enable specific hardware profiles.

  When enabling a hardware option below, the default keyer_pin_settings.h, keyer_features_and_options.h, and keyer_settings.h files are not compiled.

  See the comments on each line to determine what files are compiled and should be customized.

*/

// #define HARDWARE_NANOKEYER_REV_B   // https://nanokeyer.wordpress.com/nanokeyer-info/  edit these files: keyer_pin_settings_nanokeyer_rev_b.h, keyer_features_and_options_nanokeyer_rev_b.h, keyer_settings_nanokeyer_rev_b.h
// #define HARDWARE_NANOKEYER_REV_D   // https://nanokeyer.wordpress.com/nanokeyer-info/  edit these files: keyer_pin_settings_nanokeyer_rev_d.h, keyer_features_and_options_nanokeyer_rev_d.h, keyer_settings_nanokeyer_rev_d.h  
// #define HARDWARE_OPEN_INTERFACE   // http://remoteqth.com/open-interface.php   edit these files: keyer_pin_settings_open_interface.h, keyer_features_and_options_open_interface.h, keyer_settings_open_interface.h   
// #define HARDWARE_TINYKEYER   // http://www.ok1rr.com/index.php/technical-topics/122-the-tinykeyer   edit these files: keyer_pin_settings_tinykeyer.h, keyer_features_and_options_tinykeyer.h, keyer_settings_tinykeyer.h
// #define HARDWARE_FK_10  // Funtronics K3NG Keyer FK-10  - See notes below!!!  http://www.elekitsorparts.com/product/funtronics-k3ng-keyer-fk-10-99-winkey-emulation/   files: keyer_pin_settings_fk_10.h, keyer_features_and_options_fk_10.h, keyer_settings_fk_10.h
// #define HARDWARE_MAPLE_MINI  // edit these files: keyer_pin_settings_maple_mini.h, keyer_settings_maple_mini.h, keyer_features_and_options_maple_mini.h
// #define HARDWARE_GENERIC_STM32F103C  // edit these files: keyer_pin_settings_generic_STM32F103C.h, keyer_settings_generic_STM32F103C.h, keyer_features_and_options_generic_STM32F103C.h //sp5iou 20180329
// #define HARDWARE_MORTTY  // edit these files: keyer_pin_settings_mortty.h, keyer_settings_mortty.h, keyer_features_and_options_mortty.h
// #define HARDWARE_YAACWK   // http://i1cra.briata.org/yaacwk/  files: keyer_pin_settings_yaacwk.h, keyer_features_and_options_yaacwk.h, keyer_settings_yaacwk.h
// #define HARDWARE_K5BCQ   // edit these files: keyer_pin_settings_k5bcq.h, keyer_features_and_options_k5bcq.h, keyer_settings_k5bcq.h  
// #define HARDWARE_TEST_EVERYTHING
// #define HARDWARE_TEST


/* 


    HARDWARE_GENERIC_STM32F103C  (Contributed by sp5iou)

      How to deal with those boards with Arduino: https://www.techshopbd.com/uploads/product_document/STM32bluepillarduinoguide(1).pdf


    Funtronics FK-10 Programming Notes (Contributed by Disneysw 2016-12-10)

      Programming the unit is accomplished by selecting "Mega2560" as the target processor and uploading to the rear USB port with the front
      switch set to the Arduino position

      Note: in order to get the FK-10 USB Host port working correctly you will need to patch the file "UsbCore.h" in the USB_Host_Shield library.
      At the time of writing it is line 41 that needs modified to change "P10" to "P53" i.e. from

           #else
             typedef MAX3421e<P10, P9> MAX3421E; // Official Arduinos (UNO, Duemilanove, Mega, 2560, Leonardo, Due etc.) or Teensy 2.0 and 3.0
           #endif

      to:

           #else
             typedef MAX3421e<P53, P9> MAX3421E; // Official Arduinos (UNO, Duemilanove, Mega, 2560, Leonardo, Due etc.) or Teensy 2.0 and 3.0
           #endif


*/


// Do not touch anything below this line!
// Serial port class definitions for various devices

#if defined(ARDUINO_MAPLE_MINI)||defined(ARDUINO_GENERIC_STM32F103C) //sp5iou 20180329
  #define PRIMARY_SERIAL_CLS USBSerial
  #define SECONDARY_SERIAL_CLS USBSerial 
#elif defined(ARDUINO_AVR_PROMICRO) || defined(ARDUINO_AVR_LEONARDO) || defined(ARDUINO_AVR_MICRO) || defined(ARDUINO_AVR_YUN) || defined(ARDUINO_AVR_ESPLORA) || defined(ARDUINO_AVR_LILYPAD_USB) || defined(ARDUINO_AVR_ROBOT_CONTROL) || defined(ARDUINO_AVR_ROBOT_MOTOR) || defined(ARDUINO_AVR_LEONARDO_ETH)
  #define PRIMARY_SERIAL_CLS Serial_
  #define SECONDARY_SERIAL_CLS Serial_ 
#elif defined(TEENSYDUINO)
  #define PRIMARY_SERIAL_CLS usb_serial_class
  #define SECONDARY_SERIAL_CLS usb_serial_class
#else
  #define PRIMARY_SERIAL_CLS HardwareSerial
  #define SECONDARY_SERIAL_CLS HardwareSerial 
#endif
  
