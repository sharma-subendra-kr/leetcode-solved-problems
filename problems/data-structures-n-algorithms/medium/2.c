// 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
} typedef ListNode;

struct ListNode *getNode() {
	struct ListNode *temp = NULL;
	temp = (struct ListNode *)malloc(sizeof(struct ListNode));
	temp->next = NULL;
	return temp;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
	struct ListNode *TAIL = NULL, *HEAD = NULL, *temp = NULL, *bigList = NULL;
	int carry = 0, sum, num;

	while (l1 != NULL && l2 != NULL) {
		temp = getNode();
		sum = l1->val + l2->val + carry;
		num = sum;
		if (sum >= 10) {
			carry = 1;
			num = sum % 10;
		} else {
			carry = 0;
		}
		temp->val = num;
		if (HEAD == NULL) {
			HEAD = temp;
			TAIL = temp;
		} else {
			TAIL->next = temp;
			TAIL = temp;
		}
		l1 = l1->next;
		l2 = l2->next;
	}

	if (l1 != NULL) {
		bigList = l1;
	} else if (l2 != NULL) {
		bigList = l2;
	}

	while (bigList != NULL) {
		temp = getNode();
		sum = bigList->val + carry;
		num = sum;
		if (sum >= 10) {
			carry = 1;
			num = sum % 10;
		} else {
			carry = 0;
		}
		temp->val = num;
		if (HEAD == NULL) {
			HEAD = temp;
			TAIL = temp;
		} else {
			TAIL->next = temp;
			TAIL = temp;
		}
		bigList = bigList->next;
	}

	if (carry == 1) {
		temp = getNode();
		temp->val = carry;
		TAIL->next = temp;
		TAIL = temp;
	}

	return HEAD;
}

int main() {
	struct ListNode *l1, *l2, *temp, *res;

	temp = (ListNode *)malloc(sizeof(ListNode));
	temp->val = 3;
	l1 = temp;

	temp = (ListNode *)malloc(sizeof(ListNode));
	temp->val = 4;
	temp->next = l1;
	l1 = temp;

	temp = (ListNode *)malloc(sizeof(ListNode));
	temp->val = 2;
	temp->next = l1;
	l1 = temp;

	//

	temp = (ListNode *)malloc(sizeof(ListNode));
	temp->val = 4;
	l2 = temp;

	temp = (ListNode *)malloc(sizeof(ListNode));
	temp->val = 6;
	temp->next = l2;
	l2 = temp;

	temp = (ListNode *)malloc(sizeof(ListNode));
	temp->val = 5;
	temp->next = l2;
	l2 = temp;

	res = addTwoNumbers(l1, l2);

	while (res != NULL) {
		printf("%d->", res->val);
		res = res->next;
	}

	return 0;
}