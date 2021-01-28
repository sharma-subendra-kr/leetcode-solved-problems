// 342. Power of Four
// https://leetcode.com/problems/power-of-four/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <cmath>

using namespace std;

bool isPowerOfFour(int n) {
	if (n == 0) {
		return false;
	}

	return (!(n & ((long)n - 1))) && (n & 0x55555555);
}

// bool isPowerOfFour(int n) {
// 	double res = log2(n);

// 	return (fmod(res, 2) == 0) || res == 1 && n != 2 ? true : false;
// }

int main() {
	int n;

	n = 32;

	bool res = isPowerOfFour(n);

	cout << res << endl;

	return 0;
}