#ifndef LAB3_ITEM1_H
#define LAB3_ITEM1_H

#include "model/keyspace/key/Key.h"
#include "Item.h"

typedef struct Item {
    int busy;
    Key key;
    int nextIndex;
    int previousIndex;
    const char* data;
} Item;

int getItem(Item **item, Key key, const char *data);

#endif
