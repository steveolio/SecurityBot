#ifndef _SECURITYBOT_UI_H
#define _SECURITYBOT_UI_H

#include <iostream>
#include <chrono>
#include <vector>
#include <ncurses.h>

#include "securitybot.h"

namespace securitybot {

    using namespace std::chrono;
    using namespace elma;
    using namespace securitybot;

    //! A user interface for the a SecurityBot object
    class UserInterface : public Process {

        public:

        //! Create a new securitybot user interface using curses
        //! \param sw A reference to a SecurityBot object
        UserInterface(SecurityBot& sw);

        void init() {}
        void start() {}

        // TODO: Create new functions for what I need....
        //! Display the time at the given x,y position on the screen
        //void show_time(int x, int y, high_resolution_clock::duration d);

        //! Update the user interface by (a) reading keyboard input and (b) writing to the screen
        void update();
        void stop() {}

        private:
        SecurityBot& _securitybot;

    };

}

#endif