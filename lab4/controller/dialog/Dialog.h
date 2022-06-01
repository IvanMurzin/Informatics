#ifndef DIALOG_H
#define DIALOG_H


#include "GraphGenerator.h"
#include <stdio.h>

int dialog(const char *messages[], int messageSize);

int D_AddBT(BinaryTree *tree);

int D_FindBT(BinaryTree *tree);

int D_DeleteBT(BinaryTree *tree);

int D_ShowBT(BinaryTree *tree);

int D_MockBT(BinaryTree *tree);

#endif
