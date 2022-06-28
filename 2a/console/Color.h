#ifndef COLOR_H
#define COLOR_H
typedef enum COLOR {
    red,
    green,
    reset,
    blue,
} COLOR;

const char *getColor(COLOR color);

#endif
