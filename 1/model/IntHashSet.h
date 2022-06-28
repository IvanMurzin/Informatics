#ifndef INT_HASH_SET
#define INT_HASH_SET

#include "IntDynamicArray.h"

typedef struct IntHashSet {
    int capacity;
    IntDynamicArray **columns;
} IntHashSet;

int addToSet(IntHashSet *set, int element);

IntHashSet *getIntHashSet();

IntHashSet *getIntHashSetFromArray(const IntDynamicArray* array);

int printSet(const IntHashSet *set);

int printSetLikeArray(const IntHashSet *set);

int containsInSet(const IntHashSet *set, int element);

int countDifferences(const IntHashSet *set1, const IntHashSet *set2);

void destroySet(IntHashSet *set);

#endif