#ifndef INT_DYNAMIC_ARRAY
#define INT_DYNAMIC_ARRAY

typedef struct IntDynamicArray {
    int *data;
    int size;
    int bufferSize;
} IntDynamicArray;

int addToArray(IntDynamicArray *array, int element);

int printArray(const IntDynamicArray *array);

int getSize(const IntDynamicArray *array);

int get(const IntDynamicArray *array, int index);

int containsInArray(const IntDynamicArray *array, int element);

IntDynamicArray *getIntDynamicArray();

int isEmpty(const IntDynamicArray *array);

void destroyArray(IntDynamicArray *array);

void trimToSize(IntDynamicArray *array);

#endif