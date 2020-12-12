// 128. Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int longestConsecutive(vector<int> &nums) {
	map<int, int> mp;
	int max = 0;

	for (int i = 0; i < nums.size(); i++) {
		mp.insert({nums[i], 0});
	}

	for (int i = 0; i < nums.size(); i++) {
		int item = nums[i];
		int _item = item;

		auto _iter = mp.find(_item);
		auto iter = mp.find(item);
		if (iter->second != 0) {
			continue;
		}

		int count = 0;
		while (iter->second == 0 && iter != mp.end()) {
			iter->second = 1;
			count++;
			item++;
			iter = mp.find(item);
		}

		_iter->second = count + (iter == mp.end() ? 0 : iter->second);

		if (max < _iter->second) {
			max = _iter->second;
		}
	}

	return max;
}

int main() {
	// vector<int> arr = {100, 4, 200, 1, 3, 2};
	// vector<int> arr = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
	// vector<int> arr = {0, 0};
	vector<int> arr = {0, -1};
	int res = longestConsecutive(arr);
	cout << res;
	return 0;
}