#ifndef COOLING_STRATEGY_HPP
#define COOLING_STRATEGY_HPP

#include "typewise-alert.hpp"

class CoolingStrategy {
public:
    virtual ~CoolingStrategy() = default;
    virtual BreachType classifyTemperature(double temperatureInC) const = 0;
};

class HiActiveCoolingStrategy : public CoolingStrategy {
public:
    BreachType classifyTemperature(double temperatureInC) const override {
        return inferBreach(temperatureInC, 0, 45);
    }
};

class MedActiveCoolingStrategy : public CoolingStrategy {
public:
    BreachType classifyTemperature(double temperatureInC) const override {
        return inferBreach(temperatureInC, 0, 40);
    }
};

class PassiveCoolingStrategy : public CoolingStrategy {
public:
    BreachType classifyTemperature(double temperatureInC) const override {
        return inferBreach(temperatureInC, 0, 35);
    }
};

#endif // COOLING_STRATEGY_HPP
