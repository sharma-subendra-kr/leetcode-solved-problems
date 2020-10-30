// 66. Plus One
// https://leetcode.com/problems/plus-one/

#include <stdio.h>
#include <stdlib.h>

int *plusOne(int *digits, int digitsSize, int *returnSize) {
	int last = digitsSize - 1, carry = 1, sum, i;
	int *res;

	if (digits[last] < 9) {
		digits[last]++;
		*returnSize = digitsSize;
		return digits;
	}

	while (last >= 0) {
		sum = digits[last] + carry;
		if (sum == 10) {
			digits[last] = 0;
			carry = 1;
		} else {
			digits[last] = sum;
			carry = 0;
			break;
		}
		last--;
	}

	if (carry == 1) {
		*returnSize = digitsSize + 1;
		res = (int *)malloc((digitsSize + 1) * sizeof(int));
	} else {
		*returnSize = digitsSize;
		res = (int *)malloc((digitsSize) * sizeof(int));
	}

	for (i = digitsSize - 1; i >= 0; i--) {
		if (carry == 1) {
			res[i + 1] = digits[i];
		} else {
			res[i] = digits[i];
		}
	}

	if (carry == 1) {
		res[0] = 1;
	}

	return res;
}

int main() {
	int *digits, digitsSize, returnSize, *res, i;

	scanf("%d", &digitsSize);

	digits = (int *)malloc(digitsSize * sizeof(int));

	for (i = 0; i < digitsSize; i++) {
		scanf("%d", &digits[i]);
	}

	res = plusOne(digits, digitsSize, &returnSize);

	printf("[");
	for (i = 0; i < returnSize; i++) {
		if (i != returnSize - 1) {
			printf("%d,", res[i]);
		} else {
			printf("%d", res[i]);
		}
	}
	printf("]\n");

	free(digits);
	free(res);
}