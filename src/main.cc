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
    SecurityBot securitybot;
    Intruder intruder(securitybot);
    UserInterface ui(securitybot, intruder);

    m.schedule(ui, 10_ms)
     .schedule(securitybot, 1000_ms) 
     .schedule(intruder, 500_ms)    
     .init()
     .run();

    endwin();     
     
}