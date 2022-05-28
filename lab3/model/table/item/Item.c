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
    (*item)->previous = NULL;
    return 0;
}

Item *getItemCopy(const Item *item) {
    Item *itemCopy = NULL;
    CompositeKey keyCopy = getKeyCopy(item->key);
    char *dataCopy = malloc(strlen(item->data) + 1);
    strcpy(dataCopy, item->data);
    getItem(&itemCopy, keyCopy, dataCopy);
    itemCopy->version = item->version;
    return itemCopy;
}

Item *getSimpleItem(const char *key1, const char *key2, const char *data) {
    Item *item = NULL;
    getItem(&item, getCompositeKey(key1, key2), data);
    return item;
}

void destroyItem(Item *item) {
    if (item == NULL) return;
    if (item->key.key1.value != NULL) destroyKey(item->key.key1);
    if (item->key.key2.value != NULL) destroyKey(item->key.key2);
    free((char *) item->data);
    if (item->nodeKS1 != NULL) destroyNode(item->nodeKS1);
    if (item->nodeKS2 != NULL) destroyNode(item->nodeKS2);
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
