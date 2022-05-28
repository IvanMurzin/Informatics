#include <stdlib.h>
#include <stdio.h>
#include "Node.h"
#include "Container.h"

void destroyNode(Node *node) {
    if (node == NULL) return;
    if (node->next == NULL && node->previous == NULL) ((Container *) node->parent)->busy = -1;
    if (node->next != NULL) node->next->previous = node->previous;
    if (node->previous == NULL) {
        if (node->parent != NULL) {
            ((Container *) node->parent)->node = node->next;
        }
        free(node);
        return;
    }
    Node *previous = node->previous;
    previous->next = node->next;
    free(node);
}
