// 401. Binary Watch
// https://leetcode.com/problems/binary-watch/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <stdlib.h>
#include <math.h>

using namespace std;

// Brian Kernighan’s Algorithm to count set bits
int countBits(int n) {
	int count = 0;
	while (n) {
		n &= (n - 1);
		count++;
	}
	return count;
}

vector<string> readBinaryWatch(int turnedOn) {
	//
	vector<string> res = {};
	if (turnedOn <= 8) {
		for (int i = 0; i < 12; i++) {
			int minsTurnedOn = turnedOn - countBits(i);
			if (minsTurnedOn < 6) {
				for (int j = 0; j < 60; j++) {
					if (countBits(j) == minsTurnedOn) {
						res.push_back(to_string(i) + ":" +
													(j < 10 ? ("0" + to_string(j)) : to_string(j)));
					}
				}
			}
		}
	}
	return res;
}

int main() {
	//
	vector<string> res = readBinaryWatch(0);
	for (string str : res) {
		cout << str << endl;
	}
	return 0;
}