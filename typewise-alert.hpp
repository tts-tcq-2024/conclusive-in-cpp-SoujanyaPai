#ifndef TYPEWISEALERT_HPP
#define TYPEWISEALERT_HPP

#include "CoolingStrategy.hpp"
#include "BatteryCharacter.hpp"

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

void checkAndAlert(
  AlertTarget alertTarget, const BatteryCharacter batteryChar, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);

typedef void (*AlertFunction)(BreachType);

#endif //TYPEWISE-ALERT_HPP
