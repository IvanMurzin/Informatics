#ifndef LAB5_NODE_H
#define LAB5_NODE_H

#include "Vertex.h"

typedef struct Node {
    struct Node *next;
    Vertex data;
} Node;

void pushFirst(Node **node, Vertex vertex);

void destroyNodes(Node *node);

#endif
