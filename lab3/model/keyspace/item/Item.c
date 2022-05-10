#include <stdlib.h>
#include "Item.h"
#include "Errors.h"
#include "CompositeKey.h"

int getItem(Item **item, CompositeKey key, const char *data) {
    *item = malloc(sizeof(Item));
    if (*item == NULL) throw ERROR_OUT_OF_MEMORY;
    (*item)->key.key1 = key.key1;
    (*item)->key.key2 = key.key2;
    (*item)->data = data;
    (*item)->busy = 1;
    (*item)->waymarkKS1 = getWaymark(-1, -1);
    (*item)->waymarkKS2 = getWaymark(-1, -1);
    return 0;
}
