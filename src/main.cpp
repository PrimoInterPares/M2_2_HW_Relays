#include <Arduino.h>
#include <cstdint>
#include "Timer.h" 
#include "Button.h"
#include "RelayControl.h" 
#include "Config.h"

Button Button1(Config::PIN_BUTTON);
RelayControl Relay1(Config::PIN_RELAY_CONTROL);
Timer relayTimer(10000);    
Timer ReadRelayStatusTimer(1000); 

void setup() {
    Serial.begin(115200);
    Button1.init();
    Relay1.init(); 
}

void loop() {
    if (Button1.isPressed()) {
        Relay1.set(RelayState::ON);
    }
    else if (!Button1.isPressed()) {
        Relay1.set(RelayState::OFF);
    }

    /* if (ReadRelayStatusTimer.isReady() && digitalRead(Config::PIN_RELAY_STATUS) == HIGH) {
        Serial.println("Relay is ON");
    }
    else if (ReadRelayStatusTimer.isReady() && digitalRead(Config::PIN_RELAY_STATUS) == LOW) {
        Serial.println("Relay is OFF"); 
    } */
}