#include "BinTree.h"
#include <stdbool.h>
#ifndef QUEUE_DEF
#define QUEUE_DEF
// 定义链队列的结点，其数据域为二叉树的结点地址
typedef struct queuenode *pqueuenode;
struct queuenode{
	ptreenode pdata;
	pqueuenode next;
};
// 队列的操作需要两个指向头节点和尾结点的指针变量，所以定义一个queue结构体包含头尾指针
struct listqueue
{
	pqueuenode pfront;
	pqueuenode prear;
};
typedef struct listqueue *pqueue;
#endif
extern pqueue createQueue();
extern bool isEmpty(pqueue);
extern void enQueue(pqueue, ptreenode);
extern ptreenode delQueue(pqueue);