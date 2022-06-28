#ifndef KEYSPACE2_H
#define KEYSPACE2_H

#include "Container.h"

typedef struct KeySpace2 {
    int maxSize;
    Container *containers;

    int (*hash)(const char *data);
} KeySpace2;

int getKS2(KeySpace2 **table, int maxSize);

int insertIntoKS2(KeySpace2 *table, Item *item);

int indexOfKS2(const KeySpace2 *table, Key key);

int removeByKeyKS2(const KeySpace2 *containers, Key key);

void destroyKS2(KeySpace2 *table);

#endif