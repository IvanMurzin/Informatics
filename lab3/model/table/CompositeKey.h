#ifndef COMPOSITEKEY_H
#define COMPOSITEKEY_H

#include "Key2.h"
#include "model/keyspace/key/Key.h"

typedef struct CompositeKey{
    Key* key1;
    Key2* key2;
} CompositeKey;
#endif
