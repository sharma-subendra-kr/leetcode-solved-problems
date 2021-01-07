// 389. Find the Difference
// https://leetcode.com/problems/find-the-difference/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

// char findTheDifference(string s, string t) {
// 	int sum = 0;

// 	for (int i = 0; i < t.size(); i++) {
// 		sum += (t[i] - 0);
// 		if (i < t.size() - 1) {
// 			sum -= (s[i] - 0);
// 		}
// 	}

// 	return char(sum);
// }

char findTheDifference(string s, string t) {
	int sum = 0;

	for (int i = 0; i < t.size(); i++) {
		sum ^= t[i];
		if (i < t.size() - 1) {
			sum ^= s[i];
		}
	}

	return char(sum);
}

int main() {
	string s, t;

	s = "abcd";
	t = "abcde";

	char res = findTheDifference(s, t);

	cout << res;

	return 0;
}