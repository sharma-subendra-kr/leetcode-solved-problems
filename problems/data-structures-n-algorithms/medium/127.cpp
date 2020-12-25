// 127. Word Ladder
// https://leetcode.com/problems/word-ladder/

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// int ladderLength(string beginWord, string endWord, vector<string> &wordList)
// { 	unordered_set<string> wSet(wordList.begin(), wordList.end());
// queue<string> q; 	int len = 1;

// 	q.push(beginWord);

// 	while (!q.empty()) {
// 		int n = q.size();
// 		for (int i = 0; i < n; i++) {
// 			string word = q.front();
// 			q.pop();
// 			wSet.erase(word);

// 			if (word == endWord) {
// 				return len;
// 			}

// 			for (int j = 0; j < word.size(); j++) {
// 				char c = word[j];
// 				for (int k = 0; k < 26; k++) {
// 					word[j] = 'a' + k;
// 					if (wSet.find(word) != wSet.end()) {
// 						q.push(word);
// 					}
// 				}
// 				word[j] = c;
// 			}
// 		}
// 		len++;
// 	}

// 	return 0;
// }

int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
	unordered_map<string, int> bHeightMap;
	unordered_map<string, int> eHeightMap;
	unordered_set<string> beginSet(wordList.begin(), wordList.end());
	unordered_set<string> endSet(wordList.begin(), wordList.end());
	queue<string> beginQ;
	queue<string> endQ;
	int bLen = 1;
	int eLen = 1;

	if (beginSet.find(beginWord) == beginSet.end()) {
		beginSet.insert(beginWord);
		endSet.insert(beginWord);
	}
	beginQ.push(beginWord);
	if (endSet.find(endWord) != endSet.end()) {
		endQ.push(endWord);
	}

	while (!beginQ.empty() && !endQ.empty()) {
		int bn = beginQ.size();

		for (int i = 0; i < bn; i++) {
			string word = beginQ.front();
			beginQ.pop();

			if (bHeightMap.find(word) == bHeightMap.end()) {
				bHeightMap.insert({word, bLen});
			}

			auto e = eHeightMap.find(word);
			if (e != eHeightMap.end()) {
				return e->second + bLen - 1;
			}

			for (int j = 0; j < word.size(); j++) {
				char c = word[j];
				for (int k = 0; k < 26; k++) {
					word[j] = 'a' + k;
					if (beginSet.find(word) != beginSet.end() &&
							bHeightMap.find(word) == bHeightMap.end()) {
						beginQ.push(word);
					}
				}
				word[j] = c;
			}
		}
		bLen++;

		int en = endQ.size();

		for (int i = 0; i < en; i++) {
			string word = endQ.front();
			endQ.pop();

			if (eHeightMap.find(word) == eHeightMap.end()) {
				eHeightMap.insert({word, eLen});
			}

			auto b = bHeightMap.find(word);
			if (b != bHeightMap.end()) {
				return b->second + eLen - 1;
			}

			for (int j = 0; j < word.size(); j++) {
				char c = word[j];
				for (int k = 0; k < 26; k++) {
					word[j] = 'a' + k;
					if (endSet.find(word) != endSet.end() &&
							eHeightMap.find(word) == eHeightMap.end()) {
						endQ.push(word);
					}
				}
				word[j] = c;
			}
		}
		eLen++;
	}

	return 0;
}

int main() {
	// string beginWord = "hit", endWord = "cog";
	// vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
	// string beginWord = "hit", endWord = "cog";
	// vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};
	string beginWord = "hot", endWord = "dog";
	vector<string> wordList = {"hot", "dog"};
	// string beginWord = "hog", endWord = "cog";
	// vector<string> wordList = {"cog"};

	int res;

	res = ladderLength(beginWord, endWord, wordList);
	cout << res << endl;

	return 0;
}