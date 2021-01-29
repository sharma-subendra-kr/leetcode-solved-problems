// 290. Word Pattern
// https://leetcode.com/problems/word-pattern/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <string>

using namespace std;

bool wordPattern(string pattern, string s) {
	unordered_map<char, string> mp;
	unordered_map<string, char> smp;
	int j = 0;
	int i = 0;

	for (i = 0; i < pattern.size() && j < s.size(); i++) {
		int k = j;
		while (s[k] != ' ' && k < s.size()) {
			k++;
		}
		string temp = s.substr(j, k - j);
		auto iter1 = mp.find(pattern[i]);
		auto iter2 = smp.find(temp);

		if (iter1 != mp.end() && iter1->second != temp) {
			return false;
		} else if (iter2 != smp.end() && iter2->second != pattern[i]) {
			return false;
		} else {
			mp.insert({pattern[i], temp});
			smp.insert({temp, pattern[i]});
		}
		j = k + 1;
	}

	if (i == pattern.size() && j < s.size()) {
		return false;
	} else if (i < pattern.size() && j > s.size()) {
		return false;
	}
	return true;
}

int main() {
	string pattern, s;

	// pattern = "abba";
	// s = "dog cat cat dog";

	// pattern = "aaaa";
	// s = "dog cat cat dog";

	// pattern = "abba";
	// s = "dog dog dog dog";

	pattern = "jquery";
	s = "jquery";

	bool res = wordPattern(pattern, s);

	cout << res << endl;

	return 0;
}