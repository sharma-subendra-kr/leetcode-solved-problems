// 109. Convert Sorted List to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

TreeNode *construct(ListNode *head, ListNode *end) {
	if (head == NULL || end == NULL || end->next == head) {
		return NULL;
	}

	ListNode *fast = NULL, *slow = NULL, *slowPrev = NULL;
	fast = head;
	slow = head;

	while (fast != end) {
		slowPrev = slow;
		slow = slow->next;

		fast = fast->next;
		if (fast != end) {
			fast = fast->next;
		}
	}

	TreeNode *root = new TreeNode(slow->val);

	root->left = construct(head, slowPrev);
	root->right = construct(slow->next, end);

	return root;
}

TreeNode *sortedListToBST(ListNode *head) {
	ListNode *curr, *prev = NULL;
	curr = head;

	while (curr != NULL) {
		prev = curr;
		curr = curr->next;
	}

	return construct(head, prev);
}

int main() {
	//

	ListNode *head = new ListNode(-10);
	ListNode *curr = head;

	ListNode *item1 = new ListNode(-3);
	curr->next = item1;
	curr = curr->next;

	ListNode *item2 = new ListNode(0);
	curr->next = item2;
	curr = curr->next;

	ListNode *item3 = new ListNode(5);
	curr->next = item3;
	curr = curr->next;

	ListNode *item4 = new ListNode(9);
	curr->next = item4;
	curr = curr->next;

	TreeNode *res = sortedListToBST(head);

	printTree(res);

	return 0;
}