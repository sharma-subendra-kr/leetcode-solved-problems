// 107. Binary Tree Level Order Traversal II
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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

// Reversing the array
void levelOrderTraversal(TreeNode *root, vector<vector<int>> &res, int level) {
	if (root == NULL) {
		return;
	}
	if (level > res.size()) {
		res.push_back(vector<int>(1, root->val));
	} else {
		res[level - 1].push_back(root->val);
	}
	levelOrderTraversal(root->left, res, level + 1);
	levelOrderTraversal(root->right, res, level + 1);
}

vector<vector<int>> levelOrderBottom(TreeNode *root) {
	int level = 0;
	vector<vector<int>> res;

	levelOrderTraversal(root, res, 1);

	reverse(res.begin(), res.end());

	return res;
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

	vector<vector<int>> res = levelOrderBottom(head);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}