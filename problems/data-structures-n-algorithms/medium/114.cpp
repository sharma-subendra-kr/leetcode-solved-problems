// 114. Flatten Binary Tree to Linked List
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
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

TreeNode *preOrder(TreeNode *HEAD, TreeNode *root, TreeNode *head) {
	if (root == NULL) {
		return HEAD;
	}
	HEAD->left = root;
	HEAD = HEAD->left;
	HEAD = preOrder(HEAD, root->left, head);
	HEAD = preOrder(HEAD, root->right, head);
	return HEAD;
}

void flatten(TreeNode *root) {
	TreeNode *HEAD = new TreeNode();
	TreeNode *head = HEAD;

	preOrder(HEAD, root, head);

	TreeNode *iter = head;

	while (iter != NULL) {
		iter->right = iter->left;
		iter->left = NULL;
		iter = iter->right;
	}
}

int main() {

	TreeNode *head = new TreeNode(1);

	TreeNode *node1 = new TreeNode(2);
	head->left = node1;

	TreeNode *node2 = new TreeNode(5);
	head->right = node2;

	TreeNode *node3 = new TreeNode(3);
	node1->left = node3;
	TreeNode *node4 = new TreeNode(4);
	node1->right = node4;

	TreeNode *node5 = new TreeNode(6);
	node2->right = node5;

	flatten(head);

	printTree(head);

	return 0;
}