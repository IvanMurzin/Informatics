#pragma once

#include <vector>
#include "Action.h"
#include "Scanner.h"


class Dialog {
private:
    std::vector<Action> actions;
    Scanner in = Scanner(std::cin);

    void show() const;

public:
    Dialog() = default;

    const Scanner &getScanner() const;

    void addAction(Message &message, VoidCallback onSelect);

    bool select() const;

    void run() const;

};