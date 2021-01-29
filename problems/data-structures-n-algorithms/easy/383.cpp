// 383. Ransom Note
// https://leetcode.com/problems/ransom-note/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
	unordered_map<char, int> mp;

	for (int i = 0; i < magazine.size(); i++) {
		if (mp.find(magazine[i]) != mp.end()) {
			mp.find(magazine[i])->second++;
		} else {
			mp.insert({magazine[i], 1});
		}
	}

	for (int i = 0; i < ransomNote.size(); i++) {
		auto iter = mp.find(ransomNote[i]);
		if (iter == mp.end() || iter->second <= 0) {
			return false;
		} else {
			iter->second--;
		}
	}

	return true;
}

int main() {
	string ransomNote, magazine;

	ransomNote = "a";
	magazine = "ab";

	bool res = canConstruct(ransomNote, magazine);

	cout << res << endl;

	return 0;
}