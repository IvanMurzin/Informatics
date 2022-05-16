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
    (*table)->table = calloc(maxSize, sizeof(Item *));
    return 0;
}

int indexOfByKeyKS1(KeySpace1 *table, Key key) {
    if (table == NULL || table->table == NULL || key.value == NULL) {
        return -1;
    }
    for (int i = 0; i < table->currentSize; ++i) {
        Item *item = table->table[i];
        if (item->busy && equalsKey(item->key.key1, key)) return i;
    }
    return -1;
}

int indexOfByKeyValueKS1(KeySpace1 *table, const char *stringKey) {
    if (table == NULL || table->table == NULL || stringKey == NULL) {
        return -1;
    }
    for (int i = 0; i < table->currentSize; ++i) {
        Item *item = table->table[i];
        if (item->busy && equalsKeyValues(item->key.key1.value, stringKey))
            return i;
    }
    return -1;
}

int indexOfLatestVersionItemKS1(KeySpace1 *table, const char *stringKey) {
    int index = indexOfByKeyValueKS1(table, stringKey);
    if (index < 0) return -1;
    Item *next = table->table[index];
    while (hasNextItem1(next)) {
        index = next->waymarkKS1.next;
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

int insertIntoKS1(KeySpace1 *table, Item *item) {
    if (table == NULL || table->table == NULL || item == NULL) {
        throw ERROR_INCORRECT_INPUT;
    }
//    if (table->currentSize == table->maxSize) {
//        int garbage = collectGarbage(table);
//        if (garbage == 0) throw ERROR_TABLE_OVERFLOW;
//        table->currentSize -= garbage;
//    }
    if (table->currentSize == table->maxSize) throw ERROR_TABLE_OVERFLOW;
    int version = 0;
    int lastIndex = indexOfLatestVersionItemKS1(table, item->key.key1.value);
    if (lastIndex >= 0) {
        Item *lastItem = table->table[lastIndex];
        lastItem->waymarkKS1.next = table->currentSize;
        version = lastItem->key.key1.version + 1;
    }
    item->key.key1.version = version;
    item->waymarkKS1.previous = lastIndex;
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
    if (item->waymarkKS1.previous >= 0) {
        table->table[item->waymarkKS1.previous]->waymarkKS1.next = item->waymarkKS1.next;
    }
    if (item->waymarkKS1.next >= 0) {
        table->table[item->waymarkKS1.next]->waymarkKS1.previous = item->waymarkKS1.previous;
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
        Key key = table->table[i]->key.key1;
        if ((compareKey(key, floor) >= 0) && (compareKey(key, selling) <= 0)) {
            removeByKeyKS1(table, key);
        }
    }
    return 0;
}

void destroyKS1(KeySpace1 *table) {
    for (int i = 0; i < table->currentSize; ++i) {
        destroyItem(table->table[i]);
    }
    free(table->table);
    free(table);
}
