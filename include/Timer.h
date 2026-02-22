#pragma once 
#include <Arduino.h> 

class Timer {
private:
    unsigned long intervalBetweenActivations;       
    unsigned long milliSecFormStToLstAct;

public:

    Timer(unsigned long intervalBetweenActivationsMS);

    ~Timer();

    bool isReady();
    
    void setInterval(unsigned long new_interval);

    void resetTimer();

};