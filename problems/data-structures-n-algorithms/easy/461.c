// 461. Hamming Distance
// https://leetcode.com/problems/hamming-distance/

#include <stdio.h>
#include <stdlib.h>

// int hammingDistance(int x, int y) {
// 	int sum = 0;

// 	while (x != 0 || y != 0) {
// 		if (x % 2 != y % 2) {
// 			sum++;
// 		}
// 		x >>= 1;
// 		y >>= 1;
// 	}
// 	return sum;
// }

int hammingDistance(int x, int y) {
	int sum = 0;
	int num = x ^ y;

	while (num != 0) {
		sum++;
		num = num & (num - 1);
	}
	return sum;
}

int main() {
	int x, y;
	int res;

	scanf("%d%d", &x, &y);

	res = hammingDistance(x, y);

	printf("%d", res);

	return 0;
}