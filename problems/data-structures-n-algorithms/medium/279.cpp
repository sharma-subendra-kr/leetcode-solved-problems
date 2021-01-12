// 279. Perfect Squares
// https://leetcode.com/problems/perfect-squares/

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

int numSquares(int n) {
	int *dp = new int[n + 1];

	for (int i = 0; i < n + 1; i++) {
		dp[i] = INT_MAX;
	}

	dp[0] = 0;

	int i = 1;

	while (i < n + 1) {
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
		i++;
	}

	return dp[n];
}

int main() {
	int n = 12;

	int res = numSquares(n);

	cout << res << endl;

	return 0;
}