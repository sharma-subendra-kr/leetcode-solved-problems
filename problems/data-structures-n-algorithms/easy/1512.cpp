// 1512. Number of Good Pairs
// https://leetcode.com/problems/number-of-good-pairs/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

int numIdenticalPairs(vector<int> &nums) {
	int mp[101] = {0};
	int res = 0;

	for (int i : nums) {
		if (mp[i] > 0) {
			res = res + mp[i];
		}
		mp[i]++;
	}

	return res;
}

int main() {
	vector<int> nums;

	nums = {1, 2, 3, 1, 1, 3};

	int res = numIdenticalPairs(nums);

	cout << res << endl;

	return 0;
}