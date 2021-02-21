// 973. K Closest Points to Origin
// https://leetcode.com/problems/k-closest-points-to-origin/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

// Revisit other solution
int getDistance(vector<int> a) {
	// vector<int> b = {0, 0};
	// return sqrt(pow(b[1] - a[1], 2) + pow(b[0] - a[0], 2));
	// return sqrt((a[1] * a[1]) + (a[0] * a[0]));
	return (a[1] * a[1]) + (a[0] * a[0]);
}

struct comparator {
	bool operator()(vector<int> a, vector<int> b) {
		//
		return getDistance(a) < getDistance(b);
	}
};

vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
	priority_queue<vector<int>, vector<vector<int>>, comparator> pq;

	for (int i = 0; i < points.size(); i++) {
		pq.push(points[i]);
		if (pq.size() > K) {
			pq.pop();
		}
	}

	vector<vector<int>> res;
	while (!pq.empty()) {
		res.push_back(pq.top());
		pq.pop();
	}

	return res;
}

int main() {
	//
	vector<vector<int>> points;
	int k;

	points = {{1, 3}, {-2, 2}};
	k = 1;

	vector<vector<int>> res = kClosest(points, k);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i][0] << " " << res[i][1] << endl;
	}

	return 0;
}