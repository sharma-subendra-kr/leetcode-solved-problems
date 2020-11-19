// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

// Recursive Solution
//

// int *inOrder(struct TreeNode *root, int *returnSize, int *arr, int *iter,
// 						 int *size) {
// 	if (root == NULL) {
// 		return NULL;
// 	}

// 	inOrder(root->left, returnSize, arr, iter, size);

// 	if (*iter < *size) {
// 		arr[(*iter)++] = root->val;
// 		(*returnSize)++;
// 	} else {
// 		arr = (int *)realloc(arr, sizeof(int) * *size * 2);
// 		(*size) *= 2;
// 		arr[(*iter)++] = root->val;
// 		(*returnSize)++;
// 	}

// 	inOrder(root->right, returnSize, arr, iter, size);

// 	return arr;
// }

// int *inorderTraversal(struct TreeNode *root, int *returnSize) {
// 	int *arr = (int *)malloc(sizeof(int) * 100);
// 	int iter = 0, size = 100;
// 	*returnSize = 0;

// 	return inOrder(root, returnSize, arr, &iter, &size);
// }

// Morris Traversal solution Later
//
//

int *inorderTraversal(struct TreeNode *root, int *returnSize) {
	int *arr = (int *)malloc(sizeof(int) * 100);
	int iter = 0;
	struct TreeNode *curr = NULL, *cLeft = NULL, *temp = NULL;
	*returnSize = 0;

	curr = root;

	while (curr != NULL) {
		if (curr->left != NULL) {
			cLeft = curr->left;
			temp = cLeft;
			while (cLeft->right != NULL) {
				cLeft = cLeft->right;
			}
			cLeft->right = curr;
			curr->left = NULL;
			curr = temp;
		} else {
			arr[iter++] = curr->val;
			curr = curr->right;
		}
	}
	*returnSize = iter;
	return arr;
}

int main() {

	struct TreeNode *tree, *temp;

	int *arr, returnSize;

	temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	temp->val = 1;
	tree = temp;

	// temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	// tree->left = temp;

	temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	temp->val = 2;
	tree->right = temp;

	// temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	// tree->left->left = temp;

	// temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	// tree->left->right = temp;

	temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	temp->val = 3;
	tree->right->left = temp;

	// temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	// tree->right->right = temp;

	arr = inorderTraversal(tree, &returnSize);

	for (int i = 0; i < returnSize; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}