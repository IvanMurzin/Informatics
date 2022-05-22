#include <stdlib.h>
#include <string.h>
#include "CompositeKey.h"

CompositeKey getCompositeKey(const char *stringKey1, const char *stringKey2) {
    Key key1 = getKey(stringKey1);
    Key key2 = getKey(stringKey2);
    CompositeKey key = {key1, key2};
    return key;
}

CompositeKey getSimpleCompositeKey(const char *stringKey1, const char *stringKey2) {
    return getCompositeKey(stringKey1, stringKey2);
}


CompositeKey getKeyCopy(CompositeKey key) {
    char *key1Copy = malloc(strlen(key.key1.value) + 1);
    strcpy(key1Copy, key.key1.value);
    char *key2Copy = malloc(strlen(key.key2.value) + 1);
    strcpy(key2Copy, key.key2.value);
    return getCompositeKey(key1Copy, key2Copy);
}
