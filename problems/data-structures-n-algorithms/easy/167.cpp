// 167. Two Sum II - Input array is sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
	unordered_map<int, int> mp;

	for (int i = 0; i < numbers.size(); i++) {
		if (mp.find(target - numbers[i]) != mp.end()) {
			vector<int> res;
			res.push_back(mp.find(target - numbers[i])->second);
			res.push_back(i + 1);
			return res;
		} else {
			mp.insert({numbers[i], i + 1});
		}
	}

	return vector<int>();
}

int main() {
	vector<int> numbers;
	int target;

	// numbers = {2, 7, 11, 15};
	// target = 9;

	numbers = {-1, 0};
	target = -1;

	vector<int> res = twoSum(numbers, target);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}

	return 0;
}