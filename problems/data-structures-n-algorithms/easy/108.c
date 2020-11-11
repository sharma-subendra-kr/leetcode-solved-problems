// 108. Convert Sorted Array to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
} typedef TreeNode;

struct TreeNode *createNode(int num) {
	TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
	temp->val = num;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct TreeNode *constructTree(int *nums, int low, int high) {
	int mid = low + (high - low) / 2;
	TreeNode *node;

	if (high < low) {
		return NULL;
	}

	node = (TreeNode *)malloc(sizeof(TreeNode));
	node->val = nums[mid];
	node->left = constructTree(nums, low, mid - 1);
	node->right = constructTree(nums, mid + 1, high);

	return node;
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize) {
	TreeNode *root = NULL;

	root = constructTree(nums, 0, numsSize - 1);

	return root;
}

void printPreOrder(TreeNode *root) {
	if (root == NULL) {
		printf("null ");
		return;
	}

	printf("%d ", root->val);
	printPreOrder(root->left);
	printPreOrder(root->right);
}

int main() {
	int nums[5] = {-10, -3, 0, 5, 9};
	int numsSize = 5;
	TreeNode *root;

	root = sortedArrayToBST(nums, numsSize);

	printPreOrder(root);

	return 0;
}