// 140. Word Break II
// https://leetcode.com/problems/word-break-ii/

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

// Time limit exceeded
// void dfs(string s, string str, int start, vector<string> &res,
// 				 unordered_set<string> uset) {
// 	if (start == s.size()) {
// 		res.push_back(str);
// 		return;
// 	}

// 	for (int i = start; i < s.size(); i++) {
// 		string sub = s.substr(start, i - start + 1);
// 		if (uset.find(sub) != uset.end()) {
// 			dfs(s, start == 0 ? str + sub : str + " " + sub, i + 1, res, uset);
// 		}
// 	}
// }

// vector<string> wordBreak(string s, vector<string> &wordDict) {
// 	vector<string> res;
// 	unordered_set<string> uset;

// 	for (int i = 0; i < wordDict.size(); i++) {
// 		uset.insert(wordDict[i]);
// 	}

// 	dfs(s, "", 0, res, uset);

// 	return res;
// }

void combine(string pre, vector<string> &arr, int last, int size) {
	for (int i = 0; i < arr.size(); i++) {
		arr[i] = pre + " " + arr[i];
	}

	if (arr.size() == 0 && last == size - 1) {
		arr.push_back(pre);
	}
}

vector<string> dfs(string s, int start, unordered_set<string> &uset,
									 unordered_map<int, vector<string>> &memo) {
	vector<string> res;
	if (memo.count(start)) {
		return memo[start];
	}

	if (start == s.size()) {
		return vector<string>();
	}

	for (int i = start; i < s.size(); i++) {
		string sub = s.substr(start, i - start + 1);
		if (uset.find(sub) != uset.end()) {

			vector<string> _res = dfs(s, i + 1, uset, memo);

			combine(sub, _res, i, s.size());
			res.insert(res.end(), _res.begin(), _res.end());
		}
	}

	memo[start] = res;

	return res;
}

vector<string> wordBreak(string s, vector<string> &wordDict) {
	vector<string> res;
	unordered_set<string> uset;
	unordered_map<int, vector<string>> memo;

	for (int i = 0; i < wordDict.size(); i++) {
		uset.insert(wordDict[i]);
	}

	res = dfs(s, 0, uset, memo);

	return res;
}

int main() {
	string s;
	vector<string> wordDict;

	s = "catsanddog";
	wordDict = {"cat", "cats", "and", "sand", "dog"};

	// s = "pineapplepenapple";
	// wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};

	// s = "catsandog";
	// wordDict = {"cats", "dog", "sand", "and", "cat"};

	// s =
	// "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	// 		"aaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	// 		"aaaaaaa";
	// wordDict = {"a",			"aa",			 "aaa",			 "aaaa",			"aaaaa",
	// 						"aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};

	vector<string> res = wordBreak(s, wordDict);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}

	return 0;
}