typedef struct DynamicArray DynamicArray;

int add(DynamicArray *array, int element);

int addByIndex(DynamicArray *array, int index, int element);

int addFirst(DynamicArray *array, int element);

int addLast(DynamicArray *array, int element);

int printArray(DynamicArray *array);

DynamicArray *getDynamicArray();

int getSize(DynamicArray *array);

int get(DynamicArray *array, int index);

int set(DynamicArray *array, int index, int data);