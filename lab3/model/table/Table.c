#include <stddef.h>
#include <stdlib.h>
#include "Table.h"
#include "Errors.h"

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

int put(Table *table, CompositeKey key, const char *data) {
    if (table == NULL) throw ERROR_INCORRECT_INPUT;
    Item *item = NULL;
    if (getItem(&item, key, data)) return ERROR_UNABLE_TO_CREATE_ITEM;
    int insert1Result = insertIntoKS1(table->keySpace1, item);
    if (insert1Result) return insert1Result;
    int insert2Result = insertIntoKS2(table->keySpace2, item);
    if (insert2Result) return insert2Result;
    table->size++;
    int key1V = item->key.key1.version;
    int key2V = item->key.key2.version;
    item->key.version = key1V < key2V ? key1V : key2V;
    return 0;
}
//
//Item *find(Table *table, CompositeKey key) {
//    if (table == NULL) return NULL;
//    int index = indexOfByKeyKS2(table->keySpace2, key.key2);
//    if (index)
//}