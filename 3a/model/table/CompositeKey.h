#ifndef COMPOSITEKEY_H
#define COMPOSITEKEY_H

#include "Key.h"

typedef struct CompositeKey {
    Key key1;
    Key key2;
} CompositeKey;

CompositeKey getCompositeKey(const char *stringKey1, const char *stringKey2);

CompositeKey getKeyCopy(CompositeKey key);

int equalsCompositeKey(CompositeKey key1, CompositeKey key2);

#endif