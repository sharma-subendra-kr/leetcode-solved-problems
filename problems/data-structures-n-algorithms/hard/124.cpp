// 124. Binary Tree Maximum Path Sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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

// int getMaxSum(int a, int b, int c, int d) {
// 	int m1, m2, m3;
// 	if (a > b) {
// 		m1 = a;
// 	} else {
// 		m1 = b;
// 	}

// 	if (c > d) {
// 		m2 = c;
// 	} else {
// 		m2 = d;
// 	}

// 	if (m1 > m2) {
// 		m3 = m1;
// 	} else {
// 		m3 = m2;
// 	}

// 	return m3;
// };

// int traverse(TreeNode *root) {
// 	stack<pair<TreeNode *, int>> s;
// 	unordered_map<TreeNode *, int> mp;

// 	pair<TreeNode *, int> *curr;

// 	int max = INT_MIN;

// 	pair<TreeNode *, int> item(root, 0);
// 	s.push(item);
// 	mp.insert({root, root->val});

// 	while (!s.empty()) {
// 		curr = &s.top();

// 		curr->second++;

// 		if (curr->second > 2) {
// 			s.pop();

// 			int sum = curr->first->val;
// 			int sumL = sum, sumR = sum, sumAll = sum, sumMax;

// 			if (curr->first->left != NULL) {
// 				auto iter = mp.find(curr->first->left);
// 				sumL = sum + iter->second;
// 				sumAll = sumAll + iter->second;
// 				mp.erase(curr->first->left);
// 			}
// 			if (curr->first->right != NULL) {
// 				auto iter = mp.find(curr->first->right);
// 				sumR = sum + iter->second;
// 				sumAll = sumAll + iter->second;
// 				mp.erase(curr->first->right);
// 			}

// 			sumMax = std::max({sum, sumL, sumR});
// 			sumAll = std::max({sum, sumL, sumR, sumAll});

// 			auto f = mp.find(curr->first);
// 			f->second = sumMax;

// 			if (sumAll > max) {
// 				max = sumAll;
// 			}
// 			continue;
// 		}

// 		if (curr->second == 1 && curr->first->left != NULL) {
// 			pair<TreeNode *, int> temp(curr->first->left, 0);
// 			s.push(temp);
// 			mp.insert({curr->first->left, curr->first->left->val});
// 		} else if (curr->first->right != NULL) {
// 			pair<TreeNode *, int> temp(curr->first->right, 0);
// 			s.push(temp);
// 			mp.insert({curr->first->right, curr->first->right->val});
// 		}
// 	}

// 	return max;
// }

// int maxPathSum(TreeNode *root) {
// 	if (root == NULL) {
// 		return 0;
// 	}

// 	return traverse(root);
// }

int traverse(TreeNode *node, int *maxValue) {
	if (node == NULL) {
		return 0;
	}
	int left = traverse(node->left, maxValue);
	int right = traverse(node->right, maxValue);

	int retMax = max({left + node->val, right + node->val, node->val});

	*maxValue = max({*maxValue, left + right + node->val, retMax});
	return retMax;
}

int maxPathSum(TreeNode *root) {
	if (root == NULL) {
		return 0;
	}

	int maxValue = INT_MIN;
	traverse(root, &maxValue);
	return maxValue;
}

int main() {
	TreeNode *head;

	head = new TreeNode(-10);

	TreeNode *node1 = new TreeNode(9);
	head->left = node1;

	TreeNode *node2 = new TreeNode(20);
	head->right = node2;

	TreeNode *node3 = new TreeNode(15);
	node2->left = node3;

	TreeNode *node4 = new TreeNode(7);
	node2->right = node4;

	// head = new TreeNode(1);

	// TreeNode *node1 = new TreeNode(2);
	// head->left = node1;

	// TreeNode *node2 = new TreeNode(3);
	// head->right = node2;

	//

	// head = new TreeNode(2);

	// TreeNode *node1 = new TreeNode(-1);
	// head->left = node1;

	//

	// head = new TreeNode(5);

	// TreeNode *node1 = new TreeNode(4);
	// head->left = node1;

	// TreeNode *node2 = new TreeNode(8);
	// head->right = node2;

	// TreeNode *node3 = new TreeNode(11);
	// node1->left = node3;

	// TreeNode *node4 = new TreeNode(13);
	// node2->left = node4;

	// TreeNode *node5 = new TreeNode(4);
	// node2->right = node5;

	// TreeNode *node6 = new TreeNode(7);
	// node3->left = node6;

	// TreeNode *node7 = new TreeNode(2);
	// node3->right = node7;

	// TreeNode *node8 = new TreeNode(1);
	// node5->right = node8;

	//

	// head = new TreeNode(1);

	// TreeNode *node1 = new TreeNode(-2);
	// head->left = node1;

	// TreeNode *node2 = new TreeNode(3);
	// head->right = node2;

	int res = maxPathSum(head);

	cout << res;

	return 0;
}