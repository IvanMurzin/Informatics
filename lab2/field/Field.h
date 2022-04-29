#ifndef FIELD_H
#define FIELD_H

#include "Point.h"

typedef struct Field {
    int **data;
    int size;
    Point empty;
    Point selected;
} Field;


Field *getField(int size);

int isEmpty(Field *field, Point point);

int isSelected(Field *field, Point point);

#endif
