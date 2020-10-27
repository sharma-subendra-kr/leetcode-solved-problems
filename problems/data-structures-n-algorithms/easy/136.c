// 136. Single Number
// https://leetcode.com/problems/single-number/

#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize) {
  int i;
  int count = 0;
  for (i = 0; i < numsSize; i++) {
    count = count ^ nums[i];
  }
  return count;
}

int main() {
  int *nums, numsSize, i, res;

  scanf("%d", &numsSize);

  nums = (int*)malloc(sizeof(int) * numsSize);

  for (i = 0; i < numsSize; i++) {
    scanf("%d", &nums[i]);
  }

  res = singleNumber(nums, numsSize);

  printf("%d\n", res);

  free(nums);
}