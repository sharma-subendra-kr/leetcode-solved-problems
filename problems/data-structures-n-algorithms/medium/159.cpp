// 159. Longest Substring with At Most Two Distinct Characters
// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

// Inefficient solution
// void reset(char *mp) {
// 	for (int i = 0; i < 52; i++) {
// 		mp[i] = 0;
// 	}
// }

// int getIndex(char c) {
// 	if (c - 'a' >= 0) {
// 		return c - 'a';
// 	}
// 	return c - 'A' + 26;
// }

// int lengthOfLongestSubstringTwoDistinct(string s) {
// 	//
// 	char mp[52] = {0};
// 	int MAX = 0;
// 	int count = 0;
// 	int dist = 0;
// 	int prev = 0;

// 	for (int i = 0; i < s.size(); i++) {
// 		if (mp[getIndex(s[i])] == 1) {
// 			count++;
// 		} else if (dist < 2) {
// 			mp[getIndex(s[i])] = 1;
// 			dist++;
// 			count++;
// 		} else {
// 			MAX = max(MAX, count);
// 			reset(mp);
// 			count = 0;
// 			i = prev;
// 			prev++;
// 			dist = 0;
// 		}
// 	}

// 	return max(MAX, count);
// }

int removeLeftMost(unordered_map<char, int> &mp) {
	int min = INT_MAX;
	char minChar = '\0';

	for (auto iter = mp.begin(); iter != mp.end(); iter++) {
		if (iter->second < min) {
			min = iter->second;
			minChar = iter->first;
		}
	}

	mp.erase(minChar);

	return min;
}

// My Solution
// int lengthOfLongestSubstringTwoDistinct(string s) {
// 	//
// 	unordered_map<char, int> mp;
// 	int left = 0;
// 	int right = 0;
// 	int MAX = 0;

// 	while (right < s.size()) {
// 		mp[s[right]] = right;

// 		if (mp.size() == 3) {
// 			MAX = max(MAX, right - left);
// 			left = removeLeftMost(mp) + 1;
// 		}

// 		right++;
// 	}

// 	return max(MAX, right - left);
// }

// LeetCode Solution
int lengthOfLongestSubstringTwoDistinct(string s) {
	//
	unordered_map<char, int> mp;
	int left = 0;
	int right = 0;
	int MAX = 0;

	while (right < s.size()) {
		mp[s[right]] = right;
		right++;

		if (mp.size() == 3) {
			left = removeLeftMost(mp) + 1;
		}
		MAX = max(MAX, right - left);
	}

	return MAX;
}

int main() {
	//
	string s;

	s = "eceba";
	// s = "bacc";
	// s = "cdaba";
	// s = "abaccc";
	// s =
	// "abZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ"
	// 		"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZYX";
	// s =
	// "BabBbBbBbbABBABBbAabbbABBaBbBabaabBbbBAAaaAbbAABaAbBBaAaaaaBABbaBbAAbBBb"
	// 		"bABBaaBBbabAbBBAAbAbaaaBrBBaAaabAbbBbABabABaBabBBBBBaAbAaABaaaAAaAgAaAaB"
	// 		"AbaBaBaBbbbBbABBBBaaaBbbbAbbbBaBBaAbBBbbaaaaaBbbaaAAbAABBABBaAAABBbbBbBb"
	// 		"bBbaABBAAbBAbabbbabwBbbBArABaBBbabBaBabABABaabBBABBAabBAAaabbbbBAababAaB"
	// 		"aaAaBbBbBAAbaBabBbabaBaaBbaabABAbbBbaBAbabABbbaAaBbAAAbBbaabBBAbbbABbaab"
	// 		"AAAaaaBaBaaaBBABbBAbAAbaABaabbbbBBAabbbBABBbaABBAAAabaAbaBAbbaBaBbAbaAAb"
	// 		"BaBAbAabBBbBsBabbbAaBbabAAaABAaBAAAbbaBaAbABABBBAbABABbbbBaaBaBAbABAbaaA"
	// 		"bBbAABBbAbbAaBbabaBbABAAbAABbbAabAaAaBbBBbAAbBbaaaBAbABBbBBaCabBBabBAaBb"
	// 		"BaAbbBAbbBaBAabBAababAaAbaAaabBBBABabaabBAAAabBAAAbBAbAaaaAbAaBaAbbAaABA"
	// 		"BBbBBAABAabaAAbBaBbAAaabbABBBABaBAabAbAAbBbAabAbaBbAbBAABAABAAAbBaaaaBab"
	// 		"baBABBaABbAabBaBAbAbbABAbaAAbaAAaBaabaBbBBbBABAABBABBaabBBbBBABAAaAAbbBb"
	// 		"ABBBbAabAbABbAAAbbAbABbbAbBAbabbbBBBBbAAabaabBABABaaAbaBBBBbbABbBbBABBaA"
	// 		"bAaBBABBBabAABBBBBbBBabBaaBbaaBaBbaBbbAABbbAaaBBBbabaabBABABBBGabbBAbaBa"
	// 		"bAaAAabbbBaabBBbABBabBabbBbAbbAaBbAaAabBabBBbaBLaAbbAaaBaabAAab";
	// s = "ccaabbb";
	// s = "ababacccccc";

	int res = lengthOfLongestSubstringTwoDistinct(s);

	cout << res << endl;

	return 0;
}