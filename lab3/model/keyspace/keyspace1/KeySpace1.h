#ifndef KEYSPACE1_H
#define KEYSPACE1_H

#include "Item1.h"

typedef struct KeySpace1 {
    int maxSize;
    int currentSize;
    Item1 **table;
} KeySpace1;

int getKeySpase1(KeySpace1 **table, int maxSize);

int insertIntoKS1(KeySpace1 *table, const char *stringKey, const char *data);

int indexOfByKeyKS1(KeySpace1 *table, Key1 key);

int indexOfLatestVersionItemKS1(KeySpace1 *table, const char *stringKey);

int selectFirstVersionItemKS1(KeySpace1 *table, const char *stringKey, Item1 **item);

int removeByKeyKS1(KeySpace1 *table, Key1 key);

int removeByKeyValueKS1(KeySpace1 *table, const char *stringKey);

int removeByKeyRange(KeySpace1 *table, Key1 floor, Key1 selling);

void destroyKeySpace1(KeySpace1 *table);

#endif
