#ifndef LAB4_BNODE_H
#define LAB4_BNODE_H

#include "Key.h"

typedef struct Item {
    Key key;
    int number;
    const char *data;
    struct Item *next;
} Item;

Item *getItem(Key key, const char *data);

Item *getItemCopy(Item *item);

int putSorted(Item **src, Item *item);

int containsAny(Item *src, Key key, Item **result);

int contains(Item *src, Key key, int number, Item **result);

int deleteFromList(Item **src, Key key, int number);

int maxNumber(Item *src, Key key);

void destroyItem(Item *item);

#endif
