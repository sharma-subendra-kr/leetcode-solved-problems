// 139. Word Break
// https://leetcode.com/problems/word-break/

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

bool wordBreak(string s, vector<string> &wordDict) {
	set<string> wordSet;

	for (int i = 0; i < wordDict.size(); i++) {
		wordSet.insert(wordDict[i]);
	}

	bool *dp = new bool[s.size() + 1]{0};
	dp[0] = true;

	for (int i = 1; i < s.size() + 1; i++) {
		for (int j = 0; j < s.size(); j++) {
			if (i - j >= 0 && dp[j] == true &&
					wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
				dp[i] = true;
			}
		}
	}

	return dp[s.size()];
}

int main() {
	string s;
	vector<string> wordDict;

	// s = "leetcode";
	// wordDict = {"leet", "code"};

	s = "applepenapple";
	wordDict = {"apple", "pen"};

	s = "catsandog";
	wordDict = {"cats", "dog", "sand", "and", "cat"};

	int res = wordBreak(s, wordDict);

	cout << res << endl;

	return 0;
}