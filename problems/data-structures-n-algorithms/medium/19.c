// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
} typedef ListNode;

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
	int i;
	ListNode *fast = head, *curr = head, *temp = NULL;

	for (i = 0; i < n + 1; i++) {
		if (fast == NULL) {
			temp = head;
			head = head->next;
			temp->next = NULL;
			return head;
		}
		fast = fast->next;
	}

	while (fast != NULL) {
		fast = fast->next;
		curr = curr->next;
	}

	temp = curr->next;
	curr->next = curr->next->next;
	temp->next = NULL;

	return head;
}

int main() {
	int i, n, tempVal, d;
	ListNode *HEAD = NULL, *newHead, *tempNode;

	scanf("%d", &n);
	scanf("%d", &d);

	for (i = 0; i < n; i++) {
		scanf("%d", &tempVal);

		tempNode = (ListNode *)malloc(sizeof(ListNode));
		tempNode->val = tempVal;
		tempNode->next = HEAD;
		HEAD = tempNode;
	}

	newHead = removeNthFromEnd(HEAD, d);

	printf("%d\n", newHead->val);

	while (newHead != NULL) {
		printf("%d->", newHead->val);
		newHead = newHead->next;
	}

	return 0;
}