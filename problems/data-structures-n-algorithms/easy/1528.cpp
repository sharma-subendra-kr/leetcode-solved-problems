// 1528. Shuffle String
// https://leetcode.com/problems/shuffle-string/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

void swap(int a, int b, vector<int> &arr) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void swap(int a, int b, string *arr) {
	int temp = (*arr)[a];
	(*arr)[a] = (*arr)[b];
	(*arr)[b] = temp;
}

string restoreString(string s, vector<int> &indices) {
	for (int i = 0; i < s.size(); i++) {
		while (indices[i] != i) {
			swap(i, indices[i], &s);
			swap(i, indices[i], indices);
		}
	}

	return s;
}

int main() {
	string s;
	vector<int> indices;

	s = "art";
	indices = {1, 0, 2};

	s = "aiohn";
	indices = {3, 1, 4, 2, 0};

	string res = restoreString(s, indices);

	cout << res << endl;

	return 0;
}