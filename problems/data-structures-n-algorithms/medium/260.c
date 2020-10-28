// 260. Single Number III
// https://leetcode.com/problems/single-number-iii/

#include <stdio.h>
#include <stdlib.h>

int *singleNumber(int *nums, int numsSize, int *returnSize) {
	int i;
	int x1 = 0;
	int *res;
	*returnSize = 2;

	res = (int *)calloc(2, sizeof(int));

	for (i = 0; i < numsSize; i++) {
		x1 = x1 ^ nums[i];
	}

	x1 = x1 & -x1;

	for (i = 0; i < numsSize; i++) {
		if ((nums[i] & x1) == 0) {
			res[0] = res[0] ^ nums[i];
		} else {
			res[1] = res[1] ^ nums[i];
		}
	}

	return res;
}

int main() {
	int *nums, numsSize, returnSize, i, *res;

	scanf("%d", &numsSize);

	nums = (int *)malloc(sizeof(int) * numsSize);

	for (i = 0; i < numsSize; i++) {
		scanf("%d", &nums[i]);
	}

	res = singleNumber(nums, numsSize, &returnSize);

	printf("[");
	for (i = 0; i < returnSize; i++) {
		if (i != returnSize - 1) {
			printf("%d,", res[i]);
		} else {
			printf("%d", res[i]);
		}
	}
	printf("]\n");

	free(nums);
	free(res);
}