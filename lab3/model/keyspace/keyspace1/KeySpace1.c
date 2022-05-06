#include <stdlib.h>
#include "KeySpace1.h"
#include "Errors.h"
#include "IteratorKS1.h"


int getKeySpase1(KeySpace1 **table, int maxSize) {
    if (maxSize <= 0 || maxSize > 1000) throw ERROR_WRONG_TABLE_SIZE;
    *table = malloc(sizeof(KeySpace1));
    if (*table == NULL) throw ERROR_OUT_OF_MEMORY;
    (*table)->maxSize = maxSize;
    (*table)->table = malloc(sizeof(Item1 *) * maxSize);
    return 0;
}

int collectGarbage(KeySpace1 *table) {
    if (table == NULL) return -1;
    int j = 0;
    for (int i = 0; i < table->currentSize; ++i) {
        if (table->table[i]->busy) {
            table->table[j] = table->table[i];
            ++j;
        }
    }
    return table->currentSize - j;
}

int indexOfByKeyKS1(KeySpace1 *table, Key1 key1) {
    if (table == NULL || table->table == NULL || key1.value == NULL) {
        return -1;
    }
    for (int i = 0; i < table->currentSize; ++i) {
        Item1 *item = table->table[i];
        if (item->busy && equalsKey1(item->key, key1)) return i;
    }
    return -1;
}

int indexOfByKeyValueKS1(KeySpace1 *table, const char *stringKey) {
    if (table == NULL || table->table == NULL || stringKey == NULL) {
        return -1;
    }
    for (int i = 0; i < table->currentSize; ++i) {
        Item1 *item = table->table[i];
        if (item->busy && equalsKey1Values(item->key.value, stringKey))
            return i;
    }
    return -1;
}

int indexOfLatestVersionItemKS1(KeySpace1 *table, const char *stringKey) {
    int index = indexOfByKeyValueKS1(table, stringKey);
    if (index < 0) return -1;
    Item1 *next = table->table[index];
    while (hasNextItem1(next)) {
        index = next->nextIndex;
        next = nextItem1(table, next);
    }
    return index;
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
    if (table->currentSize == table->maxSize) {
        int garbage = collectGarbage(table);
        if (garbage == 0) throw ERROR_TABLE_OVERFLOW;
        table->currentSize -= garbage;
    }
    int version = 0;
    Item1 *item = NULL;
    int lastIndex = indexOfLatestVersionItemKS1(table, stringKey);
    if (lastIndex >= 0) {
        Item1 *lastItem = table->table[lastIndex];
        lastItem->nextIndex = table->currentSize;
        version = lastItem->key.version + 1;
    }
    Key1 key = {stringKey, version};
    if (getItem1(&item, key, data)) throw ERROR_UNABLE_TO_CREATE_ITEM;
    item->previousIndex = lastIndex;
    table->table[table->currentSize] = item;
    table->currentSize++;
    return 0;
}

int removeByKeyKS1(KeySpace1 *table, Key1 key) {
    if (table == NULL || table->table == NULL || key.value == NULL) {
        throw ERROR_INCORRECT_INPUT;
    }
    int index = indexOfByKeyKS1(table, key);
    if (index < 0) throw ERROR_NOT_FOUND;
    Item1 *item = table->table[index];
    if (item->previousIndex >= 0) {
        table->table[item->previousIndex]->nextIndex = item->nextIndex;
    }
    if (item->nextIndex >= 0) {
        table->table[item->nextIndex]->previousIndex = item->previousIndex;
    }
    table->table[index]->busy = 0;
    return 0;
}

int removeByKeyValueKS1(KeySpace1 *table, const char *stringKey) {
    if (table == NULL || table->table == NULL || stringKey == NULL) {
        throw ERROR_INCORRECT_INPUT;
    }
    int index = indexOfByKeyValueKS1(table, stringKey);
    if (index < 0) throw ERROR_NOT_FOUND;
    Item1 *next = table->table[index];
    while (hasNextItem1(next)) {
        next->busy = 0;
        next = nextItem1(table, next);
    }
    next->busy = 0;
    return 0;
}
