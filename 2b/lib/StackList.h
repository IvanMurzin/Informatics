#ifndef STACKLIST_H
#define STACKLIST_H

#include "Point.h"

typedef struct Node {
    struct Node *next;
    Point point;
} Node;

typedef struct Stack {
    Node *head;
    int size;
} Stack;

Stack *getStack();

int push(Stack *stack, Point point);

int pop(Stack *stack, Point *point);

void destroy(Stack *stack);

#endif
