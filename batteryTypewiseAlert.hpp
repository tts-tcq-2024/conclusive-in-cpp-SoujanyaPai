#ifndef BATTERY_TYPEWISE_ALERT_HPP
#define BATTERY_TYPEWISE_ALERT_HPP

#include "coolingStrategy.hpp"
#include "batteryCharacter.hpp"

enum BreachType {
    NORMAL,
    TOO_LOW,
    TOO_HIGH
};

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

#endif //BATTERY_TYPEWISE_ALERT_HPP
