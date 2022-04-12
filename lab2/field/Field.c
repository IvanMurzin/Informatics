#include <stdlib.h>
#include "Field.h"
#include "Math.h"

void fillField(Field *field) {
    int valuesSize = field->size * field->size;
    int *array = malloc(sizeof(int) * valuesSize);
    for (int i = 0; i < valuesSize - 1; ++i) array[i] = i+1;
    shuffle(array, valuesSize - 1);
    array[valuesSize - 1] = -1;
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
    field->emptyX = size - 1;
    field->emptyY = size - 1;
    field->selectedX = 0;
    field->selectedY = 0;
    fillField(field);
    return field;
}

int isEmpty(Field *field, int x, int y) {
    return x == field->emptyX && y == field->emptyY;
}

int isSelected(Field *field, int x, int y) {
    return x == field->selectedX && y == field->selectedY;
}
