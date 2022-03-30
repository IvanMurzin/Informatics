#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "IntDynamicArray.h"


int get(const IntDynamicArray *array, int index) {
    if (!array || index < 0 || index >= array->size) exit(-1);
    return array->data[index];
}

int getSize(const IntDynamicArray *array) {
    if (!array) return -1;
    return array->size;
}

int addToArray(IntDynamicArray *array, int element) {
    if (!array) return 0;
    if (!array->data) {
        array->data = (int *) malloc(10 * sizeof(int));
        array->bufferSize = 10;
        array->data[0] = element;
        array->size = 1;
        return 1;
    }
    if (array->bufferSize == array->size) {
        array->bufferSize = array->bufferSize * 5 / 3;
        array->data = (int *) realloc(array->data, array->bufferSize * sizeof(int));
        array->data[array->size] = element;
        ++array->size;
        return 1;
    }
    array->data[array->size] = element;
    ++array->size;
    return 1;
}

int containsInArray(const IntDynamicArray *array, int element) {
    if (!array ||!array->data || array->size == 0) return 0;
    for (int i = 0; i < array->size; ++i)
        if (array->data[i] == element) return 1;
    return 0;
}

int printArray(const IntDynamicArray *array) {
    if (!array || !array->data) return 0;
	for (int i = 0; i < array->size; ++i)
        printf("%d ", array->data[i]);
    return 1;
}

IntDynamicArray *getIntDynamicArray() {
    IntDynamicArray *array = (IntDynamicArray *) malloc(sizeof(IntDynamicArray));
    array->data = NULL;
    array->size = 0;
    array->bufferSize = 0;
    return array;
}

int isEmpty(const IntDynamicArray *array) {
    return array == NULL || array->size == 0;
}

void destroyArray(IntDynamicArray *array) {
    if (!array) return;
    free(array->data);
    free(array);
}

void trimToSize(IntDynamicArray *array) {
    array->data = (int *) realloc(array->data, array->size);
}