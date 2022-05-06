#include <string.h>
#include "Key.h"

int equalsKey(Key first, Key second) {
    return (first.version == second.version) && !strcmp(first.value, second.value);
}

int equalsKeyValues(const char *first, const char *second) {
    return !strcmp(first, second);
}

int compareKey(Key first, Key second) {
    return strcmp(first.value, second.value);
}
