// 686. Repeated String Match
// https://leetcode.com/problems/repeated-string-match/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <math.h>

using namespace std;

// Try Rabin-Karp solution
int repeatedStringMatch(string a, string b) {
	//
	string copy = "";
	int count = 0;
	while (copy.size() < b.size()) {
		copy += a;
		count++;
	}

	if (copy.find(b) != string::npos) {
		return count;
	}
	copy += a;
	if (copy.find(b) != string::npos) {
		return count + 1;
	}
	return -1;
}

int main() {
	//
	string a, b;

	a = "abcd";
	b = "cdabcdab";

	int res = repeatedStringMatch(a, b);

	cout << res << endl;

	return 0;
}