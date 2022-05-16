#include <stdlib.h>
#include <string.h>
#include "Item.h"
#include "Errors.h"
#include "CompositeKey.h"

int getItem(Item **item, CompositeKey key, const char *data) {
    *item = malloc(sizeof(Item));
    if (*item == NULL) throw ERROR_OUT_OF_MEMORY;
    (*item)->key = key;
    (*item)->data = data;
    (*item)->busy = 1;
    (*item)->next = NULL;
    (*item)->waymarkKS1 = getWaymark(-1, -1);
    (*item)->waymarkKS2 = getWaymark(-1, -1);
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
    free(item->key.key1.value);
    free(item->key.key2.value);
    free((char *) item->data);
    free(item);
}

Item *getMockItem(char *strKey1, char *strKey2, char *strData) {
    char *key1 = malloc(4);
    strcpy(key1, strKey1);
    char *key2 = malloc(4);
    strcpy(key2, strKey2);
    char *data = malloc(6);
    strcpy(data, strData);
    return getSimpleItem(key1, key2, data);
}
