#include <stdlib.h>
#include "KeySpace1.h"
#include "Errors.h"
#include "IteratorKS.h"


int getKS1(KeySpace1 **table, int maxSize) {
    if (maxSize <= 0 || maxSize > 1000) throw ERROR_WRONG_TABLE_SIZE;
    *table = malloc(sizeof(KeySpace1));
    if (*table == NULL) throw ERROR_OUT_OF_MEMORY;
    (*table)->maxSize = maxSize;
    (*table)->currentSize = 0;
    (*table)->table = malloc(sizeof(Item *) * maxSize);
    return 0;
}

int collectGarbage(KeySpace1 *table) {
    if (table == NULL) return -1;
    int j = 0;
    for (int i = 0; i < table->currentSize; ++i) {
        if (!table->table[i]->busy) {
            free(table->table[i]);
        } else {
            table->table[j] = table->table[i];
            ++j;
        }
    }
    return table->currentSize - j;
}

int indexOfByKeyKS1(KeySpace1 *table, Key key) {
    if (table == NULL || table->table == NULL || key.value == NULL) {
        return -1;
    }
    for (int i = 0; i < table->currentSize; ++i) {
        Item *item = table->table[i];
        if (item->busy && equalsKey(item->key, key)) return i;
    }
    return -1;
}

int indexOfByKeyValueKS1(KeySpace1 *table, const char *stringKey) {
    if (table == NULL || table->table == NULL || stringKey == NULL) {
        return -1;
    }
    for (int i = 0; i < table->currentSize; ++i) {
        Item *item = table->table[i];
        if (item->busy && equalsKeyValues(item->key.value, stringKey))
            return i;
    }
    return -1;
}

int indexOfLatestVersionItemKS1(KeySpace1 *table, const char *stringKey) {
    int index = indexOfByKeyValueKS1(table, stringKey);
    if (index < 0) return -1;
    Item *next = table->table[index];
    while (hasNextItem1(next)) {
        index = next->nextIndexKS1;
        next = nextItem1(table, next);
    }
    return index;
}

int selectFirstVersionItemKS1(KeySpace1 *table, const char *stringKey, Item **item) {
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
    Item *item = NULL;
    int lastIndex = indexOfLatestVersionItemKS1(table, stringKey);
    if (lastIndex >= 0) {
        Item *lastItem = table->table[lastIndex];
        lastItem->nextIndexKS1 = table->currentSize;
        version = lastItem->key.version + 1;
    }
    Key key = {stringKey, version};
    if (getItem(&item, key, data)) throw ERROR_UNABLE_TO_CREATE_ITEM;
    item->previousIndexKS1 = lastIndex;
    table->table[table->currentSize] = item;
    table->currentSize++;
    return 0;
}

int removeByKeyKS1(KeySpace1 *table, Key key) {
    if (table == NULL || table->table == NULL || key.value == NULL) {
        throw ERROR_INCORRECT_INPUT;
    }
    int index = indexOfByKeyKS1(table, key);
    if (index < 0) throw ERROR_NOT_FOUND;
    Item *item = table->table[index];
    if (item->previousIndexKS1 >= 0) {
        table->table[item->previousIndexKS1]->nextIndexKS1 = item->nextIndexKS1;
    }
    if (item->nextIndexKS1 >= 0) {
        table->table[item->nextIndexKS1]->previousIndexKS1 = item->previousIndexKS1;
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
    Item *next = table->table[index];
    while (hasNextItem1(next)) {
        next->busy = 0;
        next = nextItem1(table, next);
    }
    next->busy = 0;
    return 0;
}


int removeByKeyRange(KeySpace1 *table, Key floor, Key selling) {
    if (table == NULL || table->table == NULL || floor.value == NULL || selling.value == NULL) {
        throw ERROR_INCORRECT_INPUT;
    }
    for (int i = 0; i < table->currentSize; ++i) {
        Key key = table->table[i]->key;
        if ((compareKey(key, floor) >= 0) && (compareKey(key, selling) <= 0)) {
            removeByKeyKS1(table, key);
        }
    }
    return 0;
}

void destroyKS1(KeySpace1 *table) {
    for (int i = 0; i < table->currentSize; ++i) {
        free(table->table[i]);
    }
    free(table->table);
    free(table);
}
