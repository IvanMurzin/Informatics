#include <stddef.h>
#include "IteratorKS.h"


int hasNextItem1(const Item *item) {
    if (item == NULL) return 0;
    return item->waymarkKS1.next >= 0;
}

Item *nextItem1(KeySpace1 *table, const Item *item) {
    if (!hasNextItem1(item)) return NULL;
    return table->table[item->waymarkKS1.next];
}

int hasNextItem2(const Item *item) {
    if (item == NULL) return 0;
    return item->waymarkKS2.next >= 0;
}

Item *nextItem2(KeySpace2 *table, const Item *item) {
    if (!hasNextItem2(item)) return NULL;
    return table->table[item->waymarkKS2.next];
}

int hasNext(const Item *item) {
    return item->next != NULL;
}

Item *next(const Item *item) {
    return item->next;
}

