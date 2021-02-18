// 463. Island Perimeter
// https://leetcode.com/problems/island-perimeter/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

int dfs(vector<vector<int>> &grid, int i, int j, int **visited) {
	if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size()) {
		return 1;
	} else if (visited[i][j] == 1) {
		return 0;
	} else if (grid[i][j] == 0) {
		return 1;
	}

	visited[i][j] = 1;

	int a = dfs(grid, i + 1, j, visited);
	int b = dfs(grid, i - 1, j, visited);
	int c = dfs(grid, i, j + 1, visited);
	int d = dfs(grid, i, j - 1, visited);

	return a + b + c + d;
}

int islandPerimeter(vector<vector<int>> &grid) {
	//
	if (grid.size() == 0) {
		return 0;
	}

	int **visited = new int *[grid.size()];
	for (int i = 0; i < grid.size(); i++) {
		visited[i] = new int[grid[0].size()]{0};
	}

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] == 1) {
				return dfs(grid, i, j, visited);
			}
		}
	}

	return 0;
}

int main() {
	//
	vector<vector<int>> grid;

	// grid = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
	grid = {{0, 1}};

	int res = islandPerimeter(grid);

	cout << res << endl;

	return 0;
}