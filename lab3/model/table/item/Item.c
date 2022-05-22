#include <stdlib.h>
#include <string.h>
#include "Item.h"
#include "Errors.h"
#include "CompositeKey.h"
#include "Node.h"

int getItem(Item **item, CompositeKey key, const char *data) {
    *item = calloc(1, sizeof(Item));
    if (*item == NULL) throw ERROR_OUT_OF_MEMORY;
    (*item)->key = key;
    (*item)->data = data;
    (*item)->next = NULL;
    return 0;
}

Item *getItemCopy(Item *item) {
    Item *itemCopy = NULL;
    CompositeKey keyCopy = getKeyCopy(item->key);
    char *dataCopy = malloc(strlen(item->data) + 1);
    strcpy(dataCopy, item->data);
    getItem(&itemCopy, keyCopy, dataCopy);
    return itemCopy;
}

Item *getSimpleItem(const char *key1, const char *key2, const char *data) {
    Item *item = NULL;
    getItem(&item, getSimpleCompositeKey(key1, key2), data);
    return item;
}

void destroyItem(Item *item) {
    if (item == NULL) return;
    destroyKey(item->key.key1);
    destroyKey(item->key.key2);
    free((char *) item->data);
    destroyNode(item->nodeKS1);
    destroyNode(item->nodeKS2);
    free(item);
}

Item *getMockItem(char *strKey1, char *strKey2, char *strData) {
    char *key1 = malloc(strlen(strKey1) + 1);
    strcpy(key1, strKey1);
    char *key2 = malloc(strlen(strKey2) + 1);
    strcpy(key2, strKey2);
    char *data = malloc(strlen(strData) + 1);
    strcpy(data, strData);
    return getSimpleItem(key1, key2, data);
}
