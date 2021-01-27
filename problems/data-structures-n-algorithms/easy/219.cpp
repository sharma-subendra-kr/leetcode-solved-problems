// 219. Contains Duplicate II
// https://leetcode.com/problems/contains-duplicate-ii/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k) {
	unordered_map<int, int> mp;

	for (int i = 0; i < nums.size(); i++) {
		auto iter = mp.find(nums[i]);
		if (iter != mp.end()) {
			if (iter->first == nums[i] && i - iter->second <= k) {
				return true;
			} else if (iter->first == nums[i] && i - iter->second > k) {
				iter->second = i;
			}
		} else {
			mp.insert({nums[i], i});
		}
	}

	return false;
}

int main() {
	vector<int> nums;
	int k;

	nums = {1, 2, 3, 1};
	k = 3;

	bool res = containsNearbyDuplicate(nums, k);

	cout << res << endl;

	return 0;
}