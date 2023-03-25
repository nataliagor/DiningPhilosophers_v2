#include <iostream>
#include <pthread.h>
#include <thread>
#include <vector>
#include <csignal>
#include <mutex>
#include "view/IView.h"
#include "view/ConsoleView.h"
#include "view/TerminalView.h"

#define numberOfPhilosophers 5

pthread_t philosophers[numberOfPhilosophers];
std::mutex forks[numberOfPhilosophers];
std::mutex viewMutex;
IView* view;

void* philosopher(void* value);
void changeOfState(PhilosopherState philosopherState, int id);
int getNearPhilosopherId(int id);

int main() {
    view = new IView();

    int ids[numberOfPhilosophers];
    for(int i = 0 ; i < numberOfPhilosophers; i++){
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, (void*) &ids[i]);
    }
    for(int i = 0 ; i < numberOfPhilosophers; i++){
        pthread_join(philosophers[i], 0);
    }

    delete view;
    return 0;
}

void* philosopher(void* value){
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

void changeOfState(PhilosopherState philosopherState, int id){
    viewMutex.lock();
    view->displayState(philosopherState, id);
    viewMutex.unlock();
}

int getNearPhilosopherId(int id){                   //Philosopher on the right
    if(id == numberOfPhilosophers - 1) return 0;
    return id+1;
}
