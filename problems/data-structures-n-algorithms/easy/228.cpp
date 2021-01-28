// 228. Summary Ranges
// https://leetcode.com/problems/summary-ranges/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

vector<string> summaryRanges(vector<int> &nums) {
	vector<string> res;
	int start = 0;

	for (int i = 1; i <= nums.size(); i++) {
		if (i < nums.size() && abs((long)nums[i] - (long)nums[i - 1]) > 1) {
			if (start == i - 1) {
				res.push_back(to_string(nums[start]));
			} else {
				res.push_back(to_string(nums[start]) + "->" + to_string(nums[i - 1]));
			}
			start = i;
		} else if (i == nums.size() && start == i - 1) {
			res.push_back(to_string(nums[start]));
		} else if (i == nums.size() && start < i - 1) {
			res.push_back(to_string(nums[start]) + "->" + to_string(nums[i - 1]));
		}
	}

	return res;
}

int main() {
	vector<int> nums;

	nums = {0, 1, 2, 4, 5, 7};

	vector<string> res = summaryRanges(nums);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}

	return 0;
}