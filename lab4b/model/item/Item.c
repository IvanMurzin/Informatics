#include <stdlib.h>
#include "Item.h"
#include "Node.h"

Item *getItem(Key key, const char *data) {
    Item *node = calloc(1, sizeof(Item));
    node->key = key;
    node->data = data;
    return node;
}

void destroyItem(Item *item) {
//    free((char *) item->data); // todo remove
    free(item);
}

int putSorted(Item **src, Item *item) {
    if (src == NULL || *src == NULL || item == NULL) return 1;
    if (gte((*src)->key, item->key)) {
        item->next = *src;
        *src = item;
        return 0;
    }
    Item *cursor = *src;
    while (cursor->next != NULL) {
        if (gte(cursor->next->key, item->key)) {
            Item *tmp = cursor;
            item->next = tmp->next;
            cursor->next = item;
            return 0;
        }
        cursor = cursor->next;
    }
    cursor->next = item;
    return 0;
}
