// 1576. Replace All ?'s to Avoid Consecutive Repeating Characters
// https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

char getChar(int index, string &s, char *p) {
	char prev = '\0';
	char next = '\0';
	char curr = s[index];
	if (index > 0) {
		prev = p[index - 1];
	}
	if (index < s.size() - 1) {
		next = s[index + 1];
	}

	for (int i = 97; i < 123; i++) {
		if ((char)i != prev && (char)i != next) {
			return (char)i;
		}
	}
	return '\0';
}

string modifyString(string s) {
	//
	char *res = new char[s.size() + 1];

	for (int i = 0; i < s.size(); i++) {

		if (s[i] == '?') {
			char rep = getChar(i, s, res);
			if (rep != '\0') {
				res[i] = rep;
			}
		} else {
			res[i] = s[i];
		}
	}
	res[s.size()] = '\0';
	return string(res);
}

int main() {
	//
	// string s = "?zs";
	// string s = "ubv?w";
	// string s = "j?qg??b";
	string s = "??yw?ipkj?";

	string res = modifyString(s);

	cout << res << endl;

	return 0;
}