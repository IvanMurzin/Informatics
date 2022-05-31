#include <stdlib.h>
#include "BinaryTree.h"
#include "GraphGenerator.h"

BinaryTree *getBinaryTree() {
    return calloc(1, sizeof(BinaryTree));
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

int _findMinNodeBT(BNode *ptr, BNode ***result, int *size) {
    BNode *parent;
    while (ptr != NULL) {
        parent = ptr;
        ptr = ptr->left;
    }
    int minKey = parent->key;
    while (parent->parent != NULL && parent->parent->key == minKey) {
        parent = parent->parent;
    }
    *result = malloc(sizeof(BNode *) * (parent->generation + 1));
    *size = parent->generation + 1;
    while (parent != NULL) {
        (*result)[parent->generation] = parent;
        parent = parent->left;
    }
    return 0;
}

int findMinBT(const BinaryTree *tree, BNode ***result, int *size) {
    if (tree == NULL || tree->root == NULL) return 1;
    return _findMinNodeBT(tree->root, result, size);
}


int deleteBT(BinaryTree *tree, unsigned int key) {
    int size;
    BNode **targetsArray;
    int findRes = findBT(tree, key, &targetsArray, &size);
    if (findRes) return findRes;
    BNode *target = targetsArray[size - 1];
    free(targetsArray);
    if (target->left == NULL && target->right == NULL) {
        if (tree->root == target) {
            tree->root = NULL;
            free(target);
            //        free((char *)target->data) // todo replace with deep
            return 0;
        }
        if (target->parent->left == target) {
            target->parent->left = NULL;
        } else {
            target->parent->right = NULL;
        }
        free(target);
//        free((char *)target->data) // todo replace with deep
        return 0;
    }
    if (target->left == NULL) { // target->right != NULL
        if (tree->root == target) {
            tree->root = target->right;
            free(target);
            //        free((char *)target->data) // todo replace with deep
            return 0;
        }
        if (target->parent->left == target) {
            target->parent->left = target->right;
        } else {
            target->parent->right = target->right;
        }
        target->right->parent = target->parent;
        free(target);
        //        free((char *)target->data) // todo replace with deep
        return 0;
    }
    if (target->right == NULL) { // target->left != NULL
        if (tree->root == target) {
            tree->root = target->left;
            free(target);
            //        free((char *)target->data) // todo replace with deep
            return 0;
        }
        if (target->parent->left == target) {
            target->parent->left = target->left;
        } else {
            target->parent->right = target->left;
        }
        target->left->parent = target->parent;
        free(target);
        //        free((char *)target->data) // todo replace with deep
        return 0;
    }
    // target->right != NULL && target->left != NULL
    BNode **minData;
    int minDataSize = 0;
    _findMinNodeBT(target->right, &minData, &minDataSize);
    BNode *victim = minData[minDataSize - 1];

    if (victim->parent != target && victim->parent->left == victim) {
        if (minDataSize == 1) {
            victim->parent->left = NULL;
        } else {
            victim->parent->left = victim->right;
            victim->right->parent = victim->parent;
        }
    }

    if (victim->parent != target) {
        victim->right = target->right;
        target->right->parent = victim;
    }

    if (victim->parent == target && victim->left != NULL || minDataSize != 1) {
        BNode *ptr = victim->left;
        BNode *parent;
        while (ptr != NULL) {
            parent = ptr;
            ptr = ptr->left;
        }
        target->left->parent = parent;
        parent->left = target->left;
    } else {
        victim->left = target->left;
        target->left->parent = victim;
    }
    if (target->parent != NULL) {
        if (target->parent->left == target) {
            target->parent->left = victim;
        } else {
            target->parent->right = victim;
        }
        victim->parent = target->parent;
    }
    if (tree->root == target) tree->root = victim;
    free(target);
    free(minData);
    //free((char *)target->data) // todo replace with deep
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

int findBT(const BinaryTree *tree, unsigned int key, BNode ***result, int *size) {
    if (tree == NULL || tree->root == NULL) return 1;
    BNode *ptr = tree->root;
    int found = 0;
    while (ptr != NULL) {
        if (ptr->key == key) {
            if (!found) {
                *result = malloc(sizeof(BNode *) * (ptr->generation + 1));
                *size = ptr->generation + 1;
                found = 1;
            }
            (*result)[ptr->generation] = ptr;
            if (ptr->generation == 0) return 0;
        }
        if (ptr->key >= key) {
            ptr = ptr->left;
        } else {
            ptr = ptr->right;
        }
    }
    if (found == 0) return 1;
    return 0;
}