#include <stdlib.h>
#include <printf.h>
#include "StackList.h"

Stack *getStack() {
    Stack *stack = calloc(1, sizeof(Stack));
    stack->size = 0;
    return stack;
}

void push(Stack *stack, Point point) {
    if (stack == NULL) return;
    if (stack->head == NULL) {
        stack->head = calloc(1, sizeof(Node));
        stack->head->next = NULL;
        stack->head->point = point;
        stack->size = 1;
        return;
    }
    Node *newNode = calloc(1, sizeof(Node));
    newNode->next = stack->head;
    newNode->point = point;
    stack->head = newNode;
    stack->size++;
}

int pop(Stack *stack, Point* point) {
    if (stack == NULL || stack->head == NULL)
        return 0;
    *x = stack->head->x;
    *y = stack->head->y;
    Node *trash = stack->head;
    stack->head = stack->head->next;
    stack->size--;
    free(trash);
    return 1;
}

void destroy(Stack *stack) {
    Node *cursor = stack->head;
    Node *trash = cursor;
    while (cursor) {
        cursor = cursor->next;
        free(trash);
        trash = cursor;
    }
    free(stack);
}