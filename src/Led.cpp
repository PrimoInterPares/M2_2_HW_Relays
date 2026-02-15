#include "Led.h"

Led::Led(uint8_t pin_num) : pin(pin_num) {}

Led::~Led() {
    digitalWrite(pin, LOW);
}

void Led::init() {
    pinMode(pin, OUTPUT);
}

void Led::set(LedState state) {
    digitalWrite(pin, static_cast<uint8_t>(state));
}