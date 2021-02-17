// 246. Strobogrammatic Number
// https://leetcode.com/problems/strobogrammatic-number/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

int rotate(int n) {
	if (n == 6) {
		return 9;
	} else if (n == 9) {
		return 6;
	} else if (n == 0 || n == 1 || n == 8) {
		return n;
	}
	return -1;
}

string getRotatedDigit(string n) {
	string res = "";
	int count = 0;

	for (int i = n.size() - 1; i >= 0; i--) {
		int rem = n[i] - '0';
		rem = rotate(rem);
		if (rem == -1) {
			return "";
		}
		res = (char)(rem + '0') + res;
		count++;
	}

	return res;
}

bool isStrobogrammatic(string num) {
	string rotated = getRotatedDigit(num);
	string reversed = string(rotated.rbegin(), rotated.rend());
	if (reversed == num) {
		return true;
	}
	return false;
}

int main() {
	string num;

	num = "88";
	// num = "69";
	// num = "962";

	bool res = isStrobogrammatic(num);

	cout << res << endl;

	return 0;
}