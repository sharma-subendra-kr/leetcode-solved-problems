// 231. Power of Two
// https://leetcode.com/problems/power-of-two/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <cmath>

using namespace std;

// bool isPowerOfTwo(int n) {
// 	double res = log2(n);

// 	return fmod(res, 2) == 0 || fmod(res, 2) == 1 ? true : false;
// }

bool isPowerOfTwo(int n) {
	if (n == 0) {
		return false;
	}
	return !(n & ((long)n - 1));
}

int main() {
	int n;

	// n = 2097151;
	n = 8;

	bool res = isPowerOfTwo(n);

	cout << res << endl;

	return 0;
}