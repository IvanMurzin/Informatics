#include <stdlib.h>
#include "KeySpace1.h"
#include "Errors.h"


int getKeySpase1(KeySpace1 **table, int maxSize) {
    if (maxSize <= 0 || maxSize > 1000) throw ERROR_WRONG_TABLE_SIZE;
    *table = malloc(sizeof(KeySpace1));
    if (*table == NULL) throw ERROR_OUT_OF_MEMORY;
    (*table)->maxSize = maxSize;
    (*table)->table = malloc(sizeof(Item1 *) * maxSize);
    return 0;
}

int indexOfByKeyValueKS1(KeySpace1 *table, const char *stringKey) {
    if (table == NULL || table->table == NULL || stringKey == NULL) {
        return -1;
    }
    for (int i = 0; i < table->currentSize; ++i) {
        if (equalsKey1Values(table->table[i]->key1.value, stringKey))
            return i;
    }
    return -1;
}

int selectLatestVersionItemKS1(KeySpace1 *table, const char *stringKey, Item1 **item) {
    int index = indexOfByKeyValueKS1(table, stringKey);
    if (index < 0) throw ERROR_NOT_FOUND;
    while (table->table[index]->nextIndex >= 0)
        index = table->table[index]->nextIndex;
    *item = table->table[index];
    return 0;
}

int selectFirstVersionItemKS1(KeySpace1 *table, const char *stringKey, Item1 **item) {
    int index = indexOfByKeyValueKS1(table, stringKey);
    if (index < 0) throw ERROR_NOT_FOUND;
    *item = table->table[index];
    return 0;
}

int insertIntoKS1(KeySpace1 *table, const char *stringKey, const char *data) {
    if (table == NULL || table->table == NULL || data == NULL || stringKey == NULL) {
        throw ERROR_INCORRECT_INPUT;
    }
    if (table->currentSize == table->maxSize) throw ERROR_TABLE_OVERFLOW;
    int version = 0;
    Item1 *item = NULL;
    Item1 *lastItem = NULL;
    if (!selectLatestVersionItemKS1(table, stringKey, &lastItem)) {
        lastItem->nextIndex = table->currentSize;
        version = lastItem->key1.version + 1;
    }
    Key1 key = {stringKey, version};
    if (getItem1(&item, key, data)) throw ERROR_UNABLE_TO_CREATE_ITEM;
    table->table[table->currentSize] = item;
    table->currentSize++;
    return 0;
}

int indexOfByKeyKS1(KeySpace1 *table, Key1 key1) {
    if (table == NULL || table->table == NULL || key1.value == NULL) {
        return -1;
    }
    for (int i = 0; i < table->currentSize; ++i) {
        if (equalsKey1(table->table[i]->key1, key1)) return i;
    }
    return -1;
}