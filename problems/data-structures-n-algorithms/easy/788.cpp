// 788. Rotated Digits
// https://leetcode.com/problems/rotated-digits/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

// revisit the dynamic programming solution

int rotate(int n) {
	if (n == 2) {
		return 5;
	} else if (n == 5) {
		return 2;
	} else if (n == 6) {
		return 9;
	} else if (n == 9) {
		return 6;
	} else if (n == 0 || n == 1 || n == 8) {
		return n;
	}
	return -1;
}

int getRotatedDigit(int n) {
	int res = 0;
	int count = 0;
	while (n > 0) {
		int rem = n % 10;
		rem = rotate(rem);
		if (rem == -1) {
			return -1;
		}
		n /= 10;
		res = rem * pow(10, count) + res;
		count++;
	}

	return res;
}

int rotatedDigits(int N) {
	int sum = 0;
	int rotated;
	for (int i = 1; i <= N; i++) {
		rotated = getRotatedDigit(i);
		if (rotated != i && rotated != -1) {
			sum++;
		}
	}

	return sum;
}

int main() {
	//
	int N;

	N = 10;

	int good = rotatedDigits(N);

	cout << good << endl;

	return 0;
}