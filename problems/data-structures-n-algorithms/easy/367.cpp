// 367. Valid Perfect Square
// https://leetcode.com/problems/valid-perfect-square/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;
// Linear method 1 + 3 + 5 + 7
// bool isPerfectSquare(int num) {
// 	long sum = 0;
// 	int count = 1;
// 	while (sum < num) {
// 		sum += count;
// 		count += 2;
// 	}
// 	return sum == num;
// }

// binary search
// bool isPerfectSquare(int num) {
// 	int low = 1;
// 	int high = num;

// 	while (low <= high) {
// 		long mid = ((long)low + (long)high) / 2;
// 		long prod = mid * mid;
// 		if (prod == num) {
// 			return true;
// 		}

// 		if (prod > num) {
// 			high = mid - 1;
// 		} else if (prod < num) {
// 			low = mid + 1;
// 		}
// 	}
// 	return false;
// }

// Newton's method
bool isPerfectSquare(int num) {
	long r = num;
	while (r * r > num) {
		r = (r + num / r) / 2;
	}
	return r * r == num;
}

int main() {
	int num = 16;

	bool res = isPerfectSquare(num);

	cout << res << endl;

	return 0;
}