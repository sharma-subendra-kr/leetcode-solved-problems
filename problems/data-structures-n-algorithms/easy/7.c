// 7. Reverse Integer
// https://leetcode.com/problems/reverse-integer/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int reverse(int x) {
	int pop = 0;
	int rev = 0;

	while (x != 0) {
		pop = x % 10;
		x = x / 10;

		if (INT_MAX / 10 < rev) {
			return 0;
		}

		if (INT_MIN / 10 > rev) {
			return 0;
		}

		rev = rev * 10 + pop;
	}

	return rev;
}

int main() {
	int rev;
	long x;

	scanf("%ld", &x);

	rev = reverse(x);

	printf("%d", rev);
}