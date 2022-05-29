#include "BinaryTree.h"

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
    addBT(tree, 0, "10");
    addBT(tree, 0, "10");
    addBT(tree, 4, "10");
    printNLR_BT(tree);
    printBoundNLR_BT(tree,4);
    destroyBinaryTree(tree);
    return 0;
}
