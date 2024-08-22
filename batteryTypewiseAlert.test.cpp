#include <gtest/gtest.h>
#include "batteryTypewiseAlert.hpp"
#include "coolingStrategy.hpp"

class BatteryTypeWiseAlertTestSuite: public :: testing::Test {
    void SetUp() override{
        BatteryCharacter batteryChar;
        PassiveCoolingStrategy passiveCooling;
        HiActiveCoolingStrategy hiActiveCooling;
        MedActiveCoolingStrategy medActiveCooling;
    }

    void TearDown() override{
    }
};

TEST(BatteryTypeWiseAlertTestSuite,InfersBreachAccordingToLimits) {
    
    batteryChar.coolingStrategy = &passiveCooling
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, -5), TOO_LOW);
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, 39), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, 20), NORMAL);

    batteryChar.coolingStrategy = &hiActiveCooling;
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, -1), TOO_LOW);
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, 55), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, 44), NORMAL);

    batteryChar.coolingStrategy = &medActiveCooling;
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, -3), TOO_LOW);
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, 50), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, 33), NORMAL);
}

TEST(BatteryTypeWiseAlertTestSuite, ChecksAndSendsAlertToCorrectTarget) {
    BatteryCharacter batteryChar = {&passiveCooling, "BrandA"};

    testing::internal::CaptureStdout();
    checkAndAlert(TO_CONTROLLER, batteryChar, 50);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "feed : 2\n"); 

    testing::internal::CaptureStdout();
    checkAndAlert(TO_EMAIL, batteryChar, -5);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "To: a.b@c.com\nHi, the temperature is too low\n");
}
