#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

matrix *getMatrix() {
    int n;
    char c;
    printf("Введите:\n"
           "1 - чтобы считать матрицу из стандартного ввода\n"
           "2 - чтобы считать матрицу из бинарного файла\n"
           "3 - чтобы сгенерировать матрицу\n"
           "0 - для выхода из программы\n");
    scanf("%s", &c);
    n = c - '0';
    int N = 0, M = 0;
    while (n < 0 || n > 3) {
        printf("Неправильно, повторите ввод: ");
        char t;
        scanf("%s", &t);
        n = t - '0';
    }
    fflush(stdin);
    char filePath[256];
    matrix *a;
    switch (n) {
        case 0:
            return NULL;
        case 1:
            a = getMatrixFromStd();
            break;
        case 2:
            do {
                printf("Введите путь до файла: ");
                scanf("%s", filePath);
                fflush(stdin);
                a = readFromBinaryFile(filePath);
                if (a == NULL) printf("Что-то пошло не так, повторите ввод:\n");
            } while (a == NULL);
            break;
        case 3:
            printf("Введите размеры матрицы: ");
            while (N <= 0 || N >= 10 || M <= 0 || M >= 10) {
                scanf("%d", &N);
                scanf("%d", &M);
                fflush(stdin);
                if (N <= 0 || N >= 10 || M <= 0 || M >= 10) printf("Неправильно, повторите ввод:\n");
            }
            a = generateMatrix(N, M);
    }
    printMatrix(a);
    printf("Введите:\n"
           "1 - чтобы добавить столбец\n"
           "2 - чтобы удалить столбец\n"
           "3 - чтобы добавить строку\n"
           "4 - чтобы удалить строку\n"
           "5 - чтобы продолжить\n"
           "0 - для выхода из программы\n");
    char g;
    scanf("%s", &g);
    n = g - '0';
    while (n < 0 || n > 5) {
        char t;
        printf("Неправильно, повторите ввод: ");
        scanf("%s", &t);
        n = t - '0';
    }
    char t;
    switch (n) {
        case 0:
            return NULL;
        case 1:
            printf("Введите индекс, куда надо вставить столбец: \n");
            scanf("%s", &t);
            n = t - '0';
            while (!insertColumn(a, n)) {
                printf("Неправильно введен индекс, повторите ввод: ");
                printf("columnSize:%d \n", a->columnSize);
                char t1;
                scanf("%s", &t1);
                n = t1 - '0';
            }
            break;
        case 2:
            printf("Введите индекс, под которым нужно удалить столбец: \n");
            scanf("%s", &t);
            n = t - '0';
            while (!deleteColumn(a, n)) {
                printf("Неправильно введен индекс, повторите ввод: ");
                char t1;
                scanf("%s", &t1);
                n = t1 - '0';
            }
            break;
        case 3:
            printf("Введите индекс, куда надо вставить строку: \n");
            scanf("%s", &t);
            n = t - '0';
            while (!insertRow(a, n)) {
                printf("Неправильно введен индекс, повторите ввод: ");
                char t1;
                scanf("%s", &t1);
                n = t1 - '0';
            }
            break;
        case 4:
            printf("Введите индекс, под которым нужно удалить строку: \n");
            scanf("%s", &t);
            n = t - '0';
            while (!deleteRow(a, n)) {
                printf("Неправильно введен индекс, повторите ввод: ");
                char t1;
                scanf("%s", &t1);
                n = t1 - '0';
            }
            break;
    }
    return a;
}

int main() {
    matrix *a;
    matrix *b;
    do {
        do {
            a = getMatrix();
            if (a == NULL) return 0;
            printf("\nМатрица а:\n");
            printMatrix(a);
            printf("Записать ее в бинарный файл?\n"
                   "1 - да\n"
                   "2 - продолжить\n"
                   "0 - выход из программы\n");
            char t;
            scanf("%s", &t);
            int n = t - '0';
            while (n < 0 || n > 2) {
                char t;
                printf("Неправильно, повторите ввод: ");
                scanf("%s", &t);
                n = t - '0';
            }
            char filePath[256];
            int code = 0;
            switch (n) {
                case 0:
                    destroy(a);
                    return 0;
                case 1:
                    do {
                        printf("Введите путь до файла: ");
                        scanf("%s", filePath);
                        fflush(stdin);
                        code = writeToBinaryFile(filePath, a);
                        if (!code) printf("Что-то пошло не так, повторите ввод:\n");
                    } while (!code);
                    printf("Успешно!\n");
                    break;
            }
            if (a->rowSize != 1) {
                printf("На вход должен подаваться вектор-строка\nПовторите ввод:\n");
                destroy(a);
            }
        } while (a->rowSize != 1);
        do {
            b = getMatrix();
            if (b == NULL) return 0;
            printf("\nМатрица b\n");
            printMatrix(b);
            if (b->columnSize != 1) {
                printf("На вход должен подаваться вектор-столбец\nПовторите ввод:\n");
                destroy(b);
            }
        } while (b->columnSize != 1);

        if (a->columnSize != b->rowSize) {
            printf("Количество столбцов первой матрицы должно равняться количеству строк второй матрицы\nПовторите ввод:\n");
            destroy(a);
            destroy(b);
        }

    } while (a->columnSize != b->rowSize);
    printf("Ответ: %d\n", multiplyMatrix(a, b));
    destroy(a);
    destroy(b);
    return 0;
}

// /Users/ivanmurzin/Projects/CLionProjects/lab5/file.bin

