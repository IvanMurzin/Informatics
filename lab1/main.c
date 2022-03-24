#include <stdlib.h>
#include "model/IntDynamicArray.h"
#include "model/IntHashSet.h"
#include "controller/ConsoleController.h"


int main() {
    int rowSize = getRowSize();
    IntHashSet **matrix = (IntHashSet **) malloc(rowSize * sizeof(IntHashSet *));
    for (int i = 0; i < rowSize; ++i) {
        matrix[i] = getIntHashSet();
        fillSetWithLine(matrix[i]);
    }

    printMatrix(matrix, rowSize, 1);

    int b[rowSize];
    for (int i = 0; i < rowSize - 1; ++i)
        b[i] = countDifferences(matrix[i], matrix[i + 1]);
    b[rowSize - 1] = countDifferences(matrix[rowSize - 1], matrix[0]);

    printArrayOfDifferences(b, rowSize);

    for (int i = 0; i < rowSize; ++i)
        destroySet(matrix[i]);
    free(matrix);
    return 0;
}
/*
3
1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 3 1 1 1 1 2 2 2 1 1 1 3 3
43 45346 334 3345345 43 598 3894 35980435 89453 980435 890 45389453 904 894 5380945 3
32  sdfksdfoksdf skdf k34 k3 3k4 3 4 3p4k 3[4 k34 5k3



 3
1 2 3 4 5 6
1 2 3 4 5 6 7 8 9
1 2

 3
1 2 3 4 5 6 7 8 9 9 9 9 9 9 9 9 9 9 9 9 9
10 11 -12
55
 */
