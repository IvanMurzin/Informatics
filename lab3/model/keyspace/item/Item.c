#include <stdlib.h>
#include "Item.h"
#include "Errors.h"

int getItem(Item **item, Key key, const char *data) {
    *item = malloc(sizeof(Item));
    if (*item == NULL) throw ERROR_OUT_OF_MEMORY;
    (*item)->key = key;
    (*item)->data = data;
    (*item)->busy = 1;
    (*item)->nextIndex = -1;
    (*item)->previousIndex = -1;
    return 0;
}