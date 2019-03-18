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

        /*
        //! Start the securitybot
        void begin();

        //! Reset the securitybot
        void reset();

        //! Stop the securitybot
        void stop();

        //! Add a lap time to the list of lap times.
        void lap();
        */

        //! Get the time stored by the stopwatch
        //high_resolution_clock::duration value();

        //! Get a list of lap times
        //const vector<high_resolution_clock::duration>& laps() { return _laps; }

        private:

        // When overriding the StateMachine class, put state declarations here.
        WanderState wander;
        MakeNoiseState makenoise;
        EvadeState evade;
        FindRechargeState findrecharge;
        RechargeState recharge;

        // Other private variables
        //bool _running;
        //high_resolution_clock::time_point _start_time;
        //high_resolution_clock::duration _elapsed;
        //vector<high_resolution_clock::duration> _laps;

    };

}

#endif