typedef struct StructInfo StructInfo;

size_t getStructSize(StructInfo *info);

int setStructSize(StructInfo *info, size_t size);

const char *getStructString(StructInfo *info, void *data);

StructInfo *getStructInfo(size_t size, const char *( *toString)(void *));