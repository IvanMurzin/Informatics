#ifndef KEY1_H
#define KEY1_H
typedef struct Key {
    const char *value;
} Key;

int equalsKey(Key first, Key second);

int compareKey(Key first, Key second);

int equalsKeyValues(const char *first, const char *second);

Key getKey(const char *value);

Key getMockKey(const char *value);

void destroyKey(Key key);

#endif