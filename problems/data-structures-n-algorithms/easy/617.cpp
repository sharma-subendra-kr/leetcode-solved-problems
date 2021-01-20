// 617. Merge Two Binary Trees
// https://leetcode.com/problems/merge-two-binary-trees/

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

#include "../../../utils/print.h"

TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
	if (t1 == NULL) {
		return t2;
	} else if (t2 == NULL) {
		return t1;
	}

	TreeNode *merged = new TreeNode(t1->val + t2->val);
	merged->left = mergeTrees(t1->left, t2->left);
	merged->right = mergeTrees(t1->right, t2->right);

	return merged;
}

int main() {
	TreeNode *head1;
	head1 = new TreeNode(1);

	TreeNode *node1 = new TreeNode(3);
	head1->left = node1;

	TreeNode *node2 = new TreeNode(2);
	head1->right = node2;

	TreeNode *node3 = new TreeNode(5);
	node1->left = node3;

	//
	TreeNode *head2;
	head2 = new TreeNode(2);

	TreeNode *_node1 = new TreeNode(1);
	head2->left = _node1;

	TreeNode *_node2 = new TreeNode(3);
	head2->right = _node2;

	TreeNode *_node3 = new TreeNode(4);
	_node1->right = _node3;

	TreeNode *_node4 = new TreeNode(7);
	_node2->right = _node4;

	TreeNode *merged = mergeTrees(head1, head2);

	printTree(merged);

	return 0;
}