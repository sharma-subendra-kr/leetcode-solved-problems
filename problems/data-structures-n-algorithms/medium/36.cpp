// 36. Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*

5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9

 */

// bool isValidSudoku(vector<vector<char>> &board) {
// 	int i, j, box;
// 	map<string, int> hmap;
// 	string row, col, sbox;

// 	for (i = 0; i < 9; i++) {
// 		for (j = 0; j < 9; j++) {
// 			if (board[i][j] == '.') {
// 				continue;
// 			}
// 			box = (i / 3 * 3) + (j / 3);
// 			row = "row-" + to_string(i) + board[i][j];
// 			col = "col-" + to_string(j) + board[i][j];
// 			sbox = "box-" + to_string(box) + board[i][j];

// 			if (hmap.find(row) != hmap.end() || hmap.find(col) != hmap.end() ||
// 					hmap.find(sbox) != hmap.end()) {
// 				return false;
// 			} else {
// 				hmap.insert({row, board[i][j]});
// 				hmap.insert({col, board[i][j]});
// 				hmap.insert({sbox, board[i][j]});
// 			}
// 		}
// 	}

// 	return true;
// }

bool isValidSudoku(vector<vector<char>> &board) {
	int i, j, box;

	map<int, int> rowArr[9];
	map<int, int> colArr[9];
	map<int, int> boxArr[9];

	for (i = 0; i < 9; i++) {
		rowArr[i] = map<int, int>();
		colArr[i] = map<int, int>();
		boxArr[i] = map<int, int>();
	}

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (board[i][j] == '.') {
				continue;
			}
			box = (i / 3 * 3) + (j / 3);

			if (rowArr[i].find(board[i][j]) != rowArr[i].end() ||
					colArr[j].find(board[i][j]) != colArr[j].end() ||
					boxArr[box].find(board[i][j]) != boxArr[box].end()) {
				return false;
			} else {
				rowArr[i].insert({board[i][j], 1});
				colArr[j].insert({board[i][j], 1});
				boxArr[box].insert({board[i][j], 1});
			}
		}
	}

	return true;
}

int main() {
	int i, j, n = 9;
	bool res;

	vector<vector<char>> board(n, vector<char>(n));

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	res = isValidSudoku(board);
	cout << "res " << res << endl;

	cout << "[\n";
	for (i = 0; i < n; i++) {
		cout << "[";
		for (j = 0; j < n; j++) {
			cout << board[i][j] << ",";
		}
		cout << "],\n";
	}
	cout << "]";

	return 0;
}