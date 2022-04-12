#include <stdlib.h>
#include <unistd.h>
#include "stdio.h"
#include "ConsoleUtil.h"
#include "readline/readline.h"

void printHeader(int length) {
    for (int i = 0; i < length; ++i) printf("════════");
    printf("\n");
    if (length % 2 == 0) {
        for (int i = 0; i < length; ++i) {
            if (i == length / 2 - 1) printf("      TAGS      ");
            else if (i != length / 2) printf("        ");
        }
    } else {
        for (int i = 0; i < length; ++i) {
            if (i == length / 2) printf("  TAGS  ");
            else printf("        ");
        }
    }
    printf("\n");
    for (int i = 0; i < length; ++i) printf("════════");
    printf("\n");
}

void coloredLine(int length, int up, int spaceAt, int selectedAt, COLOR color) {
    printf("%s", getColor(color));
    const char *brace = up ? "╚══════╝" : "╔══════╗"; //  ╚ ╔ ╩ ╦ ╠ ═ ╬ ╣ ║ ╗ ╝
    for (int i = 0; i < length; ++i) {
        const char *printData = i == spaceAt ? "        " : brace;
        if (i == selectedAt)
            printf("%s%s%s", getColor(green), printData, getColor(color));
        else
            printf("%s", printData);
    }
    printf("%s\n", getColor(reset));
}

void printSpace() {
    printf("        ");
}

void printValue(int data, COLOR color) {
    printf("%s║  %2d  ║%s", getColor(color), data, getColor(reset));
}

void defaultPrintField(Field *field) {
    printField(field, reset, 0);
}

void printField(Field *field, COLOR color, int solid) {
    system("clear");
    printHeader(field->size);
    for (int i = 0; i < field->size; ++i) {
        int spaceAt = i == field->emptyY ? field->emptyX : -1;
        int selectedAt = (!solid && i == field->selectedY) ? field->selectedX : -1;
        coloredLine(field->size, 0, spaceAt, selectedAt, color);
        for (int j = 0; j < field->size; ++j) {
            if (isEmpty(field, j, i)) printSpace();
            else if (solid || !isSelected(field, j, i)) printValue(field->data[i][j], color);
            else printValue(field->data[i][j], green);
        }
        printf("\n");
        coloredLine(field->size, 1, spaceAt, selectedAt, color);
    }
}

void highlightField(Field *field, COLOR color) {
    system("clear");
    printField(field, color, 1);
    sleep(1);
    system("clear");
    defaultPrintField(field);
}

KeyboardInput getKeyboardInput() {
    system("/bin/stty raw");
    int c = getchar();// skip the ^ or check enter
    if (c == '!') return quit;
    if (c == 13) return enter;
    if (c == '<') return back;
    c = getchar(); // skip the [ or check enter
    if (c == '!') return quit;
    if (c == 13) return enter;
    if (c == '<') return back;
    KeyboardInput result = toKeyboardInput(getchar());
    system("/bin/stty cooked");
    return result;
}

void printFarewell() {
    printf("\nQuitting...\n");
}

void printCongratulations() {
    printf("\nYou win!\n");
}

void printGreetings() {
    system("reset");
    printf("Welcome to Tags!\n"
           "To win, you need to line up all the cells in order, and at the end there must be an empty cell.\n"
           "Use the arrows to select a cell.\n"
           "Use \"Enter\" to move the selected cell.\n"
           "Type '<' to undo changes.\n"
           "To exit the game, enter \"!\".\n"
           "%sAnd good luck!\n%s"
           "Press \"Enter\" to start...\n", getColor(blue), getColor(reset));
    getchar(); // skip enter
}

int getFieldSize() {
    printf("Please enter a field size.\n"
           "The field size is an integer from 2 to 10.\n"
           "Field size: ");
    char *string = readline("");
    int fieldSize = atoi(string);
    if (fieldSize >= 2 && fieldSize <= 10)
        return fieldSize;
    printf("%sIncorrect input of field size.\n"
           "Exit the game.%s\n", getColor(red), getColor(reset));
    exit(-1);
}