#ifndef buttonarray_h
#define buttonarray_h
#include "Arduino.h"
#ifndef MAX_ARRAY_BUTTONS
    #define MAX_ARRAY_BUTTONS 13
#endif
#define DEBOUNCE_MS 200
#define NUMBER_OF_BUTTON_READS_TO_AVERAGE 19

#if defined(ARDUINO_ARCH_ESP32) || defined(ARDUINO_GENERIC_STM32F103C)
    #define max_value 4095
#else
    #define max_value 1023
#endif

#define r1_value 10
#define r2_value 1

/* contributed by W6IPA */

class Button {
    private:
        int32_t low_limit_;
        int32_t high_limit_;
        uint8_t step_;
    public:
        Button(){};
        void InitLimits(uint8_t step);
        void InitLimits(uint8_t step, int32_t low_limit, int32_t high_limit);
        bool Pressed(int32_t analog_reading);
        int32_t high_limit();
        int32_t low_limit();
};

class ButtonArray {
    private:
        Button button_array_[MAX_ARRAY_BUTTONS];
        uint8_t pin_;
        uint8_t nb_buttons_;
        int32_t high_limit_;
        bool   reversed_;
        int8_t ReadButtons();
        bool AnyPressed();

    public:
        uint32_t last_pressed_ms;
        ButtonArray(uint8_t pin, uint8_t nb, bool reversed): pin_(pin), nb_buttons_(nb), reversed_(reversed){};
        void AddAll();
        void Add(uint8_t step, uint8_t index);
        void Add(uint8_t step, uint8_t index, int32_t low_limit, int32_t high_limit);
        int32_t high_limit();
        int8_t Pressed();
        bool Pressed(uint8_t index);
        bool Held(uint8_t index);
        bool Held(uint8_t index, uint32_t deadline );
};


#endif
