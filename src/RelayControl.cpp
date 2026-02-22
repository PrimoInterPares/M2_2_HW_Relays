#include "RelayControl.h"

RelayControl::RelayControl(uint8_t pin_num) : pin(pin_num), currentRelayStatus(false) {
    // Constructor
}

RelayControl::~RelayControl() {
    digitalWrite(pin, HIGH);
}

void RelayControl::initRelay() {
    pinMode(pin, OUTPUT);
}

void RelayControl::setRelayStatus(RelayState state) {
    if (state == RelayState::ON) {
        digitalWrite(pin, LOW);
    }
    else if (state == RelayState::OFF) {
        digitalWrite(pin, HIGH);
    }
}

bool RelayControl::getRelayStatus() {
    return currentRelayStatus;
}