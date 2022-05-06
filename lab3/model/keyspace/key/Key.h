#ifndef KEY1_H
#define KEY1_H
typedef struct Key {
    const char *value;
    int version;
} Key;

int equalsKey(Key first, Key second);

int compareKey(Key first, Key second);

int equalsKeyValues(const char *first, const char *second);

#endif
