// 143. Reorder List
// https://leetcode.com/problems/reorder-list/

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

void reorderList(ListNode *head) {
	if (head == NULL) {
		return;
	}

	//
	ListNode *fast, *slow, *slowPrev = NULL;

	fast = head;
	slow = head;

	while (fast != NULL) {
		slowPrev = slow;
		slow = slow->next;
		fast = fast->next;
		if (fast != NULL) {
			fast = fast->next;
		}
	}
	slowPrev->next = NULL;

	ListNode *left = head;
	ListNode *right = slow;
	//

	ListNode *prev = NULL;
	ListNode *curr = right;
	ListNode *next = NULL;
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	if (prev != NULL)
		right = prev;

	//
	while (right != NULL) {
		ListNode *lnext = left->next;
		ListNode *rnext = right->next;

		left->next = right;
		right->next = lnext;

		left = left->next->next;
		right = rnext;
	}
}

int main() {
	//
	ListNode *curr;
	ListNode *head = new ListNode(1);
	curr = head;
	// ListNode *item1 = new ListNode(2);
	// curr->next = item1;
	// curr = curr->next;
	// ListNode *item2 = new ListNode(3);
	// curr->next = item2;
	// curr = curr->next;
	// ListNode *item3 = new ListNode(4);
	// curr->next = item3;
	// curr = curr->next;
	// ListNode *item4 = new ListNode(5);
	// curr->next = item4;
	// curr = curr->next;

	reorderList(head);

	ListNode *iter = head;
	while (iter != NULL) {
		cout << iter->val << endl;
		iter = iter->next;
	}

	return 0;
}