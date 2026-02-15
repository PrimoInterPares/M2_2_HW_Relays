#pragma once
#include <cstdint>

struct Config {
    static constexpr uint8_t PIN_LED= 4;
    static constexpr uint8_t CONTROL_BUTTON= 5;
    static constexpr uint16_t blinkTimer = 1000;
};