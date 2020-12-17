// 138. Copy List with Random Pointer
// https://leetcode.com/problems/copy-list-with-random-pointer/

#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Node {
public:
	int val;
	Node *next;
	Node *random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

Node *copyRandomList(Node *head) {
	if (head == NULL) {
		return NULL;
	}

	unordered_map<Node *, Node *> um;

	Node *curr = head;

	while (curr != NULL) {
		Node *newTemp = NULL;
		Node *newRandom = NULL;

		auto cIter = um.find(curr);
		if (cIter == um.end()) {
			newTemp = new Node(curr->val);
			um.insert({curr, newTemp});
		} else if (cIter != um.end()) {
			newTemp = cIter->second;
		}

		auto rIter = um.find(curr->random);
		if (rIter == um.end() && curr->random != NULL) {
			newRandom = new Node(curr->random->val);
			um.insert({curr->random, newRandom});
		} else if (rIter != um.end()) {
			newRandom = rIter->second;
		}

		newTemp->random = newRandom;

		Node *tempNext = curr->next;
		curr->next = newTemp;
		newTemp->next = tempNext;
		curr = tempNext;
	}

	Node *newHead = head->next;
	Node *oIter = head;
	Node *oPrev = NULL;
	Node *nIter = NULL;
	int count = 0;

	while (oIter != NULL) {
		if (count % 2 == 1) {
			if (nIter == NULL) {
				nIter = oIter;
			} else {
				nIter->next = oIter;
				nIter = nIter->next;
			}
			oPrev->next = oIter->next;
		} else {
			oPrev = oIter;
		}

		oIter = oIter->next;
		count++;
	}

	return newHead;
}

int main() {
	Node *node0 = new Node(7);
	Node *node1 = new Node(13);
	Node *node2 = new Node(11);
	Node *node3 = new Node(10);
	Node *node4 = new Node(1);

	node0->next = node1;
	node0->random = NULL;

	node1->next = node2;
	node1->random = node0;

	node2->next = node3;
	node2->random = node4;

	node3->next = node4;
	node3->random = node2;

	node4->random = node0;

	Node *res = copyRandomList(node0);

	while (res != NULL) {
		cout << "Val: " << res->val << endl;

		if (res->random != NULL) {
			cout << "Rand: " << res->random->val << endl;
		} else {
			cout << "Rand: NULL" << endl;
		}
		cout << endl;
		res = res->next;
	}
}