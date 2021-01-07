// 329. Longest Increasing Path in a Matrix
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

int dfs(vector<vector<int>> &matrix, int i, int j, int value, int **cache) {
	if (i < 0 || i == matrix.size() || j < 0 || j == matrix[0].size()) {
		return 0;
	}

	if (matrix[i][j] <= value) {
		return -1;
	}

	if (cache[i][j] != 0) {
		return cache[i][j];
	}

	int a = dfs(matrix, i - 1, j, matrix[i][j], cache);
	int b = dfs(matrix, i + 1, j, matrix[i][j], cache);
	int c = dfs(matrix, i, j - 1, matrix[i][j], cache);
	int d = dfs(matrix, i, j + 1, matrix[i][j], cache);

	int _max = max({a, b, c, d});
	int _res = max(_max + 1, 1);
	cache[i][j] = _res;
	return _res;
}

int longestIncreasingPath(vector<vector<int>> &matrix) {
	if (matrix.size() == 0) {
		return 0;
	}

	int **cache;
	cache = new int *[matrix.size()];
	for (int i = 0; i < matrix.size(); i++)
		cache[i] = new int[matrix[0].size()]{0};

	int max = 0;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			int temp = dfs(matrix, i, j, INT_MIN, cache);
			if (temp > max) {
				max = temp;
			}
		}
	}
	return max;
}

int main() {
	vector<vector<int>> matrix;

	matrix = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
	// matrix = {{6, 8}, {1, 1}};
	// matrix = {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};
	// matrix = {{1, 2}};

	int res = longestIncreasingPath(matrix);

	cout << res << endl;

	// for (int i = 0; i < res.size(); i++) {
	// 	for (int j = 0; j < res[i].size(); j++) {
	// 		cout << res[i][j] << " " << endl;
	// 	}
	// 	cout << endl;
	// }

	return 0;
}