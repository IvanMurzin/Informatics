#ifndef KEYSPACE1_H
#define KEYSPACE1_H

#include "Container.h"

typedef struct KeySpace1 {
    int maxSize;
    int size;
    Container *containers;
} KeySpace1;

int getKS1(KeySpace1 **table, int maxSize);

int insertIntoKS1(KeySpace1 *table, Item *item);

int indexOfKS1(KeySpace1 *table, Key key);

int removeByKeyKS1(KeySpace1 *containers, Key key);

int removeByKeyRange(KeySpace1 *containers, Key floor, Key selling);

void destroyKS1(KeySpace1 *table);

#endif
