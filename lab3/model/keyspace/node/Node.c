#include <stdlib.h>
#include <stdio.h>
#include "Node.h"

void destroyNode(Node *node) {
    if (node == NULL) return;
    if (node->next != NULL) node->next->previous = node->previous;
    if (node->previous == NULL) {
        free(node);
        return;
    }
    Node *previous = node->previous;
    previous->next = node->next;
    free(node);
}
