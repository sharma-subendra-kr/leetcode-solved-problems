// 239. Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/

#include <deque>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
	deque<int> q;
	vector<int> res;

	for (int i = 0; i < nums.size(); i++) {
		if (!q.empty() && q.front() < i - k + 1) {
			q.pop_front();
		}

		while (!q.empty() && nums[q.back()] < nums[i]) {
			q.pop_back();
		}

		q.push_back(i);

		if (i >= k - 1) {
			res.push_back(nums[q.front()]);
		}
	}

	return res;
}

int main() {
	// vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
	// vector<int> nums = {1};
	// vector<int> nums = {1, -1};
	// vector<int> nums = {9, 11};
	vector<int> nums = {4, -2};
	int k = 2;

	vector<int> res = maxSlidingWindow(nums, k);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
}