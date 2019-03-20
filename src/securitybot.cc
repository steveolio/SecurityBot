#include <chrono>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

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
}

std::string SecurityBot::currentState(){
    return current().name();
}


void SecurityBot::wanderMoveFunction(){
    // The current position of the SecurityBot is found in these variables.
    // _current_x
    // _current_y
    
    int x_offset, y_offset, temp_x, temp_y;   // initialize new variables
    srand (time(NULL)); // initialize random seed
    x_offset = rand() %3+1; // generate secret number between 1 and 3
    x_offset = x_offset -2; // change number to be between -1 and 1
    y_offset = rand() %3+1; // generate secret number between 1 and 3
    y_offset = y_offset -2; // change number to be between -1 and 1
    temp_x = _current_x + x_offset;
    temp_y = _current_y + y_offset;
    //Check outer boundries
    if( (temp_x < _x_lowerboundry) || (temp_x > _x_upperboundry) ){
        temp_x = _current_x;
    }
    if( (temp_y < _y_lowerboundry) || (temp_y > _y_upperboundry) ){
        temp_y = _current_y;
    }
    _current_x = temp_x;    // change the current x location
    _current_y = temp_y;    // change the current y location
    
    //Moving uses battery
    if( _current_battery_percent > 0 ){
        _current_battery_percent = _current_battery_percent - 0.1;
    }

}

void SecurityBot::makeNoiseFunction(){
    //Stuff about alarm
}

void SecurityBot::evadeMoveFunction(){
    //Stuff about evade
}
void SecurityBot::findRechargeMoveFunction(){
    //Stuff about finding the recharge station
}

void SecurityBot::rechargeFunction(){
    //Stuff about evade
}

double SecurityBot::battery_status(){
    return _current_battery_percent;
}

int SecurityBot::current_x(){
    return _current_x;
}

int SecurityBot::current_y(){
    return _current_y;
}

int SecurityBot::x_lowerboundry(){
    return _x_lowerboundry;
}
int SecurityBot::x_upperboundry(){
    return _x_upperboundry;
}
int SecurityBot::y_lowerboundry(){
    return _y_lowerboundry;
}
int SecurityBot::y_upperboundry(){
    return _y_upperboundry;
}