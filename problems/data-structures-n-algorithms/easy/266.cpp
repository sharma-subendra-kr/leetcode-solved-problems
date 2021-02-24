// 266. Palindrome Permutation
// https://leetcode.com/problems/palindrome-permutation/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

bool canPermutePalindrome(string s) {
	//
	int oddCount = 0;
	unordered_map<char, int> ump;

	for (int i = 0; i < s.size(); i++) {
		auto iter = ump.find(s[i]);
		if (iter == ump.end()) {
			ump.insert({s[i], 1});
		} else {
			iter->second++;
		}
	}

	for (auto iter = ump.begin(); iter != ump.end(); iter++) {
		if (iter->second % 2 == 1) {
			oddCount++;
		}
		if (oddCount > 1) {
			return false;
		}
	}

	return true;
}

int main() {
	//
	string s;

	// s = "code";
	// s = "aab";
	s = "carerac";

	bool res = canPermutePalindrome(s);

	cout << res << endl;

	return 0;
}