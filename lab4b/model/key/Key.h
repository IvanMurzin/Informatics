#ifndef LAB4_KEY_H
#define LAB4_KEY_H
typedef struct Key {
    unsigned x;
    unsigned y;
} Key;

Key getKey(unsigned x, unsigned y);

int outOfBorder(Key start, Key end, Key key);

Key getHalf(Key key);

Key getBorder(Key start, Key end);

int getDirection(Key start, Key end, Key key);

int equalsKey(Key first, Key second);

int greaterKey(Key src, Key key);

int gte(Key left, Key right);

Key getNewStartBorder(Key start, Key end, int direction);

Key getNewEndBorder(Key start, Key end, int direction);

#endif
