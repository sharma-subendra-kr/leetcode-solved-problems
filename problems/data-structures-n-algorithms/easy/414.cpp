// 414. Third Maximum Number
// https://leetcode.com/problems/third-maximum-number/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

int thirdMax(vector<int> &nums) {
	int max3 = INT_MIN;
	int max2 = INT_MIN;
	int max1 = INT_MIN;
	int size = nums.size();
	int countMin = 0;
	int num;
	for (int i = 0; i < nums.size(); i++) {
		num = nums[i];
		if (num == INT_MIN && countMin == 1) {
			size--;
			continue;
		}
		if (num == INT_MIN && countMin == 0) {
			countMin++;
		}
		if ((num == max3 || num == max2 || num == max1) && num != INT_MIN) {
			size--;
			continue;
		}

		if (num > max3 && num > max2 && num > max1) {
			max1 = max2;
			max2 = max3;
			max3 = num;
		} else if (num > max2 && num > max1) {
			max1 = max2;
			max2 = num;
		} else if (num > max1) {
			max1 = num;
		}
	}

	if (size < 3) {
		return max({max3, max2, max1});
	} else {
		return min({max3, max2, max1});
	}
}

int main() {
	vector<int> arr;

	arr = {3, 2, 1};
	// arr = {2, 1};
	// arr = {2, 2, 3, 1};
	// arr = {5, 2, 2};
	// arr = {1, 2, 2, 5, 3, 5};
	// arr = {1, 2, -2147483648};
	// arr = {-2147483648, -2147483648, -2147483648, -2147483648, 1, 1, 1};

	int res = thirdMax(arr);

	cout << res;

	return 0;
}