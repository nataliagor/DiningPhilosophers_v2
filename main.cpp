#include <iostream>
#include <pthread.h>
#include <thread>
#include <vector>
#include <csignal>
#include <chrono>
#include <mutex>
#include "view/IView.h"
#include "view/ConsoleView.h"
#include "view/TerminalView.h"
using namespace std::chrono;

#define numberOfPhilosophers 5

pthread_t philosophers[numberOfPhilosophers];
std::mutex forks[numberOfPhilosophers];
std::mutex viewMutex;
IView* view;

void* philosopher(void* value);
void changeOfState(PhilosopherState philosopherState, int id, int eatingTimes, int waitingTime);
int getNearPhilosopherId(int id);
void viewHandler();

int main() {
    viewHandler();                                                                                              //view
    int ids[numberOfPhilosophers];
    for(int i = 0 ; i < numberOfPhilosophers; i++){                                                             //creating threads
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, (void*) &ids[i]);
    }
    for(int i = 0 ; i < numberOfPhilosophers; i++){                                                             //joining threads
        pthread_join(philosophers[i], 0);
    }

    delete view;
    return 0;
}

void* philosopher(void* value){
    int id = *((int*) value);
    int nextId = getNearPhilosopherId(id);
    int eatingTimes = 0;
    int waitingTime = 0;
    auto startWaiting = high_resolution_clock::now();

    while(true){
        changeOfState(PhilosopherState::WAITING, id, eatingTimes, waitingTime);             //waiting
        lock(forks[id],forks[nextId]);
        auto endWaiting = high_resolution_clock::now();                                      //calculating waiting time
        waitingTime = duration_cast<seconds>(endWaiting - startWaiting).count();

        eatingTimes++;                                                                                   //eating
        changeOfState(PhilosopherState::EATING, id, eatingTimes, waitingTime);
        forks[id].unlock();
        forks[nextId].unlock();

        waitingTime = 0;                                                                                //thinking
        changeOfState(PhilosopherState::THINKING, id, eatingTimes, waitingTime);
        startWaiting = high_resolution_clock::now();
    }
    return 0;
}

void changeOfState(PhilosopherState philosopherState, int id, int eatingTimes, int waitingTime){
    int stateTime = rand()%4;
    viewMutex.lock();
    view->displayState(philosopherState, id, eatingTimes, waitingTime, stateTime);
    viewMutex.unlock();
    if(philosopherState == PhilosopherState::THINKING || philosopherState == PhilosopherState::EATING) sleep(stateTime);
}

int getNearPhilosopherId(int id){                           //Philosopher on the right
    if(id == numberOfPhilosophers - 1) return 0;
    return id+1;
}

void viewHandler(){
    view = new TerminalView();
    view->displayHeadline();
    view->exitView();
}

