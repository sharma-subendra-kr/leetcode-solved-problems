// 412. Fizz Buzz
// https://leetcode.com/problems/fizz-buzz/

#include <stdio.h>
#include <stdlib.h>

char **fizzBuzz(int n, int *returnSize) {
	char **arr;
	int i, num, iter;
	int high, low;
	char temp;

	*returnSize = n;

	arr = (char **)malloc(sizeof(char *) * n);
	for (i = 0; i < n; i++) {
		arr[i] = (char *)malloc(sizeof(char) * 9);

		if ((i + 1) % 3 == 0 && (i + 1) % 5 == 0) {
			arr[i] = "FizzBuzz\0";
		} else if ((i + 1) % 3 == 0) {
			arr[i] = "Fizz\0";
		} else if ((i + 1) % 5 == 0) {
			arr[i] = "Buzz\0";
		} else {
			iter = 0;
			num = i + 1;
			while (num != 0) {
				arr[i][iter++] = (num % 10) + '0';
				num /= 10;
			}

			low = 0;
			high = iter - 1;
			while (low <= high) {
				temp = arr[i][low];
				arr[i][low] = arr[i][high];
				arr[i][high] = temp;

				low++;
				high--;
			}

			arr[i][iter++] = '\0';
		}
	}

	return arr;
}

int main() {
	int n, returnSize;
	char **arr;
	int i;

	scanf("%d", &n);

	arr = fizzBuzz(n, &returnSize);

	for (i = 0; i < n; i++) {
		printf("%s\n", arr[i]);
	}

	return 0;
}