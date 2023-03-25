//
// Created by dell on 25.03.2023.
//

#include "EatingTable.h"

EatingTable::EatingTable(IView& view) {
    this->view = view;
    this->numberOfPhilosophers = IView::inputNumberOfPhilosophers(); //TU SIE ZATRZYMUJE
    this->philosophers = new pthread_t[numberOfPhilosophers];
    this->forks = new std::mutex[numberOfPhilosophers];
}

void EatingTable::start(){
    createPhilosophers();
}

void EatingTable::stop(){
    joinPhilosophers();
}

void EatingTable::createPhilosophers(){
    int ids[numberOfPhilosophers];
    for(int i = 0 ; i < numberOfPhilosophers; i++){
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, &EatingTable::philosopherHelper, (void*) &ids[i]);
    }
}

void EatingTable::joinPhilosophers(){
    for(int i = 0 ; i < numberOfPhilosophers; i++){
        pthread_join(philosophers[i], 0);
    }
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

void* EatingTable::philosopherHelper(void *id){
    return ((EatingTable *) id)->philosopher(id);
}

int EatingTable::getNumberOfPhilosophers(){
    return numberOfPhilosophers;
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
