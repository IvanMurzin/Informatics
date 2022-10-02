#include <iostream>
#include "Dialog.h"
#include "Scanner.h"

void Dialog::addAction(Message &message, VoidCallback onSelect) {
    actions.push_back(Action(message, onSelect));
}

void Dialog::show() const {
    std::cout << "0. Exit program" << std::endl;
    for (int i = 0; i < actions.size(); ++i) {
        std::cout << i + 1 << ". " << actions[i].getMessage() << std::endl;
    }
}

bool Dialog::select() const {
    show();
    int actionIndex = in.next<int>(0, actions.size(), "Enter your command: ");
    if (actionIndex == 0) {
        std::cout << "Bye";
        return false;
    }
    actions[actionIndex - 1].select();
    return true;
}

const Scanner &Dialog::getScanner() const {
    return in;
}

void Dialog::run() const {
    while (select());
}
