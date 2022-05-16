#ifndef KEY1_H
#define KEY1_H
typedef struct Key {
    char *value;
    int version;
} Key;

int equalsKey(Key first, Key second);

int compareKey(Key first, Key second);

int equalsKeyValues(const char *first, const char *second);

Key getSimpleKey(const char *value);

#endif
