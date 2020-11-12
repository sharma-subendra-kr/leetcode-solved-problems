// 278. First Bad Version
// https://leetcode.com/problems/first-bad-version/

#include <stdbool.h>
#include <stdio.h>

bool isBadVersion(int n) {
	if (n >= 2147483647) {
		return true;
	}
	return false;
}

int firstBadVersion(int n) {
	int mid, low = 1, high = n;
	int flag, minBadVersion = 2147483647;

	while (low <= high) {
		mid = low + (high - low) / 2;
		flag = isBadVersion(mid);

		if (flag) {
			high = mid - 1;
			if (mid < minBadVersion) {
				minBadVersion = mid;
			}
		} else {
			low = mid + 1;
		}
	}
	return minBadVersion;
}

int main() {
	int first;
	first = firstBadVersion(2147483647);

	printf("%d", first);
	return 0;
}