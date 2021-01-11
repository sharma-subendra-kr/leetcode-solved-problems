// 309. Best Time to Buy and Sell Stock with Cooldown
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int> &prices) {
	if (prices.size() == 0) {
		return 0;
	}

	int b0 = -prices[0], b1 = -prices[0];
	int s0 = 0, s1 = 0, s2 = 0;

	for (int i = 1; i < prices.size(); i++) {
		b0 = max(b1, s2 - prices[i]);
		s0 = max(s1, b1 + prices[i]);

		s2 = s1, s1 = s0, b1 = b0;
	}

	return s0;
}

int main() {
	vector<int> prices;

	prices = {1, 2, 3, 0, 2};
	// prices = {1, 2};

	int res = maxProfit(prices);

	cout << res << endl;

	return 0;
}