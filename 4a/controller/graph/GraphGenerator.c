#include <stdio.h>
#include <stdlib.h>
#include "GraphGenerator.h"

#define DOT_HEADER "digraph binaryTree {\n"
#define DOT_FOOTER "}"
#define DOT_EMPTY_LEAVE " %d.%d -> null%d[style=invis];\n"
#define DOT_EMPTY " null%d[style=invis];\n"
#define DOT_LEAFE " %d.%d -> %d.%d;\n"
#define DOT_LEAVE_FLASHED " %d.%d -> %d.%d[style=dotted];\n"

void _writeDotNLR(FILE *file, const BNode *node, int *leaves, DrawMode mode) {
    if (node == NULL) return;
    if (node->left == NULL) {
        if (mode != FLASHED_ONLY) fprintf(file, DOT_EMPTY_LEAVE, node->key, node->generation, *leaves);
        (*leaves)++;
    } else {
        if (mode != FLASHED_ONLY)fprintf(file, DOT_LEAFE, node->key, node->generation, node->left->key, node->left->generation);
        if (mode == PARENT)
            fprintf(file, DOT_LEAFE, node->left->key, node->left->generation, node->left->parent->key, node->left->parent->generation);

    }
    if (node->right == NULL) {
        if (mode != FLASHED_ONLY)fprintf(file, DOT_EMPTY_LEAVE, node->key, node->generation, *leaves);
        (*leaves)++;
    } else {
        if (mode != FLASHED_ONLY)fprintf(file, DOT_LEAFE, node->key, node->generation, node->right->key, node->right->generation);
        if (mode == PARENT)
            fprintf(file, DOT_LEAFE, node->right->key, node->right->generation, node->right->parent->key, node->right->parent->generation);

    }
    if ((mode == FLASHED || mode == FLASHED_ONLY) && node->next != NULL)
        fprintf(file, DOT_LEAVE_FLASHED, node->key, node->generation, node->next->key, node->next->generation);
    _writeDotNLR(file, node->left, leaves, mode);
    _writeDotNLR(file, node->right, leaves, mode);
}

int createPngGraph(const BinaryTree *tree, DrawMode mode) {
    if (tree == NULL || tree->root == NULL) return 1;
    FILE *file = fopen("../output/binary_tree.dot", "w");
    if (file == NULL) return 1;
    fprintf(file, DOT_HEADER);
    int leaves = 0;

    fprintf(file, "%d.%d", tree->root->key, tree->root->generation);
    _writeDotNLR(file, tree->root, &leaves, mode);
    for (int i = 0; i < leaves; ++i) {
        fprintf(file, DOT_EMPTY, i);
    }
    fprintf(file, DOT_FOOTER);
    fclose(file);
    system("dot -Tpng -O ../output/binary_tree.dot");
    return 0;
}
