#ifndef LAB4_NODE_H
#define LAB4_NODE_H

#include "Key.h"
#include "Item.h"

typedef struct Node {
    Key border;
    struct Node *parent;
    struct Node *nodes[4];
    Item *items;
    int nodeSize;
} Node;

Node *getNode(Key border);

#endif
