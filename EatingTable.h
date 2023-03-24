//
// Created by dell on 24.03.2023.
//

#ifndef DININGPHILOSOPHERS_V2_EATINGTABLE_H
#define DININGPHILOSOPHERS_V2_EATINGTABLE_H
#include "view/IView.h"


class EatingTable {

private:
public:
    EatingTable(IView view, int numberOfPhilosophers);

private:
    int numberOfPhilosophers;
    //mutex *forks
    //mutex view
    IView view;

    int getNumberOfPhilosophers();

    void *philosopher(void);
    static void *philosopherHelper(void *context);

    void eat(int id);
    void wait(int  id);
    void think(int id);

};


#endif //DININGPHILOSOPHERS_V2_EATINGTABLE_H
