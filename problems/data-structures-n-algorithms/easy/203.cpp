// 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/

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

ListNode *removeElements(ListNode *head, int val) {
	ListNode *curr, *prev;

	curr = head;
	prev = NULL;
	while (curr != NULL) {
		if (curr == head && curr->val == val) {
			curr = curr->next;
			head = curr;
		} else if (curr->val == val) {
			prev->next = curr->next;
			curr = curr->next;
		} else {
			prev = curr;
			curr = curr->next;
		}
	}

	return head;
}

int main() {
	ListNode *head;

	return 0;
}