#include <stdlib.h>
#include "test.h"
#include "sys/time.h"
#include "BinaryTree.h"

int insert(BinaryTree *tree) {
    int a[1000];
    for (int i = 0; i < 1000; ++i) a[i] = rand();
    clock_t start = clock();
    for (int i = 0; i < 1000; ++i) {
        addBT(tree, a[i], "data");
    }
    clock_t stop = clock();
    return stop - start;
}

int find(BinaryTree *tree) {
    int a[1000];
    for (int i = 0; i < 1000; ++i) a[i] = rand();
    clock_t start = clock();
    BNode **res;
    int s;
    for (int i = 0; i < 1000; ++i) {
        findBT(tree, a[i], &res, &s);
    }
    clock_t stop = clock();
    return stop - start;
}

int delete(BinaryTree *tree) {
    int a[1000];
    for (int i = 0; i < 1000; ++i) a[i] = rand();
    clock_t start = clock();
    for (int i = 0; i < 1000; ++i) {
        deleteBT(tree, a[i]);
    }
    clock_t stop = clock();
    return stop - start;
}
