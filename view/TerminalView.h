//
// Created by dell on 24.03.2023.
//

#ifndef DININGPHILOSOPHERS_V2_TERMINALVIEW_H
#define DININGPHILOSOPHERS_V2_TERMINALVIEW_H

#include "ncurses.h"
#include <string>
#include "IView.h"

class TerminalView : public IView {
public:
    TerminalView();

private:
    virtual int inputNumberOfPhilosophers();
    virtual void displayHeadline();
    virtual void displayState(PhilosopherState philosopherState, int id, int eatingTimes, int waitingTime, int stateTime);
    virtual bool exitView();
};


#endif //DININGPHILOSOPHERS_V2_TERMINALVIEW_H
