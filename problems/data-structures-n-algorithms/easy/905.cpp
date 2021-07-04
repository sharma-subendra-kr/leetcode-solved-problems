// 905. Sort Array By Parity
// https://leetcode.com/problems/sort-array-by-parity/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

vector<int> sortArrayByParity(vector<int> &nums) {
	//
	int left = 0;
	int right = nums.size() - 1;
	int temp;
	while (left < right) {
		if ((nums[left] & 1) == true && (nums[right] & 1) == false) {
			temp = nums[left];
			nums[left] = nums[right];
			nums[right] = temp;
			left++;
			right--;
		}
		if ((nums[left] & 1) == false) {
			left++;
		}
		if ((nums[right] & 1) == true) {
			right--;
		}
	}
	return nums;
}

int main() {
	//
	vector<int> nums;

	nums = {3, 1, 2, 4};

	vector<int> res = sortArrayByParity(nums);

	for (int i : res) {
		cout << i << endl;
	}

	return 0;
}