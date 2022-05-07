#ifndef COMPOSITEKEY_H
#define COMPOSITEKEY_H

#include "Key.h"

typedef struct CompositeKey {
    Key *key1;
    Key *key2;
} CompositeKey;
#endif
