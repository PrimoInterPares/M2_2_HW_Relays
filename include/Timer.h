#pragma once 
#include <Arduino.h> 

class Timer {
private:
    unsigned long intervalBtwnAct;       
    unsigned long milliSecFormStToLstAct;

public:

    Timer(unsigned long intervalBtwnActMS);

    ~Timer();

    bool isReady();
    
    void setInterval(unsigned long new_interval);

    void resetTimer();

};