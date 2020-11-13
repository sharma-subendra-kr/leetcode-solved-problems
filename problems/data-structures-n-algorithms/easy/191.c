// 191. Number of 1 Bits
// https://leetcode.com/problems/number-of-1-bits/

#include <stdio.h>
#include <stdlib.h>

// int hammingWeight(u_int32_t n) {
// 	int sum = 0;
// 	while (n != 0) {
// 		if (n % 2 != 0) {
// 			sum++;
// 		}
// 		n = n >> 1;
// 	}

// 	return sum;
// }

int hammingWeight(u_int32_t n) {
	int sum = 0;
	while (n != 0) {
		sum++;
		n = n & (n - 1);
	}

	return sum;
}

int main() {
	u_int32_t n;
	int res;

	scanf("%d", &n);

	res = hammingWeight(n);

	printf("%d", res);

	return 0;
}