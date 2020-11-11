// 102. Binary Tree Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <math.h>
#include <stdbool.h>
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

void printInOrder(struct TreeNode *root, int **arr, int **returnColumnSizes,
									int depth, int *sizes) {
	if (root == NULL) {
		return;
	}
	printInOrder(root->left, arr, returnColumnSizes, depth + 1, sizes);
	if (sizes[depth] == returnColumnSizes[0][depth]) {
		arr[depth] = (int *)realloc(arr[depth], sizeof(int) * sizes[depth] * 2);
		sizes[depth] *= 2;
	}
	arr[depth][returnColumnSizes[0][depth]++] = root->val;
	printInOrder(root->right, arr, returnColumnSizes, depth + 1, sizes);
}

int **levelOrder(struct TreeNode *root, int *returnSize,
								 int **returnColumnSizes) {
	int depth = 0, i;
	int **arr, *sizes;

	depth = maxDepth(root);
	*returnSize = depth;

	arr = (int **)malloc(sizeof(int *) * depth);
	sizes = (int *)calloc(depth, sizeof(int));

	for (i = 0; i < depth; i++) {
		arr[i] = (int *)malloc(sizeof(int) * 1);
		sizes[i] = 1;
	}

	returnColumnSizes[0] = (int *)calloc(depth, sizeof(int));

	if (root == NULL) {
		return arr;
	}

	printInOrder(root, arr, returnColumnSizes, 0, sizes);

	free(sizes);

	return arr;
}

int main() {
	int returnSize, **returnColumnSizes, **arr;
	int i, j;
	TreeNode *root = NULL, *tempNode;

	root = (TreeNode *)malloc(sizeof(TreeNode));
	root->val = 1;

	tempNode = (TreeNode *)malloc(sizeof(TreeNode));
	tempNode->val = 2;
	root->left = tempNode;

	tempNode = (TreeNode *)malloc(sizeof(TreeNode));
	tempNode->val = 3;
	root->right = tempNode;

	tempNode = (TreeNode *)malloc(sizeof(TreeNode));
	tempNode->val = 15;
	root->right->left = tempNode;

	tempNode = (TreeNode *)malloc(sizeof(TreeNode));
	tempNode->val = 7;
	root->left->right = tempNode;

	returnColumnSizes = (int **)malloc(sizeof(int) * 1);

	arr = levelOrder(root, &returnSize, returnColumnSizes);

	for (i = 0; i < returnSize; i++) {
		for (j = 0; j < returnColumnSizes[0][i]; j++) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}

	// lazy to free pointers

	return 0;
}