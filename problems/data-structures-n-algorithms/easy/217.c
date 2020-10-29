// 217. Contains Duplicate
// https://leetcode.com/problems/contains-duplicate/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {

	int _a = *((int *)a);
	int _b = *((int *)b);

	if (_a > _b) {
		return 1;
	} else if (_a < _b) {
		return -1;
	} else {
		return 0;
	}
}

bool containsDuplicate(int *nums, int numsSize) {
	int i;

	qsort(nums, numsSize, sizeof(*nums), comp);

	for (i = 0; i < numsSize - 1; i++) {
		if (nums[i] == nums[i + 1]) {
			return true;
		}
	}
	return false;
}

int main() {
	int *nums, numsSize, i;
	bool cd;

	scanf("%d", &numsSize);

	nums = (int *)malloc(sizeof(int) * numsSize);

	for (i = 0; i < numsSize; i++) {
		scanf("%d", &nums[i]);
	}

	cd = containsDuplicate(nums, numsSize);

	if (cd == true) {
		printf("true");
	} else {
		printf("false");
	}

	free(nums);
}