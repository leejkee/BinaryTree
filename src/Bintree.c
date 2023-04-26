#include "../include/BinTree.h"
#include "../include/Queue.h"
#include "../include/Array.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
ptreenode createBintree(Array arr)
{
	ptreenode tree_root = NULL;
	ptreenode tree = NULL;
	int i_count_tree = arr.len-1;
	int *p_data = arr.data;
	pqueue queue = createQueue();
	// 第一个数据为0即代表空树，直接返回null即可，不为空则为其申请一个结点的空间并将结点地址入队
	if (*p_data != NO_NODE){
		tree_root = (ptreenode)malloc(sizeof(struct treenode));
		tree_root->idata = *p_data++;
		tree_root->left = NULL;
		tree_root->right = NULL;
		// 地址入队
		enQueue(queue, tree_root);
	}
	else {
		return NULL;
	}
	// 开始插入剩余的树结点，依次插入到左结点，右结点，直到队列为空，数值为0则表示空结点
	while(isEmpty(queue) == false && i_count_tree > 0){
		tree = delQueue(queue);
		if (*p_data == NO_NODE){
			tree->left = NULL;
			p_data++;
			i_count_tree--;
		}
		else {
			tree->left = (ptreenode)malloc(sizeof(struct treenode));
			tree->left->idata = *p_data++;
			tree->left->left = tree->left->right = NULL;
			enQueue(queue, tree->left);
			i_count_tree--;
		}
		if (*p_data == NO_NODE){
			tree->right = NULL;
			p_data++;
			i_count_tree--;
		}
		else {
			tree->right = (ptreenode)malloc(sizeof(struct treenode));
			tree->right->idata = *p_data++;
			tree->right->left = tree->right->right = NULL;
			enQueue(queue, tree->right);
			i_count_tree--;
		}
	}
	return tree_root;
}

void recDLR(ptreenode root)
{
	if (root == NULL)
	{
		return ;
	}
	printf("%d ", root->idata);
	recDLR(root->left);
	recDLR(root->right);
}
void recLDR(ptreenode root)
{
	if (root == NULL)
	{
		return ;
	}
	recDLR(root->left);
	printf("%d ", root->idata);
	recDLR(root->right);
}
void recLRD(ptreenode root)
{
	if (root == NULL)
	{
		return ;
	}
	recDLR(root->left);
	recDLR(root->right);
	printf("%d ", root->idata);
}
void iterDLR(ptreenode root)// data left right
{


}
void iterLDR(ptreenode root)
{

}
void iterLRD(ptreenode root)
{

}
void getNumOfNode(ptreenode root)
{
}
void delTree(ptreenode p_tree)
{
	if (p_tree == NULL){
		return;
	}
	delTree(p_tree->left);
	delTree(p_tree->right);
}
void printTree(ptreenode root, int space) {
    if (root == NULL) {
        return;
    }
    // 增加间隔
    space += 5;
    // 打印当前节点
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->idata);
	printf("\n");
    // 打印右子树
    printTree(root->right, space);
    // 打印左子树
    printTree(root->left, space);
}