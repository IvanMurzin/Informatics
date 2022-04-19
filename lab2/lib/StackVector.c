#include "StackVector.h"
#include <stdlib.h>

Stack *getStack() {
    Stack *stack = malloc(sizeof(Stack));
    stack->buffSize = 10;
    stack->x = malloc(sizeof(int) * stack->buffSize);
    stack->y = malloc(sizeof(int) * stack->buffSize);
    stack->top = 0;
    stack->size = 0;
    stack->start = 0;
    return stack;
}

void push(Stack *stack, int x, int y) {
    stack->x[stack->top] = x;
    stack->y[stack->top] = y;
    if (stack->start == stack->top && stack->size >= stack->buffSize)
        stack->start = (stack->start + 1) % stack->buffSize;
    else
        stack->size++;
    stack->top = (stack->top + 1) % stack->buffSize;
}

int pop(Stack *stack, int *x, int *y) {
    if (!stack || stack->size == 0)
        return 0;
    stack->top = (stack->buffSize + stack->top - 1) % stack->buffSize;
    stack->size--;
    *x = stack->x[stack->top];
    *y = stack->y[stack->top];
    return 1;
}

void destroy(Stack *stack){
    free(stack->x);
    free(stack->y);
    free(stack);
}