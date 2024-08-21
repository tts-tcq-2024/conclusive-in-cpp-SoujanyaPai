#ifndef MED_ACTIVE_COOLING_STRATEGY_HPP
#define MED_ACTIVE_COOLING_STRATEGY_HPP

#include "coolingStrategy.hpp"

class MedActiveCoolingStrategy : public CoolingStrategy {
public:
    BreachType classifyTemperature(double temperatureInCelcius) const override {
        return inferBreach(temperatureInCelcius, 0, 40);
    }
};
#endif //MED_ACTIVE_COOLING_STRATEGY_HPP
