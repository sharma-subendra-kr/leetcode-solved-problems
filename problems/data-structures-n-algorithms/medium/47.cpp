// 47. Permutations II
// https://leetcode.com/problems/permutations-ii/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

void swap(int a, int b, vector<int> &arr) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void dfs(vector<int> nums, int start, vector<vector<int>> &res) {
	if (start == nums.size()) {
		res.push_back(nums);
	}

	for (int i = start; i < nums.size(); i++) {
		if (nums[start] == nums[i] && start != i) {
			continue;
		}

		swap(start, i, nums);

		dfs(vector<int>(nums.begin(), nums.end()), start + 1, res);
	}
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
	vector<vector<int>> res;

	sort(nums.begin(), nums.end());

	dfs(nums, 0, res);

	return res;
}

int main() {
	vector<int> nums;

	// nums = {1, 2, 3};
	nums = {1, 1, 2};

	vector<vector<int>> res = permuteUnique(nums);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}