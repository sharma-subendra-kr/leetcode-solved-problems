// 118. Pascal's Triangle
// https://leetcode.com/problems/pascals-triangle/

#include <stdio.h>
#include <stdlib.h>

int **generate(int numRows, int *returnSize, int **returnColumnSizes) {
	int **res, i, j;

	*returnSize = numRows;

	(*returnColumnSizes) = (int *)malloc(sizeof(int) * numRows);

	res = (int **)malloc(sizeof(int *) * numRows);
	for (i = 0; i < numRows; i++) {
		res[i] = (int *)malloc(sizeof(int) * (i + 1));
		(*returnColumnSizes)[i] = i + 1;
	}

	if (numRows >= 1) {
		res[0][0] = 1;
	}

	for (i = 1; i < numRows; i++) {
		res[i][0] = 1;
		res[i][i] = 1;
		for (j = 1; j < i; j++) {
			res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
		}
	}

	return res;
}

int main() {
	int numRows, returnSize, *returnColumnSizes;
	int **res, i, j;

	scanf("%d", &numRows);

	res = generate(numRows, &returnSize, &returnColumnSizes);

	for (i = 0; i < numRows; i++) {
		for (j = 0; j < returnColumnSizes[i]; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}

	return 0;
}