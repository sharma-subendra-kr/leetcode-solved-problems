// 328. Odd Even Linked List
// https://leetcode.com/problems/odd-even-linked-list/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
} typedef ListNode;

struct ListNode *oddEvenList(struct ListNode *head) {
	struct ListNode *left, *right;
	struct ListNode *leftNext, *rightNext, *rightNextNext;

	if (head == NULL || head->next == NULL) {
		return head;
	}

	left = head;
	right = head->next;

	while (right != NULL) {
		leftNext = left->next;
		rightNext = right->next;
		if (rightNext == NULL) {
			return head;
		}
		rightNextNext = rightNext->next;

		left->next = rightNext;
		rightNext->next = leftNext;
		right->next = rightNextNext;

		left = left->next;
		if (right != NULL) {
			right = right->next;
		}
	}

	return head;
}

int main() {
	struct ListNode *l1, *temp, *res;

	temp = (ListNode *)malloc(sizeof(ListNode));
	temp->val = 5;
	l1 = temp;

	temp = (ListNode *)malloc(sizeof(ListNode));
	temp->val = 4;
	temp->next = l1;
	l1 = temp;

	temp = (ListNode *)malloc(sizeof(ListNode));
	temp->val = 3;
	temp->next = l1;
	l1 = temp;

	temp = (ListNode *)malloc(sizeof(ListNode));
	temp->val = 2;
	temp->next = l1;
	l1 = temp;

	temp = (ListNode *)malloc(sizeof(ListNode));
	temp->val = 1;
	temp->next = l1;
	l1 = temp;

	temp = l1;
	while (temp != NULL) {
		printf("%d->", temp->val);
		temp = temp->next;
	}
	printf("\n");

	res = oddEvenList(l1);

	while (res != NULL) {
		printf("%d->", res->val);
		res = res->next;
	}

	return 0;
}