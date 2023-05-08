// Notes: 本代码是有待优化的，仅仅是以教材为出发点的新手练手代码
// 二叉树创建 层序创建 使用队列存储新建节点的地址
// 二叉树递归遍历，非递归遍历
#include "include/BinTree.h"
#include "include/Array.h"
#include "include/Stack.h"
#include <stdio.h>
#include <stdlib.h>
int main(void){
	void readData(Array* p_arr);
	Array* p_array = initArr();
	readData(p_array);
	printArr(*p_array);
	TreeNode* Tree = createBintree(*p_array);
	LeOrder(Tree);
	printf("\n");
	// printTree(Tree, 0);
	recDLR(Tree);
	// int a = recGetHeightTree(Tree);
	// int b = iterGetHeightTree(Tree);
	delArr(p_array);
	delTree(Tree);
	return EXIT_SUCCESS;
}

void readData(Array* p_arr)
{
	FILE *pfile_data;
	int count = 0;
	// function fopen() must be executed, so function assert() cannot be used.
	if (!(pfile_data = fopen("data.txt", "r"))){
		printf("Error!!!Reading failed!!!\n");
		return;
	}
	fscanf(pfile_data, "%d", &count);
	setLenArr(count, p_arr);
	for (int i = 0; i < count; i++){
		fscanf(pfile_data, "%d", p_arr->arr_data + i);
	}
	fclose(pfile_data);
}