// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <stack>

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

// void traverse(TreeNode *root, vector<int> &res) {
// 	if (root == NULL) {
// 		return;
// 	}

// 	res.push_back(root->val);
// 	traverse(root->left, res);
// 	traverse(root->right, res);
// }

void traverse(TreeNode *root, vector<int> &res) {
	if (root == NULL) {
		return;
	}

	stack<TreeNode *> stack;
	TreeNode *iter = root;

	do {
		while (iter != NULL) {
			res.push_back(iter->val);
			stack.push(iter);
			iter = iter->left;
		}

		iter = stack.top();
		stack.pop();
		iter = iter->right;
	} while (iter != NULL || !stack.empty());
}

vector<int> preorderTraversal(TreeNode *root) {
	//
	vector<int> res;
	traverse(root, res);
	return res;
}

int main() {
	//

	TreeNode *root = new TreeNode(1);

	TreeNode *node1 = new TreeNode(2);
	root->right = node1;

	TreeNode *node2 = new TreeNode(3);
	node1->left = node2;

	vector<int> res = preorderTraversal(root);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;
}
