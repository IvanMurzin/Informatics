#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "Table.h"
#include "Errors.h"
#include "IteratorKS.h"
#include "Logger.h"

int getTable(Table **table, int maxSize) {
    *table = malloc(sizeof(Table));
    if (*table == NULL) throw ERROR_OUT_OF_MEMORY;
    int resultKS1 = getKS1(&(*table)->keySpace1, maxSize);
    if (resultKS1) return resultKS1;
    int resultKS2 = getKS2(&(*table)->keySpace2, maxSize);
    if (resultKS2) return resultKS2;
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
        item->key.version = lastCompositeItem->key.version + 1;
        lastCompositeItem->next = item;
    }
    int insert1Result = insertIntoKS1(table->keySpace1, item);
    if (insert1Result == ERROR_TABLE_OVERFLOW) {
        printf("collect: %d", collectGarbage(table));
        lastCompositeItem->next = NULL;
        insert1Result = insertIntoKS1(table->keySpace1, item);
    }
    if (insert1Result) {
        if (lastCompositeItem != NULL)
            lastCompositeItem->next = NULL;
        throw insert1Result;
    }
    int insert2Result = insertIntoKS2(table->keySpace2, item);
    if (insert2Result) {
        if (lastCompositeItem != NULL)
            lastCompositeItem->next = NULL;
        throw insert2Result;
    }
    table->size++;
    return 0;
}

int find(Table *table, CompositeKey key, Item **result) {
    if (table == NULL) throw ERROR_INCORRECT_INPUT;
    int index = indexOfByKeyKS2(table->keySpace2, key.key2);
    if (index < 0) throw ERROR_NOT_FOUND;
    Item *item = table->keySpace2->table[index];
    while (!compositeKeyEqualsValues(item->key, key) && hasNextItem2(item)) {
        item = nextItem2(table->keySpace2, item);
    }
    if (compositeKeyEqualsValues(item->key, key)) {
        *result = item;
        return 0;
    }
    throw ERROR_NOT_FOUND;
}


int findByKey1(Table *table, Key key, KeySpace1 **result) {
    if (table == NULL) throw ERROR_INCORRECT_INPUT;
    int index = indexOfByKeyKS1(table->keySpace1, key);
    if (index < 0) throw ERROR_NOT_FOUND;
    Item *latestVersionItem = table->keySpace1->table[index];
    while (hasNextItem1(latestVersionItem)) {
        latestVersionItem = nextItem1(table->keySpace1, latestVersionItem);
    }
    int countItems = latestVersionItem->key.key1.version + 1;
    int creationResult = getKS1(result, countItems);
    if (creationResult) throw creationResult;
    Item *item = table->keySpace1->table[index];
    while (hasNextItem1(item)) {
        insertIntoKS1((*result), getItemCopy(item));
        item = nextItem1(table->keySpace1, item);
    }
    insertIntoKS1((*result), getItemCopy(item));
    return 0;
}

int findByKey2(Table *table, Key key, KeySpace2 **result) {
    if (table == NULL) throw ERROR_INCORRECT_INPUT;
    int index = indexOfByKeyKS2(table->keySpace2, key);
    if (index < 0) throw ERROR_NOT_FOUND;
    Item *latestVersionItem = table->keySpace2->table[index];
    while (hasNextItem2(latestVersionItem)) {
        latestVersionItem = nextItem2(table->keySpace2, latestVersionItem);
    }
    int countItems = latestVersionItem->key.key2.version + 1;
    int creationResult = getKS2(result, countItems);
    if (creationResult) throw creationResult;
    Item *item = table->keySpace2->table[index];
    while (hasNextItem2(item)) {
        insertIntoKS2((*result), getItemCopy(item));
        item = nextItem2(table->keySpace2, item);
    }
    insertIntoKS2((*result), getItemCopy(item));
    return 0;
}

void removeItem(Table *table, Item *item) {
    Item **tableKS1 = table->keySpace1->table;
    Item **tableKS2 = table->keySpace2->table;
    if (item->waymarkKS1.previous >= 0) {
        tableKS1[item->waymarkKS1.previous]->waymarkKS1.next = item->waymarkKS1.next;
    }
    if (item->waymarkKS1.next >= 0) {
        tableKS1[item->waymarkKS1.next]->waymarkKS1.previous = item->waymarkKS1.previous;
    }
    if (item->waymarkKS2.previous >= 0) {
        tableKS2[item->waymarkKS2.previous]->waymarkKS2.next = item->waymarkKS2.next;
    }
    if (item->waymarkKS2.next >= 0) {
        tableKS2[item->waymarkKS2.next]->waymarkKS1.previous = item->waymarkKS2.previous;
    }
    item->busy = 0;
    table->keySpace2->currentSize--;
    table->size--;
}

int delete(Table *table, CompositeKey key) {
    Item *item;
    int findResult = find(table, key, &item);
    if (findResult) throw findResult;
    removeItem(table, item);
    return 0;
}

int deleteAll(Table *table, CompositeKey key) {
    Item *item;
    int findResult = find(table, key, &item);
    if (findResult) throw findResult;
    while (hasNext(item)) {
        removeItem(table, item);
        item = next(item);
    }
    removeItem(table, item);
    return 0;
}

int deleteByKey1(Table *table, Key key1) {
    if (table == NULL) throw ERROR_INCORRECT_INPUT;
    int index = indexOfByKeyKS1(table->keySpace1, key1);
    if (index < 0) throw ERROR_NOT_FOUND;
    Item *item = table->keySpace1->table[index];
    while (hasNextItem1(item)) {
        removeItem(table, item);
        item = nextItem1(table->keySpace1, item);
    }
    removeItem(table, item);
    return 0;
}

int deleteByKey2(Table *table, Key key2) {
    if (table == NULL) throw ERROR_INCORRECT_INPUT;
    int index = indexOfByKeyKS2(table->keySpace2, key2);
    if (index < 0) throw ERROR_NOT_FOUND;
    Item *item = table->keySpace2->table[index];
    while (hasNextItem2(item)) {
        removeItem(table, item);
        item = nextItem2(table->keySpace2, item);
    }
    removeItem(table, item);
    return 0;
}

void destroyTable(Table *table) {
    for (int i = 0; i < table->size; ++i) {
        free(table->keySpace1->table[i]->key.key1.value);
        free(table->keySpace1->table[i]->key.key2.value);
        free((char *) table->keySpace1->table[i]->data);
        free(table->keySpace1->table[i]);
    }
    free(table->keySpace1->table);
    free(table->keySpace1);
    free(table->keySpace2->table);
    free(table->keySpace2);
    free(table);
}

int collectGarbage(Table *table) {
    if (table == NULL) return -1;
    int j = 0;

    for (int i1 = 0; i1 < table->maxSize; ++i1) {
        Item *item = table->keySpace1->table[i1];
        printf("garbage i1: %d\n", i1);
        if (!item->busy) {
            int i2 = indexOfGarbageByKeyKS2(table->keySpace2, item->key.key2);
            printf("garbage i2: %d\n", i2);
            table->keySpace1->table[i1] = NULL;
            table->keySpace2->table[i2] = NULL;
            destroyItem(item);
            table->size--;
            table->keySpace1->currentSize--;
            table->keySpace2->currentSize--;
            printTable(table);
        } else {
            printf("j: %d i: %d\n", j, i1);
            table->keySpace1->table[j] = item;
            ++j;
        }
    }
    printf("return\n");
    printTable(table);

    return table->size - j;
}

