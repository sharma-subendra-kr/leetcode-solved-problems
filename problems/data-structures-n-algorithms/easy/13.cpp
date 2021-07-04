// 13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

int getValue(char c) {
	if (c == 'I') {
		return 1;
	} else if (c == 'V') {
		return 5;
	} else if (c == 'X') {
		return 10;
	} else if (c == 'L') {
		return 50;
	} else if (c == 'C') {
		return 100;
	} else if (c == 'D') {
		return 500;
	} else if (c == 'M') {
		return 1000;
	}
	return 0;
}

int romanToInt(string s) {
	//
	int value;
	int sum = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		value = getValue(s[i]);
		if (i < (s.size() - 1) && value < getValue(s[i + 1])) {
			sum -= getValue(s[i]);
			continue;
		}
		sum += value;
	}
	return sum;
}

int main() {
	//
	string s;

	s = "III";
	s = "IV";
	s = "IX";
	s = "LVIII";
	s = "MCMXCIV";

	int res = romanToInt(s);

	cout << res << endl;

	return 0;
}