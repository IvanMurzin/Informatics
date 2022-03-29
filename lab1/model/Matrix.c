#include <stdlib.h>
#include <stdio.h>
#include "Matrix.h"
#include "ConsoleController.h"
#include "IntDynamicArray.h"


Matrix *getMatrix() {
    Matrix *matrix = malloc(sizeof(Matrix));
    int rowSize = getRowCount();
    printf("\nInput matrix: \n");
    matrix->size = rowSize;
    matrix->rows = (IntDynamicArray **) malloc(rowSize * sizeof(IntDynamicArray *));
    for (int i = 0; i < rowSize; ++i) {
        matrix->rows[i] = getIntDynamicArray();
        gelLineFromInput(matrix->rows[i]);
        printArray(matrix->rows[i]);
    }
    return matrix;
}


int getMatrixSize(const Matrix *matrix) {
    if (!matrix) return -1;
    return matrix->size;
}

int printMatrix(const Matrix *matrix) {
    if (!matrix) return 0;
    printf("-------------------- Matrix --------------------\n");
    for (int i = 0; i < getMatrixSize(matrix); ++i) {
        printf("[%d]: ", i + 1);
        printArray(matrix->rows[i]);
        printf("\n--------------------\n");
    }
    return 1;
}

IntDynamicArray *getFromMatrix(const Matrix *matrix, int index) {
    return matrix->rows[index];
}

void destroyMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->size; ++i)
        destroyArray(getFromMatrix(matrix, i));
    free(matrix->rows);
    free(matrix);
}