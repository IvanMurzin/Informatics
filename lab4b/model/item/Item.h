#ifndef LAB4_BNODE_H
#define LAB4_BNODE_H

#include "Key.h"

typedef struct Item {
    Key key;
    const char *data;
    struct Item *next;
} Item;

Item *getItem(Key key, const char *data);

void destroyItem(Item* item);
#endif
