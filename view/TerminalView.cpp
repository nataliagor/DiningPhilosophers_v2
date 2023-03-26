//
// Created by dell on 24.03.2023.
//

#include "TerminalView.h"

TerminalView::TerminalView() {
    initscr();
    start_color();
    init_pair(0,COLOR_GREEN,COLOR_BLACK);
    init_pair(1,COLOR_BLACK,COLOR_GREEN);
}

int TerminalView::inputNumberOfPhilosophers(){
    return 5;
}

void TerminalView::displayHeadline(){
    attron(A_BOLD);
    attron(COLOR_PAIR(1));

    mvprintw(0,0, "Nr filozofa ");
    mvprintw(0,12, "| Stan filozofa   ");
    mvprintw(0,30, "| Czas oczekiwania ");
    mvprintw(0,49, "| Ilosc zjedzonych posilkow ");
    mvprintw(0,77, "| Poziom stresu ");

    attroff(A_BOLD);
    attroff(COLOR_PAIR(1));
    refresh();
}

void TerminalView::displayState(PhilosopherState philosopherState, int id) {
    if(id%2 == 0)  attron(COLOR_PAIR(1));
    else attron(COLOR_PAIR(0));

    switch (philosopherState) {
        case PhilosopherState::WAITING:
            mvprintw(id+1,0, "Filozof %d  | Czeka przy stole |                  |                           |               ", id);
            break;
        case PhilosopherState::EATING:
            mvprintw(id+1,0, "Filozof %d  |   je posilek     |                  |                           |               ", id);
            break;
        case PhilosopherState::THINKING:
            mvprintw(id+1,0, "Filozof %d  |      mysli       |                  |                           |               ", id);
            break;
        default:
            break;
    }

    if(id%2 == 0)  attroff(COLOR_PAIR(1));
    else attroff(COLOR_PAIR(0));
    refresh();
}

bool TerminalView::exitView(){

    return true;
}

