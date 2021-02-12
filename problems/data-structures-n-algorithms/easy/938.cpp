// 938. Range Sum of BST
// https://leetcode.com/problems/range-sum-of-bst/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

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

void getSum(TreeNode *root, int low, int high, int *sum) {
	if (root == NULL) {
		return;
	}

	if (root->val >= low && root->val <= high) {
		*sum += root->val;
	}

	getSum(root->left, low, high, sum);
	getSum(root->right, low, high, sum);
}

int rangeSumBST(TreeNode *root, int low, int high) {
	int sum = 0;
	getSum(root, low, high, &sum);

	return sum;
}

int main() {
	//

	return 0;
}