#ifndef _SECURITYBOT_RECHARGE_H
#define _SECURITYBOT_RECHARGE_H

#include "securitybot.h"

namespace securitybot {

    using namespace std::chrono;
    using namespace elma;

    class SecurityBot;  // Declare containing class so it can be refered to here
                        // before it is defined in securitybot.h 

    //! The Recharge the battery state of the securitybot
    class RechargeState : public State {        

        public:
        //! Build a new RechargeState state
        RechargeState() : State("recharge") {}
        void entry(const Event& e) {}
        //! Perform actions required when in the recharge state 
        void during();      
        void exit(const Event&) {}
        //! \return A reference to the containing finite state machine object
        SecurityBot& securitybot();    

    };

}

#endif