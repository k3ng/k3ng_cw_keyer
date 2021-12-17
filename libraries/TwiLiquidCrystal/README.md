# Arnakazim's TwiLiquidCrystal Arduino Library

## About

A library to interface an HD44780 based LCD via I2C (or TWI in Arduino terms).

Like its counterpart the LiquidCrystal library, this library allows an Arduino board to control Liquid Crystal displays (LCDs) based on the Hitachi HD44780 (or a compatible) chipset, which is found on most text-based LCDs. The difference is that instead of using multiple digital pins, it communicates with the Arduino via TWI (I2C) with the help of an I2C backpack attached to the LCD.

## Q&A

__Why another I2C/TWI LCD display library for Arduino?__

That's a good question with a simple answer: there is no need for another one. I am in the process on making a board around an ATMega328P and I am planning to use a HD44780 base 16x2 display over I2C.

I was using LiquidCrystal_I2C at first, but it is not well maintained and is basically a  copy/paste of LiquidCrystal with a different write4bits() function. It is nice from far, but the LiquidCrystal library isn't so perfect...

So, I have retrieved the HD44780 datasheet, read from it and started writing my own library. It worked fine for what I needed, but then I was "why not making it LiquidCrystal compatible?". And there I am.

At the moment it is 99% compatible. Timings are improved from the original library.

__What is a TWI/I2C backpack for my LCD?__

An I2C backpack is a module you connect in between your LCD and your Arduino. It enables communicating with the LCD via I2C. You willl be able to communicate via only two pins from your Arduino, instead of six or 10.

You can buy I2C backpack on [Adafruit shop](https://www.adafruit.com/product/292) for example.

The pinout to communicate using I2C on your Arduino depends on its model. You can find more information on the [Arduino website](https://www.arduino.cc/en/reference/wire).

__What's the difference with the Arduino LiquidCrystal library?__

For you? Not much. If you have a sketch using the LiquidCrystal library, you can easily switch to this one. The only thing is that you will need an I2C backpack for your LCD.

To switch from the LiquidCrystal library to the TwiLiquidCrystal it is simple. After rewiring your LCD screen, simply replace the library include and the type of your lcd variable and its parameters. That's all! Here is an example:

With the LiquidCrystal library you would use:

```cpp
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
```

And to use the same code with TwiLiquidCrystal you would simple replace this code by:

```cpp
#include <TwiLiquidCrystal.h>

const int twiAddress = 0x27; // The I2C address of your LCD backpack
TwiLiquidCrystal lcd(twiAddress);
```

__Can I help improve this library?__

Of course you can help! One of my goals is to keep this library active, bug free and updated. If you've seen a problem with this library or you think you can improve it I am open to all suggestions!

__Why so many delays in the library code?__

The HD44780 is a time sensitive chipset. It needs delays to register commands and execute them. I have reduced them as much as I can, according to the HD44780 datasheet (<https://www.sparkfun.com/datasheets/LCD/HD44780.pdf>). The thing is, the datasheet says that it takes nano seconds for certain action. The library does at best microseconds so there is a bit of time loss there. Also transmitting data over I2C takes time. I don't have an oscilloscope at hand, but I am pretty sure some delays aren't needed anymore or can be shortened...

__Hey! I find your library usefull. Can I buy you a beer?__

Yes of course! You can tip me via my Ko-fi page. If I don't invest it in my future projects, I'll make sure to at least invest it in a beer ;)

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/B0B03OTWP)

__Can I sell a product using your library?__

Haven't you read the licence file? Of course you can! I've made this project in the public domain via the Unlicense license. I did not wrote this library to make money and if it can help others, even to make money, I would make me really happy. And if you make a few bucks with it and you want to thank me, you can help me with a tip (see previous answer).

This is free and unencumbered software released into the public domain. For more information, see http://unlicense.org/ or the accompanying (un)LICENSE file.