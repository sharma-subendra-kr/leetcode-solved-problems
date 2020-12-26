// 130. Surrounded Regions
// https://leetcode.com/problems/surrounded-regions/

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Check why this works with 5 iterations
// void solve(vector<vector<char>> &board) {
// 	if (board.size() == 0) {
// 		return;
// 	}

// 	int cols = board[0].size();

// 	for (int i = 1; i < board.size() - 1; i++) {
// 		for (int j = 1; j < cols - 1; j++) {
// 			if (board[i][j] == 'O' &&
// 					(board[i - 1][j] == 'X' || board[i - 1][j] == 'Z') &&
// 					(board[i + 1][j] == 'X' || board[i + 1][j] == 'Z' ||
// 					 board[i + 1][j] == 'O') &&
// 					(board[i][j - 1] == 'X' || board[i][j - 1] == 'Z') &&
// 					(board[i][j + 1] == 'X' || board[i][j + 1] == 'Z' ||
// 					 board[i][j + 1] == 'O')) {
// 				board[i][j] = 'Z';
// 			}
// 		}
// 	}

// 	for (int i = board.size() - 2; i > 0; i--) {
// 		for (int j = cols - 2; j > 0; j--) {
// 			if (board[i][j] == 'Z' &&
// 					(board[i - 1][j] == 'O' || board[i + 1][j] == 'O' ||
// 					 board[i][j - 1] == 'O' || board[i][j + 1] == 'O')) {
// 				board[i][j] = 'O';
// 			}
// 		}
// 	}

// 	for (int i = 1; i < board.size() - 1; i++) {
// 		for (int j = 1; j < cols - 1; j++) {
// 			if (board[i][j] == 'Z' &&
// 					(board[i - 1][j] == 'O' || board[i + 1][j] == 'O' ||
// 					 board[i][j - 1] == 'O' || board[i][j + 1] == 'O')) {
// 				board[i][j] = 'O';
// 			}
// 		}
// 	}

// 	for (int i = board.size() - 2; i > 0; i--) {
// 		for (int j = cols - 2; j > 0; j--) {
// 			if (board[i][j] == 'Z' &&
// 					(board[i - 1][j] == 'O' || board[i + 1][j] == 'O' ||
// 					 board[i][j - 1] == 'O' || board[i][j + 1] == 'O')) {
// 				board[i][j] = 'O';
// 			}
// 		}
// 	}

// 	for (int i = 1; i < board.size() - 1; i++) {
// 		for (int j = 1; j < cols - 1; j++) {
// 			if (board[i][j] == 'Z' &&
// 					(board[i - 1][j] == 'O' || board[i + 1][j] == 'O' ||
// 					 board[i][j - 1] == 'O' || board[i][j + 1] == 'O')) {
// 				board[i][j] = 'O';
// 			}
// 		}
// 	}

// 	for (int i = board.size() - 2; i > 0; i--) {
// 		for (int j = cols - 2; j > 0; j--) {
// 			if (board[i][j] == 'Z' &&
// 					(board[i - 1][j] == 'O' || board[i + 1][j] == 'O' ||
// 					 board[i][j - 1] == 'O' || board[i][j + 1] == 'O')) {
// 				board[i][j] = 'O';
// 			}
// 		}
// 	}

// 	for (int i = 0; i < board.size(); i++) {
// 		for (int j = 0; j < cols; j++) {
// 			if (board[i][j] == 'Z') {
// 				board[i][j] = 'X';
// 			}
// 		}
// 	}
// }

void dfs(vector<vector<char>> &board, int i, int j) {
	if (i < 0 || i == board.size() || j < 0 || j == board[0].size()) {
		return;
	}

	if (board[i][j] == 'O') {
		board[i][j] = 'Z';
	} else {
		return;
	}

	dfs(board, i - 1, j);
	dfs(board, i + 1, j);
	dfs(board, i, j - 1);
	dfs(board, i, j + 1);
}

void solve(vector<vector<char>> &board) {
	if (board.size() == 0) {
		return;
	}

	int rows = board.size();
	int cols = board[0].size();

	for (int i = 0; i < board.size(); i++) {
		dfs(board, i, 0);
		dfs(board, i, cols - 1);
	}

	for (int j = 0; j < cols; j++) {
		dfs(board, 0, j);
		dfs(board, rows - 1, j);
	}

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < cols; j++) {
			if (board[i][j] == 'O') {
				board[i][j] = 'X';
			}
		}
	}

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < cols; j++) {
			if (board[i][j] == 'Z') {
				board[i][j] = 'O';
			}
		}
	}
}

int main() {
	vector<vector<char>> board;

	board = {{'X', 'X', 'X', 'X'},
					 {'X', 'O', 'O', 'X'},
					 {'X', 'X', 'O', 'X'},
					 {'X', 'O', 'X', 'X'}};

	// board = {{'O', 'X', 'X', 'O', 'X'},
	// 				 {'X', 'O', 'O', 'X', 'O'},
	// 				 {'X', 'O', 'X', 'O', 'X'},
	// 				 {'O', 'X', 'O', 'O', 'O'},
	// 				 {'X', 'X', 'O', 'X', 'O'}};

	// [
	// 	[ "O", "X", "X", "O", "X" ],
	// 	[ "X", "X", "X", "X", "O" ],
	// 	[ "X", "X", "X", "O", "X" ],
	// 	[ "O", "X", "O", "O", "O" ],
	// 	[ "X", "X", "O", "X", "O" ]
	// ]

	// board = {};

	// board = {{'X', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'X', 'O'},
	// 				 {'X', 'O', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'X'},
	// 				 {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X'},
	// 				 {'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X'},
	// 				 {'O', 'O', 'X', 'X', 'O', 'X', 'X', 'O', 'O', 'O'},
	// 				 {'X', 'O', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'O'},
	// 				 {'X', 'O', 'X', 'O', 'O', 'X', 'X', 'O', 'X', 'O'},
	// 				 {'X', 'X', 'O', 'X', 'X', 'O', 'X', 'O', 'O', 'X'},
	// 				 {'O', 'O', 'O', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
	// 				 {'X', 'X', 'O', 'X', 'X', 'X', 'X', 'O', 'O', 'O'}};

	// [
	// 	[ "X", "O", "X", "O", "X", "O", "O", "O", "X", "O" ],
	// 	[ "X", "O", "O", "X", "X", "X", "O", "O", "O", "X" ],
	// 	[ "O", "O", "O", "O", "O", "O", "O", "O", "X", "X" ],
	// 	[ "O", "O", "O", "O", "O", "O", "X", "O", "O", "X" ],
	// 	[ "O", "O", "X", "X", "O", "X", "X", "O", "O", "O" ],
	// 	[ "X", "O", "O", "X", "X", "X", "X", "X", "X", "O" ],
	// 	[ "X", "O", "X", "X", "X", "X", "X", "O", "X", "O" ],
	// 	[ "X", "X", "O", "X", "X", "X", "X", "O", "X", "X" ],
	// 	[ "O", "O", "O", "O", "X", "X", "X", "O", "X", "O" ],
	// 	[ "X", "X", "O", "X", "X", "X", "X", "O", "O", "O" ]
	// ]

	// [
	// 	[ "X", "O", "X", "O", "X", "O", "O", "O", "X", "O" ],
	// 	[ "X", "O", "O", "X", "X", "X", "O", "O", "O", "X" ],
	// 	[ "O", "O", "O", "O", "O", "O", "O", "O", "X", "X" ],
	// 	[ "O", "O", "O", "O", "O", "O", "X", "O", "O", "X" ],
	// 	[ "O", "O", "X", "X", "O", "X", "X", "O", "O", "O" ],
	// 	[ "X", "O", "O", "X", "X", "X", "X", "X", "X", "O" ],
	// 	[ "X", "O", "X", "X", "X", "X", "X", "O", "X", "O" ],
	// 	[ "X", "X", "O", "X", "X", "X", "X", "O", "O", "X" ],
	// 	[ "O", "O", "O", "O", "X", "X", "X", "O", "X", "O" ],
	// 	[ "X", "X", "O", "X", "X", "X", "X", "O", "O", "O" ]
	// ]

	// board = {{'O', 'X', 'X', 'X', 'X', 'X', 'O', 'O'},
	// 				 {'O', 'O', 'O', 'X', 'X', 'X', 'X', 'O'},
	// 				 {'X', 'X', 'X', 'X', 'O', 'O', 'O', 'O'},
	// 				 {'X', 'O', 'X', 'O', 'O', 'X', 'X', 'X'},
	// 				 {'O', 'X', 'O', 'X', 'X', 'X', 'O', 'O'},
	// 				 {'O', 'X', 'X', 'O', 'O', 'X', 'X', 'O'},
	// 				 {'O', 'X', 'O', 'X', 'X', 'X', 'O', 'O'},
	// 				 {'O', 'X', 'X', 'X', 'X', 'O', 'X', 'X'}};

	// [
	// 	[ "O", "X", "X", "X", "X", "X", "O", "O" ],
	// 	[ "O", "O", "O", "X", "X", "X", "X", "O" ],
	// 	[ "X", "X", "X", "X", "O", "O", "O", "O" ],
	// 	[ "X", "X", "X", "X", "O", "X", "X", "X" ],
	// 	[ "O", "X", "X", "X", "X", "X", "O", "O" ],
	// 	[ "O", "X", "X", "X", "X", "X", "X", "O" ],
	// 	[ "O", "X", "X", "X", "X", "X", "O", "O" ],
	// 	[ "O", "X", "X", "X", "X", "O", "X", "X" ]
	// ]

	// [
	// 	[ "O", "X", "X", "X", "X", "X", "O", "O" ],
	// 	[ "O", "O", "O", "X", "X", "X", "X", "O" ],
	// 	[ "X", "X", "X", "X", "O", "O", "O", "O" ],
	// 	[ "X", "X", "X", "O", "O", "X", "X", "X" ],
	// 	[ "O", "X", "X", "X", "X", "X", "O", "O" ],
	// 	[ "O", "X", "X", "X", "X", "X", "X", "O" ],
	// 	[ "O", "X", "X", "X", "X", "X", "O", "O" ],
	// 	[ "O", "X", "X", "X", "X", "O", "X", "X" ]
	// ]

	solve(board);

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}