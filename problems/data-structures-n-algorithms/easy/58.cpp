// 58. Length of Last Word
// https://leetcode.com/problems/length-of-last-word/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <limits.h>
#include <string.h>

using namespace std;

int lengthOfLastWord(string s) {
	int len = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == ' ' && len == 0) {
			continue;
		} else if (s[i] == ' ' && len != 0) {
			break;
		}
		len++;
	}

	return len;
}

int main() {
	string s;

	// s = "Hello World";
	// s = " ";
	s = "b   a    ";

	int res = lengthOfLastWord(s);

	cout << res << endl;

	return 0;
}