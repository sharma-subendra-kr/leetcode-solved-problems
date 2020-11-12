// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int maxProfit(int *prices, int pricesSize) {

	int i = 0;
	int min, profit = 0;

	if (pricesSize == 0) {
		return 0;
	}

	min = prices[0];

	for (i = 1; i < pricesSize; i++) {
		if (prices[i] < min) {
			min = prices[i];
		}
		if (prices[i] - min > profit) {
			profit = prices[i] - min;
		}
	}

	return profit;
}

int main() {
	int *prices, pricesSize;
	int i, res;

	scanf("%d", &pricesSize);

	prices = (int *)malloc(sizeof(int) * pricesSize);

	for (i = 0; i < pricesSize; i++) {
		scanf("%d", &prices[i]);
	}

	res = maxProfit(prices, pricesSize);

	printf("%d\n", res);

	return 0;
}