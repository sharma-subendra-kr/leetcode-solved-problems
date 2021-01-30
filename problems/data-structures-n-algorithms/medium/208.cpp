// 208. Implement Trie (Prefix Tree)
// https://leetcode.com/problems/implement-trie-prefix-tree/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

class Trie {
private:
	struct Node {
		char c;
		bool isWord = false;
		Node *keys[26];

		Node(char _c) : c(_c) {
			for (int i = 0; i < 26; i++) {
				keys[i] = NULL;
			}
		}
		Node() {
			for (int i = 0; i < 26; i++) {
				keys[i] = NULL;
			}
		}
	};

	Node *root;

public:
	/** Initialize your data structure here. */
	Trie() {
		//
		root = new Node();
	}

	void _insert(string &word, int index, Node *root) {
		if (index == word.size()) {
			root->isWord = true;
			return;
		}
		if (root->keys[word[index] - 'a'] == NULL) {
			root->keys[word[index] - 'a'] = new Node(word[index]);
		}
		_insert(word, index + 1, root->keys[word[index] - 'a']);
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		//
		_insert(word, 0, root);
	}

	bool _search(string &word, int index, Node *root) {
		if (index == word.size() && root->isWord) {
			return true;
		} else if (index == word.size()) {
			return false;
		}

		if (root->keys[word[index] - 'a'] != NULL) {
			return _search(word, index + 1, root->keys[word[index] - 'a']);
		}
		return false;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		//
		return _search(word, 0, root);
	}

	bool _startsWith(string &word, int index, Node *root) {
		if (index == word.size()) {
			return true;
		}
		if (root->keys[word[index] - 'a'] != NULL) {
			return _startsWith(word, index + 1, root->keys[word[index] - 'a']);
		}
		return false;
	}

	/** Returns if there is any word in the trie that starts with the given
	 * prefix. */
	bool startsWith(string prefix) {
		//
		return _startsWith(prefix, 0, root);
	}
};

int main() {
	Trie *trie = new Trie();

	trie->insert("apple");
	trie->insert("app");
	cout << trie->search("app") << endl;

	return 0;
}