#ifndef LAB5_VERTEX_H
#define LAB5_VERTEX_H
typedef struct Vertex {
    int x;
    int y;
} Vertex;

Vertex getVertex(int x, int y);

int equalsVertex(Vertex first, Vertex second);

#endif
