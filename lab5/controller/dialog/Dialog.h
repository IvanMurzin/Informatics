#ifndef DIALOG_H
#define DIALOG_H


#include "GraphGenerator.h"
#include <stdio.h>

int dialog(const char *messages[], int messageSize);

int D_AddVertex(Matrix *matrix);

int D_AddEdge(Matrix *matrix);

int D_FindPath(Matrix *matrix);

int D_FindShortestPath(Matrix *matrix);

int D_DeleteVertex(Matrix *matrix);

int D_DeleteEdge(Matrix *matrix);

int D_Show(Matrix *matrix);

int D_ShowSkeleton(Matrix *matrix);

#endif
