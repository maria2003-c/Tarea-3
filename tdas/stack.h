#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack;

Stack *stack_create(void);
void stack_push(Stack *stack, void *data);
void *stack_top(Stack *stack);
void *stack_pop(Stack *stack);
void stack_clean(Stack *stack);

#endif