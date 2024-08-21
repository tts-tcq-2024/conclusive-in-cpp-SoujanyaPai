#ifndef COOLING_STRATEGY_HPP
#define COOLING_STRATEGY_HPP

#include "batteryTypewiseAlert.hpp"
#include "breachType.hpp"

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

class CoolingStrategyTypes {
public:
    virtual ~CoolingStrategyTypes() = default;
    virtual BreachType classifyTemperature(double temperatureInCelcius) const = 0;
};

class HiActiveCoolingStrategy : public CoolingStrategyTypes {
public:
    BreachType classifyTemperature(double temperatureInCelcius) const override {
        return inferBreach(temperatureInCelcius, 0, 45);
    }
};

class MedActiveCoolingStrategy : public CoolingStrategyTypes {
public:
    BreachType classifyTemperature(double temperatureInCelcius) const override {
        return inferBreach(temperatureInCelcius, 0, 40);
    }
};

class PassiveCoolingStrategy : public CoolingStrategyTypes {
public:
    BreachType classifyTemperature(double temperatureInCelcius) const override {
        return inferBreach(temperatureInCelcius, 0, 35);
    }
};

#endif // COOLING_STRATEGY_HPP
