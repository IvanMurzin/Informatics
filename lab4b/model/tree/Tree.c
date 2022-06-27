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
    Item *newItem = getItem(key, data);
    if (tree->root == NULL) {
        tree->root = getNode(getHalf(tree->max));
    }
    Node *ptr = tree->root;
    while (ptr != NULL) {
        if (ptr->itemSize < tree->N) {
            Item *cursor = ptr->items;
            if (cursor == NULL) {
                ptr->items = newItem;
            } else {
                while (cursor->next != NULL) cursor = cursor->next;
                cursor->next = newItem;
            }
            ptr->itemSize++;
            return 0;
        }
        int direction = getDirection(ptr->border, newItem->key);
        if (ptr->nodes[direction] == NULL) {
            Key newBorder = getHalf(ptr->border);
            if (equalsKey(newBorder, ptr->border)) {
                destroyItem(newItem);
                return 1;
            }
            ptr->nodes[direction] = getNode(newBorder);
            ptr->nodes[direction]->parent = ptr;
        }
        ptr = ptr->nodes[direction];
    }
    return 0;
}

