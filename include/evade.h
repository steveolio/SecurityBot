#ifndef _SECURITYBOT_EVADE_H
#define _SECURITYBOT_EVADE_H

#include "securitybot.h"

namespace securitybot {

    using namespace std::chrono;
    using namespace elma;

    class SecurityBot;  // Declare containing class so it can be refered to here
                        // before it is defined in securitybot.h 

    //! The wander state of the securitybot
    class EvadeState : public State {        

        public:
        //! Build a new on state
        EvadeState() : State("evade") {}
        void entry(const Event& e) {}
        void during() {}

        //! Perform actions required when switching from off to on
        //! \param e The event that triggered the transition        
        void exit(const Event&);
  
        SecurityBot& securitybot();    

    };

}

#endif