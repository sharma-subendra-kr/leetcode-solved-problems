// 48. Rotate Image
// https://leetcode.com/problems/rotate-image/

#include <stdio.h>
#include <stdlib.h>

void rotate(int **matrix, int matrixSize, int *matrixColSize) {
	int i, depth, upperbound;
	int temp;
	int cnt = 0;

	depth = matrixSize / 2 - 1;
	if (matrixSize % 2 == 0) {
		upperbound = depth + 1;
	} else {
		upperbound = matrixSize / 2 + 1;
	}

	while (depth >= 0) {
		cnt = 0;
		for (i = depth; i < upperbound; i++) {
			// tl = matrix[depth][i];
			// tr = matrix[i][upperbound];
			// br = matrix[upperbound][upperbound - cnt];
			// bl = matrix[upperbound - cnt][depth];

			temp = matrix[depth][i];
			matrix[depth][i] = matrix[upperbound - cnt][depth];
			matrix[upperbound - cnt][depth] = matrix[upperbound][upperbound - cnt];
			matrix[upperbound][upperbound - cnt] = matrix[i][upperbound];
			matrix[i][upperbound] = temp;

			cnt++;
		}

		depth--;
		upperbound++;
	}
}

int main() {
	int **matrix, matrixSize, matrixColSize, i, j;

	scanf("%d%d", &matrixSize, &matrixColSize);

	matrix = (int **)malloc(matrixColSize * sizeof(int *));
	for (i = 0; i < matrixColSize; i++) {
		matrix[i] = (int *)malloc(matrixSize * sizeof(int));
	}

	for (i = 0; i < matrixColSize; i++) {
		for (j = 0; j < matrixSize; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	printf("[\n");
	for (i = 0; i < matrixColSize; i++) {
		printf("[");
		for (j = 0; j < matrixSize; j++) {
			printf("%d,", matrix[i][j]);
		}
		printf("],\n");
	}
	printf("]\n");

	rotate(matrix, matrixSize, &matrixColSize);

	printf("[\n");
	for (i = 0; i < matrixColSize; i++) {
		printf("[");
		for (j = 0; j < matrixSize; j++) {
			printf("%d,", matrix[i][j]);
		}
		printf("],\n");
	}
	printf("]\n");

	for (i = 0; i < matrixColSize; i++) {
		free(matrix[i]);
	}
	free(matrix);
}