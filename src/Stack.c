#include "../include/Stack.h"
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>

/*
malloc:
p_stack:
    SNode *top
    int count = 0

top:
    TreeNode* data = NULL
    SNode* next = NULL
*/
Stack *initStack()
{
    Stack *p_stack = (Stack *)malloc(sizeof(Stack));
    p_stack->top = (SNode*)malloc(sizeof(struct stacknode));
    p_stack->count = 0;
    (p_stack->top) -> data = NULL;
    // (p_stack->top) -> data = 0;
    (p_stack->top) -> next = NULL;
    return p_stack;
}

void pushStack(Stack *p_stack, TreeNode* data)
{
    assert(p_stack != NULL);
    if (data == NULL){
        return ;
    }
    SNode* newNode = (SNode*)malloc(sizeof(struct stacknode));
    newNode->data = data;
    newNode->next = (p_stack->top) -> next;
    (p_stack->top) -> next = newNode;
    p_stack->count++;
}

void popStack(Stack* p_stack)
{
    assert(p_stack != NULL);
    SNode* delNode = (p_stack->top) -> next;
    (p_stack->top) -> next = (p_stack->top)->next -> next;
    p_stack->count--;
    free(delNode);
}
bool nullStack(Stack* p_stack)
{
    if (p_stack->top->next == NULL || p_stack->count == 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
void freeStack(Stack * p_stack)
{
    if (p_stack == NULL)
    {
        return ;
    }
    int count = p_stack->count;
    SNode* stack_node = p_stack->top->next;
    while (count--)
    {
        free(stack_node);
    }
    free(p_stack->top);
    free(p_stack);
    p_stack = NULL;
}
TreeNode* topStack(Stack stack){
    return (stack.top->next)->data;
}