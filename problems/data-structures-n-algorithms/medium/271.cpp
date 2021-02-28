// 271. Encode and Decode Strings
// https://leetcode.com/problems/encode-and-decode-strings/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

// Encodes a list of strings to a single string.
string encode(vector<string> &strs) {
	string res = "";
	for (string &str : strs) {
		res += (to_string(str.size()) + ":" + str);
	}
	return res;
}

// Decodes a single string to a list of strings.
vector<string> decode(string s) {
	vector<string> res;

	int start = 0;
	while (start < s.size()) {
		int idx = s.find(':', start);
		int len = stoi(s.substr(start, idx - start));
		res.push_back(s.substr(idx + 1, len));
		start = idx + 1 + len;
	}

	return res;
}