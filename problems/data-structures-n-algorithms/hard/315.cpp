// 315. Count of Smaller Numbers After Self
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <numeric>

using namespace std;

// This method only works when there are no duplicates
// void merge(vector<int> &nums, int low, int mid, int high,
// 					 unordered_map<int, int> &indexMap, vector<int> &res) {
// 	vector<int> helper;

// 	int il = low;
// 	int ir = mid + 1;
// 	int inverseCount = 0;

// 	while (il <= mid && ir <= high) {
// 		if (nums[il] <= nums[ir]) {
// 			helper.push_back(nums[il]);
// 			auto iter = indexMap.find(nums[il]);
// 			res[iter->second] += inverseCount;
// 			il++;
// 		} else {
// 			helper.push_back(nums[ir]);
// 			ir++;
// 			inverseCount++;
// 		}
// 	}

// 	while (il <= mid) {
// 		helper.push_back(nums[il]);
// 		auto iter = indexMap.find(nums[il]);
// 		res[iter->second] += inverseCount;
// 		il++;
// 	}

// 	while (ir <= high) {
// 		helper.push_back(nums[ir]);
// 		ir++;
// 	}

// 	move(helper.begin(), helper.end(), nums.begin() + low);
// }

// void mergeSort(vector<int> &nums, int low, int high,
// 							 unordered_map<int, int> &indexMap, vector<int> &res) {
// 	if (low < high) {
// 		int mid = (low + high) / 2;
// 		mergeSort(nums, low, mid, indexMap, res);
// 		mergeSort(nums, mid + 1, high, indexMap, res);
// 		merge(nums, low, mid, high, indexMap, res);
// 	}
// }

// vector<int> countSmaller(vector<int> &nums) {
// 	unordered_map<int, int> indexMap;
// 	vector<int> res(nums.size(), 0);

// 	for (int i = 0; i < nums.size(); i++) {
// 		if (indexMap.find(nums[i]) == indexMap.end()) {
// 			indexMap.insert({nums[i], i});
// 		}
// 	}

// 	mergeSort(nums, 0, nums.size() - 1, indexMap, res);

// 	return res;
// }

void merge(vector<int> &nums, int low, int mid, int high, vector<int> &indexMap,
					 vector<int> &res) {
	vector<int> helper;

	int il = low;
	int ir = mid + 1;
	int inverseCount = 0;

	while (il <= mid && ir <= high) {
		if (nums[indexMap[il]] <= nums[indexMap[ir]]) {
			helper.push_back(indexMap[il]);
			res[indexMap[il]] += inverseCount;
			il++;
		} else {
			helper.push_back(indexMap[ir]);
			ir++;
			inverseCount++;
		}
	}

	while (il <= mid) {
		helper.push_back(indexMap[il]);
		res[indexMap[il]] += inverseCount;
		il++;
	}

	while (ir <= high) {
		helper.push_back(indexMap[ir]);
		ir++;
	}

	move(helper.begin(), helper.end(), indexMap.begin() + low);
}

void mergeSort(vector<int> &nums, int low, int high, vector<int> &indexMap,
							 vector<int> &res) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergeSort(nums, low, mid, indexMap, res);
		mergeSort(nums, mid + 1, high, indexMap, res);
		merge(nums, low, mid, high, indexMap, res);
	}
}

vector<int> countSmaller(vector<int> &nums) {
	vector<int> indexMap(nums.size(), 0);
	vector<int> res(nums.size(), 0);

	iota(indexMap.begin(), indexMap.end(), 0);

	mergeSort(nums, 0, nums.size() - 1, indexMap, res);

	return res;
}

int main() {
	vector<int> nums;

	nums = {5, 2, 6, 1};
	// nums = {-1, -2};
	// nums = {2, 0, 1};

	vector<int> res = countSmaller(nums);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;
}