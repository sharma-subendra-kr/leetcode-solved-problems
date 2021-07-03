// 680. Valid Palindrome II
// https://leetcode.com/problems/valid-palindrome-ii/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

pair<int, int> isValid(string &s, int low, int high) {
	while (low < high) {
		if (s[low] != s[high]) {
			return pair<int, int>(low, high);
		}
		low++;
		high--;
	}
	return pair<int, int>(-1, -1);
}

bool validPalindrome(string s) {
	//
	int low = 0;
	int high = s.size() - 1;
	pair<int, int> p, p1, p2;

	p = isValid(s, low, high);
	if (p.first != -1) {
		p1 = isValid(s, p.first + 1, p.second);
		p2 = isValid(s, p.first, p.second - 1);
	}

	if (p.first != -1 && p1.first != -1 && p2.first != -1) {
		return false;
	}

	return true;
}

int main() {
	//
	string s;
	// s = "aba";
	// s = "abca";
	// s = "abc";
	s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdh"
			"ooxfuupuculmgmqfvnbgtapekouga";

	bool res = validPalindrome(s);

	cout << res << endl;

	return 0;
}