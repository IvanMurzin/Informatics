#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "ConsoleController.h"
#include "IntDynamicArray.h"

int gelLineFromInput(IntDynamicArray *array) {
    if (!array) return 0;
    char *string = readline("");
    if (string[0] == '\0') {
        printf("Invalid row input. Emergency exit.\n");
        exit(-1);
    }
    char *word = strtok(string, " ");
    while (word != NULL) {
        int number = atoi(word);
        if (number != 0 || strstr(word, "0") != NULL)
            addToArray(array, number);
        else {
            printf("Invalid row input. Emergency exit.\n");
            exit(-1);
        }
        word = strtok(NULL, " ");
    }
    return 1;
}

int getRowCount() {
    printf("Input row count:\n");
    char *string = readline("");
    int number = atoi(string);
    if (number > 1 && number < 20)
        return number;
    printf("Incorrect input: row count should be integer between 2 and 20. Emergency exit.\n");
    exit(-1);
}