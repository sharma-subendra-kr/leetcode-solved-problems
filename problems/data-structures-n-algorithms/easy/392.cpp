// 392. Is Subsequence
// https://leetcode.com/problems/is-subsequence/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// bool isSubsequence(string s, string t) {
// 	int j = 0;

// 	if (s.size() == 0) {
// 		return 1;
// 	}

// 	for (int i = 0; i < t.size(); i++) {
// 		if (t[i] == s[j]) {
// 			j++;
// 			if (j == s.size()) {
// 				return true;
// 			}
// 		}
// 	}
// 	return false;
// }

bool isSubsequence(string s, string t) {
	unordered_map<char, vector<int>> ump;

	for (int i = 0; i < t.size(); i++) {
		auto iter = ump.find(t[i]);
		if (iter == ump.end()) {
			vector<int> v;
			v.push_back(i);
			ump.insert({t[i], v});
			continue;
		}
		iter->second.push_back(i);
	}

	int prev = 0;
	for (int i = 0; i < s.size(); i++) {
		auto iter = ump.find(s[i]);
		if (iter == ump.end())
			return false;
		int index = lower_bound(iter->second.begin(), iter->second.end(), prev) -
								iter->second.begin();
		if (index == iter->second.size()) {
			return false;
		}

		prev = iter->second[index] + 1;
	}
	return true;
}

int main() {
	string s, t;

	s = "abc";
	t = "ahbgdc";

	bool res = isSubsequence(s, t);

	cout << res << endl;
}