// 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int *nums, int numsSize) {
	int i, left = 0;

	if (numsSize == 0) {
		return 0;
	}

	for (int i = 0; i < numsSize; i++) {
		if (i == 0) {
			nums[left] = nums[i];
		} else if (nums[left] != nums[i]) {
			nums[++left] = nums[i];
		}
	}

	return left + 1;
}

int main() {
	int *nums, numsSize, i;

	scanf("%d", &numsSize);

	nums = (int *)malloc(sizeof(int) * numsSize);

	for (i = 0; i < numsSize; i++) {
		scanf("%d", &nums[i]);
	}

	removeDuplicates(nums, numsSize);

	printf("[");
	for (i = 0; i < numsSize; i++) {
		if (i != numsSize - 1) {
			printf("%d,", nums[i]);
		} else {
			printf("%d", nums[i]);
		}
	}
	printf("]\n");

	free(nums);
}