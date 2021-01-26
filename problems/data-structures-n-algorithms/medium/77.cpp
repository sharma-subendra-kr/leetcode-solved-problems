// 77. Combinations
// https://leetcode.com/problems/combinations/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

void backtrack(int n, int k, int start, int count, vector<vector<int>> &res,
							 vector<int> &curr) {
	if (k == count) {
		res.push_back(vector<int>(curr.begin(), curr.end()));
		return;
	}

	for (int i = start; i <= n; i++) {
		curr.push_back(i);
		backtrack(n, k, i + 1, count + 1, res, curr);
		curr.pop_back();
	}
}

vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> res;

	vector<int> temp;
	backtrack(n, k, 1, 0, res, temp);

	return res;
}

int main() {
	int n, k;

	n = 4;
	k = 2;

	vector<vector<int>> res = combine(n, k);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}