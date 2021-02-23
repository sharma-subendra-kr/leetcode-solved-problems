// 482. License Key Formatting
// https://leetcode.com/problems/license-key-formatting/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

char getChar(char c) {
	if ((int)c >= 97) {
		return (char)c - 32;
	}
	return c;
}

string licenseKeyFormatting(string S, int K) {
	int count = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '-') {
			count++;
		}
	}

	vector<char> res;
	count = 0;
	for (int i = S.size() - 1; i >= 0; i--) {
		if (S[i] == '-') {
			continue;
		}
		if (count == K) {
			res.push_back('-');
			count = 0;
		}
		res.push_back(getChar(S[i]));
		count++;
	}

	reverse(res.begin(), res.end());

	string result(res.begin(), res.end());

	return result;
}

int main() {
	//
	string S;
	int K;

	S = "5F3Z-2e-9-w";
	K = 4;

	string res = licenseKeyFormatting(S, K);

	cout << res << endl;

	return 0;
}