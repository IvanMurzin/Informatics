#ifndef KEYSPACE2_H
#define KEYSPACE2_H

#include "Item.h"

typedef struct KeySpace2 {
    int maxSize;
    int currentSize;

    int (*hash)(const char *data);

    Item **table;
} KeySpace2;

int getKS2(KeySpace2 **table, int maxSize);

int insertIntoKS2(KeySpace2 *table, Item* item);

int indexOfByKeyKS2(KeySpace2 *table, Key key);

int selectFirstVersionItemKS2(KeySpace2 *table, const char *stringKey, Item **item);

int removeByKeyKS2(KeySpace2 *table, Key key);

int removeByKeyValueKS2(KeySpace2 *table, const char *stringKey);

void destroyKS2(KeySpace2 *table);

#endif
