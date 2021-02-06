// 311. Sparse Matrix Multiplication
// https://leetcode.com/problems/sparse-matrix-multiplication/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

// vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B)
// {
// 	//
// 	if (A.size() == 0 || B.size() == 0) {
// 		return vector<vector<int>>();
// 	}

// 	vector<vector<int>> res(A.size(), vector<int>(B[0].size()));

// 	for (int i = 0; i < A.size(); i++) {
// 		for (int j = 0; j < B[0].size(); j++) {
// 			int sum = 0;
// 			for (int k = 0; k < A[0].size(); k++) {
// 				sum += A[i][k] * B[k][j];
// 			}
// 			res[i][j] = sum;
// 		}
// 	}

// 	return res;
// }

vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
	//
	if (A.size() == 0 || B.size() == 0) {
		return vector<vector<int>>();
	}

	vector<vector<int>> res(A.size(), vector<int>(B[0].size(), 0));

	for (int i = 0; i < A.size(); i++) {
		for (int k = 0; k < A[0].size(); k++) {
			if (A[i][k] == 0)
				continue;
			for (int j = 0; j < B[0].size(); j++) {
				res[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	return res;
}

int main() {
	//
	return 0;
}