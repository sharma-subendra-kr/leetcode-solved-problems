// 70. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/

#include <stdio.h>
#include <stdlib.h>

// int climbStairs(int n) {
// 	if (n == -1) {
// 		return 0;
// 	} else if (n == 0) {
// 		return 1;
// 	}

// 	return climbStairs(n - 1) + climbStairs(n - 2);
// }

int climbStairs(int n) {
	int arr[2] = {1, 2};
	int sum = 0, i = 0;

	if (n == 0) {
		return 1;
	} else if (n == 1) {
		return 1;
	} else if (n == 2) {
		return 2;
	}

	for (i = 3; i <= n; i++) {
		sum = arr[0] + arr[1];
		arr[0] = arr[1];
		arr[1] = sum;
	}
	return sum;
}

int main() {
	int n, res;

	scanf("%d", &n);

	res = climbStairs(n);

	printf("%d\n", res);
}
