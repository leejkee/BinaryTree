#ifndef BINTREE_DEF
#define BINTREE_DEF
#include "Array.h"
// 用0表示空结点
#define NO_NODE 0
// 定义二叉树的结点，其中包含数据和左右子结点的地址
typedef struct treenode *ptreenode;
struct treenode {
	int idata;
	ptreenode left, right;
};
#endif

extern ptreenode createBintree(Array arr);

extern void recDLR(ptreenode root);
extern void recLDR(ptreenode root);
extern void recLRD(ptreenode root);

extern void iterDLR(ptreenode root);
extern void iterLDR(ptreenode root);
extern void iterLRD(ptreenode root);

extern void getNumOfNode(ptreenode root);
extern void printTree(ptreenode root, int space);

extern void delTree(ptreenode p_tree);