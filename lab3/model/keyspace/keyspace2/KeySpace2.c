#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "KeySpace2.h"
#include "Errors.h"

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
    (*table)->size = 0;
    (*table)->hash = &hash;
    (*table)->containers = calloc(maxSize, sizeof(Container));
    return 0;
}

int indexOfKS2(KeySpace2 *table, Key key) {
    if (table == NULL || table->containers == NULL || key.value == NULL) {
        return -1;
    }
    int hashCode = table->hash(key.value);
    for (int i = 0; i < table->maxSize; ++i) {
        int hash = (hashCode + i) % table->maxSize;
        Container container = table->containers[hash];
        if (container.busy == 0) return -1;
        if ((container.busy == 1) && equalsKey(container.node->key, key)) {
            return hash;
        }
    }
    return -1;
}

int insertIntoKS2(KeySpace2 *table, Item *item) {
    if (table == NULL || table->containers == NULL || item == NULL) {
        throw ERROR_INCORRECT_INPUT;
    }
    if (table->size == table->maxSize) {
        throw ERROR_TABLE_OVERFLOW;
    }
    Key key = item->key.key2;
    int index = indexOfKS2(table, key);
    if (index < 0) {
        Container container = table->containers[table->size];
        container.busy = 1;
        container.node = calloc(1, sizeof(Node));
        container.node->version = 0;
        container.node->key = key;
        return 0;
    }
    Container container = table->containers[table->size];
    Node *temp = container.node;
    container.node = calloc(1, sizeof(Node));
    container.node->version = temp->version + 1;
    container.node->key = item->key.key1;
    container.node->next = temp;
    temp->previous = container.node;
    return 0;
}
//int indexOfGarbageByKeyKS2(KeySpace2 *table, Key key) {
//    if (table == NULL || table->containers == NULL || key.value == NULL) {
//        return -1;
//    }
//    int hashCode = table->hash(key.value);
//    for (int i = 0; i < table->maxSize; ++i) {
//        int hash = (hashCode + i) % table->maxSize;
//        Item *item = table->containers[hash];
//        if (item == NULL) continue;
//        if (!item->busy && equalsKeyValues(item->key.key2.value, key.value)) {
//            return hash;
//        }
//    }
//    return -1;
//}
//
//int indexOfByKeyValueKS2(KeySpace2 *table, const char *stringKey) {
//    if (table == NULL || table->containers == NULL || stringKey == NULL) {
//        return -1;
//    }
//    int hashCode = table->hash(stringKey);
//    for (int i = 0; i < table->maxSize; ++i) {
//        int hash = (hashCode + i) % table->maxSize;
//        Item *item = table->containers[hash];
//        if (item == NULL) return -1;
//        if (item->busy && equalsKeyValues(item->key.key2.value, stringKey)) {
//            return hash;
//        }
//    }
//    return -1;
//}
//int removeByKeyKS2(KeySpace2 *table, Key key) {
//    if (table == NULL || table->containers == NULL || key.value == NULL) {
//        throw ERROR_INCORRECT_INPUT;
//    }
//    int index = indexOfKS2(table, key);
//    if (index < 0) throw ERROR_NOT_FOUND;
//    Item *item = table->containers[index];
//    if (item->waymarkKS2.previous >= 0) {
//        table->containers[item->waymarkKS2.previous]->waymarkKS2.next = item->waymarkKS2.next;
//    }
//    if (item->waymarkKS2.next >= 0) {
//        table->containers[item->waymarkKS2.next]->waymarkKS1.previous = item->waymarkKS2.previous;
//    }
//    table->containers[index]->busy = 0;
//    table->size--;
//    return 0;
//}
//
//int removeByKeyValueKS2(KeySpace2 *table, const char *stringKey) {
//    if (table == NULL || table->containers == NULL || stringKey == NULL) {
//        throw ERROR_INCORRECT_INPUT;
//    }
//    int index = indexOfByKeyValueKS2(table, stringKey);
//    if (index < 0) throw ERROR_NOT_FOUND;
//    Item *next = table->containers[index];
//    while (hasNextItem2(next)) {
//        next->busy = 0;
//        table->size--;
//        next = nextItem2(table, next);
//    }
//    next->busy = 0;
//    table->size--;
//    return 0;
//}
//
//void destroyKS2(KeySpace2 *table) {
//    for (int i = 0; i < table->maxSize; ++i) {
//        if (table->containers[i] != NULL)
//            destroyItem(table->containers[i]);
//    }
//    free(table->containers);
//    free(table);
//}

