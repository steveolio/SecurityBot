#ifndef _SECURITYBOT_H
#define _SECURITYBOT_H

#include "elma/elma.h" // Note installation directory for elma

#include "wander.h"
#include "makenoise.h"
#include "evade.h"
#include "findrecharge.h"
#include "recharge.h"
#include "user_interface_securitybot.h"

namespace securitybot {

    using namespace std::chrono;
    using namespace elma;    

    //! A stop watch class, that inherits from StateMachine
    class SecurityBot : public StateMachine {

        public:
        //! Make a new securitybot
        SecurityBot();

        //! Return the current state of securitybot
        std::string currentState();

        //! Move to a new location for the securitybot.
        //! This function is used only when in the wander state
        void wanderMove();

        //! Return the current x location of securitybot
        int current_x();

        //! Return the current y location of securitybot
        int current_y();

        //! Return the lower boundry of x in the map for securitybot
        int x_lowerboundry();

        //! Return the upper boundry of x in the map for securitybot
        int x_upperboundry();

        //! Return the lower boundry of y in the map for securitybot
        int y_lowerboundry();

        //! Return the upper boundry of y in the map for securitybot
        int y_upperboundry();

        private:

        // Override the StateMachine declarations
        WanderState wander;
        MakeNoiseState makenoise;
        EvadeState evade;
        FindRechargeState findrecharge;
        RechargeState recharge;

        // System private variables
        int _current_x = 0;
        int _current_y = 0;
        int _x_lowerboundry = 0;
        int _x_upperboundry = 10; // Rows
        int _y_lowerboundry = 0;
        int _y_upperboundry = 100; // columns
    };

}

#endif