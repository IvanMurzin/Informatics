#ifndef LAB3_ITEM1_H
#define LAB3_ITEM1_H

#include "Item.h"
#include "CompositeKey.h"
#include "Waymark.h"

typedef struct Item {
    int busy;
    CompositeKey key;
    Waymark waymarkKS1;
    Waymark waymarkKS2;
    const char *data;
} Item;

int getItem(Item **item, CompositeKey key, const char *data);

#endif
