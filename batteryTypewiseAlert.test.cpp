#include <gtest/gtest.h>
#include "batteryTypewiseAlert.hpp"
#include "coolingStrategy.hpp"

TEST(BatteryTypeWiseAlertTestSuite,InfersBreachAccordingToLimits) {
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

TEST(BatteryTypeWiseAlertTestSuite, ChecksAndSendsAlertToCorrectTarget) {
    BatteryCharacter batteryChar = {PASSIVE_COOLING, "BrandA"};

    testing::internal::CaptureStdout();
    checkAndAlert(TO_CONTROLLER, batteryChar, 50);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "feed : 2\n"); 

    testing::internal::CaptureStdout();
    checkAndAlert(TO_EMAIL, batteryChar, -5);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "To: a.b@c.com\nHi, the temperature is too low\n");
}
