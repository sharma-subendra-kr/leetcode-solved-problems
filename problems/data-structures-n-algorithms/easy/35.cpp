// 35. Search Insert Position
// https://leetcode.com/problems/search-insert-position/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <limits.h>

using namespace std;

int searchInsert(vector<int> &nums, int target) {
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] >= target) {
			return i;
		}
	}
	return nums.size();
}

int main() {
	vector<int> nums;
	int target;

	nums = {1, 3, 5, 6};
	target = 5;

	int res = searchInsert(nums, target);

	cout << res << endl;

	return 0;
}