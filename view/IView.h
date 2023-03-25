//
// Created by dell on 24.03.2023.
//

#ifndef DININGPHILOSOPHERS_V2_IVIEW_H
#define DININGPHILOSOPHERS_V2_IVIEW_H
#include <iostream>
#include "../PhilosopherState.h"

class IView {
public:

    static int inputNumberOfPhilosophers();
    void displayHeadline();
    void displayState(PhilosopherState philosopherState, int id);
    bool exitView();
};


#endif //DININGPHILOSOPHERS_V2_IVIEW_H
