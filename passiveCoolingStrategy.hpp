#ifndef PASSIVE_COOLING_STRATEGY_HPP
#define PASSIVE_COOLING_STRATEGY_HPP

#include "coolingStrategy.hpp"

class PassiveCoolingStrategy : public CoolingStrategy {
public:
    BreachType classifyTemperature(double temperatureInCelcius) const override {
        return inferBreach(temperatureInCelcius, 0, 35);
    }
};
#endif //PASSIVE_COOLING_STRATEGY_HPP
