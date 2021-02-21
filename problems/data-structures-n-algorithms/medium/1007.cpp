// 1007. Minimum Domino Rotations For Equal Row
// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

int check(vector<int> &A, vector<int> &B, int lookFor) {
	int rot = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] != lookFor && B[i] != lookFor) {
			return -1;
		} else if (A[i] != lookFor) {
			rot++;
		}
	}

	return rot;
}

int minDominoRotations(vector<int> &A, vector<int> &B) {
	//
	vector<int> res;

	res.push_back(check(A, B, A[0]));
	res.push_back(check(A, B, B[0]));
	res.push_back(check(B, A, A[0]));
	res.push_back(check(B, A, B[0]));

	int min = INT_MAX;
	for (int r : res) {
		if (r != -1 && r < min) {
			min = r;
		}
	}

	if (min != INT_MAX) {
		return min;
	}
	return -1;
}

int main() {
	//
	vector<int> A;
	vector<int> B;

	A = {2, 1, 2, 4, 2, 2};
	B = {5, 2, 6, 2, 3, 2};

	int res = minDominoRotations(A, B);

	cout << res << endl;

	return 0;
}