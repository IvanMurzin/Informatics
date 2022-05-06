#include <stddef.h>
#include "IteratorKS1.h"

int hasNextItem1(const Item *item) {
    if (item == NULL) return 0;
    return item->nextIndex >= 0;
}

Item *nextItem1(KeySpace1 *table, const Item *item) {
    if (!hasNextItem1(item)) return NULL;
    return table->table[item->nextIndex];
}