// 334. Increasing Triplet Subsequence
// https://leetcode.com/problems/increasing-triplet-subsequence/

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool increasingTriplet(int *nums, int numsSize) {
	int i;
	int c1 = INT_MAX, c2 = INT_MAX; // candidate 1 , candidate2

	for (i = 0; i < numsSize; i++) {
		if (nums[i] < c1) {
			c1 = nums[i];
		} else if (nums[i] > c1 && nums[i] <= c2) {
			c2 = nums[i];
		} else if (c2 < nums[i]) {
			return true;
		}
	}
	return false;
}

int main() {
	int *nums, numsSize, i;
	bool flag;

	scanf("%d", &numsSize);

	nums = (int *)malloc(sizeof(int) * numsSize);

	for (i = 0; i < numsSize; i++) {
		scanf("%d", &nums[i]);
	}

	flag = increasingTriplet(nums, numsSize);

	printf("%d", flag);

	return 0;
}