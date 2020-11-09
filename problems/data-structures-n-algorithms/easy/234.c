// 234. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
} typedef ListNode;

bool isPalindrome(struct ListNode *head) {
	int len = 0, start, end, cnt = 0;
	ListNode *curr1, *curr2, *temp, *prev = NULL;

	curr1 = head;

	while (curr1 != NULL) {
		curr1 = curr1->next;
		len++;
	}

	if (len == true) {
		return true;
	} else if (len == 0) {
		return true;
	}

	// 0 based
	if (len % 2 == 0) {
		start = len / 2;
		end = len / 2 - 1;
	} else {
		start = len / 2 + 1;
		end = len / 2 - 1;
	}

	curr2 = head;
	while (cnt != start) {
		curr2 = curr2->next;
		cnt++;
	}

	while (curr2 != NULL) {
		temp = curr2->next;
		curr2->next = prev;
		prev = curr2;
		curr2 = temp;
	}

	curr2 = prev;
	curr1 = head;

	while (curr2 != NULL) {
		if (curr1->val != curr2->val) {
			return false;
		}
		curr1 = curr1->next;
		curr2 = curr2->next;
	}
	return true;
}

int main() {
	int i, n, tempVal, d;
	ListNode *HEAD = NULL, *newHead, *tempNode;
	bool flag;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &tempVal);

		tempNode = (ListNode *)malloc(sizeof(ListNode));
		tempNode->val = tempVal;
		tempNode->next = HEAD;
		HEAD = tempNode;
	}

	flag = isPalindrome(HEAD);

	printf("%d\n", flag);

	return 0;
}