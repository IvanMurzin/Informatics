#ifndef LOGGER_H
#define LOGGER_H

#include "KeySpace1.h"
#include "KeySpace2.h"

int printKS1(KeySpace1 *table, int busyOnly);

int printSelectResultKS1(KeySpace1 *table, const Item *item);

int printKS2(KeySpace2 *table, int busyOnly);

int printSelectResultKS2(KeySpace2 *table, const Item *item);

#endif
