// 977. Squares of a Sorted Array
// https://leetcode.com/problems/squares-of-a-sorted-array/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

// not a good solution
// vector<int> sortedSquares(vector<int> &nums) {
// 	//
// 	int i = 0;
// 	while (i < nums.size() && nums[i] < 0) {
// 		i++;
// 	}
// 	if (i == nums.size() ||
// 			(i - 1 >= 0 && nums[i] * nums[i] > nums[i - 1] * nums[i - 1])) {
// 		i--;
// 	}
// 	int left = i;
// 	int right = i;
// 	vector<int> res;
// 	res.push_back(nums[i] * nums[i]);
// 	left--;
// 	right++;
// 	while (left >= 0 || right < nums.size()) {
// 		int sqLeft = INT_MIN;
// 		int sqRight = INT_MAX;
// 		if (left >= 0) {
// 			sqLeft = nums[left] * nums[left];
// 		}
// 		if (right < nums.size()) {
// 			sqRight = nums[right] * nums[right];
// 		}

// 		if (sqLeft < sqRight && sqLeft != INT_MIN) {
// 			res.push_back(sqLeft);
// 			left--;
// 		} else {
// 			res.push_back(sqRight);
// 			right++;
// 		}
// 	}

// 	return res;
// }

vector<int> sortedSquares(vector<int> &nums) {
	//
	int left = 0;
	int right = nums.size() - 1;
	vector<int> res;

	while (left <= right) {
		int sqLeft = INT_MAX;
		int sqRight = INT_MIN;
		if (left < nums.size()) {
			sqLeft = nums[left] * nums[left];
		}
		if (right >= 0) {
			sqRight = nums[right] * nums[right];
		}

		if (sqLeft > sqRight && sqLeft != INT_MAX) {
			res.push_back(sqLeft);
			left++;
		} else {
			res.push_back(sqRight);
			right--;
		}
	}
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	//
	vector<int> nums;
	// nums = {-4, -1, 0, 3, 10};
	// nums = {-7, -3, 2, 3, 11};
	// nums = {-1};
	// nums = {1};
	// nums = {};
	nums = {-1, 2, 2};

	vector<int> res = sortedSquares(nums);

	for (int i : res) {
		cout << i << endl;
	}

	return 0;
}