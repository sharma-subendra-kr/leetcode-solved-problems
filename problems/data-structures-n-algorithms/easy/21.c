// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
} typedef ListNode;

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
	ListNode *HEAD = NULL, *CURR = NULL, *curr1, *curr2;

	curr1 = l1;
	curr2 = l2;

	if (curr1 != NULL && curr2 != NULL) {
		if (curr1->val < curr2->val) {
			HEAD = curr1;
			curr1 = curr1->next;
		} else {
			HEAD = curr2;
			curr2 = curr2->next;
		}
	} else if (curr1 != NULL) {
		HEAD = curr1;
		curr1 = curr1->next;
	} else if (curr2 != NULL) {
		HEAD = curr2;
		curr2 = curr2->next;
	} else {
		return NULL;
	}

	CURR = HEAD;

	while (curr1 != NULL || curr2 != NULL) {
		if (curr1 != NULL && curr2 != NULL) {
			if (curr1->val < curr2->val) {
				CURR->next = curr1;
				CURR = CURR->next;
				curr1 = curr1->next;
			} else {
				CURR->next = curr2;
				CURR = CURR->next;
				curr2 = curr2->next;
			}
		} else if (curr1 != NULL) {
			CURR->next = curr1;
			CURR = CURR->next;
			curr1 = curr1->next;
		} else {
			CURR->next = curr2;
			CURR = CURR->next;
			curr2 = curr2->next;
		}
	}

	return HEAD;
}

int main() {
	int i, n, m, tempVal, d;
	ListNode *HEAD1 = NULL, *HEAD2 = NULL, *newHead, *tempNode;

	scanf("%d", &n);
	scanf("%d", &m);

	for (i = 0; i < n; i++) {
		scanf("%d", &tempVal);

		tempNode = (ListNode *)malloc(sizeof(ListNode));
		tempNode->val = tempVal;
		tempNode->next = HEAD1;
		HEAD1 = tempNode;
	}

	for (i = 0; i < m; i++) {
		scanf("%d", &tempVal);

		tempNode = (ListNode *)malloc(sizeof(ListNode));
		tempNode->val = tempVal;
		tempNode->next = HEAD2;
		HEAD2 = tempNode;
	}

	newHead = mergeTwoLists(HEAD1, HEAD2);

	printf("%d\n", newHead->val);

	while (newHead != NULL) {
		printf("%d->", newHead->val);
		newHead = newHead->next;
	}

	return 0;
}