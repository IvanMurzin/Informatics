#include "Vertex.h"

Vertex getVertex(int x, int y) {
    Vertex result = {x, y};
    return result;
}

int equalsVertex(Vertex first, Vertex second) {
    return first.x == second.x && first.y == second.y;
}
