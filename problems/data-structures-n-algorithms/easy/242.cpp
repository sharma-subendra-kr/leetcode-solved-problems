// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

bool isAnagram(string s, string t) {
	int smp[26] = {0};
	int tmp[26] = {0};

	for (int i = 0; i < s.size(); i++) {
		smp[s[i] - 'a']++;
	}

	for (int j = 0; j < t.size(); j++) {
		tmp[t[j] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (smp[i] != tmp[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	string s, t;

	s = "a";
	t = "b";

	bool res = isAnagram(s, t);

	cout << res << endl;

	return 0;
}