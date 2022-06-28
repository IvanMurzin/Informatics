#ifndef LAB4_BINARYTREE_H
#define LAB4_BINARYTREE_H

#include "Node.h"

enum DrawMode;

typedef struct Tree {
    int N;
    Key max;
    Node *root;
} Tree;

Tree *getTree(Key max, int N);

int add(Tree *tree, Key key, const char *data);

int find(const Tree *tree, Key key, int number, Item **result);

int findMin(const Tree *tree, Item **result);

int delete(Tree *tree, Key key, int number);

int getMaxNumber(Tree *tree, Key key);

void destroyQTree(Tree *tree);

#endif