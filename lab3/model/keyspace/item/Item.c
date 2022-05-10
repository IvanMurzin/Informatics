#include <stdlib.h>
#include "Item.h"
#include "Errors.h"

int getItem(Item **item, Key key1, Key key2, const char *data) {
    *item = malloc(sizeof(Item));
    if (*item == NULL) throw ERROR_OUT_OF_MEMORY;
    (*item)->key1 = key1;
    (*item)->key2 = key2;
    (*item)->data = data;
    (*item)->busy = 1;
    (*item)->nextIndexKS1 = -1;
    (*item)->nextIndexKS2 = -1;
    (*item)->previousIndexKS1 = -1;
    (*item)->previousIndexKS2 = -1;
    return 0;
}
