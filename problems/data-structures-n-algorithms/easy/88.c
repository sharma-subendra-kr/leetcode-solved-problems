// 88. Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array/

#include <stdio.h>
#include <stdlib.h>

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
	int low, high;
	int temp;
	int i = nums1Size - m, j = 0, iter = 0;

	// revers part of the array which has numbers
	low = 0;
	high = m - 1;
	while (low < high) {
		temp = nums1[low];
		nums1[low] = nums1[high];
		nums1[high] = temp;

		low++;
		high--;
	}

	// revers entire array so that the numbers start from the (nums1Size - m)th
	// index in sorted order
	low = 0;
	high = nums1Size - 1;
	while (low < high) {
		temp = nums1[low];
		nums1[low] = nums1[high];
		nums1[high] = temp;

		low++;
		high--;
	}

	while (iter < m + n) {
		if (i < nums1Size - m + m && j < n) {
			if (nums1[i] < nums2[j]) {
				nums1[iter] = nums1[i++];
			} else {
				nums1[iter] = nums2[j++];
			}
		} else if (i < m) {
			nums1[iter] = nums1[i++];
		} else if (j < n) {
			nums1[iter] = nums2[j++];
		}
		iter++;
	}
}

int main() {
	int *nums1, *nums2;
	int nums1Size, nums2Size, m, n;
	int i;

	scanf("%d%d%d%d", &nums1Size, &m, &nums2Size, &n);

	nums1 = (int *)malloc(sizeof(int) * m);
	nums2 = (int *)malloc(sizeof(int) * n);

	for (i = 0; i < m; i++) {
		scanf("%d", &nums1[i]);
	}

	for (i = 0; i < n; i++) {
		scanf("%d", &nums2[i]);
	}

	merge(nums1, nums1Size, m, nums2, nums2Size, n);

	for (i = 0; i < n + m; i++) {
		printf("%d ", nums1[i]);
	}

	return 0;
}