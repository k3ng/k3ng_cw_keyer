/*
 * BasicTerm.h
 * Provides basic ANSI/VT220 terminal control over a serial interface
 * Copyright 2011 Trannie Carter <borys@nottwo.org>
 * Licensed for use under the terms of the GNU Lesser General Public License v3
 */

#ifndef BASICTERM_H
#define BASICTERM_H

#include <Arduino.h>

class BasicTerm : public Stream {

#define BT_NORMAL    0
#define BT_BOLD      1
#define BT_UNDERLINE 2
#define BT_BLINK     4
#define BT_REVERSE   8

#define BT_BLACK     0
#define BT_RED       1
#define BT_GREEN     2
#define BT_YELLOW    3
#define BT_BLUE      4
#define BT_MAGENTA   5
#define BT_CYAN      6
#define BT_WHITE     7

#define BT_KEY_UNKNOWN      0401
#define BT_KEY_DOWN         0402
#define BT_KEY_UP           0403
#define BT_KEY_LEFT         0404
#define BT_KEY_RIGHT        0405
#define BT_KEY_F0           0410
#define BT_KEY_F(n)         (BT_KEY_F0 + (n))

    private: 
        Stream *serial;

    public:
        BasicTerm(Stream *);
        void init(void);
        void cls(void);
        void position(uint8_t, uint8_t);
        void show_cursor(boolean);
        void set_attribute(uint8_t);
        void set_color(uint8_t, uint8_t);
        int16_t get_key(void);

        virtual int available(void);
        virtual int peek(void);
        virtual int read(void);
        virtual void flush(void);
        virtual size_t write(uint8_t);

        using Print::write;
};

#endif
