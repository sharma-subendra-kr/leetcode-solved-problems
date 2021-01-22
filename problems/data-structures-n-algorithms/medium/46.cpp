// 46. Permutations
// https://leetcode.com/problems/permutations/

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

// vector<vector<int>> dfs(vector<int> &nums, int start) {
// 	vector<vector<int>> res;

// 	if (start == nums.size() - 1) {
// 		vector<int> val(1, nums[start]);
// 		return vector<vector<int>>(1, val);
// 	}

// 	for (int i = start; i < nums.size(); i++) {
// 		if (i != nums.size() - 1) {
// 			swap(start, i + 1, nums);
// 		}
// 		vector<vector<int>> temp = dfs(nums, start + 1);
// 		for (int j = 0; j < temp.size(); j++) {
// 			temp[j].push_back(nums[start]);
// 			res.push_back(temp[j]);
// 		}
// 		if (i != nums.size() - 1) {
// 			swap(i + 1, start, nums);
// 		}
// 	}

// 	return res;
// }

// vector<vector<int>> permute(vector<int> &nums) { return dfs(nums, 0); }

void dfs(vector<int> nums, int start, vector<vector<int>> &res) {
	if (start == nums.size()) {
		res.push_back(nums);
	}

	for (int i = start; i < nums.size(); i++) {
		swap(start, i, nums);

		dfs(vector<int>(nums.begin(), nums.end()), start + 1, res);
	}
}

vector<vector<int>> permute(vector<int> &nums) {
	vector<vector<int>> res;
	dfs(nums, 0, res);
	return res;
}

int main() {
	vector<int> nums;

	nums = {1, 2, 3};

	vector<vector<int>> res = permute(nums);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}