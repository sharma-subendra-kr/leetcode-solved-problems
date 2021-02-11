// 572. Subtree of Another Tree
// https://leetcode.com/problems/subtree-of-another-tree/

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

bool check(TreeNode *s, TreeNode *t) {
	if (s == NULL && t == NULL) {
		return true;
	} else if (s == NULL || t == NULL) {
		return false;
	}

	if (s->val != t->val) {
		return false;
	}

	return check(s->left, t->left) && check(s->right, t->right);
}

bool isSubtree(TreeNode *s, TreeNode *t) {
	if (s == NULL || t == NULL) {
		return false;
	}

	if (s->val == t->val) {
		if (check(s, t)) {
			return true;
		}
	}

	return isSubtree(s->left, t) || isSubtree(s->right, t);
}

int main() { return 0; }