#ifndef NODE_H
#define NODE_H

#include "Item.h"

typedef struct Node {
    Key key;
    Item *item;
    int version;
    struct Node *next;
    struct Node *previous;
} Node;

void destroyNode(Node *node);

#endif
