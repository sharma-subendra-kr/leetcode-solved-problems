// 448. Find All Numbers Disappeared in an Array
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

// vector<int> findDisappearedNumbers(vector<int> &nums) {
// 	vector<int> resTemp(nums.size(), 0);
// 	vector<int> res;

// 	for (int i = 0; i < nums.size(); i++) {
// 		resTemp[nums[i] - 1] = nums[i];
// 	}

// 	for (int i = 0; i < resTemp.size(); i++) {
// 		if (resTemp[i] == 0) {
// 			res.push_back(i + 1);
// 		}
// 	}

// 	return res;
// }

vector<int> findDisappearedNumbers(vector<int> &nums) {
	vector<int> res;

	for (int i = 0; i < nums.size(); i++) {
		int index = abs(nums[i]) - 1;
		nums[index] = nums[index] > 0 ? -nums[index] : nums[index];
	}

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > 0) {
			res.push_back(i + 1);
		}
	}

	return res;
}

int main() {
	vector<int> nums;

	nums = {4, 3, 2, 7, 8, 2, 3, 1};

	vector<int> res = findDisappearedNumbers(nums);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}

	return 0;
}