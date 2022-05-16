#ifndef LAB3_ITEM1_H
#define LAB3_ITEM1_H

#include "Item.h"
#include "CompositeKey.h"
#include "Waymark.h"

typedef struct Item {
    int busy;
    CompositeKey key;
    struct Item *next;  // указатель на элемент со следующей версией составного ключа
    Waymark waymarkKS1; // индексы следующей и предыдущей версии элемента в пространстве 1
    Waymark waymarkKS2; // индексы следующей и предыдущей версии элемента в пространстве 2
    const char *data;
} Item;

int getItem(Item **item, CompositeKey key, const char *data);

Item *getItemCopy(Item *item);

Item *getSimpleItem(const char *key1, const char *key2, const char *data);

void destroyItem(Item *item);

Item *getMockItem(char *strKey1, char *strKey2, char *strData);

#endif
