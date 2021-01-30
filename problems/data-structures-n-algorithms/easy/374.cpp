// 374. Guess Number Higher or Lower
// https://leetcode.com/problems/guess-number-higher-or-lower/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

int guessNumber(int n) {
	int low = 0;
	int high = n;

	while (low <= high) {
		int mid = ((long)low + (long)high) / 2;
		int res = guess(mid);

		if (res == -1) {
			high = mid - 1;
		} else if (res == 1) {
			low = mid + 1;
		} else {
			return mid;
		}
	}

	return 0;
}

int main() {
	int n;

	n = 10;

	int res = guessNumber(n);

	cout << res << endl;

	return 0;
}