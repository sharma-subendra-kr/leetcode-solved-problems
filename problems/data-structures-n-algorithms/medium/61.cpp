// 61. Rotate List
// https://leetcode.com/problems/rotate-list/

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

ListNode *rotateRight(ListNode *head, int k) {
	if (head == NULL || k == 0) {
		return head;
	}

	ListNode *TAIL, *iter, *prev, *HEAD;
	int len = 0;
	int count;

	iter = head;
	while (iter != NULL) {
		prev = iter;
		iter = iter->next;
		len++;
	}
	TAIL = prev;

	if (k % len == 0) {
		return head;
	}

	if (k > len) {
		k = k % len;
	}

	count = len - k;
	iter = head;
	prev = NULL;
	while (count != 0) {
		prev = iter;
		iter = iter->next;
		count--;
	}
	prev->next = NULL;
	HEAD = iter;
	TAIL->next = head;

	return HEAD;
}

int main() {
	int k = 6;

	ListNode *head = new ListNode(1);
	ListNode *temp = head;

	ListNode *item1 = new ListNode(2);
	temp->next = item1;
	temp = temp->next;
	ListNode *item2 = new ListNode(3);
	temp->next = item2;
	temp = temp->next;
	ListNode *item3 = new ListNode(4);
	temp->next = item3;
	temp = temp->next;
	ListNode *item4 = new ListNode(5);
	temp->next = item4;
	temp = temp->next;

	ListNode *res = rotateRight(head, k);

	while (res != NULL) {
		cout << res->val;
		res = res->next;
	}

	return 0;
}