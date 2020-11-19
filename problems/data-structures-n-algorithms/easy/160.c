// 160. Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
} typedef ListNode;

struct ListNode *getIntersectionNode(struct ListNode *headA,
																		 struct ListNode *headB) {
	struct ListNode *curr1 = NULL, *curr2 = NULL, *longer = NULL, *shorter = NULL;
	int len1 = 0, len2 = 0, diff, count = 0;

	curr1 = headA;
	curr2 = headB;

	while (curr1 != NULL) {
		len1++;
		curr1 = curr1->next;
	}

	while (curr2 != NULL) {
		len2++;
		curr2 = curr2->next;
	}

	if (len1 > len2) {
		longer = headA;
		shorter = headB;
	} else {
		longer = headB;
		shorter = headA;
	}

	diff = abs(len2 - len1);

	while (count != diff) {
		longer = longer->next;
		count++;
	}

	while (longer != shorter) {
		longer = longer->next;
		shorter = shorter->next;
	}

	return longer;
}

int main() {
	// struct ListNode *l1, *l2, *temp, *res, *intersect;

	// temp = (ListNode *)malloc(sizeof(ListNode));
	// temp->val = 5;
	// l1 = temp;

	// temp = (ListNode *)malloc(sizeof(ListNode));
	// temp->val = 4;
	// temp->next = l1;
	// l1 = temp;

	// temp = (ListNode *)malloc(sizeof(ListNode));
	// temp->val = 3;
	// temp->next = l1;
	// l1 = temp;
	// intersect = temp;

	// temp = (ListNode *)malloc(sizeof(ListNode));
	// temp->val = 2;
	// temp->next = l1;
	// l1 = temp;

	// temp = (ListNode *)malloc(sizeof(ListNode));
	// temp->val = 1;
	// temp->next = l1;
	// l1 = temp;

	// //

	// temp = (ListNode *)malloc(sizeof(ListNode));
	// temp->val = 8;
	// l2 = temp;

	// temp = (ListNode *)malloc(sizeof(ListNode));
	// temp->val = 7;
	// temp->next = l2;
	// l2 = temp;

	// temp = (ListNode *)malloc(sizeof(ListNode));
	// temp->val = 6;
	// temp->next = l2;
	// l2 = temp;

	// // temp = l1;
	// // while (temp != NULL) {
	// // 	printf("%d->", temp->val);
	// // 	temp = temp->next;
	// // }
	// // printf("\n");

	// res = getIntersectionNode(l1, l2);

	// while (res != NULL) {
	// 	printf("%d->", res->val);
	// 	res = res->next;
	// }

	// return 0;
}