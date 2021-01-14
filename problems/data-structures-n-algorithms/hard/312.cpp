// 312. Burst Balloons
// https://leetcode.com/problems/burst-balloons/

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

int burst(int *vnums, int left, int right, int **cache) {
	if (left + 1 == right)
		return 0;

	if (cache[left][right] > 0) {
		return cache[left][right];
	}

	int _max = INT_MIN;
	for (int i = left + 1; i < right; i++) {
		_max = max({_max, vnums[left] * vnums[i] * vnums[right] +
													burst(vnums, left, i, cache) +
													burst(vnums, i, right, cache)});
		cache[left][right] = _max;
	}

	return _max;
}

int maxCoins(vector<int> &nums) {
	int n = 0;
	int *vnums = new int[nums.size() + 2];
	vnums[n++] = 1;

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > 0) {
			vnums[n++] = nums[i];
		}
	}
	vnums[n++] = 1;

	int **cache = new int *[n];
	for (int i = 0; i < n; i++) {
		cache[i] = new int[n]{0};
	}

	return burst(vnums, 0, n - 1, cache);
}

int main() {
	vector<int> nums;

	nums = {3, 1, 5, 8};

	int res = maxCoins(nums);

	cout << res << endl;

	return 0;
}