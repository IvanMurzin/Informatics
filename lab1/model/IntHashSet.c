#include <stdlib.h>
#include <stdio.h>
#include "IntHashSet.h"
#include "IntDynamicArray.h"


struct IntHashSet {
    int capacity;
    IntDynamicArray **columns;
};


IntHashSet *getIntHashSet() {
    IntHashSet *set = (IntHashSet *) malloc(sizeof(IntHashSet));
    set->capacity = 10;
    set->columns = (IntDynamicArray **) malloc(10 * sizeof(IntDynamicArray *));
    for (int i = 0; i < set->capacity; ++i)
        set->columns[i] = getIntDynamicArray();
    return set;
}

int addToSet(IntHashSet *set, int element) {
    int columnIndex = (element >= 0 ? element : -element) % 10;
    IntDynamicArray *column = set->columns[columnIndex];
    if (containsInArray(column, element)) return 0;
    addToArray(column, element);
    return 1;
}

int printSet(IntHashSet *set) {
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

int containsInSet(IntHashSet *set, int element) {
    if (!set) return 0;
    int columnIndex = (element >= 0 ? element : -element) % 10;
    IntDynamicArray *column = set->columns[columnIndex];
    if (containsInArray(column, element)) return 1;
    return 0;
}

int printSetLikeArray(IntHashSet *set) {
    if (!set) return 0;
    for (int i = 0; i < set->capacity; ++i)
        printArray(set->columns[i]);

    printf("\n");
    return 1;
}

int countDifferences(IntHashSet *set1, IntHashSet *set2) {
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
        destroyArray(set->columns[i]);
    free(set->columns);
    free(set);
}