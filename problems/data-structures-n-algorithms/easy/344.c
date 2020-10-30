// 344. Reverse String
// https://leetcode.com/problems/reverse-string/

#include <stdio.h>
#include <stdlib.h>

void reverseString(char *s, int sSize) {
	int start = 0, end = sSize - 1;
	char temp;

	while (start <= end) {
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;

		start++;
		end--;
	}
}

int main() {
	char *s;
	int sSize, i;

	scanf("%d", &sSize);

	s = (char *)malloc(sizeof(char) * (sSize + 1));

	for (i = 0; i < sSize; i++) {
		scanf("%s", &s[i]);
	}

	reverseString(s, sSize);

	for (i = 0; i < sSize; i++) {
		printf("%c", s[i]);
	}

	free(s);
}