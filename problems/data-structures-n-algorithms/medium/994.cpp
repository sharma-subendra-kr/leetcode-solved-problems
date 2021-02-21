// 994. Rotting Oranges
// https://leetcode.com/problems/rotting-oranges/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

// Need to revisit other solution
int dfs(vector<vector<int>> &grid, int i, int j, int **visited, int **cache) {
	if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size()) {
		return 0;
	} else if (grid[i][j] == 0) {
		return 0;
	} else if (visited[i][j] == 1) {
		return 0;
	} else if (grid[i][j] == 2) {
		return 1;
	} else if (cache[i][j] != 0) {
		return cache[i][j];
	}

	vector<int> res;

	visited[i][j] = 1;
	res.push_back(dfs(grid, i + 1, j, visited, cache));
	res.push_back(dfs(grid, i - 1, j, visited, cache));
	res.push_back(dfs(grid, i, j + 1, visited, cache));
	res.push_back(dfs(grid, i, j - 1, visited, cache));
	visited[i][j] = 0;

	int MIN = INT_MAX;
	for (int num : res) {
		if (num > 0 && num < MIN) {
			MIN = num;
		}
	}

	if (MIN == INT_MAX) {
		return 0;
	}
	return MIN + 1;
}

int orangesRotting(vector<vector<int>> &grid) {
	if (grid.size() == 0) {
		return 0;
	}

	int MAX = 0;

	int **visited = new int *[grid.size()];
	int **cache = new int *[grid.size()];
	for (int i = 0; i < grid.size(); i++) {
		visited[i] = new int[grid[0].size()]{0};
		cache[i] = new int[grid[0].size()]{0};
	}

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] == 1) {
				int rc = dfs(grid, i, j, visited, cache) - 1;
				if (rc > 0) {
					MAX = max(MAX, rc);
				} else {
					return -1;
				}
			}
		}
	}

	return MAX;
}

int main() {
	//
	vector<vector<int>> grid;

	// grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
	// grid = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
	// grid = {{0, 1}};
	// grid = {{0, 2, 2}};
	grid = {{2, 1, 1}, {1, 1, 1}, {0, 1, 2}};

	int res = orangesRotting(grid);

	cout << res << endl;

	return 0;
}