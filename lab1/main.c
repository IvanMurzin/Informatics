#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"


int main() {
    Matrix *matrix = getMatrix();
    printf("Raw matrix:\n");
    printMatrix(matrix);

    IntDynamicArray *differences = getIntDynamicArray();
    IntHashSet *set1;
    IntHashSet *set2;
    for (int i = 0; i < matrix->size - 1; ++i) {
        set1 = getIntHashSetFromArray(matrix->rows[i]);
        set2 = getIntHashSetFromArray(matrix->rows[i + 1]);
        addToArray(differences, countDifferences(set1, set2));
        destroySet(set1);
        destroySet(set2);
    }
    set1 = getIntHashSetFromArray(matrix->rows[matrix->size - 1]);
    set2 = getIntHashSetFromArray(matrix->rows[0]);
    addToArray(differences, countDifferences(set1, set2));
    printf("%d\n",countDifferences(set1, set2));
    destroySet(set1);
    destroySet(set2);

    printf("Array of differences:\n");
    printArray(differences);
    printf("\n");
    destroyArray(differences);
    destroyMatrix(matrix);
    return 0;
}
