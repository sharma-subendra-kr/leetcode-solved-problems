// 852. Peak Index in a Mountain Array
// https://leetcode.com/problems/peak-index-in-a-mountain-array/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

int peakIndexInMountainArray(vector<int> &arr) {
	int low = 0;
	int high = arr.size() - 1;
	int mid;

	while (low <= high) {
		mid = (low + high) / 2;
		if (mid == 0) {
			low = mid + 1;
		} else if (mid == arr.size() - 1) {
			high = mid - 1;
		} else if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
			return mid;
		} else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1]) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return 0;
}

int main() {
	//
	vector<int> arr;

	// arr = {0, 1, 0};
	// arr = {0, 0, 1, 0};
	// arr = {0, 2, 1, 0};
	// arr = {0, 10, 5, 2};
	// arr = {3, 4, 5, 1};
	// arr = {24, 69, 100, 99, 79, 78, 67, 36, 26, 19};
	arr = {3, 5, 3, 2, 0};

	int index = peakIndexInMountainArray(arr);

	cout << index << endl;

	return 0;
}