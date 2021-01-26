// 31. Next Permutation
// https://leetcode.com/problems/next-permutation/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

void reverse(vector<int> &arr, int start, int end) {
	while (start <= end) {
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;

		start++;
		end--;
	}
}

void nextPermutation(vector<int> &nums) {
	int lowerIndex = -1;
	for (int i = nums.size() - 2; i >= 0; i--) {
		if (nums[i] < nums[i + 1]) {
			lowerIndex = i;
			break;
		}
	}

	if (lowerIndex >= 0) {
		int upperIndex = nums.size() - 1;
		int diff = INT_MAX;
		for (int i = nums.size() - 1; i > lowerIndex; i--) {
			if (nums[i] > nums[lowerIndex]) {
				upperIndex = i;
				break;
			}
		}
		int temp = nums[upperIndex];
		nums[upperIndex] = nums[lowerIndex];
		nums[lowerIndex] = temp;
		reverse(nums, lowerIndex + 1, nums.size() - 1);
	} else {
		// reverse array, original array is sorted descending
		reverse(nums, 0, nums.size() - 1);
	}
}

int main() {
	vector<int> nums;

	// nums = {1, 2, 3};
	// nums = {3, 2, 1};
	nums = {2, 3, 1};

	nextPermutation(nums);

	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << endl;
	}

	return 0;
}