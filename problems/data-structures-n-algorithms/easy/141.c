// 141. Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
} typedef ListNode;

bool hasCycle(struct ListNode *head) {
	ListNode *fast, *slow;

	if (head == NULL) {
		return false;
	}

	fast = head->next;
	slow = head;

	while (fast != slow && fast != NULL) {
		fast = fast->next;
		if (fast == NULL) {
			return false;
		}
		fast = fast->next;
		slow = slow->next;
	}

	if (fast == NULL) {
		return false;
	}

	return true;

	// fast = head;

	// while (fast != slow) {
	// 	fast = fast->next;
	// 	slow = slow->next;
	// }

	// return fast;
}

int main() {
	int i, n, tempVal;
	ListNode *HEAD = NULL, *tempNode, *cycle1, *cycle2;
	bool flag;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &tempVal);

		tempNode = (ListNode *)malloc(sizeof(ListNode));
		tempNode->val = tempVal;
		tempNode->next = HEAD;
		HEAD = tempNode;

		if (i == 0) {
			cycle1 = HEAD;
		}

		if (i == n - 2) {
			cycle2 = HEAD;
		}
	}

	// cycle1->next = cycle2;

	flag = hasCycle(HEAD);

	printf("%d\n", flag);

	// while (HEAD != NULL) {
	// 	printf("%d->", HEAD->val);
	// 	HEAD = HEAD->next;
	// }

	return 0;
}