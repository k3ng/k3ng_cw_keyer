#include <ST7032_asukiaaa.h>

ST7032_asukiaaa lcd;

void setup() {
  lcd.begin(16, 2); // columns and rows

  lcd.setContrast(30);
  // If lcd become black, try reduced value for contrast
  // lcd.setContrast(10);

  lcd.print("hello!");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(millis()/1000);
}
