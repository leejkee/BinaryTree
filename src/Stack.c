#include "../include/Stack.h"
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
/* 
 top = new Node
 count = 0
 Node.data = NULL
 Node.next = NULL
 */
Stack *initStack()
{
    Stack *p_stack = (Stack *)malloc(sizeof(Stack));
    p_stack->top = (Node)malloc(sizeof(struct node));
    p_stack->count = 0;
    // (p_stack->top) -> data = NULL;
    (p_stack->top) -> data = 0;
    (p_stack->top) -> next = NULL;
    return p_stack;
}

void pushStack(Stack *p_stack, Elem data)
{
    assert(p_stack != NULL);
    Node newNode = (Node)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = (p_stack->top) -> next;
    (p_stack->top) -> next = newNode;
    p_stack->count++;
}
void popStack(Stack *p_stack)
{
    assert(p_stack != NULL);
    assert((p_stack->top) -> next);
    Node delNode = (p_stack->top) -> next;
    (p_stack->top) -> next = (p_stack->top)->next -> next;
    p_stack->count--;
    free(delNode);
}
Elem topStack(Stack stack){
    return (stack.top->next)->data;
}
