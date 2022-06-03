#include "Container.h"
#include "Edge.h"
#include "Node.h"

#ifndef LAB5_MATRIX_H
#define LAB5_MATRIX_H
typedef struct Matrix {
    int buffSize;
    int size;
    Container *containers;
} Matrix;

Matrix *getMatrix();

int addVertex(Matrix *matrix, Vertex vertex);

int deleteVertex(Matrix *matrix, Vertex vertex);

int addEdge(Matrix *matrix, Edge edge);

int deleteEdge(Matrix *matrix, Edge edge);

int findPathDFS(Matrix *matrix, Vertex begin, Vertex end, Node **path);

int findShortestPathBellmanFord(Matrix *matrix, Vertex begin, Vertex end, Node **path);

int findSkeletonPrim(Matrix *matrix, Matrix **result);

void destroyMatrix(Matrix *matrix);

#endif
