// 148. Sort List
// https://leetcode.com/problems/sort-list/

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode **merge(ListNode *list, ListNode *left, ListNode *leftTail,
								 ListNode *right, ListNode *rightTail) {
	ListNode *res = new ListNode(), *iter = NULL;
	iter = res;

	while ((left != leftTail && left != NULL) &&
				 (right != rightTail && right != NULL)) {
		if (left->val < right->val) {
			iter->next = left;
			left = left->next;
		} else {
			iter->next = right;
			right = right->next;
		}
		iter = iter->next;
	}

	while (left != leftTail && left != NULL) {
		iter->next = left;
		left = left->next;
		iter = iter->next;
	}

	while (right != rightTail && right != NULL) {
		iter->next = right;
		right = right->next;
		iter = iter->next;
	}

	iter->next = rightTail;

	ListNode **arr = new ListNode *[2];
	arr[0] = res->next;
	arr[1] = rightTail;
	return arr;
}

ListNode **mergeSort(ListNode *list, ListNode *head, ListNode *tail) {
	ListNode *fast = head, *slow = head, *mid;

	if (head == tail || head == NULL) {
		ListNode **arr = new ListNode *[2];
		arr[0] = head;
		arr[1] = head == NULL ? NULL : head->next;
		return arr;
	}

	if (head->next != tail) {
		while (fast != tail) {
			slow = slow->next;
			fast = fast->next;
			if (fast != tail) {
				fast = fast->next;
			}
		}
	} else {
		slow = head;
	}

	mid = slow;

	ListNode **left = mergeSort(list, head, mid);
	ListNode **right = mergeSort(list, left[1], tail);
	ListNode **res = merge(list, left[0], left[1], right[0], right[1]);
	return res;
}

ListNode *sortList(ListNode *head) {
	ListNode *tail = head;

	if (head == NULL) {
		return head;
	}

	while (tail->next != NULL) {
		tail = tail->next;
	}

	return mergeSort(head, head, tail)[0];
}

int main() {
	ListNode *head, *curr, *temp;

	curr = new ListNode(4);
	head = curr;

	temp = new ListNode(2);
	curr->next = temp;
	curr = curr->next;

	temp = new ListNode(1);
	curr->next = temp;
	curr = curr->next;

	temp = new ListNode(3);
	curr->next = temp;
	curr = curr->next;

	ListNode *iter = sortList(head);

	while (iter != NULL) {
		cout << iter->val;
		iter = iter->next;
	}

	return 0;
}