#include <stdlib.h>
#include "Container.h"

Container getEmptyContainer(int size) {
    Container result = {0, 0};
    result.data = calloc(size, sizeof(int));
    return result;
}

Container getContainer(Vertex vertex, int size) {
    Container result = getEmptyContainer(size);
    result.vertex = vertex;
    return result;
}
