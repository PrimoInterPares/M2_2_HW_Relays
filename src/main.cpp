#include <Arduino.h>
#include <cstdint>
#include "Timer.h" 
#include "Button.h"
#include "RelayControl.h" 
#include "Config.h"

Button Button1(Config::PIN_BUTTON);
RelayControl Relay1(Config::PIN_RELAY_CONTROL);
Timer RelayStatusOutTimer(5000);

void RelayInterruptHandler() {
    Relay1.currentRelayStatus = !Relay1.currentRelayStatus;
}

void setup() {
    Serial.begin(115200);
    Button1.initButton();
    Relay1.initRelay(); 
    attachInterrupt(digitalPinToInterrupt(Config::PIN_RELAY_CONTROL), RelayInterruptHandler, CHANGE);
}

void loop() {
    if (Button1.isPressed()) {
        Relay1.setRelayStatus(RelayState::ON);
    }
    else if (!Button1.isPressed()) {
        Relay1.setRelayStatus(RelayState::OFF);
    }
    if (RelayStatusOutTimer.isReady()) {
        Serial.print("Relay status: ");
        if (Relay1.getRelayStatus()) {
            Serial.println("ON");
        }
        else if (!Relay1.getRelayStatus()) {
        Serial.println("OFF");
        }
    Serial.println("");
    }
}
