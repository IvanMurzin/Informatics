#ifndef LAB3_ITEM1_H
#define LAB3_ITEM1_H

#include "model/keyspace/key/Key.h"
#include "Item.h"

typedef struct Item {
    int busy;
    Key key1;
    Key key2;
    int nextIndexKS1;
    int nextIndexKS2;
    int previousIndexKS1;
    int previousIndexKS2;
    const char *data;
} Item;

int getItem(Item **item, Key key1, Key key2, const char *data);

#endif
