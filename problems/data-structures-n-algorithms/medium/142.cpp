// 142. Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/

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
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
	if (head == NULL) {
		return NULL;
	}

	ListNode *fast, *slow;
	fast = head->next;
	slow = head;

	while (fast != NULL && fast->next != NULL && fast != slow) {
		slow = slow->next;
		fast = fast->next->next;
	}

	if (fast == NULL || fast->next == NULL) {
		return NULL;
	}

	// moving fast one step cuz fast started 1 step ahead of slow
	// to not execute the below statement start fast and slow at the same point
	// and put if checks inside 1st while loop
	fast = fast->next;
	slow = head;
	while (fast != slow) {
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}

int main() {
	ListNode *HEAD = new ListNode(3);
	ListNode *head = HEAD;

	ListNode *item1 = new ListNode(2);
	head->next = item1;
	head = head->next;
	ListNode *item2 = new ListNode(0);
	head->next = item2;
	head = head->next;
	ListNode *item3 = new ListNode(-4);
	item3->next = item1;
	head->next = item3;
	head = head->next;

	ListNode *res = detectCycle(HEAD);

	if (res != NULL) {
		cout << res->val << endl;
	} else {
		cout << "res is null" << endl;
	}

	// while (res != NULL) {
	// 	cout << res->val << endl;
	// 	res = res->next;
	// }

	return 0;
}