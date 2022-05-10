#ifndef COMPOSITEKEY_H
#define COMPOSITEKEY_H

#include "Key.h"

typedef struct CompositeKey {
    Key key1;
    Key key2;
    int version;
} CompositeKey;

CompositeKey getSimpleCompositeKey(const char *stringKey1, const char *stringKey2);

#endif
