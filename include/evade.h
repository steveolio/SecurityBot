#ifndef _SECURITYBOT_EVADE_H
#define _SECURITYBOT_EVADE_H

#include "securitybot.h"

namespace securitybot {

    using namespace std::chrono;
    using namespace elma;

    class SecurityBot;  // Declare containing class so it can be refered to here
                        // before it is defined in securitybot.h 

    //! The Evade an intruder state of the securitybot
    class EvadeState : public State {        

        public:
        //! Build a new EvadeState state
        EvadeState() : State("evade") {}
        void entry(const Event& e) {}
        //! Perform actions required when in the evade station state 
        void during();  
        void exit(const Event&) {}
        //! \return A reference to the containing finite state machine object
        SecurityBot& securitybot();    

    };

}

#endif