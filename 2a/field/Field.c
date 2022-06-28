#include <stdlib.h>
#include "Field.h"
#include <time.h>

void shuffle(int *array, int size) {
    srand(time(NULL));
    for (int i = 0; i < size - 1; i++) {
        int j = i + rand() / (RAND_MAX / (size - 1 - i) + 1);
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
    }
}

void reset(int *array, int size) {
    for (int i = 0; i < size - 1; ++i) array[i] = i + 1;
    array[size - 1] = -1;
}

int isSolvable(int *array, int size) {
    int countInversions = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < i; j++) {
            if (array[j] > array[i])
                countInversions++;
        }
    }

    return countInversions % 2 == 0;
}

void fillField(Field *field) {
    int valuesSize = field->size * field->size;
    int *array = malloc(sizeof(int) * valuesSize);
    do {
        reset(array, valuesSize);
        shuffle(array, valuesSize);
    } while (!isSolvable(array, valuesSize));
    for (int i = 0; i < field->size; ++i) {
        field->data[i] = (int *) malloc(sizeof(int) * field->size);
        for (int j = 0; j < field->size; ++j)
            field->data[i][j] = array[i * field->size + j];
    }
    free(array);
}

Field *getField(int size) {
    Field *field = malloc(sizeof(Field));
    field->data = (int **) malloc(sizeof(int *) * size);
    field->size = size;
    field->empty.x = size - 1;
    field->empty.y = size - 1;
    field->selected.x = 0;
    field->selected.y = 0;
    fillField(field);
    return field;
}

int isEmpty(Field *field, Point point) {
    return point.x == field->empty.x && point.y == field->empty.y;
}

int isSelected(Field *field, Point point) {
    return point.x == field->selected.x && point.y == field->selected.y;
}
