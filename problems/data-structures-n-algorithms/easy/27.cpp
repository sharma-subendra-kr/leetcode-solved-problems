// 27. Remove Element
// https://leetcode.com/problems/remove-element/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

void swap(int a, int b, vector<int> &arr) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

// Correct solution its my own but longer and no mug up needed
// int removeElement(vector<int> &nums, int val) {
// 	if (nums.size() == 0) {
// 		return 0;
// 	}

// 	int hits = 0;
// 	int low = 0;
// 	int high = nums.size() - 1;

// 	while (low <= high) {
// 		while (nums[low] != val && low < high) {
// 			low++;
// 		}

// 		if (nums[low] == val) {
// 			hits++;
// 		}

// 		while (nums[high] == val && high > low) {
// 			high--;
// 			hits++;
// 		}

// 		if (low < high) {
// 			swap(low, high, nums);
// 		}
// 		low++;
// 		high--;
// 	}

// 	return nums.size() - hits;
// }

int removeElement(vector<int> &nums, int val) {
	int left = 0;
	int count = 0;
	for (int i = nums.size() - 1; i >= 0; i--) {
		if (nums[i] != val && left < i) {
			swap(left++, i++, nums);
		} else if (nums[i] == val) {
			count++;
		}
	}

	return nums.size() - count;
}

int main() {
	vector<int> nums;
	int val;

	// nums = {3, 2, 2, 3};
	// val = 3;

	// nums = {0, 1, 2, 2, 3, 0, 4, 2};
	// val = 2;

	// nums = {};
	// val = 0;

	// nums = {2};
	// val = 3;

	nums = {1};
	val = 1;

	int res = removeElement(nums, val);

	cout << res << endl << endl;

	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << endl;
	}
	cout << endl;

	return 0;
}