#include "../include/BinTree.h"
#include "../include/Queue.h"
#include "../include/Array.h"
#include "../include/Stack.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

TreeNode* createBintree(Array arr)
{
	TreeNode* tree_root = NULL;
	TreeNode* tree_node = NULL;
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
	for ( int i = 0; i < arr.len-1 && (!nullQueue(queue)); ){
		tree_node = delQueue(queue);
		if (array_data[i] == NO_NODE){
			tree_node->left = NULL;
		}
		else {
			tree_node->left = (TreeNode*)malloc(sizeof(TreeNode));
			tree_node->left->data = array_data[i];
			tree_node->left->left = tree_node->left->right = NULL;
			enQueue(queue, tree_node->left);
		}
		i++;
		if (i >= arr.len-1)
		{
			break;
		}
		if (array_data[i] == NO_NODE){
			tree_node->right = NULL;
		}
		else {
			tree_node->right = (TreeNode*)malloc(sizeof(TreeNode));
			tree_node->right->data = array_data[i];
			tree_node->right->left = tree_node->right->right = NULL;
			enQueue(queue, tree_node->right);
		}
		i++;
	}
	freeQueue(queue);
	return tree_root;
}

// 先序遍历
void recDLR(TreeNode* root)
{
	if (root == NULL)
	{
		return ;
	}
	printf("%d ", root->data);
	recDLR(root->left);
	recDLR(root->right);
}
// 中序遍历
void recLDR(TreeNode* root)
{
	if (root == NULL)
	{
		return ;
	}
	recDLR(root->left);
	printf("%d ", root->data);
	recDLR(root->right);
}
// 后序遍历
void recLRD(TreeNode* root)
{
	if (root == NULL)
	{
		return ;
	}
	recDLR(root->left);
	recDLR(root->right);
	printf("%d ", root->data);
}

// 层序遍历
void LeOrder(TreeNode* root)
{
	if (root == NULL)
	{
		return ;
	}
	TreeNode* tree_node = NULL;
	Queue* p_queue = createQueue();
	enQueue(p_queue, root);
	while (!nullQueue(p_queue))
	{
		tree_node = delQueue(p_queue);
		printf("%d ", tree_node->data);
		enQueue(p_queue, tree_node->left);
		enQueue(p_queue, tree_node->right);
	}
	freeQueue(p_queue);
}

// 非递归遍历
void iterDLR(TreeNode* root)// data left right
{
	assert(root != NULL);
	Stack* p_stack = initStack();
	TreeNode* tree_node = NULL;
	pushStack(p_stack, root);
	while (!nullStack(p_stack))
	{
		tree_node = topStack(*p_stack);
		// printf("iterDLR:\n");
		printf("%d ", tree_node->data);
		popStack(p_stack);
		pushStack(p_stack, tree_node->right);
		pushStack(p_stack, tree_node->left);
	}
	freeStack(p_stack);
}
void iterLDR(TreeNode* root)
{
	assert(root != NULL);
}
void iterLRD(TreeNode* root)
{
	assert(root != NULL);
}
// 递归求树高度
int recGetHeightTree(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return recGetHeightTree(root->left) > recGetHeightTree(root->right) ? recGetHeightTree(root->left) + 1 : recGetHeightTree(root->right) + 1;
}
// 迭代算法求树高度
// 第一次入列根结点，统计到队列中一个元素，即最顶层只有一个元素
// 入队根节点的子结点多少个，第二层就有多少个结点，再在出队操作之前统计一次，即可控制每层结点出队完毕就讲高度加1
int iterGetHeightTree(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int height_tree = 0;
	TreeNode* tree_node = NULL;
	Queue* p_queue = createQueue();
	enQueue(p_queue, root);
	while (!nullQueue(p_queue))
	{
		int count_queue = getNumQueue(p_queue);
		while(count_queue--)
		{
			tree_node = delQueue(p_queue);
			enQueue(p_queue, tree_node->left);
			enQueue(p_queue, tree_node->right);
		}
		height_tree++;
	}
	freeQueue(p_queue);
	return height_tree;
}
void getNumOfNode(TreeNode* root)
{
}
void delTree(TreeNode* root)
{
	if(root == NULL){
		return;
	}
	delTree(root->left);
	delTree(root->right);
	free(root);
	root = NULL;
}
// to be re
// void printTree(TreeNode* root, int space) {
//     // 增加间隔
//     space += 5;
//     // 打印当前节点
//     for (int i = 5; i < space; i++) {
//         printf(" ");
//     }
//     printf("%d\n", root->data);
// 	printf("\n");
//     // 打印右子树
//     printTree(root->right, space);
//     // 打印左子树
//     printTree(root->left, space);
// }
void printTree(TreeNode * root, int level)
{
	// 若节点为空，返回
    if (root == NULL) {
        return;
    }
    // 打印右子树
    printTree(root->right, level + 1);
    // 打印该节点
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    printf("%d\n", root->data);
    // 打印左子树
    printTree(root->left, level + 1);
}