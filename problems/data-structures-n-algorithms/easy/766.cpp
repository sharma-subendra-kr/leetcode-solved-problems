// 766. Toeplitz Matrix
// https://leetcode.com/problems/toeplitz-matrix/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

// bool isToeplitzMatrix(vector<vector<int>> &matrix) {
// 	//
// 	if (matrix.size() == 0) {
// 		return 0;
// 	}

// 	for (int i = 0; i < matrix[0].size(); i++) {
// 		int d = matrix[0][i];
// 		int _i = 0;
// 		int j = i;
// 		while (_i < matrix.size() && j < matrix[0].size() && d == matrix[_i][j]) {
// 			_i++;
// 			j++;
// 		}

// 		if (_i != matrix.size() && j != matrix[0].size()) {
// 			return false;
// 		}
// 	}

// 	for (int i = 1; i < matrix.size(); i++) {
// 		int d = matrix[i][0];
// 		int _i = i;
// 		int j = 0;
// 		while (_i < matrix.size() && j < matrix[0].size() && d == matrix[_i][j]) {
// 			_i++;
// 			j++;
// 		}

// 		if (_i != matrix.size() && j != matrix[0].size()) {
// 			return false;
// 		}
// 	}

// 	return true;
// }

bool isToeplitzMatrix(vector<vector<int>> &matrix) {
	//
	if (matrix.size() == 0) {
		return 0;
	}

	for (int i = 0; i < matrix.size() - 1; i++) {
		for (int j = 0; j < matrix[0].size() - 1; j++) {
			if (matrix[i][j] != matrix[i + 1][j + 1]) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	//
	vector<vector<int>> matrix;

	// matrix = {{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}};
	// matrix = {{1, 2}, {2, 2}};
	matrix = {{11, 74, 0, 93}, {40, 11, 74, 7}};

	bool res = isToeplitzMatrix(matrix);

	cout << res << endl;

	return 0;
}