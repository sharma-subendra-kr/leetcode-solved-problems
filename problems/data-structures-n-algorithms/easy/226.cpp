// 226. Invert Binary Tree
// https://leetcode.com/problems/invert-binary-tree/

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

TreeNode *invertTree(TreeNode *root) {
	if (root == NULL) {
		return root;
	}

	TreeNode *temp = root->left;
	root->left = root->right;
	root->right = temp;

	invertTree(root->left);
	invertTree(root->right);

	return root;
}

int main() {
	TreeNode *head;
	head = new TreeNode(4);

	TreeNode *node1 = new TreeNode(2);
	head->left = node1;

	TreeNode *node2 = new TreeNode(7);
	head->right = node2;

	TreeNode *node3 = new TreeNode(1);
	node1->left = node3;

	TreeNode *node4 = new TreeNode(3);
	node1->right = node4;

	TreeNode *node5 = new TreeNode(6);
	node2->left = node5;

	TreeNode *node6 = new TreeNode(9);
	node2->right = node6;

	TreeNode *inverted = invertTree(head);

	printTree(inverted);

	return 0;
}