// 560. Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

// Time limit exceeded
// int subarraySum(vector<int> &nums, int k) {
// 	vector<int> mp(nums.size() + 1, 0);
// 	int count = 0;
// 	mp[0] = 0;
// 	for (int i = 1; i < mp.size(); i++) {
// 		mp[i] = mp[i - 1] + nums[i - 1];
// 	}

// 	for (int i = 0; i < nums.size(); i++) {
// 		for (int j = i + 1; j <= nums.size(); j++) {
// 			if (mp[j] - mp[i] == k) {
// 				count++;
// 			}
// 		}
// 	}

// 	return count;
// }

int subarraySum(vector<int> &nums, int k) {
	unordered_map<int, int> sum;
	int count = 0;
	sum[0] = 1;
	int _sum = 0;

	for (int i = 1; i <= nums.size(); i++) {
		_sum = _sum + nums[i - 1];

		if (sum.find(_sum - k) != sum.end()) {
			count += sum.find(_sum - k)->second;
		}
		sum[_sum] = (sum.find(_sum) != sum.end() ? sum[_sum] : 0) + 1;
	}

	return count;
}

int main() {
	vector<int> nums;
	int k;

	// nums = {1, 1, 2};
	// k = 2;
	nums = {1, 1, 1};
	k = 2;
	// nums = {1};
	// k = 0;

	int res = subarraySum(nums, k);

	cout << res << endl;

	return 0;
}