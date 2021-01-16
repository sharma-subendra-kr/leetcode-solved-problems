// 324. Wiggle Sort II
// https://leetcode.com/problems/wiggle-sort-ii/

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void wiggleSort(vector<int> &nums) {
	vector<int> cnums(nums.begin(), nums.end());
	sort(cnums.begin(), cnums.end());

	int left = (nums.size() + 1) / 2 - 1;
	int right = nums.size() - 1;

	for (int i = 0; i < nums.size(); i++) {
		if (i % 2 == 1) {
			nums[i] = cnums[right--];
		} else {
			nums[i] = cnums[left--];
		}
	}
}

int main() {
	vector<int> nums;

	nums = {1, 5, 1, 1, 6, 4};

	wiggleSort(nums);

	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;

	return 0;
}