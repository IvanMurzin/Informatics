#include <string.h>
#include <stdlib.h>
#include <printf.h>
#include "sys/time.h"
#include "BinaryTree.h"

int insertSortedElements(int count) {
    struct timeval stop, start;
    BinaryTree *tree = getBinaryTree();
    gettimeofday(&start, NULL);
    for (int i = 0; i < count; ++i) {
        addBT(tree, i, "data");
    }
    gettimeofday(&stop, NULL);
    return ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec) / 1000;
}

int insertRandomElements(int count) {
    struct timeval stop, start;
    BinaryTree *tree = getBinaryTree();
    gettimeofday(&start, NULL);
    for (int i = 0; i < count; ++i) {
        addBT(tree, rand(), "data");
    }
    gettimeofday(&stop, NULL);
    return ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec) / 1000;
}

int findInSortedFilledTree(int count) {
    struct timeval stop, start;
    BinaryTree *tree = getBinaryTree();
    for (int i = 0; i < 1000000; ++i) {
        addBT(tree, i, "data");
    }
    BNode **result;
    int size = 0;
    int key = rand() % count;
    while (size == 0) {
        key = rand() % count;
        gettimeofday(&start, NULL);
        findBT(tree, key, &result, &size);
//        printf("key: %d, found: %d \n", key, size);
        gettimeofday(&stop, NULL);
    }
    return ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
}

int findInRandomFilledTree(int count) {
    struct timeval stop, start;
    BinaryTree *tree = getBinaryTree();
    for (int i = 0; i < count; ++i) {
        int key = rand() % 1000;
        addBT(tree, key, "data");
    }
    BNode **result;
    int size = 0;
    int key = rand() % count;
    while (size == 0) {
        key = rand() % 1000;
        gettimeofday(&start, NULL);
        findBT(tree, key, &result, &size);
//        printf("key: %d, found: %d \n", key, size);
        gettimeofday(&stop, NULL);
    }
    return ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
}

int deleteInSortedFilledTree(int count) {
    struct timeval stop, start;
    BinaryTree *tree = getBinaryTree();
    for (int i = 0; i < count; ++i) {
        char *data = malloc(5 * sizeof(char));
        strcpy(data, "data");
        addBT(tree, i, data);
    }
    int key;
    int res = 1;
    while (res) {
        key = rand() % 1000;
        gettimeofday(&start, NULL);
        res = deleteBT(tree, key);
        gettimeofday(&stop, NULL);
    }
    return ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
}

int deleteInRandomFilledTree(int count) {
    struct timeval stop, start;
    BinaryTree *tree = getBinaryTree();
    srand(NULL);
    for (int i = 0; i < count; ++i) {
        int key = rand() % 1000;
        char *data = malloc(5 * sizeof(char));
        strcpy(data, "data");
        addBT(tree, key, data);
    }
    int key;
    int res = 1;
    while (res) {
        key = rand() % 1000;
        gettimeofday(&start, NULL);
        res = deleteBT(tree, key);
        gettimeofday(&stop, NULL);
    }
    return ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
}
