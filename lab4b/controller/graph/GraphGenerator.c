#include <stdio.h>
#include <stdlib.h>
#include "GraphGenerator.h"

#define DOT_HEADER "digraph tree {\n"
#define DOT_FOOTER "}"

void _writeNode(FILE *file, const Node *node) {
    fprintf(file, "\"[%d;%d]", node->border.x, node->border.y);
    Item *cursor = node->items;
    while (cursor != NULL) {
        fprintf(file, "\n(%d;%d)", cursor->key.x, cursor->key.y);
        cursor = cursor->next;
    }
    fprintf(file, "\"");
}

void _writeDotNLR(FILE *file, const Node *node, int *leaves) {
    if (node == NULL) return;
    } else {
        for (int i = 0; i < 4; ++i) {
            if (node->nodes[i] != NULL)
                _writeNode(file, node);
        }
        _writeDotNLR(file, node->left, leaves);
        _writeDotNLR(file, node->right, leaves);
    }

    int createPngGraph(const Tree *tree) {
        if (tree == NULL || tree->root == NULL) return 1;
        FILE *file = fopen("../output/tree.dot", "w");
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

