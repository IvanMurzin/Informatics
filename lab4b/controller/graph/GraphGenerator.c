#include <stdio.h>
#include <stdlib.h>
#include "GraphGenerator.h"

#define DOT_HEADER "digraph tree {\n"
#define DOT_FOOTER "}"

void _writeNode(FILE *file, const Node *node) {
    fprintf(file, "\"x∈[%d;%d]; y∈[%d;%d]", node->borderStart.x, node->borderEnd.x, node->borderStart.y, node->borderEnd.y);
    Item *cursor = node->items;
    while (cursor != NULL) {
        fprintf(file, "\n{%d;%d} №%d", cursor->key.x, cursor->key.y, cursor->number);
        cursor = cursor->next;
    }
    fprintf(file, "\"");
}

void _writeDotNLR(FILE *file, const Node *node) {
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
        _writeDotNLR(file, node->nodes[i]);
    }
}

void _writeDotLRN(FILE *file, const Node *node) {
    if (node == NULL) return;
    for (int i = 3; i >= 0; --i) {
        _writeDotLRN(file, node->nodes[i]);
    }
    _writeNode(file, node);
    for (int i = 3; i >= 0; --i) {
        if (node->nodes[i] != NULL) {
            _writeNode(file, node);
            fprintf(file, " -> ");
            _writeNode(file, node->nodes[i]);
        }
    }
}

int createPngGraph(const Tree *tree, int isNLR) {
    if (tree == NULL || tree->root == NULL) return 1;
    FILE *file = fopen("../output/tree.dot", "w");
    if (file == NULL) return 1;
    fprintf(file, DOT_HEADER);
    isNLR ? _writeDotNLR(file, tree->root) : _writeDotLRN(file, tree->root);
    fprintf(file, DOT_FOOTER);
    fclose(file);
    system("dot -Tpng -O ../output/tree.dot");
    return 0;
}

