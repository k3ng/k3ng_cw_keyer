# Adafruit_LiquidCrystal

This library has been renamed Adafruit_LiquidCrystal so as not to conflict with LiquidCrystal. Also, it now works with tiny85's if you have Adafruit AVR board pkg 1.4.3+

<!-- START COMPATIBILITY TABLE -->

## Compatibility

MCU               | Tested Works | Doesn't Work | Not Tested  | Notes
----------------- | :----------: | :----------: | :---------: | -----
Atmega328 @ 16MHz |      X       |             |            | 
Atmega328 @ 12MHz |      X       |             |            | For SPI, Pro Trinket has no pin 2, can move to pin 5.
Atmega32u4 @ 16MHz |      X       |             |            | 
Atmega32u4 @ 8MHz |      X       |             |            | 
ESP8266           |      X       |             |            | For SPI, ESP8266 has no pin 3, moved to pin 5.
Atmega2560 @ 16MHz |      X       |             |            | 
ATSAM3X8E         |      X       |             |            | 
ATSAM21D          |             |      X       |            | I2C works, use SDA and SCL pins. For SPI, LCD blinks once on start up.
ATtiny85 @ 16MHz  |             |      X       |            | Use TinyLiquidCrystal libray instead: https://github.com/adafruit/TinyLiquidCrystal

I2C uses SDA &amp; SCL pins 0 &amp; 2
ATtiny85 @ 8MHz   |             |      X       |            | Use TinyLiquidCrystal libray instead: https://github.com/adafruit/TinyLiquidCrystal

I2C uses SDA &amp; SCL pins 0 &amp; 2

  * ATmega328 @ 16MHz : Arduino UNO, Adafruit Pro Trinket 5V, Adafruit Metro 328, Adafruit Metro Mini
  * ATmega328 @ 12MHz : Adafruit Pro Trinket 3V
  * ATmega32u4 @ 16MHz : Arduino Leonardo, Arduino Micro, Arduino Yun, Teensy 2.0
  * ATmega32u4 @ 8MHz : Adafruit Flora, Bluefruit Micro
  * ESP8266 : Adafruit Huzzah
  * ATmega2560 @ 16MHz : Arduino Mega
  * ATSAM3X8E : Arduino Due
  * ATSAM21D : Arduino Zero, M0 Pro
  * ATtiny85 @ 16MHz : Adafruit Trinket 5V
  * ATtiny85 @ 8MHz : Adafruit Gemma, Arduino Gemma, Adafruit Trinket 3V

<!-- END COMPATIBILITY TABLE -->
