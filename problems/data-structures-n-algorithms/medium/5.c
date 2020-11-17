// 5. Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char *longestPalindrome(char *s) {
	int i = 0;
	int len = 0, low, high, maxLen = 0, currLen = 0, where = 0, iFront, iBack, tF,
			tB;
	int **map, count = 0;
	char *res;

	while (s[len] != '\0') {
		len++;
	}

	if (len == 0 || len == 1) {
		return s;
	} else if (len == 2 && s[0] == s[1]) {
		return s;
	} else if (len == 2) {
		res = malloc(sizeof(char) * 2);
		res[0] = s[0];
		res[1] = '\0';
		return res;
	}

	map = (int **)malloc(sizeof(int *) * len * 2);

	for (i = 1; i < len - 1; i++) {
		if (s[i] == s[i - 1]) {
			map[count] = (int *)malloc(sizeof(int) * 2);
			map[count][0] = i - 1;
			map[count][1] = i;
			count++;
		} else if (s[i] == s[i + 1]) {
			map[count] = (int *)malloc(sizeof(int) * 2);
			map[count][0] = i;
			map[count][1] = i + 1;
			count++;
		}
		if (s[i - 1] == s[i + 1]) {
			map[count] = (int *)malloc(sizeof(int) * 2);
			map[count][0] = i - 1;
			map[count][1] = i + 1;
			count++;
		}
	}

	if (count == 0) {
		res = malloc(sizeof(char) * 2);
		res[0] = s[0];
		res[1] = '\0';
		return res;
	}

	for (i = 0; i < count; i++) {
		low = map[i][0];
		high = map[i][1];
		currLen = map[i][1] - map[i][0] + 1;
		while (low >= 0 && high < len) {
			if (s[low] == s[high]) {
				currLen += 2;
				tF = low;
				tB = high;
				low--;
				high++;
			} else {
				break;
			}
		}
		if (currLen >= maxLen) {
			where = i;
			maxLen = currLen;
			iFront = tF;
			iBack = tB;
		}
	}

	count = 0;
	res = (char *)malloc(sizeof(char) * (maxLen + 1));

	for (i = iFront; i <= iBack; i++) {
		res[count++] = s[i];
	}

	res[count] = '\0';

	return res;
}

int main() {
	char *str, *res;

	str = (char *)malloc(sizeof(char) * 100);

	scanf("%s", str);

	res = longestPalindrome(str);

	printf("%s", res);

	return 0;
}