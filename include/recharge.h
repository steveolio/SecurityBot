#ifndef _SECURITYBOT_RECHARGE_H
#define _SECURITYBOT_RECHARGE_H

#include "securitybot.h"

namespace securitybot {

    using namespace std::chrono;
    using namespace elma;

    class SecurityBot;  // Declare containing class so it can be refered to here
                        // before it is defined in securitybot.h 

    //! The wander state of the securitybot
    class RechargeState : public State {        

        public:
        //! Build a new on state
        RechargeState() : State("recharge") {}
        void entry(const Event& e) {}
        void during() {}

        //! Perform actions required when switching from off to on
        //! \param e The event that triggered the transition        
        void exit(const Event&);
  
        SecurityBot& securitybot();    

    };

}

#endif