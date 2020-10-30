#include <stdio.h>
#include <stdlib.h>

int main() {
	int **board, i, n = 3, m = 3;

	// * sizeof(int *) cuz we need an array of pointers. size of pointer is same
	// for all datatypes for a particular machine
	// * size of pointer varies with the hardware.
	// * 64-bit machine has 8 byte integer pointer, 32-bit machine has 4 byte
	// integer pointer
	// * this is the reason why 32-bit machine can have only 4gb ram

	board = (int **)malloc(n * sizeof(int *));
	if (board == NULL) {
		printf("Failed to initialize memory!\n");
	}
	for (i = 0; i < n; i++) {
		// * sizeof(int) cuz we need an array of integers.
		board[i] = (int *)malloc(m * sizeof(int));
		if (board[i] == NULL) {
			printf("Failed to initialize memory!\n");
		}
	}

	for (i = 0; i < n; i++) {
		free(board[i]);
	}
	free(board);

	printf("%zu\n", sizeof(char *));
	printf("%zd\n", sizeof(float *));
	printf("%zx\n", sizeof(double *));
	printf("%zu\n", sizeof(long *));
	printf("%zu\n", sizeof(long long *));
	printf("%zu\n", sizeof(unsigned int *));
	printf("%zu\n", sizeof(unsigned long *));
	printf("%zu\n", sizeof(char **));
	printf("%zu\n", sizeof(float **));
	printf("%zu\n", sizeof(double **));
	printf("%zu\n", sizeof(long **));
	printf("%zu\n", sizeof(long long **));
	printf("%zu\n", sizeof(unsigned int **));
	printf("%zu\n", sizeof(unsigned long **));
}
