#include <stdlib.h>
#include <string.h>
#include <printf.h>
#include "DynamicArray.h"

struct DynamicArray {
    void **data;
    int size;
    int bufferSize;
    StructInfo *info;
};

void *get(DynamicArray *array, int index) {
    if (!array || index < 0 || index >= array->size) return NULL;
    return array->data[index];
}

int set(DynamicArray *array, int index, void *data) {
    if (!array || index < 0 || index >= array->size) return 0;
    free(array->data[index]);
    array->data[index] = data;
    return 1;
}

int getSize(DynamicArray *array) {
    if (!array) return -1;
    return array->size;
}

void initArray(DynamicArray *array, void *element) {
    array->data = (void **) malloc(getStructSize(array->info) * 10);
    array->bufferSize = 10;
    array->data[0] = element;
    array->size = 1;
}

int addByIndex(DynamicArray *array, int index, void *element) {
    if (!array) return 0;
    if (index < 0 || index >= array->size) return 0;
    if (!array->data) {
        initArray(array, element);
        return 1;
    }
    if (array->bufferSize == array->size) {
        array->bufferSize = array->bufferSize * 5 / 3;
        void **newData = malloc(getStructSize(array->info) * array->bufferSize);
        memcpy(newData, array->data, getStructSize(array->info) * index);
        memcpy(newData + index + 1, array->data + index, getStructSize(array->info) * (array->size - index));
        free(array->data);
        array->data = newData;
        array->data[index] = element;
        ++array->size;
        return 1;
    }
    memcpy(array->data + index + 1, array->data + index, getStructSize(array->info) * (array->size - index));
    array->data[index] = element;
    ++array->size;
    return 1;
}

int add(DynamicArray *array, void *element) {
    return addLast(array, element);
}

int addFirst(DynamicArray *array, void *element) {
    if (!array) return 0;
    if (!array->data) {
        initArray(array, element);
        return 1;
    }
    if (array->bufferSize == array->size) {
        array->bufferSize = array->bufferSize * 5 / 3;
        void **newData = malloc(getStructSize(array->info) * array->bufferSize);
        void **pointerToStart = newData + getStructSize(array->info);
        memcpy(pointerToStart, array->data, getStructSize(array->info) * array->size);
        free(array->data);
        array->data = newData;
        array->data[0] = element;
        ++array->size;
        return 1;
    }
    memcpy(array->data + 1, array->data, getStructSize(array->info) * array->size);
    array->data[0] = element;
    ++array->size;
    return 1;
}


int addLast(DynamicArray *array, void *element) {
    if (!array) return 0;
    if (!array->data) {
        initArray(array, element);
        return 1;
    }
    if (array->bufferSize == array->size) {
        array->bufferSize = array->bufferSize * 5 / 3;
        void **newData = malloc(getStructSize(array->info) * array->bufferSize);
        memcpy(newData, array->data, getStructSize(array->info) * array->size);
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
    for (int i = 0; i < array->size; ++i) {
        char* b = getStructString(array->info, array->data[i]);
        printf("%s ",b);
    }
    printf("\n");
    return 1;
}

DynamicArray *getDynamicArray(StructInfo *info) {
    DynamicArray *array = malloc(sizeof(DynamicArray));
    array->data = NULL;
    array->size = 0;
    array->bufferSize = 0;
    array->info = info;
    return array;
}