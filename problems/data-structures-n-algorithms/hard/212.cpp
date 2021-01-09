// 212. Word Search II
// https://leetcode.com/problems/word-search-ii/

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TrieNode {
	string word;
	TrieNode *next[26];
	TrieNode() {
		for (int i = 0; i < 26; i++) {
			next[i] = NULL;
		}
		word = "";
	}
};

void insert(TrieNode *root, string word) {
	TrieNode *parent = root;
	for (int i = 0; i < word.size(); i++) {
		if (parent->next[word[i] - 'a'] == NULL) {
			parent->next[word[i] - 'a'] = new TrieNode();
		}
		parent = parent->next[word[i] - 'a'];
	}

	parent->word = word;
}

void dfs(vector<vector<char>> &board, int i, int j, TrieNode *node,
				 vector<string> &result) {
	if (i < 0 || i == board.size() || j < 0 || j == board[0].size() ||
			board[i][j] == '#') {
		return;
	}

	if (node->next[board[i][j] - 'a'] == NULL) {
		return;
	}

	node = node->next[board[i][j] - 'a'];

	if (node->word != "") {
		result.push_back(node->word);
		node->word = "";
	}

	char backup = board[i][j];

	board[i][j] = '#';
	dfs(board, i - 1, j, node, result);
	dfs(board, i + 1, j, node, result);
	dfs(board, i, j - 1, node, result);
	dfs(board, i, j + 1, node, result);
	board[i][j] = backup;
}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
	vector<string> res;

	TrieNode *root = new TrieNode();

	for (int i = 0; i < words.size(); i++) {
		insert(root, words[i]);
	}

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			dfs(board, i, j, root, res);
		}
	}

	return res;
}

int main() {
	vector<vector<char>> board;
	vector<string> words;

	// board = {{'o', 'a', 'a', 'n'},
	// 				 {'e', 't', 'a', 'e'},
	// 				 {'i', 'h', 'k', 'r'},
	// 				 {'i', 'f', 'l', 'v'}};
	// words = {"oath", "pea", "eat", "rain"};

	board = {{'o', 'a', 'a', 'n'},
					 {'e', 't', 'a', 'e'},
					 {'i', 'h', 'k', 'r'},
					 {'i', 'f', 'l', 'v'}};
	// words = {"oath", "pea", "eat", "rain", "hklf", "hf"};
	words = {"hklf", "hf"};

	vector<string> res = findWords(board, words);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}