#include <chrono>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "securitybot.h"

using namespace std::chrono;
using namespace elma;
using namespace securitybot;

SecurityBot::SecurityBot() : StateMachine("securitybot"){

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
    add_transition("battery low", makenoise, findrecharge);             // transfered to UI
}

std::string SecurityBot::currentState(){
    return current().name();
}

void SecurityBot::wanderMoveFunction(){
    // The current position of the SecurityBot is found in these variables.
    // _current_x
    // _current_y
    int x_offset, y_offset, temp_x, temp_y, intruderx, intrudery;   // initialize new variables
    srand (time(NULL)); // initialize random seed

    // Get the current position of the intruder
    if ( channel("Intruder_X").nonempty() ) {
        intruderx = channel("Intruder_X").latest();
    }
    if ( channel("Intruder_X").nonempty() ) {
        intrudery = channel("Intruder_Y").latest();
    }
    
    //check proximity to intruder
    if ( abs(intruderx - _current_x) < 10 && abs(intrudery - _current_y) < 10 ){
        emit(Event("intruder detected"));
    } else {
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
        consumeBattery();
    }

}

void SecurityBot::makeNoiseFunction(){
    int intruderx, intrudery;   // initialize new variables

    // Get the current position of the intruder
    if ( channel("Intruder_X").nonempty() ) {
        intruderx = channel("Intruder_X").latest();
    }
    if ( channel("Intruder_X").nonempty() ) {
        intrudery = channel("Intruder_Y").latest();
    }

    //check proximity to intruder
    if ( abs(intruderx - _current_x) < 5 && abs(intrudery - _current_y) < 5 ){
        emit(Event("proximity warning"));
    }

    consumeBattery();
}

void SecurityBot::evadeMoveFunction(){
    int intruderx;
    int intrudery;

    // Get the current position of the intruder
    if ( channel("Intruder_X").nonempty() ) {
        intruderx = channel("Intruder_X").latest();
    }
    if ( channel("Intruder_X").nonempty() ) {
        intrudery = channel("Intruder_Y").latest();
    }

    int x_offset, y_offset, temp_x, temp_y;   // initialize new variables

    if( (_current_x - intruderx) > 0){
        x_offset = 1;
    } else if ( (_current_x - intruderx) < 0){
        x_offset = -1;
    } 

    if( (_current_y - intrudery) > 0){
        y_offset = 1;
    } else if ( (_current_y - intrudery) < 0){
        y_offset = -1;
    }

    // If the intruder is on the robot
    if( (_current_y - intrudery) == 0 && (_current_x - intruderx) == 0 ){
        if( _current_x == _x_upperboundry){
            x_offset = -2;
        }
        if( _current_x == _x_lowerboundry){
            x_offset = +2;
        }
        if( _current_y == _y_upperboundry){
            y_offset = -2;
        }
        if( _current_y == _y_lowerboundry){
            y_offset = +2;
        }
    }


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

    consumeBattery();
}

void SecurityBot::findRechargeMoveFunction(){
    // The current position of the SecurityBot is found in these variables.
    // _current_x
    // _current_y
    
    int x_offset, y_offset, temp_x, temp_y;   // initialize new variables

    if(_current_x > _x_rechargestation){
        x_offset = -1;
    } else if (_current_x < _x_rechargestation) {
        x_offset = 1;
    } else {
        x_offset = 0;
    }

    if(_current_y > _y_rechargestation){
        y_offset = -1;
    } else if (_current_y < _y_rechargestation) {
        y_offset = 1;
    }  else {
        y_offset = 0;
    }

    if(x_offset == 0 && y_offset == 0){
        emit(Event("found recharge station"));
    } else {
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
        consumeBattery();
    }
}

void SecurityBot::rechargeFunction(){
    if(_current_battery_percent<100){
        _current_battery_percent = _current_battery_percent + 1;
    } else {
        emit(Event("battery full"));
    }
}

double SecurityBot::batteryStatus(){
    return _current_battery_percent;
}

void SecurityBot::consumeBattery(){
    if( _current_battery_percent > 20 ){
        if( current().name() == "wander" || current().name() == "evade" || current().name() == "find recharge station"){
            _current_battery_percent = _current_battery_percent - 0.1;
        } else if (current().name() == "make noise") {
            _current_battery_percent = _current_battery_percent - 0.05;
        }
    } else {
        emit(Event("battery low"));
        _current_battery_percent = _current_battery_percent - 0.1;
    }
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
int SecurityBot::x_rechargestation(){
    return _x_rechargestation;
}
int SecurityBot::y_rechargestation(){
    return _y_rechargestation;
}