#ifndef BATTERY_CHARACTER_HPP
#define BATTERY_CHARACTER_HPP

#include "CoolingStrategy.hpp"

struct BatteryCharacter {
    CoolingStrategy* coolingStrategy;
    char brand[48];
};

#endif // BATTERY_CHARACTER_HPP
