// 263. Ugly Number
// https://leetcode.com/problems/ugly-number/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

bool isUgly(int num) {
	if (num == 0) {
		return false;
	}

	while (num % 2 == 0)
		num /= 2;
	while (num % 3 == 0)
		num /= 3;
	while (num % 5 == 0)
		num /= 5;

	return num == 1;
}

int main() {
	int num;

	num = 15;

	bool res = isUgly(num);

	cout << res << endl;

	return 0;
}