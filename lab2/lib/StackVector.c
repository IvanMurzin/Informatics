#include "StackVector.h"
#include <stdlib.h>

Stack *getStack() {
    Stack *stack = malloc(sizeof(Stack));
    stack->buffSize = 10;
    stack->point = malloc(sizeof(Point) * stack->buffSize);
    stack->top = 0;
    stack->size = 0;
    stack->start = 0;
    return stack;
}

int push(Stack *stack, Point point) {
    if (stack == NULL) return 0;
    stack->point[stack->top] = point;
    if (stack->start == stack->top && stack->size >= stack->buffSize) {
        stack->start = (stack->start + 1) % stack->buffSize;
    } else {
        stack->size++;
    }
    stack->top = (stack->top + 1) % stack->buffSize;
    return 1;
}

int pop(Stack *stack, Point *point) {
    if (!stack || stack->size == 0)
        return 0;
    stack->top = (stack->buffSize + stack->top - 1) % stack->buffSize;
    stack->size--;
    *point = stack->point[stack->top];
    return 1;
}

void destroy(Stack *stack) {
    free(stack->point);
    free(stack);
}