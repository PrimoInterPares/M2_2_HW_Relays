#include <Arduino.h>
#include <cstdint>
#include "Timer.h" 
#include "Led.h" 
#include "Config.h"

bool isLedOn = false;
volatile bool buttonPressed = false;
bool isFast = false;

Led Led1(Config::PIN_LED);
Timer BlikerTimer (Config::blinkTimer);

void IRAM_ATTR handleButtonInterrupt() {
    static unsigned long lastInterruptTime = 0;
    unsigned long interruptTime = millis();

    if (interruptTime - lastInterruptTime > 200) {
        buttonPressed = true;
        lastInterruptTime = interruptTime;
    }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Started");
  Led1.init();
  pinMode(Config::CONTROL_BUTTON, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(Config::CONTROL_BUTTON), handleButtonInterrupt, FALLING);
}

void loop() {

    if (buttonPressed) {
        buttonPressed = false;
        
        if (isFast) {
            BlikerTimer.setInterval(1000); 
        } else {
            BlikerTimer.setInterval(200);  
        }
        isFast = !isFast;
        Serial.println("Mode changed");
    }

    if (BlikerTimer.isReady())
    {
        if (isLedOn == false)
        {
            Led1.set(LedState::ON); 
            isLedOn = !isLedOn;
        } 
        else 
        {
            Led1.set(LedState::OFF); 
            isLedOn = !isLedOn;
        }

    }  
}