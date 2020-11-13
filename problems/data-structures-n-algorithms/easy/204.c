// 204. Count Primes
// https://leetcode.com/problems/count-primes/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int countPrimes(int n) {
	int *arr, i, j, sum = 0, sq;

	arr = (int *)calloc(n, sizeof(int));

	sq = sqrt(n);

	if (n > 2) {
		sum = n - 2;
	}

	for (i = 2; i <= sq; i++) {
		if (arr[i] == -1) {
			continue;
		}
		for (j = i * i; j < n; j += i) {
			if (j % i == 0 && arr[j] != -1) {
				arr[j] = -1;
				sum--;
			}
		}
	}

	return sum;
}

int main() {
	int n, res;

	scanf("%d", &n);

	res = countPrimes(n);

	printf("%d", res);

	return 0;
}