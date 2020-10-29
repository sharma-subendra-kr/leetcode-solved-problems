// 189. Rotate Array
// https://leetcode.com/problems/rotate-array/

#include <stdio.h>
#include <stdlib.h>

void reverse(int *nums, int start, int end) {
	int temp;
	while (start < end) {
		temp = nums[start];
		nums[start] = nums[end];
		nums[end] = temp;
		start++;
		end--;
	}
}

void rotate(int *nums, int numsSize, int k) {
	if (k > numsSize) {
		k = k % numsSize;
	}

	reverse(nums, 0, numsSize - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k, numsSize - 1);
}

int main() {
	int *nums, numsSize, k, i;

	scanf("%d", &numsSize);

	nums = (int *)malloc(sizeof(int) * numsSize);

	scanf("%d", &k);

	for (i = 0; i < numsSize; i++) {
		scanf("%d", &nums[i]);
	}

	rotate(nums, numsSize, k);

	for (i = 0; i < numsSize; i++) {
		if (i != numsSize - 1) {
			printf("%d,", nums[i]);
		} else {
			printf("%d", nums[i]);
		}
	}

	free(nums);
}