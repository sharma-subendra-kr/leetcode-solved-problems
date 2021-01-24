// 105. Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right)
			: val(x), left(left), right(right) {}
};

#include "../../../utils/print.h"

int getRootIndex(int start, int end, int root, vector<int> &inorder) {
	for (int i = start; i <= end; i++) {
		if (inorder[i] == root) {
			return i;
		}
	}
	return -1;
}

TreeNode *build(int preStart, int inOrderStart, int inOrderEnd,
								vector<int> &inorder, vector<int> &preorder) {
	if (inOrderStart > inOrderEnd) {
		return NULL;
	}

	int rootIndex =
			getRootIndex(inOrderStart, inOrderEnd, preorder[preStart], inorder);

	TreeNode *node = new TreeNode(inorder[rootIndex]);

	node->left =
			build(preStart + 1, inOrderStart, rootIndex - 1, inorder, preorder);
	node->right = build(preStart + rootIndex - inOrderStart + 1, rootIndex + 1,
											inOrderEnd, inorder, preorder);

	return node;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
	if (preorder.size() == 0) {
		return NULL;
	}
	return build(0, 0, inorder.size() - 1, inorder, preorder);
}

int main() {
	vector<int> preorder, inorder;

	// preorder = {3, 9, 20, 15, 7};
	// inorder = {9, 3, 15, 20, 7};

	preorder = {-1};
	inorder = {-1};

	TreeNode *root = buildTree(preorder, inorder);

	printTree(root);

	return 0;
}