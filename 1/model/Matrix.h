#ifndef MATRIX
#define MATRIX

#include "IntHashSet.h"

typedef struct Matrix {
    IntDynamicArray **rows;
    int size;
} Matrix;

Matrix *getMatrix();

int getMatrixSize(const Matrix *matrix);

int printMatrix(const Matrix *matrix);

IntDynamicArray *getFromMatrix(const Matrix *matrix, int index);

void destroyMatrix(Matrix *matrix);

#endif