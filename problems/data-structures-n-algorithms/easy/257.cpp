// 257. Binary Tree Paths
// https://leetcode.com/problems/binary-tree-paths/

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

void getPaths(TreeNode *root, vector<string> &res, string s) {
	if (root == NULL) {
		return;
	}

	if (root->left == NULL && root->right == NULL) {
		s += (to_string(root->val));
		res.push_back(s);
	} else {
		s += (to_string(root->val) + "->");
		getPaths(root->left, res, s);
		getPaths(root->right, res, s);
	}
}

vector<string> binaryTreePaths(TreeNode *root) {
	vector<string> res;
	getPaths(root, res, "");

	return res;
}

int main() {
	TreeNode *root = new TreeNode(1);

	TreeNode *node1 = new TreeNode(2);
	root->left = node1;

	TreeNode *node2 = new TreeNode(3);
	root->right = node2;

	TreeNode *node3 = new TreeNode(5);
	node1->right = node3;

	vector<string> res = binaryTreePaths(root);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}

	return 0;
}