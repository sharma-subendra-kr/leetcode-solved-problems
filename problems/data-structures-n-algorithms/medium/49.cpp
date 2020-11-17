// 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/

#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

// string getAnagram(string str) {
// 	int base[26] = {0};
// 	int len = str.size();
// 	int i;
// 	string res(77, '-');

// 	for (i = 0; i < len; i++) {
// 		base[str[i] - 'a']++;
// 	}

// 	for (i = 0; i < 26; i++) {
// 		if (i != 25) {
// 			res.append(to_string(base[i]) + '-');
// 		} else {
// 			res.append(to_string(base[i]));
// 		}
// 	}

// 	return res;
// }

string getAnagram(string str) {
	string res = str;

	sort(res.begin(), res.end());

	return res;
}

vector<vector<string>> groupAnagrams(vector<string> &strs) {
	map<string, vector<string>> hmap;
	vector<vector<string>> res;
	int i, cnt = 0;
	string anagram;

	for (i = 0; i < strs.size(); i++) {
		anagram = getAnagram(strs[i]);

		auto tIter = hmap.find(anagram);
		if (tIter != hmap.end()) {
			tIter->second.push_back(strs[i]);
		} else {
			vector<string> nlist;
			nlist.push_back(strs[i]);
			hmap.insert({anagram, nlist});
		}
	}

	for (auto iter = hmap.begin(); iter != hmap.end(); iter++) {
		res.push_back(iter->second);
	}

	return res;
}

int main() {
	vector<string> strs;
	vector<vector<string>> res;
	string temp;

	int n = 0, i, j;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> temp;
		strs.push_back(temp);
	}

	res = groupAnagrams(strs);

	for (i = 0; i < res.size(); i++) {
		for (j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}