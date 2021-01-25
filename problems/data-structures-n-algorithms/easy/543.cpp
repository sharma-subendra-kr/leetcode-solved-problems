// 543. Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <algorithm>

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

int maxDepth(TreeNode *root, int *_max) {
	if (root == NULL) {
		return 0;
	}

	int left = maxDepth(root->left, _max);
	int right = maxDepth(root->right, _max);

	*_max = max(*_max, left + right);

	return max(left, right) + 1;
};

int diameterOfBinaryTree(TreeNode *root) {
	int max = 0;

	int temp = maxDepth(root, &max);

	return max;
}

int main() {
	TreeNode *head = ;

	return 0;
}