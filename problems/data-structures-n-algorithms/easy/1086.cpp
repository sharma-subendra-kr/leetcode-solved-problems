// 1086. High Five
// https://leetcode.com/problems/high-five/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <string>

using namespace std;

bool comp(vector<int> &a, vector<int> &b) {
	if (a[0] != b[0]) {
		return a[0] < b[0];
	}
	return a[1] > b[1];
}

vector<vector<int>> highFive(vector<vector<int>> &items) {
	//
	vector<vector<int>> res;

	sort(items.begin(), items.end(), comp);

	int prev = -1;
	int iter = 0;
	while (iter < items.size()) {
		if (prev == items[iter][0]) {
			iter++;
			continue;
		}
		prev = items[iter][0];
		int count = 1;
		int sum = items[iter][1];
		int curr = iter + 1;
		vector<int> left = items[iter];
		while (curr < items.size() && left[0] == items[curr][0] && count != 5) {
			sum += items[curr][1];
			curr++;
			count++;
		}
		vector<int> t{items[iter][0], sum / count};
		res.push_back(t);
		iter += count;
	}

	return res;
}

int main() {
	//

	vector<vector<int>> items = {{1, 91},	{1, 92},	{2, 93}, {2, 97},
															 {1, 60},	{2, 77},	{1, 65}, {1, 87},
															 {1, 100}, {2, 100}, {2, 76}};

	vector<vector<int>> res = highFive(items);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}