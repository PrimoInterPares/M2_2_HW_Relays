#include "RelayControl.h"

RelayControl::RelayControl(uint8_t pin_num) : pin(pin_num) {}

RelayControl::~RelayControl() {
    digitalWrite(pin, HIGH);
}

void RelayControl::init() {
    pinMode(pin, OUTPUT);
}

void RelayControl::set(RelayState state) {
    if (state == RelayState::ON) {
        digitalWrite(pin, LOW);
    }
    else if (state == RelayState::OFF) {
        digitalWrite(pin, HIGH);
    }
    
}