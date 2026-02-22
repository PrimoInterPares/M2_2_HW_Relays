#pragma once 
#include <Arduino.h> 
#include "RelayState.h"

class RelayControl {
private:
    const uint8_t pin;
public:
    RelayControl(uint8_t pin_num);
    ~RelayControl();
    void init();
    void set(RelayState state);
};
