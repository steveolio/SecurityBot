#include <unistd.h>
#include "securitybot.h"

using namespace securitybot;

UserInterface::UserInterface(SecurityBot& sw) : Process("user input"), _securitybot(sw) {
    initscr();   // Start ncurses
    timeout(1);  // Timeout for waiting for user input
    noecho();    // Do not echo user input to the screen
    curs_set(0); // Do not show the cursor
};

// void UserInterface::show_time(int x, int y, high_resolution_clock::duration d) {

//     // Print the time at the desired position.
//     // mvprintw just calls sprintf
//     mvprintw(x,y,"%d:%02d:%02d", 
//         std::chrono::duration_cast<std::chrono::minutes>(d).count(),
//         std::chrono::duration_cast<std::chrono::seconds>(d).count()%60,
//         (std::chrono::duration_cast<std::chrono::milliseconds>(d).count()%1000)/10
//     );
// }

void UserInterface::update() {

    // USER INPUT
    // get a character from the user, if one is ready.
    // If no character is ready, getch() returns ERR (which is
    // ignored below since there is no condition in the switch statement)
    int c = getch();

    switch ( c ) {            
        case 'i':
            emit(Event("intruder detected"));
            break;
        case 'r':
            emit(Event("reset"));
            //clear(); // Clear the screen of old stuff
            break;
        case 'p':
            emit(Event("proximity warning"));
            break;
        case 'e':
            emit(Event("battery low"));
            break;
        case 'f':
            emit(Event("battery full"));
            break;
        case 's':
            emit(Event("found recharge station"));
            break;
        case 'q':
            std::cout << "halting\n";
            halt();
            break;
    }

    // OUTPUT
    //Print the current state somehow???
    //show_time(1,1,_stopwatch.value()); 
    std::string temporaryState = _securitybot.currentState();
    // TODO: I need to clear the line before a new line is displayed
    mvprintw(1,1,"%s", temporaryState.c_str());
    mvprintw(3,1,"Intruder Detected(i), Proximity Warning(p), Reset(r), Battery Low(e), Found Recharge Station(s), Battery Full(f), Quit(q)");
    // PRINT the lab list if needed
    // for ( int i=0; i<_stopwatch.laps().size(); i++ ) {
    //     mvprintw(5+i, 1, "Lap %d", _stopwatch.laps().size()-i);
    //     show_time(5+i, 10, _stopwatch.laps()[i]);
    // }

    // NOTE: Since the stopwatch is running every 10 ms, we should sleep
    //       the ui to give processing time back to the OS. It is debatable
    //       whether this is the right place to put this. It could also become
    //       an Elma feature, or it could go in the StopWatch class, etc.
    //       The number 9999 should also be a parameter and not a constant.
    usleep(9999);

}