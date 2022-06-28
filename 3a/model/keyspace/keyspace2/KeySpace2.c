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
    (*table)->hash = &hash;
    (*table)->containers = calloc(maxSize, sizeof(Container));
    return 0;
}

int indexOfKS2(const KeySpace2 *table, Key key) {
    if (table == NULL || table->containers == NULL || key.value == NULL) {
        return -1;
    }
    int hashCode = table->hash(key.value);
    for (int i = 0; i < table->maxSize; ++i) {
        int hash = (hashCode + i) % table->maxSize;
        Container container = table->containers[hash];
        if (container.busy == 0) return -1;
//        if (container.busy == 1 && container.node == NULL) table->containers[hash].busy = -1;
        if (table->containers[hash].busy == -1) continue;
        if (equalsKey(container.node->key, key)) {
            return hash;
        }
    }
    return -1;
}

int insertIntoKS2(KeySpace2 *table, Item *item) {
    if (table == NULL || table->containers == NULL || item == NULL) {
        throw ERROR_INCORRECT_INPUT;
    }
    Key key = item->key.key2;
    int index = indexOfKS2(table, key);
    if (index < 0) {
        for (int i = 0; i < table->maxSize; ++i) {
            int hashCode = table->hash(key.value);
            int hash = (hashCode + i) % table->maxSize;
            if (table->containers[hash].busy != 1 || table->containers[hash].node->item->data == NULL) {
                table->containers[hash].busy = 1;
                table->containers[hash].node = calloc(1, sizeof(Node));
                table->containers[hash].node->version = 0;
                table->containers[hash].node->key = key;
                table->containers[hash].node->parent = &table->containers[hash];
                item->nodeKS2 = table->containers[hash].node;
                table->containers[hash].node->item = item;
                return 0;
            }
        }
        throw ERROR_TABLE_OVERFLOW;
    }
    Node *temp = table->containers[index].node;
    table->containers[index].node = calloc(1, sizeof(Node));
    table->containers[index].node->version = temp->version + 1;
    table->containers[index].node->key = key;
    table->containers[index].node->parent = &table->containers[index];
    table->containers[index].node->item = item;
    item->nodeKS2 = table->containers[index].node;
    table->containers[index].node->next = temp;
    temp->previous = table->containers[index].node;
    return 0;
}

int removeByKeyKS2(const KeySpace2 *table, Key key) {
    if (table == NULL || table->containers == NULL || key.value == NULL) {
        throw ERROR_INCORRECT_INPUT;
    }
    int index = indexOfKS2(table, key);
    if (index < 0) throw ERROR_NOT_FOUND;
    destroyContainer(&table->containers[index]);
    return 0;
}

void destroyKS2(KeySpace2 *table) {
    for (int i = 0; i < table->maxSize; ++i) {
        if (table->containers[i].busy == 1) {
            destroyContainer(&table->containers[i]);
        }
    }
    free(table->containers);
    free(table);
}