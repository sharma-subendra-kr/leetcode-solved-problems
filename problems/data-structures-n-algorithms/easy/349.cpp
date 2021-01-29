// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

void getMap(unordered_set<int> &s, vector<int> &arr) {
	for (int i = 0; i < arr.size(); i++) {
		s.insert(arr[i]);
	}
}

void getRes(unordered_set<int> &s, vector<int> &arr, vector<int> &res) {
	for (int i = 0; i < arr.size(); i++) {
		if (s.find(arr[i]) != s.end()) {
			s.erase(arr[i]);
			res.push_back(arr[i]);
		}
	}
}

vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
	unordered_set<int> s;
	vector<int> res;

	if (nums1.size() <= nums2.size()) {
		getMap(s, nums1);
		getRes(s, nums2, res);
	} else if (nums1.size() > nums2.size()) {
		getMap(s, nums2);
		getRes(s, nums1, res);
	}

	return res;
}

int main() {
	vector<int> nums1, nums2;

	nums1 = {1, 2, 2, 1};
	nums2 = {2, 2};

	vector<int> res = intersection(nums1, nums2);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}

	return 0;
}