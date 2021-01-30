// 146. LRU Cache
// https://leetcode.com/problems/lru-cache/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

class LRUCache {
private:
	struct Cache {
		int key;
		int val;
		Cache *next;
		Cache *prev;
		Cache(int k, int v) : key(k), val(v), next(NULL), prev(NULL) {}
	};

	int capacity;
	int size;
	unordered_map<int, Cache *> mp;
	Cache *HEAD;
	Cache *TAIL;

public:
	LRUCache(int capacity) {
		this->capacity = capacity;
		size = 0;

		HEAD = NULL;
		TAIL = NULL;
	}

	int get(int key) {
		auto iter = mp.find(key);
		if (iter != mp.end()) {
			if (HEAD != TAIL && iter->second != HEAD) {
				Cache *curr = iter->second;
				Cache *prev = curr->prev;
				Cache *next = curr->next;

				curr->next = NULL;
				curr->prev = NULL;

				prev->next = next;

				if (next != NULL) {
					next->prev = prev;
				}

				curr->next = HEAD;
				HEAD->prev = curr;
				HEAD = curr;

				if (curr == TAIL) {
					TAIL = prev;
				}
			}
			return iter->second->val;
		}
		return -1;
	}

	void put(int key, int value) {
		auto iter = mp.find(key);

		if (size == capacity && iter == mp.end()) {
			Cache *temp = TAIL;
			if (TAIL != HEAD) {
				TAIL = TAIL->prev;
				TAIL->next = NULL;
			} else {
				HEAD = NULL;
				TAIL = NULL;
			}

			mp.erase(temp->key);
			delete temp;
			size--;
		}

		if (HEAD == NULL) {
			Cache *c = new Cache(key, value);
			HEAD = c;
			TAIL = c;
			mp.insert({key, c});
			size++;
		} else if (iter == mp.end()) {
			Cache *c = new Cache(key, value);
			c->next = HEAD;
			HEAD->prev = c;
			HEAD = HEAD->prev;
			mp.insert({key, c});
			size++;
		} else {
			iter->second->val = value;
			get(key);
		}
	}

	void print() {
		Cache *iter = HEAD;
		while (iter != NULL) {
			cout << iter->val << endl;
			iter = iter->next;
		}
	}
};

int main() {
	// LRUCache *lru = new LRUCache(2);

	// lru->put(1, 1);
	// lru->put(2, 2);
	// cout << lru->get(1) << endl;
	// lru->put(3, 3);
	// cout << lru->get(2) << endl;
	// lru->put(4, 4);
	// cout << lru->get(1) << endl;
	// cout << lru->get(3) << endl;
	// cout << lru->get(4) << endl;

	// cout << "*****" << endl;

	// lru->print();

	// //

	// LRUCache *lru = new LRUCache(1);

	// lru->put(2, 1);
	// cout << lru->get(2) << endl;
	// lru->put(3, 2);
	// cout << lru->get(2) << endl;
	// cout << lru->get(3) << endl;

	// cout << "*****" << endl;

	// lru->print();

	//

	LRUCache *lru = new LRUCache(2);

	lru->put(2, 1);
	lru->put(1, 1);
	lru->put(2, 3);
	lru->put(4, 1);
	cout << lru->get(1) << endl;
	cout << lru->get(2) << endl;

	cout << "*****" << endl;

	lru->print();

	return 0;
}