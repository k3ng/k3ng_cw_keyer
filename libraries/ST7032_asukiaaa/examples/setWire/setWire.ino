#include <ST7032_asukiaaa.h>

ST7032_asukiaaa lcd;

void setup() {
#if defined(ESP32)
  Wire.begin(21, 22); // SDA, SCL
  lcd.setWire(&Wire);
#endif
  lcd.begin(16, 2);
  lcd.setContrast(30);
  lcd.print("hello, world!");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(millis()/1000);
}
