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
	ptreenode Tree = createBintree(*p_array);
	delArr(p_array);
	delTree(Tree);
	return EXIT_SUCCESS;
}
void readData(Array* p_arr)
{
	FILE *pfile_data;
	int icount_node = 0;
	if (!(pfile_data = fopen("data.txt", "r"))){
		printf("Error!!!Reading failed!!!\n");
		exit(1);
	}
	fscanf(pfile_data, "%d", &icount_node);
	setLenArr(icount_node, p_arr);
	for (int i = 0; i < icount_node; i++){
		fscanf(pfile_data, "%d", p_arr->data + i);
	}
}