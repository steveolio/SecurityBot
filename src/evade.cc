#include <iostream>
#include <chrono>
#include <vector>

#include "securitybot.h"

using namespace std::chrono;
using namespace elma;
using namespace securitybot;

SecurityBot& EvadeState:: securitybot() { return (SecurityBot&) state_machine(); }

void EvadeState::during(){
    securitybot().evadeMoveFunction();
}
