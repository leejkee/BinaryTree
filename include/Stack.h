#ifndef STACK_DEF
#define STACK_DEF
#include "BinTree.h"
typedef ptreenode Elem;
typedef struct node *Node;
struct node{
    Elem data;
    Node next;
};
typedef struct stack
{
    Node base;
    Node top;
    int count;
} Stack;

extern Stack *init();
extern void del(Stack stack);
extern void push(Elem data);
extern void pop();
extern Elem top(Stack stack);
#endif