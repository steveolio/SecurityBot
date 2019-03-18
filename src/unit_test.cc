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
        SecurityBot sw; 
        ASSERT_EQ("wander", sw.current().name());
    }

    // More tests go here. You should aim to test every
    // method of every object, either directly or indirectly,
    // although testing user interfaces is notoriously 
    // difficult.

}