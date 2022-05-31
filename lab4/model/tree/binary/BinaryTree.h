#ifndef LAB4_BINARYTREE_H
#define LAB4_BINARYTREE_H

#include "BNode.h"

typedef struct BinaryTree {
    int size;
    BNode *root;
} BinaryTree;

BinaryTree *getBinaryTree();

BinaryTree *getBoundBinaryTree(const BinaryTree *tree, unsigned key);

/*
 * Добавление нового элемента в дерево без нарушения свойств упорядоченности.
 */
int addBT(BinaryTree *tree, unsigned key, const char *data);

/*
 * Удаление элемента, заданного своим ключом, без нарушения свойств упорядоченности дерева.
 * Если в дереве присутствуют несколько элементов с указанным ключом,
 * то необходимо удалить наиболее старый из них.
 */
int deleteBT(BinaryTree *tree, unsigned key);

/*
 * Вывод содержимого дерева в прямом порядке следования ключей,
 * не превышающих заданный (если ключ не указан — вывод содержимого всего дерева).
 */
int printBoundNLR_BT(const BinaryTree *tree, unsigned key);

int printNLR_BT(const BinaryTree *tree);

/*
 * Поиск информации по заданному ключу.
 * Если элементов с требуемым значением ключа может быть несколько,
 * то необходимо в качестве результата вернуть их все.
 * Возврат необходимо осуществлять при помощи вектора указателей,
 * возврат копий элементов не допускается.
 */
int findBT(const BinaryTree *tree, unsigned key, BNode ***result, int *size);

/*
 * Поиск элемента c наименьшим значением ключа
 * (если таких элементов несколько — действовать по аналогии с операцией поиска по ключу)
 */
int findMinBT(const BinaryTree *tree, BNode ***result, int *size);

void destroyBinaryTree(BinaryTree *tree);

#endif