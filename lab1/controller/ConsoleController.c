#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ConsoleController.h"

int fillSetWithLine(IntHashSet *set) {
    if (!set) return 0;
    while (fgetc(stdin) != '\n');
    char string[1024];
    scanf("%[^\n]s", string);
    char *word = strtok(string, " ");
    while (word != NULL) {
        int number = atoi(word);
        if (number != 0 || strstr(word, "0") != NULL)
            addToSet(set, number);
        word = strtok(NULL, " ");
    }
    return 1;
}

int getRowSize() {
    printf("Input row size:\n");
    int rowSize;
    while (!scanf("%d", &rowSize) || rowSize <= 0 || rowSize > 20) {
        while (fgetc(stdin) != '\n');
        printf("Incorrect input: row size should be integer between 0 and 20.\nInput row size:\n");
    }
    return rowSize;
}

int printMatrix(IntHashSet **matrix, int rowSize, int pretty) {
    printf("\n\n");
    if (!matrix) return 0;
    printf("-------------------- Matrix --------------------\n");
    for (int i = 0; i < rowSize; ++i) {
        printf("[%d]: ", i + 1);
        if (pretty) printSetLikeArray(matrix[i]);
        else printSet(matrix[i]);
        printf("--------------------\n");
    }
    return 1;
}

void printArrayOfDifferences(int b[], int size) {
    printf("\n\n");
    printf("-------------------- Array Of Differences --------------------\n");
    for (int i = 0; i < size; ++i) {
        printf("[%d]: %d", i + 1, b[i]);
        printf("\n--------------------\n");
    }
}