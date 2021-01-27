// 258. Add Digits
// https://leetcode.com/problems/add-digits/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

// int addDigits(int num) {
// 	int n = num;

// 	while (n / 10 != 0) {
// 		int sum = 0;
// 		while (n != 0) {
// 			int rem = n % 10;
// 			sum += rem;
// 			n /= 10;
// 		}
// 		n = sum;
// 	}

// 	return n;
// }

int addDigits(int num) {
	if (num == 0) {
		return 0;
	} else if (num % 9 == 0) {
		return 9;
	} else {
		return num % 9;
	}
}

int main() {
	int num;

	num = 38;

	int res = addDigits(num);

	cout << res << endl;

	return 0;
}