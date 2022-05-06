#include <string.h>
#include "Key.h"

int equalsKey1(Key first, Key second) {
    return (first.version == second.version) && !strcmp(first.value, second.value);
}

int equalsKey1Values(const char *first, const char *second) {
    return !strcmp(first, second);
}

int compareKey1(Key first, Key second) {
    return strcmp(first.value, second.value);
}
