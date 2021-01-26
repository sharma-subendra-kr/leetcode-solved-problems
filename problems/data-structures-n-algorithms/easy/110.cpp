// 110. Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/

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

int check(TreeNode *root, bool *res) {
	if (root == NULL) {
		return 0;
	}
	int left = check(root->left, res);
	int right = check(root->right, res);

	if (abs(left - right) > 1) {
		*res = false;
	}

	return max(left, right) + 1;
}

bool isBalanced(TreeNode *root) {
	bool res = 1;
	check(root, &res);

	return res;
}

int main() {
	TreeNode *head = new TreeNode(3);

	// TreeNode *node1 = new TreeNode(9);
	// head->left = node1;

	TreeNode *node2 = new TreeNode(20);
	head->right = node2;

	TreeNode *node3 = new TreeNode(15);
	node2->left = node3;

	TreeNode *node4 = new TreeNode(7);
	node2->right = node4;

	bool res = isBalanced(head);

	cout << res << endl;

	return 0;
}