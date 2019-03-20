#include <unistd.h>
#include "securitybot.h"

using namespace securitybot;

UserInterface::UserInterface(SecurityBot& sw) : Process("user input"), _securitybot(sw) {
    initscr();   // Start ncurses
    timeout(1);  // Timeout for waiting for user input
    noecho();    // Do not echo user input to the screen
    curs_set(0); // Do not show the cursor
};

void UserInterface::printMap(int startline) {
    std::string tempstring = "";
    for (int j = _securitybot.x_lowerboundry()-1; j <= _securitybot.x_upperboundry()+1; j++){ //row
        tempstring = "";
        for (int i = _securitybot.y_lowerboundry()-1; i <= _securitybot.y_upperboundry()+1; i++){ //column
            if(j == _securitybot.x_lowerboundry()-1 || j == _securitybot.x_upperboundry()+1){ //if first or last row
                tempstring = tempstring + "=";
            } else {                                                                          //all other rows
                if(i == _securitybot.y_lowerboundry()-1 || i == _securitybot.y_upperboundry()+1){ //if first or last column
                    tempstring = tempstring + "|";
                } else {                                                                     //all other columns
                    if( j == _securitybot.current_x() && i == _securitybot.current_y() ){  
                        tempstring = tempstring + "R";
                    } else {
                        tempstring = tempstring + " ";
                    }
                }
            }
        }
        move(j+startline, 0); clrtoeol(); // clear line of previous data
        mvprintw(j+startline,0,tempstring.c_str());
    }
    
}

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
    mvprintw(0,1," SSS  EEEE  CCCC  U  U  RRR   I  TTTTT  Y   Y  BBB    OOO   TTTTT");
    mvprintw(1,1,"S     E     C     U  U  R  R  I    T     Y Y   B  B  O   O    T");
    mvprintw(2,1," SS   EEEE  C     U  U  RRR   I    T      Y    BBB   O   O    T");
    mvprintw(3,1,"   S  E     C     U  U  R  R  I    T      Y    B  B  O   O    T");
    mvprintw(4,1,"SSS   EEEE  CCCC  UUUU  R  R  I    T      Y    BBB    OOO     T");
    // Leave next line blank
    move(6, 0); clrtoeol(); // clear line of previous data
    mvprintw(6,1,"Current SecurityBot State:%s", _securitybot.currentState().c_str());
    move(7, 0); clrtoeol(); // clear line of previous data
    mvprintw(7,1,"Current SecurityBot Location:%d,%d", _securitybot.current_x(),_securitybot.current_y());
    mvprintw(10,1,"Change State Manually:");
    mvprintw(10,1,"Intruder Detected(i), Proximity Warning(p), Reset(r), Battery Low(e), Found Recharge Station(s), Battery Full(f), Quit(q)");
    // PRINT the boundry and show wher the robot is
    
    int startline = 12;
    printMap(startline);
    // std::string tempstring = "";
    // for (int j = _securitybot.x_lowerboundry()-1; j <= _securitybot.x_upperboundry()+1; j++){ //row
    //     tempstring = "";
    //     for (int i = _securitybot.y_lowerboundry()-1; i <= _securitybot.y_upperboundry()+1; i++){ //column
    //         if(j == _securitybot.x_lowerboundry()-1 || j == _securitybot.x_upperboundry()+1){ //if first or last row
    //             tempstring = tempstring + "=";
    //         } else {                                                                          //all other rows
    //             if(i == _securitybot.y_lowerboundry()-1 || i == _securitybot.y_upperboundry()+1){ //if first or last column
    //                 tempstring = tempstring + "|";
    //             } else {                                                                     //all other columns
    //                 if( j == _securitybot.current_x() && i == _securitybot.current_y() ){  
    //                     tempstring = tempstring + "R";
    //                 } else {
    //                     tempstring = tempstring + " ";
    //                 }
    //             }
    //         }
    //     }
    //     move(j+offset, 0); clrtoeol(); // clear line of previous data
    //     mvprintw(j+offset,0,tempstring.c_str());
    // }
    
    // NOTE: Sleep the ui to give processing time back to the OS.
    usleep(9999);

}