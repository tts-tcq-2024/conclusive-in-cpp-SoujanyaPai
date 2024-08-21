#ifndef BATTERYTYPEWISEALERT_HPP
#define BATTERYTYPEWISEALERT_HPP

#include "coolingStrategy.hpp"
#include "batteryCharacter.hpp"

typedef enum {
    NORMAL,
    TOO_LOW,
    TOO_HIGH
} BreachType;

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInCelcius);

void checkAndAlert(
  AlertTarget alertTarget, const BatteryCharacter batteryChar, double temperatureInCelcius);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);

typedef void (*AlertFunction)(BreachType);

#endif //BATTERYTYPEWISEALERT_HPP
