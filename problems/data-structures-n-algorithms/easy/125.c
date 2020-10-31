// 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isAlphanumeric(char c) {
	int ascii = (int)c;
	if ((ascii >= 48 && ascii <= 57) || (ascii >= 65 && ascii <= 90) ||
			(ascii >= 97 && ascii <= 122)) {
		return true;
	}
	return false;
}

char toLowerCase(char c) {
	int ascii = (int)c;
	if (ascii >= 65 && ascii <= 90) {
		return (char)(ascii + 32);
	}
	return c;
}

bool isPalindrome(char *s) {
	int start = 0, end = 0;

	while (s[end] != '\0') {
		end++;
	}

	end -= 1;

	while (start <= end) {
		if (!isAlphanumeric(s[start])) {
			start++;
			continue;
		}
		if (!isAlphanumeric(s[end])) {
			end--;
			continue;
		}

		if (toLowerCase(s[start]) != toLowerCase(s[end])) {
			return false;
		}

		start++;
		end--;
	}
	return true;
}

int main() {
	char *s, temp;
	int sSize;
	bool flag;

	scanf("%d", &sSize);
	scanf("%c", &temp);

	s = (char *)malloc(sizeof(char) * (sSize + 1));

	fgets(s, sSize + 1, stdin);
	s[strlen(s)] = '\0';

	printf("%s\n", s);

	flag = isPalindrome(s);

	printf("%d\n", flag);

	free(s);
}