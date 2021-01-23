// 67. Add Binary
// https://leetcode.com/problems/add-binary/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <limits.h>
#include <string.h>

using namespace std;

char add(char a, char b, int *carry) {
	int sum = (a - '0') + (b - '0') + *carry;

	*carry = sum / 2;
	return (char)(sum % 2 + '0');

	// if (sum == 0) {
	// 	return '0';
	// } else if (sum == 1) {
	// 	*carry = 0;
	// 	return '1';
	// } else if (sum == 2) {
	// 	*carry = 1;
	// 	return '0';
	// } else if (sum == 3) {
	// 	*carry = 1;
	// 	return '1';
	// }
	// return '0';
}

string addBinary(string a, string b) {
	int ai = a.size() - 1;
	int bi = b.size() - 1;

	string res = "";

	int carry = 0;

	while (ai >= 0 && bi >= 0) {
		res = add(a[ai], b[bi], &carry) + res;
		ai--;
		bi--;
	}

	while (ai >= 0) {
		res = add(a[ai], '0', &carry) + res;
		ai--;
	}

	while (bi >= 0) {
		res = add('0', b[bi], &carry) + res;
		bi--;
	}

	if (carry == 1) {
		res = '1' + res;
	}

	return res;
}

int main() {
	string a, b;

	// a = "11";
	// b = "1";

	a = "1010";
	b = "1011";

	string res = addBinary(a, b);

	cout << res << endl;

	return 0;
}