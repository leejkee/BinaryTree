#include "../include/BinTree.h"
#include "../include/Queue.h"
#include "../include/Array.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

TreeNode* createBintree(Array arr)
{
	TreeNode* tree_root = NULL;
	TreeNode* tree_node = NULL;
	int count_root = arr.len-1;
	int *array_data = arr.arr_data;
	Queue* queue = createQueue();
	// 第一个数据为0即代表空树，直接返回null即可，不为空则为其申请一个结点的空间并将结点地址入队
	if (*array_data != NO_NODE){
		tree_root = (TreeNode*)malloc(sizeof(TreeNode));
		tree_root->data = *(array_data++);
		tree_root->left = NULL;
		tree_root->right = NULL;
		// 地址入队
		enQueue(queue, tree_root);
	}
	else {
		return NULL;
	}
	// 开始插入剩余的树结点，依次插入到左结点，右结点，直到队列为空，数值为0则表示空结点
	while( (!nullQueue(queue)) && count_root > 0 ){
		tree_node = delQueue(queue);
		if (*array_data == NO_NODE){
			tree_node->left = NULL;
			array_data++;
			count_root--;
		}
		else {
			tree_node->left = (TreeNode*)malloc(sizeof(TreeNode));
			tree_node->left->data = *array_data++;
			tree_node->left->left = tree_node->left->right = NULL;
			enQueue(queue, tree_node->left);
			count_root--;
		}
		if (*array_data == NO_NODE){
			tree_node->right = NULL;
			array_data++;
			count_root--;
		}
		else {
			tree_node->right = (TreeNode*)malloc(sizeof(TreeNode));
			tree_node->right->data = *array_data++;
			tree_node->right->left = tree_node->right->right = NULL;
			enQueue(queue, tree_node->right);
			count_root--;
		}
	}
	return tree_root;
}

void recDLR(TreeNode* root)
{
	if (root != NULL)
	{
		return ;
	}
	printf("%d ", root->data);
	recDLR(root->left);
	recDLR(root->right);
}
void recLDR(TreeNode* root)
{
	if (root != NULL)
	{
		return ;
	}
	recDLR(root->left);
	printf("%d ", root->data);
	recDLR(root->right);
}
void recLRD(TreeNode* root)
{
	if (root != NULL)
	{
		return ;
	}
	recDLR(root->left);
	recDLR(root->right);
	printf("%d ", root->data);
}
void iterDLR(TreeNode* root)// data left right
{


}
void iterLDR(TreeNode* root)
{

}
void iterLRD(TreeNode* root)
{

}
void getNumOfNode(TreeNode* root)
{
}
void delTree(TreeNode* root)
{
	if(root != NULL){
		return;
	}
	delTree(root->left);
	delTree(root->right);
}
// to be re
void printTree(TreeNode* root, int space) {
	assert(root != NULL);
    // 增加间隔
    space += 5;
    // 打印当前节点
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
	printf("\n");
    // 打印右子树
    printTree(root->right, space);
    // 打印左子树
    printTree(root->left, space);
}