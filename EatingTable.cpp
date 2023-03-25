//
// Created by dell on 25.03.2023.
//

#include "EatingTable.h"

EatingTable::EatingTable(IView& view, int numberOfPhilosophers) {
    this->view = view;
    this->numberOfPhilosophers = numberOfPhilosophers;
    this->forks = new std::mutex[numberOfPhilosophers];
}

void* EatingTable::philosopher(void* value){
    int id = *((int*) value);
    int nextId = getNearPhilosopherId(id);
    while(true){
        changeOfState(PhilosopherState::WAITING, id);
        lock(forks[id],forks[nextId]);
        changeOfState(PhilosopherState::EATING, id);
        forks[id].unlock();
        forks[nextId].unlock();
        changeOfState(PhilosopherState::THINKING, id);
    }
    return 0;
}

void EatingTable::changeOfState(PhilosopherState philosopherState, int id){
    viewMutex.lock();
    view.displayState(philosopherState, id);
    viewMutex.unlock();
}

int EatingTable::getNearPhilosopherId(int id){                   //Philosopher on the right
    if(id == numberOfPhilosophers - 1) return 0;
    return id+1;
}

void* EatingTable::philosopherHelper(void *id){
    return ((EatingTable *) id)->philosopher(id);
}
