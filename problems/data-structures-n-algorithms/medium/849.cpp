// 849. Maximize Distance to Closest Person
// https://leetcode.com/problems/maximize-distance-to-closest-person/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

int maxDistToClosest(vector<int> &seats) {
	int iter = 0;
	int MAX = 0;

	while (iter < seats.size()) {
		if (seats[iter] == 0) {
			int start = iter;
			while (iter < seats.size() && seats[iter] == 0) {
				iter++;
			}
			int temp = iter - start;
			int distance;
			if (start == 0 || iter == seats.size()) {
				distance = temp;
			} else if (temp % 2 == 0) {
				distance = temp / 2;
			} else {
				distance = temp / 2 + 1;
			}

			MAX = max(MAX, distance);

			continue;
		}
		iter++;
	}

	return MAX;
}

int main() {
	//
	vector<int> seats;

	seats = {1, 0, 0, 0, 1, 0, 1};
	// seats = {1, 0, 0, 0};
	// seats = {0, 1};

	int res = maxDistToClosest(seats);

	cout << res << endl;

	return 0;
}