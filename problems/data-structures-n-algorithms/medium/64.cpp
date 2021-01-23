// 64. Minimum Path Sum
// https://leetcode.com/problems/minimum-path-sum/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <limits.h>

using namespace std;

// Working DFS solution
// int dfs(vector<vector<int>> &grid, int i, int j, bool **visited, int **cache)
// { 	if (i == grid.size() - 1 && j == grid[0].size() - 1) { 		return
// grid[i][j]; 	} else if (i == grid.size() || j == grid[0].size() || i == -1 ||
// j == -1) { 		return -1; 	} else if (visited[i][j] == 1) { 		return -1;
// 	}

// 	if (cache[i][j] != -1) {
// 		return cache[i][j];
// 	}

// 	visited[i][j] = 1;

// 	vector<int> r;
// 	r.push_back(dfs(grid, i + 1, j, visited, cache));
// 	r.push_back(dfs(grid, i, j + 1, visited, cache));

// 	visited[i][j] = 0;

// 	int min = 100000;
// 	for (int k = 0; k < 2; k++) {
// 		if (r[k] < min && r[k] >= 0) {
// 			min = r[k];
// 		}
// 	}

// 	cache[i][j] = grid[i][j] + min;

// 	return cache[i][j];
// }

// int minPathSum(vector<vector<int>> &grid) {
// 	if (grid.size() == 0) {
// 		return 0;
// 	}
// 	bool **visited = new bool *[grid.size()];
// 	int **cache = new int *[grid.size()];
// 	for (int i = 0; i < grid.size(); i++) {
// 		visited[i] = new bool[grid[0].size()]{0};
// 		cache[i] = new int[grid[0].size()]{0};

// 		for (int j = 0; j < grid[0].size(); j++) {
// 			cache[i][j] = -1;
// 		}
// 	}

// 	return dfs(grid, 0, 0, visited, cache);
// }

int minPathSum(vector<vector<int>> &grid) {
	if (grid.size() == 0) {
		return 0;
	}

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (i == 0 && j == 0) {
				continue;
			}
			int top = INT_MAX - grid[i][j];
			int left = INT_MAX - grid[i][j];
			if (i - 1 >= 0) {
				top = grid[i - 1][j];
			}
			if (j - 1 >= 0) {
				left = grid[i][j - 1];
			}
			grid[i][j] = min(top + grid[i][j], left + grid[i][j]);
		}
	}

	return grid[grid.size() - 1][grid[0].size() - 1];
}

int main() {
	vector<vector<int>> grid;

	grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
	// grid = {{1, 3}, {1, 5}};
	// grid = {{1, 2, 3}, {4, 5, 6}};
	// grid = {{1, 2, 5}, {3, 2, 1}};

	int sum = minPathSum(grid);

	cout << sum << endl;

	return 0;
}