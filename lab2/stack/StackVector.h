#ifndef STACKVECTOR_H
#define STACKVECTOR_H

typedef struct Stack {
    int *x;
    int *y;
    int buffSize;
    int top;
    int start;
    int size;
} Stack;

Stack *getStack();

void push(Stack *stack, int x, int y);

int pop(Stack *stack, int *x, int *y);

#endif
