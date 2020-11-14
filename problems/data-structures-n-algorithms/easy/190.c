// 190. Reverse Bits
// https://leetcode.com/problems/reverse-bits/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// u_int32_t reverseBits(u_int32_t n) {
// 	int cnt = 31;
// 	u_int32_t res = 0, toggler;

// 	while (n != 0) {
// 		toggler = 1;
// 		if (n % 2 != 0) {
// 			toggler <<= cnt;
// 			res = res + toggler;
// 		}
// 		n >>= 1;
// 		cnt--;
// 	}

// 	return res;
// }

// u_int32_t reverseBits(u_int32_t n) {
// 	int cnt = 31;
// 	u_int32_t res = 0, toggler;

// 	while (n != 0) {
// 		toggler = (n & 1) << cnt;
// 		res = res + toggler;

// 		n >>= 1;
// 		cnt--;
// 	}

// 	return res;
// }

u_int32_t reverseBits(u_int32_t n) {
	u_int32_t left, right, res;

	res = n;

	left = 0xffff0000 & res;
	right = 0x0000ffff & res;
	left >>= 16;
	right <<= 16;
	res = left | right;

	left = 0xff00ff00 & res;
	right = 0x00ff00ff & res;
	left >>= 8;
	right <<= 8;
	res = left | right;

	left = 0xf0f0f0f0 & res;
	right = 0x0f0f0f0f & res;
	left >>= 4;
	right <<= 4;
	res = left | right;

	left = 0xcccccccc & res;
	right = 0x33333333 & res;
	left >>= 2;
	right <<= 2;
	res = left | right;

	left = 0xaaaaaaaa & res;
	right = 0x55555555 & res;
	left >>= 1;
	right <<= 1;
	res = left | right;

	return res;
}

int main() {
	int n;
	unsigned res;

	scanf("%d", &n);

	res = reverseBits(n);

	printf("%u", res);

	return 0;
}