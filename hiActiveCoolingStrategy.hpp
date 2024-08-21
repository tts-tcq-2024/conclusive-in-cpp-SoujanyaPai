#ifndef HI_ACTIVE_COOLING_STRATEGY_HPP
#define HI_ACTIVE_COOLING_STRATEGY_HPP

#include "coolingStrategy.hpp"

class HiActiveCoolingStrategy : public CoolingStrategy {
public:
    BreachType classifyTemperature(double temperatureInCelcius) const override {
        return inferBreach(temperatureInCelcius, 0, 45);
    }
};

#endif // HI_ACTIVE_COOLING_STRATEGY_HPP
