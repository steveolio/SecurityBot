#include <iostream>
#include <chrono>
#include <vector>

#include "securitybot.h"

using namespace std::chrono;
using namespace elma;
using namespace securitybot;

SecurityBot& RechargeState:: securitybot() { return (SecurityBot&) state_machine(); }

void RechargeState::during(){
    securitybot().rechargeFunction();
}
