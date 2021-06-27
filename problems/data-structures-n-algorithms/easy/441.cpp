// 441. Arranging Coins
// https: // leetcode.com/problems/arranging-coins/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

// Worst solution
// int arrangeCoins(int n) {
// 	//
// 	int num = 1;
// 	int rows = 0;
// 	int prev = 0;
// 	while (n >= num) {
// 		if (num > prev) {
// 			cout << num << endl;
// 			rows++;
// 		}
// 		n -= num;
// 		prev = num;
// 		num++;
// 	}

// 	return rows;
// }

// Best solution
// int arrangeCoins(int n) {
// 	//
// 	double sroot = (double)sqrt((double)2 * n + (double)1 / 4) - (double)1 / 2;
// 	return floor(sroot);
// }

// Binary search
int arrangeCoins(int n) {
	//
	int low = 0, high = n;
	int sum = n;
	int max = 0;
	while (low <= high) {
		long mid = (low + high) / 2;
		long curr = mid * (mid + 1) / 2;

		if (curr <= sum && mid > max) {
			max = mid;
		}

		if (curr > sum) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return max;
}

int main() {
	int res = arrangeCoins(36);
	cout << res << endl;
	return 0;
}