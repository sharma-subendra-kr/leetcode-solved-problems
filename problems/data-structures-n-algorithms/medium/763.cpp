// 763. Partition Labels
// https://leetcode.com/problems/partition-labels/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

vector<int> partitionLabels(string S) {
	vector<int> res;
	unordered_map<char, int> mp;

	for (int i = 0; i < S.size(); i++) {
		char c = S[i];
		auto iter = mp.find(c);
		if (iter == mp.end()) {
			mp.insert({c, i});
		} else {
			iter->second = i;
		}
	}

	int start = 0;
	int last = 0;
	for (int i = 0; i < S.size(); i++) {
		last = max(mp.find(S[i])->second, last);

		if (i == last) {
			res.push_back(last - start + 1);
			start = last + 1;
		}
	}

	return res;
}

int main() {
	string s;

	s = "ababcbacadefegdehijhklij";

	vector<int> res = partitionLabels(s);

	for (int i : res) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}