#include <stdlib.h>
#include <printf.h>
#include "Table.h"
#include "Errors.h"
#include "Iterator.h"

int getTable(Table **table, int maxSize) {
    *table = malloc(sizeof(Table));
    if (*table == NULL) throw ERROR_OUT_OF_MEMORY;
    int resultKS1 = getKS1(&(*table)->keySpace1, maxSize);
    if (resultKS1) throw resultKS1;
    int resultKS2 = getKS2(&(*table)->keySpace2, maxSize);
    if (resultKS2) throw resultKS2;
    (*table)->size = 0;
    (*table)->maxSize = maxSize;
    return 0;
}

int put(Table *table, Item *item) {
    if (table == NULL || item == NULL) throw ERROR_INCORRECT_INPUT;
    CompositeKey key = item->key;
    Item *lastCompositeItem = NULL;
    int findCompositeResult = find(table, key, &lastCompositeItem);
    if (!findCompositeResult) {
        while (hasNext(lastCompositeItem))
            lastCompositeItem = next(lastCompositeItem);
        item->version = lastCompositeItem->version + 1;
    }
    int insert1Result = insertIntoKS1(table->keySpace1, item);
    if (insert1Result) throw insert1Result;
    int insert2Result = insertIntoKS2(table->keySpace2, item);
    if (insert2Result) {
        removeLastByKeyKS1(table->keySpace1, item->key.key1);
        throw insert2Result;
    }
    if (lastCompositeItem != NULL) {
        lastCompositeItem->next = item;
        item->previous = lastCompositeItem;
    }
    table->size++;
    return 0;
}

int find(Table *table, CompositeKey key, Item **result) {
    if (table == NULL) throw ERROR_INCORRECT_INPUT;
    int index = indexOfKS2(table->keySpace2, key.key2);
    if (index < 0) throw ERROR_NOT_FOUND;
    Node *node = table->keySpace2->containers[index].node;
    while (!equalsCompositeKey(node->item->key, key) && hasNextNode(node)) {
        node = nextNode(node);
    }
    if (equalsCompositeKey(node->item->key, key)) {
        *result = node->item;
        return 0;
    }
    throw ERROR_NOT_FOUND;
}


int findByKey1(Table *table, Key key, Item **result) {
    if (table == NULL) throw ERROR_INCORRECT_INPUT;
    int index = indexOfKS1(table->keySpace1, key);
    if (index < 0) throw ERROR_NOT_FOUND;
    Node *node = table->keySpace1->containers[index].node;
    *result = getItemCopy(node->item);
    Item *cursor = *result;
    while (hasNextNode(node)) {
        node = nextNode(node);
        cursor->next = getItemCopy(node->item);
        cursor = cursor->next;
    }
    return 0;
}


int findByKey2(Table *table, Key key, Item **result) {
    if (table == NULL) throw ERROR_INCORRECT_INPUT;
    int index = indexOfKS2(table->keySpace2, key);
    if (index < 0) throw ERROR_NOT_FOUND;
    Node *node = table->keySpace2->containers[index].node;
    *result = getItemCopy(node->item);
    Item *cursor = *result;
    while (hasNextNode(node)) {
        node = nextNode(node);
        cursor->next = getItemCopy(node->item);
        cursor = cursor->next;
    }
    return 0;
}


int deleteAll(Table *table, CompositeKey key) {
    Item *item;
    int findResult = find(table, key, &item);
    if (findResult) throw findResult;
    Item *tmp;
    while (item->previous != NULL) item = item->previous;
    while (hasNext(item)) {
        tmp = item;
        item = next(item);
        destroyItem(tmp);
    }
    destroyItem(item);
    return 0;
}


int deleteByKey1(Table *table, Key key1) {
    if (table == NULL) throw ERROR_INCORRECT_INPUT;
    int index = indexOfKS1(table->keySpace1, key1);
    if (index < 0) throw ERROR_NOT_FOUND;
    destroyContainer(&table->keySpace1->containers[index]);
    return 0;
}


int deleteByKey2(Table *table, Key key2) {
    if (table == NULL) throw ERROR_INCORRECT_INPUT;
    int index = indexOfKS2(table->keySpace2, key2);
    if (index < 0) throw ERROR_NOT_FOUND;
    destroyContainer(&table->keySpace2->containers[index]);
    return 0;
}

int deleteByRangeKey1(Table *table, Key floor, Key selling) {
    return removeByKeyRange(table->keySpace1, floor, selling);
}

void destroyTable(Table *table) {
    for (int i = 0; i < table->maxSize; ++i) {
        destroyContainer(&table->keySpace1->containers[i]);
        destroyContainer(&table->keySpace2->containers[i]);
    }
    free(table->keySpace1->containers);
    free(table->keySpace1);
    free(table->keySpace2->containers);
    free(table->keySpace2);
    free(table);
}

