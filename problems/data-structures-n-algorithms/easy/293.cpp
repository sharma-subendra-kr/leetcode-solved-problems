// 293. Flip Game
// https://leetcode.com/problems/flip-game/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

vector<string> generatePossibleNextMoves(string s) {
	vector<string> res = {};
	for (int i = 0; i < (int)s.size() - 1; i++) {
		if (s[i] == '+' && s[i + 1] == '+') {
			s[i] = s[i + 1] = '-';
			res.push_back(s);
			s[i] = s[i + 1] = '+';
		}
	}

	return res;
}

int main() {
	//
	string s;

	// s = "++++";
	s = "";

	vector<string> res = generatePossibleNextMoves(s);

	for (int i = 0; i < s.size(); i++) {
		cout << res[i] << endl;
	}

	return 0;
}