// 76. Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/

#include <deque>
#include <iostream>
#include <limits.h>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

string minWindow(string s, string t) {
	int map[128] = {0};
	int end = 0, begin = 0, head = 0, counter = t.size(), d = INT_MAX;

	for (char c : t)
		map[c]++;

	while (end < s.size()) {
		if (map[s[end++]]-- > 0) {
			counter--;
		}

		while (counter == 0) {
			if (end - begin < d)
				d = end - (head = begin);

			if (map[s[begin++]]++ == 0)
				counter++;
		}
	}

	return s.substr(head, d == INT_MAX ? 0 : d);
}

int main() {
	// string s = "ADOBECODEBANC";
	// string t = "ABC";
	// string s = "a";
	// string t = "a";
	// string s = "bba";
	// string t = "ab";
	string s = "a";
	string t = "aa";
	// string s = "aa";
	// string t = "aa";

	string res = minWindow(s, t);

	cout << res << endl;
}