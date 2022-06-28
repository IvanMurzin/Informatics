#ifndef LAB5_EDGE_H
#define LAB5_EDGE_H

#include "Vertex.h"

typedef struct Edge {
    Vertex first;
    Vertex second;
    double weight;
} Edge;

Edge getEdge(Vertex first, Vertex second);

double getDistant(Vertex first, Vertex second);

#endif
