#include <stdlib.h>
#include "Game.h"
#include "ConsoleUtil.h"
#include "Field.h"
#include "Stack.h"

Field *field;
Stack *stack;

int isWin() {
    if (field->emptyX != field->size - 1 || field->emptyY != field->size - 1) return 0;
    int previous = field->data[0][0];
    for (int i = 0; i < field->size; ++i) {
        for (int j = 0; j < field->size; ++j) {
            if (i == field->size - 1 && j == field->size - 1) break;
            if (field->data[i][j] < previous) return 0;
            previous = field->data[i][j];
        }
    }
    return 1;
}

int canMove() {
    int x = field->selectedX;
    int y = field->selectedY;
    if (x < 0 || x >= field->size || y < 0 || y >= field->size)
        return 0;
    int dx = abs(x - field->emptyX);
    int dy = abs(y - field->emptyY);
    if (dx > 1 || dy > 1 || dx + dy != 1)
        return 0;
    return 1;
}


void swap() {
    int x = field->selectedX;
    int y = field->selectedY;
    int temp = field->data[y][x];
    field->data[y][x] = field->data[field->emptyY][field->emptyX];
    field->data[field->emptyY][field->emptyX] = temp;
    field->emptyX = x;
    field->emptyY = y;
}

int select(int x, int y) {
    if (x < 0 || x >= field->size || y < 0 || y >= field->size || isEmpty(field, x, y)) {
        return 0;
    }
    field->selectedX = x;
    field->selectedY = y;
    return 1;
}

int move() {
    if (!canMove()) {
        highlightField(field, red);
        return 0;
    }
    swap();
    return 1;
}

void transfer(KeyboardInput input) {
    int x = field->selectedX;
    int y = field->selectedY;
    switch (input) {
        case up:
            select(x, y - 1);
            break;
        case down:
            select(x, y + 1);
            break;
        case left:
            select(x - 1, y);
            break;
        case right:
            select(x + 1, y);
        default:
            return;
    }
}

void destroyGameData() {
    for (int i = 0; i < field->size; ++i) free(field->data[i]);
    free(field->data);
    free(field);
    destroy(stack);
}

void start() {
    printGreetings();
    int fieldSize = getFieldSize();
    field = getField(fieldSize);
    stack = getStack();
    defaultPrintField(field);
    KeyboardInput input;
    int flag = 0;
    while (!flag) {
        input = getKeyboardInput();
        switch (input) {
            case enter:
                system("stty sane");
                int x = field->emptyX;
                int y = field->emptyY;
                if (move()) push(stack, x, y);
                if (isWin()) flag = 1;
                break;
            case quit:
                system("stty sane");
                flag = 2;
                break;
            case back:
                system("stty sane");
                pop(stack, &field->selectedX, &field->selectedY);
                move();
            default:
                transfer(input);
        }
        defaultPrintField(field);
    }
    if (flag == 1) {
        printField(field, green, 1);
        printCongratulations();
    } else printFarewell();
    destroyGameData();
}

Game *getGame() {
    Game *game = malloc(sizeof(Game));
    game->start = &start;
    return game;
}
