// 236. Lowest Common Ancestor of a Binary Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include "../../../utils/print.h"

struct Item {
	struct TreeNode *node;
	int status;
	Item() : status(0), node(NULL) {}
	Item(int s, TreeNode *n) : status(s), node(n) {}
};

stack<Item *> traverse(TreeNode *root, TreeNode *node) {
	stack<Item *> s;
	Item *curr;

	Item *item = new Item(0, root);
	s.push(item);

	while (!s.empty()) {
		curr = s.top();

		if (curr->node == node) {
			return s;
		}

		curr->status++;

		if (curr->status > 2) {
			s.pop();
			continue;
		}

		if (curr->status == 1 && curr->node->left != NULL) {
			Item *temp = new Item(0, curr->node->left);
			s.push(temp);
		} else if (curr->node->right != NULL) {
			Item *temp = new Item(0, curr->node->right);
			s.push(temp);
		}
	}

	return s;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
	stack<Item *> ps = traverse(root, p);
	stack<Item *> qs = traverse(root, q);
	stack<Item *> *curr = NULL;
	Item *ip = NULL, *iq = NULL;

	int diff = abs((int)(ps.size() - qs.size()));
	if (ps.size() > qs.size()) {
		curr = &ps;
	} else if (qs.size() > ps.size()) {
		curr = &qs;
	}

	while (diff != 0) {
		curr->pop();
		diff--;
	}

	while (ps.size() > 0 && qs.size() > 0) {
		ip = ps.top();
		ps.pop();

		iq = qs.top();
		qs.pop();

		if (ip->node->val == iq->node->val) {
			return ip->node;
		}
	}

	return NULL;
}

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

	//

	// head = new TreeNode(1);
	// TreeNode *node0 = head;

	// TreeNode *node1 = new TreeNode(2);
	// head->left = node1;

	// TreeNode *node2 = new TreeNode(3);
	// head->right = node2;

	// TreeNode *node3 = new TreeNode(4);
	// node1->right = node3;

	TreeNode *res = lowestCommonAncestor(head, node1, node8);

	cout << res->val;

	// printTree(head);

	return 0;
}