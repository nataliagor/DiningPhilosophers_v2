//
// Created by dell on 24.03.2023.
//

#ifndef DININGPHILOSOPHERS_V2_CONSOLEVIEW_H
#define DININGPHILOSOPHERS_V2_CONSOLEVIEW_H

#include "IView.h"

class ConsoleView  : public IView{
    virtual int inputNumberOfPhilosophers();
    virtual void displayHeadline();
    virtual void displayState(PhilosopherState philosopherState, int id);
    virtual bool exitView();
};


#endif //DININGPHILOSOPHERS_V2_CONSOLEVIEW_H
