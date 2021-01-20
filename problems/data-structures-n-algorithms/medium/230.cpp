// 230. Kth Smallest Element in a BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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

void inOrder(TreeNode *root, int *count, int *res) {
	if (root == NULL) {
		return;
	}
	inOrder(root->left, count, res);
	(*count)--;
	if (*count == 0) {
		*res = root->val;
	}
	inOrder(root->right, count, res);
}

int kthSmallest(TreeNode *root, int k) {
	int count = k;
	int res;

	inOrder(root, &count, &res);

	return res;
}

int main() {
	int k;

	k = 2;

	TreeNode *head;
	head = new TreeNode(3);

	TreeNode *node1 = new TreeNode(1);
	head->left = node1;

	TreeNode *node2 = new TreeNode(4);
	head->right = node2;

	TreeNode *node3 = new TreeNode(2);
	node1->right = node3;

	int res = kthSmallest(head, k);

	cout << res << endl;

	return 0;
}