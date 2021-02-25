// 806. Number of Lines To Write String
// https://leetcode.com/problems/number-of-lines-to-write-string/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

vector<int> numberOfLines(vector<int> &widths, string s) {
	//
	int count = 0;
	int lines = 0;
	int iter = 100;
	while (count < s.size()) {
		iter = 100;
		while (iter != 0 && count < s.size()) {
			if (widths[(int)(s[count] - 97)] > iter) {
				break;
			}
			iter -= widths[(int)(s[count] - 97)];
			count++;
		}
		lines++;
	}

	vector<int> res = {lines, 100 - iter};

	return res;
}

int main() {
	//
	vector<int> widths;
	string s;

	widths = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
						10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
	s = "abcdefghijklmnopqrstuvwxyz";

	vector<int> res = numberOfLines(widths, s);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}

	return 0;
}