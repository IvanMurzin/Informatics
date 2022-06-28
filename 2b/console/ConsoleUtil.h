#ifndef CONSOLEUTIL_H
#define CONSOLEUTIL_H

#include "Field.h"
#include "Color.h"
#include "KeyboardInput.h"

void printField(Field *field, COLOR color, int solid);

void defaultPrintField(Field *field);

void highlightField(Field *field, COLOR color);

KeyboardInput getKeyboardInput();

void printFarewell();

void printGreetings();

int getFieldSize();

void printCongratulations();

#endif
