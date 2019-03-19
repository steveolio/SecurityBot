#include <iostream>
#include <chrono>
#include <vector>
#include <ncurses.h>

#include "securitybot.h"

using namespace std::chrono;
using namespace elma;
using namespace securitybot;

int main() {

    Manager m;
    SecurityBot securitybot;
    UserInterface ui(securitybot);

    m.schedule(ui, 10_ms)
     .schedule(securitybot, 1000_ms)     
     .init()
     .run();

    endwin();     
     
}