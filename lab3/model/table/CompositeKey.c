#include <stdlib.h>
#include <string.h>
#include <printf.h>
#include "CompositeKey.h"

CompositeKey getCompositeKey(const char *stringKey1, const char *stringKey2, int version) {
    Key key1 = getSimpleKey(stringKey1);
    Key key2 = getSimpleKey(stringKey2);
    CompositeKey key = {key1, key2, version};
    return key;
}

CompositeKey getSimpleCompositeKey(const char *stringKey1, const char *stringKey2) {
    return getCompositeKey(stringKey1, stringKey2, 0);
}

int compositeKeyEqualsValues(CompositeKey key1, CompositeKey key2) {
    return equalsKeyValues(key1.key1.value, key2.key1.value) && equalsKeyValues(key1.key2.value, key2.key2.value);
}

CompositeKey getKeyCopy(CompositeKey key) {
    char *key1Copy = malloc(strlen(key.key1.value) + 1);
    strcpy(key1Copy, key.key1.value);
    char *key2Copy = malloc(strlen(key.key2.value) + 1);
    strcpy(key2Copy, key.key2.value);
    return getCompositeKey(key1Copy, key2Copy, key.version);
}
