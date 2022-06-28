#include <stdlib.h>
#include <stdio.h>
#include "Tree.h"

Tree *getTree(Key start, Key end, int N) {
    Tree *tree = calloc(1, sizeof(Tree));
    tree->start = start;
    tree->end = end;
    tree->N = N;
    return tree;
}

void _addLRN(Tree *src, const Node *node) {
    if (node == NULL) return;
    for (int i = 3; i >= 0; --i) {
        _addLRN(src, node->nodes[i]);
    }
    for (int i = 3; i >= 0; --i) {
        if (node->nodes[i] != NULL) {
            Item *cursor = node->nodes[i]->items;
            while (cursor != NULL) {
                Item *newItem = getItemCopy(cursor);
                add(src, newItem->key, newItem->data);
                cursor = cursor->next;
            }
        }
    }
}

Tree *getNewTree(Tree *tree, Key start, Key end) {
    Tree *result = getTree(start, end, tree->N);
    _addLRN(result, tree->root);
    return result;
}

void _divideTree(Node *node) {
    if (node->nodes[0] == NULL) {
        getNodes(node->borderStart, node->borderEnd, node->nodes);
        return;
    }
    for (int i = 0; i < 4; ++i) {
        _divideTree(node->nodes[i]);
    }
}

int add(Tree *tree, Key key, const char *data) {
    if (tree == NULL) return 1;
    if (outOfBorder(tree->start, tree->end, key)) {
        free((char *) data);
        return 2;
    }
    Item *newItem = getItem(key, data);
    if (tree->root == NULL) {
        tree->root = getNode(tree->start, tree->end);
    }
    Node *ptr = tree->root;
    while (ptr != NULL) {
        if (outOfBorder(ptr->borderStart, ptr->borderEnd, newItem->key)) {
            destroyItem(newItem);
            return 2;
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
            return 3;
        }
        int maxNum = maxNumber(ptr->items, newItem->key);
        if (maxNum > 0) {
            newItem->number = newItem->number > (maxNum + 1) ? newItem->number : (maxNum + 1);
        }
        int direction = getDirection(ptr->borderStart, ptr->borderEnd, newItem->key);
        if (ptr->nodes[direction] == NULL) {
            _divideTree(tree->root);
            ptr->nodes[direction]->parent = ptr;
        }

        ptr = ptr->nodes[direction];
    }
    return 0;
}

int find(const Tree *tree, Key key, int number, Item **result) {
    Node *ptr = tree->root;
    while (ptr != NULL) {
        if (contains(ptr->items, key, number, result)) return 0;
        int direction = getDirection(ptr->borderStart, ptr->borderEnd, key);
        ptr = ptr->nodes[direction];
    }
    return 1;
}

int findMin(const Tree *tree, Item **result) {
    if (tree == NULL || tree->root == NULL) return 1;
    Node *ptr = tree->root;
    while (ptr->nodes[0] != NULL) {
        ptr = ptr->nodes[0];
    }
    *result = ptr->items;
    return 0;
}

int delete(Tree *tree, Key key, int number) {
    if (tree == NULL || tree->root == NULL) return 1;
    Node *ptr = tree->root;
    Item *result;
    int direction;
    while (ptr != NULL) {
        if (contains(ptr->items, key, number, &result)) {
            deleteFromList(&ptr->items, key, number);
            ptr->itemSize--;
            return 0;
        }
        direction = getDirection(ptr->borderStart, ptr->borderEnd, key);
        ptr = ptr->nodes[direction];
    }
    return 1;
}

int getMaxNumber(Tree *tree, Key key) {
    Node *ptr = tree->root;
    int max = -1;
    int num;
    while (ptr != NULL && !outOfBorder(ptr->borderStart, ptr->borderEnd, key)) {
        num = maxNumber(ptr->items, key);
        if (num > 0) {
            if (max < num) max = num;
        }
        int direction = getDirection(ptr->borderStart, ptr->borderEnd, key);
        ptr = ptr->nodes[direction];
    }
    return max;
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
