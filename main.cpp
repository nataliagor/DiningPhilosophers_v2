#include <iostream>
#include "EatingTable.h"
#include "view/IView.h"
#include "view/ConsoleView.h"
#include "view/TerminalView.h"
std::mutex* forks;
std::mutex viewMutex;

int main() {
    IView* view = new IView();
    EatingTable* eatingTable = new EatingTable(*view);
    int ids[eatingTable->getNumberOfPhilosophers()];
    for(int i = 0 ; i < eatingTable->getNumberOfPhilosophers(); i++){
        ids[i] = i;
        pthread_create(&eatingTable->philosophers[i], NULL, &EatingTable::philosopherHelper, (void*) &ids[i]);
    }
    /*for(int i = 0 ; i < eatingTable->getNumberOfPhilosophers(); i++){
        pthread_join(eatingTable->philosophers[i], 0);
    }*/
    return 0;
}
