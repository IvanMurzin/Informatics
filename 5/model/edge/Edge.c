#include "math.h"
#include "Edge.h"

double getDistant(Vertex first, Vertex second) {
    int dx = first.x - second.x;
    int dy = first.y - second.y;
    return sqrt(dx * dx + dy * dy);
}

Edge getEdge(Vertex first, Vertex second) {
    Edge result = {first, second, getDistant(first, second)};
    return result;
}


