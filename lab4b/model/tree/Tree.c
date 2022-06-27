#include <stdlib.h>
#include "Tree.h"

Tree *getTree(Key max, int N) {
    Tree *tree = calloc(1, sizeof(Tree));
    tree->max = max;
    tree->N = N;
    return tree;
}


int add(Tree *tree, Key key, const char *data) {
    if (tree == NULL) return 1;
    if (greaterKey(tree->max, key)) return 1;
    Item *newItem = getItem(key, data);
    if (tree->root == NULL) {
        tree->root = getNode(getKey(0, 0), tree->max);
    }
    Node *ptr = tree->root;
    while (ptr != NULL) {
        if (outOfBorder(ptr->borderStart, ptr->borderEnd, key)) {
            destroyItem(newItem);
            return 1;
        }
        if (ptr->items == NULL) {
            ptr->items = newItem;
            ptr->itemSize = 1;
            return 0;
        }
        if (ptr->itemSize < tree->N) {
            putSorted(&ptr->items, newItem);
            ptr->itemSize++;
            return 0;
        }
        if (equalsKey(ptr->borderStart, ptr->borderEnd)) {
            destroyItem(newItem);
            return 1;
        }
        int direction = getDirection(ptr->borderStart, ptr->borderEnd, newItem->key);
        if (ptr->nodes[direction] == NULL) {
            Key newStart = getNewStartBorder(ptr->borderStart, ptr->borderEnd, direction);
            Key newEnd = getNewEndBorder(ptr->borderStart, ptr->borderEnd, direction);
            ptr->nodes[direction] = getNode(newStart, newEnd);
            ptr->nodes[direction]->parent = ptr;
        }
        ptr = ptr->nodes[direction];
    }
    return 0;
}

int find(const Tree *tree, unsigned int key, Item ***result, int *size) {
    return 0;
}

void _destroyNodeNLR(Node *node) {
    if (node == NULL) return;
    for (int i = 0; i < 4; ++i) {
        _destroyNodeNLR(node->nodes[i]);
    }
    destroyNode(node);
}

void destroyQTree(Tree *tree) {
    _destroyNodeNLR(tree->root);
    free(tree);
}

