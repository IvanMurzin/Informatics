#include <stdlib.h>
#include <limits.h>
#include "KeySpace2.h"
#include "Errors.h"
#include "IteratorKS.h"

int hash(const char *data) {
    int hash = INT_MAX;
    while (*data != '\0') {
        hash = hash * 37 + *data;
        data++;
    }
    return abs(hash);
}

int getKS2(KeySpace2 **table, int maxSize) {
    if (maxSize <= 0 || maxSize > 1000) throw ERROR_WRONG_TABLE_SIZE;
    *table = calloc(1, sizeof(KeySpace2));
    if (*table == NULL) throw ERROR_OUT_OF_MEMORY;
    (*table)->maxSize = maxSize;
    (*table)->currentSize = 0;
    (*table)->hash = &hash;
    (*table)->table = calloc(maxSize, sizeof(Item *));
    return 0;
}

int indexOfByKeyKS2(KeySpace2 *table, Key key) {
    if (table == NULL || table->table == NULL || key.value == NULL) {
        return -1;
    }
    int hashCode = table->hash(key.value);
    for (int i = 0; i < table->maxSize; ++i) {
        int hash = (hashCode + i) % table->maxSize;
        Item *item = table->table[hash];
        if (item->busy && equalsKey(item->key, key)) {
            return hash;
        }
    }
    return ERROR_NOT_FOUND;
}

int indexOfByKeyValueKS2(KeySpace2 *table, const char *stringKey) {
    if (table == NULL || table->table == NULL || stringKey == NULL) {
        return -1;
    }
    int hashCode = table->hash(stringKey);
    for (int i = 0; i < table->maxSize; ++i) {
        int hash = (hashCode + i) % table->maxSize;
        Item *item = table->table[hash];
        if (item->busy && equalsKeyValues(item->key.value, stringKey)) {
            return hash;
        }
    }
    return ERROR_NOT_FOUND;
}

int insertIntoKS2(KeySpace2 *table, const char *stringKey, const char *data) {
    if (table == NULL || table->table == NULL || data == NULL || stringKey == NULL) {
        throw ERROR_INCORRECT_INPUT;
    }
    if (table->currentSize == table->maxSize) {
        throw ERROR_TABLE_OVERFLOW;
    }
    int version = 0;
    int previousIndex = -1;
    int hashCode = table->hash(stringKey);
    for (int i = 0; i < table->maxSize; ++i) {
        int hash = (hashCode + i) % table->maxSize;
        Item *item = table->table[hash];
        if (item != NULL && item->busy) {
            if (equalsKeyValues(item->key.value, stringKey)) {
                previousIndex = hash;
                version++;
            }
        } else {
            if (item != NULL) free(item);
                Key key = {stringKey, version};
            if (getItem(&item, key, data)) throw ERROR_UNABLE_TO_CREATE_ITEM;
            if (previousIndex >= 0) {
                table->table[previousIndex]->nextIndexKS2 = hash;
                item->previousIndexKS2 = previousIndex;
            }
            table->table[hash] = item;
            table->currentSize++;
            return 0;
        }
    }
    return ERROR_TABLE_OVERFLOW;
}

int removeByKeyKS2(KeySpace2 *table, Key key) {
    if (table == NULL || table->table == NULL || key.value == NULL) {
        throw ERROR_INCORRECT_INPUT;
    }
    int index = indexOfByKeyKS2(table, key);
    if (index < 0) throw ERROR_NOT_FOUND;
    Item *item = table->table[index];
    if (item->previousIndexKS2 >= 0) {
        table->table[item->previousIndexKS2]->nextIndexKS2 = item->nextIndexKS2;
    }
    if (item->nextIndexKS2 >= 0) {
        table->table[item->nextIndexKS2]->previousIndexKS2 = item->previousIndexKS2;
    }
    table->table[index]->busy = 0;
    table->currentSize--;
    return 0;
}

int removeByKeyValueKS2(KeySpace2 *table, const char *stringKey) {
    if (table == NULL || table->table == NULL || stringKey == NULL) {
        throw ERROR_INCORRECT_INPUT;
    }
    int index = indexOfByKeyValueKS2(table, stringKey);
    if (index < 0) throw ERROR_NOT_FOUND;
    Item *next = table->table[index];
    while (hasNextItem2(next)) {
        next->busy = 0;
        table->currentSize--;
        next = nextItem2(table, next);
    }
    next->busy = 0;
    table->currentSize--;
    return 0;
}

void destroyKS2(KeySpace2 *table) {
    for (int i = 0; i < table->maxSize; ++i) {
        if (table->table[i] != NULL)
            free(table->table[i]);
    }
    free(table->table);
    free(table);
}

int selectFirstVersionItemKS2(KeySpace2 *table, const char *stringKey, Item **item) {
    int index = indexOfByKeyValueKS2(table, stringKey);
    if (index < 0) throw ERROR_NOT_FOUND;
    *item = table->table[index];
    return 0;
}
