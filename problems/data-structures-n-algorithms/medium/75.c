// 75. Sort Colors
// https://leetcode.com/problems/sort-colors/

#include <stdio.h>
#include <stdlib.h>

void swap(int *nums, int a, int b) {
	int temp;

	temp = nums[a];
	nums[a] = nums[b];
	nums[b] = temp;
}

void sortColors(int *nums, int numsSize) {
	int i = 0, j = 0, k = numsSize - 1;
	int mid = 1;

	while (j <= k) {
		if (nums[j] < mid) {
			swap(nums, i, j);
			i++;
			j++;
		} else if (nums[j] > mid) {
			swap(nums, j, k);
			k--;
		} else {
			j++;
		}
	}
}

int main() {
	int nums[3] = {2, 0, 1};
	int numsSize = 3;
	int i;

	sortColors(nums, numsSize);

	for (i = 0; i < numsSize; i++) {
		printf("%d ", nums[i]);
	}

	return 0;
}