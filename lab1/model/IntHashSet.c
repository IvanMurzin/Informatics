#include <stdlib.h>
#include <stdio.h>
#include "IntHashSet.h"
#include "IntDynamicArray.h"


IntHashSet *getIntHashSet() {
    IntHashSet *set = (IntHashSet *) malloc(sizeof(IntHashSet));
    set->capacity = 10;
    set->columns = (IntDynamicArray **) malloc(set->capacity * sizeof(IntDynamicArray *));
    return set;
}

IntHashSet *getIntHashSetFromArray(const IntDynamicArray *array) {
    IntHashSet *set = getIntHashSet();
    for (int i = 0; i < getSize(array); ++i)
        addToSet(set, get(array, i));
    return set;
}

int addToSet(IntHashSet *set, int element) {
    int columnIndex = (element >= 0 ? element : -element) % 10;
    if (!set->columns[columnIndex])
        set->columns[columnIndex] = (IntDynamicArray *) malloc(sizeof(IntDynamicArray *));
    IntDynamicArray *column = set->columns[columnIndex];
    if (containsInArray(column, element)) return 0;
    addToArray(column, element);
    return 1;
}

int printSet(const IntHashSet *set) {
    if (!set) return 0;
    for (int i = 0; i < set->capacity; ++i) {
        if (!isEmpty(set->columns[i])) {
            printf("[%d]: ", i);
            printArray(set->columns[i]);
            printf("\n");
        }
    }
    return 1;
}

int containsInSet(const IntHashSet *set, int element) {
    if (!set) return 0;
    int columnIndex = (element >= 0 ? element : -element) % 10;
    IntDynamicArray *column = set->columns[columnIndex];
    if (containsInArray(column, element)) return 1;
    return 0;
}

int printSetLikeArray(const IntHashSet *set) {
    if (!set) return 0;
    for (int i = 0; i < set->capacity; ++i)
        printArray(set->columns[i]);

    printf("\n");
    return 1;
}

int countDifferences(const IntHashSet *set1, const IntHashSet *set2) {
    int count = 0;
    for (int i = 0; i < set1->capacity; ++i) {
        IntDynamicArray *column = set1->columns[i];
        for (int j = 0; j < getSize(column); ++j) {
            if (!containsInSet(set2, get(column, j)))
                count++;
        }
    }
    return count;
}

void destroySet(IntHashSet *set) {
    if (!set) return;
    for (int i = 0; i < set->capacity; ++i)
        if (!set->columns[i]) {
            printf(":%d:", i);
            destroyArray(set->columns[i]);
        }
    free(set->columns);
    free(set);
}