#ifndef DIALOG_H
#define DIALOG_H


#include "GraphGenerator.h"
#include <stdio.h>

int dialog(const char *messages[], int messageSize);

int D_Add(Tree *tree);

int D_Find(Tree *tree);

int D_FindMin(Tree *tree);

int D_DeleteByNumber(Tree *tree);

int D_Delete(Tree *tree);

int D_Draw(Tree *tree);

int D_DrawReverse(Tree *tree);

int D_Mock(Tree *tree);

#endif
