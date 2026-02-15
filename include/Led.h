#pragma once 
#include <Arduino.h> 
#include "LedState.h"

class Led {
private:
    const uint8_t pin;
public:
    Led(uint8_t pin_num);
    ~Led();
    void init();
    void set(LedState state);
};
