#ifndef LAB4_BINARYTREE_H
#define LAB4_BINARYTREE_H

#include "Node.h"

enum DrawMode;

typedef struct Tree {
    int N;
    Key max;
    Node *root;
} Tree;

Tree *getTree(Key max);

/*
 * Добавление нового элемента в дерево без нарушения свойств упорядоченности.
 */
int add(Tree *tree, Key key, const char *data);

/*
 * Удаление элемента, заданного своим ключом, без нарушения свойств упорядоченности дерева.
 */
int delete(Tree *tree, unsigned key);

/*
 * Вывод содержимого дерева в прямом порядке следования ключей,
 * не превышающих заданный (если ключ не указан — вывод содержимого всего дерева).
 */
int printBoundNLR(const Tree *tree, unsigned key, enum DrawMode mode);

int printNLR(const Tree *tree, enum DrawMode mode);

/*
 * Поиск информации по заданному ключу.
 * Если элементов с требуемым значением ключа может быть несколько,
 * то необходимо в качестве результата вернуть их все.
 * Возврат необходимо осуществлять при помощи вектора указателей,
 * возврат копий элементов не допускается.
 */
int find(const Tree *tree, unsigned key, Item ***result, int *size);

/*
 * Поиск элемента c наименьшим значением ключа
 * (если таких элементов несколько — действовать по аналогии с операцией поиска по ключу)
 */
int findMin(const Tree *tree, Item ***result, int *size);

void destroyQTree(Tree *tree);

void destroyQTreeDeep(Tree *tree);

#endif
// todo если сломаю тебе лабу - ты напишешь мне мою 4б. Подпись: dick(Дмитрий Иванович Ckуплинов)