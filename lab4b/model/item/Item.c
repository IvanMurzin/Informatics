#include <stdlib.h>
#include "Item.h"

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
