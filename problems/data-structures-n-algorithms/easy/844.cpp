// 844. Backspace String Compare
// https://leetcode.com/problems/backspace-string-compare/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

bool backspaceCompare(string S, string T) {
	stack<char> sSt;
	stack<char> tSt;
	int count = 0;

	while (count < S.size()) {
		if (S[count] == '#' && !sSt.empty()) {
			sSt.pop();
		} else if (S[count] != '#') {
			sSt.push(S[count]);
		}
		count++;
	}

	count = 0;
	while (count < T.size()) {
		if (T[count] == '#' && !tSt.empty()) {
			tSt.pop();
		} else if (T[count] != '#') {
			tSt.push(T[count]);
		}
		count++;
	}

	string a = "";
	while (!sSt.empty()) {
		char c = sSt.top();
		sSt.pop();
		a += c;
	}

	string b = "";
	while (!tSt.empty()) {
		char c = tSt.top();
		tSt.pop();
		b += c;
	}

	return a == b;
}

int main() {
	//
	string S;
	string T;

	// S = "ab#c";
	// T = "ad#c";

	// S = "ab##";
	// T = "c#d#";

	// S = "a##c";
	// T = "#a#c";

	// S = "a#c";
	// T = "b";

	S = "y#fo##f";
	T = "y#f#o##f";

	int res = backspaceCompare(S, T);

	cout << res << endl;

	return 0;
}