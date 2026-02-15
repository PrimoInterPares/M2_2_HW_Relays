#pragma once 
#include <Arduino.h> 

class Timer {
private:
    unsigned long interval;       
    unsigned long previousMillis;

public:

    Timer(unsigned long intervalMs);

    bool isReady();
    
    void setInterval(unsigned long new_interval);

    ~Timer();
};