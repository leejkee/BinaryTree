#ifndef STACK_DEF
#define STACK_DEF
#include "BinTree.h"
typedef ptreenode Elem;
// typedef int Elem;
typedef struct node *Node;
struct node
{
    Elem data;
    Node next;
};
typedef struct stack
{
    Node top;
    int count;
} Stack;

extern Stack *initStack();
extern void pushStack(Stack *p_stack, Elem data);
extern void popStack(Stack *p_stack);
extern Elem topStack(Stack stack);
#endif