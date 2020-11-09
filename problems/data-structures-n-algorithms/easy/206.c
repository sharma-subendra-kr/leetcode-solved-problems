// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
} typedef ListNode;

struct ListNode *reverseList(struct ListNode *head) {
	ListNode *prev = NULL, *curr, *temp;

	curr = head;
	while (curr != NULL) {
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}

	return prev;
}

int main() {
	int i, n, tempVal;
	ListNode *HEAD = NULL, *tempNode;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &tempVal);

		tempNode = (ListNode *)malloc(sizeof(ListNode));
		tempNode->val = tempVal;
		tempNode->next = HEAD;
		HEAD = tempNode;
	}

	HEAD = reverseList(HEAD);

	while (HEAD != NULL) {
		printf("%d->", HEAD->val);
		HEAD = HEAD->next;
	}

	return 0;
}