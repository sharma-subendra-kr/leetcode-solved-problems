// 29. Divide Two Integers
// https://leetcode.com/problems/divide-two-integers/

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int divide(int dividend, int divisor) {
	long res = 0;
	bool isNegative = false;

	if ((dividend > 0) ^ (divisor > 0)) {
		isNegative = true;
	}

	if (dividend == INT_MIN && divisor == -1) {
		return INT_MAX;
	}

	long _dividend = labs(dividend);
	long _divisor = labs(divisor);

	while (_dividend >= _divisor) {
		long d = _divisor;
		int count = 0;
		long r = 1;
		while (d << 1 < _dividend) {
			d <<= 1;
			count++;
		}
		_dividend -= d;
		r <<= count;
		res += r;
	}

	if (isNegative) {
		res = -res;
	}

	return res;
};

int main() {
	// int res = divide(-2147483648, -1);
	int res = divide(-2147483648, 1);
	// int res = divide(7, 3);
	// int res = divide(2147483647, 1);

	printf("%d", res);

	return 0;
}
