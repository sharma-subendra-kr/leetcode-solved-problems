// 131. Palindrome Partitioning
// https://leetcode.com/problems/palindrome-partitioning/

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool isPalindrome(string s) {
	int l = 0;
	int r = s.size() - 1;
	while (l < r) {
		if (s[l] != s[r]) {
			return false;
		}
		l++;
		r--;
	}

	return true;
};

void partition(string s, int start, vector<string> &par,
							 vector<vector<string>> &pars) {
	if (start == s.size()) {
		pars.push_back(par);
		return;
	}
	for (int i = start; i < s.size(); i++) {
		string subs = s.substr(start, i - start + 1);
		if (isPalindrome(subs)) {
			par.push_back(subs);
			partition(s, i + 1, par, pars);
			par.pop_back();
		}
	}
};

vector<vector<string>> partition(string s) {
	vector<vector<string>> pars;
	vector<string> par;
	partition(s, 0, par, pars);
	return pars;
}

int main() {
	string s;

	s = "aab";

	vector<vector<string>> res = partition(s);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}