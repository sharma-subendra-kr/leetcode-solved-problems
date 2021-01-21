// 442. Find All Duplicates in an Array
// https://leetcode.com/problems/find-all-duplicates-in-an-array/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

vector<int> findDuplicates(vector<int> &nums) {
	vector<int> res;

	for (int i = 0; i < nums.size(); i++) {
		int index = abs(nums[i]) - 1;
		if (nums[index] < 0) {
			res.push_back(abs(nums[i]));
		} else {
			nums[index] = -nums[index];
		}
	}

	return res;
}

int main() {
	vector<int> nums;

	// nums = {4, 3, 2, 7, 8, 2, 3, 1};

	nums = {10, 2, 5, 10, 9, 1, 1, 4, 3, 7};

	vector<int> res = findDuplicates(nums);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}

	return 0;
}