// 485. Max Consecutive Ones
// https://leetcode.com/problems/max-consecutive-ones/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

// int findMaxConsecutiveOnes(vector<int> &nums) {
// 	//
// 	int curr = 0;
// 	int max = 0;
// 	int tempMax = 0;
// 	for (int i = 0; i < nums.size(); i++) {
// 		if (nums[i] == 0) {
// 			max = tempMax > max ? tempMax : max;
// 			curr = 0;
// 			tempMax = 0;
// 			continue;
// 		}
// 		curr++;
// 		tempMax++;
// 	}
// 	return tempMax > max ? tempMax : max;
// }

int findMaxConsecutiveOnes(vector<int> &nums) {
	//
	int curr = 0;
	int max = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 1) {
			curr++;
			max = curr > max ? curr : max;
		} else {
			curr = 0;
		}
	}
	return max;
}

int main() {
	//
	vector<int> nums;

	// nums = {1, 1, 0, 1, 1, 1};
	nums = {1, 0, 1, 1, 0, 1};
	nums = {1, 1, 0, 1};

	int res = findMaxConsecutiveOnes(nums);

	cout << res << endl;

	return 0;
}