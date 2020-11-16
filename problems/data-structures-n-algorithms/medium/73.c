// 73. Set Matrix Zeroes
// https://leetcode.com/problems/set-matrix-zeroes/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// void setZeroes(int **matrix, int matrixSize, int *matrixColSize) {
// 	int *arr;
// 	int hasZero = 0;
// 	int cnt = 0, i, j, index;

// 	arr = (int *)malloc(sizeof(int) * (*matrixColSize));

// 	for (i = 0; i < *matrixColSize; i++) {
// 		arr[i] = -1;
// 	}

// 	for (i = 0; i < matrixSize; i++) {
// 		hasZero = 0;
// 		for (j = 0; j < *matrixColSize; j++) {
// 			if (matrix[i][j] == 0) {
// 				arr[j] = j;
// 				hasZero = 1;
// 			}
// 		}
// 		if (hasZero) {
// 			for (j = 0; j < *matrixColSize; j++) {
// 				matrix[i][j] = 0;
// 			}
// 		}
// 	}

// 	for (i = 0; i < *matrixColSize; i++) {
// 		index = arr[i];
// 		if (index == -1) {
// 			continue;
// 		}
// 		for (j = 0; j < matrixSize; j++) {
// 			matrix[j][index] = 0;
// 		}
// 	}
// }

void setZeroes(int **matrix, int matrixSize, int *matrixColSize) {
	int i, j, clearRowZero = 0, clearColZero = 0;

	for (i = 0; i < matrixSize; i++) {
		for (j = 0; j < *matrixColSize; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][0] = 0;
				matrix[0][j] = 0;
				if (i == 0) {
					clearRowZero = 1;
				}

				if (j == 0) {
					clearColZero = 1;
				}
			}
		}
	}

	for (i = 1; i < matrixSize; i++) {
		if (matrix[i][0] != 0) {
			continue;
		}
		for (j = 0; j < *matrixColSize; j++) {
			matrix[i][j] = 0;
		}
	}

	for (i = 1; i < *matrixColSize; i++) {
		if (matrix[0][i] != 0) {
			continue;
		}
		for (j = 0; j < matrixSize; j++) {
			matrix[j][i] = 0;
		}
	}

	if (clearRowZero == 1) {
		for (j = 0; j < *matrixColSize; j++) {
			matrix[0][j] = 0;
		}
	}

	if (clearColZero == 1) {
		for (i = 0; i < matrixSize; i++) {
			matrix[i][0] = 0;
		}
	}
}

int main() {
	int **matrix, matrixSize, matrixColSize;
	int i, j;

	scanf("%d", &matrixSize);
	scanf("%d", &matrixColSize);

	matrix = (int **)malloc(sizeof(int *) * matrixSize);

	for (i = 0; i < matrixSize; i++) {
		matrix[i] = (int *)malloc(sizeof(int) * matrixColSize);
		for (j = 0; j < matrixColSize; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	setZeroes(matrix, matrixSize, &matrixColSize);

	for (i = 0; i < matrixSize; i++) {
		for (j = 0; j < matrixColSize; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}