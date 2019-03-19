#include <iostream>
#include <chrono>
#include <vector>

#include "securitybot.h"

using namespace std::chrono;
using namespace elma;
using namespace securitybot;

SecurityBot& WanderState:: securitybot() { return (SecurityBot&) state_machine(); }

void WanderState::during(){
    securitybot().wanderMove();
}

void WanderState::exit(const Event& e) {
    // NO ACTIONS CURRENTLY JUST STATES SO DON"T PERFORM ANY CALCULATIONS
    //securitybot().wanderMove();
    // if ( e.name() == "start/stop" ) {
    //     // User started the stopwatch
    //     stopwatch().begin();
    // } else if ( e.name() == "reset" ) {
    //     // User rest the stopwatch
    //     stopwatch().reset();
    // }
}
