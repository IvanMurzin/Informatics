#ifndef LOGGER_H
#define LOGGER_H

#include "Table.h"

int printKS1(KeySpace1 *table, int busyOnly);

int printSelectResultKS1(KeySpace1 *table, const Item *item);

int printKS2(KeySpace2 *table, int busyOnly);

int printTable(Table *table);

int printSelectResultKS2(KeySpace2 *table, const Item *item);

void handleResult(int result);

void printItem(Item *item);

#endif
