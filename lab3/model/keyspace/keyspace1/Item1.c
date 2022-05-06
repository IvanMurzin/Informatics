#include <stdlib.h>
#include "Item1.h"
#include "Errors.h"

int getItem1(Item1 **item, Key1 key, const char *data) {
    *item = malloc(sizeof(Item1));
    if (*item == NULL) throw ERROR_OUT_OF_MEMORY;
    (*item)->key1 = key;
    (*item)->data = data;
    (*item)->busy = 1;
    (*item)->nextIndex = -1;
    return 0;
}