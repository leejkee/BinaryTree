#ifndef BINTREE_DEF
#define BINTREE_DEF
#include "Array.h"
// 用0表示空结点
#define NO_NODE 0
// 定义二叉树的结点，其中包含数据和左右子结点的地址
typedef struct treenode TreeNode;
struct treenode {
	int data;
	TreeNode* left;
	TreeNode* right;
};
#endif
extern TreeNode* createBintree(Array arr);

extern void LeOrder(TreeNode* root);
extern void recDLR(TreeNode* root);
extern void recLDR(TreeNode* root);
extern void recLRD(TreeNode* root);

extern void iterDLR(TreeNode* root);
extern void iterLDR(TreeNode* root);
extern void iterLRD(TreeNode* root);

extern void getNumOfNode(TreeNode* root);
// extern void printTree(TreeNode* root, int space);

extern void delTree(TreeNode* p_tree);