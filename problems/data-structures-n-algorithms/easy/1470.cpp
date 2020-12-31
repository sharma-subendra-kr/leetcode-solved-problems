// 1470. Shuffle the Array
// https://leetcode.com/problems/shuffle-the-array/

#include <iostream>
#include <vector>

using namespace std;

// extra memory solution
// vector<int> shuffle(vector<int> &nums, int n) {
// 	vector<int> res;
// 	res.push_back(nums[0]);

// 	int l = 1;
// 	int r = n;
// 	for (int i = 1; i <= 2 * n - 2; i++) {
// 		res.push_back(i % 2 == 1 ? nums[r++] : nums[l++]);
// 	}

// 	res.push_back(nums[2 * n - 1]);

// 	return res;
// }

// inplace solution
int getDesiredIndex(int i, int n) {
	if (i < n) {
		return 2 * i;
	} else {
		return i - (2 * n - 1 - i);
	}
}

vector<int> shuffle(vector<int> &nums, int n) {
	int next;

	for (int i = 1; i < 2 * n - 1; i++) {
		int j = i;
		int temp = nums[j];
		while (nums[getDesiredIndex(j, n)] > 0) {
			int di = getDesiredIndex(j, n);
			next = nums[di];
			nums[di] = -temp;
			temp = next;
			j = di;
		}
	}

	for (int i = 1; i < 2 * n - 1; i++) {
		nums[i] = -nums[i];
	}

	return nums;
}

int main() {
	int n;
	vector<int> nums;

	nums = {2, 5, 1, 3, 4, 7};
	n = 3;
	// nums = {1, 2, 3, 3, 2, 1};
	// n = 3;
	// nums = {1, 2, 3, 4, 4, 3, 2, 1};
	// n = 4;
	// nums = {1, 1, 2, 2};
	// n = 2;

	vector<int> res = shuffle(nums, n);

	for (int i = 0; i < 2 * n; i++) {
		cout << res[i] << " ";
	}
}