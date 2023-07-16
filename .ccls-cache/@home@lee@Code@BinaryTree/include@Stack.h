#ifndef STACK_DEF
#define STACK_DEF
#include "BinTree.h"
#include <stdbool.h>

typedef struct stacknode SNode;
struct stacknode
{
    TreeNode* data;
    SNode* next;
};
struct stack
{
    SNode* top;// top指向的内存不存储数据
    int count;
};
typedef struct stack Stack;
extern Stack *initStack();
extern void pushStack(Stack *p_stack, TreeNode* data);
extern void popStack(Stack *p_stack);
extern TreeNode* topStack(Stack stack);
extern bool nullStack(Stack* p_stack);
extern void freeStack(Stack* p_stack);
#endif