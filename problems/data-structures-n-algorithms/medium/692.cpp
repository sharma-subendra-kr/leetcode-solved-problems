// 692. Top K Frequent Words
// https://leetcode.com/problems/top-k-frequent-words/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

// static bool compareStr(string &a, string &b) {
// 	int ia = 0, ib = 0;

// 	while (ia < a.size() && ib < b.size() && ia == ib) {
// 		ia++;
// 		ib++;
// 	}

// 	if (ia < a.size() && ib < b.size()) {
// 		if (a[ia] - 'a' < b[ib] - 'a') {
// 			return true;
// 		}
// 		return false;
// 	} else if (ia < a.size()) {
// 		return false;
// 	}
// 	return true;
// }

struct Item {
	int count;
	string word;

	Item(int count, string word) : count(count), word(word) {}
};

struct comparator {
	bool operator()(Item *a, Item *b) {
		if (a->count != b->count) {
			return a->count > b->count;
		}
		return a->word < b->word;
		// return compareStr(a->word, b->word);
	}
};

vector<string> topKFrequent(vector<string> &words, int k) {
	unordered_map<string, int> umap;
	priority_queue<Item *, vector<Item *>, comparator> pq;

	for (int i = 0; i < words.size(); i++) {
		auto iter = umap.find(words[i]);
		if (iter == umap.end()) {
			umap.insert({words[i], 1});
		} else {
			iter->second++;
		}
	}

	for (auto iter = umap.begin(); iter != umap.end(); iter++) {
		if (pq.size() < k) {
			pq.push(new Item(iter->second, iter->first));
		} else {
			pq.push(new Item(iter->second, iter->first));
			pq.pop();
		}
	}

	vector<string> res;
	while (!pq.empty()) {
		res.push_back(pq.top()->word);
		pq.pop();
	}

	reverse(res.begin(), res.end());

	return res;
}

int main() {
	//
	vector<string> words;
	int k;

	// words = {"i", "love", "leetcode", "i", "love", "coding"};
	// k = 2;
	words = {"the", "day", "is",		"sunny", "the",
					 "the", "the", "sunny", "is",		 "is"};
	k = 4;

	vector<string> res = topKFrequent(words, k);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}

	return 0;
}