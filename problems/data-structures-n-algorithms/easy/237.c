// 237. Delete Node in a Linked List
// https://leetcode.com/problems/delete-node-in-a-linked-list/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
} typedef ListNode;

void deleteNode(struct ListNode *node) {
	ListNode next, nextNext;
	next = *node->next;
	nextNext.next = next.next;

	node->val = next.val;
	node->next = nextNext.next;
}

int main() {
	int i, n, tempVal, d;
	ListNode *HEAD = NULL, *delNode, *tempNode;

	scanf("%d", &n);
	scanf("%d", &d);

	for (i = 0; i < n; i++) {
		scanf("%d", &tempVal);

		tempNode = (ListNode *)malloc(sizeof(ListNode));
		tempNode->val = tempVal;
		tempNode->next = HEAD;
		HEAD = tempNode;

		if (i == d) {
			delNode = tempNode;
		}
	}

	deleteNode(delNode);

	while (HEAD != NULL) {
		printf("%d->", HEAD->val);
		HEAD = HEAD->next;
	}

	return 0;
}