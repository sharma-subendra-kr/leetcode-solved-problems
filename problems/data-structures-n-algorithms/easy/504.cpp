// 504. Base 7
// https://leetcode.com/problems/base-7/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

string convertToBase7(int num) {
	if (num == 0) {
		return "0";
	}

	string res = "";
	bool isNegative = num < 0 ? true : false;
	num = abs(num);
	while (num != 0) {
		int rem = num % 7;
		num /= 7;
		res += to_string(rem);
	}

	reverse(res.begin(), res.end());

	return isNegative ? "-" + res : res;
}

int main() {
	//
	string res = convertToBase7(-7);

	cout << res << endl;

	return 0;
}