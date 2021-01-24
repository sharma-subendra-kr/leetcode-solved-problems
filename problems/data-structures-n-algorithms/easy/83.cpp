// 83. Remove Duplicates from Sorted List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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

ListNode *deleteDuplicates(ListNode *head) {
	ListNode *HEAD = head;
	ListNode *curr = head;
	ListNode *prev = NULL;

	while (curr != NULL) {
		if (prev == NULL) {
			prev = curr;
			curr = curr->next;
			continue;
		}
		if (prev->val == curr->val) {
			prev->next = curr->next;
			curr = curr->next;
		} else {
			prev = curr;
			curr = curr->next;
		}
	}

	return HEAD;
}

int main() {
	ListNode *head = new ListNode(1);
	ListNode *HEAD = head;
	ListNode *temp = new ListNode(1);
	head->next = temp;
	head = head->next;
	temp = new ListNode(2);
	head->next = temp;
	head = head->next;

	// ListNode *res = HEAD;
	ListNode *res = deleteDuplicates(HEAD);

	while (res != NULL) {
		cout << res->val << " ";
		res = res->next;
	}

	return 0;
}