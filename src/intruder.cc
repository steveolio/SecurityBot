#include <unistd.h>
#include <sstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "securitybot.h"

using namespace securitybot;

Intruder::Intruder(SecurityBot& sw) : Process("intruder"), _securitybot(sw) {
    _current_intruder_x = _securitybot.x_upperboundry();
    _current_intruder_y = _securitybot.y_upperboundry();
};

void Intruder::update() {
    int x_offset, y_offset, temp_x, temp_y;   // initialize new variables
    srand (time(NULL)); // initialize random seed
    x_offset = rand() %3+1; // generate secret number between 1 and 3
    x_offset = x_offset -2; // change number to be between -1 and 1
    y_offset = rand() %3+1; // generate secret number between 1 and 3
    y_offset = y_offset -2; // change number to be between -1 and 1
    temp_x = _current_intruder_x + x_offset;
    temp_y = _current_intruder_y + y_offset;
    //Check outer boundries
    if( (temp_x < _securitybot.x_lowerboundry()) || (temp_x > _securitybot.x_upperboundry()) ){
        temp_x = _current_intruder_x;
    }
    if( (temp_y < _securitybot.y_lowerboundry()) || (temp_y > _securitybot.y_upperboundry()) ){
        temp_y = _current_intruder_y;
    }
    _current_intruder_x = temp_x;    // change the current x location
    _current_intruder_y = temp_y;    // change the current y location
}

int Intruder::current_intruder_x(){
    return _current_intruder_x;
}

int Intruder::current_intruder_y(){
    return _current_intruder_y;
}