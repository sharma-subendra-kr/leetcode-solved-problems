// 100. Same Tree
// https://leetcode.com/problems/same-tree/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

bool isSameTree(TreeNode *p, TreeNode *q) {
	if (p == NULL && q == NULL) {
		return true;
	} else if (p == NULL) {
		return false;
	} else if (q == NULL) {
		return false;
	}

	bool left = isSameTree(p->left, q->left);
	if (p->val != q->val) {
		return false;
	}
	bool right = isSameTree(p->right, q->right);

	return left && right;
}

int main() {}