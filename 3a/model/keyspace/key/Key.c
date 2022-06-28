#include <string.h>
#include <stdlib.h>
#include "Key.h"


int compareKey(Key first, Key second) {
    return strcmp(first.value, second.value);
}

Key getKey(const char *value) {
    Key result = {value};
    return result;
}

int equalsKey(Key first, Key second) {
    return !compareKey(first, second);
}

Key getMockKey(const char *value) {
    Key result;
    char *data = malloc(strlen(value) + 1);
    strcpy(data, value);
    result.value = data;
    return result;
}

void destroyKey(Key key) {
    free((char *) key.value);
}
