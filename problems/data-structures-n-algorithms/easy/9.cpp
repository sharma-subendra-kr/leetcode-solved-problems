// 9. Palindrome Number
// https://leetcode.com/problems/palindrome-number/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

bool isPalindrome(int x) {
	long reverse = 0;
	int num = x;
	int rem;

	if (x < 0) {
		return false;
	}

	while (num != 0) {
		rem = num % 10;
		reverse = reverse * 10 + rem;
		num /= 10;
	}

	if (x == reverse) {
		return true;
	}
	return false;
}

int main() {
	int x;

	x = 121;

	bool res = isPalindrome(x);

	cout << res << endl;

	return 0;
}