// 23. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
	int len = lists.size();
	int count = 0;

	if (len == 0) {
		return NULL;
	}

	while (len != 1) {
		for (int i = 0; i < len; i += 2) {
			ListNode *merged = new ListNode();
			ListNode *iter = merged;
			ListNode *l1 = lists[i];
			ListNode *l2 = NULL;
			if (i + 1 < len) {
				l2 = lists[i + 1];
			}

			while (l1 != NULL && l2 != NULL) {
				if (l1->val < l2->val) {
					iter->next = l1;
					l1 = l1->next;
				} else {
					iter->next = l2;
					l2 = l2->next;
				}
				iter = iter->next;
			}

			while (l2 != NULL) {
				iter->next = l2;
				l2 = l2->next;
				iter = iter->next;
			}

			while (l1 != NULL) {
				iter->next = l1;
				l1 = l1->next;
				iter = iter->next;
			}

			lists[count++] = merged->next;
		}
		if (len % 2 == 0) {
			len = len / 2;
		} else {
			len = len / 2 + 1;
		}
		count = 0;
	}

	return lists[0];
}

int main() {
	vector<ListNode *> v;

	ListNode *head1, *head2, *head3, *head4, *head5, *head6, *head7;
	ListNode *curr, *temp;

	//
	// head1 = new ListNode(1);
	// curr = head1;
	// temp = new ListNode(4);
	// curr->next = temp;
	// curr = curr->next;
	// temp = new ListNode(5);
	// curr->next = temp;
	// curr = curr->next;

	// head2 = new ListNode(1);
	// curr = head2;
	// temp = new ListNode(3);
	// curr->next = temp;
	// curr = curr->next;
	// temp = new ListNode(4);
	// curr->next = temp;
	// curr = curr->next;

	// head3 = new ListNode(2);
	// curr = head3;
	// temp = new ListNode(6);
	// curr->next = temp;
	// curr = curr->next;

	//
	// head1 = new ListNode(2);

	// head2 = NULL;

	// head3 = new ListNode(-1);

	//
	// head1 = NULL;

	//
	// [[-10,-9,-9,-3,-1,-1,0],[-5],[4],[-8],[],[-9,-6,-5,-4,-2,2,3],[-3,-3,-2,-1,0]]
	head1 = new ListNode(-10);
	curr = head1;
	temp = new ListNode(-9);
	curr->next = temp;
	curr = curr->next;
	temp = new ListNode(-9);
	curr->next = temp;
	curr = curr->next;
	temp = new ListNode(-3);
	curr->next = temp;
	curr = curr->next;
	temp = new ListNode(-1);
	curr->next = temp;
	curr = curr->next;
	temp = new ListNode(-1);
	curr->next = temp;
	curr = curr->next;
	temp = new ListNode(-0);
	curr->next = temp;
	curr = curr->next;

	head2 = new ListNode(-5);

	head3 = new ListNode(4);

	head4 = new ListNode(-8);

	head5 = NULL;

	head6 = new ListNode(-9);
	curr = head6;
	temp = new ListNode(-6);
	curr->next = temp;
	curr = curr->next;
	temp = new ListNode(-5);
	curr->next = temp;
	curr = curr->next;
	temp = new ListNode(-4);
	curr->next = temp;
	curr = curr->next;
	temp = new ListNode(-2);
	curr->next = temp;
	curr = curr->next;
	temp = new ListNode(2);
	curr->next = temp;
	curr = curr->next;
	temp = new ListNode(3);
	curr->next = temp;
	curr = curr->next;

	head7 = new ListNode(-3);
	curr = head7;
	temp = new ListNode(-3);
	curr->next = temp;
	curr = curr->next;
	temp = new ListNode(-2);
	curr->next = temp;
	curr = curr->next;
	temp = new ListNode(-1);
	curr->next = temp;
	curr = curr->next;
	temp = new ListNode(0);
	curr->next = temp;
	curr = curr->next;

	v.push_back(head1);
	v.push_back(head2);
	v.push_back(head3);
	v.push_back(head4);
	v.push_back(head5);
	v.push_back(head6);
	v.push_back(head7);

	ListNode *res = mergeKLists(v);

	while (res != NULL) {
		cout << res->val << endl;
		res = res->next;
	}
}
