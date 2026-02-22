#include "Button.h"

Button::Button(uint8_t pin_num) : pin(pin_num), buttonPressed(false) {}

Button::~Button() {
}

void Button::initButton() {
    pinMode(pin, INPUT_PULLDOWN);
}

bool Button::isPressed() {
   
    if (digitalRead(pin) == HIGH && (millis() - lastTimeButtonTrig) > 500) { 
        buttonPressed = !buttonPressed;
        lastTimeButtonTrig = millis();
    }

    return buttonPressed;
}