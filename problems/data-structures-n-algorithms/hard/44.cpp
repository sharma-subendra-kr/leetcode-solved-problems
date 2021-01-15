// 44. Wildcard Matching
// https://leetcode.com/problems/wildcard-matching/

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool isMatch(string s, string p) {
	int si = 0;
	int pi = 0;
	int asterisk = -1;
	int match = -1;

	while (si < s.size()) {
		if (p[pi] == '?' || s[si] == p[pi]) {
			si++;
			pi++;
			continue;
		} else if (p[pi] == '*') {
			asterisk = pi;
			match = si;
			pi++;
			continue;
		} else if (asterisk >= 0) {
			pi = asterisk + 1;
			match++;
			si = match;
			continue;
		}
		return false;
	}

	while (pi < p.size() && p[pi] == '*') {
		pi++;
	}
	if (pi < p.size()) {
		return false;
	}
	return true;
}

int main() {
	string s, p;

	// s = "aa";
	// p = "a";

	// s = "aa";
	// p = "a*";

	s = "aa";
	p = "*";

	s = "abcabczzzde";
	p = "*abc???de*";

	bool res = isMatch(s, p);

	cout << res << endl;
}