#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "gtest/gtest.h"
#include "securitybot.h"

namespace {
 
    using namespace elma;
    using namespace securitybot;

    TEST(SecurityBot,Construction) { 
        SecurityBot sb; 
        ASSERT_EQ("wander", sb.current().name());
    }

    TEST(SecurityBot,ValidStateCheck) {
        //Variables
        SecurityBot sb;
        string wander = "wander";
        string noise = "make noise";
        string evade = "evade";
        string findrecharge = "find recharge station";
        string recharge = "recharge";

        //Start the machine
        Manager m;
        m.schedule(sb, 10_ms)
        .init()
        .start();
        
        //run tests
        std::cout << robot.current().name() << std::endl;
        EXPECT_EQ(robot.current().name(), wander.c_str());

        m.emit(Event("intruder detected"));
        std::cout << robot.current().name() << std::endl;
        EXPECT_EQ(robot.current().name(), noise.c_str());

        m.emit(Event("proximity warning"));
        std::cout << robot.current().name() << std::endl;
        EXPECT_EQ(robot.current().name(), evade.c_str());

        m.emit(Event("reset"));
        std::cout << robot.current().name() << std::endl;
        EXPECT_EQ(robot.current().name(), noise.c_str());

        m.emit(Event("reset"));
        std::cout << robot.current().name() << std::endl;
        EXPECT_EQ(robot.current().name(), wander.c_str());

        m.emit(Event("battery low"));
        std::cout << robot.current().name() << std::endl;
        EXPECT_EQ(robot.current().name(), findrecharge.c_str());

        m.emit(Event("found recharge station"));
        std::cout << robot.current().name() << std::endl;
        EXPECT_EQ(robot.current().name(), recharge.c_str());

    }
}