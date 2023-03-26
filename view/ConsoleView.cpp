//
// Created by dell on 24.03.2023.
//

#include "ConsoleView.h"

int ConsoleView::inputNumberOfPhilosophers(){
    int x;
    std::cin >> x;
    return x;
}

void ConsoleView::displayHeadline(){

}

void ConsoleView::displayState(PhilosopherState philosopherState, int id) {
    switch (philosopherState) {
        case PhilosopherState::WAITING:
            std::cout << id << " CZEKA" << std::endl;
            break;
        case PhilosopherState::EATING:
            std::cout << id << " JE" << std::endl;
            break;
        case PhilosopherState::THINKING:
            std::cout << id << " MYSLI" << std::endl;
            break;
        default:
            break;
    }
}

bool ConsoleView::exitView(){
    return true;
}