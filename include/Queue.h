#include "BinTree.h"
#include <stdbool.h>
#ifndef QUEUE_DEF
#define QUEUE_DEF
// 定义链队列的结点，其数据域为二叉树的结点地址
typedef struct queuenode QNode;
struct queuenode{
	TreeNode* tree_data;
	QNode* next;
};
// 队列的操作需要两个指向头节点和尾结点的指针变量，所以定义一个queue结构体包含头尾指针，单链表的尾部无法进行删除操作，
struct listqueue
{
	QNode* front;
	QNode* rear;
};
typedef struct listqueue Queue;
#endif
extern Queue* createQueue();
extern bool nullQueue(Queue* p_queue);
extern void enQueue(Queue* p_queue, TreeNode* data);
extern TreeNode* delQueue(Queue* p_queue);
extern void freeQueue(Queue * p_queue);