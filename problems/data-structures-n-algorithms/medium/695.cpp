// 695. Max Area of Island
// https://leetcode.com/problems/max-area-of-island/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

int dfs(vector<vector<int>> &grid, int i, int j, int **visited, int **cache) {
	if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
		return 0;
	} else if (visited[i][j] == 1) {
		return 0;
	} else if (grid[i][j] == 0) {
		return 0;
	} else if (cache[i][j] != 0) {
		return cache[i][j];
	}

	visited[i][j] = 1;

	int a = dfs(grid, i + 1, j, visited, cache);
	int b = dfs(grid, i - 1, j, visited, cache);
	int c = dfs(grid, i, j + 1, visited, cache);
	int d = dfs(grid, i, j - 1, visited, cache);

	cache[i][j] = 1 + a + b + c + d;

	return cache[i][j];
}

int maxAreaOfIsland(vector<vector<int>> &grid) {
	//
	if (grid.size() == 0) {
		return 0;
	}

	int **cache = new int *[grid.size()];
	int **visited = new int *[grid.size()];
	for (int i = 0; i < grid.size(); i++) {
		visited[i] = new int[grid[0].size()]{0};
		cache[i] = new int[grid[0].size()]{0};
	}

	int sum = 0;
	int MAX = 0;

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			sum = dfs(grid, i, j, visited, cache);
			MAX = max(sum, MAX);
		}
	}

	return MAX;
}

int main() {
	//

	vector<vector<int>> grid;

	grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
					{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
					{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

	// grid = {
	// 		{1, 0, 1},
	// 		{1, 1, 1},
	// 		{0, 0, 1},
	// };

	// grid = {{0, 1, 0, 1}, {0, 1, 1, 1}, {0, 0, 0, 1}, {1, 1, 1, 0}, {1, 1, 0,
	// 0}};

	// grid = {
	// 		{0, 0, 1},
	// 		{0, 0, 1},
	// 		{0, 1, 1},
	// };

	int res = maxAreaOfIsland(grid);

	cout << res << endl;

	return 0;
}