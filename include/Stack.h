#ifndef STACK_DEF
#define STACK_DEF
#include "BinTree.h"

typedef TreeNode* Elem;
typedef struct node *Node;
struct node
{
    Elem data;
    Node next;
};
struct stack
{
    Node top;
    int count;
};
typedef struct stack Stack;
extern Stack *initStack();
extern void pushStack(Stack *p_stack, Elem data);
extern void popStack(Stack *p_stack);
extern Elem topStack(Stack stack);
#endif