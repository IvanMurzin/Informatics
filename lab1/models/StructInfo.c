#include <stddef.h>
#include <stdlib.h>
#include "StructInfo.h"

struct StructInfo {
    size_t size;

    const char *( *toString)(void *);
};

size_t getStructSize(StructInfo *info) {
    if (!info) return -1;
    return info->size;
}

int setStructSize(StructInfo *info, size_t size) {
    if (!info) return 0;
    info->size = size;
    return 1;
}

const char *getStructString(StructInfo *info, void *data) {
    if (!info) return NULL;
    return info->toString(data);
}


StructInfo *getStructInfo(size_t size, const char *( *toString)(void *)) {
    StructInfo *info = (StructInfo *) malloc(size);
    info->size = size;
    info->toString = toString;
    return info;
}