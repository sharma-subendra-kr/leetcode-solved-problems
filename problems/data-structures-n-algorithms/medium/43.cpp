// 43. Multiply Strings
// https://leetcode.com/problems/multiply-strings/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <stack>

using namespace std;

// num size can be 200 digits long so this doesnt work
// long convertToInt(string str) {
// 	long num = 0;
// 	long count = 0;

// 	while (count != str.size()) {
// 		num = num * 10 + (str[count] - '0');

// 		count++;
// 	}

// 	return num;
// }

// string convertToString(long num) {
// 	string res = "";

// 	while (num != 0) {
// 		int rem = num % 10;
// 		num /= 10;

// 		res = to_string(rem) + res;
// 	}

// 	return res == "" ? "0" : res;
// }

// string multiply(string num1, string num2) {
// 	//
// 	return convertToString((long)convertToInt(num1) * (long)convertToInt(num2));
// }

string multiply(string num1, string num2) {
	int *arr = new int[num1.size() + num2.size()]{0};

	for (int i = num1.size() - 1; i >= 0; i--) {
		for (int j = num2.size() - 1; j >= 0; j--) {
			int prod = (int)(num1[i] - '0') * (int)(num2[j] - '0');

			int pos1 = i + j;
			int pos2 = i + j + 1;

			int sum = arr[pos2] + prod;
			arr[pos1] += sum / 10;
			arr[pos2] = sum % 10;
		}
	}

	string s = "";
	int start = 0;
	for (int i = 0; i < num1.size() + num2.size(); i++) {
		if (start == 0 && arr[i] == 0) {
			continue;
		}
		start = 1;
		s += (char)arr[i] + 48;
	}

	return s.size() > 0 ? s : "0";
}

int main() {
	string num1, num2;

	// num1 = "123456789";
	// num2 = "987654321";

	num1 = "123";
	num2 = "456";

	string res = multiply(num1, num2);

	cout << res << endl;
}