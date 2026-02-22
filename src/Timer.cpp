#include "Timer.h"

Timer::Timer(unsigned long intervalBetweenActivationsMS) {
    intervalBetweenActivations = intervalBetweenActivationsMS;
    milliSecFormStToLstAct = 0;
}

Timer::~Timer() { 
    intervalBetweenActivations = 0;
    milliSecFormStToLstAct = 0;
}

bool Timer::isReady() {
    unsigned long milliSecAfterSt = millis();
    
    if (milliSecAfterSt - milliSecFormStToLstAct >= intervalBetweenActivations) {
        milliSecFormStToLstAct = milliSecAfterSt; 
        return true; 
    }
    
    return false;
}

void Timer::setInterval(unsigned long new_intervalBtwnAct) {
    intervalBetweenActivations = new_intervalBtwnAct;
    milliSecFormStToLstAct = millis();
}

void Timer::resetTimer() {
    milliSecFormStToLstAct = millis();
}