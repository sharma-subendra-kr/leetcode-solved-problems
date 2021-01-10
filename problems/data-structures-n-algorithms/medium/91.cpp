// 91. Decode Ways
// https://leetcode.com/problems/decode-ways/

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Time limit exceeded
// void decode(string s, int i, int *count) {
// 	if (i < s.size() && s[i] - '0' < 1) {
// 		return;
// 	}

// 	if (i == s.size() - 1 || i == s.size()) {
// 		(*count)++;
// 		return;
// 	}

// 	decode(s, i + 1, count);

// 	if (stoi(s.substr(i, 2)) <= 26) {
// 		decode(s, i + 2, count);
// 	}
// }

// int numDecodings(string s) {
// 	if (s.size() == 0) {
// 		return 0;
// 	}

// 	int count = 0;

// 	decode(s, 0, &count);

// 	return count;
// }

int numDecodings(string s) {
	if (s.size() == 0) {
		return 0;
	}

	int num1;
	int num2;
	int _sum = 1;
	int sum = s[0] != '0' ? 1 : 0;
	int temp;

	for (int i = 1; i < s.size(); i++) {
		temp = 0;

		num1 = s[i] - '0';
		if (num1 > 0 && num1 < 10) {
			temp = sum;
		}

		num2 = stoi(s.substr(i - 1, 2));
		if (num2 >= 10 && num2 <= 26) {
			temp += _sum;
		}
		_sum = sum;
		sum = temp;
	}

	return sum;
}

int main() {
	string s;

	// s = "226";
	// s = "2265";
	// s = "2225";
	// s = "0";
	// s = "12";
	// s = "111111111111111111111111111111111111111111111";
	// s = "10";
	s = "2101";

	int res = numDecodings(s);

	cout << res << endl;

	return 0;
}