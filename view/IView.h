//
// Created by dell on 24.03.2023.
//

#ifndef DININGPHILOSOPHERS_V2_IVIEW_H
#define DININGPHILOSOPHERS_V2_IVIEW_H


class IView {
public:
    static int inputNumberOfPhilosophers();
    void displayHeadline();

    void displayEating(int id);
    void displayWaiting(int id);
    void displayThinking(int id);

    bool exitView();
};


#endif //DININGPHILOSOPHERS_V2_IVIEW_H
