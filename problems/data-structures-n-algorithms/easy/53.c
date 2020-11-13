// 53. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/

#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int *nums, int numsSize) {
	int i = 0, max = -2147483647, sum = 0;

	for (i = 0; i < numsSize; i++) {
		if (sum > 0) {
			sum = sum + nums[i];
		} else {
			sum = nums[i];
		}

		if (sum > max) {
			max = sum;
		}
	}

	return max;
}

int main() {
	int *nums, numsSize;
	int i, res;

	scanf("%d", &numsSize);

	nums = (int *)malloc(sizeof(int) * numsSize);

	for (i = 0; i < numsSize; i++) {
		scanf("%d", &nums[i]);
	}

	res = maxSubArray(nums, numsSize);

	printf("%d", res);

	return 0;
}