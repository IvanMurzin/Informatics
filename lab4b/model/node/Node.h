#ifndef LAB4_NODE_H
#define LAB4_NODE_H

#include "Key.h"
#include "Item.h"

typedef struct Node {
    Key borderStart;
    Key borderEnd;
    struct Node *parent;
    struct Node *nodes[4];
    Item *items;
    int itemSize;
} Node;

Node *getNode(Key borderStart, Key borderEnd);

void destroyNode(Node *node);

#endif
