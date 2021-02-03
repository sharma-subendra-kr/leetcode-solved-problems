// 303. Range Sum Query - Immutable
// https://leetcode.com/problems/range-sum-query-immutable/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <stack>

using namespace std;

class NumArray {
private:
	vector<int> copy;

public:
	NumArray(vector<int> &nums) {
		int sum = 0;
		copy.push_back(sum);
		for (int i = 0; i < nums.size(); i++) {
			sum = sum + nums[i];
			copy.push_back(sum);
		}
	}

	int sumRange(int i, int j) {
		//
		return copy[j + 1] - copy[i];
	}
};

int main() {
	//
	vector<int> nums = {-2, 0, 3, -5, 2, -1};

	NumArray *na = new NumArray(nums);

	int res = na->sumRange(0, 2);

	cout << res << endl;

	return 0;
}