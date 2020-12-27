// 236. Lowest Common Ancestor of a Binary Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include "../../../utils/print.h"

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {}

int main() {
	TreeNode *head;

	head = new TreeNode(3);

	TreeNode *node1 = new TreeNode(5);
	head->left = node1;

	TreeNode *node2 = new TreeNode(1);
	head->right = node2;

	TreeNode *node3 = new TreeNode(6);
	node1->left = node3;

	TreeNode *node4 = new TreeNode(2);
	node1->right = node4;

	TreeNode *node5 = new TreeNode(0);
	node2->left = node5;

	TreeNode *node6 = new TreeNode(8);
	node2->right = node6;

	TreeNode *node7 = new TreeNode(7);
	node4->left = node7;

	TreeNode *node8 = new TreeNode(4);
	node4->right = node8;

	TreeNode *res = lowestCommonAncestor(head, node1, node2);

	printTree(head);

	return 0;
}