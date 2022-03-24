typedef struct IntDynamicArray IntDynamicArray;

int addToArray(IntDynamicArray *array, int element);

int printArray(IntDynamicArray *array);

int getSize(IntDynamicArray *array);

int get(IntDynamicArray *array, int index);

int containsInArray(IntDynamicArray *array, int element);

IntDynamicArray *getIntDynamicArray();

int isEmpty(IntDynamicArray *array);

void destroyArray(IntDynamicArray* array);