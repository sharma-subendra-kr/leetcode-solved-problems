// 387. First Unique Character in a String
// https://leetcode.com/problems/first-unique-character-in-a-string/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int firstUniqChar(char *s) {
	int map[128] = {0};
	int i = 0;

	while (s[i] != '\0') {
		map[(int)s[i]]++;
		i++;
	}

	i = 0;
	while (s[i] != '\0') {
		if (map[(int)s[i]] == 1) {
			return i;
		}
		i++;
	}
	return -1;
}

int main() {
	char *s;
	int sSize, index;

	scanf("%d", &sSize);

	s = (char *)malloc(sizeof(char) * (sSize + 1));

	scanf("%s", s);

	index = firstUniqChar(s);

	printf("%d\n", index);

	printf("%s\n", s);

	free(s);
}