#ifndef KEYSPACE1CONTROLLER_H
#define KEYSPACE1CONTROLLER_H

#include "KeySpace1.h"

int putToKS1(KeySpace1 *table, const char *stringKey, const char *stringData);

int selectFromKS1(KeySpace1 *table, const char *stringKey);

int deleteAllKS1(KeySpace1 *table, const char *stringKey);

int deleteByRangeKS1(KeySpace1 *table, const char *floor, const char *selling);

#endif
