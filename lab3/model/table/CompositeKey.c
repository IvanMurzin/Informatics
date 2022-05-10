#include "CompositeKey.h"

CompositeKey getSimpleCompositeKey(const char *stringKey1, const char *stringKey2) {
    Key key1 = {stringKey1, 0};
    Key key2 = {stringKey2, 0};
    CompositeKey key = {key1, key2, 0};
    return key;
}
