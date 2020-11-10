// 101. Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
} typedef TreeNode;

bool isSymmetricalII(struct TreeNode *root1, struct TreeNode *root2) {
	if (root1 == NULL || root2 == NULL) {
		return root1 == root2;
	}

	if (root1->val != root2->val) {
		return false;
	}

	return isSymmetricalII(root1->left, root2->right) &&
				 isSymmetricalII(root1->right, root2->left);
}

bool isSymmetric(struct TreeNode *root) {
	if (root == NULL) {
		return true;
	}

	return isSymmetricalII(root->left, root->right);
}

int main() {
	int flag;
	TreeNode *root, *tempNode;

	root = (TreeNode *)malloc(sizeof(TreeNode));
	root->val = 1;

	tempNode = (TreeNode *)malloc(sizeof(TreeNode));
	tempNode->val = 2;
	root->left = tempNode;

	tempNode = (TreeNode *)malloc(sizeof(TreeNode));
	tempNode->val = 3;
	root->right = tempNode;

	// tempNode = (TreeNode *)malloc(sizeof(TreeNode));
	// tempNode->val = 15;
	// root->right->left = tempNode;

	// tempNode = (TreeNode *)malloc(sizeof(TreeNode));
	// tempNode->val = 7;
	// root->left->right = tempNode;

	flag = isSymmetric(root);

	printf("%d\n", flag);

	return 0;
}