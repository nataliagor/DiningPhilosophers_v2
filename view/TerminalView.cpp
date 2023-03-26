//
// Created by dell on 24.03.2023.
//

#include "TerminalView.h"

TerminalView::TerminalView() {
    initscr();
    initializeColors();
    displayHeadline();
    displayExitCondition();
}

int TerminalView::inputNumberOfPhilosophers(){
    return 0;
}

void TerminalView::displayHeadline(){
    attron(A_BOLD);
    attron(COLOR_PAIR(1));

    mvprintw(0,0, "Nr filozofa ");
    mvprintw(0,12, "| Stan filozofa   ");
    mvprintw(0,30, "| Czas oczekiwania ");
    mvprintw(0,49, "| Ilosc zjedzonych posilkow ");
    mvprintw(0,77, "| Czas jedzenia ");
    mvprintw(0,93, "| Czas myslenia ");

    attroff(A_BOLD);
    attroff(COLOR_PAIR(1));
    refresh();
}

void TerminalView::displayState(PhilosopherState philosopherState, int id, int eatingTimes, int waitingTime, int stateTime) {
    if(id%2 == 0)  attron(COLOR_PAIR(2));
    else attron(COLOR_PAIR(1));

    switch (philosopherState) {
        case PhilosopherState::WAITING:
            mvprintw(id+1,0, "Filozof %d  | czeka przy stole |         %7ds |                   %7d |               |               ", id, waitingTime, eatingTimes);
            break;
        case PhilosopherState::EATING:
            mvprintw(id+1,0, "Filozof %d  |   je posilek     |         %7ds |                   %7d |       %7d |               ", id, waitingTime, eatingTimes, stateTime);
            break;
        case PhilosopherState::THINKING:
            mvprintw(id+1,0, "Filozof %d  |      mysli       |         %7ds |                   %7d |               |       %7d ", id, waitingTime, eatingTimes, stateTime);
            break;
        default:
            break;
    }

    if(id%2 == 0)  attroff(COLOR_PAIR(2));
    else attroff(COLOR_PAIR(1));
    refresh();
}

void TerminalView::exitView(){
    endwin();
}

bool TerminalView::exitCondition(){
    noecho();
    if(int esc=getch() != 27) return false;
    return true;
}

void TerminalView::displayExitCondition(){
    mvprintw(20,0, "Press ESC to exit ...");
    refresh();
}

void TerminalView::initializeColors(){
    start_color();
    init_pair(0,COLOR_GREEN,COLOR_BLACK);
    init_pair(1,COLOR_BLACK,COLOR_GREEN);
    init_pair(2,COLOR_BLACK,COLOR_MAGENTA);
}



