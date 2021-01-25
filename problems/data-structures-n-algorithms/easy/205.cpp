// 205. Isomorphic Strings
// https://leetcode.com/problems/isomorphic-strings/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

bool isIsomorphic(string s, string t) {
	int smap[128] = {0}, tmap[128] = {0};

	for (int i = 0; i < s.size(); i++) {
		if (smap[s[i]] != tmap[t[i]]) {
			return false;
		}
		smap[s[i]] = i + 1;
		tmap[t[i]] = i + 1;
	}

	return true;
}

int main() {
	string s, t;

	s = "egg";
	t = "add";

	// s = "foo";
	// t = "bar";

	bool res = isIsomorphic(s, t);

	cout << res << endl;

	return 0;
}