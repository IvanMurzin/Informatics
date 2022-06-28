#include "KeyboardInput.h"

const char *getName(KeyboardInput input) {
    switch (input) {
        case up:
            return "up";
        case down:
            return "down";
        case left:
            return "left";
        case right:
            return "right";
        case quit:
            return "quit";
        case back:
            return "back";
        default:
            return "none";
    }
}

KeyboardInput toKeyboardInput(int arrowCode) {
    switch (arrowCode) {
        case 'A':
            return up;
        case 'B':
            return down;
        case 'C':
            return right;
        case 'D':
            return left;
        case '!':
            return back;
        case 13:
            return enter;
        case '<':
            return back;
        default:
            return none;
    }
}
