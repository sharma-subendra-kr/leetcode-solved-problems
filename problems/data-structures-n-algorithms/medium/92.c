// 92. Reverse Linked List II
// https://leetcode.com/problems/reverse-linked-list-ii/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
} typedef ListNode;

struct ListNode *reverseBetween(struct ListNode *head, int m, int n) {
	int count = 1;
	ListNode *startPrev = NULL, *start = NULL, *prev = NULL, *curr, *temp;

	curr = head;
	while (count < m) {
		count++;
		startPrev = curr;
		curr = curr->next;
	}

	start = curr;

	while (count <= n && curr != NULL) {
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
		count++;
	}

	if (startPrev != NULL) {
		startPrev->next = prev;
	} else {
		head = prev;
	}
	start->next = curr;

	return head;
}

int main() {
	int i, n, tempVal, m, k;
	ListNode *HEAD = NULL, *tempNode;

	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &k);

	for (i = 0; i < n; i++) {
		scanf("%d", &tempVal);

		tempNode = (ListNode *)malloc(sizeof(ListNode));
		tempNode->val = tempVal;
		tempNode->next = HEAD;
		HEAD = tempNode;
	}

	HEAD = reverseBetween(HEAD, m, k);

	while (HEAD != NULL) {
		printf("%d->", HEAD->val);
		HEAD = HEAD->next;
	}

	return 0;
}