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
