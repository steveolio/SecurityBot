#include <iostream>
#include <chrono>
#include <vector>
#include <ncurses.h>

#include "securitybot.h"
#include "intruder.h"

using namespace std::chrono;
using namespace elma;
using namespace securitybot;

int main() {

    Manager m;
    Channel intruderx("Intruder_X");
    Channel intrudery("Intruder_Y");
    SecurityBot securitybot;
    Intruder intruder(securitybot);
    UserInterface ui(securitybot, intruder);

    m.schedule(ui, 10_ms)
     .schedule(securitybot, 750_ms) 
     .schedule(intruder, 300_ms) 
     .add_channel(intruderx)
     .add_channel(intrudery)   
     .init()
     .run();

    endwin();     
     
}