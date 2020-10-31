// 28. Implement strStr()
// https://leetcode.com/problems/implement-strstr/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int strStr(char *haystack, char *needle) {
// 	int hlen = 0, nlen = 0;
// 	int i = 0, hstart = 0, hend = 0, nstart = 0, nend = 0, isSubstr = 1;

// 	while (haystack[hlen] != '\0') {
// 		hlen++;
// 	}

// 	while (needle[nlen] != '\0') {
// 		nlen++;
// 	}

// 	if (hlen < nlen) {
// 		return -1;
// 	}

// 	for (i = 0; i <= hlen - nlen; i++) {
// 		hstart = i;
// 		hend = i + nlen - 1;
// 		nstart = 0;
// 		nend = nlen - 1;

// 		isSubstr = 1;

// 		while (nstart <= nend) {
// 			if (haystack[hstart] != needle[nstart] ||
// 					haystack[hend] != needle[nend]) {
// 				isSubstr = 0;
// 				break;
// 			}

// 			hstart++;
// 			hend--;
// 			nstart++;
// 			nend--;
// 		}

// 		if (isSubstr == 1) {
// 			return i;
// 		}
// 	}

// 	return -1;
// }

/*
	Edge cases:

	* "aabaaabaaac"
		"aabaaac"

	* "ababcaababcaabc"
		"ababcaabc"

	* "adcadcaddcadde"
		"adcadde"*/

int *getKMPPiTable(char *needle, int nlen) {
	int i = 0, prefixCnt = 0;

	int _prefixCnt, _i, flag;

	// lps - longest prefix which is same as some suffix
	int *lps = (int *)calloc(nlen, sizeof(int));

	for (i = 1; i < nlen; i++) {
		if (needle[prefixCnt] == needle[i]) {
			if (lps[i] == 0) {
				lps[i] = prefixCnt + 1;
			}
			prefixCnt++;
		} else if (prefixCnt != 0) {
			_prefixCnt = prefixCnt;
			_i = i;
			flag = 1;
			while (_prefixCnt--) {
				if (needle[_prefixCnt] != needle[_i]) {
					flag = 0;
					break;
				}
				_i--;
			}
			if (flag == 1) {
				lps[i] = prefixCnt;
			}

			prefixCnt = 0;
			i--;
		}
	}

	// for (i = 0; i < nlen; i++) {
	// 	printf("%d\t", lps[i]);
	// }
	// printf("\n");

	return lps;
}

int strStr(char *haystack, char *needle) {
	int i = 0, hlen = 0, nlen = 0;
	int *lps;
	int piCnt = -1;

	while (haystack[hlen] != '\0') {
		hlen++;
	}

	while (needle[nlen] != '\0') {
		nlen++;
	}

	if (hlen < nlen) {
		return -1;
	} else if (nlen == 0) {
		return 0;
	}

	lps = getKMPPiTable(needle, nlen);

	for (i = 0; i < hlen; i++) {
		if (haystack[i] == needle[piCnt + 1]) {
			piCnt++;
			if (piCnt == nlen - 1) {
				return i - (nlen - 1);
			}
		} else if (piCnt != -1) {
			piCnt = lps[piCnt] - 1;
			i--;
		}
	}

	return -1;
}

int main() {
	char *haystack, *needle, temp;
	int sSize, index = 0;

	scanf("%d", &sSize);
	scanf("%c", &temp);

	haystack = (char *)malloc(sizeof(char) * (sSize + 1));
	needle = (char *)malloc(sizeof(char) * (sSize + 1));

	fgets(haystack, sSize + 1, stdin);
	haystack[strlen(haystack) - 1] = '\0';

	fgets(needle, sSize + 1, stdin);
	needle[strlen(needle) - 1] = '\0';

	printf("%s\n", haystack);
	printf("%s\n", needle);

	index = strStr(haystack, needle);

	printf("%d\n", index);

	free(haystack);
	free(needle);
}