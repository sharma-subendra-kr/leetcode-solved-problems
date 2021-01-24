// 59. Spiral Matrix II
// https://leetcode.com/problems/spiral-matrix-ii/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> res(n, vector<int>(n));

	int count = 1;
	int circleCount = n % 2 == 0 ? n / 2 : n / 2 + 1;

	int side = 0;

	int top = n - 1;
	int topStart = 0;
	int topRow = 0;

	int right = n - 1;
	int rightStart = 1;
	int rightCol = n - 1;

	int bottom = 0;
	int bottomStart = n - 2;
	int bottomRow = n - 1;

	int left = 1;
	int leftStart = n - 2;
	int leftCol = 0;

	for (int i = 0; i < circleCount; i++) {
		for (int j = topStart; j <= top; j++) {
			res[topRow][j] = count++;
		}
		topStart++;
		top--;
		topRow++;

		for (int j = rightStart; j <= right; j++) {
			res[j][rightCol] = count++;
		}
		rightStart++;
		right--;
		rightCol--;

		for (int j = bottomStart; j >= bottom; j--) {
			res[bottomRow][j] = count++;
		}
		bottomStart--;
		bottom++;
		bottomRow--;

		for (int j = leftStart; j >= left; j--) {
			res[j][leftCol] = count++;
		}
		leftStart--;
		left++;
		leftCol++;
	}

	return res;
}

int main() {
	int n = 3;

	vector<vector<int>> res = generateMatrix(n);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}