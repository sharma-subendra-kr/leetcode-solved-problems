// 415. Add Strings
// https://leetcode.com/problems/add-strings/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

string addStrings(string num1, string num2) {
	//
	string res = "";
	int carry = 0;
	int len = min(num1.size(), num2.size());
	int iter1 = num1.size() - 1;
	int iter2 = num2.size() - 1;
	while (iter1 >= 0 && iter2 >= 0) {
		int a = num1[iter1] - '0';
		int b = num2[iter2] - '0';
		int sum = a + b + carry;

		if (sum >= 10) {
			carry = 1;
			sum = sum % 10;
		} else {
			carry = 0;
		}

		res += (char)sum + '0';
		iter1--;
		iter2--;
	}

	string &greater = num1.size() > num2.size() ? num1 : num2;
	int iter = greater.size() - len;
	while (iter > 0) {
		iter--;
		int a = greater[iter] - '0';
		int sum = a + carry;

		if (sum >= 10) {
			carry = 1;
			sum = sum % 10;
		} else {
			carry = 0;
		}

		res += (char)sum + '0';
	}

	if (carry > 0) {
		res += (char)carry + '0';
	}

	reverse(res.begin(), res.end());

	return res;
}

int main() {
	//
	string num1, num2;

	// num1 = "123";
	// num2 = "123";

	// num1 = "123";
	// num2 = "129";

	// num1 = "123";
	// num2 = "1123";

	num1 = "1";
	num2 = "9";

	string res = addStrings(num1, num2);

	cout << res << endl;

	return 0;
}