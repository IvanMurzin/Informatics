#ifndef LOGGER_H
#define LOGGER_H

#include "KeySpace1.h"

int printKS1(KeySpace1 *table, int busyOnly);

int printFindResultKS1(Key key, int result);

int printSelectResultKS1(KeySpace1 *table,const Item *item);

#endif