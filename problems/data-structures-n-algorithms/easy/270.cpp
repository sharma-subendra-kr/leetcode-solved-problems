// 270. Closest Binary Search Tree Value
// https://leetcode.com/problems/closest-binary-search-tree-value/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>
#include <float.h>

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

void getClosest(TreeNode *root, double target, int *closest) {
	if (root == NULL) {
		return;
	}

	if (*closest == INT_MAX ||
			fabs((double)*closest - target) > fabs((double)(root->val) - target)) {
		*closest = root->val;
	}

	if (target < (double)root->val) {
		getClosest(root->left, target, closest);
	} else {
		getClosest(root->right, target, closest);
	}
}

int closestValue(TreeNode *root, double target) {
	if (root == NULL) {
		return 0;
	}

	int closest = INT_MAX;

	getClosest(root, target, &closest);

	return closest;
}

int main() {
	//
	double target = 3.714286;

	TreeNode *head = new TreeNode(4);

	TreeNode *node1 = new TreeNode(2);
	head->left = node1;

	TreeNode *node2 = new TreeNode(5);
	head->right = node2;

	TreeNode *node3 = new TreeNode(1);
	node2->left = node3;

	TreeNode *node4 = new TreeNode(3);
	node2->right = node4;

	int res = closestValue(head, target);

	cout << res << endl;

	return 0;
}