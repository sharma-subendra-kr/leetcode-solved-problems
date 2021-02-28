// 939. Minimum Area Rectangle
// https://leetcode.com/problems/minimum-area-rectangle/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

struct comparator {
	bool operator()(vector<int> &a, vector<int> &b) {
		//
		if (a[1] != b[1]) {
			return a[1] < b[1];
		}
		return a[0] < b[0];
	}
};

vector<vector<int>> getCoordinates(vector<int> &a, vector<int> &b,
																	 vector<int> &c, vector<int> &d) {
	vector<vector<int>> arr;
	arr.push_back(a);
	arr.push_back(b);
	arr.push_back(c);
	arr.push_back(d);
	sort(arr.begin(), arr.end(), comparator());

	vector<int> temp = arr[3];
	arr[3] = arr[2];
	arr[2] = temp;

	return arr;
};

bool isRectangle(vector<vector<int>> &arr) {
	if (arr[0][1] != arr[1][1] || arr[0][0] == arr[1][0] ||
			arr[2][1] != arr[3][1] || arr[2][0] == arr[3][0]) {
		return false;
	}

	if (arr[0][0] != arr[3][0] || arr[0][1] == arr[3][1] ||
			arr[1][0] != arr[2][0] || arr[1][1] == arr[2][1]) {
		return false;
	}

	return true;
}

// bool isRectangle(vector<int> &a, vector<int> &b, vector<int> &c,
// 								 vector<int> &d) {
// 	if (a[1] != b[1] || c[1] != d[1] || a[0] != d[0] || b[0] != c[0]) {
// 		return false;
// 	}
// 	return true;
// }

int getArea(vector<vector<int>> &arr) {
	int length = arr[1][0] - arr[0][0];
	int breadth = arr[3][1] - arr[0][1];

	return length * breadth;
}

int minAreaRect(vector<vector<int>> &points) {
	//
	if (points.size() < 4) {
		return 0;
	}

	int MIN = INT_MAX;

	for (int i = 0; i < points.size() - 1; i++) {
		for (int j = i + 1; j < points.size(); j++) {
			if ((points[i][0] != points[j][0] && points[i][1] == points[j][1]) ||
					(points[i][1] != points[j][1] && points[i][0] == points[j][0])) {
				for (int k = 0; k < points.size() - 1; k++) {
					if ((points[i][0] != points[k][0] && points[i][1] == points[k][1]) ||
							(points[j][0] != points[k][0] && points[j][1] == points[k][1]) ||
							(points[i][1] != points[k][1] && points[i][0] == points[k][0]) ||
							(points[j][1] != points[k][1] && points[j][0] == points[k][0])) {
						for (int l = k + 1; l < points.size(); l++) {
							vector<vector<int>> rect =
									getCoordinates(points[i], points[j], points[k], points[l]);

							if (isRectangle(rect)) {
								int area = getArea(rect);
								if (area < MIN) {
									MIN = area;
								}
							}
						}
					}
				}
			}
		}
	}

	if (MIN != INT_MAX) {
		return MIN;
	}
	return 0;
}

int main() {
	//

	vector<vector<int>> points;

	// points = {{1, 1}, {1, 3}, {3, 1}, {3, 3}, {2, 2}};
	// points = {{1, 1}, {1, 3}, {3, 1}, {3, 3}, {4, 1}, {4, 3}};
	// points = {{0, 1}, {1, 3}, {3, 3}, {4, 4}, {1, 4}, {2, 3}, {1, 0}, {3, 4}};
	points = {{0, 1}, {0, 0}, {3, 0}, {4, 4}, {1, 4},
						{2, 1}, {4, 2}, {0, 3}, {4, 1}, {0, 2}};

	int res = minAreaRect(points);

	cout << res << endl;

	return 0;
}