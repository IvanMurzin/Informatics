#ifndef KEYSPACE2_H
#define KEYSPACE2_H

#include "Item.h"

typedef struct KeySpace2 {
    int maxSize;
    int currentSize;
    int (*hash)(const char * data);
    Item **table;
} KeySpace1;

#endif
