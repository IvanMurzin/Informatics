#ifndef KEYSPACE1_H
#define KEYSPACE1_H

#include "Item.h"

typedef struct KeySpace1 {
    int maxSize;
    int currentSize;
    Item **table;
} KeySpace1;

int getKeySpase1(KeySpace1 **table, int maxSize);

int insertIntoKS1(KeySpace1 *table, const char *stringKey, const char *data);

int indexOfByKeyKS1(KeySpace1 *table, Key key);

int indexOfLatestVersionItemKS1(KeySpace1 *table, const char *stringKey);

int selectFirstVersionItemKS1(KeySpace1 *table, const char *stringKey, Item **item);

int removeByKeyKS1(KeySpace1 *table, Key key);

int removeByKeyValueKS1(KeySpace1 *table, const char *stringKey);

int removeByKeyRange(KeySpace1 *table, Key floor, Key selling);

void destroyKeySpace1(KeySpace1 *table);

#endif
