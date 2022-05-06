#ifndef KEY1_H
#define KEY1_H
typedef struct Key1 {
    const char *value;
    int version;
} Key1;

int equalsKey1(Key1 first, Key1 second);

int compareKey1(Key1 first, Key1 second);

int equalsKey1Values(const char *first, const char *second);

#endif
