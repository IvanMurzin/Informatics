#include <stdlib.h>
#include "Node.h"

void pushFirst(Node **node, Vertex vertex) {
    if (*node == NULL) {
        *node = calloc(1, sizeof(Node));
        (*node)->data = vertex;
        return;
    }
    Node *newNode = calloc(1, sizeof(Node));
    newNode->data = vertex;
    newNode->next = *node;
    *node = newNode;
}

void destroyNodes(Node *node) {
    Node *cursor = node;
    while (cursor != NULL) {
        Node *trash = cursor;
        cursor = cursor->next;
        free(trash);
    }
}
