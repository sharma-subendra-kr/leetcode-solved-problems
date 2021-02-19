// 1056. Confusing Number
// https://leetcode.com/problems/confusing-number/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

int rotate(int n) {
	if (n == 6) {
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
		res = res * 10 + rem;
		count++;
	}

	return res;
}

bool confusingNumber(int N) {
	int rotated = getRotatedDigit(N);
	if (rotated != N && rotated != -1) {
		return true;
	}
	return false;
}

int main() {
	//
	int N;

	// N = 89;
	N = 916;

	bool res = confusingNumber(N);

	cout << res << endl;

	return 0;
}