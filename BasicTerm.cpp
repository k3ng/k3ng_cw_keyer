/*
 * BasicTerm.cpp
 * Provides basic ANSI/VT220 terminal control over a serial interface
 * Copyright 2011 Trannie Carter <borys@nottwo.org>
 * Licensed for use under the terms of the GNU Lesser General Public License v3
 */

#include "BasicTerm.h"

BasicTerm::BasicTerm(Stream *ser) {
    serial = ser;
}

int BasicTerm::available(void) {
    return serial->available();
}

int BasicTerm::peek(void) {
    return serial->peek();
}

int BasicTerm::read(void) {
    return serial->read();
}

void BasicTerm::flush(void) {
    serial->flush();
}

size_t BasicTerm::write(uint8_t c) {
    return serial->write(c);
}

void BasicTerm::init(void) {
   serial->print(F("\x1b\x63")); 
}

void BasicTerm::cls(void) {
    serial->print(F("\x1b[2J"));
}

void BasicTerm::position(uint8_t row, uint8_t col) {
    serial->print(F("\x1b["));
    serial->print((uint8_t)row + 1);
    serial->print(F(";"));
    serial->print((uint8_t)col + 1);
    serial->print(F("H"));
}

void BasicTerm::show_cursor(boolean show) {
    if(show) {
        serial->print(F("\x1b[?25h"));
    } else {
        serial->print(F("\x1b[?25l"));
    }
}

int16_t BasicTerm::get_key(void) {
    int16_t key;
    uint16_t when;

    key = serial->read();

    if(key == 0x1b) { /* escape sequence */
        when = millis();
        while(serial->available() < 2) {
            if(((uint16_t) millis() - when) > 1000) {
                return key;
            }
        }

        key = serial->read();

        switch(key) {
            case '[':
                key = serial->read();
                switch(key) {
                    case 'A':
                        return BT_KEY_UP;
                    case 'B':
                        return BT_KEY_DOWN;
                    case 'C':
                        return BT_KEY_RIGHT;
                    case 'D':
                        return BT_KEY_LEFT;
                    default:
                        return key;
                }
                break;
            case 'O':
                key = serial->read();
                switch(key) {
                    case 'P':
                        return BT_KEY_F(1);
                    case 'Q':
                        return BT_KEY_F(2);
                    case 'R':
                        return BT_KEY_F(3);
                    case 'S':
                        return BT_KEY_F(4);
                    default:
                        return key;
                }
                break;
            default:
                return key;
        } 
    }

    return key;
}

void BasicTerm::set_attribute(uint8_t attr) {
    if(attr & BT_REVERSE) {
        serial->print(F("\x1b[7m"));
    }
    if(attr & BT_UNDERLINE) {
        serial->print(F("\x1b[4m"));
    }
    if(attr & BT_BOLD) {
        serial->print(F("\x1b[1m"));
    }
    if(attr & BT_BLINK) {
        serial->print(F("\x1b[5m"));
    }
    if(attr == BT_NORMAL) {
        serial->print(F("\x1b[0m"));
    }
}

void BasicTerm::set_color(uint8_t fg, uint8_t bg) {
    serial->print(F("\x1b["));
    serial->print(30 + fg);
    serial->print(";");
    serial->print(40 + bg);
    serial->print("m");
}
