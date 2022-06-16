#include <stdlib.h>
#include "Node.h"

Node *getNode(Key border) {
    Node *unit = calloc(1, sizeof(Node));
    unit->border = border;
    return unit;
}
