// 104. Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
} typedef TreeNode;

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int maxDepth(struct TreeNode *root) {
	if (root == NULL) {
		return 0;
	}

	return max(max(maxDepth(root->left) + 1, 1),
						 max(maxDepth(root->right) + 1, 1));
}

int main() {
	int depth;
	TreeNode *root, *tempNode;

	root = (TreeNode *)malloc(sizeof(TreeNode));
	root->val = 3;

	tempNode = (TreeNode *)malloc(sizeof(TreeNode));
	tempNode->val = 9;
	root->left = tempNode;

	tempNode = (TreeNode *)malloc(sizeof(TreeNode));
	tempNode->val = 20;
	root->right = tempNode;

	tempNode = (TreeNode *)malloc(sizeof(TreeNode));
	tempNode->val = 15;
	root->right->left = tempNode;

	tempNode = (TreeNode *)malloc(sizeof(TreeNode));
	tempNode->val = 7;
	root->right->right = tempNode;

	depth = maxDepth(root);

	printf("%d\n", depth);

	return 0;
}