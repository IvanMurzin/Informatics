#include <stdlib.h>
#include "Game.h"
#include "ConsoleUtil.h"
#include "Field.h"
#include "Stack.h"


int isWin(Field *field) {
    if (field->empty.x != field->size - 1 || field->empty.y != field->size - 1) return 0;
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

int canMove(Field *field) {
    int x = field->selected.x;
    int y = field->selected.y;
    if (x < 0 || x >= field->size || y < 0 || y >= field->size)
        return 0;
    int dx = abs(x - field->empty.x);
    int dy = abs(y - field->empty.y);
    if (dx > 1 || dy > 1 || dx + dy != 1)
        return 0;
    return 1;
}


void swap(Field *field) {
    Point selected = field->selected;
    int temp = field->data[selected.y][selected.x];
    field->data[selected.y][selected.x] = field->data[field->empty.y][field->empty.x];
    field->data[field->empty.y][field->empty.x] = temp;
    field->empty = selected;
}

int select(Field *field, int x, int y) {
    Point point = {x, y};
    if (x < 0 || x >= field->size ||
        y < 0 || y >= field->size ||
        isEmpty(field, point)) {
        return 0;
    }
    field->selected = point;
    return 1;
}

int move(Field *field) {
    if (!canMove(field)) {
        highlightField(field, red);
        return 0;
    }
    swap(field);
    return 1;
}

void transfer(Field *field, KeyboardInput input) {
    int x = field->selected.x;
    int y = field->selected.y;
    switch (input) {
        case up:
            select(field, x, y - 1);
            break;
        case down:
            select(field, x, y + 1);
            break;
        case left:
            select(field, x - 1, y);
            break;
        case right:
            select(field, x + 1, y);
        default:
            return;
    }
}

void destroyGameData(Field *field, Stack *stack) {
    for (int i = 0; i < field->size; ++i) free(field->data[i]);
    free(field->data);
    free(field);
    destroy(stack);
}

void start() {
    printGreetings();
    int fieldSize = getFieldSize();
    Field *field = getField(fieldSize);
    Stack *stack = getStack();
    defaultPrintField(field);
    KeyboardInput input;
    int flag = 0;
    while (!flag) {
        input = getKeyboardInput();
        switch (input) {
            case enter:
                system("stty sane");
                Point empty = field->empty;
                if (move(field)) push(stack, empty);
                if (isWin(field)) flag = 1;
                break;
            case quit:
                system("stty sane");
                flag = 2;
                break;
            case back:
                system("stty sane");
                pop(stack, &field->selected);
                move(field);
            default:
                transfer(field, input);
        }
        defaultPrintField(field);
    }
    if (flag == 1) {
        printField(field, green, 1);
        printCongratulations();
    } else printFarewell();
    destroyGameData(field, stack);
}

Game *getGame() {
    Game *game = malloc(sizeof(Game));
    game->start = &start;
    return game;
}
