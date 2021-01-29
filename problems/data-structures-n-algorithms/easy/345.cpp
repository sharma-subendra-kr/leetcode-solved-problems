// 345. Reverse Vowels of a String
// https://leetcode.com/problems/reverse-vowels-of-a-string/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

string reverseVowels(string s) {
	int low = 0;
	int high = s.size() - 1;
	unordered_set<char> mp{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

	while (low < high) {
		if (mp.find(s[high]) != mp.end() && mp.find(s[low]) != mp.end()) {
			char temp = s[low];
			s[low] = s[high];
			s[high] = temp;
			low++;
			high--;
			continue;
		}
		if (mp.find(s[low]) == mp.end()) {
			low++;
		}
		if (mp.find(s[high]) == mp.end()) {
			high--;
		}
	}

	return s;
}

int main() {
	string s;

	s = "hello";

	string res = reverseVowels(s);

	cout << res << endl;

	return 0;
}