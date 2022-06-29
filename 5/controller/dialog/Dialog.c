#include <string.h>
#include "Dialog.h"
#include "Logger.h"

int _getInt(int *a) {
    int n;
    do {
        n = scanf("%d", a);
        if (n < 0) return 0;
        if (n == 0 || *a < 0) {
            printf("%s\n", "Error! Repeat input");
            scanf("%*[^\n]");
            n = 0;
        }
    } while (n == 0);
    return 1;
}

int dialog(const char *messages[], int messageSize) {
    char *errorMessage = "";
    int actionIndex;
    int n;
    do {
        puts(errorMessage);
        errorMessage = "You are wrong. Repeat, please!";
        for (int i = 0; i < messageSize; ++i) {
            puts(messages[i]);
        }
        puts("Make your choice --> ");
        n = _getInt(&actionIndex);
        if (n == 0) actionIndex = 0;
    } while (actionIndex < 0 || actionIndex >= messageSize);
    return actionIndex;
}

Vertex _readVertex() {
    int x = 0;
    puts("Enter x: --> ");
    _getInt(&x);
    int y = 0;
    puts("Enter y: --> ");
    _getInt(&y);
    Vertex vertex = {x, y};
    return vertex;
}

int D_AddVertex(Matrix *matrix) {
    Vertex vertex = _readVertex();
    if (addVertex(matrix, vertex)) puts("Error");
    else puts("Ok");
    return 1;
}

int D_AddEdge(Matrix *matrix) {
    puts("Enter first vertex");
    Vertex first = _readVertex();
    puts("Enter second vertex");
    Vertex second = _readVertex();
    if (addEdge(matrix, getEdge(first, second))) puts("Error");
    else puts("Ok");
    return 1;
}

int D_FindPath(Matrix *matrix) {
    puts("Enter first vertex");
    Vertex first = _readVertex();
    puts("Enter second vertex");
    Vertex second = _readVertex();
    Node *path = NULL;
    if (equalsVertex(first, second)) {
        printf("(%d;%d)", first.x, second.y);
        return 1;
    }
    if (findPathDFS(matrix, first, second, &path)) puts("Error");
    else {
        if (path == NULL || path->next == NULL) puts("Error");
        else {
            puts("Ok");
            printPath(path);
        }
        destroyNodes(path);
    }
    return 1;
}

int D_FindShortestPath(Matrix *matrix) {
    puts("Enter first vertex");
    Vertex first = _readVertex();
    puts("Enter second vertex");
    Vertex second = _readVertex();
    Node *path = NULL;
    if (equalsVertex(first, second)) {
        printf("(%d;%d)", first.x, second.y);
        return 1;
    }
    if (findShortestPathBellmanFord(matrix, first, second, &path)) puts("Error");
    else {
        if (path == NULL || path->next == NULL) puts("Error");
        else {
            puts("Ok");
            printPath(path);
        }
        destroyNodes(path);
    }
    return 1;
}

int D_DeleteVertex(Matrix *matrix) {
    Vertex vertex = _readVertex();
    if (deleteVertex(matrix, vertex)) puts("Error");
    else puts("Ok");
    return 1;
}

int D_DeleteEdge(Matrix *matrix) {
    puts("Enter first vertex");
    Vertex first = _readVertex();
    puts("Enter second vertex");
    Vertex second = _readVertex();
    if (deleteEdge(matrix, getEdge(first, second))) puts("Error");
    else puts("Ok");
    return 1;
}

int D_Show(Matrix *matrix) {
    printMatrix(matrix);
    createPngGraph(matrix);
    return 1;
}

int D_ShowSkeleton(Matrix *matrix) {
    Matrix *res;
    if (findSkeletonPrim(matrix, &res)) {
        D_Show(res);
        destroyMatrix(res);
    } else puts("Error");
    return 1;
}