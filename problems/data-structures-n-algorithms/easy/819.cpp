// 819. Most Common Word
// https://leetcode.com/problems/most-common-word/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

string toLowerCase(string str) {
	vector<char> arr;

	for (int i = 0; i < str.size(); i++) {
		arr.push_back(tolower(str[i]));
	}

	return string(arr.begin(), arr.end());
}

// Do in seperate loops cuz space complexity O(n) == O(n/2)
string mostCommonWord(string paragraph, vector<string> &banned) {
	//
	unordered_set<string> uset(banned.begin(), banned.end());
	unordered_map<string, int> mp;
	unordered_set<char> symbols({'!', '?', '\'', ',', ';', '.'});
	int max = 0;
	string maxStr;

	int iter = 0;
	while (iter < paragraph.size()) {
		if (paragraph[iter] == ' ' ||
				symbols.find(paragraph[iter]) != symbols.end()) {

			iter++;
			continue;
		}

		int start = iter;
		while (iter < paragraph.size() && paragraph[iter] != ' ' &&
					 symbols.find(paragraph[iter]) == symbols.end()) {
			iter++;
		}
		string sub = toLowerCase(paragraph.substr(start, iter - start));
		if (uset.find(sub) != uset.end()) {
			continue;
		}

		auto mpIter = mp.find(sub);
		if (mpIter == mp.end()) {
			mp.insert({sub, 0});
			mpIter = mp.find(sub);
		}
		mpIter->second++;

		if (mpIter->second > max) {
			max = mpIter->second;
			maxStr = sub;
		}
	}

	return maxStr;
}

int main() {
	//
	string paragraph;
	vector<string> banned;

	// paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
	// banned = {"hit"};

	paragraph = "Bob";
	banned = {};

	string res = mostCommonWord(paragraph, banned);

	cout << res << endl;

	return 0;
}