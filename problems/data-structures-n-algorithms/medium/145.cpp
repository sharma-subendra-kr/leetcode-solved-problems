// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/

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

// void traverse(TreeNode *root, vector<int> &res) {
// 	if (root == NULL) {
// 		return;
// 	}

// 	traverse(root->left, res);
// 	traverse(root->right, res);
// 	res.push_back(root->val);
// }

void traverse(TreeNode *root, vector<int> &res) {
	if (root == NULL) {
		return;
	}

	stack<TreeNode *> st;
	stack<TreeNode *> rst;
	TreeNode *iter = root;
	TreeNode *riter = NULL;

	do {
		while (iter != NULL) {
			res.push_back(iter->val);
			st.push(iter);
			iter = iter->left;
		}

		iter = st.top();
		riter = rst.top();

		if (iter == riter) {
			res.push_back(iter->val);
			st.pop();
			rst.pop();
			iter = st.top();
			rst.push(iter);
			iter = iter->right;
		} else {
			rst.push(iter);
			iter = iter->right;
		}
	} while (iter != NULL || !st.empty());
}

vector<int> postorderTraversal(TreeNode *root) {
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

	vector<int> res = postorderTraversal(root);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;
}