//
// Created by dell on 24.03.2023.
//

#include "IView.h"

int IView::inputNumberOfPhilosophers(){
    int x;
    std::cin >> x;
    return x;
}

void IView::displayHeadline(){

}

void IView::displayState(PhilosopherState philosopherState, int id){
    switch(philosopherState){
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