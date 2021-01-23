// 96. Unique Binary Search Trees
// https://leetcode.com/problems/unique-binary-search-trees/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <limits.h>

using namespace std;

int numTrees(int n) {
	int *G = new int[n + 1]{0};
	G[0] = G[1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			G[i] += G[j - 1] * G[i - j];
		}
	}

	return G[n];
}

int main() {
	int n;

	n = 3;

	int res = numTrees(n);

	cout << res << endl;

	return 0;
}