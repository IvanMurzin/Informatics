#ifndef KEYSPACE2_H
#define KEYSPACE2_H

#include "Item.h"

typedef struct KeySpace2 {
    int maxSize;
    int size;
    Container *containers;

    int (*hash)(const char *data);
} KeySpace2;

int getKS2(KeySpace2 **table, int maxSize);

int insertIntoKS2(KeySpace2 *table, Item *item);

int indexOfKS2(KeySpace2 *table, Key key);
//
//int indexOfGarbageByKeyKS2(KeySpace2 *containers, Key key);
//
//int selectFirstVersionItemKS2(KeySpace2 *containers, const char *stringKey, Item **item);
//
//int removeByKeyKS2(KeySpace2 *containers, Key key);
//
//int removeByKeyValueKS2(KeySpace2 *containers, const char *stringKey);
//
//void destroyKS2(KeySpace2 *containers);

#endif
