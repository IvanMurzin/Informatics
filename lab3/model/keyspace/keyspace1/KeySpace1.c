#include "KeySpace1.h"
#include <stdlib.h>
#include <printf.h>
#include "Errors.h"


int getKS1(KeySpace1 **table, int maxSize) {
    if (maxSize <= 0 || maxSize > 1000) throw ERROR_WRONG_TABLE_SIZE;
    *table = malloc(sizeof(KeySpace1));
    if (*table == NULL) throw ERROR_OUT_OF_MEMORY;
    (*table)->maxSize = maxSize;
    (*table)->size = 0;
    (*table)->containers = calloc(maxSize, sizeof(Container));
    return 0;
}

int collectGarbage(KeySpace1 *table) {
    if (table == NULL) return -1;
    int j = 0;
    for (int i = 0; i < table->size; ++i) {
        if (table->containers[i].busy == 1) {
            table->containers[j].node = table->containers[i].node;
            table->containers[j].busy = 1;
            if (i != j) {
                table->containers[i].busy = 0;
                table->containers[i].node = NULL;
            }
            ++j;
        }
    }
    int garbage = table->size - j;
    table->size -= garbage;
    return garbage;
}

int indexOfKS1(const KeySpace1 *table, Key key) {
    if (table == NULL || table->containers == NULL || key.value == NULL) {
        return -1;
    }
    for (int i = 0; i < table->size; ++i) {
//        Container container = table->containers[i];
//        if (container.busy == 1 && container.node == NULL) table->containers[i].busy = -1;
        if ((table->containers[i].busy == 1) && equalsKey(table->containers[i].node->key, key))
            return i;
    }
    return -1;
}

int insertIntoKS1(KeySpace1 *table, Item *item) {
    if (table == NULL || table->containers == NULL || item == NULL) {
        throw ERROR_INCORRECT_INPUT;
    }
    Key key = item->key.key1;
    int index = indexOfKS1(table, key);
    if (index < 0) {
        if (table->size == table->maxSize) {
            throw ERROR_TABLE_OVERFLOW;
        }
        table->containers[table->size].busy = 1;
        table->containers[table->size].node = calloc(1, sizeof(Node));
        table->containers[table->size].node->version = 0;
        table->containers[table->size].node->key = key;
        table->containers[table->size].node->parent = &table->containers[table->size];
        item->nodeKS1 = table->containers[table->size].node;
        table->containers[table->size].node->item = item;
        table->size++;
        return 0;
    }
    Node *temp = table->containers[index].node;
    table->containers[index].node = calloc(1, sizeof(Node));
    table->containers[index].node->version = temp->version + 1;
    table->containers[index].node->key = key;
    table->containers[index].node->parent = &table->containers[index];
    table->containers[index].node->item = item;
    item->nodeKS1 = table->containers[index].node;
    table->containers[index].node->next = temp;
    temp->previous = table->containers[index].node;
    return 0;
}

int removeByKeyKS1(const KeySpace1 *table, Key key) {
    if (table == NULL || table->containers == NULL || key.value == NULL) {
        throw ERROR_INCORRECT_INPUT;
    }
    int index = indexOfKS1(table, key);
    if (index < 0) throw ERROR_NOT_FOUND;
    destroyContainer(&table->containers[index]);
    return 0;
}

int removeLastByKeyKS1(const KeySpace1 *table, Key key) {
    if (table == NULL || table->containers == NULL || key.value == NULL) {
        throw ERROR_INCORRECT_INPUT;
    }
    int index = indexOfKS1(table, key);
    if (index < 0) throw ERROR_NOT_FOUND;
    Node *node = table->containers[index].node;
    if (node->next == NULL) {
        destroyItem(node->item);
        table->containers[index].node = NULL;
        table->containers[index].busy = 0;
        return 0;
    }
    node->item->nodeKS1 = NULL;
    table->containers[index].node = node->next;
    destroyNode(node);
    return 0;
}

int removeByKeyRange(const KeySpace1 *table, Key floor, Key selling) {
    if (table == NULL || table->containers == NULL || floor.value == NULL || selling.value == NULL) {
        throw ERROR_INCORRECT_INPUT;
    }
    for (int i = 0; i < table->size; ++i) {
        if (table->containers[i].busy == 1) {
            Key key = table->containers[i].node->key;
            if ((compareKey(key, floor) >= 0) && (compareKey(key, selling) <= 0)) {
                destroyContainer(&table->containers[i]);
            }
        }
    }
    return 0;
}

void destroyKS1(KeySpace1 *table) {
    for (int i = 0; i < table->size; ++i) {
        if (table->containers[i].busy) {
            destroyContainer(&table->containers[i]);
        }
    }
    free(table->containers);
    free(table);
}
