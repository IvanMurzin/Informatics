#ifndef LAB5_CONTAINER_H
#define LAB5_CONTAINER_H

#include "Vertex.h"

typedef struct Container {
    Vertex vertex;
    int *data;
} Container;

Container getEmptyContainer(int size);


Container getContainer(Vertex vertex, int size);

#endif
