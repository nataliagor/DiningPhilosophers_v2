//
// Created by dell on 24.03.2023.
//

#ifndef DININGPHILOSOPHERS_V2_IVIEW_H
#define DININGPHILOSOPHERS_V2_IVIEW_H
#include <iostream>
#include <thread>
#include "../PhilosopherState.h"

class IView {
public:
    virtual int inputNumberOfPhilosophers() = 0;
    virtual void displayState(PhilosopherState philosopherState, int id, int eatingTimes, int waitingTime, int stateTime) = 0;
    virtual void exitView() = 0;
    virtual bool exitCondition() = 0;

};


#endif //DININGPHILOSOPHERS_V2_IVIEW_H
