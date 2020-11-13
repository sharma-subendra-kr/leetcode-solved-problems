// 384. Shuffle an Array
// https://leetcode.com/problems/shuffle-an-array/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *arr, *dup;
	int size;
} Solution;

Solution *solutionCreate(int *nums, int numsSize) {
	int i;
	Solution *solution = (Solution *)malloc(sizeof(Solution));
	solution->arr = nums;
	solution->size = numsSize;

	solution->dup = (int *)malloc(sizeof(int) * numsSize);
	for (i = 0; i < numsSize; i++) {
		solution->dup[i] = nums[i];
	}

	return solution;
}

/** Resets the array to its original configuration and return it. */
int *solutionReset(Solution *obj, int *retSize) {
	*retSize = obj->size;
	return obj->arr;
}

/** Returns a random shuffling of the array. */
int *solutionShuffle(Solution *obj, int *retSize) {
	int i, random, temp;
	*retSize = obj->size;

	for (i = 0; i < *retSize; i++) {
		random = rand() % obj->size;
		temp = obj->dup[i];
		obj->dup[i] = obj->dup[random];
		obj->dup[random] = temp;
	}

	return obj->dup;
}

void solutionFree(Solution *obj) { free(obj); }

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);

 * int* param_2 = solutionShuffle(obj, retSize);

 * solutionFree(obj);
*/

int main() {
	int *nums, numsSize, retSize;
	int i;

	scanf("%d", &numsSize);
	nums = (int *)malloc(sizeof(int) * numsSize);
	for (i = 0; i < numsSize; i++) {
		scanf("%d", &nums[i]);
	}

	Solution *obj = solutionCreate(nums, numsSize);
	int *param_1 = solutionShuffle(obj, &retSize);
	for (i = 0; i < numsSize; i++) {
		printf("%d ", param_1[i]);
	}
	printf("\n ");
	int *param_2 = solutionReset(obj, &retSize);
	for (i = 0; i < numsSize; i++) {
		printf("%d ", param_2[i]);
	}
	printf("\n ");
	int *param_3 = solutionShuffle(obj, &retSize);
	for (i = 0; i < numsSize; i++) {
		printf("%d ", param_3[i]);
	}
	printf("\n ");

	return 0;
}