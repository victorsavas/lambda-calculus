#include <string.h>

#include "stack.h"

#define STACK_CAP 16

struct Stack {
        void **array;
        size_t top;
        size_t capacity;
};

Stack *stack_init()
{
        Stack *stack = malloc(sizeof(*stack));

        if (stack == NULL)
                return NULL;

        stack->array = malloc(sizeof(*stack->array) * STACK_CAP);

        if (stack->array == NULL) {
                free(stack);
                return NULL;
        }

        stack->top = 0;
        stack->capacity = STACK_CAP;

        return stack;
}

void stack_free(Stack *stack)
{
        if (stack == NULL)
                return;

        free(stack->array);
        free(stack);
}

void *stack_push(Stack *stack, void *address)
{
        if (stack == NULL)
                return NULL;

        if (stack->top + 1 == stack->capacity) {
                void **array = realloc(stack->array, stack->capacity << 1);

                if (array == NULL)
                        return NULL;
                
                stack->array = array;
                stack->capacity <<= 1;
        }

        stack->array[stack->top++] = address;

        return address;
}

void *stack_pop(Stack *stack)
{
        if (stack == NULL)
                return NULL;

        if (stack->top == 0)
                return NULL;

        return stack->array[--stack->top];
}

void *stack_peek(Stack *stack)
{
        if (stack == NULL)
                return NULL;

        if (stack->top == 0)
                return NULL;

        return stack->array[stack->top];
}

void *stack_search(Stack *stack, void *address, bool compare(void *left, void *right))
{
        if (stack == NULL)
                return NULL;

        for (size_t i = 0; i < stack->top; i++) {
                void *entry = stack->array[i];

                if (compare(address, entry))
                        return entry;
        }

        return NULL;
}