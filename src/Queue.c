#include "../include/BinTree.h"
#include "../include/Queue.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

Queue* createQueue(){
	Queue* new_queue = (Queue*)malloc(sizeof(struct listqueue));
	new_queue->front = new_queue->rear = NULL;
	return new_queue;
}
bool nullQueue(Queue* p_queue){
	if (p_queue->front == NULL){
		return true;
	}
	else {
		return false;
	}
}
void enQueue(Queue* p_queue, TreeNode* data)
{
	if (data == NULL)
	{
		return ;
	}
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->tree_data = data;
	node->next = NULL;
	// 处理结点的插入
	// 1)空队，需要让front和rear同时指向第一个结点
	// 2)非空队，只需要插入后后移一次rear即可
	if (nullQueue(p_queue)){
		p_queue->front = node;
		p_queue->rear = node;
	}
	else {
		p_queue->rear->next = node;
		p_queue->rear = node;
	}
}
TreeNode* delQueue(Queue* p_queue)
{
	// 1)空队 无法出队，退出
	// 2)非空 仅有一个结点的情况需要额外单独处理，其他就正常后移front即可
	QNode* tmp_queue_node = NULL;
	TreeNode* addr_tree_node = NULL;
	assert(!nullQueue(p_queue));
	addr_tree_node = p_queue->front->tree_data;
	tmp_queue_node = p_queue->front;
	if (p_queue->front == p_queue->rear){
		p_queue->front = NULL;
		p_queue->rear = NULL;
	}
	else {
		p_queue->front = p_queue->front->next;
	}
	free(tmp_queue_node);
	tmp_queue_node = NULL;
	return addr_tree_node;
}

int getNumQueue(Queue* p_queue)
{
	if (nullQueue(p_queue))
	{
		return 0;
	}
	int num_queue = 1;
	for (QNode* iter = p_queue->front; iter != p_queue->rear; iter = iter->next)
	{
		num_queue++;
	}
	return num_queue;
}
void freeQueue(Queue * p_queue)
{
	if (p_queue == NULL)
	{
		return ;
	}
	if (!nullQueue(p_queue)){
		while (p_queue->front){
			p_queue->rear = p_queue->front->next;
			free(p_queue->front);
			p_queue->front = p_queue->rear;
		}
	}
	free(p_queue);
	p_queue = NULL;
}