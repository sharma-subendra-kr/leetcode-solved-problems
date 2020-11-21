// 103. Binary Tree Zigzag Level Order Traversal
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
	vector<vector<int>> res;
	queue<TreeNode *> q;
	int reverse = 0;
	int nodesInLevel = 1;
	int level = 0;

	if (root == NULL) {
		return res;
	}

	q.push(root);

	while (!q.empty()) {
		TreeNode *node = q.front();
		q.pop();

		if (res.size() < level + 1) {
			vector<int> temp = vector<int>(nodesInLevel);
			res.push_back(temp);
		}

		if (reverse) {
			res[level][nodesInLevel - 1] = node->val;
		} else {
			res[level][res[level].size() - nodesInLevel] = node->val;
		}

		nodesInLevel--;

		if (node->left != NULL) {
			q.push(node->left);
		}
		if (node->right != NULL) {
			q.push(node->right);
		}
		if (nodesInLevel == 0) {
			nodesInLevel = q.size();
			reverse = !reverse;
			level++;
		}
	}

	return res;
}

int main() {
	struct TreeNode *tree, *temp;

	// vector<vector<int>> arr;

	temp = new TreeNode();
	temp->val = 3;
	tree = temp;

	// temp = new TreeNode();
	// tree->left = temp;

	temp = new TreeNode();
	temp->val = 20;
	tree->right = temp;

	temp = new TreeNode();
	temp->val = 9;
	tree->left = temp;

	temp = new TreeNode();
	temp->val = 15;
	tree->right->left = temp;

	temp = new TreeNode();
	temp->val = 7;
	tree->right->right = temp;

	// temp = new TreeNode();
	// tree->right->right = temp;

	vector<vector<int>> arr = zigzagLevelOrder(tree);

	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}