#ifndef _SECURITYBOT_MAKENOISE_H
#define _SECURITYBOT_MAKENOISE_H

#include "securitybot.h"

namespace securitybot {

    using namespace std::chrono;
    using namespace elma;

    class SecurityBot;  // Declare containing class so it can be refered to here
                        // before it is defined in securitybot.h 

    //! The Sound the alarm state of the securitybot
    class MakeNoiseState : public State {        

        public:
        //! Build a new MakeNoiseState state
        MakeNoiseState() : State("make noise") {}
        void entry(const Event& e) {}
        //! Perform actions required when in the make noise state 
        void during();        
        void exit(const Event&) {}
        //! \return A reference to the containing finite state machine object
        SecurityBot& securitybot();    

    };

}

#endif