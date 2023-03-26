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
    virtual void displayHeadline() = 0;
    virtual void displayState(PhilosopherState philosopherState, int id) = 0;
    virtual bool exitView() = 0;

};


#endif //DININGPHILOSOPHERS_V2_IVIEW_H
