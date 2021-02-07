// 163. Missing Ranges
// https://leetcode.com/problems/missing-ranges/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

void insert(int right, int left, vector<string> &res) {
	if (right - left == 2) {
		res.push_back(to_string(left + 1));
	} else {
		res.push_back(to_string(left + 1) + "->" + to_string(right - 1));
	}
}

vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
	vector<string> res;

	if (nums.size() == 0) {
		insert(upper + 1, lower - 1, res);
		return res;
	}

	int left = lower;

	if (nums[0] - left >= 1) {
		insert(nums[0], left - 1, res);
	}

	left = nums[0];

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] - left > 1) {
			insert(nums[i], left, res);
		}
		left = nums[i];
	}

	if (upper - nums[nums.size() - 1] >= 1) {
		insert(upper + 1, left, res);
	}

	return res;
}

int main() {
	//

	vector<int> nums;
	int lower, upper;

	nums = {0, 1, 3, 50, 75};
	lower = 0;
	upper = 99;

	vector<string> res = findMissingRanges(nums, lower, upper);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;
}