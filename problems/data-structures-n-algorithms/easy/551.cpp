// 551. Student Attendance Record I
// https://leetcode.com/problems/student-attendance-record-i/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

bool checkRecord(string s) {
	int absentCount = 0;
	int consecutiveLateCount = 0;
	int totalLateCount = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A') {
			absentCount++;
			consecutiveLateCount = 0;
		} else if (s[i] == 'L') {
			consecutiveLateCount++;
			if (consecutiveLateCount > 2) {
				totalLateCount++;
				consecutiveLateCount = 1;
			}
		} else {
			consecutiveLateCount = 0;
		}
	}

	if (absentCount > 1 || totalLateCount >= 1) {
		return false;
	}
	return true;
}

int main() {
	//
	string s;

	s = "PPALLP";
	// s = "PPALLL";

	bool res = checkRecord(s);

	cout << res << endl;

	return 0;
}