//
// Created by dell on 24.03.2023.
//

#include "ConsoleView.h"

int ConsoleView::inputNumberOfPhilosophers(){
    int x;
    std::cin >> x;
    return x;
}

void ConsoleView::displayState(PhilosopherState philosopherState, int id, int eatingTimes, int waitingTime, int stateTime) {
    switch (philosopherState) {
        case PhilosopherState::WAITING:
            std::cout << "Filozof " << id << " czeka, jedl razy: " << eatingTimes<< std::endl;
            break;
        case PhilosopherState::EATING:
            std::cout << "Filozof " << id << " je, jadl razy: " << eatingTimes <<  std::endl;
            break;
        case PhilosopherState::THINKING:
            std::cout << "Filozof " << id << " mysli, jadl razy: " << eatingTimes<<  std::endl;
            break;
        default:
            break;
    }
}

void ConsoleView::exitView(){
    std::cout << "ConsoleView::exitView -> brak inplemetacji" << std::endl;
}

bool ConsoleView::exitCondition(){
    std::cout << "ConsoleView::exitCondition -> brak inplemetacji" << std::endl;
    return false;
}
