#include <stddef.h>
#include "IteratorKS1.h"

int hasNextItem1(const Item1 *item) {
    if (item == NULL) return 0;
    return item->nextIndex >= 0;
}

Item1 *nextItem1(KeySpace1 *table, const Item1 *item) {
    if (!hasNextItem1(item)) return NULL;
    return table->table[item->nextIndex];
}