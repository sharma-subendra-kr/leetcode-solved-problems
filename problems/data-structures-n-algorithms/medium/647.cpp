// 647. Palindromic Substrings
// https://leetcode.com/problems/palindromic-substrings/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

int countPalindrome(int index, string *s) {
	int count = 0;
	int left = index - 1;
	int right = index + 1;
	while (left >= 0 && right < s->size()) {
		if ((*s)[left] != (*s)[right]) {
			break;
		}
		count++;
		left--;
		right++;
	}
	return count;
}

int countPalindrome(int left, int right, string *s) {
	int count = 0;

	if (left < 0) {
		return false;
	} else if (right == s->size()) {
		return false;
	}

	while (left >= 0 && right < s->size()) {
		if ((*s)[left] != (*s)[right]) {
			break;
		}
		count++;
		left--;
		right++;
	}

	return count;
}

int countSubstrings(string s) {
	int count = 0;

	for (int i = 0; i < s.size(); i++) {
		count++;
		count += countPalindrome(i, &s);
		count += countPalindrome(i, i + 1, &s);
	}

	return count;
}

int main() {
	string s = "aaa";

	int res = countSubstrings(s);

	cout << res << endl;

	return 0;
}