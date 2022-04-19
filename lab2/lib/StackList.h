#ifndef STACKLIST_H
#define STACKLIST_H

typedef struct Node {
    struct Node *next;
    int x;
    int y;
} Node;

typedef struct Stack {
    Node *head;
    int size;
} Stack;

Stack *getStack();

void push(Stack *stack, int x, int y);

int pop(Stack *stack, int *x, int *y);

void destroy(Stack *stack);

#endif
