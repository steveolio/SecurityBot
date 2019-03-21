#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "gtest/gtest.h"
#include "securitybot.h"

namespace {
 
    using namespace elma;
    using namespace securitybot;

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
        std::cout << "Expect wander: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), wander.c_str());
        
        m.emit(Event("intruder detected"));
        std::cout << "Expect make noise: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), noise.c_str());

        m.emit(Event("proximity warning"));
        std::cout << "Expect evade: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), evade.c_str());

        m.emit(Event("reset"));
        std::cout << "Expect make noise: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), noise.c_str());

        m.emit(Event("reset"));
        std::cout << "Expect wander: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), wander.c_str());

        m.emit(Event("battery low"));
        std::cout << "Expect find recharge station: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), findrecharge.c_str());

        m.emit(Event("found recharge station"));
        std::cout << "Expect rechage: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), recharge.c_str());

        m.emit(Event("battery full"));
        std::cout << "Expect wander: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), wander.c_str());

        m.emit(Event("intruder detected"));
        std::cout << "Expect make noise: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), noise.c_str());

        m.emit(Event("proximity warning"));
        std::cout << "Expect evade: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), evade.c_str());

        m.emit(Event("battery low"));
        std::cout << "Expect find recharge station: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), findrecharge.c_str());

        m.emit(Event("found recharge station"));
        std::cout << "Expect rechage: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), recharge.c_str());

        m.emit(Event("battery full"));
        std::cout << "Expect wander: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), wander.c_str());

        m.emit(Event("intruder detected"));
        std::cout << "Expect make noise: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), noise.c_str());

        m.emit(Event("battery low"));
        std::cout << "Expect rind recharge station: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), findrecharge.c_str());

    }

    TEST(SecurityBot,NonValidWanderEventCheck) {
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
        std::cout << "Expect wander: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), wander.c_str());

        m.emit(Event("reset"));
        std::cout << "Expect wander: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), wander.c_str());

        m.emit(Event("battery full"));
        std::cout << "Expect wander: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), wander.c_str());

        m.emit(Event("found recharge station"));
        std::cout << "Expect wander: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), wander.c_str());

        m.emit(Event("proximity warning"));
        std::cout << "Expect wander: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), wander.c_str());
    }

    TEST(SecurityBot,NonValidMakeNoiseEventCheck) {
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
        std::cout << "Expect wander: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), wander.c_str());

        m.emit(Event("intruder detected"));
        std::cout << "Expect make noise: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), noise.c_str());

        m.emit(Event("battery full"));
        std::cout << "Expect make noise: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), noise.c_str());

        m.emit(Event("found recharge station"));
        std::cout << "Expect make noise: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), noise.c_str());

        m.emit(Event("intruder detected"));
        std::cout << "Expect make noise: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), noise.c_str());
    }

    TEST(SecurityBot,NonValidEvadeEventCheck) {
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
        std::cout << "Expect wander: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), wander.c_str());

        m.emit(Event("intruder detected"));
        std::cout << "Expect make noise: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), noise.c_str());

        m.emit(Event("proximity warning"));
        std::cout << "Expect evade: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), evade.c_str());

        m.emit(Event("proximity warning"));
        std::cout << "Expect evade: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), evade.c_str());

        m.emit(Event("found recharge station"));
        std::cout << "Expect evade: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), evade.c_str());

        m.emit(Event("battery full"));
        std::cout << "Expect evade: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), evade.c_str());

        m.emit(Event("intruder detected"));
        std::cout << "Expect evade: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), evade.c_str());
    }

    TEST(SecurityBot,NonValidFindRechargeStationEventCheck) {
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
        std::cout << "Expect wander: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), wander.c_str());

        m.emit(Event("battery low"));
        std::cout << "Expect find recharge station: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), findrecharge.c_str());

        m.emit(Event("battery low"));
        std::cout << "Expect find recharge station: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), findrecharge.c_str());

        m.emit(Event("proximity warning"));
        std::cout << "Expect find recharge station: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), findrecharge.c_str());

        m.emit(Event("reset"));
        std::cout << "Expect find recharge station: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), findrecharge.c_str());

        m.emit(Event("battery full"));
        std::cout << "Expect find recharge station: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), findrecharge.c_str());

        m.emit(Event("intruder detected"));
        std::cout << "Expect find recharge station: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), findrecharge.c_str());
    }

    TEST(SecurityBot,NonValidRechargeEventCheck) {
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
        std::cout << "Expect wander: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), wander.c_str());

        m.emit(Event("battery low"));
        std::cout << "Expect find recharge station: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), findrecharge.c_str());

        m.emit(Event("found recharge station"));
        std::cout << "Expect recharge: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), recharge.c_str());

        m.emit(Event("proximity warning"));
        std::cout << "Expect find recharge station: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), recharge.c_str());

        m.emit(Event("reset"));
        std::cout << "Expect find recharge station: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), recharge.c_str());

        m.emit(Event("found recharge station"));
        std::cout << "Expect find recharge station: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), recharge.c_str());

        m.emit(Event("intruder detected"));
        std::cout << "Expect find recharge station: " << sb.current().name() << std::endl;
        EXPECT_EQ(sb.current().name(), recharge.c_str());
    }
}
