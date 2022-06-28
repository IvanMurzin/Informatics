#ifndef LAB4_GRAPHGENERATOR_H
#define LAB4_GRAPHGENERATOR_H

#include "BinaryTree.h"

typedef enum DrawMode {
    DEFAULT,
    PARENT,
    FLASHED,
    FLASHED_ONLY,
} DrawMode;

int createPngGraph(const BinaryTree *tree, DrawMode mode);

#endif
