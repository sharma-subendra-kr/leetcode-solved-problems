// 388. Longest Absolute File Path
// https://leetcode.com/problems/longest-absolute-file-path/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

#include "../../../utils/customString.h"

int getTabCount(string &s, int start) {
	int count = 0;
	while (start < s.size() && s[start] == '\t') {
		count++;
		start++;
	}

	return count;
}

struct Item {
	int len;
	int tabs;
	bool isFile;

	Item(int l, int t, bool f) : len(l), tabs(t), isFile(f) {}
};

int lengthLongestPath(string input) {
	stack<Item *> st;
	vector<string> names = split(input, '\n');

	if (names.size() == 0) {
		return 0;
	} else if (names.size() == 1 && names[0].find('.') != string::npos) {
		return names[0].size();
	} else if (names.size() == 1) {
		return 0;
	}

	int sum = 0;
	int MAX = 0;

	for (int i = 0; i < names.size(); i++) {
		if (st.empty()) {
			vector<string> s = split(names[i], '\t');
			string word = s[s.size() - 1];
			int tabs = s.size() - 1;
			st.push(new Item(word.size(), tabs, word.find('.') != string::npos));
			sum = word.size();
		} else {
			vector<string> s = split(names[i], '\t');
			string word = s[s.size() - 1];
			int tabs = s.size() - 1;

			Item *item = st.top();
			if (item->isFile) {
				MAX = max(sum, MAX);
			}
			while (!st.empty() && st.top()->tabs >= tabs) {
				sum -= st.top()->len;
				st.pop();
			}

			int wordSize = tabs > 0 ? word.size() + 1 : word.size();

			st.push(new Item(wordSize, tabs, word.find('.') != string::npos));
			sum += (wordSize);
		}
	}

	if (!st.top()->isFile) {
		sum = 0;
	}

	return max(sum, MAX);
}

int main() {
	//
	string input;

	// input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
	// input = "dir\n\tsubdir1\n\t\tfile1."
	// 				"ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
	// input = "file1.txt\nfile2.txt\nlongfile.txt";
	input = "a";
	// input = "a\n\tb\n\t\tc";

	int res = lengthLongestPath(input);

	cout << res << endl;

	return 0;
}