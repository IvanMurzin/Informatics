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

int firstNotEmptyIndex(Node **nodes, int size) {
    for (int i = 0; i < size; ++i) {
        if (nodes[i]->items != NULL) return i;
    }
    return -1;
}

int getNodes(Key borderStart, Key borderEnd, Node **result) {
    for (int i = 0; i < 4; ++i) {
        Key start = getNewStartBorder(borderStart, borderEnd, i);
        Key end = getNewEndBorder(borderStart, borderEnd, i);
        result[i] = getNode(start, end);
    }
    return 0;
}
