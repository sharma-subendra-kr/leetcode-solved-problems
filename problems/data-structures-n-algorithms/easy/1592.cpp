// 1592. Rearrange Spaces Between Words
// https://leetcode.com/problems/rearrange-spaces-between-words/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

string reorderSpaces(string text) {
	//
	//
	int start = -1;
	int countSpaces = 0;
	int countWords = 0;

	for (int i = 0; i < text.size(); i++) {
		if (text[i] == ' ') {
			countSpaces++;
		}
		if (text[i] != ' ' && start == -1) {
			start = i;
		} else if (text[i] == ' ' && start != -1) {
			start = -1;
			countWords++;
		}
		if (text[i] != ' ' && i == text.size() - 1) {
			countWords++;
		}
	}

	int spacesBetn = (countWords - 1) > 0 ? countSpaces / (countWords - 1) : 0;

	string res = "";
	int iter = 0;
	while (iter < text.size()) {
		int cnt = 0;
		int start = iter;
		while (iter < text.size() && text[iter] != ' ') {
			cnt++;
			iter++;
		}
		if (cnt != 0) {
			res += text.substr(start, cnt);
			if (spacesBetn > 0 && countSpaces / spacesBetn > 0) {
				string spaces(spacesBetn, ' ');
				countSpaces -= spacesBetn;
				res += spaces;
			}
			continue;
		}
		iter++;
	}

	if (countSpaces != 0) {
		string spaces(countSpaces, ' ');
		res += spaces;
	}

	return res;
}

int main() {
	//

	string text;

	// text = "  this   is  a sentence  ";
	// text = " practice   makes   perfect";
	text = "a b   c d";

	string res = reorderSpaces(text);

	cout << res << endl;

	return 0;
}