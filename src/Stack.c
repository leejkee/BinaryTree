#include "../include/Stack.h"
#include <stddef.h>
#include <stdlib.h>

Stack *init()
{
    Stack *p_stack = (Stack *)malloc(sizeof(Stack));
    p_stack->base = p_stack->top = NULL;
    p_stack->count = 0;
    return p_stack;
}
void del(Stack *p_stack)
{
    if (NULL == p_stack)
    {
        return ;
    }
    
}
void push(Elem data) {}
void pop() {}
Elem top(Stack stack) {}
