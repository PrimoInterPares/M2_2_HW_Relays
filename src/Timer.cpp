#include "Timer.h"

Timer::Timer(unsigned long intervalBtwnActMS) {
    intervalBtwnAct = intervalBtwnActMS;
    milliSecFormStToLstAct = 0;
}

Timer::~Timer() { 
    intervalBtwnAct = 0;
    milliSecFormStToLstAct = 0;
}

bool Timer::isReady() {
    unsigned long milliSecAfterSt = millis();
    
    if (milliSecAfterSt - milliSecFormStToLstAct >= intervalBtwnAct) {
        milliSecFormStToLstAct = milliSecAfterSt; 
        return true; 
    }
    
    return false;
}

void Timer::setInterval(unsigned long new_intervalBtwnAct) {
    intervalBtwnAct = new_intervalBtwnAct;
    milliSecFormStToLstAct = millis();
}

void Timer::resetTimer() {
    milliSecFormStToLstAct = millis();
}