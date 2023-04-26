#include "../include/BinTree.h"
#include "../include/Queue.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
pqueue createQueue(){
	pqueue new_queue = (pqueue)malloc(sizeof(struct listqueue));
	new_queue->pfront = new_queue->prear = NULL;
	return new_queue;
}
bool isEmpty(pqueue Q){
	if (Q->pfront == NULL){
		return true;
	}
	else {
		return false;
	}
}
void enQueue(pqueue queue, ptreenode data)
{
	pqueuenode node = (pqueuenode)malloc(sizeof(struct queuenode));
	node->pdata = data;
	node->next = NULL;
	// 处理结点的插入
	// 1)空队，需要让front和rear同时指向第一个结点
	// 2)非空队，只需要插入后后移一次rear即可
	if (isEmpty(queue)){
		queue->pfront = node;
		queue->prear = node;
	}
	else {
		queue->prear->next = node;
		queue->prear = node;
	}
}
ptreenode delQueue(pqueue queue)
{
	// 1)空队 无法出队，退出
	// 2)非空 仅有一个结点的情况需要额外单独处理，其他就正常后移front即可
	pqueuenode tmp_queue_node = NULL;
	ptreenode addr_tree_node = NULL;
	if (isEmpty(queue) == true){
		printf("The queue is empty");
		exit(1);
	}
	else {
		addr_tree_node = queue->pfront->pdata;
		tmp_queue_node = queue->pfront;
		if (queue->pfront == queue->prear){
			queue->pfront = NULL;
			queue->prear = NULL;
		}
		else {
			queue->pfront = queue->pfront->next;
		}
		free(tmp_queue_node);
	}
	return addr_tree_node;
}