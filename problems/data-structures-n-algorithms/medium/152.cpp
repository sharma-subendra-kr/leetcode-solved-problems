// 152. Maximum Product Subarray
// https://leetcode.com/problems/maximum-product-subarray/

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// int maxProduct(vector<int> &nums) {
// 	int prod = nums[nums.size() - 1];
// 	int MAX = prod;
// 	for (int i = nums.size() - 2; i >= 0; i--) {
// 		prod = max({nums[i], nums[i] * nums[i + 1], nums[i] * prod});
// 		if (prod > MAX) {
// 			MAX = prod;
// 		}
// 	}
// 	return MAX;
// }

int maxProduct(vector<int> &nums) {
	int leftProd = 0;
	int rightProd = 0;
	int MAX = INT_MIN;
	int size = nums.size() - 1;
	for (int i = 0; i < nums.size(); i++) {
		leftProd = (leftProd ? leftProd : 1) * nums[i];
		rightProd = (rightProd ? rightProd : 1) * nums[size - i];

		MAX = max({MAX, leftProd, rightProd});
	}

	return MAX;
}

int main() {

	// vector<int> nums = {2, 3, -2, 4};
	// vector<int> nums = {-2, 0, -1};
	// vector<int> nums = {-3, -1, -1};
	// vector<int> nums = {0, 2};
	// vector<int> nums = {-2, 3, -4};
	// vector<int> nums = {-1, -2, -9, -6};
	// vector<int> nums = {3, -2, -3, -3, 1, 3, 0};
	vector<int> nums = {3, -2, -3, 3, -1, 0, 1};

	int res = maxProduct(nums);

	cout << res << endl;

	return 0;
}