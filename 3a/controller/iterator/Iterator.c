#include <stddef.h>
#include "Iterator.h"
#include "Item.h"


int hasNextNode(const Node *node) {
    if (node == NULL) return 0;
    return node->next != NULL;
}

Node *nextNode(const Node *node) {
    if (!hasNextNode(node)) return NULL;
    return node->next;
}

int hasNext(const Item *item) {
    return item->next != NULL;
}

Item *next(const Item *item) {
    return item->next;
}

