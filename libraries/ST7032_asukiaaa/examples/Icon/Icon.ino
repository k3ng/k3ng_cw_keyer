/*
  ST7032 I2C LCD Controler - Icon Display Example
  2013/05/11 tomozh@gmail.com
  
 ------------------------
  Arduino        ST7032
 ------------------------
  3.3V    --+-- VDD
            +-- RST
  A4(SDA) --*-- SDA
  A5(SCL) --*-- SCL
  GND     ----- GND
  
  *... 10Kohm pull-up
 ------------------------
*/

#include <ST7032_asukiaaa.h>


#define NELEMS(arg) (sizeof(arg) / sizeof((arg)[0]))

typedef struct tagICON_MAP {
  byte addr;
  byte pat;
}ICON_MAP;

static const ICON_MAP iconMap[] = {
  { 0x00, (1<<4) },    // 0
  { 0x02, (1<<4) },    // 1
  { 0x04, (1<<4) },    // 2
  { 0x06, (1<<4) },    // 3
  { 0x07, (1<<4) },    // 4
  { 0x07, (1<<3) },    // 5
  { 0x09, (1<<4) },    // 6
  { 0x0B, (1<<4) },    // 7
  { 0x0D, (1<<4) },    // 8
  { 0x0D, (1<<3) },    // 9
  { 0x0D, (1<<2) },    // 10
  { 0x0D, (1<<1) },    // 11
  { 0x0F, (1<<4) },    // 12
};

static byte iconTmp[16];
bool showIcon = true;
ST7032_asukiaaa lcd;

static void setIndexedIcon(uint8_t index, bool show) {
  if((0 <= index) && (index < NELEMS(iconMap))) {
    const ICON_MAP* pMap = &iconMap[index];
    byte* pTmp = &iconTmp[pMap->addr];
    
    if(show) {
      *pTmp |= pMap->pat;
    } else {
      *pTmp &= ~pMap->pat;
    }
    
    lcd.setIcon(pMap->addr, *pTmp);
  }
}

void setup(){
  lcd.begin(16, 2, LCD_5x8DOTS);
  lcd.setContrast(30);
  lcd.print("ST7032 ICON TEST");
}

void loop(){
  int i;

  for(i = 0; i < NELEMS(iconMap); i++) {
    setIndexedIcon(i, showIcon);
    lcd.setCursor(0, 1);
    lcd.print("No.");
    lcd.print(i);
    lcd.print("  ");
    
    delay(500);
  }
  
  while(1){}
  
  showIcon = !showIcon;
}
