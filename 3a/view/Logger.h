#ifndef LOGGER_H
#define LOGGER_H

#include "Table.h"

int printKS1(const KeySpace1 *table, int busyOnly);

int printKS2(const KeySpace2 *table, int busyOnly);

int printTable(const Table *table);

void handleResult(int result);

void printItems(const Item *item);

#endif
