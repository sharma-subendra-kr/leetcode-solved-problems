// 422. Valid Word Square
// https://leetcode.com/problems/valid-word-square/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

// bool validWordSquare(vector<string> &words) {
// 	//
// 	int i = 0;

// 	while (i < words.size() && i < words[i].size()) {
// 		int _i = i + 1;

// 		bool flag = true;
// 		while (_i < words.size() && i < words[_i].size() && _i < words[i].size())
// { 			if (words[_i][i] != words[i][_i]) { 				flag = false; break;
// 			}
// 			_i++;
// 		}

// 		int len = _i;
// 		if (_i + 1 < words.size() && i < words[_i + 1].size()) {
// 			len += 1;
// 		}

// 		if (flag == false || len != words[i].size()) {
// 			return false;
// 		}

// 		i++;
// 	}

// 	return true;
// }

bool validWordSquare(vector<string> &words) {
	for (int i = 0; i < words.size(); i++) {
		for (int j = 0; j < words[i].size(); j++) {
			if (j >= words.size() || i >= words[j].size() ||
					words[i][j] != words[j][i]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	//
	vector<string> words;

	// words = {"abcd", "bnrt", "crmy", "dtye"};
	// words = {"ball", "asee", "let", "lep"};
	words = {"abcd", "bnrt", "crm", "dt"};

	bool res = validWordSquare(words);

	cout << res << endl;

	return 0;
}