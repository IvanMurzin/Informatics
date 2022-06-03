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

int indexOfKS1(const KeySpace1 *table, Key key);

int removeByKeyKS1(const KeySpace1 *table, Key key);

int removeLastByKeyKS1(const KeySpace1 *table, Key key);

int removeByKeyRange(const KeySpace1 *table, Key floor, Key selling);

void destroyKS1(KeySpace1 *table);

int collectGarbage(KeySpace1 *table);

#endif
