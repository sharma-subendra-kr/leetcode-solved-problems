// 268. Missing Number
// https://leetcode.com/problems/missing-number/

#include <stdio.h>
#include <stdlib.h>

// int missingNumber(int *nums, int numsSize) {
// 	int sum = 0, supposedSum = 0;

// 	int i = 0;

// 	for (i = 0; i < numsSize; i++) {
// 		sum += nums[i];
// 	}

// 	supposedSum = numsSize * (numsSize + 1) / 2;

// 	return supposedSum - sum;
// }

int missingNumber(int *nums, int numsSize) {
	int i = 0;
	int xor = numsSize;

	for (i = 0; i < numsSize; i++) {
		xor = xor^i ^ nums[i];
	}

	return xor;
}

int main() {
	int *nums, numsSize;
	int i, res;

	scanf("%d", &numsSize);

	nums = (int *)malloc(sizeof(int) * numsSize);

	for (i = 0; i < numsSize; i++) {
		scanf("%d", &nums[i]);
	}

	res = missingNumber(nums, numsSize);

	printf("%d", res);

	return 0;
}