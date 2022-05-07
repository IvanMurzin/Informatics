#include <stddef.h>
#include "IteratorKS.h"

int hasNextItem1(const Item *item) {
    if (item == NULL) return 0;
    return item->nextIndexKS1 >= 0;
}

Item *nextItem1(KeySpace1 *table, const Item *item) {
    if (!hasNextItem1(item)) return NULL;
    return table->table[item->nextIndexKS1];
}

int hasNextItem2(const Item *item) {
    if (item == NULL) return 0;
    return item->nextIndexKS2 >= 0;
}

Item *nextItem2(KeySpace2 *table, const Item *item) {
    if (!hasNextItem2(item)) return NULL;
    return table->table[item->nextIndexKS2];
}
