#ifndef LOGGER_H
#define LOGGER_H

#include "Table.h"

int printKS1(KeySpace1 *table, int busyOnly);

int printKS2(KeySpace2 *table, int busyOnly);

int printTable(Table *table);

void handleResult(int result);

void printItems(Item *item);

#endif
