#include <stdlib.h>
#include <limits.h>
#include "Matrix.h"

void _initContainers(Matrix *matrix, int size) {
    matrix->containers = calloc(size, sizeof(Container));
    for (int i = 0; i < size; ++i) matrix->containers[i] = getEmptyContainer(size);
}

int _findMatrix(Matrix *matrix, Vertex vertex) {
    for (int i = 0; i < matrix->size; ++i) {
        if (equalsVertex(vertex, matrix->containers[i].vertex)) {
            return i;
        }
    }
    return -1;
}


Matrix *getMatrix() {
    int initSize = 5;
    Matrix *matrix = calloc(1, sizeof(Matrix));
    matrix->size = 0;
    matrix->buffSize = initSize;
    _initContainers(matrix, initSize);
    return matrix;
}

int addVertex(Matrix *matrix, Vertex vertex) {
    if (matrix == NULL || matrix->containers == NULL) return 1;
    int index = _findMatrix(matrix, vertex);
    if (index >= 0) return 1;
    if (matrix->size == matrix->buffSize) {
        matrix->buffSize += 5;
        Container *oldContainers = matrix->containers;
        _initContainers(matrix, matrix->buffSize);
        for (int i = 0; i < matrix->size; ++i) {
            matrix->containers[i].vertex = oldContainers[i].vertex;
            for (int j = 0; j < matrix->size; ++j) {
                matrix->containers[i].data[j] = oldContainers[i].data[j];
            }
        }
        for (int i = 0; i < matrix->size; ++i) free(oldContainers[i].data);
        free(oldContainers);
    }
    matrix->containers[matrix->size].vertex = vertex;
    matrix->size++;
    return 0;
}

int addEdge(Matrix *matrix, Edge edge) {
    if (matrix == NULL || matrix->containers == NULL) return 1;
    int firstIndex = _findMatrix(matrix, edge.first);
    if (firstIndex < 0) return 1;
    int secondIndex = _findMatrix(matrix, edge.second);
    if (secondIndex < 0) return 1;
//    if (firstIndex == secondIndex) matrix->containers[firstIndex].data[secondIndex] = 1;
//    else {
    matrix->containers[firstIndex].data[secondIndex] = 1;
    matrix->containers[secondIndex].data[firstIndex] = 1;
//    }
    return 0;
}

int deleteVertex(Matrix *matrix, Vertex vertex) {
    if (matrix == NULL || matrix->containers == NULL) return 1;
    int index = _findMatrix(matrix, vertex);
    if (index < 0) return 1;
    for (int i = 0; i < matrix->size; ++i) {
        Container container = matrix->containers[i];
        for (int j = index; j < matrix->size - 1; ++j) {
            container.data[j] = container.data[j + 1];
        }
    }
    free(matrix->containers[index].data);
    for (int i = index; i < matrix->size - 1; ++i) {
        matrix->containers[i] = matrix->containers[i + 1];
    }
    matrix->size--;
    return 0;
}

int deleteEdge(Matrix *matrix, Edge edge) {
    if (matrix == NULL || matrix->containers == NULL) return 1;
    int firstIndex = _findMatrix(matrix, edge.first);
    if (firstIndex < 0) return 1;
    int secondIndex = _findMatrix(matrix, edge.second);
    if (secondIndex < 0) return 1;
    if (matrix->containers[firstIndex].data[secondIndex] < 0 || matrix->containers[secondIndex].data[firstIndex] < 0)
        return 1;
//    if (firstIndex == secondIndex) matrix->containers[firstIndex].data[secondIndex] = 0;
//    else {
    matrix->containers[firstIndex].data[secondIndex] = 0;
    matrix->containers[secondIndex].data[firstIndex] = 0;
//    }
    return 0;
}


void _dfs(Matrix *matrix, int *colors, int *previous, int index) {
    colors[index] = 1;
    Container container = matrix->containers[index];
    for (int i = 0; i < matrix->size; ++i) {
        if (container.data[i] == 1) {
            if (colors[i] == 0) {
                previous[i] = index;
                _dfs(matrix, colors, previous, i);
            }
        }
    }
    colors[index] = 2;
}

int _buildPath(Matrix *matrix, int endIndex, int beginIndex, int *previous, Node **path) {
    pushFirst(path, matrix->containers[endIndex].vertex);
    int prev = previous[endIndex];
    while (prev != -1 && prev != beginIndex) {
        pushFirst(path, matrix->containers[prev].vertex);
        prev = previous[prev];
    }
    pushFirst(path, matrix->containers[beginIndex].vertex);
    return 0;
}

int findPathDFS(Matrix *matrix, Vertex begin, Vertex end, Node **path) {
    if (matrix == NULL || matrix->containers == NULL) return 1;
    int beginIndex = _findMatrix(matrix, begin);
    if (beginIndex < 0) return 1;
    int endIndex = _findMatrix(matrix, end);
    if (endIndex < 0) return 1;
    int *colors = calloc(matrix->size, sizeof(int));
    int *previous = malloc(matrix->size * sizeof(int));
    for (int i = 0; i < matrix->size; ++i) previous[i] = -1;
    _dfs(matrix, colors, previous, beginIndex);
    int res = _buildPath(matrix, endIndex, beginIndex, previous, path);
    free(colors);
    free(previous);
    return res;
}

int _allZero(int *a, int size) {
    for (int i = 0; i < size; ++i) {
        if (a[i] != 0) return 0;
    }
    return 1;
}

int findShortestPathBellmanFord(Matrix *matrix, Vertex begin, Vertex end, Node **path) {
    if (matrix == NULL || matrix->containers == NULL) return 1;
    for (int i = 0; i < matrix->size; ++i) {
        if (_allZero(matrix->containers[i].data, matrix->size)) return 1;
    }
    int beginIndex = _findMatrix(matrix, begin);
    if (beginIndex < 0) return 1;
    int endIndex = _findMatrix(matrix, end);
    if (endIndex < 0) return 1;

    int *d = malloc(sizeof(int) * matrix->size);
    int *previous = malloc(matrix->size * sizeof(int));
    for (int i = 0; i < matrix->size; ++i) {
        d[i] = INT_MAX - 1000;
        previous[i] = -1;
    }
    d[beginIndex] = 0;
    for (int _ = 0; _ < matrix->size; ++_) {
        for (int i = 0; i < matrix->size; ++i) {
            Container first = matrix->containers[i];
            for (int j = 0; j < matrix->size; ++j) {
                if (first.data[j] != 1) continue;
                Container second = matrix->containers[j];
                int weight = getDistant(first.vertex, second.vertex);
                if (d[j] > d[i] + weight) {
                    d[j] = d[i] + weight;
                    previous[j] = i;
                }
            }
        }
    }
    _buildPath(matrix, endIndex, beginIndex, previous, path);
    free(d);
    free(previous);
    return 0;
}

void destroyMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->buffSize; ++i) {
        free(matrix->containers[i].data);
    }
    free(matrix->containers);
    free(matrix);
}

int _min(int *a, int size) {
    int min = INT_MAX;
    int minIndex = 0;
    for (int i = 0; i < size; ++i) {
        if ((a[i] < min) && a[i] != -1) {
            min = a[i];
            minIndex = i;
        }
    }
    a[minIndex] = -1;
    return minIndex;
}

int findSkeletonPrim(Matrix *matrix, Matrix **result) {
    int *queue = malloc(sizeof(int) * matrix->size);
    int *previous = malloc(matrix->size * sizeof(int));
    int n = matrix->size;
    for (int i = 0; i < matrix->size; ++i) {
        queue[i] = INT_MAX - 10;
        previous[i] = -1;
    }
    queue[0] = 0;
    while (n > 0) {
        int minIndex = _min(queue, matrix->size);
        n--;
        Container container = matrix->containers[minIndex];
        for (int i = 0; i < matrix->size; ++i) {
            if (container.data[i] == 1) {
                int weight = getDistant(container.vertex, matrix->containers[i].vertex);
                if (weight < queue[i]) {
                    previous[i] = minIndex;
                    queue[i] = weight;
                }
            }
        }
    }
    *result = getMatrix();
    for (int i = 0; i < matrix->size; ++i) {
        addVertex(*result, matrix->containers[i].vertex);
    }
    for (int i = 0; i < matrix->size; ++i) {
        addEdge(*result, getEdge(matrix->containers[i].vertex, matrix->containers[previous[i]].vertex));
    }
    return 0;
}




