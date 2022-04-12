#ifndef FIELD_H
#define FIELD_H

typedef struct Field {
    int **data;
    int size;
    int emptyY;
    int emptyX;
    int selectedX;
    int selectedY;
} Field;


Field *getField(int size);

int isEmpty(Field *field, int x, int y);

int isSelected(Field *field, int x, int y);

#endif
