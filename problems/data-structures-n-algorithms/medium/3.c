// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) a > b ? a : b

void sanitizeIndex(int *arr, int wipe) {
	int i;

	for (i = 0; i < 128; i++) {
		if (arr[i] < wipe) {
			arr[i] = -1;
		}
	}
}

int lengthOfLongestSubstring(char *s) {
	int arr[128];

	int len = 0;
	int i, maxLen = 0, prevIndex = 0;

	while (len < 128) {
		arr[len++] = -1;
	}

	len = 0;

	while (s[len] != '\0') {
		len++;
	}

	for (i = 0; i < len; i++) {
		if (arr[s[i] - '\0'] > -1) {
			prevIndex = MAX(arr[s[i] - '\0'], prevIndex);
		}
		// adding one here cuz it causes problem with string with length 1
		maxLen = MAX(maxLen, i - prevIndex + 1);
		// adding one here cuz it causes problem with string with length 1
		arr[s[i] - '\0'] = i + 1;
	}

	return maxLen;
};

int main() {
	char *str;
	int res;

	// str = (char *)malloc(sizeof(char) * 100);

	// scanf("%s", str);

	// res = lengthOfLongestSubstring(str);

	str = (char *)malloc(sizeof(char) * 2);
	str[0] = ' ';
	str[1] = '\0';
	res = lengthOfLongestSubstring(str);

	printf("%d", res);

	return 0;
}
