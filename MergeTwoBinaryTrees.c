#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
	if(!t1)						//t1节点为空则返回t2
	{
		return t2;
	}
	if(!t2)						//t2节点为空则返回t1
	{
		return t1;
	}
	if(t1 && t2)				//两者都非空则返回则把两者值相加，并递归其左右叶子节点
	{
		t1->val += t2->val;
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);
	}
	return t1;					//两者都空情况；返回t1头结点
}

/**
 *     2       5
 *    / \     /
 *   3   4   6
 */

int main(int argc, char *argv[])
{
	struct TreeNode *t1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	struct TreeNode *t1l = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	struct TreeNode *t1r = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	t1->val = 2;
	t1l->val = 3;
	t1r->val = 4;
	t1->left = t1l;
	t1->right = t1r;

	struct TreeNode *t2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	struct TreeNode *t2l = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	t2->val = 5;
	t2l->val = 6;
	t2->left = t2l;

	struct TreeNode *result = mergeTrees(t1, t2);
	printf("%d,%d,%d\n", result->val, result->left->val, result->right->val);
	return 0;
}
