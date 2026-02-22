#pragma once 
#include <Arduino.h> 

class Button {
private:
    const uint8_t pin;
    volatile bool buttonPressed;
    unsigned long lastTimeButtonTrig = 0;
public:
    Button(uint8_t pin_num);
    ~Button();
    void init();
    bool isPressed();
};
