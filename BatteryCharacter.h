#ifndef BATTERY_CHARACTER_H
#define BATTERY_CHARACTER_H

#include "CoolingStrategy.h"

struct BatteryCharacter {
    CoolingStrategy* coolingStrategy;
    char brand[48];
};

#endif // BATTERY_CHARACTER_H
