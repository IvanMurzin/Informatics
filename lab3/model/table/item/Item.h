#ifndef ITEM_H
#define ITEM_H

#include "Info.h"

typedef struct Item {
    Info *info;
    int release;
    struct Item *next;
} Item;
#endif
