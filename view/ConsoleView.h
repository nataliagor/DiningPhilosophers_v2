//
// Created by dell on 24.03.2023.
//

#ifndef DININGPHILOSOPHERS_V2_CONSOLEVIEW_H
#define DININGPHILOSOPHERS_V2_CONSOLEVIEW_H

#include "IView.h"

class ConsoleView  : public IView{
    virtual int inputNumberOfPhilosophers();
    virtual void displayState(PhilosopherState philosopherState, int id, int eatingTimes, int waitingTime, int stateTime);
    virtual void exitView();
    virtual bool exitCondition();
};


#endif //DININGPHILOSOPHERS_V2_CONSOLEVIEW_H
