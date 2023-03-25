//
// Created by dell on 25.03.2023.
//

#ifndef DININGPHILOSOPHERS_V2_EATINGTABLE_H
#define DININGPHILOSOPHERS_V2_EATINGTABLE_H
#include <iostream>
#include <pthread.h>
#include <mutex>
#include <chrono>
#include <thread>
#include "view/IView.h"
#include "PhilosopherState.h"

class EatingTable {

public:
    EatingTable(IView& view);
    void start();
    void stop();
    int getNumberOfPhilosophers();
    void createPhilosophers();
    void joinPhilosophers();

//private:
    int numberOfPhilosophers;
    pthread_t *philosophers;
    std::mutex *forks;
    std::mutex viewMutex;
    IView view;

    void *philosopher(void* value);
    static void *philosopherHelper(void *id);
    void changeOfState(PhilosopherState philosopherState, int id);
    int getNearPhilosopherId(int id);
};


#endif //DININGPHILOSOPHERS_V2_EATINGTABLE_H
