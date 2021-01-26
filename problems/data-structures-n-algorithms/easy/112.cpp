// 112. Path Sum
// https://leetcode.com/problems/path-sum/

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

bool check(TreeNode *root, TreeNode *sibling, int sum, int agg) {
	if (root == NULL && agg == sum && sibling == NULL) {
		return true;
	} else if (root == NULL) {
		return false;
	}

	agg += root->val;

	bool left = check(root->left, root->right, sum, agg);
	bool right = check(root->right, root->left, sum, agg);

	return (left || right);
}

bool hasPathSum(TreeNode *root, int sum) { return check(root, NULL, sum, 0); }

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

	int res = hasPathSum(head, 12);

	cout << res << endl;

	return 0;
}