/*
  Library created in February 2021
  by Arnaud Ouvrier (http://www.arnaudouvrier.fr)

  This is free and unencumbered software released into the public domain.
  For more information, see http://unlicense.org/ or
  the accompanying (un)LICENSE file

  https://github.com/arnakazim/TwiLiquidCrystal-library
*/

#ifndef TwiLiquidCrystal_h
#define TwiLiquidCrystal_h

#include <inttypes.h>
#include "Arduino.h"
#include "Wire.h"
#include "Print.h"

/*
 * Control bit defintions
 */

#define BL_BIT  0b00001000  // Backlight bit
#define EN_BIT  0b00000100  // Enable bit
#define RW_BIT  0b00000010  // Read/Write bit
#define RS_BIT  0b00000001  // Register select bit

#define DATA_PORTION 0b11110000 // D7 D6 D5 D4
#define CTRL_PORTION 0b00001111 // BL EN RW RS

#define LCD_5x10DOTS 1
#define LCD_5x8DOTS  0

/*
 * Command definitions
 * 
 * LCD_CLEARDISPLAY
 * LCD_RETURNHOME
 * LCD_ENTRYMODESET
 *   I/D = 1 -> Increment cursor pos
 *   S =   0 -> No shift
 * LCD_DISPLAYCONTROL
 *   D =   0 -> Display off
 *   C =   0 -> Cursor off
 *   B =   0 -> Blinking off
 * LCD_CURSORSHIFT
 *   S/C = 0 -> Shift cursor (1 for screen)
 *   R/L = 0 -> To the right
 * LCD_FUNCTIONSET
 *   DL =  1 -> 8-bit interface data
 *   N =   0 -> 1-line display
 *   F =   0 -> 5 × 8 dot character font
 * LCD_SETCGRAMADDR
 * LCD_SETDDRAMADDR
 */

#define LCD_CLEARDISPLAY    0b00000001 // 0   0   0   0   0   0   0   1
#define LCD_RETURNHOME      0b00000010 // 0   0   0   0   0   0   1   -
#define LCD_ENTRYMODESET    0b00000100 // 0   0   0   0   0   1 I/D   S
#define LCD_DISPLAYCONTROL  0b00001000 // 0   0   0   0   1   D   C   B
#define LCD_CURSORSHIFT     0b00010000 // 0   0   0   1 S/C R/L   -   -
#define LCD_FUNCTIONSET     0b00100000 // 0   0   1  DL   N   F   -   -
#define LCD_SETCGRAMADDR    0b01000000 // 0   1 ACG ACG ACG ACG ACG ACG
#define LCD_SETDDRAMADDR    0b10000000 // 1 ADD ADD ADD ADD ADD ADD ADD

/* 
 * Command parameters
 */
#define LCD_ENTRYMODESET_ID_BIT 0b00000010
#define LCD_ENTRYMODESET_S_BIT  0b00000001

#define LCD_DISPLAYCONTROL_D_BIT  0b00000100
#define LCD_DISPLAYCONTROL_C_BIT  0b00000010
#define LCD_DISPLAYCONTROL_B_BIT  0b00000001

#define LCD_CURSORSHIFT_SC_BIT  0b00001000
#define LCD_CURSORSHIFT_RL_BIT  0b00000100

#define LCD_FUNCTIONSET_DL_BIT  0b00010000
#define LCD_FUNCTIONSET_N_BIT   0b00001000
#define LCD_FUNCTIONSET_F_BIT   0b00000100

class TwiLiquidCrystal : public Print
{
private:
    /*
    * Registers to store settings
    */
    uint8_t _ctrlRegister = 0b00000000; // To store BL EN RS RW bits state
    uint8_t _dsplRegister = 0b00000000; // To store the display settings
    uint8_t _modeRegister = 0b00000000; // To store the mode settings
    uint8_t _fctnRegister = 0b00000000; // To store the function settings

    /*
    * LCD settings
    */
    uint8_t _i2cLcdAddress;
    uint8_t _cols;
    uint8_t _rows;
    uint8_t _font;

    uint8_t _rowOffsets[4];
    
    void initializationRoutine();

    void send(uint8_t data);
    void sendQuartet(uint8_t data);
    void setCtrlRegisterBit(uint8_t bit, bool state);
    void setDsplRegisterBit(uint8_t bit, bool state);
    void setEntryModeBit(uint8_t bit, bool state);
    void sendCmd(uint8_t data);
public:
    TwiLiquidCrystal(uint8_t address);
    
    void begin(uint8_t cols, uint8_t rows, uint8_t font = LCD_5x8DOTS);

    void setCursor(uint8_t col, uint8_t row = 0);
    void setBacklight(bool state);
    void clear();
    void home();
    void createChar(uint8_t index, uint8_t character[]);
    void selectScreen(uint8_t index);

    virtual size_t write(uint8_t);

    // Faster than using LiquidCrystal Library compatible functions
    // Set multiple bits, send one time
    void setFctnRegister(uint8_t bytemode, uint8_t lines, uint8_t font = LCD_5x8DOTS);
    void setDsplControl(uint8_t display, uint8_t cursor, uint8_t blink);
    void setEntryMode(uint8_t increment, uint8_t shift);
    void setRowOffsets(int row1, int row2, int row3, int row4);

    // LiquidCrystal Library compatible functions
    // Set one bit, send one time
    void backlight();
    void noBacklight();
    void display();
    void noDisplay();
    void blink();
    void noBlink();
    void cursor();
    void noCursor();
    void leftToRight();
    void rightToLeft();
    void autoscroll();
    void noAutoscroll();
    void scrollDisplayLeft();
    void scrollDisplayRight();
    inline void command(uint8_t value);
};

#endif