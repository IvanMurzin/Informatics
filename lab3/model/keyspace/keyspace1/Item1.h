#ifndef LAB3_ITEM1_H
#define LAB3_ITEM1_H

#include "Key1.h"
#include "Item.h"

typedef struct Item1 {
    int busy;
    Key1 key1;
    int nextIndex;
    const char *data;

} Item1;

int getItem1(Item1 **item, Key1 key1, const char *data);

#endif
