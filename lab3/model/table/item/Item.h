#ifndef LAB3_ITEM1_H
#define LAB3_ITEM1_H


#include "CompositeKey.h"

struct Node;
typedef struct Item {
    CompositeKey key;
    const char *data;
    int version;
    struct Node *nodeKS1;
    struct Node *nodeKS2;
    struct Item *next;  // указатель на элемент со следующей версией составного ключа
    struct Item *previous;  // указатель на элемент с предыдущей версией составного ключа
} Item;

int getItem(Item **item, CompositeKey key, const char *data);

Item *getItemCopy(Item *item);

Item *getSimpleItem(const char *key1, const char *key2, const char *data);

Item *getMockItem(char *strKey1, char *strKey2, char *strData);

void destroyItem(Item *item);

#endif
