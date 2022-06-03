#ifndef DIALOG_H
#define DIALOG_H

#include "Logger.h"
#include "Table.h"

int dialog(const char *messages[], int messageSize);

int D_Add(const Table *table);

int D_Find(Table *table);

int D_FindByKey1(Table *table);

int D_FindByKey2(Table *table);

int D_Delete(Table *table);

int D_DeleteByKey1(Table *table);

int D_DeleteByKey2(Table *table);

int D_DeleteByRangeKey1(Table *table);

int D_Show(Table *table);

int D_Mock(Table *table);

int D_CollectGarbage(Table *table);

#endif
