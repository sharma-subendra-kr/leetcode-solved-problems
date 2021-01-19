// 338. Counting Bits
// https://leetcode.com/problems/counting-bits/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

vector<int> countBits(int num) {
	vector<int> res(num + 1, 0);

	for (int i = 1; i <= num; i++) {
		res[i] = res[i >> 1] + (i & 1);
	}

	return res;
}

int main() {
	int num;

	num = 5;

	vector<int> res = countBits(num);

	for (int i : res) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}