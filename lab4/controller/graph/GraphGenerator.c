#include <stdio.h>
#include <stdlib.h>
#include "GraphGenerator.h"

#define DOT_HEADER "digraph binaryTree {\n"
#define DOT_FOOTER "}"
#define DOT_EMPTY_LEAVE " %d.%d -> null%d[style=invis];\n"
#define DOT_EMPTY " null%d[style=invis];\n"
#define DOT_LEAVE " %d.%d -> %d.%d;\n"

void _writeDotNLR(FILE *file, const BNode *node, int *leaves) {
    if (node == NULL || (node->left == NULL && node->right == NULL)) return;
    if (node->left == NULL) {
        fprintf(file, DOT_EMPTY_LEAVE, node->key, node->generation, *leaves);
        (*leaves)++;
    } else {
        fprintf(file, DOT_LEAVE, node->key, node->generation, node->left->key, node->left->generation);
        fprintf(file, DOT_LEAVE, node->left->key, node->left->generation, node->left->parent->key, node->left->parent->generation);
    }
    if (node->right == NULL) {
        fprintf(file, DOT_EMPTY_LEAVE, node->key, node->generation, *leaves);
        (*leaves)++;
    } else {
        fprintf(file, DOT_LEAVE, node->key, node->generation, node->right->key, node->right->generation);
        fprintf(file, DOT_LEAVE, node->right->key, node->right->generation, node->right->parent->key, node->right->parent->generation);

    }
    _writeDotNLR(file, node->left, leaves);
    _writeDotNLR(file, node->right, leaves);
}

int createPngGraph(const BinaryTree *tree) {
    FILE *file = fopen("../output/binary_tree.dot", "w");
    if (file == NULL) return 1;
    fprintf(file, DOT_HEADER);
    int leaves = 0;
    _writeDotNLR(file, tree->root, &leaves);
    for (int i = 0; i < leaves; ++i) {
        fprintf(file, DOT_EMPTY, i);
    }
    fprintf(file, DOT_FOOTER);
    fclose(file);
    system("dot -Tpng -O ../output/binary_tree.dot");
    return 0;
}
