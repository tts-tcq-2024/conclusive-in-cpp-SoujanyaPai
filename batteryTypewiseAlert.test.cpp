#include <gtest/gtest.h>
#include "batteryTypewiseAlert.hpp"

TEST(TypeWiseAlertTestSuite,InfersBreachAccordingToLimits) {
    BatteryCharacter batteryChar;
    PassiveCoolingStrategy passiveStrategy;
    HiActiveCoolingStrategy hiActiveStrategy;
    MedActiveCoolingStrategy medActiveStrategy;

    batteryChar.coolingStrategy = &passiveStrategy;
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, -5), TOO_LOW);
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, 39), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, 20), NORMAL);

    batteryChar.coolingStrategy = &hiActiveStrategy;
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, -1), TOO_LOW);
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, 55), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, 44), NORMAL);

    batteryChar.coolingStrategy = &medActiveStrategy;
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, -3), TOO_LOW);
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, 50), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, 33), NORMAL);
}
