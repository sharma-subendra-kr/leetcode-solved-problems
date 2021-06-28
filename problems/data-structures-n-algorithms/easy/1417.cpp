// 1417. Reformat The String
// https://leetcode.com/problems/reformat-the-string/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

void forAlpha(int *ptr, string &s, string &res, bool *valid) {
	while (*ptr != s.size()) {
		if (isalpha(s[*ptr])) {
			res += s[*ptr];
			(*ptr)++;
			*valid = true;
			break;
		}
		(*ptr)++;
	}
}

void forNum(int *ptr, string &s, string &res, bool *valid) {
	while (*ptr != s.size()) {
		if (!isalpha(s[*ptr])) {
			res += s[*ptr];
			(*ptr)++;
			*valid = true;
			break;
		}
		(*ptr)++;
	}
}

string reformat(string s) {
	//
	string res = "";
	int cPtr = 0;
	int nPtr = 0;
	int turn = 0;

	int cAlp = 0;
	int cNum = 0;

	for (char c : s) {
		if (isalpha(c)) {
			cAlp++;
		} else {
			cNum++;
		}
	}

	while (turn < s.size()) {
		bool valid = false;

		if (cAlp > cNum) {
			forAlpha(&cPtr, s, res, &valid);
			turn++;
			if (!valid) {
				return "";
			}
			if (turn == s.size()) {
				break;
			}
			valid = false;
			forNum(&nPtr, s, res, &valid);
			if (!valid) {
				return "";
			}
		} else {
			forNum(&nPtr, s, res, &valid);
			turn++;
			if (!valid) {
				return "";
			}
			if (turn == s.size()) {
				break;
			}
			valid = false;
			forAlpha(&cPtr, s, res, &valid);
			if (!valid) {
				return "";
			}
		}
		turn++;
	}
	return res;
}

int main() {
	//
	// string res = reformat("a0b1c2");
	// string res = reformat("leetcode");
	// string res = reformat("1le");
	// string res = reformat("");
	string res = reformat("ab123");

	cout << res << endl;
	return 0;
}