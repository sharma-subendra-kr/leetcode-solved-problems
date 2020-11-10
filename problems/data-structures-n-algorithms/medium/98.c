// 98. Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
} typedef TreeNode;

bool isValid(struct TreeNode *root, struct TreeNode **pre) {
	bool flag = true;
	if (root == NULL) {
		return true;
	}

	flag = isValid(root->left, pre);
	if (flag == false) {
		return false;
	}

	if (*pre != NULL && root->val <= (*pre)->val) {
		return false;
	}
	*pre = root;

	flag = isValid(root->right, pre);

	return flag;
}

bool isValidBST(struct TreeNode *root) {
	TreeNode *pre = NULL;
	return isValid(root, &pre);
}

int main() {
	int flag;
	TreeNode *root, *tempNode;

	root = (TreeNode *)malloc(sizeof(TreeNode));
	root->val = 2;

	tempNode = (TreeNode *)malloc(sizeof(TreeNode));
	tempNode->val = 1;
	root->left = tempNode;

	tempNode = (TreeNode *)malloc(sizeof(TreeNode));
	tempNode->val = 3;
	root->right = tempNode;

	// tempNode = (TreeNode *)malloc(sizeof(TreeNode));
	// tempNode->val = 6;
	// root->right->left = tempNode;

	// tempNode = (TreeNode *)malloc(sizeof(TreeNode));
	// tempNode->val = 20;
	// root->right->right = tempNode;

	flag = isValidBST(root);

	printf("%d\n", flag);

	return 0;
}