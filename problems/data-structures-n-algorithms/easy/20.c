// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isClosingBracket(char c) {
	if (c == ')' || c == '}' || c == ']') {
		return true;
	}
	return false;
}

bool doPairsMatch(char open, char close) {
	if (open == '(' && close == ')') {
		return true;
	} else if (open == '{' && close == '}') {
		return true;
	} else if (open == '[' && close == ']') {
		return true;
	}
	return false;
}

bool isValid(char *s) {
	int len = 0, i = 0, top = -1;
	char *stack;

	while (s[len] != '\0') {
		len++;
	}

	if (len == 0) {
		return true;
	}

	stack = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (len != 0) {
		if (!isClosingBracket(s[i])) {
			stack[++top] = s[i];
		} else if (isClosingBracket(s[i]) &&
							 (top == -1 || !doPairsMatch(stack[top], s[i]))) {
			return false;
		} else {
			top--;
		}

		i++;
		len--;
	}

	if (top != -1) {
		return false;
	}
	return true;
}

int main() {
	char *s, c;
	bool res;

	s = (char *)malloc(sizeof(char) * 100);

	// scanf("%c", &c);
	scanf("%s", s);

	res = isValid(s);

	printf("%d", res);

	return 0;
}