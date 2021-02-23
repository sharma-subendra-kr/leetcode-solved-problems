// 836. Rectangle Overlap
// https://leetcode.com/problems/rectangle-overlap/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

bool doRectsOverlap(vector<int> &rec1, vector<int> &rec2) {
	if (rec2[0] >= rec1[2] || rec2[1] >= rec1[3]) {
		return false;
	}
	return true;
}

bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2) {
	//
	if (rec1[0] == rec1[2] || rec1[1] == rec1[3] || rec2[0] == rec2[2] ||
			rec2[1] == rec2[3]) {
		return false;
	}
	if (doRectsOverlap(rec1, rec2) && doRectsOverlap(rec2, rec1)) {
		return true;
	}
	return false;
}

int main() {
	//

	vector<int> rect1, rect2;

	rect1 = {0, 0, 2, 2};
	rect2 = {1, 1, 3, 3};

	bool res = isRectangleOverlap(rect1, rect2);

	cout << res << endl;

	return 0;
}