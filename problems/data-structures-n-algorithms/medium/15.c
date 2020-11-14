// 15. 3Sum
// https://leetcode.com/problems/3sum/

#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {

	int _a = *((int *)a);
	int _b = *((int *)b);

	if (_a > _b) {
		return 1;
	} else if (_a < _b) {
		return -1;
	}
	return 0;
}

int **threeSum(int *nums, int numsSize, int *returnSize,
							 int **returnColumnSizes) {
	int **res, i, low, high, sum, len = numsSize;
	*returnSize = 0;

	qsort(nums, numsSize, sizeof(int), comp);

	res = (int **)malloc(sizeof(int *) * numsSize);
	*returnColumnSizes = (int *)malloc(sizeof(int) * numsSize);

	for (i = 0; i < numsSize - 2; i++) {
		low = i + 1;
		high = numsSize - 1;

		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		while (low < high) {
			sum = nums[i] + nums[low] + nums[high];
			if (sum < 0) {
				low++;
			} else if (sum > 0) {
				high--;
			} else {
				if (*returnSize == len) {
					len *= 2;
					res = (int **)realloc(res, sizeof(int *) * len);
					*returnColumnSizes =
							(int *)realloc(*returnColumnSizes, sizeof(int) * len);
				}

				res[*returnSize] = (int *)malloc(sizeof(int) * 3);
				res[*returnSize][0] = nums[i];
				res[*returnSize][1] = nums[low];
				res[*returnSize][2] = nums[high];
				(*returnColumnSizes)[*returnSize] = 3;
				(*returnSize)++;

				while (low < high && nums[low] == nums[low + 1]) {
					low++;
				}

				while (low < high && nums[high] == nums[high - 1]) {
					high--;
				}

				low++;
				high--;
			}
		}
	}

	return res;
}

int main() {
	int *nums, numsSize, returnSize, *returnColumnSizes;
	int i, j, **arr;

	scanf("%d", &numsSize);

	nums = (int *)malloc(sizeof(int) * numsSize);

	for (i = 0; i < numsSize; i++) {
		scanf("%d", &nums[i]);
	}

	arr = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);

	for (i = 0; i < returnSize; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}