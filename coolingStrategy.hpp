#ifndef COOLING_STRATEGY_HPP
#define COOLING_STRATEGY_HPP

#include "batteryTypewiseAlert.hpp"

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

class CoolingStrategy {
public:
    virtual ~CoolingStrategy() = default;
    virtual BreachType classifyTemperature(double temperatureInCelcius) const = 0;
};

class HiActiveCoolingStrategy : public CoolingStrategy {
public:
    BreachType classifyTemperature(double temperatureInCelcius) const override {
        return inferBreach(temperatureInCelcius, 0, 45);
    }
};

class MedActiveCoolingStrategy : public CoolingStrategy {
public:
    BreachType classifyTemperature(double temperatureInCelcius) const override {
        return inferBreach(temperatureInCelcius, 0, 40);
    }
};

class PassiveCoolingStrategy : public CoolingStrategy {
public:
    BreachType classifyTemperature(double temperatureInCelcius) const override {
        return inferBreach(temperatureInCelcius, 0, 35);
    }
};

#endif // COOLING_STRATEGY_HPP
