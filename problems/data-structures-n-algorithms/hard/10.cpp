// 10. Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching/

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool isMatch(string s, string p) {
	int slen = s.size();
	int plen = p.size();

	bool **dp = new bool *[slen + 1];

	for (int i = 0; i < slen + 1; i++) {
		dp[i] = new bool[plen + 1]{0};
	}

	dp[0][0] = true;

	for (int i = 2; i < plen + 1; i += 2) {
		if (p[i - 1] == '*' && dp[0][i - 2]) {
			dp[0][i] = true;
		}
	}

	for (int i = 1; i < slen + 1; i++) {
		for (int j = 1; j < plen + 1; j++) {
			char cs = s[i - 1];
			char cp = p[j - 1];
			if (cs == cp) {
				dp[i][j] = dp[i - 1][j - 1];
			} else if (cp == '.') {
				dp[i][j] = dp[i - 1][j - 1];
			} else if (cp == '*') {
				char prevp = p[j - 2];
				if (prevp != '.' && prevp != cs) {
					dp[i][j] = dp[i][j - 2];
				} else if (prevp == '.' || prevp == cs) {
					dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];
				}
			}
		}
	}

	return dp[slen][plen];
}

int main() {
	string s, p;

	s = "aa";
	p = "a";

	// s = "aa";
	// p = "a*";

	bool res = isMatch(s, p);

	cout << res << endl;
}