#include <printf.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "readline/readline.h"

void a(int **a) {
    *a = malloc(sizeof(int) * 5);
    *a[0] = 0;
    *a[1] = 1;
    *a[2] = 2;
    *a[3] = 3;
    *a[4] = 4;
}

int main() {
    BinaryTree *tree = getBinaryTree();
    addBT(tree, 5, "1");
    addBT(tree, 1, "2");
    addBT(tree, 6, "3");
    addBT(tree, 7, "4");
    addBT(tree, 8, "5");
    addBT(tree, 3, "6");
    addBT(tree, 5, "7");
    addBT(tree, 5, "8");
    addBT(tree, 5, "9");
    addBT(tree, 5, "10");
    addBT(tree, 2, "10");
    addBT(tree, 0, "1");
    addBT(tree, 0, "2");
    addBT(tree, 4, "10");
    deleteBT(tree, 7);
    deleteBT(tree, 0);
    deleteBT(tree, 6);
    deleteBT(tree, 8);
    printNLR_BT(tree);
    destroyBinaryTree(tree);
    return 0;
}
