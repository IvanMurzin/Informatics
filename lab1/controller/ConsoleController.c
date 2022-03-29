#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "ConsoleController.h"
#include "IntDynamicArray.h"

int gelLineFromInput(IntDynamicArray *array) {
    if (!array) return 0;
    char *string = readline("");
    if (string[0] == '\0') return 0;
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
    printf("before realloc:\n");
    printArray(array);
    trimToSize(array);
    printf("\nafter realloc:\n");
    printArray(array);
    printf("\n");
    return 1;
}

int getRowCount() {
    printf("Input row count:\n");
    char *string = readline("");
    int number = atoi(string);
    if (number > 0 && number <20)
        return number;
    printf("Incorrect input: row count should be integer between 0 and 20. Emergency exit.\n");
    exit(-1);
}


void printArrayOfDifferences(const int b[], int size) {
    printf("\n\n");
    printf("-------------------- Array Of Differences --------------------\n");
    for (int i = 0; i < size; ++i) {
        printf("[%d]: %d", i + 1, b[i]);
        printf("\n--------------------\n");
    }
}