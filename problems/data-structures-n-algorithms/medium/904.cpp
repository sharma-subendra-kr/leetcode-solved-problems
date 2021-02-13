// 904. Fruit Into Baskets
// https://leetcode.com/problems/fruit-into-baskets/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

int getOther(unordered_map<int, int> &umap, int key) {
	for (auto iter = umap.begin(); iter != umap.end(); iter++) {
		if (iter->first != key) {
			return iter->first;
		}
	}
	return -1;
}

int totalFruit(vector<int> &tree) {
	unordered_map<int, int> umap;
	int sum = 0;
	int MAX = 0;

	for (int i = 0; i < tree.size(); i++) {
		if (umap.size() == 2 && umap.find(tree[i]) == umap.end()) {
			auto iter = umap.find(tree[i - 1]);
			int fruit = iter->first;
			int fruitIndex = iter->second;
			int otherKey = getOther(umap, fruit);
			int index = umap.find(otherKey)->second + 1;
			umap.clear();
			umap.insert({fruit, (fruitIndex > index ? fruitIndex : index)});
			umap.insert({tree[i], i});
			sum = i - index + 1;
			MAX = max(sum, MAX);
			// index - previous index + one
			continue;
		} else if (umap.size() < 2) {
			umap.insert({tree[i], i});
		}
		umap.find(tree[i])->second = i;
		sum++;
		MAX = max(sum, MAX);
	}

	return MAX;
}

int main() {
	//
	vector<int> tree;

	// tree = {1, 2, 1};
	// tree = {0, 1, 2, 2};
	// tree = {1, 2, 3, 2, 2};
	// tree = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
	// tree = {0, 1, 6, 6, 4, 4, 6};
	tree = {6, 2, 1, 1, 3, 6, 6};

	int res = totalFruit(tree);

	cout << res << endl;

	return 0;
}