#include <stdio.h>
#include <stdlib.h>
#include "GraphGenerator.h"

#define DOT_HEADER "digraph tree {\n"
#define DOT_FOOTER "}"

void _writeNode(FILE *file, const Node *node) {
    fprintf(file, "\"x∈[%d;%d]; y∈[%d;%d]", node->borderStart.x, node->borderEnd.x, node->borderStart.y, node->borderEnd.y);
    Item *cursor = node->items;
    while (cursor != NULL) {
        fprintf(file, "\n{%d;%d}", cursor->key.x, cursor->key.y);
        cursor = cursor->next;
    }
    fprintf(file, "\"");
}

void _writeDotNLR(FILE *file, const Node *node, int *leaves) {
    if (node == NULL) return;
    _writeNode(file, node);
    for (int i = 0; i < 4; ++i) {
        if (node->nodes[i] != NULL) {
            _writeNode(file, node);
            fprintf(file, " -> ");
            _writeNode(file, node->nodes[i]);
        }
    }
    for (int i = 0; i < 4; ++i) {
        _writeDotNLR(file, node->nodes[i], leaves);
    }
}

int createPngGraph(const Tree *tree) {
    if (tree == NULL || tree->root == NULL) return 1;
    FILE *file = fopen("../output/tree.dot", "w");
    if (file == NULL) return 1;
    fprintf(file, DOT_HEADER);
    int leaves = 0;

    _writeDotNLR(file, tree->root, &leaves);
//    for (int i = 0; i < leaves; ++i) {
//        fprintf(file, DOT_EMPTY, i);
//    }
    fprintf(file, DOT_FOOTER);
    fclose(file);
    system("dot -Tpng -O ../output/tree.dot");
    return 0;
}

