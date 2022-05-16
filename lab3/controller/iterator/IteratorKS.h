#ifndef ITERATORKS1_H
#define ITERATORKS1_H

#include "Table.h"

int hasNext(const Item *item);

Item *next(const Item *item);

int hasNextItem1(const Item *item);

Item *nextItem1(KeySpace1 *table, const Item *item);

int hasNextItem2(const Item *item);

Item *nextItem2(KeySpace2 *table, const Item *item);

#endif
