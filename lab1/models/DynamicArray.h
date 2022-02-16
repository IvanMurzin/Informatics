#include "StructInfo.h"

typedef struct DynamicArray DynamicArray;

int add(DynamicArray *array, void *element);

int addByIndex(DynamicArray *array, int index, void *element);

int addFirst(DynamicArray *array, void *element);

int addLast(DynamicArray *array, void *element);

int printArray(DynamicArray *array);

DynamicArray *getDynamicArray(StructInfo *info);

int getSize(DynamicArray *array);

void *get(DynamicArray *array, int index);

int set(DynamicArray *array, int index, void *data);