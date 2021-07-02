// 1313. Decompress Run-Length Encoded List
// https://leetcode.com/problems/decompress-run-length-encoded-list/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

vector<int> decompressRLElist(vector<int> &nums) {
	//
	vector<int> res;
	for (int i = 0; i < nums.size() - 1; i += 2) {
		int freq = nums[i];
		int val = nums[i + 1];

		for (int j = 0; j < freq; j++) {
			res.push_back(val);
		}
	}
	return res;
}

int main() {
	//
	vector<int> arr;
	arr = {1, 2, 3, 4};
	arr = {1, 1, 2, 3};

	vector<int> res = decompressRLElist(arr);

	for (auto i : res) {
		cout << i << endl;
	}

	return 0;
}