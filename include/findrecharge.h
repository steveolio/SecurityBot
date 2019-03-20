#ifndef _SECURITYBOT_FINDRECHARGE_H
#define _SECURITYBOT_FINDRECHARGE_H

#include "securitybot.h"

namespace securitybot {

    using namespace std::chrono;
    using namespace elma;

    class SecurityBot;  // Declare containing class so it can be refered to here
                        // before it is defined in securitybot.h 

    //! The Find Recharge Station state of the securitybot
    class FindRechargeState : public State {        

        public:
        //! Build a new FindRechargeState state
        FindRechargeState() : State("find recharge station") {}
        void entry(const Event& e) {}
        //! Perform actions required when in the find recharge station state 
        void during();     
        void exit(const Event&) {}
        //! \return A reference to the containing finite state machine object
        SecurityBot& securitybot();    

    };

}

#endif