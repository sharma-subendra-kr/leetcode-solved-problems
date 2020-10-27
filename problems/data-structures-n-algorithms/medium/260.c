// 260. Single Number III
// https://leetcode.com/problems/single-number-iii/

#include <stdio.h>
#include <stdlib.h>

int singleNumber(int *nums, int numsSize, int *returnSize) {}

int main() {
	int *nums, numsSize, returnSize[2], i, res;

	scanf("%d", &numsSize);

	nums = (int *)malloc(sizeof(int) * numsSize);

	for (i = 0; i < numsSize; i++) {
		scanf("%d", &nums[i]);
	}

	singleNumber(nums, numsSize, returnSize);

	printf("%d, %d\n", returnSize[0], returnSize[1]);

	free(nums);
}