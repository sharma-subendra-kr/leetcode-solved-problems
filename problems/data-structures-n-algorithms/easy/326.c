// 326. Power of Three
// https://leetcode.com/problems/power-of-three/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// bool isPowerOfThree(int n) {
// 	int num = 1;

// 	while (num < n && num < 715827882) {
// 		num *= 3;
// 	}

// 	if (num == n) {
// 		return true;
// 	}
// 	return false;
// }

bool isPowerOfThree(int n) { return n > 0 && 1162261467 % n == 0; }

int main() {
	int n, res;

	scanf("%d", &n);

	res = isPowerOfThree(n);

	printf("%d", res);

	return 0;
}