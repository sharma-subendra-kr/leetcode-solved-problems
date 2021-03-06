// 40. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <string>

using namespace std;

// Try out this solution also
// https://leetcode.com/problems/combination-sum-ii/discuss/16878/Combination-Sum-I-II-and-III-Java-solution-(see-the-similarities-yourself)

vector<vector<int>> dfs(vector<int> &candidates, int sum, int start) {
	vector<vector<int>> res;
	int prev;

	for (int i = start; i < candidates.size(); i++) {
		if (i != start && candidates[i] == prev) {
			continue;
		}
		prev = candidates[i];

		if (sum - candidates[i] == 0) {
			vector<int> final = {candidates[i]};
			res.push_back(final);
			break;
		} else if (sum - candidates[i] > 0) {
			vector<vector<int>> tempRes;

			tempRes = dfs(candidates, sum - candidates[i], i);

			for (int j = 0; j < tempRes.size(); j++) {
				tempRes[j].push_back(candidates[i]);
				res.push_back(tempRes[j]);
			}
		}
	}
	return res;
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
	sort(candidates.begin(), candidates.end());
	return dfs(candidates, target, 0);
}

int main() {
	vector<int> candidates;
	int target;

	// candidates = {2, 3, 6, 7};
	// target = 8;

	candidates = {2, 3, 6, 7};
	target = 7;

	vector<vector<int>> res = combinationSum(candidates, target);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}