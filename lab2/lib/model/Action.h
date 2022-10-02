#pragma once

#include <string>
#include <functional>
typedef const std::string Message;
typedef std::function<void()> VoidCallback;

class Action {
private:
    Message message;
    VoidCallback onSelect;

public:
    Action(Message & message, VoidCallback onSelect);

    Message &getMessage() const;

    void select() const;
};