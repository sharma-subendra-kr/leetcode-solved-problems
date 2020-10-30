// 350. Intersection of Two Arrays II
// https://leetcode.com/problems/intersection-of-two-arrays-ii/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
	vector<int> *large, *small, res;

	map<int, int> hmap;

	int count = 0;

	if (nums1.size() > nums2.size()) {
		large = &nums1;
		small = &nums2;
	} else {
		large = &nums2;
		small = &nums1;
	}

	for (auto iter = small->begin(); iter != small->end(); iter++) {
		auto miter = hmap.find(*iter);
		if (miter == hmap.end()) {
			hmap.insert({*iter, 1});
			count++;
		} else {
			miter->second++;
			count++;
		}
	}

	for (auto iter = large->begin(); iter != large->end(); iter++) {
		auto miter = hmap.find(*iter);
		if (miter != hmap.end() && miter->second != 0) {
			res.push_back(*iter);
			miter->second--;
		}
	}

	return res;
}

int main() {
	int nums1Size, nums2Size, i, temp;
	vector<int> nums1, nums2, res;

	cin >> nums1Size >> nums2Size;

	for (i = 0; i < nums1Size; i++) {
		cin >> temp;
		nums1.push_back(temp);
	}

	for (i = 0; i < nums2Size; i++) {
		cin >> temp;
		nums2.push_back(temp);
	}

	res = intersect(nums1, nums2);

	cout << "[";
	for (auto iter = res.begin(); iter != res.end(); iter++) {
		if (iter != res.end() - 1) {
			cout << *iter << ",";
		} else {
			cout << *iter;
		}
	}
	cout << "]";

	return 0;
}