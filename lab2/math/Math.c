#include <stdlib.h>
#include <time.h>
#include "Math.h"

void shuffle(int *array, int size) {
    srand(time(NULL));
    for (int i = 0; i < size - 1; i++) {
        int j = i + rand() / (RAND_MAX / (size - i) + 1);
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
    }
}