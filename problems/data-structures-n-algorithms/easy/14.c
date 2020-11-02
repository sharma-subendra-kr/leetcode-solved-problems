// 14. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/

#include <stdio.h>
#include <stdlib.h>

char *longestCommonPrefix(char **strs, int strsSize) {
	int i, index = 0, cnt = 0, breakSig = 0;
	char *prefix;

	while (strsSize > 1) {
		breakSig = 0;
		for (i = 0; i < strsSize - 1; i++) {
			if (strs[i][index] != strs[i + 1][index] || strs[i][index] == '\0' ||
					strs[i + 1][index] == '\0') {
				breakSig = 1;
				break;
			}
		}

		if (breakSig) {
			break;
		}

		index++;
	}

	if (strsSize == 1) {
		while (strs[0][index] != '\0') {
			index++;
		}
	}

	prefix = (char *)malloc(sizeof(char) * (index + 1));

	while (cnt < index) {
		prefix[cnt] = strs[0][cnt];
		cnt++;
	}

	prefix[cnt] = '\0';

	return prefix;
}

int main() {
	char **strs, temp, *res;
	int strsSize, length, i, cnt = 0;

	scanf("%d", &strsSize);
	scanf("%d", &length);
	scanf("%c", &temp);

	strs = (char **)malloc(sizeof(char *) * strsSize);

	for (i = 0; i < strsSize; i++) {
		strs[i] = (char *)calloc(length, sizeof(char));
	}

	for (i = 0; i < strsSize; i++) {
		scanf("%s", strs[i]);
	}

	res = longestCommonPrefix(strs, strsSize);

	printf("%s", res);
}