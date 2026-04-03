#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef struct Stack Stack;

Stack *stack_init();
void stack_free(Stack *stack);

void *stack_push(Stack *stack, void *address);
void *stack_pop(Stack *stack);
void *stack_peek(Stack *stack);
void *stack_search(Stack *stack, void *address, bool compare(void *left, void *right));