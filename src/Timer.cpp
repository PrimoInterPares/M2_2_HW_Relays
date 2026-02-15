#include "Timer.h"

Timer::Timer(unsigned long intervalMs) {
    interval = intervalMs;
    previousMillis = 0;
}

bool Timer::isReady() {
    unsigned long currentMillis = millis();
    
    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis; 
        return true; 
    }
    
    return false;
}

void Timer::setInterval(unsigned long new_interval) {
    interval = new_interval;
    previousMillis = millis();
}

Timer::~Timer() { 
    interval = 0;
    previousMillis = 0;
}