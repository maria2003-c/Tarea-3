#include <stdlib.h>
#include "stack.h"


typedef struct StackNode {
    void *data;
    struct StackNode *next;
} StackNode;

struct Stack {
    StackNode *top;
};

Stack *stack_create(void) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack != NULL) {
        stack->top = NULL;
    }
    return stack;
}


void stack_push(Stack *stack, void *data) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = stack->top;
        stack->top = newNode;
    }
}


void *stack_top(Stack *stack) {
    if (stack->top == NULL) return NULL;
    return stack->top->data;
}


void *stack_pop(Stack *stack) {
    if (stack->top == NULL) return NULL;

    StackNode *temp = stack->top;
    void *data = temp->data;

    stack->top = stack->top->next;
    free(temp);

    return data;
}


void stack_clean(Stack *stack) {
    while (stack->top != NULL) {
        stack_pop(stack);
    }
    free(stack);
}