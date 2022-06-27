#ifndef DIALOG_H
#define DIALOG_H


#include "GraphGenerator.h"
#include <stdio.h>

int dialog(const char *messages[], int messageSize);

int D_AddBT(Tree *tree);

int D_FindBT(Tree *tree);

int D_DeleteBT(Tree *tree);

int D_ShowBT(Tree *tree);

int D_MockBT(Tree *tree);

int D_GetFromFile(Tree **tree);

#endif
