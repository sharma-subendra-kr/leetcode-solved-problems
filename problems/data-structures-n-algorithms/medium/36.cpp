// 36. Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isValidSudoku(char **board, int boardSize, int *boardColSize) {
	int i, j;
	int current;

	// for (i = 0; i < boardColSize; i++) {
	// 	current = board[i][j];
	// 	for (j = 0; j < boardSize; j++) {
	// 	}
	// }
}

int main() {
	char **board;
	int boardSize = 9, boardColSize = 9, i, j;
	bool res;

	board = (char **)malloc(boardColSize * sizeof(char *));
	if (board == NULL) {
		printf("Failed to initialize memory!\n");
	}
	for (i = 0; i < boardColSize; i++) {
		board[i] = (char *)malloc(boardSize * sizeof(char));
		if (board[i] == NULL) {
			printf("Failed to initialize memory!\n");
		}
	}

	for (i = 0; i < boardColSize; i++) {
		for (j = 0; j < boardSize; j++) {
			scanf("%c", &board[i][j]);
		}
	}

	res = isValidSudoku(board, boardSize, boardColSize);

	printf("%d", res);

	for (i = 0; i < boardColSize; i++) {
		free(board[i]);
	}
	free(board);
}