#include <chrono>
#include <vector>

#include "securitybot.h"

using namespace std::chrono;
using namespace elma;
using namespace securitybot;

SecurityBot::SecurityBot() : StateMachine("securitybot") {

    // Define state machine initial states and transitions here
    set_initial(wander);
    set_propagate(false);
    add_transition("battery low", wander, findrecharge);                // transfered to UI
    add_transition("found recharge station", findrecharge, recharge);   // transfered to UI
    add_transition("battery full", recharge, wander);                   // transfered to UI
    add_transition("intruder detected", wander, makenoise);             // transfered to UI
    add_transition("proximity warning", makenoise, evade);              // transfered to UI
    add_transition("reset", evade, makenoise);                          // transfered to UI
    add_transition("reset", makenoise, wander);                         // transfered to UI
    add_transition("battery low", evade, findrecharge);                 // transfered to UI
    //add_transition("start",wander,wander);

    // Make sure we start in the right condition
    //reset();
}

std::string SecurityBot::currentState(){
    return current().name();
}

/* I don't need any functions right now

high_resolution_clock::duration StopWatch::value() {
    if ( current().name() == "on" ) {
        return high_resolution_clock::now() - _start_time + _elapsed;
    } else {
        return _elapsed;
    }
}

void StopWatch::begin() {
    _start_time = high_resolution_clock::now();
}

void StopWatch::reset() {
    _elapsed = high_resolution_clock::duration::zero();
    _laps.clear();
}

void StopWatch::stop() {
    _elapsed += high_resolution_clock::now() - _start_time;
}

void StopWatch::lap() {
    _laps.insert(_laps.begin(), value());
}
*/