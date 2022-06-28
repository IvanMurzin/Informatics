#include <stdlib.h>
#include <printf.h>
#include "StackList.h"

Stack *getStack() {
    Stack *stack = calloc(1, sizeof(Stack));
    stack->size = 0;
    return stack;
}

int push(Stack *stack, Point point) {
    if (stack == NULL) return 0;
    Node *newNode = calloc(1, sizeof(Node));
    if (newNode == NULL) return 0;
    newNode->next = stack->head;
    newNode->point = point;
    stack->head = newNode;
    stack->size++;
    return 1;
}

int pop(Stack *stack, Point *point) {
    if (stack == NULL || stack->head == NULL)
        return 0;
    *point = stack->head->point;
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