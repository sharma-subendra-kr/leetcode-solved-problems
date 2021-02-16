// 459. Repeated Substring Pattern
// https://leetcode.com/problems/repeated-substring-pattern/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

bool repeatedSubstringPattern(string s) {
	int iter = 0;
	while (iter < s.size() / 2) {
		if (s[iter] == s[s.size() - 1] && s.size() % (iter + 1) == 0) {
			bool flag = true;
			for (int i = iter + 1; i < s.size();) {
				for (int j = 0; j <= iter; j++) {
					if (s[i] != s[j]) {
						flag = false;
						break;
					}
					i++;
				}
				if (flag == false) {
					break;
				}
			}
			if (flag == true) {
				return true;
			}
		}

		iter++;
	}

	return false;
}

int main() {
	//

	string s;

	// s = "abcabcabcabc";
	// s = "ababba";
	s = "babbabbabbabbab";

	bool res = repeatedSubstringPattern(s);

	cout << res << endl;

	return 0;
}