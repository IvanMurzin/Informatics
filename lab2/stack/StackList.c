//#include <stdlib.h>
//#include "StackList.h"
//
//Stack *getStack() {
//    Stack *stack = malloc(sizeof(Stack));
//    stack->head = NULL;
//    stack->size = 0;
//    return stack;
//}
//
//void push(Stack *stack, int x, int y) {
//    if (stack->head == NULL) {
//        stack->head = malloc(sizeof(Node));
//        stack->head->x = x;
//        stack->head->y = y;
//        return;
//    }
//    Node *newNode = malloc(sizeof(Node));
//    newNode->next = stack->head;
//    newNode->x = x;
//    newNode->y = y;
//    stack->head = newNode;
//}
//
//int pop(Stack *stack, int *x, int *y) {
//    if (!stack || stack->head == NULL)
//        return 0;
//    *x = stack->head->x;
//    *y = stack->head->y;
//    stack->head = stack->head->next;
//    return 1;
//}
