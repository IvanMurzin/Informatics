#include "Action.h"

#include <utility>

Action::Action(Message &message, VoidCallback onSelect) : message(message), onSelect(onSelect) {}

Message &Action::getMessage() const {
    return message;
}

void Action::select() const {
    onSelect();
}
