// 404. Sum of Left Leaves
// https://leetcode.com/problems/sum-of-left-leaves/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

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

void leftSum(TreeNode *node, int *sum, bool isleft) {
	if (node == NULL) {
		return;
	}

	if (isleft && node->left == NULL && node->right == NULL) {
		*sum += node->val;
	}
	leftSum(node->left, sum, true);
	leftSum(node->right, sum, false);
}

int sumOfLeftLeaves(TreeNode *root) {
	int sum = 0;
	leftSum(root, &sum, false);
	return sum;
}

int main() {
	TreeNode *root;

	// root = new TreeNode(3);

	// TreeNode *node1 = new TreeNode(9);
	// root->left = node1;
	// TreeNode *node2 = new TreeNode(20);
	// root->right = node2;

	// TreeNode *node3 = new TreeNode(15);
	// node2->left = node3;
	// TreeNode *node4 = new TreeNode(7);
	// node2->right = node4;

	root = new TreeNode(1);

	TreeNode *node1 = new TreeNode(2);
	root->left = node1;
	TreeNode *node2 = new TreeNode(3);
	root->right = node2;

	TreeNode *node3 = new TreeNode(4);
	node1->left = node3;
	TreeNode *node4 = new TreeNode(5);
	node1->right = node4;

	int res = sumOfLeftLeaves(root);

	cout << res;

	return 0;
}