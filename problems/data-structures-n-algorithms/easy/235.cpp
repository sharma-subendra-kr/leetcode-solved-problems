// 235. Lowest Common Ancestor of a Binary Search
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
	if (root == NULL) {
		return NULL;
	}

	if (p->val < root->val && q->val < root->val) {
		return lowestCommonAncestor(root->left, p, q);
	} else if (p->val > root->val && q->val > root->val) {
		return lowestCommonAncestor(root->right, p, q);
	} else {
		return root;
	}
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