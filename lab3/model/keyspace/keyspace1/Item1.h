#ifndef LAB3_ITEM1_H
#define LAB3_ITEM1_H

#include "Key1.h"
#include "Item.h"

typedef struct Item1 {
    int busy;
    Key1 key;
    int nextIndex;
    int previousIndex;
    const char *data; // -> Item
} Item1;

int getItem1(Item1 **item, Key1 key, const char *data);

#endif
