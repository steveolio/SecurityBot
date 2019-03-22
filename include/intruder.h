#ifndef _SECURITYBOT_INTRUDER_H
#define _SECURITYBOT_INTRUDER_H

#include <iostream>
#include <chrono>
#include <vector>
#include <ncurses.h>

#include "securitybot.h"

namespace securitybot {

    using namespace std::chrono;
    using namespace elma;
    using namespace securitybot;

    //! An Intruder for the SecurityBot object
    class Intruder : public Process {

        public:

        //! Create a new Intruder for the SecurityBot object
        //! \param sw A reference to a SecurityBot object
        Intruder(SecurityBot& sw);

        void init() {}
        void start() {}

        //! Return the current x location of securitybot
        int current_intruder_x();

        //! Return the current y location of securitybot
        int current_intruder_y();

        //! Return the absolute distance between SecurityBot and Intruder x
        int distance_to_intruder_x();

        //! Return the absolute distance between SecurityBot and Intruder y
        int distance_to_intruder_y();

        //! Update the position of the Intruder and move around the room
        void update();

        void stop() {}

        private:
        SecurityBot& _securitybot;

        int _current_intruder_x = 0;
        int _current_intruder_y = 0;
    };

}

#endif