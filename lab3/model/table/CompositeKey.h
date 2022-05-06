#ifndef COMPOSITEKEY_H
#define COMPOSITEKEY_H

#include "Key2.h"
#include "Key1.h"

typedef struct CompositeKey{
    Key1* key1;
    Key2* key2;
} CompositeKey;
#endif
