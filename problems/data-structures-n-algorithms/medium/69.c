// 69. Sqrt(x)
// Implement int sqrt(int x).

// Compute and return the square root of x, where x is guaranteed to be a
// non-negative integer.

// Since the return type is an integer, the decimal digits are truncated and
// only the integer part of the result is returned.

#include <stdio.h>
#include <stdlib.h>

int mySqrt(int n) {
	// Newton's Method

	long r = n;
	while (r * r > n) {
		r = (r + n / r) / 2;
	}
	return r;
}

int main() {
	int n;
	scanf("%d", &n);

	printf("%d", mySqrt(n));

	return 0;
}