#ifndef BREACH_TYPE_HPP
#define BREACH_TYPE_HPP

#include "batteryCharacter.hpp"

enum BreachType {
    NORMAL,
    TOO_LOW,
    TOO_HIGH
};

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(const BatteryCharacter& batteryChar, double temperatureInCelcius);

#endif // BREACHTYPE_HPP
