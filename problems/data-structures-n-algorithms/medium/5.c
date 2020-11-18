// 5. Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// char *longestPalindrome(char *s) {
// 	int i = 0;
// 	int len = 0, low, high, maxLen = 1, currLen = 0, start = 0, count = 0;
// 	char *res;

// 	while (s[len] != '\0') {
// 		len++;
// 	}

// 	if (len == 0 || len == 1) {
// 		return s;
// 	} else if (len == 2 && s[0] == s[1]) {
// 		return s;
// 	} else if (len == 2) {
// 		res = malloc(sizeof(char) * 2);
// 		res[0] = s[0];
// 		res[1] = '\0';
// 		return res;
// 	}

// 	for (i = 1; i < len; i++) {
// 		low = i - 1;
// 		high = i;
// 		currLen = 0;
// 		while (low >= 0 && high < len && s[low] == s[high]) {
// 			low--;
// 			high++;
// 			currLen += 2;
// 		}

// 		if (currLen > maxLen) {
// 			start = low + 1;
// 			maxLen = currLen;
// 		}

// 		if (i == len - 1) {
// 			continue;
// 		}

// 		low = i - 1;
// 		high = i + 1;
// 		currLen = 0;
// 		while (low >= 0 && high < len && s[low] == s[high]) {
// 			if (low == i - 1) {
// 				currLen += 3;
// 			} else {
// 				currLen += 2;
// 			}

// 			low--;
// 			high++;
// 		}

// 		if (currLen > maxLen) {
// 			start = low + 1;
// 			maxLen = currLen;
// 		}
// 	}

// 	res = (char *)malloc(sizeof(char) * (maxLen + 1));

// 	for (i = start; i <= start + maxLen - 1; i++) {
// 		res[count++] = s[i];
// 	}

// 	res[count] = '\0';

// 	return res;
// }

// DP solution
char *longestPalindrome(char *s) {
	int len = 0, i, k, j, count = 0;
	int **arr;
	int start = 0;
	int maxLen = 0;
	char *res;

	while (s[len] != '\0') {
		len++;
	}

	arr = (int **)calloc(len, sizeof(int *));

	for (i = 0; i < len; i++) {
		arr[i] = (int *)calloc(len, sizeof(int));
	}

	for (i = 0; i < len; i++) {
		arr[i][i] = 1;
		maxLen = 1;
	}

	for (i = 0; i < len - 1; i++) {
		if (s[i] == s[i + 1]) {
			arr[i][i + 1] = 1;
			start = i;
			maxLen = 2;
		}
	}

	for (k = 3; k <= len; k++) {
		for (i = 0; i < len - k + 1; i++) {
			j = i + k - 1;

			if (arr[i + 1][j - 1] && s[i] == s[j]) {
				arr[i][j] = 1;
				if (k > maxLen) {
					start = i;
					maxLen = k;
				}
			}
		}
	}

	res = (char *)malloc(sizeof(char) * maxLen + 1);

	for (i = start; i < start + maxLen; i++) {
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