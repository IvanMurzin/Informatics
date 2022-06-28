#ifndef KEYBOARDINPUT_H
#define KEYBOARDINPUT_H
typedef enum KeyboardInput {
    up,
    down,
    left,
    right,
    none,
    quit,
    enter,
    back
} KeyboardInput;

const char *getName(KeyboardInput input);

KeyboardInput toKeyboardInput(int arrowCode);

#endif
