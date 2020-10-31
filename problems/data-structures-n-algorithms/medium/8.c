// 8. String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myAtoi(char *s) {
	int start = -1, end = -1;
	int i = 0;
	int isNegative = 0, res = 0;

	while (s[i] != '\0') {
		if (start != -1 && ((int)s[i] >= 48 && (int)s[i] <= 57)) {
			end++;
		} else if (start != -1 && ((int)s[i] < 48 || (int)s[i] > 57)) {
			break;
		}

		if (start == -1 && (((int)s[i] >= 48 && (int)s[i] <= 57) ||
												(int)s[i] == 43 || (int)s[i] == 45)) {
			start = i;
			end = i;
		} else if (start == -1 && (int)s[i] != 32) {
			return 0;
		}

		i++;
	}

	if (start == -1) {
		return 0;
	}

	if (start == end && ((int)s[start] == 43 || (int)s[start] == 45)) {
		// string with only "-" or "+" sign
		return 0;
	} else if ((int)s[start] == 45) {
		isNegative = 1;
		start++;
	} else if ((int)s[start] == 43) {
		start++;
	}

	i = start;
	while (i <= end) {
		if ((res + (s[i] - '0')) > (INT_MAX / 10 + 7) && !isNegative) {
			return INT_MAX;
		} else if ((res - (s[i] - '0')) < (INT_MIN / 10 - 8) && isNegative) {
			return INT_MIN;
		}

		if (!isNegative) {
			res = res * 10 + (s[i] - '0');
		} else {
			res = res * 10 - (s[i] - '0');
		}

		i++;
	}

	return res;
}

int main() {
	char *s, temp;
	int sSize, res;

	scanf("%d", &sSize);
	scanf("%c", &temp);

	s = (char *)malloc(sizeof(char) * (sSize + 1));

	fgets(s, sSize + 1, stdin);
	s[strlen(s)] = '\0';

	printf("%d\n", INT_MAX / 10);
	printf("%d\n", INT_MAX);
	printf("%d\n", INT_MIN / 10);
	printf("%d\n", INT_MIN);

	res = myAtoi(s);

	printf("%d\n", res);

	free(s);
}