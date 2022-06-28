#include <stdlib.h>
#include <stdio.h>
#include "Tree.h"

Tree *getTree(Key max, int N) {
    Tree *tree = calloc(1, sizeof(Tree));
    tree->max = max;
    tree->N = N;
    return tree;
}

int addToNode(Node *node, Item *newItem, int N) {
    Node *ptr = node;
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
        if (ptr->itemSize < N) {
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
            Key newStart = getNewStartBorder(ptr->borderStart, ptr->borderEnd, direction);
            Key newEnd = getNewEndBorder(ptr->borderStart, ptr->borderEnd, direction);
            ptr->nodes[direction] = getNode(newStart, newEnd);
            ptr->nodes[direction]->parent = ptr;
        }
        ptr = ptr->nodes[direction];
    }
    return 0;
}

int add(Tree *tree, Key key, const char *data) {
    if (tree == NULL) return 1;
    if (greaterKey(tree->max, key)) {
        free((char *) data);
        return 2;
    }
    Item *newItem = getItem(key, data);
    if (tree->root == NULL) {
        tree->root = getNode(getKey(0, 0), tree->max);
    }
    return addToNode(tree->root, newItem, tree->N);
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

Item *_getVictim(Node *node) {
    Item *victim = NULL;
    Node *ptr = node;
    int index;
    while (ptr != NULL) {
        index = firstNotNullIndex(ptr->nodes, 4);
        if (ptr->nodes[index]->itemSize == 1) {
            if (isAllNull(ptr->nodes[index]->nodes, 4)) {
                victim = getItemCopy(ptr->nodes[index]->items);
                destroyItem(ptr->nodes[index]->items);
                ptr->nodes[index] = NULL;
                return victim;
            }
            ptr = ptr->nodes[index];
        } else {
            victim = getItemCopy(ptr->nodes[index]->items);
            deleteFromList(&ptr->nodes[index]->items, victim->key, victim->number);
            ptr->nodes[index]->itemSize--;
            return victim;
        }
    }
    return NULL;
}

int delete(Tree *tree, Key key, int number) {
    if (tree == NULL || tree->root == NULL) return 1;
    Node *ptr = tree->root;
    Item *result;
    int direction;
    while (ptr != NULL) {
        if (contains(ptr->items, key, number, &result)) {
            if (ptr->itemSize > 1) {
                deleteFromList(&ptr->items, key, number);
                ptr->itemSize--;
                return 0;
            }
            if (isAllNull(ptr->nodes, 4)) {
                destroyItem(ptr->items);
                if (ptr->parent == NULL) {
                    tree->root = NULL;
                } else {
                    ptr->parent->nodes[direction] = NULL;
                }
                free(ptr);
                return 0;
            }
            Item *victim = _getVictim(ptr);
            destroyItem(ptr->items);
            ptr->items = victim;
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

