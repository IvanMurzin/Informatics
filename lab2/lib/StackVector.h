#ifndef STACKVECTOR_H
#define STACKVECTOR_H

#include "Point.h"

typedef struct Stack {
    Point *point;
    int buffSize;
    int top;
    int start;
    int size;
} Stack;

Stack *getStack();

int push(Stack *stack, Point point);

int pop(Stack *stack, Point *point);

void destroy(Stack *stack);

#endif
