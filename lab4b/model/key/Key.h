#ifndef LAB4_KEY_H
#define LAB4_KEY_H
typedef struct Key {
    unsigned x;
    unsigned y;
} Key;

Key getKey(unsigned x, unsigned y);

Key getHalf(Key key);

int getDirection(Key border, Key key);

int equalsKey(Key first, Key second);
#endif
