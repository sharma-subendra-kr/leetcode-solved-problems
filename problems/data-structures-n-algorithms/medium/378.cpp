// 378. Kth Smallest Element in a Sorted Matrix
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int kthSmallest(vector<vector<int>> &matrix, int k) {
	priority_queue<int> pq;
	int _k = k;

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			if (_k > 0) {
				pq.push(matrix[i][j]);
				_k--;
			} else {
				int top = pq.top();
				if (top > matrix[i][j]) {
					pq.push(matrix[i][j]);
					pq.pop();
				}
			}
		}
	}

	return pq.top();
}

int main() {
	vector<vector<int>> matrix;
	int k;

	matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
	k = 8;

	int res = kthSmallest(matrix, k);

	cout << res << endl;

	return 0;
}