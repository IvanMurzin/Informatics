#ifndef KEY1_H
#define KEY1_H
typedef struct Key {
    const char *value;
    int version;
} Key;

int equalsKey1(Key first, Key second);

int compareKey1(Key first, Key second);

int equalsKey1Values(const char *first, const char *second);

#endif
