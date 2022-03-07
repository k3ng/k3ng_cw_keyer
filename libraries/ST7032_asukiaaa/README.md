# ST7032_asukiaaa

A library to control ST7032 on a LiquidCrystal.
This library was forked from [tomozh/arduino_ST7032](https://github.com/tomozh/arduino_ST7032).

# Install

## Arduino IDE
You can install via library manager.
Search `ST7032` on the library manager

## PlatformIO

Add this library to dependencies on `platformio.ini`.
```
lib_deps =
  ST7032_asukiaaa
```

# Connection

ST7032 | Arduino
-------|--------
VDD | 3V3
RES | 3V3
SDA* | SDA(A4 for Uno)
SCL* | SCL(A5 for Uno)
GND | GND

*... 10Kohm pull-up is needed.

You can check SDA and SCL for your board on [Wire page](https://www.arduino.cc/en/reference/wire).

# Usage

## Hello world
See [HelloWorld](./examples/HelloWorld/HelloWorld.ino).

```c
#include <ST7032_asukiaaa.h>

ST7032_asukiaaa lcd;

void setup() {
  lcd.begin(16, 2); // LCD columns and rows.
  lcd.setContrast(40);
  // If lcd become black, reduced value for contrast
  // lcd.setContrast(10);
  lcd.print("hello, world!");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(millis()/1000);
}
```

## Set slave address
You can specify slave address for a LCD.

```c
ST7032_asukiaaa lcd(0x3E);
```

## Set wire
You can set customized wire.(See [setWire](./examples/setWire/setWire.ino))

```c
#if defined(ESP32)
  Wire.begin(25, 26); // SDA, SCL
  lcd.setWire(&Wire);
#endif
```

See [examples](./examples) to know other usage.

# License
MIT

# References
- [I2C液晶のArduinoライブラリ – ST7032](http://ore-kb.net/archives/195)
- [tomozh/arduino_ST7032](https://github.com/tomozh/arduino_ST7032)
