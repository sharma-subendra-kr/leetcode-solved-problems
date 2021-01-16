// 215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int findKthLargest(vector<int> &nums, int k) {
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < k; i++) {
		pq.push(nums[i]);
	}

	for (int i = k; i < nums.size(); i++) {
		int top = pq.top();
		if (top < nums[i]) {
			pq.push(nums[i]);
			pq.pop();
		}
	}

	return pq.top();
}

int main() {
	vector<int> nums;
	int k;

	nums = {3, 2, 1, 5, 6, 4};
	k = 2;

	int res = findKthLargest(nums, k);

	cout << res << endl;

	return 0;
}