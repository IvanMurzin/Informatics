#include "stdio.h"
#include "Logger.h"

void _print(Matrix *matrix, int size) {
    if (matrix == NULL || matrix->containers == NULL || size == 0) return;
    printf("               ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < size; ++i) {
        Container container = matrix->containers[i];
        printf("|x:%2d y:%2d|%2d| ", container.vertex.x, container.vertex.y, i);
        for (int j = 0; j < size; ++j) printf("%d ", container.data[j]);
        printf("|\n");
    }
}

void printMatrix(Matrix *matrix) {
    _print(matrix, matrix->size);
}

void printFullMatrix(Matrix *matrix) {
    _print(matrix, matrix->buffSize);
}

void printPath(Node *node) {
    if (node == NULL) return;
    Node *cursor = node;
    printf("(%d;%d)", cursor->data.x, cursor->data.y);
    cursor = cursor->next;
    while (cursor != NULL) {
        printf("--(%d;%d)", cursor->data.x, cursor->data.y);
        cursor = cursor->next;
    }
    printf("\n");
}
