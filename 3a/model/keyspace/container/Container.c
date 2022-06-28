#include <stddef.h>
#include "Container.h"

void destroyContainer(Container *container) {
    Node *node = container->node;
    while (node != NULL) {
        Node *next = node->next;
        destroyItem(node->item);
        node = next;
    }
    container->busy = -1;
    container->node = NULL;
}
