// 137. Single Number II
// https://leetcode.com/problems/single-number-ii/

#include <stdio.h>
#include <stdlib.h>

int singleNumber(int *nums, int numsSize) {
	int i;
	int x2 = 0, x1 = 0, mask = 0;
	for (i = 0; i < numsSize; i++) {
		x2 = x2 ^ (x1 & nums[i]);
		x1 = x1 ^ nums[i];

		mask = ~(x2 & x1);

		x2 = x2 & mask;
		x1 = x1 & mask;
	}

	return x1;
}

int main() {
	int *nums, numsSize, i, res;

	scanf("%d", &numsSize);

	nums = (int *)malloc(sizeof(int) * numsSize);

	for (i = 0; i < numsSize; i++) {
		scanf("%d", &nums[i]);
	}

	res = singleNumber(nums, numsSize);

	printf("%d\n", res);

	free(nums);
}