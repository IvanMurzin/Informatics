#include <string.h>
#include "Key1.h"

int equalsKey1(Key1 first, Key1 second) {
    return (first.version == second.version) && !strcmp(first.value, second.value);
}

int equalsKey1Values(const char * first, const char * second) {
    return !strcmp(first, second);
}
