// 106. Construct Binary Tree from Inorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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

TreeNode *construct(vector<int> &inorder, vector<int> &postorder, int start,
										int end, int index) {

	if (start > end) {
		return NULL;
	}

	int idx = 0;

	for (int i = start; i <= end; i++) {
		if (postorder[index] == inorder[i]) {
			idx = i;
			break;
		}
	}

	TreeNode *root = new TreeNode(inorder[idx]);

	int rightSize = end - idx;

	root->left =
			construct(inorder, postorder, start, idx - 1, index - rightSize - 1);
	root->right = construct(inorder, postorder, idx + 1, end, index - 1);

	return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
	//
	return construct(inorder, postorder, 0, inorder.size() - 1,
									 postorder.size() - 1);
}

int main() {
	//
	vector<int> inorder, postorder;

	inorder = {9, 3, 15, 20, 7};
	postorder = {9, 15, 7, 20, 3};

	TreeNode *res = buildTree(inorder, postorder);

	printTree(res);

	return 0;
}