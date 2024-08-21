#ifndef COOLING_STRATEGY_HPP
#define COOLING_STRATEGY_HPP

#include "batteryTypewiseAlert.hpp"
#include "breachType.hpp"

class CoolingStrategy {
public:
    virtual ~CoolingStrategy() = default;
    virtual BreachType classifyTemperature(double temperatureInCelcius) const = 0;
};

#endif // COOLING_STRATEGY_HPP
