#include <stdlib.h>
#include "BinaryTree.h"
#include "GraphGenerator.h"

BinaryTree *getBinaryTree() {
    return calloc(1, sizeof(BinaryTree));
}

void _putBoundElements(const BNode *root, unsigned key, BinaryTree *to) {
    if (root == NULL) return;
    if (root->key <= key) addBT(to, root->key, root->data);
    _putBoundElements(root->left, key, to);
    _putBoundElements(root->right, key, to);
}

BinaryTree *getBoundBinaryTree(const BinaryTree *tree, unsigned int key) {
    BinaryTree *newTree = getBinaryTree();
    _putBoundElements(tree->root, key, newTree);
    return newTree;
}

int addBT(BinaryTree *tree, unsigned int key, const char *data) {
    if (tree == NULL) return 1;
    tree->size++;
    BNode *newNode = getBNode(key, data);
    if (tree->root == NULL) {
        tree->root = newNode;
        return 0;
    }
    BNode *ptr = tree->root;
    BNode *parent;
    while (ptr != NULL) {
        parent = ptr;
        if (ptr->key >= key) {
            if (ptr->key == key) ptr->generation++;
            ptr = ptr->left;
        } else {
            ptr = ptr->right;
        }
    }
    newNode->parent = parent;
    if (parent->key >= key) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
    BNode *tmp = newNode;
    ptr = tmp->parent;
    while (ptr != NULL && tmp == ptr->right) {
        tmp = ptr;
        ptr = tmp->parent;
    }
    newNode->next = ptr;
    return 0;
}

int deleteBT(BinaryTree *tree, unsigned int key) {
    exit(-1);
    return 0;
}

int printBoundNLR_BT(const BinaryTree *tree, unsigned key) {
    if (tree == NULL) return 1;
    BinaryTree *printTree = getBoundBinaryTree(tree, key);
    createPngGraph(printTree);
    destroyBinaryTree(printTree);
    return 0;
}

int printNLR_BT(const BinaryTree *tree) {
    if (tree == NULL) return 1;
    createPngGraph(tree);
    return 0;
}

int findBT(const BinaryTree *tree, unsigned int key, int **result, int *size) {
    exit(-1);
    return 0;
}

int findMinBT(const BinaryTree *tree, int **result, int *size) {
    exit(-1);
    return 0;
}

void _destroyBNode(BNode *node) {
    if (node == NULL) return;
    _destroyBNode(node->left);
    _destroyBNode(node->right);
    free(node);
}

void destroyBinaryTree(BinaryTree *tree) {
    _destroyBNode(tree->root);
    free(tree);
}

void _destroyBNodeDeep(BNode *node) {
    if (node == NULL) return;
    _destroyBNode(node->left);
    _destroyBNode(node->right);
    free((char *) node->data);
    free(node);
}

void destroyBinaryTreeDeep(BinaryTree *tree) {
    _destroyBNodeDeep(tree->root);
    free(tree);
}
