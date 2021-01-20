// 739. Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int> &T) {
	stack<pair<int, int>> s;
	vector<int> res(T.size(), 0);

	for (int i = 0; i < T.size(); i++) {
		if (s.empty()) {
			s.push({T[i], i});
			continue;
		}
		int count = 1;
		while (!s.empty() && s.top().first < T[i]) {
			res[s.top().second] = i - s.top().second;
			s.pop();
		}
		s.push({T[i], i});
	}

	while (!s.empty()) {
		res[s.top().second] = 0;
		s.pop();
	}

	return res;
}

int main() {
	vector<int> T;

	T = {73, 74, 75, 71, 69, 72, 76, 73};

	vector<int> res = dailyTemperatures(T);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;
}