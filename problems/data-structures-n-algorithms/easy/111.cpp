// 111. Minimum Depth of Binary Tree
// https://leetcode.com/problems/minimum-depth-of-binary-tree/

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

int minDepth(TreeNode *root) {
	if (root == NULL) {
		return 0;
	}

	int left = minDepth(root->left);
	int right = minDepth(root->right);

	return (left == 0 || right == 0) ? left + right + 1 : min(left, right) + 1;
}

int main() {
	TreeNode *head = new TreeNode(3);

	TreeNode *node1 = new TreeNode(9);
	head->left = node1;

	TreeNode *node2 = new TreeNode(20);
	head->right = node2;

	TreeNode *node3 = new TreeNode(15);
	node2->left = node3;

	TreeNode *node4 = new TreeNode(7);
	node2->right = node4;

	int res = minDepth(head);

	cout << res << endl;

	return 0;
}