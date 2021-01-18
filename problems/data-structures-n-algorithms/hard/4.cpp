// 4. Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
	int totalSize = nums1.size() + nums2.size();

	if (totalSize == 0) {
		return -1;
	}

	if (nums1.size() > nums2.size()) {
		return findMedianSortedArrays(nums2, nums1);
	}

	int aMinCount = 0;
	int aMaxCount = nums1.size();
	int lefthalfLength = (nums1.size() + nums2.size() + 1) / 2;

	while (aMinCount <= aMaxCount) {
		int aCount = (aMinCount + aMaxCount) / 2;
		int bCount = lefthalfLength - aCount;

		int ax = aCount > 0 && aCount <= nums1.size() ? nums1[aCount - 1] : INT_MIN;
		int axNext = aCount < nums1.size() && aCount >= 0 ? nums1[aCount] : INT_MAX;
		int bx = bCount > 0 && bCount <= nums2.size() ? nums2[bCount - 1] : INT_MIN;
		int bxNext = bCount < nums2.size() && bCount >= 0 ? nums2[bCount] : INT_MAX;

		if (ax > bxNext) {
			// if (aCount > 0 && nums1[aCount - 1] > nums2[bCount]) {
			aMaxCount = aCount - 1;
		} else if (bx > axNext) {
			// } else if (aCount < nums1.size() && nums2[bCount - 1] > nums1[aCount])
			// {
			aMinCount = aCount + 1;
		} else {
			int leftHalfEnd = aCount == 0
														? nums2[bCount - 1]
														: (bCount == 0)
																	? nums1[aCount - 1]
																	: max(nums1[aCount - 1], nums2[bCount - 1]);

			if (totalSize % 2 == 1) {
				return leftHalfEnd;
			}

			int rightHalfEnd = (aCount == nums1.size())
														 ? nums2[bCount]
														 : (bCount == nums2.size())
																	 ? nums1[aCount]
																	 : min(nums1[aCount], nums2[bCount]);

			return (leftHalfEnd + rightHalfEnd) / 2.0;
		}
	}
	return -1;
}

int main() {
	vector<int> nums1, nums2;

	nums1 = {1, 3};
	nums2 = {2};

	// nums1 = {1, 2};
	// nums2 = {3, 4};

	// nums1 = {0, 0};
	// nums2 = {0, 0};

	nums1 = {};
	nums2 = {1};

	// nums1 = {2};
	// nums2 = {};

	double res = findMedianSortedArrays(nums1, nums2);

	cout << res << endl;

	return 0;
}