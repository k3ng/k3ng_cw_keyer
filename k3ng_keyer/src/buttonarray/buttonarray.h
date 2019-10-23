#ifndef buttonarray_h
#define buttonarray_h
#include "Arduino.h"

#define MAX_BUTTONS 8
#define DEBOUNCE_MS 200

#if defined(ARDUINO_ARCH_ESP32)
    #define max_value 4095
#else
    #define max_value 1023
#endif

#define r1_value 10
#define r2_value 1

class Button {
    private:
        int32_t low_limit_;
        int32_t high_limit_;
        uint8_t step_;
    public:
        Button(){};
        InitLimits(uint8_t step);
        InitLimits(uint8_t step, int32_t low_limit, int32_t high_limit);
        bool Pressed(int32_t analog_reading);
        int32_t high_limit();
        int32_t low_limit();
};

class ButtonArray {
    private:
        Button button_array_[MAX_BUTTONS];
        uint8_t pin_;
        uint8_t nb_buttons_;
        int32_t high_limit_;
        bool   reversed_;
        int8_t ReadButtons();

    public:
        uint32_t last_pressed_ms;
        ButtonArray(uint8_t pin, uint8_t nb, bool reversed): pin_(pin), nb_buttons_(nb), reversed_(reversed){};
        AddAll();
        Add(uint8_t step, uint8_t index);
        Add(uint8_t step, uint8_t index, int32_t low_limit, int32_t high_limit);
        int32_t high_limit();
        int8_t Pressed();
        bool Pressed(uint8_t index);
        bool Held(uint8_t index);
        bool Held(uint8_t index, uint32_t deadline );
};


#endif