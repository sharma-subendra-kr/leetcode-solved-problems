// 1089. Duplicate Zeros
// https://leetcode.com/problems/duplicate-zeros/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

void duplicateZeros(vector<int> &arr) {
	//
	int countZero = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == 0) {
			countZero++;
		}
	}

	int i = arr.size() - 1;
	int j = arr.size() - 1 + countZero;

	while (i != j && i > 0) {
		if (j < arr.size()) {
			arr[j] = arr[i];
		}
		if (arr[i] == 0) {
			j--;
		} else {
			arr[i] = 0;
		}
		i--;
		j--;
	}
}

int main() {
	//
	vector<int> arr;
	// arr = {1, 0, 2, 3, 0, 4, 5, 0};
	// arr = {1, 2, 3};
	arr = {0, 0, 0, 0, 0, 0, 0};

	duplicateZeros(arr);

	for (int i : arr) {
		cout << i << endl;
	}

	return 0;
}