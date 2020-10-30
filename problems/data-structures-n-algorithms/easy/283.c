// 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/

#include <stdio.h>
#include <stdlib.h>

void moveZeroes(int *nums, int numsSize) {
	int i, back = -1;

	for (i = 0; i < numsSize; i++) {
		if (nums[i] == 0 && back == -1) {
			back = i;
		} else if (nums[i] != 0 && back != -1) {
			nums[back++] = nums[i];
			nums[i] = 0;
		}
	}
}

int main() {
	int *nums, numsSize, i;

	scanf("%d", &numsSize);

	nums = (int *)malloc(numsSize * sizeof(int));

	for (i = 0; i < numsSize; i++) {
		scanf("%d", &nums[i]);
	}

	moveZeroes(nums, numsSize);

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