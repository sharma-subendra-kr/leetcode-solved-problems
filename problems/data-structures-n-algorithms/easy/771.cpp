// 771. Jewels and Stones
// https://leetcode.com/problems/jewels-and-stones/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

int numJewelsInStones(string jewels, string stones) {
	unordered_map<char, int> mp;
	int res = 0;
	for (char c : jewels) {
		if (mp.find(c) != mp.end()) {
			mp[c]++;
		} else {
			mp[c] = 1;
		}
	}

	for (char c : stones) {
		if (mp.find(c) != mp.end()) {
			res++;
		}
	}

	return res;
}

int main() {
	string jewels, stones;

	jewels = "aA";
	stones = "aAAbbbb";

	int res = numJewelsInStones(jewels, stones);

	cout << res << endl;

	return 0;
}