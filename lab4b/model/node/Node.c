#include <stdlib.h>
#include "Node.h"

Node *getNode(Key borderStart, Key borderEnd) {
    Node *unit = calloc(1, sizeof(Node));
    unit->borderStart = borderStart;
    unit->borderEnd = borderEnd;
    return unit;
}

void destroyNode(Node *node) {
    Item *cursor = node->items;
    while (cursor != NULL) {
        Item *trash = cursor;
        cursor = cursor->next;
        destroyItem(trash);
    }
    free(node);
}

int isAllNull(Node **nodes, int size) {
    int countNull = 0;
    for (int i = 0; i < size; ++i) {
        countNull += (nodes[i] == NULL);
    }
    return size == countNull;
}

int firstNotNullIndex(Node **nodes, int size) {
    for (int i = 0; i < size; ++i) {
        if (nodes[i] != NULL) return i;
    }
    return -1;
}
