#include <printf.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"


void printMatrix(matrix *a) {
    for (int i = 0; i < a->rowSize; ++i) {
        for (int j = 0; j < a->columnSize; ++j) {
            printf("%d\t", a->data[i][j]);
        }
        printf("\n");
    }
}

int insertRow(matrix *a, int index) {
    if (index < 0 || index > a->rowSize) return 0;
    int **newData = malloc((a->rowSize + 1) * a->columnSize * sizeof(int) * 10);
    printf("Введите %d елементов\n", a->columnSize);
    for (int i = 0; i < a->rowSize + 1; ++i) {
        newData[i] = malloc(a->columnSize * sizeof(int));
        for (int j = 0; j < a->columnSize; ++j) {
            if (i < index) newData[i][j] = a->data[i][j];
            else if (i == index) scanf("%d", &newData[i][j]);
            else newData[i][j] = a->data[i - 1][j];

        }
    }
    destroyData(a);
    a->data = newData;
    a->rowSize = a->rowSize + 1;
    return 1;
}

int deleteRow(matrix *a, int index) {
    if (index < 0 || index >= a->rowSize) return 0;
    int **newData = malloc((a->rowSize - 1) * a->columnSize * sizeof(int) * 10);
    for (int i = 0; i < a->rowSize - 1; ++i) {
        newData[i] = malloc(a->columnSize * sizeof(int));
        for (int j = 0; j < a->columnSize; ++j) {
            if (i < index) newData[i][j] = a->data[i][j];
            else newData[i][j] = a->data[i + 1][j];
        }
    }
    destroyData(a);
    a->data = newData;
    a->rowSize = a->rowSize - 1;
    return 1;
}

int insertColumn(matrix *a, int index) {
    if (index < 0 || index > a->columnSize) return 0;
    int **newData = malloc((a->columnSize + 1) * a->rowSize * sizeof(int) * 10);
    printf("Введите %d елементов\n", a->rowSize);
    for (int j = 0; j < a->columnSize + 1; ++j) {
        for (int i = 0; i < a->rowSize; ++i) {
            if (j == 0) newData[i] = malloc(a->columnSize * sizeof(int));
            if (j < index) newData[i][j] = a->data[i][j];
            else if (j == index) scanf("%d", &newData[i][j]);
            else newData[i][j] = a->data[i][j - 1];
        }
    }
    destroyData(a);
    a->data = newData;
    a->columnSize = a->columnSize + 1;
    return 1;
}

int deleteColumn(matrix *a, int index) {
    if (index < 0 || index >= a->columnSize) return 0;
    int **newData = malloc((a->columnSize - 1) * a->rowSize * sizeof(int) * 10);
    for (int j = 0; j < a->columnSize - 1; ++j) {
        for (int i = 0; i < a->rowSize; ++i) {
            if (j == 0) newData[i] = malloc(a->columnSize * sizeof(int));
            if (j < index) newData[i][j] = a->data[i][j];
            else newData[i][j] = a->data[i][j + 1];
        }
    }
    destroyData(a);
    a->data = newData;
    a->columnSize = a->columnSize - 1;
    return 1;
}

void destroyData(matrix *a) {
    for (int i = 0; i < a->rowSize; ++i)free(a->data[i]);
    free(a->data);
}

void destroy(matrix *a) {
    destroyData(a);
    free(a);
}

int multiplyMatrix(matrix *a, matrix *b) {
    int result = 0;
    for (int i = 0; i < a->columnSize; ++i)
        result += a->data[0][i] * b->data[i][0];
    return result;
}

matrix *getMatrixFromStd() {
    int n = -1;
    int m = -1;
    char c;
    printf("Введите размеры матрицы: \n");
    printf("row size: ");
    scanf("%s", &c);
    n = c - '0';
    printf("column size: ");
    scanf("%s", &c);
    m = c - '0';
    while ((n < 0 || n > 10) || (m < 0 || m > 10)) {
        printf("Размеры матрицы должны быть от 0 до 10\n");
        printf("row size: ");
        scanf("%s", &c);
        n = c - '0';
        printf("column size: ");
        scanf("%s", &c);
        m = c - '0';
    }
    matrix *a = malloc(sizeof(matrix));
    a->rowSize = n;
    a->columnSize = m;
    a->data = malloc(n * m * sizeof(int) * 10);
    printf("Введите матрицу: \n");
    for (int i = 0; i < a->rowSize; ++i) {
        a->data[i] = malloc(m * sizeof(int));
        for (int j = 0; j < a->columnSize; ++j) {
            scanf("%d", &a->data[i][j]);
        }
    }
    return a;
}

matrix *generateMatrix(int n, int m) {
    matrix *a = malloc(sizeof(matrix));
    a->rowSize = n;
    a->columnSize = m;
    a->data = malloc(n * m * sizeof(int) * 10);
    for (int i = 0; i < a->rowSize; ++i) {
        a->data[i] = malloc(m * sizeof(int));
        for (int j = 0; j < a->columnSize; ++j) {
            a->data[i][j] = rand() % 20 - 5;
        }
    }
    return a;
}

int writeToBinaryFile(const char *filePath, matrix *a) {
    FILE *file = fopen(filePath, "wb");
    if (file == NULL) return 0;
    fwrite(&a->rowSize, sizeof(int), 1, file);
    fwrite(&a->columnSize, sizeof(int), 1, file);
    for (int i = 0; i < a->rowSize; ++i) {
        for (int j = 0; j < a->columnSize; ++j) {
            fwrite(&a->data[i][j], sizeof(int), 1, file);
        }
    }
    fclose(file);
    return 1;
}

matrix *readFromBinaryFile(const char *filePath) {
    FILE *file = fopen(filePath, "rb");
    if (file == NULL) return NULL;
    matrix *a = malloc(sizeof(matrix));
    int readResult;
    readResult = fread(&a->rowSize, sizeof(int), 1, file);
    if (readResult != 1) {
        free(a);
        return NULL;
    }
    readResult = fread(&a->columnSize, sizeof(int), 1, file);
    if (readResult != 1) {
        free(a);
        return NULL;
    }
    a->data = malloc(a->rowSize * a->columnSize * sizeof(int));
    for (int i = 0; i < a->rowSize; ++i) {
        a->data[i] = malloc(a->columnSize * sizeof(int));
        for (int j = 0; j < a->columnSize; ++j) {
            readResult = fread(&a->data[i][j], sizeof(int), 1, file);
            if (readResult != 1) {
                a->rowSize = i;
                a->columnSize = j;
                destroy(a);
                return NULL;
            }
        }
    }
    fclose(file);
    return a;
}
