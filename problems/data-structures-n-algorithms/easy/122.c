// 122. Best Time to Buy and Sell Stock II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// Input: [7,1,5,3,6,4]
// Output: 7

#include <stdio.h>
#include <stdlib.h>

int maxProfit(int *prices, int pricesSize) {
	int i, left = 0, profit = 0, increasedPrice = 0;

	for (i = 0; i < pricesSize; i++) {
		if (i == 0) {
			left = prices[i];
		} else if (left < prices[i] && prices[i] > increasedPrice) {
			increasedPrice = prices[i];
		} else if (increasedPrice > left) {
			// make a transaction
			profit += increasedPrice - left;
			left = prices[i];
			increasedPrice = 0;
		} else if (left > prices[i]) {
			left = prices[i];
		}
	}

	if (increasedPrice > left) {
		profit += increasedPrice - left;
	}

	return profit;
}

int main() {
	int *prices, pricesSize, i, res;

	scanf("%d", &pricesSize);

	prices = (int *)malloc(sizeof(int) * pricesSize);

	for (i = 0; i < pricesSize; i++) {
		scanf("%d", &prices[i]);
	}

	res = maxProfit(prices, pricesSize);

	printf("%d\n", res);

	free(prices);
}