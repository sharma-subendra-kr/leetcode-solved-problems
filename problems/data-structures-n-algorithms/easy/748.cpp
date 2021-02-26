// 748. Shortest Completing Word
// https://leetcode.com/problems/shortest-completing-word/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

string shortestCompletingWord(string licensePlate, vector<string> &words) {
	//
	unordered_map<char, int> umap;
	int count = 0;
	for (int i = 0; i < licensePlate.size(); i++) {
		auto iter = umap.find(tolower(licensePlate[i]));
		if (isalpha(tolower(licensePlate[i])) && iter != umap.end()) {
			iter->second++;
			count++;
		} else if (isalpha(licensePlate[i])) {
			umap.insert({tolower(licensePlate[i]), 1});
			count++;
		}
	}

	string res;
	for (int i = 0; i < words.size(); i++) {
		unordered_map<char, int> tempMap(umap.begin(), umap.end());
		int cnt = 0;
		for (int j = 0; j < words[i].size(); j++) {
			auto iter = tempMap.find({words[i][j]});
			if (iter != tempMap.end()) {
				iter->second--;
				cnt++;
				if (iter->second == 0) {
					tempMap.erase(words[i][j]);
				}
			}
		}
		if (cnt == count && (res.size() > words[i].size() || res.size() == 0)) {
			res = words[i];
		}
	}

	return res;
}

int main() {
	//
	string licensePlate;
	vector<string> words;
	;

	licensePlate = "1s3 PSt";
	words = {"step", "steps", "stripe", "stepple"};

	string res = shortestCompletingWord(licensePlate, words);

	cout << res << endl;

	return 0;
}
