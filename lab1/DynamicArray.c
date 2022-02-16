#include <stdlib.h>
#include <string.h>
#include <printf.h>
#include "DynamicArray.h"

struct DynamicArray {
    int *data;
    int size;
    int bufferSize;
};

int get(DynamicArray *array, int index) {
    if (!array || index < 0 || index >= array->size) return NULL;
    return array->data[index];
}

int set(DynamicArray *array, int index, int data) {
    if (!array || index < 0 || index >= array->size) return 0;
    array->data[index] = data;
    return 1;
}

int getSize(DynamicArray *array) {
    if (!array) return 0;
    return array->size;
}

void initArray(DynamicArray *array, int element) {
    array->data = (int *) malloc(sizeof(int) * 10);
    array->bufferSize = 10;
    array->data[0] = element;
    array->size = 1;
}

int addByIndex(DynamicArray *array, int index, int element) {
    if (!array) return 0;
    if (index < 0 || index >= array->size) return 0;
    if (!array->data) {
        initArray(array, element);
        return 1;
    }
    if (array->bufferSize == array->size) {
        array->bufferSize = array->bufferSize * 5 / 3;
        int *newData = malloc(sizeof(int) * array->bufferSize);
        memcpy(newData, array->data, sizeof(int) * index);
        memcpy(newData + index + 1, array->data + index, sizeof(int) * (array->size - index));
        free(array->data);
        array->data = newData;
        array->data[index] = element;
        ++array->size;
        return 1;
    }
    memcpy(array->data + index + 1, array->data + index, sizeof(int) * (array->size - index));
    array->data[index] = element;
    ++array->size;
    return 1;
}

int add(DynamicArray *array, int element) {
    return addLast(array, element);
}

int addFirst(DynamicArray *array, int element) {
    if (!array) return 0;
    if (!array->data) {
        initArray(array, element);
        return 1;
    }
    if (array->bufferSize == array->size) {
        array->bufferSize = array->bufferSize * 5 / 3;
        int *newData = malloc(sizeof(int) * array->bufferSize);
        int *pointerToStart = newData + 1;
        memcpy(pointerToStart, array->data, sizeof(int) * array->size);
        free(array->data);
        array->data = newData;
        array->data[0] = element;
        ++array->size;
        return 1;
    }
    memcpy(array->data + 1, array->data, sizeof(int) * array->size);
    array->data[0] = element;
    ++array->size;
    return 1;
}


int addLast(DynamicArray *array, int element) {
    if (!array) return 0;
    if (!array->data) {
        initArray(array, element);
        return 1;
    }
    if (array->bufferSize == array->size) {
        array->bufferSize = array->bufferSize * 5 / 3;
        int *newData = malloc(sizeof(int) * array->bufferSize);
        memcpy(newData, array->data, sizeof(int) * array->size);
        free(array->data);
        array->data = newData;
        array->data[array->size] = element;
        ++array->size;
        return 1;
    }
    array->data[array->size] = element;
    ++array->size;
    return 1;
}

int printArray(DynamicArray *array) {
    if (!array) return 0;
    for (int i = 0; i < array->size; ++i)
        printf("%d ", array->data[i]);
    printf("\n");
    return 1;
}

DynamicArray *getDynamicArray() {
    DynamicArray *array = malloc(sizeof(DynamicArray));
    array->data = NULL;
    array->size = 0;
    array->bufferSize = 0;
    return array;
}