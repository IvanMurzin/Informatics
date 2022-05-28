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


//int delete(Table *table, CompositeKey key) {
//    Item *item;
//    int findResult = find(table, key, &item);
//    if (findResult) throw findResult;
//    removeItem(table, item);
//    return 0;
//}
//
//
//int deleteByKey1(Table *table, Key key1) {
//    if (table == NULL) throw ERROR_INCORRECT_INPUT;
//    int index = indexOfKS1(table->keySpace1, key1);
//    if (index < 0) throw ERROR_NOT_FOUND;
//    Item *item = table->keySpace1->containers[index];
//    while (hasNextItem1(item)) {
//        removeItem(table, item);
//        item = nextItem1(table->keySpace1, item);
//    }
//    removeItem(table, item);
//    return 0;
//}
//
//int deleteByKey2(Table *table, Key key2) {
//    if (table == NULL) throw ERROR_INCORRECT_INPUT;
//    int index = indexOfKS2(table->keySpace2, key2);
//    if (index < 0) throw ERROR_NOT_FOUND;
//    Item *item = table->keySpace2->containers[index];
//    while (hasNextItem2(item)) {
//        removeItem(table, item);
//        item = nextItem2(table->keySpace2, item);
//    }
//    removeItem(table, item);
//    return 0;
//}
//
void destroyTable(Table *table) {
    for (int i = 0; i < table->maxSize; ++i) {
        if (table->keySpace1->containers[i].busy == 1) {
            destroyContainer(&table->keySpace1->containers[i]);
        }
    }
    free(table->keySpace1->containers);
    free(table->keySpace1);
    free(table->keySpace2->containers);
    free(table->keySpace2);
    free(table);
}
//
//int collectGarbage(Table *table) {
//    if (table == NULL) return -1;
//    int j = 0;
//
//    for (int i1 = 0; i1 < table->maxSize; ++i1) {
//        Item *item = table->keySpace1->containers[i1];
//        printf("garbage i1: %d\n", i1);
//        if (!item->busy) {
//            int i2 = indexOfGarbageByKeyKS2(table->keySpace2, item->key.key2);
//            printf("garbage i2: %d\n", i2);
//            table->keySpace1->containers[i1] = NULL;
//            table->keySpace2->containers[i2] = NULL;
//            destroyItem(item);
//            table->size--;
//            table->keySpace1->size--;
//            table->keySpace2->size--;
//            printTable(table);
//        } else {
//            printf("j: %d i: %d\n", j, i1);
//            table->keySpace1->containers[j] = item;
//            ++j;
//        }
//    }
//    printf("return\n");
//    printTable(table);
//
//    return table->size - j;
//}

