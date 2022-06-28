#include <stdlib.h>
#include "test.h"
#include "time.h"
#include "Tree.h"

int insertQ(Tree *tree) {
    int a[1000];
    int b[1000];
    for (int i = 0; i < 1000; ++i) a[i] = rand()%1000;
    for (int i = 0; i < 1000; ++i) b[i] = rand()%1000;
    char *data[1000];
    for (int i = 0; i < 1000; ++i) data[i] = malloc(10);
    clock_t start = clock();
    for (int i = 0; i < 1000; ++i) {
        add(tree, getKey(a[i], b[i]), data[i]);
    }
    clock_t stop = clock();
    return stop - start;
}

int findQ(Tree *tree) {
    int a[1000];
    int b[1000];
    for (int i = 0; i < 1000; ++i) a[i] = rand()%1000;
    for (int i = 0; i < 1000; ++i) b[i] = rand()%1000;
    clock_t start = clock();
    Item *res;
    for (int i = 0; i < 1000; ++i) {
        find(tree, getKey(a[i], b[i]), i, &res);
    }
    clock_t stop = clock();
    return stop - start;
}

int deleteQ(Tree *tree) {
    int a[1000];
    int b[1000];
    for (int i = 0; i < 1000; ++i) a[i] = rand()%1000;
    for (int i = 0; i < 1000; ++i) b[i] = rand()%1000;
    clock_t start = clock();
    for (int i = 0; i < 1000; ++i) {
        delete(tree, getKey(a[i], b[i]), getMaxNumber(tree, getKey(a[i], b[i])));
    }
    clock_t stop = clock();
    return stop - start;
}
