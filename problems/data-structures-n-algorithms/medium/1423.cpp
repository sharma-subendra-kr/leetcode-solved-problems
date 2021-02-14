// 1423. Maximum Points You Can Obtain from Cards
// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

// 33 test cases passed, time limit exceeded
// void getMax(vector<int> &cardPoints, int k, int left, int right, int sum,
// 						int *max, int **cache) {

// 	if (k == 0) {
// 		if (sum > *max) {
// 			*max = sum;
// 		}
// 		return;
// 	}

// 	if (cache[left][right] == 1) {
// 		return;
// 	}

// 	getMax(cardPoints, k - 1, left + 1, right, sum + cardPoints[left], max,
// 				 cache);
// 	cache[left][right] = 1;
// 	getMax(cardPoints, k - 1, left, right - 1, sum + cardPoints[right], max,
// 				 cache);
// 	cache[left][right] = 1;
// }

// int maxScore(vector<int> &cardPoints, int k) {
// 	//
// 	int max = 0;
// 	int sum = 0;

// 	int **cache = new int *[k];
// 	for (int i = 0; i < k; i++) {
// 		cache[i] = new int[cardPoints.size()]{0};
// 	}

// 	getMax(cardPoints, k, 0, cardPoints.size() - 1, sum, &max, cache);

// 	return max;
// }

int maxScore(vector<int> &cardPoints, int k) {
	//
	int MAX = 0;
	int sum = 0;

	for (int i = cardPoints.size() - k; i < cardPoints.size(); i++) {
		sum += cardPoints[i];
	}
	MAX = sum;

	int left = 0;
	int right = cardPoints.size() - k;

	while (left < k) {
		sum -= cardPoints[right];
		sum += cardPoints[left];

		MAX = max(sum, MAX);

		right++;
		left++;
	}

	return MAX;
}

int main() {
	//
	vector<int> cardPoints;
	int k;

	cardPoints = {1, 2, 3, 4, 5, 6, 1};
	k = 3;

	int res = maxScore(cardPoints, k);

	cout << res << endl;

	return 0;
}